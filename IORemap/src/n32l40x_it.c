
/**
 * @file n32l40x_it.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "n32l40x_it.h"
#include "n32l40x.h"
#include "main.h"

/** @addtogroup N32L40X_StdPeriph_Template
 * @{
 */

extern __IO uint32_t CurrDataCounterEnd;

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Memory Manage exception.
 */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Bus Fault exception.
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Usage Fault exception.
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles SVCall exception.
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 */
void SysTick_Handler(void)
{
}

/**
 * @brief  This function handles DMA interrupt request defined in main.h .
 */
void DMA_IRQ_HANDLER(void)
{
}

/******************************************************************************/
/*                 N32L40X Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_n32l40x.s).                                                 */
/******************************************************************************/

/******************************************************************************/
/*                 N32L40X Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_n32l40x.s). */
/*  1ms timer interrupt                                                */
/******************************************************************************/
/**
 * @brief  This function handles TIM1 update interrupt request.
 *  1ms timer1 
 */
void TIM1_UP_IRQHandler(void)
{
    static uint32_t i,j,z,n;
    
    if (TIM_GetIntStatus(TIM1, TIM_INT_UPDATE) != RESET)
    {
        TIM_ClrIntPendingBit(TIM1, TIM_INT_UPDATE);

        /* Pin PC.06 toggling */
       // GPIO_WriteBit(GPIOB, GPIO_PIN_9, (Bit_OperateType)(1 - GPIO_ReadOutputDataBit(GPIOB, GPIO_PIN_9)));
		j++;
		if(key_t.keyTimes_1s==1){
		   if(j>100){
				j=0;
				z++;
		       if(z==3){
			   	 z=0;
				 key_t.keyTimes_ms++;
			     printf("timers_1s %d\n",key_t.keyTimes_ms);
				   if(key_t.keyPressedLongTimes <15){
					 run_t.timerOver_flag =3;
                     printf("timerOver_flag = 1sssssssssssss\n");
                     run_t.dispCmd=1;
				     key_t.RunCmd_flag= 1;
					  key_t.keyadjust_flag =3;

				   }
				 
		       	} 

		  }
		}

		if(key_t.keyTimes ==1) {
            i++;
            if(i>299){//if(i>499){ //500ms
                i=0;
                key_t.keyPressedTimes++;
				
		        if(key_t.keyPressedLongTimes >30) //54)//63)
		        {
		        	  printf("adjust is long key times!!!!!!!!!!!!!!!! \n");
					 // key_t.keyPressedLongTimes=0;
					  key_t.RunCmd_flag = 1;
					  run_t.dispCmd=1;
					  key_t.keyadjust_flag =2;
					  run_t.timerOver_flag =2;

				}
				if(key_t.keyPressedLongTimes >29  && key_t.keyPressedLongTimes <30){

					 printf("adjust is shot key times !!!!!!!!!!!!!!! \n");
					 run_t.dispCmd=1;
				     key_t.RunCmd_flag= 1;

					 key_t.keyadjust_flag =1;
					 run_t.timerOver_flag =1;
					 
				}
                if(run_t.timerOver_flag !=2 &&  run_t.timerOver_flag !=1 && key_t.keyPressedLongTimes >20){
                     run_t.timerOver_flag =3;
                     printf("timerOver_flag = 3$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
					
					 key_t.keyadjust_flag =3;

					 run_t.dispCmd=1;
				     key_t.RunCmd_flag= 1;
                }
				
            }
           
           
       }  
    }
}

/**
 * @brief  This function handles PPP interrupt request.
 */
/*void PPP_IRQHandler(void)
{
}*/

/**
 * @}
 */
