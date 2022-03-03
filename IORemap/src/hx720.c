#include "hx720.h"

unsigned long HX711_Read(void);	//??128
static uint32_t getIndexOfStings(char ch);
static long hexToDec(char *source);
//所用压力传感器型号：	HX711

//比例系数确定数据：
//	42500 	-->  160g --> 265.65
//	80000 	-->  285g --> 280.7
//	115000 	-->  405g --> 283.95
//	405000 	--> 1400g --> 289.29
//拟合直线：
// y = 291.92x-3580.2 (忽略截距)

float Kp_Weight = 293.0f;
float Weight_Maopi=0;

uint32_t  HX720_Buffer = 0;
uint32_t  Weight_No_Lode=0;
uint32_t  Weight_Lode=0 ;

long HX711_Buffer = 0;
float Weight_Shiwu = 0;

#define GapValue 430

float Weight_Real = 0;

int8_t  No_Load_Flag;

float Get_Maopi(void);

void Sensor_Init(void)
{
    GPIO_InitType GPIO_InitStructure;
	
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
	//RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    
    //output CLK
	GPIO_InitStruct(&GPIO_InitStructure);
    /* GPIOC Configuration:Pin6, 7, 8 and 9 as alternate function push-pull */
    GPIO_InitStructure.Pin        = CLK;
	//GPIO_InitStructure.GPIO_Pull    = GPIO_Pull_Up;//GPIO_No_Pull;
    GPIO_InitStructure.Pin  = GPIO_Mode_Out_OD;//GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Current = GPIO_DC_4mA;

    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
	
	
	//数据线浮空输入
	GPIO_InitStructure.Pin = DATA;	
	GPIO_InitStructure.Pin = GPIO_Mode_Input;//GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Current = GPIO_DC_4mA; 
	GPIO_InitPeripheral(GPIOA,&GPIO_InitStructure);

}

uint32_t Sensor_Read(void)
{
    uint32_t value;
	uint8_t i;
	
	//每次读取数据前保证数据线电平稳定
	//此处只是为了稳定电平 拉高或拉低效果相同
//	GPIO_ResetBits(Sensor_Gpio,DATA);
	GPIO_SetBits(GPIOA,DATA);
	
	//为了等待输出电平稳定
	//在每次一操作电平时加微小延时
	//SysTick_Delay_us(2);//delay_us(2);
	
	//时钟线拉低 空闲时时钟线保持低电位
	 GPIO_ResetBits(GPIOA, CLK); //1//GPIO_ResetBits(Sensor_Gpio,CLK);
	
	SysTick_Delay_us(2);//delay_us(2);	
	
	//等待AD转换结束
	while(GPIO_ReadInputDataBit(GPIOA,DATA));
	
	for(i=0;i<24;i++)
	{
		//时钟线拉高 开始发送时钟脉冲
		GPIO_SetBits(GPIOA,CLK);
		
		SysTick_Delay_us(2);//delay_us(2);
		
		//左移位 右侧补零 等待接收数据
		value = value << 1;
		
		//时钟线拉低
		GPIO_ResetBits(GPIOA,CLK);
		
		SysTick_Delay_us(2);//delay_us(2);
		
		//读取一位数据
		if(GPIO_ReadInputDataBit(GPIOA,DATA))
			value ++;
	}
	
	//第25个脉冲
	GPIO_SetBits(GPIOA,CLK);
	
	SysTick_Delay_us(2);//delay_us(2);

	//第25个脉冲下降沿到来时 转换数据
	//此处说明：
	//			HX711是一款24位的AD转换芯片
	//			最高位是符号位 其余为有效位
	//			输出数组最小值0x800000
	//					最大值0x7FFFFF
	//异或运算：
	//			相同为0 
	//			不同为1
	//数据处理说明：
	//			之所以会发生 INPA-INNA < 0mv 的情况
	//			是因为发生了零点漂移
	//			例如上面的数据就是初始状态INPA-INNA = -0.5mv
	//			然后随着重量的增加会发生过零点
	//			这时如果直接使用读取到的数据就会发生错误
	//			因为读取到的是小于0的二进制补码
	//			是不能直接使用的 需要转换成其原码

	//			比较简单的处理方法就是读到的数据直接和0x800000进行异或
	//			这时最高位可以看做是有效位
	//			不代表符号位而代表的下一位的进位
	//			这样数据会一直往上增长 
	//			我们可以直接拿来进行使用
	value = value^0x800000;
//	value = value&0x7FFFFF;
	value = value >> 2; 
	//第25个脉冲结束
	GPIO_ResetBits(GPIOA,CLK);
	
	SysTick_Delay_us(2);//delay_us(2);
	
	return value;

}


