#ifndef __PRINTF_H_
#define __PRINTF_H_
#include "main.h"

//#define _USART1_COM_
 #define _USART2_COM_

#ifdef _USART1_COM_
#define USARTx            USART1
#define USARTx_GPIO       GPIOA
#define USARTx_CLK        RCC_APB2_PERIPH_USART1
#define USARTx_GPIO_CLK   RCC_APB2_PERIPH_GPIOA
#define USARTx_RxPin      GPIO_PIN_10
#define USARTx_TxPin      GPIO_PIN_9
#define USARTx_Rx_GPIO_AF GPIO_AF4_USART1
#define USARTx_Tx_GPIO_AF GPIO_AF4_USART1

#define GPIO_APBxClkCmd   RCC_EnableAPB2PeriphClk
#define USART_APBxClkCmd  RCC_EnableAPB2PeriphClk
#endif

#ifdef _USART2_COM_
#define USARTx            USART2
#define USARTx_GPIO       GPIOB//GPIOA
#define USARTx_CLK        RCC_APB1_PERIPH_USART2
#define USARTx_GPIO_CLK   RCC_APB2_PERIPH_GPIOB //RCC_APB2_PERIPH_GPIOA
#define USARTx_RxPin      GPIO_PIN_5//GPIO_PIN_3
#define USARTx_TxPin      GPIO_PIN_4 //GPIO_PIN_2
#define USARTx_Rx_GPIO_AF GPIO_AF4_USART2
#define USARTx_Tx_GPIO_AF GPIO_AF4_USART2

#define GPIO_APBxClkCmd   RCC_EnableAPB2PeriphClk
#define USART_APBxClkCmd  RCC_EnableAPB1PeriphClk
#endif

void Printf_RCC_Configuration(void);
void Printf_GPIO_Configuration(void);





#endif 


