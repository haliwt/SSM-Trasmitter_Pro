#include "flash.h"

flash flash_t;
QUEUE queue_t;


typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} Status;


uint8_t Buffercmp(const uint32_t* pBuffer1, uint32_t* pBuffer2, uint32_t BufferLength);




#define FLASH_WRITE_START_ADDR ((uint32_t)0x08010000)
#define FLASH_WRITE_END_ADDR   ((uint32_t)0x08018000)

#define FLASH_PROGRAM_TIMEOUT ((uint32_t)0x00002000)

#define BUFFER_SIZE (uint32_t)32



void Flash_DMA_WriteData(void);


uint32_t Flash_Data_Buffer[BUFFER_SIZE] __attribute__((at(FLASH_WRITE_START_ADDR)));

//uint32_t SRAM_Data_Buffer[BUFFER_SIZE] = {
//    0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10, 0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20,
//    0x21222324, 0x25262728, 0x292A2B2C, 0x2D2E2F30, 0x31323334, 0x35363738, 0x393A3B3C, 0x3D3E3F40,
//    0x41424344, 0x45464748, 0x494A4B4C, 0x4D4E4F50, 0x51525354, 0x55565758, 0x595A5B5C, 0x5D5E5F60,
//    0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70, 0x71727374, 0x75767778, 0x797A7B7C, 0x7D7E7F80}; 


uint32_t SRAM_Data_Buffer[BUFFER_SIZE] ;//= { };




/**
 * @brief  DMA_Flash_SRAM_Config.
 */
void DMA_Flash_SRAM_Config(void)
{
    DMA_InitType DMA_InitStructure;

    /* DMA1 channel6 configuration */
    RCC_EnableAHBPeriphClk(RCC_AHB_PERIPH_DMA, ENABLE);
    DMA_InitStructure.PeriphAddr     = (uint32_t)SRAM_Data_Buffer;
    DMA_InitStructure.MemAddr        = (uint32_t)Flash_Data_Buffer;
    DMA_InitStructure.Direction      = DMA_DIR_PERIPH_SRC;
    DMA_InitStructure.BufSize        = BUFFER_SIZE;
    DMA_InitStructure.PeriphInc      = DMA_PERIPH_INC_ENABLE;
    DMA_InitStructure.DMA_MemoryInc  = DMA_MEM_INC_ENABLE;
    DMA_InitStructure.PeriphDataSize = DMA_PERIPH_DATA_SIZE_WORD;
    DMA_InitStructure.MemDataSize    = DMA_MemoryDataSize_Word;
    DMA_InitStructure.CircularMode   = DMA_MODE_NORMAL;
    DMA_InitStructure.Priority       = DMA_PRIORITY_HIGH;
    DMA_InitStructure.Mem2Mem        = DMA_M2M_ENABLE;
    DMA_Init(DMA_CH6, &DMA_InitStructure);
    DMA_ClearFlag(DMA_FLAG_TC6, DMA);
    DMA_EnableChannel(DMA_CH6, ENABLE);
}

void Flash_DMA_WriteData(void)
{
	
	
	/* Unlocks the FLASH Program Erase Controller */
   
	//SRAM_Data_Buffer[0] = 0x01020304;

    /* Erase */
   
     FLASH_Unlock();
		 /* Erase */
       if (FLASH_COMPL == FLASH_EraseOnePage(FLASH_WRITE_START_ADDR))
       {
        /* Clear All pending flags */
        FLASH_ClearFlag(FLASH_STS_CLRFLAG);

        /* Wait for last operation to be completed */
        if (FLASH_COMPL == FLASH_WaitForLastOpt(FLASH_PROGRAM_TIMEOUT))
        {
            /* if the previous operation is completed, proceed to program the new data */
            FLASH->CTRL |= FLASH_CTRL_PG;

            /* Start DMA Program FLASH */
            DMA_Flash_SRAM_Config();


        }
	   }
   
}

