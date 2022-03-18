#include "f3menu.h"
f3classmenu f3menu_t;

static void Number_1bit_DIS(int8_t *pA);
static void Number_3bit_twoPoint_DIS(int8_t *pA);

int8_t AF3404[3];
int8_t AF3405[5];
int8_t AF3406[5];
int8_t AF3407[5];


/***********************************************************
 * 
 * Function Name: void F1SubMenu_Sub_03(void)
 * Function: the third menu display nixie tube 
 * 
 * 
***********************************************************/
uint8_t F3_04_PushSub_Item(int8_t nsize)
{
	 F3_04_item_Top++;
	 if(F3_04_item_Top > nsize){
	     // printf("Error :stack overflow \n");
	     //return ;
	  
	   F3_04_item_Top=1;
	}
	
	//F1SubMenu(menuF1SubTop);
	return F3_04_item_Top;
}
uint8_t F3_04_PopSub_Item(int8_t nsize)
{
	F3_04_item_Top--; 
	if(F3_04_item_Top == 0 || F3_04_item_Top ==-1 ){
	    //printf("Error : no element to Pop \n");
		//return;
		F3_04_item_Top = nsize  ;
	}
    

	
    return F3_04_item_Top ;
}
uint8_t F3_04_Item_Top(void)
{
	   return F3_04_item_Top ;
	
}

/*************************************************
*
*The F1 ->F1-01-> F1-01-01,F1-01-02,F1-01-03
*F1-01-04,F1-01-05,F1-01-06.....F1-01-13
*
*
*

*************************************************/
uint8_t F3_05_PushSub_Item(int8_t nsize)
{
	
	F3_05_item_Top++;
    if(F3_05_item_Top > (nsize - 1)){
	     // printf("Error :stack overflow \n");
	     //return ;
	  
	   F3_05_item_Top=0;
	}
	
	return F3_05_item_Top;
}
uint8_t F3_05_PopSub_Item(int8_t nsize)
{
	F3_05_item_Top--;
	if(F3_05_item_Top== -1){
	    //printf("Error : no element to Pop \n");
		//return;
		F3_05_item_Top = nsize -1 ;
	}
   
    return F3_05_item_Top ;
}
uint8_t F3_05_PopSub_Item_Top(void)
{
	   return F3_05_item_Top ;
	
}
/***********************************************************
 * 
 * Function Name: void F3SubMenu_03(F1submenuList f1sub)
 * Function :display nixie tube character
 * Input Ref: F1 menu submenu item
 * Retern Ref: No
 * 
************************************************************/
void F3_MasterFunction_EnterKey(void)
{
        if(menu_t.menuF3Sub_first==0){  //F3-1.
                menu_t.menuF3Sub_first++;
                menuFxSubTop=-1;
                mainitem_t.task_MainMenu=TheSecond_Menu;
                menu_t.menuTitle_02=3;
                menu_t.FxMainMenu_key =0xB0;
                menu_t.FxSub_02_key=0xf30;
                menu_t.F3_SubMenuTop= PushSub_Menu(F3Mnumbers);
                printf("F3_Keyreturn thirst = %d\n",key_t.keyReturn_F3_flag);
        } 
        else{
                key_t.keyReturn_F3_flag++;
                printf("F3_Keyreturn = %d\n",key_t.keyReturn_F3_flag);

                if(key_t.keyReturn_F3_flag==1){ //F3-1.1 

                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                        //menu_t.menuTitle_02=3;
                        menu_t.menuTitle_03=submenu_F3;

                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf30;  //F2-01 -> the third sub open

                        menu_t.F3_SubMenuTop_02 = submenu_03_Top();
                        menu_t.menu_F1Sub_03_xx_key=menu_t.F3SubMenu_Id;
                        printf("F3_enter_03 = %d\n",menu_t.F3SubMenu_Id);
                        //by test is success 

                }
                else if(key_t.keyReturn_F3_flag==2){ //the fourth menu
                        mainitem_t.task_MainMenu=TheFourth_Menu; //open the Fourth  menu


                        if(menu_t.F3SubMenu_Id==F301){

                                if(AF3401[0]==0){

                                menu_t.menu_F1Sub_03_xx_key = f3menu_t.threeClass_menu_Id; //EDIT.202203.18//= 1;
                                menu_t.menuTitle_04= 1; 
                                }
                                else{
                                menu_t.menu_F1Sub_03_xx_key= AF3401[0];
                                menu_t.menuTitle_04= AF3402[0]; 
                                }
                        }
                        else{  
                        if(AF3402[0]==0){
                                menu_t.menu_F1Sub_03_xx_key= 1;
                                menu_t.menuTitle_04= 1; 
                                }
                                else{

                                menu_t.menuTitle_04= AF3402[0];
                                menu_t.menu_F1Sub_03_xx_key=f3menu_t.threeClass_menu_Id; //AF3402[0]; 
                        }
                        }
                        //runKey fun
                        menu_t.FxMainMenu_key =0xD0; //the FOURTH menu open 
                        menu_t.FxSub_03_key=0xf3;  //F2-01 -> the third sub open


                     
                        printf("F3_enter_04 = %d\n",menu_t.menuTitle_04);
                        printf("F3_03_xx_key_04 = %d\n",menu_t.menu_F1Sub_03_xx_key);
                }
                else{ //Return F3  function
                        menu_t.menuId= F3;

                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu

                        menu_t.FxMainMenu_key =0xB0;
                        menu_t.menuTitle_02=3;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                        //  F2_01_xx_SelectCmd();
                        menu_t.F3_SubMenuTop=menu_t.F3SubMenu_Id;
                        key_t.keyReturn_F3_flag=0;
                        printf("f3sub_top_enter = %d\n",menu_t.F3_SubMenuTop);

                }

        }   

}
/***********************************************************
 * 
 * Function Name: void F1SubMenu_Sub_03(void)
 * Function: the third menu display nixie tube 
 * 
 * 
***********************************************************/
void F3_Add_TheThirdMenu_KeyFunction(uint8_t f3mu)
{
   switch(f3mu){
        case F301:
        AF3401[0]= F3_04_PushSub_Item(7);    // Number_Digital_Set5bit_AddSelect(AF3401,7);
        printf("AF3401= %d\n",AF3401[0]);
        break;

        case F302:
                AF3402[0]= F3_04_PushSub_Item(7);    // Number_Digital_Set5bit_twoAddSelect(AF3402,7);
                printf("AF3402= %d\n",AF3401[0]);
        break;


        }
        printf("f1f30_c_keyd+ = %d\n",menu_t.menu_F1Sub_03_xx_key);
}
/***********************************************************
 * 
 * Function Name: void F3SubMenu_02_DispSelect(uint8_t mn)
 * Function :display nixie tube character
 * Input Ref: F1 menu submenu item
 * Retern Ref: No
 * 
************************************************************/
void F3SubMenu_02_DispSelect(uint8_t mn)
{
        switch(mn){

	        case F301:
			menu_t.F3SubMenu_Id = F301;
			F3SubMenu_01(); //"F1 - 1."
			break;

		case F302:
			  //  F2SubMenu_Master_01();
			     menu_t.F3SubMenu_Id = F302;
			F3SubMenu_02(); //"F1-2."
		break;
			
		default:

		break;

	}

}




