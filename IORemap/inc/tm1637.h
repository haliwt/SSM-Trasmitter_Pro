#ifndef __TM1637_H_
#define __TM1637_H_

#include "n32l40x_gpio.h"

#define I2C_SDA_PORT      					GPIOB
#define I2C_SCL_PORT      					GPIOB
#define I2C_SDA_PIN       					GPIO_PIN_14
#define I2C_SCL_PIN       					GPIO_PIN_13




//extern volatile uint8_t DispData[3];//??LED??
#define		BitSET(x,y)		x|=(1<<y)				//?1
#define		BitCLR(x,y)		x&=~(1<<y)				//?0

/**************************************************
	    //                a
        //            ---------
        //           |         |
        //         f |         | b
        //           |    g    |
        //            ---------
        //           |         |
        //         e |         | c
        //           |    d    |
        //            ---------   O <- h
**************************************************/
//????,SEG1~SEG8
#define   seg_a  0x01       //seg_a   //seg_e = 0x10  
#define   seg_b  0x02      //seg_b , //seg_f = 0x20
#define   seg_c  0x04      //seg_c , //seg_g = 0x40
#define   seg_d  0x08      //seg_d , //seg_d = 0x08
#define   seg_e  0x10      //seg_e , //seg_c = 0x04
#define   seg_f  0x20      //seg_f   //seg_a = 0x01
#define   seg_g  0x40      //seg_g   //seg_b = 0x02 
#define   seg_h  0x80      //Dot 

/*************High byte*******************/


#define char_F()     (seg_a+seg_f+seg_e+seg_e)      //char "F"


typedef enum{
    digital_1= 0xc0,
    digital_2 = 0xc1,
    digital_3 = 0xc2,
    digital_4 = 0xc3,
    digital_5 = 0xc4,
    digital_6 = 0xc5

}disreg;

void GPIO_OutputInit(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_InputInit(GPIO_Module* GPIOx, uint16_t Pin);

void GPIO_SetHigh(GPIO_Module* GPIOx, uint16_t Pin);
void GPIO_SetLow(GPIO_Module* GPIOx, uint16_t Pin);

void SmgDisplay(disreg dg,uint8_t dat);
void SmgDisplay_All(void);

void SmgDisplay_Character(disreg dg,uint8_t chdat);

uint8_t ScanKey(void);

void Net_KeyLed(void);
void CH1_KeyLed(void);

void Peak_KeyLed(void);
void CH2_KeyLed(void);

void Valley_KeyLed(void);
void CH3_KeyLed(void);

void Mot_KeyLed(void);
void CH4_KeyLed(void);



#endif 

