#include "hx720.h"

#define HX720_CLK_H()   (GPIO_SetBits(CLK_GPIO,CLK))
#define HX720_CLK_L()   (GPIO_ResetBits(CLK_GPIO,CLK))
#define GetDataPinState()    (GPIO_ReadInputDataBit(DATA_GPIO,DATA))

uint8_t HX720_ReadDataFlag=0;

//static uint32_t getIndexOfStings(char ch);
//static long hexToDec(char *source);
//����ѹ���������ͺţ�	HX711

//����ϵ��ȷ�����ݣ�
//	42500 	-->  160g --> 265.65
//	80000 	-->  285g --> 280.7
//	115000 	-->  405g --> 283.95
//	405000 	--> 1400g --> 289.29
//���ֱ�ߣ�
// y = 291.92x-3580.2 (���Խؾ�)

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
	
	//RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
	 
   // RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_GPIOB, ENABLE);
    //output CLK
	GPIO_InitStruct(&GPIO_InitStructure);
    /* GPIOC Configuration:Pin6, 7, 8 and 9 as alternate function push-pull */
    GPIO_InitStructure.Pin        = CLK;
	GPIO_InitStructure.GPIO_Pull    = GPIO_Pull_Up;//GPIO_No_Pull;
    GPIO_InitStructure.Pin  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Current = GPIO_DC_8mA;

    GPIO_InitPeripheral(CLK_GPIO, &GPIO_InitStructure);
	
	
	//�����߸�������
	GPIO_InitStructure.Pin = DATA;	
	GPIO_InitStructure.Pin = GPIO_Mode_Input;//GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Current = GPIO_DC_4mA; 
	GPIO_InitPeripheral(DATA_GPIO,&GPIO_InitStructure);

}

uint32_t Sensor_Read(void)
{
    uint32_t value;
	uint8_t i;
	
	//ÿ�ζ�ȡ����ǰ��֤�����ߵ�ƽ�ȶ�
	//�˴�ֻ��Ϊ���ȶ���ƽ ���߻�����Ч����ͬ
	GPIO_OutputInit(DATA_GPIO, DATA);
	 //GPIO_ResetBits(Sensor_Gpio,DATA);
	GPIO_SetBits(DATA_GPIO,DATA);
	
	//Ϊ�˵ȴ������ƽ�ȶ�
	//��ÿ��һ������ƽʱ��΢С��ʱ
	SysTick_Delay_us(2);//delay_us(2);
	GPIO_OutputInit(CLK_GPIO, CLK);
	//ʱ�������� ����ʱʱ���߱��ֵ͵�λ
	 GPIO_ResetBits(CLK_GPIO, CLK); //1//GPIO_ResetBits(Sensor_Gpio,CLK);
	
	SysTick_Delay_us(2);//delay_us(2);	
	
	//�ȴ�ADת������
	GPIO_ResetBits(DATA_GPIO,DATA);
	while(GPIO_ReadInputDataBit(DATA_GPIO,DATA));
	GPIO_InputInit(DATA_GPIO, DATA);
	GPIO_OutputInit(CLK_GPIO, CLK);
	
	for(i=0;i<24;i++)
	{
		//ʱ�������� ��ʼ����ʱ������
		GPIO_SetBits(CLK_GPIO,CLK);
		
		SysTick_Delay_us(1);//delay_us(2);
		
		//����λ �Ҳಹ�� �ȴ���������
		value = value << 1;
		
		//ʱ��������
		GPIO_ResetBits(CLK_GPIO,CLK);
		
		SysTick_Delay_us(2);//delay_us(2);
		
		//��ȡһλ����
		if(GPIO_ReadInputDataBit(DATA_GPIO,DATA))
			value ++;
	}
	
	//��25������
	GPIO_SetBits(CLK_GPIO,CLK);
	
	//SysTick_Delay_us(2);//delay_us(2);

	//��25�������½��ص���ʱ ת������
	//�˴�˵����
	//			HX711��һ��24λ��ADת��оƬ
	//			���λ�Ƿ���λ ����Ϊ��Чλ
	//			���������Сֵ0x800000
	//					���ֵ0x7FFFFF
	//������㣺
	//			��ͬΪ0 
	//			��ͬΪ1
	//���ݴ���˵����
	//			֮���Իᷢ�� INPA-INNA < 0mv �����
	//			����Ϊ���������Ư��
	//			������������ݾ��ǳ�ʼ״̬INPA-INNA = -0.5mv
	//			Ȼ���������������ӻᷢ�������
	//			��ʱ���ֱ��ʹ�ö�ȡ�������ݾͻᷢ������
	//			��Ϊ��ȡ������С��0�Ķ����Ʋ���
	//			�ǲ���ֱ��ʹ�õ� ��Ҫת������ԭ��

	//			�Ƚϼ򵥵Ĵ����������Ƕ���������ֱ�Ӻ�0x800000�������
	//			��ʱ���λ���Կ�������Чλ
	//			����������λ����������һλ�Ľ�λ
	//			�������ݻ�һֱ�������� 
	//			���ǿ���ֱ����������ʹ��
	value = value^0x800000;
	//value = value&0x7FFFFF;
	
	//��25���������
	GPIO_ResetBits(CLK_GPIO,CLK);
	
	//SysTick_Delay_us(2);//delay_us(2);
	//HX720_ReadDataFlag=1;
	
	return value;

}


