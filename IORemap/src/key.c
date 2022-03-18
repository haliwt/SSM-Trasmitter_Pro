#include "key.h"
#include "menu.h"
#include <stdio.h>



#define MAZ_F1_SUBMENU_SIZE   13



KEY key_t;
run run_t;

uint32_t *pfdata;
uint32_t *pfInputData;

// pfdata=flash_t.flashData;


uint8_t F305_tmp4,F305_tmp5,F305_tmp6,F305_tmp7;
subNumbers_TypedDef submenStruct;


int8_t AF104[4];
int8_t AF105[2];
int8_t AF106[5];
int8_t AF107[5];
int8_t AF108[2];
int8_t AF109[5];
int8_t AF110[4];
int8_t AF111[1];
int8_t AF112[2];
int8_t AF113[2];

//*******F2************/
int8_t AF201[1];
int8_t AF202[5];
int8_t AF203[5];
int8_t AF204[1];
int8_t AF205[5];
int8_t AF206[5];

/************F3*****************/


int8_t AF301[3];
int8_t AF302[1];
int8_t AF303[6];
int8_t AF304[3];
int8_t AF305[5];
int8_t AF306[5];
int8_t AF307[5];

int8_t AF803[5];
int8_t AF804[5];
int8_t AF805[5];
int8_t AF806[5];



int8_t one,two,three,four,five; 
void(*DispDigital_3BitSmg)(void);



void Number_Digital_Set5bit_twoAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_twoDecSelect(int8_t *ap ,uint8_t n);

void Number_Digital_Set5bit_ZeroAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_ZeroDecSelect(int8_t *ap ,uint8_t n);


//void RunDispDigital_Fun(void(*DisSmg)(void));
static void KEY1_ZERIO_UP_Fun(void);
static void KEY2_TRAE_DOWN_Fun(void);
static void KEY3_SWITCH_LEFT_Fun(void);
//static void KEY4_SET_ENTER_Fun(void);
static void KEY_SubMenuFun_Enter(void);
static void F1_01_xx_SelectCmd(void);



int8_t ATop(void);



void KeyValua_Init(void)
{
   key_t.currkeyset =0xff;
   key_t.currkeytrae = 0xff;
   key_t.currkeyswitch = 0xff;
   key_t.currkeyzero = 0xff;   
   key_t.keyTimes=0;
   *pfdata = NULL ;

}


uint8_t Scan_EnterKey(uint8_t keyvalue)
{

    static uint32_t key1,key2;

	   uint8_t cnt1,cnt2;

	 if(keyvalue == 0xf7){

      
	    if(key1<51)
	   	{
                
          key1++;


	   }
	   else
	   	 key1=0;

	   if(key2<101){
          key2++;

	   	}
	   else 
	   	key2 =0;

	 }

	 

	   if(key1==50){

          cnt1 = 0x02;

	   }

	   if(key2==100){

         cnt2 = 0x04;

	   }


	   
      return (cnt1|cnt2);





}
		

	
	

/***********************************************************************
 **********************************************************************/
