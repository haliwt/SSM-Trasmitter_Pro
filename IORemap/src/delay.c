#include "delay.h"

ErrorStatus HSEStartUpStatus;
ErrorStatus HSIStartUpStatus;
GPIO_InitType GPIO_InitStructure;
RCC_ClocksType RCC_ClockFreq;





void SetSysClockToMSI(void);
void SetSysClockToHSI(void);
void SetSysClockToHSE(void);
void SetSysClockToPLL(uint32_t freq, uint8_t src);

void DumpClock(const char* msg)
{
    //log_init(); // should reinit after sysclk changed
    //log_info("--------------------------------\n");
   // log_info("%s:\n", msg);
   // RCC_GetClocksFreqValue(&RCC_ClockFreq);
   // log_info("SYSCLK: %d\n", RCC_ClockFreq.SysclkFreq);
   // log_info("HCLK: %d\n", RCC_ClockFreq.HclkFreq);
   // log_info("PCLK1: %d\n", RCC_ClockFreq.Pclk1Freq);
   // log_info("PCLK2: %d\n", RCC_ClockFreq.Pclk2Freq);
}


/**
 * @brief  Configure the system tick clock.
 */
uint32_t DBG_SysTick_Config(uint32_t ticks)
{
    if (ticks > SysTick_LOAD_RELOAD_Msk)
        return (1); /* Reload value impossible */

    SysTick->LOAD = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;       /* set reload register */
    NVIC_SetPriority(SysTick_IRQn, (1 << __NVIC_PRIO_BITS) - 1); /* set Priority for Cortex-M0 System Interrupts */
    SysTick->VAL  = 0;                                           /* Load the SysTick Counter Value */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; /* Enable SysTick IRQ and SysTick Timer */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
    return (0); /* Function successful */
}
/**
 * @brief  Use the system tick clock to delay.
 */
