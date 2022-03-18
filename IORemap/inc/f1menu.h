#ifndef __F1MENU_H_
#define __F1MENU_H_

#include "main.h"



typedef struct F1MENUNEW{
  
   
   uint8_t f1r01;
   uint8_t f1r02;
   uint8_t f1r03;

   uint8_t f1r04;
   uint8_t f1r05;
   uint8_t f1r06;

    uint8_t f1r07;
   uint8_t f1r08;
   uint8_t f1r09;

   uint8_t f1r10;
   uint8_t f1r11;
   uint8_t f1r12;

   uint8_t f1r13;
 
 

   uint32_t f2r06_reg;
   uint32_t f2r03_reg;
   uint32_t f2r04_reg;
   uint32_t f2r01_reg;
   uint32_t f2r02_reg;
   uint32_t f2r05_reg;

   uint32_t f1r01_reg;
   uint32_t f1r02_reg;
   uint32_t f1r12_reg ;

  uint32_t f2r05_reg_next;

}f1menunew;

extern f1menunew f1menu_t;

void F1_MasterFunction_EnterKey(void);
void F1_Add_TheThirdMenu_KeyFunction(uint8_t f1mu);
void F1_Dec_TheThirdMenu_KeyFunction(uint8_t f1mu3);

#endif 