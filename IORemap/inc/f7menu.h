#ifndef __F7MENU_H__
#define __F7MENU_H__
#include "main.h"

typedef struct _F7menu{

   uint8_t F7SubMenu_Id;
   uint8_t F7_03_subMenuTop;
	
	uint8_t F7_02_Id;
   uint8_t F7_03_Id;
   uint8_t F7_03_01_Id;
   uint8_t F7_03_02_Id;
   uint8_t F7_03_03_Id;
   uint8_t F7_03_04_Id;
	uint8_t F7_03_05_Id;
   uint8_t F7_03_06_Id;
   uint8_t F7_03_07_Id;
	uint8_t unit;
	uint8_t decade;
	uint8_t hundred;

   uint8_t F7_SubMenuTop;
	uint8_t menuF7Sub_first;
	uint8_t F7_Sub01_Top;



}F7menu;
extern F7menu f7menu_t;

void F7SubMenu_02_DIS(uint8_t mu);

void F7SubMenu_03_DIS(void);




#endif 