void KEY_Function(uint8_t keydata)
{
             
    
      switch(keydata){

            
              case 0:

                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    key_t.keyzero++; 
              break;
              
              
              
              
              
              
               case 0xf4://KEY1-ZERO--up
                
                    Net_KeyLed();
                   
                    if(key_t.currkeyzero != key_t.keyzero){
                           key_t.currkeyzero = key_t.keyzero; 
                           if(cali_t.CaliControl_key==0)
                               KEY1_ZERIO_UP_Fun();
                            else
                                CALI_KEY1_UP_Fun();//CALI_KEY_UP_Fun();
                          
                    }
                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                     Valley_KeyLed();
                  
               break;
                   
               case 0xf6://KEY2 -TARE-donwn
                  
                    // Peak_KeyLed();
                     Mot_KeyLed();
                     if(key_t.currkeytrae != key_t.keytrae){
                           key_t.currkeytrae = key_t.keytrae;
                          if(cali_t.CaliControl_key==0)
                                KEY2_TRAE_DOWN_Fun();
                          else
                                CALI_KEY2_DOWN_Fun();
                     }
											
                   key_t.keyset++;
                 key_t.keyswitch++;
                
                 key_t.keyzero++; 
               break;

               case 0xf5: //KEY3 -SWITCH   <-
               
                    // CH1_KeyLed();
                     CH3_KeyLed();
                     key_t.keyTimes=1;
                     if(key_t.currkeyswitch !=key_t.keyswitch){
                            key_t.currkeyswitch = key_t.keyswitch;
                             if(cali_t.CaliControl_key==0)
                                   KEY3_SWITCH_LEFT_Fun();
                             else 
                                 CALI_KEY3_SWITCH_Fun();
                      }
                    
                  Valley_KeyLed();
                  key_t.keyset++;
                  key_t.keytrae++;
                  key_t.keyzero++; 
							 	      
               break;

                 case 0xf7://KEY4-SET/CAL-->Enter
                      CH2_KeyLed();
					  
                     if(run_t.EnterKey_flag ==1){
                     if(key_t.keyset !=key_t.currkeyset){
                        
                          key_t.keyset = key_t.currkeyset;
                        if(cali_t.CaliControl_key == 0){

                            KEY4_SET_ENTER_Fun();      
                        }
                        else{
                              
                             CAL_KEY4_ENTER_Fun() ;
                              
                        }
                       CH4_KeyLed();
                          
                     
                 
                    
                     
                 key_t.keyswitch++;
                 key_t.keytrae++;
                 key_t.keyzero++; 
                  }
              
								      
               break;
               
             
               default:     
			 key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    key_t.keyzero++; 
                    
               break;

               
            }
		}


}
/**********************************************************
 * 
 * Function Name:static void KEY_MainMenuFun(void)
 * Function : the first be pressed Enter key
 * 
********************************************************/  
 void	KEY4_SET_ENTER_Fun(void)
{
       if(menu_t.menuFirst == 0){
          menu_t.menuFirst++;
          menu_t.menuMain=1;
          menuTop= -1;
          mainitem_t.task_MainMenu=TheFirst_Menu;
          menu_t.FxMainMenu_key =0xA0;
          menu_t.FxSub_02_key=0;
          menu_t.FxSub_03_key=0;
          menu_t.mainTop= PushMainMenu(); 
       //   run_t.Fx_Menu_Function=1;
                                   
       }
       else{
         KEY_SubMenuFun_Enter();

       }
     
}
/**************************************************
 * 
 * Function Name:static void KEY_SubMenuFun_Enter(void)
 * Function :the second menu function 
 * 
***************************************************/           
static void KEY_SubMenuFun_Enter(void)
{
     
      switch(menu_t.mainTop){//switch(menu_t.menuId){
               
            case F1: //F1 - 01

            F1_MasterFunction_EnterKey();

            break;

            case F2:
            F2_MasterFunction_EnterKey();

            break;

            case F3:
            F3_MasterFunction_EnterKey();
            break;
            //Enter KY4 F7 Enter key
            case F7:
            F7_MasterFunction_EnterKey();
            break;
            //F8 -01-> Enter KEY 
            case F8:

            F8_MasterFunction_EnterKey();

            break; 

            case F9:
            F9_MasterFunction_EnterKey();

            break; 

     } 
 }

//the third menu function -F1

