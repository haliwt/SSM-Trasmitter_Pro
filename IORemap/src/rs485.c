#include  "rs485.h"

#define TxBufferSize1 (countof(TxBuffer1) - 1)
#define TxBufferSize2 (countof(TxBuffer2) - 1)
#define RxBufferSize1 TxBufferSize2
#define RxBufferSize2 TxBufferSize1

#define countof(a) (sizeof(a) / sizeof(*(a)))
	
uint8_t outputBuf[MAX_BUFFER_SIZE];

uint8_t TxBuffer2[8]={0x01,0x03,0x00,0x51,0X00,0x02,0x95,0xDA};

RS485 rs485_t;

void (*USART_Interrpt_RxHandler)(void);
void (*USART_Interrpt_TxHandler)(void);	
void ISR_TxBack(void(*interruptHandler)(void));

volatile uint8_t transOngoingFlag;



//static uint8_t transferSize;
static uint8_t state;

static uint8_t state;

uint8_t crcOne_byte,crcTwo_byte;
uint8_t TxcrcTwo_byte, TxcrcOne_byte;

uint8_t RxBuffer1[MAX_RX_BUFFER_SIZE];
USART_InitType USART_InitStructure;

__IO TestStatus TransferStatus1 = FAILED;



static void CRC16Calc(void);


/**
 * @brief  Configures the different GPIO ports.
 */
void UART_GPIO_Configuration(void)
{
   GPIO_InitType GPIO_InitStructure;

    /* Initialize GPIO_InitStructure */
    GPIO_InitStruct(&GPIO_InitStructure);

    /* Configure USARTy Tx as alternate function push-pull */
    GPIO_InitStructure.Pin            = USARTy_TxPin;    
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = USARTy_Tx_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);

   

    /* Configure USARTy Rx as alternate function push-pull and pull-up */
    GPIO_InitStructure.Pin            = USARTy_RxPin;
    GPIO_InitStructure.GPIO_Pull      = GPIO_Pull_Up;
    GPIO_InitStructure.GPIO_Alternate = USARTy_Rx_GPIO_AF;
    GPIO_InitPeripheral(USARTy_GPIO, &GPIO_InitStructure);    

 

     /* USARTy and USARTz configuration ------------------------------------------------------*/
    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.BaudRate            = 19200;//115200;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure.Mode                = USART_MODE_RX | USART_MODE_TX;

    /* Configure USARTy and USARTz */
    USART_Init(USARTy, &USART_InitStructure);
   

    /* Enable USARTy Receive and Transmit interrupts */
    USART_ConfigInt(USARTy, USART_INT_RXDNE, ENABLE);
    USART_ConfigInt(USARTy, USART_INT_TXDE, ENABLE);

  

    /* Enable the USARTy and USARTz */
    USART_Enable(USARTy, ENABLE);
  


}
   



/**
 * @brief  Configures the different system clocks.
 */
void UART_RCC_Configuration(void)
{
    /* Enable GPIO clock */
    RCC_EnableAPB2PeriphClk(USARTy_GPIO_CLK , ENABLE);
    /* Enable USARTy and USARTz Clock */
    USARTy_APBxClkCmd(USARTy_CLK, ENABLE);
   
}

/**
 * @brief  Configures the nested vectored interrupt controller.
 */
void UART_NVIC_Configuration(void)
{
    NVIC_InitType NVIC_InitStructure;

    /* Configure the NVIC Preemption Priority Bits */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel            = USARTy_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd         = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	  
   
}

/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param BufferLength buffer's length
 * @return PASSED: pBuffer1 identical to pBuffer2
 *         FAILED: pBuffer1 differs from pBuffer2
 */


/****************************************************************************************************
**
*Function Name:void RS485_SendData(uint8_t index)
*Function: UART2 transmit interrupt process 
*Input Ref: weight of value 
*Return Ref:NO
*
****************************************************************************************************/
void USART_SetTxInterruptHandler(void (* interruptHandler)(void))
{
       USART_Interrpt_TxHandler=interruptHandler;

}

void ISR_TxBack(void(*interruptHandler)(void))
{
   interruptHandler();

}
void RS485_SendData(void)
{
	  uint8_t i;
   static uint8_t currsend=0xff ;
  //  tenNum=index/5; // WT.EDIT 5 group LED number 2021.04.23 remainder

		//crc=0x55;
		outputBuf[0]=0x01; //0X56
		outputBuf[1]=0x03; //0X58
		outputBuf[2]=0x04; //0X4C	// 'L' for light board
		outputBuf[3]=0x00; //0X4F	// 'O' -->SPOT BOARD,   'C' close all light command
		outputBuf[4]=0x00; //0X31	//has  three command parameter
		outputBuf[5]=0x00; //0X33   //the first = ledab.led_lr_id = 3 --left and right the same time On
		outputBuf[6]=0x00; // change to ascii number ,decimal + 0x30 ->hexadecimal
		CRC16Calc_TX();
	  outputBuf[7]=TxcrcOne_byte; //crc bit 1--0xfa
	  outputBuf[8]=TxcrcTwo_byte; //crc bit 2--0x33

	 if(rs485_t.rs485_Tx_flag != currsend){
		 rs485_t.rs485_Tx_flag = currsend;
	  //if(rs485_t.rs485_Rx_flag == PASSED){
		  currsend = rs485_t.rs485_Tx_flag;
		 // transferSize=9;
      for(i=0;i<9;i++){
				USART_SendData(USARTy, outputBuf[i]);
	      SysTick_Delay_us(800);
		 }
		
		 
		}
	 
	 
}
void RS485_RX_TX_SendData(void)
{
   uint8_t i;
	 USART_SendData(USARTy, RxBuffer1[i]);
	 i++;
	 if(i==7){
		 
		 i=0;
		// SysTick_Delay_Ms(500);
   }
}


