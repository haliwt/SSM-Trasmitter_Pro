#include "menusub.h"

void StackStacksubmenu_03_Init(Stacksubmenu_03 *sm03)
{
    sm03->submenuTop_03 =-1;
}
int8_t Is_empty(Stacksubmenu_03 *sm03)
{
    if(sm03->submenuTop_03 !=-1)
	     return -1;
	else 
	   return 0;
}
int8_t Is_full(Stacksubmenu_03 *sm03)
{
    if(sm03->submenuTop_03 !=  MAX_SUB_SIZE_03 -1)
	    return -1;
	else 
	   return 0;
}
int8_t subPush_03(Stacksubmenu_03 *sm03,uint8_t dat)
{
    if(!Is_full(sm03)){
		return -1;
	}
	else{
		
		sm03->submenuTop_03++;
		sm03->subdata[sm03->submenuTop_03]=dat;
	}
	return 0;
}

int8_t subPop_03(Stacksubmenu_03 *sm03)
{
    if(!Is_empty(sm03)){
          return -1;
    }
	else{
		sm03->submenuTop_03--;
		return sm03->subdata[sm03->submenuTop_03];
	}
    
}
int8_t subTop_03(Stacksubmenu_03 *s)
{
    if(!Is_empty(s)){
        return -1;
    }
	else{
		return s->subdata[s->submenuTop_03];
	}
}


/************************************************
*
*Function Name :void TheThird_03_Menu(void)
*Function :selected the be going to run cmd
*Input Refer:NO
*Return Refer:NO
*
************************************************/
void TheThird_03_Menu(void)
{
    switch(menu_t.menuTitle_03){

           case 0:
               mainitem_t.task_MainMenu=TheSecond_Menu;
           break;
           
           case submenu_F1: //F1-01
		      
		       switch(menu_t.menu_F1Sub_03_xx_key){
				   
				   case 0:
				       F1SubMenu_F101_01_Select_DIS(menu_t.F1_Sub01_Top);
                     //  printf("f1sub_01_03_Top = %d\n",menu_t.F1_Sub01_Top);
                       key_t.keyReturn_flag=1;
                      
				   break;
				   
				   case 0x01:
                       menu_t.F1SubMenu_Sub_02_Id =0x01;
					   F1SubMenu_F1_02_01(menu_t. F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                     //  printf("f1sub_02_03_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;
                       
				   break;

				   
				   case 0x0c:
					   
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

void F1_TheBlinkMenu_03(void)
{
	  switch(menu_t.F1SubMenu_Sub_03_Id){
           
                    case  F101_01 :
                            
                                menu_t.F1_Submenu_Check_flag =101; //0x01
                                F1SubMenu_F101_01_Select_DIS(menu_t.F1_Sub01_Top); //"---9"
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
         
	
	
}
