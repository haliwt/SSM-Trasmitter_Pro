#ifndef __F3MENU_H__
#define __F3MENU_H__
#include "main.h"

typedef struct _f3class_3_{
    
    uint8_t threeClass_menu_Id;
    uint8_t F3_theFourth_Id;
    
}f3classmenu;


extern int8_t AF3404[3];
extern int8_t AF3405[5];
extern int8_t AF3406[5];
extern int8_t AF3407[5];

extern f3classmenu f3menu_t;


void F3_Add_TheThirdMenu_KeyFunction(uint8_t f3mu);


uint8_t F3_04_PushSub_Item(int8_t nsize);
uint8_t F3_04_PopSub_Item(int8_t nsize);
uint8_t F3_04_Item_Top(void);

uint8_t F3_05_PushSub_Item(int8_t nsize);
uint8_t F3_05_PophSub_Item(int8_t nsize);
uint8_t F3_05_Item_Top(void);

//F3 SubMenu List
void F3SubMenu_01(void);
void F3SubMenu_02(void);

void F3SubMenu_F302_02_Select_DIS(int8_t *pA,uint8_t n);

//key function 
void F3SubMenu_Master_01(void);

void F3_MasterFunction_EnterKey(void);
void F3SubMenu_02_DispSelect(uint8_t mn);
void F3SubMenu_03_Item(uint8_t mf301);


void F3_Add_TheFourthMenu_KeyFunction(uint8_t f3mu4);
void F3_Dec_TheThirdMenu_KeyFunction(uint8_t f3mu3);

void F3_SubMenu_TheFourth_RunCmdDis(uint8_t f3mu);


#endif 