/*******************F3-01-01**********************************
 * 
 * Function Name:void F3SubMenu_03_Item(uint8_t mf301)
 * Function :Dispaly F3 of the third class menu 
 * 
 * 
*************************************************************/
void F3SubMenu_03_Item(uint8_t mf301)
{

       switch(mf301){

        case F301 : //display -> 3bit
           // menu_t.F3SubMenu_Id_03=F301;

           switch(AF3401[0]){

               case 0:

               break;

               case F3401:
                        f3menu_t.threeClass_menu_Id = 1;
                        SmgDisplay(digital_5,0x01); // 0~100
               break;

                case F3402:
                        f3menu_t.threeClass_menu_Id = 2;
                        SmgDisplay(digital_5,0x02); // 0~100
               break;

                case F3403:
                        f3menu_t.threeClass_menu_Id = 3;
                        SmgDisplay(digital_5,0x03); // 0~100
               break;

               case F3404:
                        f3menu_t.threeClass_menu_Id = 4;
                        SmgDisplay(digital_5,0x04); // 0~100
               break;

                case F3405:
                        f3menu_t.threeClass_menu_Id = 5;
                        SmgDisplay(digital_5,0x05); // 0~100
               break;

                case F3406:
                        f3menu_t.threeClass_menu_Id = 6;
                        SmgDisplay(digital_5,0x06); // 0~100
               break;

                case F3407:
                        f3menu_t.threeClass_menu_Id = 7;
                        SmgDisplay(digital_5,0x07); // 0~100
               break;


           }
            
        break;

        case F302 : //"5BIT" has "-"

              switch(AF3402[0]){

               case 0:

               break;

               case F3401:
                        f3menu_t.threeClass_menu_Id = 1;
                        SmgDisplay(digital_5,0x01); // 0~100
               break;

                case F3402:
                         f3menu_t.threeClass_menu_Id = 2;
                        SmgDisplay(digital_5,0x02); // 0~100
               break;

             case F3403:
                         f3menu_t.threeClass_menu_Id = 3;
                        SmgDisplay(digital_5,0x03); // 0~100
               break;

               case F3404:
                         f3menu_t.threeClass_menu_Id = 4;
                        SmgDisplay(digital_5,0x04); // 0~100
               break;

                case F3405:
                         f3menu_t.threeClass_menu_Id = 5;
                        SmgDisplay(digital_5,0x05); // 0~100
               break;

                case F3406:
                        f3menu_t.threeClass_menu_Id = 6;
                        SmgDisplay(digital_5,0x06); // 0~100
               break;

                case F3407:
                         f3menu_t.threeClass_menu_Id = 7;
                        SmgDisplay(digital_5,0x07); // 0~100
               break;


           }
            
        break;
          
        break;

        default:

        break;
    }



}

