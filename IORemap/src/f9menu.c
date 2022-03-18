#include "f9menu.h"

int8_t *pa;

static void  F9SubMenu_02_00_Dis(int8_t *pa);
static void  F9SubMenu_03_00_Dis(int8_t *pa);
static  void F9SubMenu_02_05_Dis(void);
static void   F9SubMenu_02_06_Dis(void);
F9menu f9menu_t;

void F9_MasterFunction_EnterKey(void)
{
     if(f9menu_t.menuF9Sub_first==0){  //F8- 01 
                  f9menu_t.menuF9Sub_first++;
                  menuFxSubTop=-1;
                  mainitem_t.task_MainMenu=TheSecond_Menu;

                  menu_t.menuTitle_02=9; //the second menu 
                  menu_t.FxMainMenu_key =0xB0;
                   menu_t.FxSub_02_key=0xf90;
                  f9menu_t.F9_SubMenuTop = PushSub_Menu(F9Mnumbers);
                  printf("f9_theFirst_enkey = %d\n",menu_t.menuTitle_02);
		} 
            else{ //F801-> 01
                  key_t.f9keyReturn_flag = key_t.f9keyReturn_flag^ 0x01;
                  if(key_t.f9keyReturn_flag== 1){
                 
                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                       
                         menu_t.menuTitle_03=submenu_F9;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf90;  //the third sub open
            
                       //f7menu_t.F7_03_subMenuTop=f7menu_t.F7SubMenu_Id;
                        menu_t.menu_F1Sub_03_xx_key=f9menu_t.F9SubMenu_Id;
                        printf("f9_03_Top = %d\n",f9menu_t.F9_03_subMenuTop);
                  }    
                  else{
                        
                        menu_t.menuId= F9;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0; 
                       menu_t.FxSub_02_key=0xf90; 
                        menu_t.menuTitle_03=0;
				menu_t.menuTitle_02=9; 
                        f9menu_t.F9_SubMenuTop=f9menu_t.F9SubMenu_Id;
                     
                        printf("f9_04_enkey = %d\n",f9menu_t.F9_03_subMenuTop);
                    }

            }          
}

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