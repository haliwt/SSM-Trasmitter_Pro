#ifndef __CALMENU_H_
#define __CALMENU_H_
#include "main.h"


typedef struct _CALI{
   
    uint8_t CaliControl_key;
    uint8_t CaliMenu_Item;
    uint8_t CaliMenu_Sub_Item;
    uint8_t CaliSub_Menu_02_Title;
    uint8_t CaliSub_Menu_03_Title;


    uint8_t CaliMenu_01_Id;
    uint8_t CaliMenu_02_Id;
    uint8_t keyEnter_flag;

    uint8_t CaliSub_02_01_Itme;
    uint8_t CaliSub_02_02_Item;
    uint8_t CaliSub_02_03_Item;

           

     uint8_t CaliSub_03_01_Itme;
    uint8_t CaliSub_03_02_Item;
    uint8_t CaliSub_03_03_Item;
  

    int8_t stackCali_02_01_Tp;
    int8_t stackCali_02_02_Tp;
    int8_t stackCali_02_03_Tp;



    int8_t stackCali_03_01_Tp;
    int8_t stackCali_03_02_Tp;
    int8_t stackCali_03_03_Tp;
}cali;
extern cali cali_t;
enum calimenu{

    caliTheFirst_Menu,
    caliTheSecond_Menu,
    caliTheThird_Menu
};

enum cali{
   
   CAL1 ,
   CAL2 ,
   CAL3 ,
   CAL5

};



extern int8_t caliMainTop  ;

extern int8_t caliSun_02_Top  ;


uint8_t Push_stackCaliMain(int8_t maxize);
uint8_t Pop_stackCaliMain(int8_t maxize);
uint8_t CaliMain_stackTop(void);

int8_t Push_stackCaliMain_02(int8_t maxize,int8_t ntop);
int8_t Pop_stackCaliMain_02(int8_t maxize,int8_t ntop);
int8_t CaliSub_02_stackTop(int8_t ntop);

void KEY4_InputCalibration_Mode(void);
 void CALI_KEY3_SWITCH_Fun(void );
 void  CALI_KEY1_UP_Fun(void);
void CALI_KEY2_DOWN_Fun(void );
void CAL_KEY4_ENTER_Fun(void);

void CALI_MENU_01_DIS(uint8_t mu);
void CALI_MENU_SUB_02_DIS(uint8_t mu,uint8_t su);
 void CALI_MENU_SUB_03_DIS(uint8_t mu,uint8_t su); //speical numbers "0000 000 1000"
 

#endif 
