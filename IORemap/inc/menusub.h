#ifndef __MENUSUB_H_
#define __MENUSUB_H_
#include "main.h"
#define  MAX_SUB_SIZE_03   5

struct stackmenu{
    uint8_t subdata[MAX_SUB_SIZE_03] ;
    int8_t submenuTop_03;
    
};
typedef struct stackmenu Stacksubmenu_03;



typedef struct b_blinkMenu{
    
    uint8_t   EditSubmenu_03;
    uint8_t   wp_submenu;
   

      
      
}submenublinkmenu;
extern submenublinkmenu blinkMenu;

typedef enum{
    
     F1_BLINK_1 = 0X01,
     F2_BLINK_2,
     F3_BLINK_3,
     F7_BLINK_7,
     F8_BLINK_8,
     F9_BLINK_9
}enumblinkmenu;

void StackStacksubmenu_03_Init(Stacksubmenu_03 *sm03);
int8_t Is_empty(Stacksubmenu_03 *sm03);
int8_t Is_full(Stacksubmenu_03 *sm03);
int8_t subPush_03(Stacksubmenu_03 *sm03, uint8_t dat);
int8_t subPop_03(Stacksubmenu_03 *sm03);
int8_t subTop_03(Stacksubmenu_03 *sm03);

void TheThird_03_Menu(void);
void F1_TheBlinkMenu_03(void);





#endif 

