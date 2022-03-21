#ifndef __CALMENU_H_
#define __CALMENU_H_
#include "main.h"


typedef struct _CALI{
   
   
    uint8_t Thefirst_InputKeyValue;
    uint8_t CaliControl_key;
    uint8_t CaliMenu_Item;
    uint8_t CaliMenu_Sub_Item;
    uint8_t CaliSub_Menu_02_Title;
    uint8_t CaliSub_Menu_03_Title;
    uint8_t runCmd_flag;
    uint8_t CAL1_Sub_Id;
    uint8_t CAL1_Id;
    uint8_t CAL2_Id ;
    uint8_t CAL3_Id;
    uint8_t CAL1_FlashSaveData;
    uint8_t CAL_Item_flag;
    
    

    uint8_t CaliMenu_01_Id;
    uint8_t CaliMenu_02_Id;
    uint8_t keyEnter_flag;

    uint8_t CaliSub_02_01_Item;
    uint8_t CaliSub_02_02_Item;
    uint8_t CaliSub_02_03_Item;
    uint8_t CaliSub_02_05_Item;
    uint8_t CaliSub_theSecond_02_Item;
    uint8_t CaliMenu_02_sub_Id;
    uint8_t runKeyMenu;
 
           

     uint8_t CaliSub_03_01_Itme;
    uint8_t CaliSub_03_02_Item;
    uint8_t CaliSub_03_03_Item;
  

    int8_t stackCali_02_01_Tp;
    int8_t stackCali_02_02_Tp;
    int8_t stackCali_02_03_Tp;

    uint8_t unit;
    uint8_t decade;
    uint8_t hundred;
    uint8_t onethousand;
    uint8_t tenthousand; //CaliSubMenu_03_01_01_5bitPoint(ACAL302);

   int8_t CAL1_sequence_flag;
   int8_t CAL2_sequence_flag;
   int8_t CAL3_sequence_flag;

    int8_t stackCali_03_01_Tp;
    int8_t stackCali_03_02_Tp;
    int8_t stackCali_03_03_Tp;

    uint32_t cal1_r00_reg;
    uint32_t cal1_r01_reg;
    uint32_t cal1_r02_reg;
    uint32_t cal1_r03_reg;

    uint32_t cal2_r00_reg;
    uint32_t cal2_r01_reg;
    uint32_t cal2_r02_reg;
    uint32_t cal2_r03_reg;
}cali;
extern cali cali_t;
enum calimenu{

    caliTheFirst_Menu,
    caliTheSecond_Menu,
    caliTheThird_Menu,
    caliTheFourth_Menu,
    caliTheFifth_Menu,
    caliTheSixth_Menu
};

enum cali{
   
   CAL1 ,
   CAL2 ,
   CAL3 ,
   CAL5 ,

};



extern int8_t caliMainTop  ;

extern int8_t caliSun_02_Top  ;

extern int8_t caliSubMenu_03_Top ;

extern int8_t ACAL1_00[1];
extern int8_t ACAL1_01[5];
extern int8_t ACAL1_02[5];
extern int8_t ACAL1_03[5];
extern int8_t ACAL1_021[5];
extern int8_t ACAL1_031[5];

extern int8_t ACAL2_00[1];
extern int8_t ACAL2_01[5];
extern int8_t ACAL2_02[5];
extern int8_t ACAL2_021[5];
extern int8_t ACAL2_03[5];
extern int8_t ACAL2_031[5];
extern int8_t ACAL2_04[5];
extern int8_t ACAL2_041[5];
extern int8_t ACAL3_02[5];
extern int8_t ACAL3_021[5];





uint8_t Push_stackCaliMain(int8_t maxize);
uint8_t Pop_stackCaliMain(int8_t maxize);
uint8_t CaliMain_stackTop(void);

int8_t Push_stackCaliMain_02(int8_t maxize);
int8_t Pop_stackCaliMain_02(int8_t maxize);
int8_t CaliSub_02_stackTop(int8_t maxize);

void KEY4_InputCalibration_Mode(void);
 void CALI_KEY3_SWITCH_Fun(void );
 void  CALI_KEY1_UP_Fun(void);
void CALI_KEY2_DOWN_Fun(void );
void CAL_KEY4_ENTER_Fun(void);

void CALI_MENU_01_DIS(uint8_t mu);
void CALI_MENU_SUB_02_DIS(void);
 void CALI_MENU_SUB_03_DIS(uint8_t mu); //speical numbers "0000 000 1000"
void Calibration_RunDisCmd(void);
void Calibration_TheSecondRunDis_Cmd(void );
void Calibration_TheThirdRunDis_Cmd(void );

void  Calibration_TheFourthRunDis_Cmd(void);

#endif 
