#include "tm1637.h"
#include "delay.h"




const unsigned char segNumber_point[]={
	
     
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_h,        		// char "0"  0x00
         seg_b+seg_c+seg_h,                                       // char "1"  0x01
         seg_a+seg_b+seg_d+seg_e+seg_g+seg_h,              		// char "2"  0x02
         seg_a+seg_b+seg_c+seg_d+seg_g+seg_h,              		// char "3"  0x03
         seg_b+seg_c+seg_f+seg_g+seg_h,                   	    // char "4"  0x04
         seg_a+seg_c+seg_d+seg_f+seg_g+seg_h,              		// char "5"  0x05
         seg_a+seg_c+seg_d+seg_e+seg_f+seg_g+seg_h,              // char "6"  0x06
         seg_a+seg_b+seg_c+seg_f+seg_h,                    		// char "7"  0x07
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_g+seg_h,  		// char "8"  0x08
         seg_a+seg_b+seg_c+seg_d+seg_f+seg_g+seg_h,        		// char "9"  0x09
         seg_h,                                             // char "."  0x0A
         0x00                                               // Dont't display 0x0B
       
};



const unsigned char segNumber[]={
	
     
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f,        		// char "0"  0x00
         seg_b+seg_c,                                       // char "1"  0x01
         seg_a+seg_b+seg_d+seg_e+seg_g,              		// char "2"  0x02
         seg_a+seg_b+seg_c+seg_d+seg_g,              		// char "3"  0x03
         seg_b+seg_c+seg_f+seg_g,                   	    // char "4"  0x04
         seg_a+seg_c+seg_d+seg_f+seg_g,              		// char "5"  0x05
         seg_a+seg_c+seg_d+seg_e+seg_f+seg_g,              // char "6"  0x06
         seg_a+seg_b+seg_c+seg_f,                    		// char "7"  0x07
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_g,  		// char "8"  0x08
         seg_a+seg_b+seg_c+seg_d+seg_f+seg_g,        		// char "9"  0x09
         seg_h,                                             // char "."  0x0A
         0x00                                               // Dont't display 0x0B
       
};

const unsigned char segChar[]={
    seg_a+seg_b+seg_c+seg_e+seg_f+seg_g,        //'A'  ->0
    seg_a+seg_d+seg_e+seg_f,                    //'C'  ->1
    seg_b+seg_c+seg_d+seg_e+seg_g,              //'d'  ->2
    seg_a+seg_d+seg_e+seg_f+seg_g,              //'E'  ->3
    seg_a+seg_e+seg_f+seg_g,                    //'F'  ->4                 
    seg_b+seg_c+seg_e+seg_f+seg_g,              //'H'  ->5
    seg_d+seg_e+seg_f,                          //'L'  ->6
    seg_c+seg_e+seg_g,                          //'n'  ->7
    seg_c+seg_d+seg_e+seg_g,                    //'o'  ->8
    seg_a+seg_b+seg_e+seg_f+seg_g,              //'P'  ->9
    seg_a+seg_b+seg_c+seg_f+seg_g,              //'q'  ->10->0X0A
    seg_e+seg_g,                                //'r'  ->11->0X0B
    seg_d+seg_e+seg_f+seg_g,                    //'t'  ->12->0X0C
    seg_b+seg_c+seg_d+seg_f+seg_g,              //'Y'  ->13->0x0d
    seg_a+seg_d+seg_e,                          //'C'-lack   ->14->0xe
    seg_g										//'-'  ->15  ->0x0F
};

//static void Delay_us(uint8_t i);
static void I2CStart(void);
static void I2Cask(void);
static void I2CStop(void);
static void I2CWrByte(uint8_t oneByte);




/**
 * @brief  Configures LED GPIO.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void GPIO_OutputInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    /* Enable the GPIO Clock */
    if (GPIOx == GPIOA)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
    }
    else
    {
        if (GPIOx == GPIOD)
        {
            RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOD, ENABLE);
        }
    }

    /* Configure the GPIO pin */      
    if (Pin <= GPIO_PIN_ALL)
    {
        GPIO_InitStruct(&GPIO_InitStructure);
        GPIO_InitStructure.Pin        = Pin;
        GPIO_InitStructure.GPIO_Current = GPIO_DC_2mA;//GPIO_DC_4mA;
        GPIO_InitStructure.GPIO_Pull    = GPIO_Pull_Up;//GPIO_No_Pull;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP; //Output 
        GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
    }
}

