
/**
 * @file main.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "main.h"
#include <stdio.h>
#include <stdint.h>



/**
 * @brief Assert failed function by user.
 * @param file The name of the call that failed.
 * @param line The source line number of the call that failed.
 */
#ifdef USE_FULL_ASSERT
void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif // USE_FULL_ASSERT

/**
 * @brief  Main program.
 */
int main(void)
{
   
    uint8_t keydata;
	
	/*SystemInit() function has been called by startup file startup_n32l40x.s*/

	 //  SetSysClockToHSI();
      //DumpClock("HSI, 16MHz");
	
	SetSysClockToPLL(8000000, SYSCLK_PLLSRC_HSIDIV2_PLLDIV2);
    //DumpClock("HSI/2->PLL/2, 8M");
	// RCC_EnableClockSecuritySystem(ENABLE);
	
	RCC_Configuration();
    /* Initialize Led1~Led2 as output pushpull mode*/
	  Sensor_Init();
	  LED_Init();
     GPIO_OutputInit(I2C_SCL_PORT, I2C_SCL_PIN);
     GPIO_OutputInit(I2C_SDA_PORT, I2C_SDA_PIN);
	 
	  Timer1_Configuration();
	   
	 
	//GPIO_Configuration(); //test Timer1 
	  
	  TIM1_NVIC_Configuration();
	  GetKeyValua_Init();
	HX720_ReadDataFlag=0;
    while (1)
    {
			Get_Weight();
		//Weight_Real = 0x100;
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
		SysTick_Delay_Ms(1000);
		keydata = ScanKey();
		 if(keydata == 0xff)keydata=0;
		 if(keydata !=0)run_t.dispCmd=1;
		Get_Weight();
		//Weight_Real = 0x0A;
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
        SysTick_Delay_Ms(1000);
		if(run_t.dispCmd==0){
			Get_Weight();
			Weigt_DisSmg(Weight_Real) ;//(HX720_Buffer);//(Weight_Real) ;
		}
	    else{
		    
			
		    CheckMode(keydata);//KEY_Function(keydata);
            RunCommand();
			
		}
    
				 
    }
		
}
/**
 * @
 */
