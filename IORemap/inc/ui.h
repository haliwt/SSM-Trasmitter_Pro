#ifndef __UI_H_
#define __UI_H_
#include "main.h"


void Symbol_HrL(void);
void Symbol_ECH(void);
void Symbol_Por(void);
void Symbol_EEr(void);
void Symbol_PRS(void);
void Symbol_CnoSS(void);
void Symbol_nEt(void);
void Symbol_PERH(void);
void Symbol_uRLEy(void);
void Symbol_p_u(void);
void Symbol_uRLLE(void);
 void Symbol_ERS(void);
void Symbol_nonE(void);


void DisplayMode_Normal(void);

void Menu_F1(void);

void Menu_F2(void);

void Menu_F3(void);
void Menu_F6(void);
void Menu_F7(void);
void Menu_F8(void);
void Menu_F9(void);
//F1 SubMenu list
void F1_DIS(void);

/***********************F1********************************/
void F1SubMenu_01(void);
void F1SubMenu_02(void);
void F1SubMenu_03(void);
void F1SubMenu_04(void);
void F1SubMenu_05(void);
void F1SubMenu_06(void);
void F1SubMenu_07(void);
void F1SubMenu_08(void);
void F1SubMenu_09(void);
void F1SubMenu_10(void);
void F1SubMenu_11(void);
void F1SubMenu_12(void);
void F1SubMenu_13(void);

//F1 the third menu 01 list 
void F1SubMenu_Sub_01_01(void);
void F1SubMenu_Sub_01_02(void);
void F1SubMenu_Sub_01_03(void);
void F1SubMenu_Sub_01_04(void);
void F1SubMenu_Sub_01_05(void);
//F1 the third menu 02 list
void F1SubMenu_F1_02_01(int8_t unit,int8_t decade,int8_t hundred);

void F1SubMenu_F104_01_Select_DIS(int8_t *p);
void F1SubMenu_F105_01_Select_DIS(int8_t *pA);
void F1SubMenu_F106_01_Select_DIS(int8_t *pA);
void F1SubMenu_F109_01_Select_DIS(int8_t *pA);
void F1SubMenu_F110_01_Select_DIS(int8_t *pA);
void F1SubMenu_F111_01_Select_DIS(int8_t *pA);
void F1SubMenu_F112_01_Select_DIS(int8_t *pA);

//F2 the third menu 03 list
//F2 SubMenu list
void F2SubMenu_Master_01(void);
void F2SubMenu_F201_01_Select_DIS(int8_t *pA);
void F2SubMenu_F202_01_Select_DIS(int8_t *pA);
void F2SubMenu_F203_01_Select_DIS(int8_t *pA);
void F2SubMenu_F204_01_Select_DIS(int8_t *pA);
void F2SubMenu_F205_01_Select_DIS(int8_t *pA);
void F2SubMenu_F206_01_Select_DIS(int8_t *pA);



void F3SubMenu_F301_01_Select_DIS(int8_t *pA,uint8_t n);
void F3SubMenu_F301_02_Select_DIS(int8_t *pA,uint8_t n);


void F3SubMenu_04_Item(int8_t *pA,int8_t *pt);

//F7 SubMenu List 
void F7SubMenu_Master_01(void);

//F8 SubMenu List 
void F8SubMenu_Master_01(void);
void F8SubMenu_03_02_StandDis(uint8_t mu);

//F9 SubMenu List 
void F9SubMenu_Master_01(void);

void Number_5bit_Char_DIS(int8_t *pA);

void Number_5bit_DIS(int8_t *pA);

#endif 


