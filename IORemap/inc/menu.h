#ifndef __MENU_H_
#define __MENU_H_
#include "main.h"

#define MAX_SIZE_MAINMENU 			6
#define MAX_SIZE_F1SUBMENU       	13

//#define F1Mnumbers         13  //has 13 itme sub menues
//#define F2Mnumbers      6
//#define F3Mnumbers    2
#define F7Mnumbers       7
//#define F8Mnumbers       8
//#define F9Mnumbers      7
//uint8_t unit,decade,hundred;
typedef struct _MENU{

	   uint8_t mainTop;
	   uint8_t menuMain;
	   uint8_t menuList;
	   uint8_t menuFirst;
	   uint8_t menuTitle;

	   uint8_t DisplaySmgBit_Select_Numbers;
	   
	   
	   
	   uint8_t menuId;
	   uint8_t active_Submenu;
       uint8_t menuSubId;
	   
	   uint8_t F1_SubMenuTop;
	   uint8_t menuF1Sub_first;
	   uint8_t F1SubMenu_Id;
	   uint8_t F1SubMenu_Sub_02_Id;
	   uint8_t F1SubMenu_Sub_01_first;
	   uint8_t F1SubMenu_Sub_02_first;
	   uint8_t F1SubMenu_Sub_03_first;
	   uint8_t F1SubMenu_Sub_04_first;
	   uint8_t F1SubMenu_Sub_05_first;
	   uint8_t F1SubMenu_Sub_06_first;
	   uint8_t F1SubMenu_Sub_07_first;
	   uint8_t F1SubMenu_Sub_08_first;
	   uint8_t F1SubMenu_Sub_09_first;
	   uint8_t F1SubMenu_Sub_10_first;
	   uint8_t F1SubMenu_Sub_11_first;
	   uint8_t F1SubMenu_Sub_12_first;
	   uint8_t F1SubMenu_Sub_13_first;
	   
	    uint8_t F1SubMenu_Sub_03_Id;
		uint8_t F101_03_SubMeng_flag;
	
	   
	   uint8_t F1_Sub01_Top;
	   uint8_t F1_Sub02_Top;
	    uint8_t F1_Sub03_Top;
		uint8_t F1_Sub04_Top;
	    uint8_t F1_Sub05_Top;
	    uint8_t F1_Sub06_Top;
       uint8_t F1_Sub07_Top;
	   uint8_t F1_Sub08_Top;
	    uint8_t F1_Sub09_Top;
		uint8_t F1_Sub10_Top;
	   uint8_t F1_Sub11_Top;
	    uint8_t F1_Sub12_Top;
		uint8_t F1_Sub13_Top;



	   int8_t F1_Sub02_unit;
	   int8_t F1_Sub02_decade;
	   int8_t F1_Sub02_hundred;
	   
	   int8_t F1_Sub03_unit;
	   int8_t F1_Sub03_decade;
	   int8_t F1_Sub03_hundred;

	   uint8_t F1_Submenu_Check_flag;
	   uint8_t inputNumber_Select;
	   
	
       uint8_t F2_Sub01_Top;
	   uint8_t F2_Sub02_Top;
	   uint8_t F2_SubMenuTop;
	   uint8_t menuF2Sub_first;


	   uint8_t F2SubMenu_Id;
	   
	 
	   uint8_t F3_SubMenuTop;
	   uint8_t F3_SubMenuTop_02;
	   uint8_t F3_SubMenuTop_03;
	   uint8_t F3_04_ID ;
	   
	   uint8_t menuF3Sub_first;
	   uint8_t F3SubMenu_Id;
	   uint8_t F3SubMenu_04_Id;
	   uint8_t F34_KEY_VALUE;
	   
	
	   
	   uint8_t F8_SubMenuTop;
	   uint8_t menuF8Sub_first;
	   uint8_t F8SubMenu_Id;
	   
	   uint8_t F9_SubMenuTop;
	   uint8_t menuF9Sub_first;
	 


	  uint8_t menuTitle_02;
	  uint8_t  menuTitle_03;
	  uint8_t  menuTitle_04;
	  uint8_t  FxMainMenu_key;
	  uint8_t  menu_F1Sub_03_xx_key;

	int8_t unit;
	int8_t decade;
	int8_t hundred;
	int8_t thousand;
	  uint16_t FxSub_02_key;
      uint16_t FxSub_03_key;
	
	   
}MENU;