/**
 * @brief  Buffercmp.
 * @param  pBuffer1
 * @param  pBuffer2
 * @param  BufferLength
 */
uint8_t Buffercmp(const uint32_t* pBuffer1, uint32_t* pBuffer2, uint32_t BufferLength)
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


void FlashSaveData(void)
{
  
    uint8_t i=0;
	 
    pfdata =  SRAM_Data_Buffer;
	
	//	*pfdata = (0x03 <<24)|(0x2<<16)|(0x3<<8)|0x04; //0x01020304
	//  *(pfdata+1) = (0x05 <<24)|(0x6<<16)|(0x7<<8)|0x08; //0x05060708

    Flash_DMA_WriteData();
}

//$)Ao?=o?=H!V8o?=o?=o?=o?=V7o?=o?=R;o?=o?=o?=o?=(32N;o?=o?=o?=o?=) 
//faddr:$)Ao?=o?=o?=o?=V7 
//$)Ao?=o?=o?=o?=V5:o?=o?=S&o?=o?=o?=o?=.
uint32_t STMFLASH_ReadWord(uint32_t faddr)
{
	return *(uint32_t*)faddr; 
}  

//$)Ao?=o?=V8o?=o?=o?=o?=V7o?=o?=J<o?=o?=o?=o?=V8o?=o?=o?=o?=o?=H5o?=o?=o?=o?=o?=
//ReadAddr:$)Ao?=o?=J<o?=o?=V7
//pBuffer:$)Ao?=o?=o?=o?=V8o?=o?=
//NumToRead:$)Ao?=o?=(32N;)o?=o?=
void STMFLASH_Read(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t NumToRead)   	
{
	uint32_t i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadWord(ReadAddr);//4 of words 
		ReadAddr+=4;//$)AF+o?=o?=4o?=o?=o?=V=o?=.	
		
		printf("ReadAddr = %x",pBuffer[i]);
	}
}

void Flash_Read(void)
{

	uint32_t Counter_Num =0;
    FLASH_Unlock();
	if(flash_t.flashRead_flag==0){
	
		   for (Counter_Num = 0; Counter_Num < FLASH_PAGE_SIZE; Counter_Num += 4)
		   {
			  flash_t.flashData[Counter_Num]= *(__IO uint32_t*)(FLASH_WRITE_START_ADDR + Counter_Num);
                
			   
			    printf("data[] =%X\n", flash_t.flashData[Counter_Num]);
			    printf("Counter_Num=%d\n",Counter_Num);
		   }
		  if(Counter_Num   >= FLASH_PAGE_SIZE) flash_t.flashRead_flag= 1;
			
   }


}


void InitQueue(void)
{
     queue_t.front = queue_t.rear =0;

}


uint8_t QueueEmpty(void)
{
	if(queue_t.rear == queue_t.front){
		return 1;
	}
	else 
		return 0;


}

uint8_t EnQueue(uint8_t qdat)
{
   if((queue_t.rear+1)%DATA_MAXSIZE == queue_t.front){
		return 0;
   }

   queue_t.quData[queue_t.rear]=qdat; //data insert queue in the end of 
   queue_t.rear = (queue_t.rear +1)%DATA_MAXSIZE ;
   return 1;
}

uint8_t DeQueue(uint8_t qdat)
{
   if(queue_t.rear == queue_t.front)
   	    return 0;

   qdat= queue_t.quData[queue_t.front];
   queue_t.front = (queue_t.front +1)%DATA_MAXSIZE; //head pointer move next position
   
   return 1;

}

uint8_t GetHead_Queue(uint8_t qdat)
{
     if(queue_t.rear == queue_t.front)
          return 0;

	 qdat = queue_t.quData[queue_t.front];

	  return 1;

}

uint8_t QueueNum(void)
{
    return (queue_t.rear -queue_t.front + DATA_MAXSIZE)%DATA_MAXSIZE;


}





