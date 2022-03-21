#ifndef __DIS_H_
#define __DIS_H_
#include "main.h"

void Number_Digital_1bit_AddSelect(int8_t *ap);
void Number_Digital_1bit_DecSelect(int8_t *ap);

void Number_Digital_5bit_DecSelect(int8_t *ap);
void Number_Digital_5bit_AddSelect(int8_t *ap);

void Number_Digital_3bit_NoRefDecSelect(void);
void Number_Digital_3bit_NoRefAddSelect(void);

void Number_Digital_Set5bit_RefAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_RefDecSelect(int8_t *ap ,uint8_t n);

void Number_Digital_5bitPoint_AddSelect(int8_t *ap);
void Number_Digital_5bitPoint_DecSelect(int8_t *ap);

void Number_Digital_3bit_AddSelect(int8_t *ap);
void Number_Digital_3bit_DecSelect(int8_t *ap);

void Number_Digital_5bit_SymAddSelect(int8_t *ap);
void Number_Digital_5bit_SymDecSelect(int8_t *ap);

void SmgDisplay_ALLBitsOff(void);




#endif 

