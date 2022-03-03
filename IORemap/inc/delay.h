#ifndef __DELAY_H_
#define __DELAY_H_

#include "n32l40x_rcc.h"
#include "n32l40x_pwr.h"
#include "n32l40x_flash.h"

enum
{
    SYSCLK_PLLSRC_HSI,             			//0
    SYSCLK_PLLSRC_HSIDIV2,         			//1
    SYSCLK_PLLSRC_HSI_PLLDIV2,     			//2
    SYSCLK_PLLSRC_HSIDIV2_PLLDIV2,  		//3
    SYSCLK_PLLSRC_HSE,              		//4
    SYSCLK_PLLSRC_HSEDIV2,
    SYSCLK_PLLSRC_HSE_PLLDIV2,
    SYSCLK_PLLSRC_HSEDIV2_PLLDIV2,
};


void SysTick_Delay_Ms(__IO uint32_t ms);

void SysTick_Delay_us(__IO uint32_t ms);

void SetSysClockToHSI(void);
void SetSysClockToPLL(uint32_t freq, uint8_t src);

#endif