/*************************************************************************************
*
*Function Name:void F3_SubMenu_TheFourth_Fun(uint8_t f3mu)
*Function :control F3 the fourth class menu fun
*
*
*************************************************************************************/
void F3_SubMenu_TheFourth_RunCmdDis(uint8_t f3mu)
{
      switch(f3mu){

                  case F3401:
                      menu_t.DisplaySmgBit_Select_Numbers=3;
                       switch(f3menu_t.F3_theFourth_Id){

                               case 0: //
                                   Symbol_nonE();
                               break;

                               case 1:
                                   Symbol_Por();
                               break;

                               case 2:
                                 Symbol_EEr();
                               break;

                       }
                  break;

                  case F3402:
                       
                    
                        Number_1bit_DIS(AF3402);
                         
                break;

                  case F3403:
                          menu_t.DisplaySmgBit_Select_Numbers=0;
                           switch(f3menu_t.F3_theFourth_Id){

                               case 0: //
                                    Symbol_PRS();
                               break;

                               case 1:
                                Symbol_nEt();
                               break;

                               case 2:
                                 Symbol_uRLEy();
                               break;

                              case 3:
                                Symbol_CnoSS();
                               break;

                               case 4:
                                 Symbol_PERH();
                               break;

                                case 5:
                                 Symbol_p_u();
                               break;

                             

                       }
                       
                  break;

                  case F3404: //display 3 bit digital 
                      menu_t.DisplaySmgBit_Select_Numbers=3;
                      Number_3bit_twoPoint_DIS(AF3404);
                  break;

                  case F3405://display 5bi digital with"-""
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                       F2SubMenu_F202_01_Select_DIS(AF3405);
                        
                  break;

                  case F3406://display 5bi digital
                    menu_t.DisplaySmgBit_Select_Numbers=5;
                     F2SubMenu_F202_01_Select_DIS(AF3406);
                      
                  break;

                  case F3407://display 5bi digital
                    menu_t.DisplaySmgBit_Select_Numbers=5;
                      F2SubMenu_F202_01_Select_DIS(AF3407);
                      
                  break;

              }  
        
        
}

/***********************************************************
 * 
 * Function Name: void F1SubMenu_Sub_03(void)
 * Function: the third menu display nixie tube 
 * 
 * 
***********************************************************/
void F3SubMenu_01(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay_Point(digital_4,0x01); //'1.'
   SmgDisplay(digital_5,0x0B); //'NULL'

}
void F3SubMenu_02(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay_Point(digital_4,0x02); //'1.'
   SmgDisplay(digital_5,0x0B); //'NULL'
}
void F3SubMenu_F301_01_Select_DIS(int8_t *pA,uint8_t n)
{
     static uint8_t i=0;
     if(i==0){
        if(*pA==0)*pA =1;
         i++;
     }
      SmgDisplay(digital_5,*pA); // 0~100
       
}
void F3SubMenu_F302_02_Select_DIS(int8_t *pA,uint8_t n)
{
      static uint8_t i=0;
     if(i==0){
        if(*pA==0)*pA =1;
         i++;
     }
      SmgDisplay(digital_5,*pA); // 0~100
}
void F3SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x03); //'3'
  

}
/************************************************************************
 * 
 * Function Name:void F3_Add_TheFourthMenu_KeyFunction(uint8_t f3mu4)
 * Function:F3 menu by input by key be pressd ad add 
 * 
 * 
 ***********************************************************************/
