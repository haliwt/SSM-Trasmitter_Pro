#include "printf.h"
#include <stdio.h>
USART_InitType USART_InitStructure_2;

void Printf_GPIO_Configuration(void)
{
	GPIO_InitType GPIO_InitStructure;

    /* Initialize GPIO_InitStructure */
    GPIO_InitStruct(&GPIO_InitStructure);
	
	
	 /* Enable GPIO clock */
    GPIO_APBxClkCmd(USARTx_GPIO_CLK, ENABLE);
    /* Enable USARTx Clock */
    USART_APBxClkCmd(USARTx_CLK, ENABLE);

    /* Configure USARTx Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTx_TxPin;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = USARTx_Tx_GPIO_AF;
    GPIO_InitPeripheral(USARTx_GPIO, &GPIO_InitStructure);
    
    /* Configure USARTx Rx as alternate function push-pull and pull-up */
    GPIO_InitStructure.Pin            = USARTx_RxPin;
    GPIO_InitStructure.GPIO_Pull      = GPIO_Pull_Up;
    GPIO_InitStructure.GPIO_Alternate = USARTx_Rx_GPIO_AF;
    GPIO_InitPeripheral(USARTx_GPIO, &GPIO_InitStructure);
	
	  /* USARTy and USARTz configuration ------------------------------------------------------*/
    USART_StructInit(&USART_InitStructure_2);
    USART_InitStructure_2.BaudRate            = 115200;
    USART_InitStructure_2.WordLength          = USART_WL_8B;
    USART_InitStructure_2.StopBits            = USART_STPB_1;
    USART_InitStructure_2.Parity              = USART_PE_NO;
    USART_InitStructure_2.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure_2.Mode                = USART_MODE_RX | USART_MODE_TX;

    /* Configure USARTx */
    USART_Init(USARTx, &USART_InitStructure_2);
    /* Enable the USARTx */
    USART_Enable(USARTx, ENABLE);

    /* Output a message on Hyperterminal using printf function */
    printf("\n\rUSART Printf Example: retarget the C library printf function to the USART\n\r");

}



void Printf_RCC_Configuration(void)
{



}
/* retarget the C library printf function to the USART */
int fputc(int ch, FILE* f)
{
    USART_SendData(USARTx, (uint8_t)ch);
    while (USART_GetFlagStatus(USARTx, USART_FLAG_TXDE) == RESET)
        ;

    return (ch);
}

#if 0
#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param file pointer to the source file name
 * @param line assert_param error line source number
 */
void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif 

#endif 
