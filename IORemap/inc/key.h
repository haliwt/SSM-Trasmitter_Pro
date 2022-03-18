#ifndef __KEY_H_
#define __KEY_H_
#include  "main.h"






typedef struct _KEY_{
	     
	   uint8_t keyTimes;
	   uint8_t keyTimes_ms;
	   uint8_t keyTimes_1s;
	   uint8_t keyPressedTimes;
	   uint8_t keyRunTimes;
	   
	   uint8_t keyGetLong_Numbers;
	   uint8_t RunCmd_flag; 
	   uint8_t F1_0102FlashSave_flag ;
	   uint8_t F2_0102FlashSave_flag;

	   uint8_t keyadjust_flag ;
	
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
	   uint8_t keyReturn_F2_flag;
	   uint8_t keyReturn_F3_flag;
	   uint8_t  f7keyReturn_flag;
	   uint8_t	f8keyReturn_flag;
	   uint8_t	f9keyReturn_flag;
	   uint32_t keyPressedLongTimes;
	  
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

extern int8_t AF201[1];
extern int8_t AF202[5];
extern int8_t AF203[5];
extern int8_t AF204[1];
extern int8_t AF205[5];
extern int8_t AF206[5];

extern int8_t AF3401[1];
extern int8_t AF3402[1];
extern int8_t AF301[3];
extern int8_t AF302[1];
extern int8_t AF303[6];
extern int8_t AF304[3];
extern int8_t AF305[5];
extern int8_t AF306[5];
extern int8_t AF307[5];

extern int8_t AF803[5];
extern int8_t AF804[5];
extern int8_t AF805[5];
extern int8_t AF806[5];


extern KEY key_t;

void KEY_Function(uint8_t keyvalue);
void	KEY4_SET_ENTER_Fun(void);

void KeyValua_Init(void);



extern void (*DispDigital_3BitSmg)(void);
void RunDispDigital_Fun(void(*DisSmg)(void));


void Number_Digital_2bit_DecSelect(int8_t *ap);
void Number_Digital_2bit_AddSelect(int8_t *ap);

void Number_Digital_3bit_PointerDecSelect(int8_t *ap);
void Number_Digital_3bit_PointerAddSelect(int8_t *ap);

 void Number_Digital_4bit_DecSelect(int8_t *ap);
void Number_Digital_4bit_AddSelect(int8_t *ap);

void Number_Digital_5bitPoint_AddSelect(int8_t *ap);
void Number_Digital_5bitPoint_DecSelect(int8_t *ap);
uint8_t Scan_EnterKey(uint8_t keyvalue);
#endif 