/**
 * @brief  Configures key GPIO.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void GPIO_InputInit(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIO_InitType GPIO_InitStructure;

    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    /* Enable the GPIO Clock */
    if (GPIOx == GPIOA)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
    }
    else
    {
        if (GPIOx == GPIOD)
        {
            RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOD, ENABLE);
        }
    }

    /* Configure the GPIO pin as input floating*/
    if (Pin <= GPIO_PIN_ALL)
    {
        GPIO_InitStruct(&GPIO_InitStructure);
        GPIO_InitStructure.Pin        = Pin;
        GPIO_InitStructure.GPIO_Pull    = GPIO_Pull_Up;//GPIO_No_Pull;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Input;
        GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
    }
}

/**
 * @brief  Turns selected Led on as output low level.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void GPIO_SetLow(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBSC = Pin; //low
}
/**
 * @brief  Turns selected Led Off as output high level.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
void GPIO_SetHigh(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBC = Pin; //output 1
}
/***********************************************************
 * 
 * * Function Name:void SmgDisplay(disreg dg,uint8_t data)
 * Input Refer: 1: display register address 
 *              2: display on LED data
 * Retrun Refer: NO
 * 
************************************************************/
void SmgDisplay(disreg dg,uint8_t data)
{
    
	  const uint8_t *pointer;
	  pointer = segNumber;
	
	
	  I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(dg); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(*(pointer+data));//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();
}

void SmgDisplay_Point(disreg dg,uint8_t data)
{
    
	  const uint8_t *pointer;
	  pointer = segNumber_point;
	  I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(dg); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(*(pointer+data));//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();
}
/***********************************************************
 * 
 * Function Name:SmgDisplay_Character(disreg dg,uint8_t chdat)
 * Input Refer: 1: display register address 
 *              2: display on character 
 * Retrun Refer: NO
 * 
************************************************************/
void SmgDisplay_Character(disreg dg,uint8_t chdat)
{
    const uint8_t *pointerChar;
	  pointerChar = segChar;
	
	
	  I2CStart();
	 // SysTick_Delay_us(1);
	  I2CWrByte(0x44);  //siginal address
	//  SysTick_Delay_us(1);
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	//  SysTick_Delay_us(1);
	  I2CWrByte(dg); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(*(pointerChar+chdat));//I2CWrByte(0xf0);//I2CWrByte(0xff);
	//  SysTick_Delay_us(1);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
	//	SysTick_Delay_us(1);
		I2CWrByte(0x8f); //open display ,brightness max
	//	SysTick_Delay_us(1);
		I2Cask();
		I2CStop();
}
/**************************************************
 *************************************************/
void SmgDisplay_All(void)
{

        uint8_t i;
	  const uint8_t *pointer;
	  pointer = segNumber;
	  I2CStart();
	  I2CWrByte(0x40); // address auto add + 1 
	 
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc0); // display address of digit One byte
	  I2Cask();
	
	  
	
	   for(i=0;i<6;i++){          
				
			 
			 I2CWrByte(*pointer);//I2CWrByte(0xf0);//I2CWrByte(0xff);
			 I2Cask();

		}
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();


}


#if 0
void Delay_us(uint8_t nCount)
{
	//SysTick_Delay_us(i);

    uint32_t tcnt;
    while (nCount--)
    {
        tcnt = 64 / 5;
        while (tcnt--){;}
    }


}
#endif 
static void I2CStart(void)
{
  GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN); //1
	//GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);
	GPIO_SetBits(I2C_SDA_PORT, I2C_SDA_PIN);//1
	SysTick_Delay_us(20);//Delay_us(2);
	GPIO_ResetBits(I2C_SDA_PORT, I2C_SDA_PIN);

}

