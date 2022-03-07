#ifndef __HX720_H_
#define __HX720_H_
#include "main.h"

#define CLK_GPIO   			GPIOB 
#define DATA_GPIO     		GPIOB

#define DATA      GPIO_PIN_9  //input Port
#define CLK       GPIO_PIN_0 //Output  Port

extern int8_t  No_Load_Flag;
extern uint32_t  Weight_No_Lode;
extern uint32_t  Weight_Lode ;
extern float Weight_Real;
extern uint8_t HX720_ReadDataFlag;
extern uint32_t  HX720_Buffer;


void Sensor_Init(void);

uint32_t Sensor_Read(void);

void Get_No_Lode(void);
float Get_Weight(void);


void Weigt_DisSmg(float weightValue) ;
void SmgDis_TurnOff_ALl(void);
float Get_Maopi(void);
float Get_Weight_2(void);
unsigned long HX711_Read(void)	;
uint32_t GetHX720Data(void);
void RunHX720Cmd(vodi);

#endif 
