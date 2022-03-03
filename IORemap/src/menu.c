#include "menu.h"

MENU menu_t;

uint8_t PushSu_bMenu(int8_t nsize);
uint8_t PopSub_Menu(int8_t nsize);

uint8_t PushSub_Sub_Menu(int8_t msize);
uint8_t PopSub_Sub_Menu(int8_t msize);

int8_t menuTop= -1;
int8_t menuFxSubTop=-1;
int8_t menuFxSub_03_Top = -1;


uint8_t PushMainMenu(void)
{
    
	if(menuTop==(MAX_SIZE_MAINMENU -1)){
	     // printf("Error :stack overflow \n");
	     //return ;
	  
	   menuTop=0;
	}
	else{
		menuTop++;
	}
	//MainMenu(menuTop);
	return menuTop;
}

uint8_t PopMainMenu(void)
{
    menuTop--;
	if(menuTop == -1){
	    //printf("Error : no element to Pop \n");
		//return;
		menuTop = MAX_SIZE_MAINMENU -1 ;
	}
   // MainMenu(menuTop);
	return menuTop;
}
int8_t PopMainMenu_Return(void)
{
    menuTop--;
	if(menuTop == -1){
	   // //printf("Error : no element to Pop \n");
		//return;
	   //menuTop = MAX_SIZE_MAINMENU -1 ;
	   return -1;
	}
   // MainMenu(menuTop);
	return menuTop;

}

void TopMainMenu(void)
{
   MainMenu(menuTop);
}

void MainMenu(int8_t mtop)
{
     switch(mtop){

        case F1:
		   
            menu_t.menuId=F1;
		    Menu_F1();

		break;

		case F2:
		    menu_t.menuId=F2;
			Menu_F2();
		break;

		case F3:
			menu_t.menuId=F3;
			Menu_F3();
		break;

	    case F7:
			menu_t.menuId=F7;
			Menu_F7();
		break;

		case F8:
			menu_t.menuId=F8;
			Menu_F8();
		break;

		case F9:
			menu_t.menuId=F9;
			Menu_F9();
		break;

		default:

		break;

	}
}
/***********************************************************
 * 
 * Function Name: void PushF1SubMenu(void)
 * Function :push in stack menu add 
 * 
 * 
************************************************************/
uint8_t PushSub_Menu(int8_t msize)
{
	if(menuFxSubTop==(msize - 1)){
	     // printf("Error :stack overflow \n");
	     //return ;
	  
	   menuFxSubTop=0;
	}
	else{
		menuFxSubTop++;
	}
	//F1SubMenu(menuF1SubTop);
	return menuFxSubTop;

}
uint8_t PopSub_Menu(int8_t msize)
{
	menuFxSubTop--;
	if(menuFxSubTop == -1){
	    //printf("Error : no element to Pop \n");
		//return;
		menuFxSubTop = msize -1 ;
	}
    //F1SubMenu(menuF1SubTop);
    return menuFxSubTop ;
}
int8_t SubMenu_02_Top(void)
{
   return menuFxSubTop;

}
/*************************************************
//The thrid menu Sub menu
*************************************************/
uint8_t PushSub_03_Menu(int8_t nsize)
{
	 if(menuFxSub_03_Top== (nsize +1)){
	     // printf("Error :stack overflow \n");
	     //return ;
	  
	   menuFxSub_03_Top=1;
	}
	else{
		menuFxSub_03_Top++;
	}
	//F1SubMenu(menuF1SubTop);
	return menuFxSub_03_Top;
}
uint8_t PopSub_03_Menu(int8_t nsize)
{
	menuFxSub_03_Top--;
	if(menuFxSub_03_Top == 0){
	    //printf("Error : no element to Pop \n");
		//return;
		menuFxSub_03_Top = nsize  ;
	}
    //F1SubMenu(menuF1SubTop);
    return menuFxSub_03_Top ;
}
uint8_t SubMenu_03_Top(void)
{
	   return menuFxSub_03_Top ;
	
}
/***********************************************************
 * 
 * Function Name: void F1SubMenu(F1submenuList f1sub)
 * Function :display nixie tube character
 * Input Ref: F1 menu submenu item
 * Retern Ref: No
 * 
************************************************************/
void F1SubMenu(int8_t f1sub)
{
		switch(f1sub){

			case F101:
			    menu_t.F1SubMenu_Id = F101;
				F1SubMenu_01(); //"F1 ---"
			break;

			case F102:
			     menu_t.F1SubMenu_Id = F102;
				F1SubMenu_02();
			break;
			
			case F103:
			     menu_t.F1SubMenu_Id = F103;
				F1SubMenu_03();
			break;
				
			case F104:
				 menu_t.F1SubMenu_Id = F104;
				F1SubMenu_04();
			break;

			case F105:
				 menu_t.F1SubMenu_Id = F105;
				F1SubMenu_05();
			break;
				
			case F106:
				 menu_t.F1SubMenu_Id = F106;
				F1SubMenu_06();
			break;

			case F107:
				 menu_t.F1SubMenu_Id = F107;
				 F1SubMenu_07();
			break;

			case F108:
				 menu_t.F1SubMenu_Id = F108;
				F1SubMenu_08();
			break;

			case F109:
				menu_t.F1SubMenu_Id = F109;
				F1SubMenu_09();
			break;

			case F110:
				 menu_t.F1SubMenu_Id = F110;
				F1SubMenu_10();
			break;

			case F111:
				 menu_t.F1SubMenu_Id = F111;
				F1SubMenu_11();
			break;

			case F112:
				 menu_t.F1SubMenu_Id = F112;
				F1SubMenu_12();
			break;

			case F113:
				 menu_t.F1SubMenu_Id = F113;
				F1SubMenu_13();
			break;

			default:

			break;


		}

}
//F1 MENU the third menu 
void F1SubMenu_F101_Select_DIS(uint8_t subm3)
{
   switch(subm3){
     
	   case 0:
            F1SubMenu_Sub_01_01();
	   break;

	   case 1:
			F1SubMenu_Sub_01_02();
	   break;

	   case 2:
			 F1SubMenu_Sub_01_03();
	   break;

	   case 3:
             F1SubMenu_Sub_01_04();
	   break;

	   case 4:
			 F1SubMenu_Sub_01_05();
	   break;
       default:

	   break;
	}
}
//F1 menu the third menu 
void F1SubMenu_F102_Select_DIS(int8_t unit,int8_t decade,int8_t hundred)
{
	 
	F1SubMenu_F1_02_01(unit,decade,hundred);
	
}






