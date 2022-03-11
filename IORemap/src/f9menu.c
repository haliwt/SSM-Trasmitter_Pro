#include "f9menu.h"

int8_t *pa;

static void  F9SubMenu_02_00_Dis(int8_t *pa);
static void  F9SubMenu_03_00_Dis(int8_t *pa);
static  void F9SubMenu_02_05_Dis(void);
static void   F9SubMenu_02_06_Dis(void);
F9menu f9menu_t;


void F9SubMenu_02_DIS(uint8_t mu)
{
    switch(mu){

        case 1:
           

        break;

        case 3:
             
        break;

         case 5:
             
        break;

        case 6:
             
        break;


    }


}



 void F9SubMenu_03_DIS(uint8_t mu)
 {
        switch(mu){

        case 1:
            F9SubMenu_02_00_Dis(pa);

        break;

        case 3:
          //   F9SubMenu_02_03_Dis(pa);
        break;

         case 5:
              F9SubMenu_02_05_Dis();
        break;

        case 6:
              F9SubMenu_02_06_Dis();
        break;


    }



 }
 
static void  F9SubMenu_02_00_Dis(int8_t *pa)
 {
 
 
 }
static void  F9SubMenu_03_00_Dis(int8_t *pa)
{



}

static  void F9SubMenu_02_05_Dis(void)
{

}
static void   F9SubMenu_02_06_Dis(void)
{


}