void F3_Add_TheFourthMenu_KeyFunction(uint8_t f3mu4)
{
        switch(f3mu4){

                  case F3401:
                      f3menu_t.F3_theFourth_Id = F3_05_PushSub_Item(3); //Number_Digital_Set5bit_ZeroAddSelect(AF301,3);
                  break;

                  case F3402:
                      
                        Number_Digital_1bit_AddSelect(AF302);
                        printf("AF302[0] + = %d\n",AF302[0]);
                  break;

                  case F3403:
                     
                       f3menu_t.F3_theFourth_Id = F3_05_PushSub_Item(6);  //Number_Digital_Set5bit_ZeroAddSelect(AF303,6);
                  break;

                  case F3404:
                        Number_Digital_3bit_AddSelect(AF3404);
                  break;

                  case F3405:
                        Number_Digital_5bit_AddSelect(AF3405);
                  break;

                  case F3406:
                     Number_Digital_5bit_AddSelect(AF3406);
                  break;

                  case F3407:
                         Number_Digital_5bit_AddSelect(AF3407);
                  
                  break;


        }
}
/************************************************************************
 * 
 * Function Name:void F3_Add_TheFourthMenu_KeyFunction(uint8_t f3mu4)
 * Function:F3 menu by input by key be pressd ad add 
 * 
 * 
 ***********************************************************************/
void F3_Dec_TheFourthMenu_KeyFunction(uint8_t f3mu4)
{
        switch(f3mu4){

                  case F3401:
                      f3menu_t.F3_theFourth_Id = F3_05_PopSub_Item(3); //Number_Digital_Set5bit_ZeroAddSelect(AF301,3);
                  break;

                  case F3402:
                   
                      Number_Digital_1bit_DecSelect(AF302);
                      printf("AF302[0] - = %d\n",AF302[0]);
                  break;

                  case F3403:
                     
                       f3menu_t.F3_theFourth_Id = F3_05_PopSub_Item(6);  //Number_Digital_Set5bit_ZeroAddSelect(AF303,6);
                  break;

                  case F3404:
                        Number_Digital_3bit_DecSelect(AF3404);
                  break;

                  case F3405:
                        Number_Digital_5bit_DecSelect(AF3405);
                  break;

                  case F3406:
                     Number_Digital_5bit_DecSelect(AF3406);
                  break;

                  case F3407:
                         Number_Digital_5bit_DecSelect(AF3407);
                  
                  break;


        }
}
void F3_Dec_TheThirdMenu_KeyFunction(uint8_t f3mu3)
{
    switch(f3mu3){
    case F301:

    AF3401[0]=F3_04_PopSub_Item(7);//Number_Digital_Set5bit_DecSelect(AF3401,7);
    printf("AF3401 key- = %d\n",AF3401[0]);  
    break;

    case F302:
    AF3402[0]= F3_04_PopSub_Item(7);//Number_Digital_Set5bit_twoDecSelect(AF3402,7);
    printf("AF3402 key- = %d\n",AF3401[0]);
    break;


    printf("F3f30_DecKey - = %d\n",menu_t.menu_F1Sub_03_xx_key);
    break;
        
    }
}



/***********************************************
*
*Smg F1-05 display  2 bit 1-5.0
*
**********************************************/
static void Number_1bit_DIS(int8_t *pA)
{
   
   SmgDisplay(digital_1,0x0b); // null
   SmgDisplay(digital_2,0x0b); // null
   SmgDisplay(digital_3,0x0b); // null
   SmgDisplay(digital_4,0x0b); // null
   SmgDisplay(digital_5,*pA); // 0~100
  

}

void Number_3bit_twoPoint_DIS(int8_t *pA)
{
    SmgDisplay(digital_1,0x0b); // null
   SmgDisplay(digital_2,0x0b); // null
   SmgDisplay(digital_3,*(pA+2)); // 0~100
   SmgDisplay_Point(digital_4,*(pA+1));  // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
}