void Get_No_Lode(void)
{
	//HX720_Buffer = Sensor_Read();
	
	Weight_No_Lode = HX720_Buffer;
	
	
	No_Load_Flag = 1;
}

float Get_Weight(void)
{
	//HX720_Buffer = Sensor_Read();
	//HX720_Buffer=  HX711_Read();	//??128
	
	HX720_Buffer= GetHX720Data();
	
	Weight_Lode = HX720_Buffer;
		
	//�жϷǿ���
	if(Weight_Lode > Weight_No_Lode)
	{
		Weight_Real = (Weight_Lode - Weight_No_Lode)/Kp_Weight;
	}
	else if(Weight_Lode <= Weight_No_Lode)
		Weight_Real = 0.0f;
	
	//�����ﵽһ����ֵ �򴮿���ʾ
//	if(Weight_Real>100.0f)
//		printf("��ǰ����%u\r\n\r\n",Weight_Real);
	
	return Weight_Real;


}

void Weigt_DisSmg(float weightValue) 
{
	
	uint32_t unitPlace,tenPlace,hundredPlace,thousandPlace,onethousandPlace,hundredthousandPlace,tenthousandPlace;

	 
    hundredthousandPlace = (uint32_t) (weightValue/1000000)%10;
	
	tenthousandPlace = (uint32_t) (weightValue/100000)%10;
	
	onethousandPlace =(uint32_t) (weightValue/10000)%10;
	 
	 thousandPlace =(uint32_t) (weightValue /1000)%10;//(weightValue/1000)%10;
	  
	 hundredPlace =(uint32_t) (weightValue/100)%10;
	 
	 tenPlace =(uint32_t)(weightValue/10)%10;
	 
	 unitPlace =(uint32_t) (weightValue/1)%10; 
	
	 SysTick_Delay_Ms(5);
	 if(hundredthousandPlace ==0){
		 
		 hundredthousandPlace=0x0b;
	
	 }
	 
	 if(tenthousandPlace == 0){
	    if(hundredthousandPlace==0x0b)
			tenthousandPlace =0x0b;
	  
	 }
	 
	 if(onethousandPlace == 0){ 
		 if(tenthousandPlace == 0x0b)
		     onethousandPlace  = 0x0b;
	  }
     
	  if(thousandPlace ==0){
		 if(onethousandPlace ==0x0b)
		   thousandPlace = 0x0b;
	 }
	
	 if(hundredPlace ==0){
		  if(thousandPlace ==0x0b)
		      hundredPlace = 0x0b;
	}
	 if(tenPlace ==0){
		  if( hundredPlace == 0x0b)
		     tenPlace =0x0b;
	 }
	
	 if(hundredthousandPlace==0x0b && tenthousandPlace ==0x0b ){
	  
	   SmgDisplay(digital_1,onethousandPlace); //"10000"
	   SmgDisplay(digital_2,thousandPlace);//'1000'
	   SmgDisplay(digital_3,hundredPlace); //
	   SmgDisplay(digital_4,tenPlace);
	   SmgDisplay(digital_5,unitPlace);
	 }
     else if(hundredthousandPlace ==0x0b && tenthousandPlace !=0x0b){
	   SmgDisplay(digital_1,tenthousandPlace); //"10000"
	   SmgDisplay(digital_2,onethousandPlace);//'1000'
	   SmgDisplay(digital_3,thousandPlace); //
	   SmgDisplay(digital_4,hundredPlace);
	   SmgDisplay(digital_5,tenPlace);
	 
	  }
	  else if(hundredthousandPlace !=0x0b){
	 
	   SmgDisplay(digital_1,hundredthousandPlace); //"10000"
	   SmgDisplay(digital_2,tenthousandPlace);//'1000'
	   SmgDisplay(digital_3,onethousandPlace); //
	   SmgDisplay(digital_4,thousandPlace);
	   SmgDisplay(digital_5,hundredPlace);
	  }
	 
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
	GPIO_OutputInit(DATA_GPIO, DATA);
	GPIO_ResetBits(DATA_GPIO,DATA);
	while(GPIO_ReadInputDataBit(DATA_GPIO,DATA));
	
	SysTick_Delay_us(1);
	//sck ??
	GPIO_ResetBits(CLK_GPIO,CLK);
	GPIO_SetBits(DATA_GPIO,DATA);
	//read data 
	while(!GPIO_ReadInputDataBit(DATA_GPIO,DATA));

	GPIO_InputInit(DATA_GPIO, DATA);
    GPIO_OutputInit(CLK_GPIO, CLK);
	for(i=0;i<24;i++) 
	{ 
		
		GPIO_SetBits(CLK_GPIO,CLK);	   
		val=val<<1; 
		SysTick_Delay_us(1);//delay_us(1);  
		GPIO_ResetBits(CLK_GPIO,CLK);	   
		if(GPIO_ReadInputDataBit(DATA_GPIO,DATA))  //
		val++; 
		SysTick_Delay_us(1);//delay_us(1); 
	} 
	GPIO_SetBits(CLK_GPIO,CLK);
	
	val = val^0x800000; 
	

	SysTick_Delay_us(1);//delay_us(1); 
	GPIO_ResetBits(CLK_GPIO,CLK); 
	SysTick_Delay_us(1);//delay_us(1);  
	HX720_ReadDataFlag=1;
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
#if 0
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

int main(int argc, char *argv[]) {
	
		char *hex = "9a";
		printf("hex = \t %s\n",hex);
		printf("dec=  \t%ld\n",hexToDec(hex));
		
		return 0;

}
#endif 
uint32_t GetHX720Data(void)
{
	volatile uint32_t Count=0;
	uint8_t i;
	HX720_CLK_L();//SCLK is low
	
	Count =0;
	GPIO_OutputInit(DATA_GPIO, DATA);
	GPIO_ResetBits(DATA_GPIO, DATA);
	while(GetDataPinState());
	GPIO_InputInit(DATA_GPIO, DATA);
	 GPIO_OutputInit(CLK_GPIO, CLK);
	for(i=0;i<24;i++)
	{
	   HX720_CLK_H();
	   
	   Count =Count <<1;
	   
	   HX720_CLK_L(); //PD_SCK low
	   
	   if(GetDataPinState())
	     Count++;
	
	}
	
	HX720_CLK_H();
	Count = Count ^ 0x800000;
	

    HX720_CLK_L();
    
    return (Count);

}

void RunHX720Cmd(vodi)
{
	
		Get_Weight();//Weight_Real=HX711_Read();//GetHX720Data();//Get_Weight();
		//Weight_Real = 0x100;
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
		SysTick_Delay_Ms(1000);
		 keydata = ScanKey();
		 if(keydata == 0xff)keydata=0;
		 if(keydata !=0)run_t.dispCmd=1;
		Get_Weight();//Weight_Real=HX711_Read();//GetHX720Data();//Get_Weight();
		//Weight_Real = 0x0A;
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
        SysTick_Delay_Ms(1000);
		Get_Weight();//Weight_Real=HX711_Read();//GetHX720Data();//Get_Weight();
		//Weight_Real = 0x0A;
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
		SysTick_Delay_Ms(1000);
	  

}