void SysTick_Delay_Ms(__IO uint32_t ms)
{
    uint32_t i;
    RCC_ClocksType RCC_Clocks;

    RCC_GetClocksFreqValue(&RCC_Clocks);
    DBG_SysTick_Config(RCC_Clocks.SysclkFreq / 1000);

    for (i = 0; i < ms; i++)
    {
        /* When the value of the counter is reduced to 0, the bit 16 of the CRTL register is set to 1.
           When set to 1, the bit  will cleared to 0 with read
        */
        while (!((SysTick->CTRL) & (1 << 16)))
            ;
    }
    // Disable SysTick timer
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Delay_us(__IO uint32_t us)
{
		uint32_t i;
    RCC_ClocksType RCC_Clocks;

    RCC_GetClocksFreqValue(&RCC_Clocks);
    DBG_SysTick_Config(RCC_Clocks.SysclkFreq / 1000000);
     
    for (i = 0; i < us; i++)
    {
        /* When the value of the counter is reduced to 0, the bit 16 of the CRTL register is set to 1.
           When set to 1, the bit  will cleared to 0 with read
        */
        while (!((SysTick->CTRL) & (1 << 16)))
            ;
    }
    // Disable SysTick timer
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

}


//    SetSysClockToPLL(8000000, SYSCLK_PLLSRC_HSIDIV2_PLLDIV2);
//    DumpClock("HSI/2->PLL/2, 8M");


/**
 * @brief  Selects PLL clock as System clock source and configure HCLK, PCLK2
 *         and PCLK1 prescalers.
 */
void SetSysClockToPLL(uint32_t freq, uint8_t src)
{
    uint32_t pllsrcclk;
    uint32_t pllsrc;
    uint32_t pllmul;
    uint32_t plldiv = RCC_PLLDIVCLK_DISABLE;
    uint32_t latency;
    uint32_t pclk1div, pclk2div;
    uint32_t msi_ready_flag = RESET;

    if (HSE_VALUE != 8000000)
    {
        /* HSE_VALUE == 8000000 is needed in this project! */
        while (1);
    }

    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration
     * -----------------------------*/

    if ((src == SYSCLK_PLLSRC_HSI)         || (src == SYSCLK_PLLSRC_HSIDIV2) 
     || (src == SYSCLK_PLLSRC_HSI_PLLDIV2) || (src == SYSCLK_PLLSRC_HSIDIV2_PLLDIV2))
    {
        /* Enable HSI */
        RCC_ConfigHsi(RCC_HSI_ENABLE);

        /* Wait till HSI is ready */
        HSIStartUpStatus = RCC_WaitHsiStable();

        if (HSIStartUpStatus != SUCCESS)
        {
            /* If HSI fails to start-up, the application will have wrong clock
               configuration. User can add here some code to deal with this
               error */

            /* Go to infinite loop */
            while (1);
        }

        if ((src == SYSCLK_PLLSRC_HSIDIV2) || (src == SYSCLK_PLLSRC_HSIDIV2_PLLDIV2))
        {
            pllsrc = RCC_PLL_HSI_PRE_DIV2;
            pllsrcclk = HSI_VALUE/2;

            if(src == SYSCLK_PLLSRC_HSIDIV2_PLLDIV2)
            {
                plldiv = RCC_PLLDIVCLK_ENABLE;
                pllsrcclk = HSI_VALUE/4;
            }
        } 
		else if ((src == SYSCLK_PLLSRC_HSI) || (src == SYSCLK_PLLSRC_HSI_PLLDIV2))
        {
            pllsrc = RCC_PLL_HSI_PRE_DIV1;
            pllsrcclk = HSI_VALUE;

            if(src == SYSCLK_PLLSRC_HSI_PLLDIV2)
            {
                plldiv = RCC_PLLDIVCLK_ENABLE;
                pllsrcclk = HSI_VALUE/2;
            }
        }

    } 
	else if ((src == SYSCLK_PLLSRC_HSE)         || (src == SYSCLK_PLLSRC_HSEDIV2) 
            || (src == SYSCLK_PLLSRC_HSE_PLLDIV2) || (src == SYSCLK_PLLSRC_HSEDIV2_PLLDIV2))
    {
        /* Enable HSE */
        RCC_ConfigHse(RCC_HSE_ENABLE);

        /* Wait till HSE is ready */
        HSEStartUpStatus = RCC_WaitHseStable();

        if (HSEStartUpStatus != SUCCESS)
        {
            /* If HSE fails to start-up, the application will have wrong clock
               configuration. User can add here some code to deal with this
               error */

            /* Go to infinite loop */
            while (1);
        }

        if ((src == SYSCLK_PLLSRC_HSEDIV2) || (src == SYSCLK_PLLSRC_HSEDIV2_PLLDIV2))
        {
            pllsrc = RCC_PLL_SRC_HSE_DIV2;
            pllsrcclk = HSE_VALUE/2;

            if(src == SYSCLK_PLLSRC_HSEDIV2_PLLDIV2)
            {
                plldiv = RCC_PLLDIVCLK_ENABLE;
                pllsrcclk = HSE_VALUE/4;
            }
        } else if ((src == SYSCLK_PLLSRC_HSE) || (src == SYSCLK_PLLSRC_HSE_PLLDIV2))
        {
            pllsrc = RCC_PLL_SRC_HSE_DIV1;
            pllsrcclk = HSE_VALUE;

            if(src == SYSCLK_PLLSRC_HSE_PLLDIV2)
            {
                plldiv = RCC_PLLDIVCLK_ENABLE;
                pllsrcclk = HSE_VALUE/2;
            }
        }
    }

    latency = (freq/32000000);
    
    if(freq > 54000000)
    {
        pclk1div = RCC_HCLK_DIV4;
        pclk2div = RCC_HCLK_DIV2;
    }
    else
    {
        if(freq > 27000000)
        {
            pclk1div = RCC_HCLK_DIV2;
            pclk2div = RCC_HCLK_DIV1;
        }
        else
        {
            pclk1div = RCC_HCLK_DIV1;
            pclk2div = RCC_HCLK_DIV1;
        }
    }
    
    if(((freq % pllsrcclk) == 0) && ((freq / pllsrcclk) >= 2) && ((freq / pllsrcclk) <= 32))
    {
        pllmul = (freq / pllsrcclk);
        if(pllmul <= 16)
        {
            pllmul = ((pllmul - 2) << 18);
        }
        else
        {
            pllmul = (((pllmul - 17) << 18) | (1 << 27));
        }
    }
    else
    {
        /* Cannot make a PLL multiply factor to freq. */
       // log_info("Cannot make a PLL multiply factor to freq..\n");
        while(1);
    }

    /* Cheak if MSI is Ready */
    if(RESET == RCC_GetFlagStatus(RCC_CTRLSTS_FLAG_MSIRD))
    {
        /* Enable MSI and Config Clock */
        RCC_ConfigMsi(RCC_MSI_ENABLE, RCC_MSI_RANGE_4M);
        /* Waits for MSI start-up */
        while(SUCCESS != RCC_WaitMsiStable());

        msi_ready_flag = SET;
    }

    /* Select MSI as system clock source */
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_MSI);

    FLASH_SetLatency(latency);

    /* HCLK = SYSCLK */
    RCC_ConfigHclk(RCC_SYSCLK_DIV1);

    /* PCLK2 = HCLK */
    RCC_ConfigPclk2(pclk2div);

    /* PCLK1 = HCLK */
    RCC_ConfigPclk1(pclk1div);

    /* Disable PLL */
    RCC_EnablePll(DISABLE);

    RCC_ConfigPll(pllsrc, pllmul, plldiv);

    /* Enable PLL */
    RCC_EnablePll(ENABLE);

    /* Wait till PLL is ready */
    while (RCC_GetFlagStatus(RCC_CTRL_FLAG_PLLRDF) == RESET);

    /* Select PLL as system clock source */
    RCC_ConfigSysclk(RCC_SYSCLK_SRC_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while (RCC_GetSysclkSrc() != 0x0C);

    if(msi_ready_flag == SET)
    {
        /* MSI oscillator OFF */
        RCC_ConfigMsi(RCC_MSI_DISABLE, RCC_MSI_RANGE_4M);
    }
}


/**
 * @brief  Selects HSI as System clock source and configure HCLK, PCLK2
 *         and PCLK1 prescalers.
 */
void SetSysClockToHSI(void)
{
    uint32_t msi_ready_flag = RESET;

    RCC_EnableHsi(ENABLE);

    /* Wait till HSI is ready */
    HSIStartUpStatus = RCC_WaitHsiStable();

    if (HSIStartUpStatus == SUCCESS)
    {
        /* Enable Prefetch Buffer */
        FLASH_PrefetchBufSet(FLASH_PrefetchBuf_EN);

        if(((*(__IO uint8_t*)((UCID_BASE + 0x2))) == 0x01)
        || ((*(__IO uint8_t*)((UCID_BASE + 0x2))) == 0x11)
        || ((*(__IO uint8_t*)((UCID_BASE + 0x2))) == 0xFF))
        {
            /* Cheak if MSI is Ready */
            if(RESET == RCC_GetFlagStatus(RCC_CTRLSTS_FLAG_MSIRD))
            {
                /* Enable MSI and Config Clock */
                RCC_ConfigMsi(RCC_MSI_ENABLE, RCC_MSI_RANGE_4M);
                /* Waits for MSI start-up */
                while(SUCCESS != RCC_WaitMsiStable());

                msi_ready_flag = SET;
            }

            /* Select MSI as system clock source */
            RCC_ConfigSysclk(RCC_SYSCLK_SRC_MSI);

            /* Disable PLL */
            RCC_EnablePll(DISABLE);

            RCC_ConfigPll(RCC_PLL_HSI_PRE_DIV2, RCC_PLL_MUL_2, RCC_PLLDIVCLK_DISABLE);

            /* Enable PLL */
            RCC_EnablePll(ENABLE);

            /* Wait till PLL is ready */
            while (RCC_GetFlagStatus(RCC_CTRL_FLAG_PLLRDF) == RESET);

            /* Select PLL as system clock source */
            RCC_ConfigSysclk(RCC_SYSCLK_SRC_PLLCLK);

            /* Wait till PLL is used as system clock source */
            while (RCC_GetSysclkSrc() != 0x0C);

            if(msi_ready_flag == SET)
            {
                /* MSI oscillator OFF */
                RCC_ConfigMsi(RCC_MSI_DISABLE, RCC_MSI_RANGE_4M);
            }
        }
        else
        {
            /* Select HSI as system clock source */
            RCC_ConfigSysclk(RCC_SYSCLK_SRC_HSI);

            /* Wait till HSI is used as system clock source */
            while (RCC_GetSysclkSrc() != 0x04)
            {
            }
        }

        /* Flash 0 wait state */
        FLASH_SetLatency(FLASH_LATENCY_0);

        /* HCLK = SYSCLK */
        RCC_ConfigHclk(RCC_SYSCLK_DIV1);

        /* PCLK2 = HCLK */
        RCC_ConfigPclk2(RCC_HCLK_DIV1);

        /* PCLK1 = HCLK */
        RCC_ConfigPclk1(RCC_HCLK_DIV1);
    }
    else
    {
        /* If HSI fails to start-up, the application will have wrong clock
           configuration. User can add here some code to deal with this error */

        /* Go to infinite loop */
        while (1)
        {
        }
    }
}