void Get_No_Lode(void)
{
	HX720_Buffer = Sensor_Read();
	
	Weight_No_Lode = HX720_Buffer;
	
	No_Load_Flag = 1;
}

float Get_Weight(void)
{
	//HX720_Buffer = Sensor_Read();
	HX720_Buffer=  HX711_Read();	//??128
	
	Weight_Lode = HX720_Buffer;
		
	//判断非空载
	if(Weight_Lode > Weight_No_Lode)
	{
		Weight_Real = (Weight_Lode - Weight_No_Lode)/Kp_Weight;
	}
	else if(Weight_Lode <= Weight_No_Lode)
		Weight_Real = 0.0f;
	
	//拉力达到一定阈值 则串口显示
//	if(Weight_Real>100.0f)
//		printf("当前拉力%u\r\n\r\n",Weight_Real);
	
	return Weight_Real;


}

void Weigt_DisSmg(float weightValue) 
{
	static uint8_t tenthousand_bit,thousand_bit,hundred_bit,ten_bit,unit_bit,decimals_bit; 
	
	uint32_t unitPlace,tenPlace,hundredPlace,thousandPlace,tenthousandPlace;
    uint32_t DecValue_high,DecValue_low,DecValue_total;
	
	char temp1,temp2;
	uint8_t bithigh,bitlow;
	char *pchar_h,*pchar_l;
	
	uint32_t  temp;// =0xabcd,
	
	temp = (uint32_t)weightValue;
	
	
	
	
	bithigh=temp>>8; //0xab
	
	bitlow= temp & 0x00FF; //0xcd
	
	temp1 = (char)bithigh;
	temp2 = (char)bitlow;
	
	
	
	pchar_h = &temp1;
	pchar_l = &temp2;
	

	
	//char *pinter ;
	
	
	
	#if 0
	if(weightValue < 1){
		weightValue = weightValue *100;
		if(weightValue >= 1) {
			unitPlace =(uint32_t)(weightValue/1)%10; 
			tenPlace =(uint32_t)(weightValue/10)%10;
			hundred_bit = 0;
		    decimals_bit = 0x0A; //decimals point
			
			SmgDisplay(digital_1,0x0b); //"NULL"
	        SmgDisplay(digital_2,0x0b);// NULL
			SmgDisplay(digital_3,hundred_bit);  //'0'
			SmgDisplay(digital_3,decimals_bit); //'.'
			SmgDisplay(digital_4,ten_bit);
			SmgDisplay(digital_5,unit_bit);
		}
		else{
		
		    SmgDisplay(digital_1,0x0b); //"NULL"
	        SmgDisplay(digital_2,0x0b);// NULL
			SmgDisplay(digital_3,0x0b);  //NULL
			//SmgDisplay(digital_3,decimals_bit); //NULL
			SmgDisplay(digital_4,0x0b);  //NULL
			SmgDisplay(digital_5,0);
		
		}
		
		// unitPlace =(float)((((weightValue + 0.05)*10))/10);
	
	}
    else{
	#endif 
	
	  DecValue_high = hexToDec(pchar_h);
	  DecValue_low = hexToDec(pchar_l);
	  
	  DecValue_total = DecValue_high *256 + DecValue_low;
	 
	  
	//  DecValue = 20;
	  
	 unitPlace =(uint32_t) (DecValue_total/1)%10; 
	
	 tenPlace =(uint32_t)(DecValue_total/10)%10;

	 hundredPlace =(uint32_t) (DecValue_total/100)%10;
	 thousandPlace =(uint32_t) (DecValue_total/1000)%10;
	 tenthousandPlace =(uint32_t) (DecValue_total/10000)%10;
	 
	 
	 
	  
	 if(tenthousandPlace == 0){ 
		tenthousand_bit = 0x0b;
	  }
     else{
	  
	   tenthousand_bit =tenthousandPlace;
	 }	 
      
		 
	 	
	 if(thousandPlace ==0){
		 if(tenthousand_bit==0x0b)
		    thousand_bit = 0x0b;
	 }
	 else{
		thousand_bit=thousandPlace;
	 }
	  
	 if(hundredPlace ==0){
		  if(thousand_bit ==0x0b)
		      hundred_bit = 0x0b;
	  }
	  else{
	  
	     hundred_bit =hundredPlace;
	  }
	  
	  if(tenPlace ==0){
		  if( hundred_bit == 0x0b)
		     ten_bit =0x0b;
	  }
	  else ten_bit =tenPlace;
	  
	   unit_bit=unitPlace;
	   
	  
	  
	   SmgDisplay(digital_1,tenthousand_bit); //"F"
	   SmgDisplay(digital_2,thousand_bit);//'1'
	   SmgDisplay(digital_3,hundred_bit);
	   SmgDisplay(digital_4,ten_bit);
	   SmgDisplay(digital_5,unit_bit);
 }
	

/**********************************************************************
***********************************************************************/
//****************************************************
//??HX711
//****************************************************
unsigned long HX711_Read(void)	//??128
{
		unsigned long val = 0; 
	unsigned char i = 0; 

	//DATA
	while(GPIO_ReadInputDataBit(GPIOA,DATA));
	
	SysTick_Delay_Ms(1);
	//sck ??
	GPIO_ResetBits(GPIOA,CLK);
	//read data 
	//while(!GPIO_ReadInputDataBit(GPIOA,DATA)){
	
		//LED_Fun();
	
	//};
  
	for(i=0;i<24;i++) 
	{ 
		SysTick_Delay_Ms(100);//delay_us(100); 
		GPIO_SetBits(GPIOA,CLK);	   
		val=val<<1; 
		SysTick_Delay_Ms(1);//delay_us(1);  
		GPIO_ResetBits(GPIOA,CLK);	   
		if(GPIO_ReadInputDataBit(GPIOA,DATA))  //
		val++; 
		SysTick_Delay_Ms(1);//delay_us(1); 
	} 
	GPIO_SetBits(GPIOA,CLK); 
	val = val^0x800000; 
	SysTick_Delay_Ms(1);//delay_us(1); 
	GPIO_ResetBits(GPIOA,CLK); 
	SysTick_Delay_Ms(1);//delay_us(1);  
	return val; 
}
#if 1
//****************************************************
//??????
//****************************************************
float  Get_Maopi(void)
{
	Weight_Maopi = HX711_Read();
    return Weight_Maopi ;	
} 

//****************************************************
//??
//****************************************************
float Get_Weight_2(void)
{
	
	HX720_Buffer = HX711_Read();
	Weight_Shiwu = HX720_Buffer;
	Weight_Shiwu = Weight_Shiwu - Weight_Maopi;				//?????AD?????
	Weight_Shiwu = (long)((float)Weight_Shiwu/GapValue); 	
	return Weight_Shiwu;
}
#endif 

/***********************************************************
*
*
* Hex = 0xab(1gital)
*
*
***********************************************************/
static long hexToDec(char *source)
{
	long sum=0;
	long t=1;
	int i,len;
	
	
	for(i=0;i>=0;i--)
	{
		sum += t*getIndexOfStings(*(source+i));
		t *=16;
	}
	return sum;
}


static uint32_t getIndexOfStings(char  ch)
{
	if(ch >='0' && ch<='9')
	{
		return ch- '0';
	}
	
	if(ch >='A' && ch<='F')
	{
		return ch- 'A'+10;
	}
	
	if(ch >='a' && ch<='f')
	{
		return ch- 'a'+10;
	}
	
}
#if 0
int main(int argc, char *argv[]) {
	
		char *hex = "9a";
		printf("hex = \t %s\n",hex);
		printf("dec=  \t%ld\n",hexToDec(hex));
		
		return 0;

}
#endif 
