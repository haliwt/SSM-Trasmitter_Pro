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
*Function Name :void TheThird_F1_03_Menu(void)
*Function :selected the be going to run cmd
*Input Refer:NO
*Return Refer:NO
*
************************************************/
void TheThird_F1_03_Menu(void)
{
     switch(menu_t.menu_F1Sub_03_xx_key){
				   
				   case 0: //F1-01-01
                      menu_t.F1SubMenu_Sub_02_Id =0;
				       F1SubMenu_F101_01_Select_DIS(menu_t.F1_Sub01_Top);
                     //  printf("f1sub_01_03_Top = %d\n",menu_t.F1_Sub01_Top);
                       key_t.keyReturn_flag=1;
                      
				   break;
				   
				   case 0x01: //F1-02-01 ->
                       menu_t.F1SubMenu_Sub_02_Id =0x01;
					   F1SubMenu_F1_02_01(menu_t. F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                     //  printf("f1sub_02_03_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;
                       
				   break;

                   case 0x02:
                        menu_t.F1SubMenu_Sub_02_Id =0x02;
					   F1SubMenu_F1_02_01(menu_t. F1_Sub03_unit,menu_t.F1_Sub03_decade,menu_t.F1_Sub03_hundred);
                     //  printf("f1sub_02_03_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;

                   break;

                   case 0x03://F1-04-01
                        menu_t.F1SubMenu_Sub_02_Id =0x03;
                        F1SubMenu_F104_01_Select_DIS(AF104);
                        key_t.keyReturn_flag=1;
                   break;

                   break;

                   case 0x04://F1-05-01 
                      menu_t.F1SubMenu_Sub_02_Id =0x04;
                       key_t.keyReturn_flag=1;
                       F1SubMenu_F105_01_Select_DIS(AF105);

                   break;
                   case 0x05 : //F1-06-01 -->5bit
                       menu_t.F1SubMenu_Sub_02_Id =0x05;
                        F1SubMenu_F106_01_Select_DIS(AF106);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x06 : //F1-07-01 -->5bit 
                        menu_t.F1SubMenu_Sub_02_Id =0x06;
                        F1SubMenu_F106_01_Select_DIS(AF107);
                        key_t.keyReturn_flag=1;
				   break;

                  case 0x07 : //F1-08-01
                        menu_t.F1SubMenu_Sub_02_Id =0x07;
                         F1SubMenu_F105_01_Select_DIS(AF108);
                        key_t.keyReturn_flag=1;
				   break;

                  case 0x08 : //F1-09-01 ->4bit
                         menu_t.F1SubMenu_Sub_02_Id =0x08;
                        F1SubMenu_F109_01_Select_DIS(AF109);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x09 : //F1-10-01 -> 5bit
                        menu_t.F1SubMenu_Sub_02_Id =0x09;
                        F1SubMenu_F110_01_Select_DIS(AF110);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0A : //F1-11-01 -> 4bit
                         menu_t.F1SubMenu_Sub_02_Id =0x0A;
                        F1SubMenu_F111_01_Select_DIS(AF111);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0B : //F1-12-01 -> 2bit
                        menu_t.F1SubMenu_Sub_02_Id =0x0B;
                        F1SubMenu_F112_01_Select_DIS(AF112);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0C : //F1-13-01
                        menu_t.F1SubMenu_Sub_02_Id =0x0C;
                         F1SubMenu_F112_01_Select_DIS(AF113);
                        key_t.keyReturn_flag=1;
				   break;

		}
}



void F2SubMenu_03_Item(void)
{
    switch(menu_t.menu_F1Sub_03_xx_key){
                 
                 case F201 : //display -> 3bit
                        menu_t.F2SubMenu_Id=F201;
                        F2SubMenu_F201_01_Select_DIS(AF201);
                 break;

                 case F202 : //"5BIT" has "-"
                        menu_t.F2SubMenu_Id=F202;
                        F2SubMenu_F202_01_Select_DIS(AF202);
                 break;

                 case F203 : //5BIT 
                         menu_t.F2SubMenu_Id=F203;
                         F2SubMenu_F203_01_Select_DIS(AF203);
                 break;

                 case F204 : //3bit
                         menu_t.F2SubMenu_Id=F204;
                         F2SubMenu_F201_01_Select_DIS(AF204);//F2SubMenu_F204_01_Select_DIS(AF204);
                 break;
                
                case F205 : //"5BIT" has "-"
                        menu_t.F2SubMenu_Id=F205;
                        F2SubMenu_F202_01_Select_DIS(AF205); //F2SubMenu_F205_01_Select_DIS(AF205);
                 break;

                 case F206 ://"5BIT"
                        menu_t.F2SubMenu_Id=F206;
                        F2SubMenu_F203_01_Select_DIS(AF206);//F2SubMenu_F206_01_Select_DIS(AF206);
                 break;
                 default:

                 break;


            }
			



}