/*******************************************************
 * 
 * Function Name :static void KEY1_ZERIO_UP_Fun(void)
 * Function :KEY add value ++
 * 
********************************************************/
static void KEY1_ZERIO_UP_Fun(void)
{

      
    
	// pfdata=flash_t.flashData;
       
       pfdata =  SRAM_Data_Buffer;
	
	 switch(menu_t.FxMainMenu_key){

         case 0:

         break;

         case 0xA0:  //the first Menu 
             
               menu_t.mainTop= PushMainMenu(); 
              printf("mainTop_keyUp = %d\n",menu_t.mainTop);
                 
         break;

         case 0xB0: //the second Menu
            switch(menu_t.FxSub_02_key){

                case 0xf10:

                  menu_t.F1_SubMenuTop = PushSub_Menu(F1Mnumbers);
                  printf("f1sub_Top_keyu = %d\n",menu_t.F1_SubMenuTop);
                break;

                case 0xf20:
                      menu_t.F2_SubMenuTop= PushSub_Menu(F2Mnumbers);
                break;

                case 0xf30:
                     menu_t.F3_SubMenuTop= PushSub_Menu(F3Mnumbers);
                      printf("f1f3_b_keyd+ = %d\n",menu_t.F3_SubMenuTop);
                break;

                case 0xf70:
                  f7menu_t.F7_SubMenuTop = PushSub_Menu(F7Mnumbers);
                  printf("f7_02_TopKey = %d\n",f7menu_t.F7_SubMenuTop);
                break;

                 case 0xf80:
                  f8menu_t.F8_SubMenuTop = PushSub_Menu(F8Mnumbers);
                  printf("f7_keyDown = %d\n",f8menu_t.F8_SubMenuTop);
                break;

             

               }
         break;
     /**************************************************************/
      case 0xc0: //the third Menu
      switch(menu_t.FxSub_03_key){

      case 0xf10:

            F1_Add_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);            
        break;
     
      case 0xf20://F2-01->Control
                 
            F2_Add_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);
              
            
      break;
     
      case 0xf30://F3-01 ->Control F3-1.1 --KEY UP +
                  
            F3_Add_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);
                 
      break;

      case 0xf70:
                  
                 
      F7_Add_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);

                  
      break;
                    //F8 - 01 -> the thrid menu
      case 0xf80:

                 
                  F8_Add_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);

               

      break;

      case 0xf90:

      break;

      }//the  third F3 class --END
      
      /*********************************************************************************
      *
      *The theFourth class menu 
      *
      **********************************************************************************/   
      case 0xD0:
            switch(menu_t.FxSub_03_key){

            case 0xf3:
                  
                  F3_Add_TheFourthMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);
                  printf("F3_enter_04 = %d\n",menu_t.menuTitle_04);
            
            break;
            }
     
      break;

      default:
            
      break;


       }
  }
      
 
 

/*****************************************************
 * 
 * KEY DOWN 
 * 
 * 
 * 
******************************************************/
static void KEY2_TRAE_DOWN_Fun(void)
{
     
    switch(menu_t.FxMainMenu_key){
    
    case 0:

    break;

    case 0xA0 :
            menu_t.mainTop=PopMainMenu();
         printf("mainTop_keyDown = %d\n",menu_t.mainTop);
     break;
      
     case 0xB0:  //the second mentu
      switch(menu_t.FxSub_02_key){

                case 0xf10: //F1-01
                        menu_t.F1_SubMenuTop = PopSub_Menu(F1Mnumbers);
                        printf("f1sub_Top_keyd = %d\n",menu_t.F1_SubMenuTop);
                break;

                case 0xf20: //F2-01
                       menu_t.F2_SubMenuTop = PopSub_Menu(F2Mnumbers);
                break;

                case 0xf30: //F3-01
                     menu_t.F3_SubMenuTop = PopSub_Menu(F3Mnumbers);
                     printf("f3_keyDown = %d\n",menu_t.F3_SubMenuTop);
                break;

                case 0xf70:
                  f7menu_t.F7_SubMenuTop = PopSub_Menu(F7Mnumbers);
                  printf("f7_02_keyDown = %d\n",f7menu_t.F7_SubMenuTop);
                break;

                case 0xf80:
                  f8menu_t.F8_SubMenuTop = PopSub_Menu(F8Mnumbers);
                  printf("f8_keyDown = %d\n",f8menu_t.F8_SubMenuTop);
                break;

                case 0xf90:

                break;
                default:

                break;
      }
     break;   

     case 0xC0: //The input the first 
      switch( menu_t.FxSub_03_key){

                    
      case 0xf10:
             F1_Dec_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key) ;        
            
      break;
      
      case 0xf20:
            F2_Dec_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);
      break;
/***********************************F3-1.1 ---***************************************************
********************************************************************************************/
                  //F3-1.1
      case 0xf30: //KEY - DOWN -
            F3_Dec_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key)   ;        

      break;       
      //F7 -01 -display
      case 0xf70:
                   
            F7_Dec_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);
      break;

      case 0xf80:
                     
           F8_Dec_TheThirdMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);

      break;

      case 0xf90:

      break;

                   

                

       }
      break; //end 0xC0 (The TheThird_Menu)
     /*********the fourth menu ************/
     
     case 0xD0:


	  F3_Add_TheFourthMenu_KeyFunction(menu_t.menu_F1Sub_03_xx_key);

              
          
      break;
    }
}