typedef  struct _F1_MENU{
	 uint8_t F1_03_item_flag;
	
}F1_FUN;

extern F1_FUN F1_menu;

extern MENU menu_t;

typedef enum{
	F1,
	F2,
	F3,
	F7,
	F8,
	F9,

}menuList;


typedef enum{
   
    
	 submenu_F1=0X01,
	 submenu_F2,
	 submenu_F3,
	 submenu_F7,
	 submenu_F8,
	 submenu_F9,

}submenuList;

//The second menu F1
typedef enum{
     F101,
	 F102,
	 F103,
	 F104,
	 F105,
	 F106,
	 F107,
	 F108,
	 F109,
	 F110,
	 F111,
	 F112,
	 F113
}F1submenuList;


 
typedef enum{
     F101_01,
	 F101_02,
	 F101_03,
	 F101_04,
	 F101_05,
	 F101_06,
	 F101_07,
	 F101_08,
	 F101_09,
	 F101_10,
	 F101_11,
	 F101_12,
	 F101_13
}F1submenuList_03;

//How many sub menu include of manin menu?
typedef enum {
	
	F1Mnumbers = 13 , //has 13 itme sub menues
	F2Mnumbers = 6,
	F3Mnumbers = 2,
//	F7Mnumbers = 7,
	F8Mnumbers = 8,
	F9Mnumbers = 7
	
}submenuNumbers;

typedef enum {
	
	F101_01_01 = 5 , //has 13 itme sub menues
	F101_01_02 = 1,
	F101_01_03 = 1,
    F101_01_04 = 1,
	F101_01_05= 1,
	F101_01_06 = 1,
	F101_01_07 = 1,
	F101_01_08 = 1,
    F101_01_09 = 1,
	F101_01_10= 1,
	F101_01_11 = 4,
	F101_01_12= 11,
	F101_01_13 = 1
	
	
}submenuNumber_02;


typedef struct _submenulist{
	
   submenuNumbers subNumbers;
	
}subNumbers_TypedDef;

extern subNumbers_TypedDef submenStruct;
extern int8_t menuTop;
extern int8_t menuFxSubTop;
extern int8_t menuFxSub_03_Top;
extern  int8_t F1_03_item_Top;
extern int8_t F3_04_item_Top ;
extern int8_t F3_05_item_Top ;
//Main menu
void Menu_Init(void);
uint8_t PushMainMenu(void);
uint8_t PopMainMenu(void);
void MainMenu(int8_t mtop);
int8_t PopMainMenu_Return(void);
uint8_t MainMenu_Top(void);

//F1 ,F2,F3,F6,F7,F8,F9 ->the second menu F1 -01 ,F2-01
void F1SubMenu(int8_t fsub);
extern uint8_t PushSub_Menu(int8_t size);
extern uint8_t PopSub_Menu(int8_t sizem);
int8_t SubMenu_02_Top(void);
//F1,F2,F3,F7,F8,F9 ->the third menu >F1 -01 -> g,H9,t,n,nonE
extern uint8_t PushSub_03_Menu(int8_t msize);
extern uint8_t PopSub_03_Menu(int8_t msize);
int8_t submenu_03_Top(void);

uint8_t F3_04_PushSub_Item(int8_t nsize);
uint8_t F3_04_PopSub_Item(int8_t nsize);
uint8_t F3_04_Item_Top(void);

uint8_t F3_05_PushSub_Item(int8_t nsize);
uint8_t F3_05_PophSub_Item(int8_t nsize);
uint8_t F3_05_Item_Top(void);
//F1 MENU the third menu 
void F1SubMenu_F101_01_Select_DIS(uint8_t subm3);

void F1SubMenu_F1_03_DIS(int8_t unit,int8_t decade,int8_t hundred);

uint8_t F1_PushSub_03_Item(int8_t nsize);

uint8_t F1_PopSub_03_Item_Top(void);

uint8_t F1_PopSub_03_Item(int8_t nsize);


void F1SubMenu_F101_02_Select_DIS(uint8_t subm3);

/******************F2-01***************************/
void F2SubMenu_02(uint8_t mn);

/******************F3-01*****************************/
void F3SubMenu_02_DispSelect(uint8_t mn);

#endif 
