#ifndef __RUN_H_
#define __RUN_H_
#include "main.h"

typedef struct _RUN{
  
    uint8_t dispCmd;
    uint8_t keySetValue;
    uint8_t keyReturn;
    uint8_t Fx_Menu_Function ;
	uint8_t timerOver_flag;
    uint8_t EnterKey_flag
}run;

extern run run_t;

typedef enum{
   
     TheFirst_Menu =0x01,
     TheSecond_Menu,
     TheThird_Menu,
     TheFourth_Menu,
     TheFifth_Menu,
     TheSixth_Menu,
     TheSeventh_Menu,

}MainMenuStructure;

typedef enum{
    
    theFirst_02_Menu,
    theSecond_02_Menu,
    theThird_02_Menu

}subMenuStructure;

typedef enum{
    
    theFirst_02__03_Menu,
    theSecond_02_03_Menu,
    theThird_02_03_Menu

}subsubMenuStructure;

typedef struct _MainItem{
   
     uint8_t task_MainMenu;
     uint8_t task_SubMenu_02;
     uint8_t task_Stacksubmenu_03;
     

}mainitem;

extern mainitem mainitem_t;
void CheckMode(uint8_t mydata);
void RunCommand(void);
void RunBlinkbMenuCmd(void);

void RunCalibration_Command(void);

#endif 
