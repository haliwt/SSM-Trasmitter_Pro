#include "tim.h"
#include "main.h"

TIM_TimeBaseInitType TIM_TimeBaseStructure;
OCInitType TIM_OCInitStructure;
uint16_t PrescalerValue = 0;

/**
 * @brief  Configures tim1 clocks.
 * TIM1 CLK=64M 
 * TIM1 CLK(HSI)=8MHz
 * timers 1 overflow times = ((arr+1)*(prescaler+1))/(Timer frequency MHz)
 *           =(65535+1)*(prescale+1)/64MHz= 1024us=1.024ms
 *
 */
void Timer1_Configuration()
{
    /* Compute the prescaler value  TIM1 CLK=64M */
    PrescalerValue = 0; //(uint16_t) (SystemCoreClock / 12000000) - 1;
												//Timer = 8000000/4000   = 2ms -1 
    /* Time base configuration */
    TIM_TimeBaseStructure.Period    = 4000-1;//4000-1 -> 1ms //800-2ms//16000;//32000;//65535;
    TIM_TimeBaseStructure.Prescaler =0;//0;
    TIM_TimeBaseStructure.ClkDiv    = 0;  // 1/2
    TIM_TimeBaseStructure.CntMode   = TIM_CNT_MODE_UP;

    TIM_InitTimeBase(TIM1, &TIM_TimeBaseStructure);

    /* Prescaler configuration */
    TIM_ConfigPrescaler(TIM1, PrescalerValue, TIM_PSC_RELOAD_MODE_IMMEDIATE);

    /* TIM1 enable update irq */
    TIM_ConfigInt(TIM1, TIM_INT_UPDATE, ENABLE);

    /* TIM1 enable counter */
    TIM_Enable(TIM1, ENABLE);
}
/**
 * @brief  Configures the different system clocks.
 */
void RCC_Configuration(void)
{
    /* PCLK1 = HCLK/4 */
    RCC_ConfigPclk2(RCC_HCLK_DIV4);

    /* TIM1 clock enable */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_TIM1, ENABLE);

    /* GPIOC clock enable */
  //  RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
}

/**
 * @brief  Configure the nested vectored interrupt controller.
 */
/**
 * @brief  Configure the nested vectored interrupt controller.
 */
void TIM1_NVIC_Configuration(void)
{
    NVIC_InitType NVIC_InitStructure;

    /* Enable the TIM1 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = TIM1_UP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}
#if 1
/**
 * @brief  Configure the GPIO Pins.
 */
void GPIO_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

	  GPIO_InitStruct(&GPIO_InitStructure);
    /* GPIOC Configuration:Pin6, 7, 8 and 9 as alternate function push-pull */
    GPIO_InitStructure.Pin        = GPIO_PIN_8 | GPIO_PIN_9;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Current = GPIO_DC_4mA;

    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
}

#endif 
