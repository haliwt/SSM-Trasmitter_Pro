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


typedef enum{
  F201,
  F202,
  F203,
  F204,
  F205,
  F206

}F2SubMenuenum_02;


typedef enum{
  F301,
  F302,
}F3SubMenuenum_01_03;

typedef enum{
  F30_11,
  F30_21,

  F30_12,
  F30_22,

  F30_13,
  F30_23,

  F3_14,
  F3_24,

  F3_15,
  F3_25,

  F3_16,
  F3_26,

  F3_17,
  F3_27
  

}F3SubMenuenum_03_03;

typedef enum{
  F3401=0X01,
  F3402,
  F3403,
  F3404,
  F3405,
  F3406,
  F3407
  
}F3SubMenuenum_04;


int8_t Is_empty(Stacksubmenu_03 *sm03);
int8_t Is_full(Stacksubmenu_03 *sm03);
int8_t subPush_03(Stacksubmenu_03 *sm03, uint8_t dat);
int8_t subPop_03(Stacksubmenu_03 *sm03);
int8_t subTop_03(Stacksubmenu_03 *sm03);

void TheThird_F1_03_Menu(void);
void TheThird_F2_03_Menu(void);
void F1_TheBlinkMenu_03(void);

void F3SubMenu_03_Item(uint8_t mf301);




void F2SubMenu_03_Item(void);

void F7SubMenu_03_Item(void);
void F8ubMenu_03_Item(void);
void F9SubMenu_03_Item(void);



#endif 