/********************************************************************************
	**
	*Function Name:void RS485_ReceiveData(void)
	*Function :UART callback function  for UART interrupt for receive data
	*Input Ref: structure UART_HandleTypeDef pointer
	*Return Ref:NO
	*
*******************************************************************************/
void USART_SetRxInterruptHandler(void (* interruptHandler)(void))
{
    USART_Interrpt_RxHandler = interruptHandler;
}

void RS485_ReceiveData(void)
{
	 
	 	RxBuffer1[rs485_t.rs485_RxCounter++] = USART_ReceiveData(USARTy);
		if(sizeof(RxBuffer1) <= rs485_t.rs485_RxCounter)
    {
      rs485_t.rs485_RxCounter= 0;
    }
		
	
    switch(state)
		{
		case 0:  //#0
			if(RxBuffer1[0]== 0x01){  //hex :4D - "M" -fixed
				 state= 1; //=1
				 
			}
			else{
				 rs485_t.rs485_RxCounter=0;
			
			}
			
			break;
		case 1: //#1
			if(RxBuffer1[1]==0x03) //hex : 58 -'X'  -fixed 
			{
				state=2;
				
			}
			else{
				 rs485_t.rs485_RxCounter=0;
				rs485_t.rs485_Rx_flag = FAILED;
				state= 0;
			}
			break;
		case 2://#2
			if(RxBuffer1[2]==0) //hex :43 --'C'--control board
			{
				state=3;
				
			}
			else{
				 rs485_t.rs485_RxCounter=0;
				rs485_t.rs485_Rx_flag = FAILED;
				state=0;
			}
			break;
		case 3: //#3  if 'R' = hex:0x52
			if(RxBuffer1[3]==0x51){ 
			    state =4;
				 
			}
			else{
				 rs485_t.rs485_RxCounter=0;
				rs485_t.rs485_Rx_flag = FAILED;
				state=0;
			}
			break;
		case 4://#4
			if(RxBuffer1[4]==0) //hex :43 --'C'--control board
			{
				state=5;
			
			}
			else{
				 rs485_t.rs485_RxCounter=0;
				rs485_t.rs485_Rx_flag = FAILED;
				state=0;
			}
			break;
		case 5://#5
			if(RxBuffer1[5]==0x02) //hex :43 --'C'--control board
			{
				state=6;
				
			}
			else{
				  rs485_t.rs485_RxCounter=0;
				rs485_t.rs485_Rx_flag = FAILED;
				state=0;
			}
			break;
			

		 case 6:
			  CRC16Calc();
			  if(crcOne_byte == RxBuffer1[6]){ //0x95
				   state = 7;
					
				}
				else{
				 rs485_t.rs485_RxCounter=0;
					rs485_t.rs485_Rx_flag = FAILED;
					state =0;
				}
		
			break;
		case 7:
		if(crcTwo_byte == RxBuffer1[7]){  //0xda
				   
			 rs485_t.rs485_Rx_flag = PASSED;
			 rs485_t.rs485_RxCounter=0;
		  
			  
			
			state = 0;  
			
		}
		else{
			 
			 rs485_t.rs485_RxCounter=0;
		   state = 0;  
		}
		break;
		
	  default:
			 rs485_t.rs485_RxCounter=0;
		   state = 0;
		   rs485_t.rs485_Rx_flag = FAILED;
		break;
			
		}
	// TransferStatus1 = Buffercmp(TxBuffer2, RxBuffer1, RxBufferSize1);
	
}
/******************************************************
	**
  *Function Name:static void CRC16Calc(void)
  *Function :  polynomial is 0xa001 
  *Input Ref:NO
	*Return Ref:NO
	*
******************************************************/
static void CRC16Calc(void)
{
	 uint8_t n,i,*p;
	
	 uint32_t tmp,ret1;
	
	 p= outputBuf;
	 tmp= 0xffff;
	 ret1=0;
	 
	 for(n=0;n<7;n++){
		 
		   tmp = *(p+n)^tmp;
		   for(i=0;i<8;i++){
				  if(tmp & 0x01){
					       tmp =tmp >>1;
						     tmp = tmp ^ 0xa001; 
					}
					else{
						 tmp = tmp >>1;
					}
			 }
	 }
	 /*Low and high be changed position*/
	 ret1 = tmp >> 8;
	 crcTwo_byte = ret1;
	 
	 ret1 = tmp & 0x00ff;
	 crcOne_byte = ret1;
	
}
void CRC16Calc_TX(void)
{
   uint8_t n,i,*p;
	
	 uint32_t tmp,ret1;
	
	 p= outputBuf;
	 tmp= 0xffff;
	 ret1=0;
	 
	 for(n=0;n<7;n++){
		 
		   tmp = *(p+n)^tmp;
		   for(i=0;i<8;i++){
				  if(tmp & 0x01){
					       tmp =tmp >>1;
						     tmp = tmp ^ 0xa001; 
					}
					else{
						 tmp = tmp >>1;
					}
			 }
	 }
	 /*Low and high be changed position*/
	 ret1 = tmp >> 8;
	 TxcrcTwo_byte = ret1;
	 
	 ret1 = tmp & 0x00ff;
	 TxcrcOne_byte = ret1;

}
#if 0
/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param BufferLength buffer's length
 * @return PASSED: pBuffer1 identical to pBuffer2
 *         FAILED: pBuffer1 differs from pBuffer2
 */
TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
    while (BufferLength--)
    {
        if (*pBuffer1 != *pBuffer2)
        {
            return FAILED;
        }

        pBuffer1++;
        pBuffer2++;
    }

    return PASSED;
}
#endif 