/**************************************************************
 * 
 * Function Name :static void KEY3_SWITCH_LEFT_Fun(void)
 * Function :return last menu select numbers of bits 
 * Input Refer:No
 * Return Refer:NO
 * 
**************************************************************/
static void KEY3_SWITCH_LEFT_Fun(void)
{ 
     
     if(mainitem_t.task_MainMenu==TheFirst_Menu){
           run_t.Fx_Menu_Function=0;
           run_t.keySetValue = 1; //return normal display flag
           run_t.dispCmd=0;
           key_t.RunCmd_flag=0; //normal display flag 
           key_t.keyGetLong_Numbers=0;
           menu_t.menuFirst=0;
           run_t.EnterKey_flag=0;
           printf("key3_switch_TheFirst_Menu\n");
           return ;
     }
     if(mainitem_t.task_MainMenu==TheSecond_Menu){
          
          
          menu_t.menuF1Sub_first=0;
          menu_t.menuF2Sub_first=0;
          menu_t.menuF3Sub_first=0;
          f7menu_t.menuF7Sub_first=0;
          f8menu_t.menuF8Sub_first=0;
          f9menu_t.menuF9Sub_first=0;
           menu_t.menuMain=menu_t.menuId;
          mainitem_t.task_MainMenu=TheFirst_Menu;
          menu_t.FxMainMenu_key =0xA0;
         
          menu_t.mainTop= menu_t.menuId;//PushMainMenu(); 
          menu_t.FxSub_02_key=0;
          menu_t.FxSub_03_key=0;
          printf("key3_switch_TheSecond_Menu\n");
          return ;
      }

      //2BIT
      
       if(menu_t.DisplaySmgBit_Select_Numbers ==2){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >1){
                  menu_t.inputNumber_Select =0;
            }
            
              
       }
      
      //3BIT
     if(menu_t.DisplaySmgBit_Select_Numbers ==3){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >2){
                  menu_t.inputNumber_Select =0;
            }
            
              
       }
    //4IBIT
    if(menu_t.DisplaySmgBit_Select_Numbers ==4){
          menu_t.inputNumber_Select ++;
        if(menu_t.inputNumber_Select >3){
                  menu_t.inputNumber_Select =0;
          }
    }
    //5BIT
    if(menu_t.DisplaySmgBit_Select_Numbers ==5){
            menu_t.inputNumber_Select ++;
           if(menu_t.inputNumber_Select >4){
              menu_t.inputNumber_Select =0;
          }
        printf("key3_right= %d\n",menu_t.inputNumber_Select);
      }

}


/*******************************************************************
 * 
 * Function Name:static void F1_01_xx_SelectCmd(void)
 * Function : one to one F1SubMenu_Id  by F1 sub menu 
 * 
 * 
 * 
*******************************************************************/

/*************************************************************
*
*Display Smg 2 bit 1~9.0 increas 
*
*
**************************************************************/
void Number_Digital_2bit_DecSelect(int8_t *ap)
{
  
 
  if(menu_t.inputNumber_Select==0){
             menu_t.unit--;
            if(menu_t.unit < 0){
               menu_t.unit=9;
            }
            *ap =menu_t.unit;
            printf("s_1 = %d\n",menu_t.unit);
      }
      else if(menu_t.inputNumber_Select ==1){
            menu_t.decade--;
            if(menu_t.decade< 0){
             menu_t.decade=9;
            }
            *(ap+1)=menu_t.decade;
            printf("s_2 = %d\n",menu_t.decade);
      
      }    
}
void Number_Digital_2bit_AddSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
            menu_t.unit++ ;
            if(menu_t.unit >9){
               menu_t.unit=0;
            }
            *ap =menu_t.unit;
            printf("s_1 = %d\n",menu_t.unit);
      }
      else if(menu_t.inputNumber_Select ==1){
                  menu_t.decade++;
                  if(menu_t.decade >9){
                        menu_t.decade=0;
                  }
            *(ap+1)=menu_t.decade;
            printf("s_2 = %d\n",menu_t.decade);
       }
      
      
}




