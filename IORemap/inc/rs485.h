#ifndef __RS485_H_
#define __RS485_H_
#include "main.h"


//#define _USART1_
//#define  _USART2_
#define _USART3_UART4_
//#define _UART4_UART5_

#ifdef _USART1_  // _USART2_
#define USARTy            USART1
#define USARTy_GPIO       GPIOA
#define USARTy_CLK        RCC_APB2_PERIPH_USART1
#define USARTy_GPIO_CLK   RCC_APB2_PERIPH_GPIOA
#define USARTy_RxPin      GPIO_PIN_10
#define USARTy_TxPin      GPIO_PIN_9
#define USARTy_Rx_GPIO_AF GPIO_AF4_USART1
#define USARTy_Tx_GPIO_AF GPIO_AF4_USART1
#define USARTy_APBxClkCmd RCC_EnableAPB2PeriphClk
#define USARTy_IRQn       USART1_IRQn
#define USARTy_IRQHandler USART1_IRQHandler
#endif 

#ifdef _USART2_
#define USARTz            USART2
#define USARTz_GPIO       GPIOB
#define USARTz_CLK        RCC_APB1_PERIPH_USART2
#define USARTz_GPIO_CLK   RCC_APB2_PERIPH_GPIOB
#define USARTz_RxPin      GPIO_PIN_5
#define USARTz_TxPin      GPIO_PIN_4
#define USARTz_Rx_GPIO_AF GPIO_AF6_USART2
#define USARTz_Tx_GPIO_AF GPIO_AF4_USART2
#define USARTz_APBxClkCmd RCC_EnableAPB1PeriphClk
#define USARTz_IRQn       USART2_IRQn
#define USARTz_IRQHandler USART2_IRQHandler
#endif

#ifdef _USART3_UART4_
#define USARTy            USART3
#define USARTy_GPIO       GPIOC
#define USARTy_CLK        RCC_APB1_PERIPH_USART3
#define USARTy_GPIO_CLK   RCC_APB2_PERIPH_GPIOC
#define USARTy_RxPin      GPIO_PIN_11
#define USARTy_TxPin      GPIO_PIN_10
#define USARTy_Rx_GPIO_AF GPIO_AF5_USART3
#define USARTy_Tx_GPIO_AF GPIO_AF5_USART3
#define USARTy_APBxClkCmd RCC_EnableAPB1PeriphClk
#define USARTy_IRQn       USART3_IRQn
#define USARTy_IRQHandler USART3_IRQHandler
#endif 

#ifdef _USART4_
#define USARTz            UART4
#define USARTz_GPIO       GPIOD
#define USARTz_CLK        RCC_APB2_PERIPH_UART4
#define USARTz_GPIO_CLK   RCC_APB2_PERIPH_GPIOD
#define USARTz_RxPin      GPIO_PIN_12
#define USARTz_TxPin      GPIO_PIN_13
#define USARTz_Rx_GPIO_AF GPIO_AF6_UART4
#define USARTz_Tx_GPIO_AF GPIO_AF6_UART4
#define USARTz_APBxClkCmd RCC_EnableAPB2PeriphClk
#define USARTz_IRQn       UART4_IRQn
#define USARTz_IRQHandler UART4_IRQHandler
#endif

#ifdef _UART4_UART5_
#define USARTy            UART4
#define USARTy_GPIO       GPIOC
#define USARTy_CLK        RCC_APB2_PERIPH_UART4
#define USARTy_GPIO_CLK   RCC_APB2_PERIPH_GPIOC
#define USARTy_RxPin      GPIO_PIN_11
#define USARTy_TxPin      GPIO_PIN_10
#define USARTy_Rx_GPIO_AF GPIO_AF6_UART4
#define USARTy_Tx_GPIO_AF GPIO_AF6_UART4
#define USARTy_APBxClkCmd RCC_EnableAPB2PeriphClk
#define USARTy_IRQn       UART4_IRQn
#define USARTy_IRQHandler UART4_IRQHandler

#define USARTz            UART5
#define USARTz_GPIO       GPIOB
#define USARTz_CLK        RCC_APB2_PERIPH_UART5
#define USARTz_GPIO_CLK   RCC_APB2_PERIPH_GPIOB
#define USARTz_RxPin      GPIO_PIN_9
#define USARTz_TxPin      GPIO_PIN_8
#define USARTz_Rx_GPIO_AF GPIO_AF6_UART5
#define USARTz_Tx_GPIO_AF GPIO_AF6_UART5
#define USARTz_APBxClkCmd RCC_EnableAPB2PeriphClk
#define USARTz_IRQn       UART5_IRQn
#define USARTz_IRQHandler UART5_IRQHandler
#endif

#define MAX_RX_BUFFER_SIZE    8
#define MAX_BUFFER_SIZE       9

extern uint8_t outputBuf[MAX_BUFFER_SIZE];

typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} TestStatus;

typedef struct{
    uint8_t rs485_Rx_flag;
	  uint8_t rs485_Tx_flag;
	  uint8_t rs485_RxCounter;
	  uint8_t rs485_TxCounter;
	  uint8_t rs485_Rx_OK;
	  
}RS485;

extern RS485 rs485_t;

extern uint8_t TxcrcTwo_byte, TxcrcOne_byte;


TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

void UART_GPIO_Configuration(void);
void UART_RCC_Configuration(void);
void UART_NVIC_Configuration(void);
void RS485_SendData(void);
void RS485_ReceiveData(void);

extern void (*USART_Interrpt_RxHandler)(void);
extern void (*USART_Interrpt_TxHandler)(void);
extern void ISR_TxBack(void(*interruptHandler)(void));

void USART_SetRxInterruptHandler(void (* interruptHandler)(void));
void USART_SetTxInterruptHandler(void (* interruptHandler)(void));

extern uint8_t RxBuffer1[MAX_RX_BUFFER_SIZE];
void CRC16Calc_TX(void);

void RS485_RX_TX_SendData(void);
#endif 
