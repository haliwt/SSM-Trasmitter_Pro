#ifndef __F8MENU_H__
#define __F8MENU_H__
#include "main.h"

typedef struct _F8menu{

   uint8_t F8SubMenu_Id;
   uint8_t F8_03_subMenuTop;
	
	uint8_t F8_02_Id;
   uint8_t F8_03_Id;
   uint8_t F8_03_01_Id;
   uint8_t F8_03_02_Id;
   uint8_t F8_03_03_Id;
   uint8_t F8_03_04_Id;
	uint8_t F8_03_05_Id;
   uint8_t F8_03_06_Id;
   uint8_t F8_03_07_Id;
   uint8_t F8_03_08_Id;
	uint8_t F8_03_subMenuTop_Id;
	
   uint8_t unit;
    uint8_t decade;
     uint8_t hundred;
   uint8_t onethousand;
   uint8_t tenthousand;

    uint8_t F8_SubMenuTop;
	uint8_t menuF8Sub_first;
	


}F8menu;
extern F8menu f8menu_t;

void F8_MasterFunction_EnterKey(void);

void F8SubMenu_03_02_DIS(uint8_t mu);


void F8SubMenu_03_DIS(uint8_t mu);

void F8_Add_TheThirdMenu_KeyFunction(uint8_t f8mu);
void F8_Dec_TheThirdMenu_KeyFunction(uint8_t f8mu3);




#endif 

