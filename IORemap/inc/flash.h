#ifndef __FLASH_H__
#define __FLASH_H__

#include "main.h"

//Ҫд�뵽STM32 FLASH���ַ�������
//const u8 TEXT_Buffer[]={"STM32 FLASH TEST"};
#define TEXT_LENTH 						sizeof(TEXT_Buffer)	 		  	//���鳤��	
//#define SIZE 							TEXT_LENTH/4+((TEXT_LENTH%4)?1:0)

#define SIZE 							128 /4 

#define FLASH_PAGE_SIZE   		 ((uint16_t)0x80) //  ((uint16_t)0x800)

#define FLASH_WRITE_START_ADDR ((uint32_t)0x08010000) // 

#define FLASH_WRITE_END_ADDR   ((uint32_t)0x08018000)

#define FLASH_PROGRAM_TIMEOUT ((uint32_t)0x00002000)

#define BUFFER_SIZE 		(uint32_t)32

extern uint32_t SRAM_Data_Buffer[BUFFER_SIZE] ;

extern uint32_t Flash_Data_Buffer[BUFFER_SIZE] __attribute__((at(FLASH_WRITE_START_ADDR)));

void STMFLASH_Read(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t NumToRead)  ; 


typedef struct _FLASH{

         uint8_t flashSave_falg;

		 uint8_t flashRead_flag;
		 uint8_t array_8bit_1;
		 uint8_t array_8bit_2;
		 uint8_t array_8bit_3;

		 uint32_t flashData[BUFFER_SIZE];


		 uint32_t *pointerflash;

		 
		



}flash;


extern flash flash_t;

extern uint32_t *pfdata;


//void DMA_Flash_SRAM_Config(void);



void Flash_Read(void);




#endif 

