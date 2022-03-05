#include "run.h"
 mainitem mainitem_t;

static void TheThird_03_Menu(void);
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
                menu_t.F1_Submenu_Check_flag =10;
                F1_DIS();
                F1SubMenu(menu_t.F1_SubMenuTop); //"Fx - 01"

         break;

         case TheThird_Menu:
              TheThird_03_Menu();

         break;

         default:
           run_t.dispCmd =0;

         break;



     }


}

/************************************************
 ***********************************************/
static void TheThird_03_Menu(void)
{
    switch(menu_t.menuTitle){

          case submenu_F1: //F1-01
            
              
          switch(menu_t.F1SubMenu_Sub_03_Id){
           
                    case  F101_01 :
                            
                                menu_t.F1_Submenu_Check_flag =101; //0x01
                                F1SubMenu_F101_Select_DIS(menu_t.F1_Sub01_Top); //"---9"
                        break;
                    case F101_02 :
                                menu_t.F1_Submenu_Check_flag =102;
                                F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_03 :
                                menu_t.F1_Submenu_Check_flag =103;
                                F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_04 :
                                menu_t.F1_Submenu_Check_flag =104;
                                F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_05 :
                                menu_t.F1_Submenu_Check_flag =105;
                                F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_06:
                                menu_t.F1_Submenu_Check_flag =106;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_07 :
                                menu_t.F1_Submenu_Check_flag =107;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_08 :
                                menu_t.F1_Submenu_Check_flag =108;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_09 :
                                menu_t.F1_Submenu_Check_flag =109;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_10 :
                                menu_t.F1_Submenu_Check_flag =110;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case F101_11 :
                                menu_t.F1_Submenu_Check_flag =111;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        
                    case F101_12:
                                menu_t.F1_Submenu_Check_flag =112;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                    case  F101_13:
                                menu_t.F1_Submenu_Check_flag =113;
                                 F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        break;
                 }
           
          break;

          case submenu_F2:
            F2SubMenu_Master_01();
			F1SubMenu(menu_t.F2_SubMenuTop);
            
          break;

          case submenu_F3:
            F3SubMenu_Master_01();
            F1SubMenu(menu_t.F3_SubMenuTop);
           
          break;

       
          case submenu_F7:
             F7SubMenu_Master_01();
             F1SubMenu(menu_t.F7_SubMenuTop);
           
          break;

          case submenu_F8:
              menu_t.menuSubId = submenu_F8;
               F8SubMenu_Master_01();
               F1SubMenu(menu_t.F8_SubMenuTop);
            
          break;

          case submenu_F9:
              menu_t.menuSubId = submenu_F9;
              F9SubMenu_Master_01();
              F1SubMenu(menu_t.F9_SubMenuTop);
             
          break;

          default:

          break;
    }


}
	
