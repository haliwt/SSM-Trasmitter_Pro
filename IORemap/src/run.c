#include "run.h"
 mainitem mainitem_t;
submenublinkmenu blinkMenu;


void CheckMode(uint8_t mydata)
{
    KEY_Function(mydata);

}

void RunCommand(void)
{
     switch(mainitem_t.task_MainMenu){

         case 0:

         break;
         
         
         case TheFirst_Menu:
                 MainMenu(menu_t.mainTop);
         break;

         case TheSecond_Menu:
                menu_t.F1_Submenu_Check_flag =0x02;
                F1_DIS();
                F1SubMenu(menu_t.F1_SubMenuTop); //"Fx - 01"
                printf("f1sub_Top_run = %d\n",menu_t.F1_SubMenuTop);
                key_t.keyReturn_flag=0;
         break;

         case TheThird_Menu:
              TheThird_03_Menu();

         break;
         
         case TheFourth_Menu: //F3->F3-1->F3-1.1 -> ;F3-2 ->F3-2.1
         
         break;

         default:
           run_t.dispCmd =0;

         break;



     }


}
void RunBlinkbMenuCmd(void)
{
     switch(blinkMenu.EditSubmenu_03){
         
         case 0:
         
         break;
         
         case F1_BLINK_1:
              F1_TheBlinkMenu_03();
         break;
         
         case F2_BLINK_2:
         
         break;
         
         case F3_BLINK_3:
         
         break;
         
         case F7_BLINK_7:
         
         break;
         
         case F8_BLINK_8:
         
         break;
         
         case F9_BLINK_9:
         
         break;
         
         
     }
     
    
    
}


	
