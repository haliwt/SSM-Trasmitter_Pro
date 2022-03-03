#include "led.h"

/**
 * @brief  Inserts a delay time.
 * @param count specifies the delay time length.
 */
void Delay(uint32_t count)
{
    for (; count > 0; count--)
        ;
}
/**
 * @brief  Turns selected Led on as output low level.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
static void LedOn(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBSC = Pin; //output 0
}
/**
 * @brief  Turns selected Led Off as output high level.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
static void LedOff(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->PBC = Pin; //output 1
}
/**
 * @brief  Turns selected Led on or off.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be one of the following values:
 *  @arg GPIO_PIN_0~GPIO_PIN_15: set related pin on
 *      @arg (GPIO_PIN_0<<16)~(GPIO_PIN_15<<16): clear related pin off
 */
static void LedOnOff(GPIO_Module* GPIOx, uint32_t Pin)
{
    GPIOx->PBSC = Pin;
}
/**
 * @brief  Toggles the selected Led.
 * @param GPIOx x can be A to G to select the GPIO port.
 * @param Pin This parameter can be GPIO_PIN_0~GPIO_PIN_15.
 */
static void LedBlink(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->POD ^= Pin;
}

void LED_Init(void)
{
	 GPIO_InitType GPIO_InitStructure;

	 GPIO_InitStruct(&GPIO_InitStructure);
    /* GPIOC Configuration:Pin6, 7, 8 and 9 as alternate function push-pull */
    GPIO_InitStructure.Pin        = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	 GPIO_InitStructure.GPIO_Pull    = GPIO_Pull_Up;//GPIO_No_Pull;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Current = GPIO_DC_4mA;

    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

}

void LED_Fun(void)
{
  LedOn(GPIOB, GPIO_PIN_6);
  LedOn(GPIOB, GPIO_PIN_7);
  SysTick_Delay_Ms(500);
	//SysTick_Delay_us(5000);
  LedOff(GPIOB, GPIO_PIN_6);
  LedOff(GPIOB, GPIO_PIN_7);
	 // Delay(0x28FFFF);
   SysTick_Delay_Ms(500);
	//SysTick_Delay_us(5000);

}

