#ifndef __F9MENU_H__
#define __F9MENU_H__
#include "main.h"

typedef struct _F9menu{

   uint8_t F9SubMenu_Id;
   uint8_t F9_03_subMenuTop;
   uint8_t F9_SubMenuTop;
	
	uint8_t F9_02_Id;
   uint8_t F9_03_Id;
   uint8_t F9_03_01_Id;
   uint8_t F9_03_02_Id;
   uint8_t F9_03_03_Id;
   uint8_t F9_03_04_Id;
	uint8_t F9_03_05_Id;
   uint8_t F9_03_06_Id;
   uint8_t F9_03_07_Id;
   uint8_t menuF9Sub_first;


}F9menu;
extern F9menu f9menu_t;

void F9SubMenu_02_DIS(uint8_t mu);

void F9SubMenu_03_DIS(uint8_t mu);






#endif


