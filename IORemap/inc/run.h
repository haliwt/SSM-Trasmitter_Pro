#ifndef __RUN_H_
#define __RUN_H_
#include "main.h"

typedef struct _RUN{
  
    uint8_t dispCmd;


}run;

extern run run_t;

typedef enum{
   
     TheFirst_Menu,
     TheSecond_Menu,
     Thethird_Menu
  

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
     uint8_t task_SubMenu_03;
     

}mainitem;

extern mainitem mainitem_t;
void CheckMode(uint8_t mydata);
void RunCommand(void);




#endif 
