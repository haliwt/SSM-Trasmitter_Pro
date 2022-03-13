#ifndef __FLASH_H__
#define __FLASH_H__

#include "main.h"

#define FLASH_PAGE_SIZE        ((uint16_t)0x800)
#define FLASH_WRITE_START_ADDR ((uint32_t)0x08010000)
#define FLASH_WRITE_END_ADDR   ((uint32_t)0x08018000)

#define FLASH_PROGRAM_TIMEOUT ((uint32_t)0x00002000)

#define BUFFER_SIZE (uint32_t)32




void Flash_DMA_WriteData(void);



#endif 

