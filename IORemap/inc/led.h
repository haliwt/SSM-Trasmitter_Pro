#ifndef __LED_H_
#define __LED_H_
#include "main.h"


/*Led1-PB0,Led2-PB1,Led3-PE0,Led4-PE1,Led5-PE5*/
#define PORT_GROUP2      	GPIOB
#define LED1_PORT   		PORT_GROUP2
#define LED2_PORT   		PORT_GROUP2
#define LED3_PORT   		PORT_GROUP2
//#define LED4_PORT   		PORT_GROUP2


#define LED1_PIN    		GPIO_PIN_6
#define LED2_PIN    		GPIO_PIN_7
#define LED3_PIN    		GPIO_PIN_8
//#define LED4_PIN    		GPIO_PIN_9



void LED_Init(void);
void LED_Fun(void);










#endif 