void RunDispDigital_Fun(void(*DisSmg)(void))
{
    DispDigital_3BitSmg =DisSmg;
    if(DispDigital_3BitSmg){

          DispDigital_3BitSmg();
    }

}
/*******************************************************
********************************************************/
void Number_Digital_4bit_DecSelect(int8_t *ap)
{
     
	if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){
               one=9;
            }
			*ap= one;
            printf("s_1 = %d\n",one);
      }
      else if(menu_t.inputNumber_Select==1){
            two--;
            if(two< 0){
               two=9;
            }
			*(ap+1) = two;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select==2){
            three--;
            if(three< 0){ 
               three=9;
            }
			*(ap+2) = three;
            printf("s_3 = %d\n",*(ap+2));
          
      }
      else if(menu_t.inputNumber_Select >=3){
             four--;
            if( four < 0){ 
               four=9;
            }
			*(ap+3) = four;
            printf("s_4 = %d\n", *(ap+3));
          
      }

}
/************************************************************
 * 
 * Function Name:static void Number_Digital_4bit_AddSelect(int8_t *ap)
 * Function :display smg of digitial bits 
 * 
 * 
*************************************************************/
void Number_Digital_4bit_AddSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9){
               one=0;
            }
			*ap = one;
      }
      else if(menu_t.inputNumber_Select==1){
                  two++;
                  if(two >9){
                        two=0;
                  }
				  *(ap+1) = two;
       }
      else if(menu_t.inputNumber_Select==2){
                  three++;  
                  if(three >9){
                      three=0;
                   }
				  *(ap+2)=three;
      } 
      else if(menu_t.inputNumber_Select >=3){
                  four++;  
                  if(four >9){
                      four=0;
                    }
				  *(ap+3) = four; 
      } 
      

}

void Number_Digital_3bit_PointerDecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){
               one=9;
            }
			*ap= one;
            printf("s_1 = %d\n",one);
      }
      else if(menu_t.inputNumber_Select==1){
            two--;
            if(two< 0){
               two=9;
            }
			*(ap+1) = two;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select >=2){
            three--;
            if(three< 0){ 
               three=9;
            }
			*(ap+2) = three;
            printf("s_3 = %d\n",*(ap+2));
          
      }
     

}
void Number_Digital_3bit_PointerAddSelect(int8_t *ap)
{
      
      if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9){
               one=0;
            }
			*ap = one;
      }
      else if(menu_t.inputNumber_Select==1){
                  two++;
                  if(two >9){
                        two=0;
                  }
			*(ap+1) = two;
       }
      else if(menu_t.inputNumber_Select >=2){
                  three++;  
                  if(three >9){
                      three=0;
                   }
			*(ap+2)=three;
      } 
    
      


}

void Number_Digital_Set5bit_twoDecSelect(int8_t *ap,uint8_t n)
{
     static  int8_t  i=2;
       i--;
      if(i ==0)i=n;
       *ap =i;
       
       menu_t.F34_KEY_VALUE = i;
        
}

void Number_Digital_Set5bit_ZeroAddSelect(int8_t *ap ,uint8_t n)
{
     static  uint8_t  i;
       i++;
       if(i>(n-1))i=0;
       *ap =i;
       menu_t.F34_KEY_VALUE = i;
      
        
        

}
void Number_Digital_Set5bit_ZeroDecSelect(int8_t *ap,uint8_t n)
{
   static  int8_t  i;
      if(i== -1) i= (n-1);
      i--;
      *ap =i;
      menu_t.F34_KEY_VALUE = i;
        
}





