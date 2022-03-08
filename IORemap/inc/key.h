#ifndef __KEY_H_
#define __KEY_H_
#include  "main.h"

typedef struct _KEY_{
	     
	   uint8_t keyTimes;
	   uint8_t keyTimes_ms;
	   uint8_t keyTimes_1s;
	   uint8_t keyTimes_2s;
	   uint8_t GetKey;
	   uint8_t PrevKey;
	   uint8_t keypress;
	   uint8_t keydown;
	   uint8_t currkeyset;
	   uint8_t keyset;
	   uint8_t currkeytrae;
	   uint8_t keytrae;
	   uint8_t currkeyswitch;
	   uint8_t keyswitch;
	   uint8_t currkeyzero;
	   uint8_t keyzero;
	   uint8_t keyReturn_flag;
	  
}KEY;

extern int8_t AF104[4];

extern int8_t AF105[2]; //2bit 1~5.0 
extern int8_t AF106[5];
extern int8_t AF107[5];
extern int8_t AF108[2];
extern int8_t AF109[5];
extern int8_t AF110[4];
extern int8_t AF111[1];
extern int8_t AF112[2];
extern int8_t AF113[2];

extern KEY key_t;

void KEY_Function(uint8_t keyvalue);


void GetKeyValua_Init(void);


extern void (*DispDigital_3BitSmg)(void);
void RunDispDigital_Fun(void(*DisSmg)(void));
#endif 

