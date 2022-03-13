#include "flash.h"


typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} Status;

void DMA_Flash_SRAM_Config(void);
uint8_t Buffercmp(const uint32_t* pBuffer1, uint32_t* pBuffer2, uint32_t BufferLength);

#define BUFFER_SIZE 		(uint32_t)32

#define FLASH_PAGE_SIZE        ((uint16_t)0x800)
#define FLASH_WRITE_START_ADDR ((uint32_t)0x08010000)
#define FLASH_WRITE_END_ADDR   ((uint32_t)0x08018000)

#define FLASH_PROGRAM_TIMEOUT ((uint32_t)0x00002000)

#define BUFFER_SIZE (uint32_t)32

uint32_t Flash_Data_Buffer[BUFFER_SIZE] __attribute__((at(FLASH_WRITE_START_ADDR)));

const uint32_t SRAM_Data_Buffer[BUFFER_SIZE] = {
    0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10, 0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20,
    0x21222324, 0x25262728, 0x292A2B2C, 0x2D2E2F30, 0x31323334, 0x35363738, 0x393A3B3C, 0x3D3E3F40,
    0x41424344, 0x45464748, 0x494A4B4C, 0x4D4E4F50, 0x51525354, 0x55565758, 0x595A5B5C, 0x5D5E5F60,
    0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70, 0x71727374, 0x75767778, 0x797A7B7C, 0x7D7E7F80};


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
	uint8_t Test_Result = 0;
	
	/* Unlocks the FLASH Program Erase Controller */
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

            /* Wait for last operation to be completed */
            while (FLASH_COMPL == FLASH_WaitForLastOpt(FLASH_PROGRAM_TIMEOUT))
            {
                /* Check */
                if (PASSED == Buffercmp(SRAM_Data_Buffer, Flash_Data_Buffer, BUFFER_SIZE))
                {
                    /* Test PASSED */
                    Test_Result = PASSED;
                    break;
                }
            }
        }
        else
        {
            /* Test Fail */
            Test_Result = FAILED;
        }
    }
    else
    {
        /* Test Fail */
        Test_Result = FAILED;

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