static void I2Cask(void)
{
		GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);
	  GPIO_InputInit(I2C_SDA_PORT, I2C_SDA_PIN);
	  SysTick_Delay_us(50);//Delay_us(5);
	
	  while(GPIO_ReadInputDataBit(I2C_SDA_PORT, I2C_SDA_PIN));
	  GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN); 
	
	  SysTick_Delay_us(20);//Delay_us(2);
	  GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);
	  GPIO_OutputInit(I2C_SDA_PORT, I2C_SDA_PIN); //EDIT 
}

static void I2CStop(void)
{
	GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);// clk=0
	SysTick_Delay_us(20);//Delay_us(2);
	
	GPIO_ResetBits(I2C_SDA_PORT, I2C_SDA_PIN); //dio=0
	SysTick_Delay_us(20);//Delay_us(2);
	GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN); //clk=1 
	SysTick_Delay_us(20);//Delay_us(2);
	GPIO_SetBits(I2C_SDA_PORT, I2C_SDA_PIN); //dio=1
}


static void I2CWrByte(uint8_t oneByte)
{
    uint8_t i;
	  for(i=0;i<8;i++){
			 GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);//clk=0;
			 if(oneByte & 0x01){ //low bit head  
				    GPIO_SetBits(I2C_SDA_PORT, I2C_SDA_PIN);//dio=1;
			 }
			 else{
					GPIO_ResetBits(I2C_SDA_PORT, I2C_SDA_PIN); //dio=0
			 
			 }
			 SysTick_Delay_us(30);//Delay_us(3);
			 oneByte = oneByte>>1;
			 GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN); //clk=1 
			  SysTick_Delay_us(30);//Delay_us(3);
		}
}

uint8_t ScanKey(void)
{
	  uint8_t rekey,i;
	
	  I2CStart();
	  SysTick_Delay_us(1);
	  I2CWrByte(0x42);
	  SysTick_Delay_us(2);
	  I2Cask();
	
	 // GPIO_OutputInit(I2C_SDA_PORT, I2C_SDA_PIN);
	  GPIO_SetBits(I2C_SDA_PORT, I2C_SDA_PIN) ;//dio=1;
	  
	  for(i=0;i<8;i++){
			 GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);//clk=0; 
			 rekey = rekey>>1;
			 SysTick_Delay_us(300);//Delay_us(30);
			 GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN); //clk=1 
			
			 GPIO_InputInit(I2C_SDA_PORT, I2C_SDA_PIN);
			if(GPIO_ReadInputDataBit(I2C_SDA_PORT, I2C_SDA_PIN)){
			        rekey =rekey | 0x80;
			 
			 }
			 else{
			     rekey =rekey | 0x00;
			 
			 }
			 SysTick_Delay_us(300);//Delay_us(30);
		}
		I2Cask();
		I2CStop();
		GPIO_OutputInit(I2C_SDA_PORT, I2C_SDA_PIN);
    return(rekey);
}
/***********************************************************
 * *
 * Function Name:void Net_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void Net_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x40);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}

/***********************************************************
 * *
 * Function Name:void CH1_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void CH1_KeyLed(void)
{
     
     I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x80);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void Peak_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void Peak_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x10);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void CH2_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void CH2_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x20);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void Valley_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void Valley_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x04);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void CH3_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void CH3_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x08);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void Mot_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void Mot_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x01);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}
/***********************************************************
 * *
 * Function Name:void CH4_KeyLed(void)
 * Input Refer: NO
 * Retrun Refer: NO
 * *
************************************************************/
void CH4_KeyLed(void)
{
     
      I2CStart();
	  I2CWrByte(0x44);  //siginal address
	
	  I2Cask();
	  I2CStop();
	
	  I2CStart();
	  I2CWrByte(0xc5); // display address of digit One byte
	  I2Cask();
	
	  I2CWrByte(0x02);//I2CWrByte(0xf0);//I2CWrByte(0xff);
	  I2Cask();
		I2CStop();
		
		I2CStart(); //EDIT 
		I2CWrByte(0x8f); //open display ,brightness max
		I2Cask();
		I2CStop();

}

void SmgDis_TurnOff_ALl(void)
{
     SmgDisplay(digital_1,0x0b);
	 SmgDisplay(digital_2,0x0b);
	 SmgDisplay(digital_3,0x0b);
	 SmgDisplay(digital_4,0x0b);
	 SmgDisplay(digital_5,0x0b);
	 
}



