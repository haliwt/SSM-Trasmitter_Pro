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
               
                switch(menu_t.menuTitle_02){
                 case 0:

                 break;
               
                 case 1://F1-01
                     menu_t.F1_Submenu_Check_flag =0x01;
                     F1_DIS();
                    F1SubMenu(menu_t.F1_SubMenuTop); //"Fx - 01"
                    printf("f1sub_Top_run = %d\n",menu_t.F1_SubMenuTop);
                    key_t.keyReturn_flag=0;

                 break;

                 case 2://F2-01
                     menu_t.F1_Submenu_Check_flag =0x02;
                     F2SubMenu_Master_01();
                     F2SubMenu_02(menu_t.F2_SubMenuTop);
                 break;

                 case 3: //F3-01-
                     menu_t.F1_Submenu_Check_flag =0x03;
                     F3SubMenu_Master_01();
                     F3SubMenu_02_DispSelect(menu_t.F3_SubMenuTop);
                 break;

                 case 7: //F7-01-

                 break; 

                 case 8: //F8-01-

                 break; 

                 case 9: //F8-01-

                 break; 

               
                }
         break;

         case TheThird_Menu:
               switch(menu_t.menuTitle_03){

                   case 0:
                         mainitem_t.task_MainMenu=TheSecond_Menu;
                    break;

                   case submenu_F1: //F1-01:
                         TheThird_F1_03_Menu();
                    break;
                    
                    case submenu_F2:
                           F2SubMenu_03_Item();//TheThird_F2_03_Menu();
                    break;

                    case submenu_F3:
                           F3SubMenu_03_Item(menu_t.menu_F1Sub_03_xx_key);//TheThird_F2_03_Menu();

                    break;

                    case submenu_F7:

                    break;

                    case submenu_F8:

                    break;

                    case submenu_F9:

                    break;

              }
              
             

         break;
         
         case TheFourth_Menu: //F3->F3-1->F3-1.1 -> ;F3-2 ->F3-2.1
              
              switch(menu_t.menuTitle_04){

                   case 0:

                   break;

                   case F430:
                         F3SubMenu_04_Item(AF340,AFP340);
                   break;
              }
                 
         break;

         default:
           run_t.dispCmd =0;

         break;



     }


}



	
