#ifndef __DIS_H_
#define __DIS_H_
#include "main.h"


void Number_Digital_5bit_DecSelect(int8_t *ap);
void Number_Digital_5bit_AddSelect(int8_t *ap);

void Number_Digital_3bit_DecSelect(void);

void Number_Digital_3bit_AddSelect(void);
void Number_Digital_Set5bit_RefAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_RefDecSelect(int8_t *ap ,uint8_t n);

void Number_Digital_5bitPoint_AddSelect(int8_t *ap);
void Number_Digital_5bitPoint_DecSelect(int8_t *ap);

#endif 