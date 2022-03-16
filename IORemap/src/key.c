#include "key.h"
#include "menu.h"
#include <stdio.h>



#define MAZ_F1_SUBMENU_SIZE   13



KEY key_t;
run run_t;

uint32_t *pfdata;


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
int8_t AF3401[1];
int8_t AF3402[1];

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







int8_t Amenu_Top = -1;

uint8_t Amenu[MAZ_F1_SUBMENU_SIZE];

int8_t one,two,three,four,five; 
void(*DispDigital_3BitSmg)(void);

//static void Number_Digital_5bitPoint_AddSelect(int8_t *ap);
//static void Number_Digital_5bitPoint_DecSelect(int8_t *ap);

void Number_Digital_Set5bit_twoAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_twoDecSelect(int8_t *ap ,uint8_t n);

void Number_Digital_Set5bit_ZeroAddSelect(int8_t *ap ,uint8_t n);
void Number_Digital_Set5bit_ZeroDecSelect(int8_t *ap ,uint8_t n);

static void Number_Digital_Set5bit_AddSelect(int8_t *ap ,uint8_t n);
static void Number_Digital_Set5bit_DecSelect(int8_t *ap ,uint8_t n);





static void Number_Digital_3bit_DecSelect(void);
static void Number_Digital_3bit_AddSelect(void);



static void Number_Digital_5bit_DecSelect(int8_t *ap);
static void Number_Digital_5bit_AddSelect(int8_t *ap);

static void Number_Digital_F111_4bit_AddSelect(int8_t *ap);
static void Number_Digital_F111_4bit_DecSelect(int8_t *ap);

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
            
		if( menu_t.menuF1Sub_first== 0){ //"F1- 01"
             
                menu_t.menuFirst++;
			   menu_t.menuF1Sub_first++;
               run_t.Fx_Menu_Function=1;
               mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
               menu_t.menuTitle_02=1;
               menuFxSubTop=-1;
               menu_t.FxMainMenu_key =0xB0;
               menu_t.FxSub_02_key=0xf10;
               menu_t.F1_SubMenuTop= PushSub_Menu(F1Mnumbers);//subNumbers_TypedDef submenN;
               printf("f1top = %d\n",menu_t.F1_SubMenuTop);
             }
             else{ //F1-01 ->next -> g ,H9,t,n,nonE
                  
                  key_t.keyReturn_flag = key_t.keyReturn_flag^ 0x01;
                  printf("key_enter = %d\n",key_t.keyReturn_flag);
                  if(key_t.keyReturn_flag== 1){
                 
                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                        menu_t.menuTitle_02=1;
                        menu_t.menuTitle_03=submenu_F1;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf10;  //the third sub open
            
                        F1_01_xx_SelectCmd();
                     
                        menu_t.menu_F1Sub_03_xx_key=menu_t.F1SubMenu_Id;
                    }    
                  
                  else{  //return last menu and save data
                        
                        menu_t.menuId= F1;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                        
                        menu_t.F1_SubMenuTop=menu_t.F1SubMenu_Id;
											flash_t.flashSave_falg =1; //flash save data 
				
                     
                        printf("f1sub_top_return = %d\n",menu_t.F1_SubMenuTop);
                    }
		}


            break;
         
          case F2:
            if(menu_t.menuF2Sub_first==0){  
				menu_t.menuF2Sub_first++;
                        menuFxSubTop=-1;
                        mainitem_t.task_MainMenu=TheSecond_Menu;
                        menu_t.menuTitle_02=2;
				menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_02_key=0xf20;
	                  menu_t.F2_SubMenuTop= PushSub_Menu(F2Mnumbers);
                        printf("f201top = %d\n",menu_t.F2_SubMenuTop);
		}
            else{
                      
                     key_t.keyReturn_F2_flag = key_t.keyReturn_F2_flag ^ 0X01; 
                     if(key_t.keyReturn_F2_flag==1){

                      /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                        menu_t.menuTitle_02=2;
                        menu_t.menuTitle_03=submenu_F2;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf20;  //F2-01 -> the third sub open
            
                        //F2_02_xx_SelectCmd();
                     
                        menu_t.menu_F1Sub_03_xx_key=menu_t.F2SubMenu_Id;
                        
                     }
                     else{
                      
                        menu_t.menuId= F2;
                       

                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                      
                        menu_t.FxMainMenu_key =0xB0;
                         menu_t.menuTitle_02=2;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                      //  F2_01_xx_SelectCmd();
                        menu_t.F2_SubMenuTop=menu_t.F2SubMenu_Id;
                     
                        printf("f2sub_top_return = %d\n",menu_t.F2_SubMenuTop);
                     }

            }    
          break;
          
          case F3:
            if(menu_t.menuF3Sub_first==0){  //F3-1.
				menu_t.menuF3Sub_first++;
			       menuFxSubTop=-1;
                        mainitem_t.task_MainMenu=TheSecond_Menu;
                        menu_t.menuTitle_02=3;
				menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_02_key=0xf30;
				menu_t.F3_SubMenuTop= PushSub_Menu(F3Mnumbers);
                      
		} 
            else{
                    key_t.keyReturn_F3_flag++;
                    printf("F3_Keyreturn = %d\n",key_t.keyReturn_F3_flag);
                   // key_t.keyReturn_F3_flag = key_t.keyReturn_F3_flag ^ 0X01; 
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
                        
                     }
                     else if(key_t.keyReturn_F3_flag==2){ //the fourth menu
                        mainitem_t.task_MainMenu=TheFourth_Menu; //open the Fourth  menu
                       

                        if(menu_t.F3_SubMenuTop_02==F301){
                       
                            if(AF3401[0]==0){

                             menu_t.menu_F1Sub_03_xx_key= 1;
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
                                menu_t.menu_F1Sub_03_xx_key= AF3402[0]; 
                               }
                         }
                        //runKey fun
                        menu_t.FxMainMenu_key =0xD0; //the FOURTH menu open 
                        menu_t.FxSub_03_key=0xf30;  //F2-01 -> the third sub open
            
                       

                        printf("F3_enter_04 = %d\n",menu_t.menuTitle_04);
                        printf("F3_03_xx_key_04 = %d\n",menu_t.menu_F1Sub_03_xx_key);
                     }
                     else{
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
          break;
         //Enter KY4 F7 Enter key
         case F7:
            if(f7menu_t.menuF7Sub_first==0){  //F7- 01 
                  f7menu_t.menuF7Sub_first++;
                  menuFxSubTop=-1;
                  mainitem_t.task_MainMenu=TheSecond_Menu;

                  menu_t.menuTitle_02=7; //the second menu 
                  menu_t.FxMainMenu_key =0xB0;
                   menu_t.FxSub_02_key=0xf70;
                  f7menu_t.F7_SubMenuTop = PushSub_Menu(7);
                   printf("f7_theFirst_enkey = %d\n", menu_t.menuTitle_02);
		} 
            else{ //F7-01-> 01
                  key_t.f7keyReturn_flag = key_t.f7keyReturn_flag^ 0x01;
                  printf("f7keyenter = %d\n",key_t.f7keyReturn_flag);
                  if(key_t.f7keyReturn_flag== 1){
                 
                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                       
                      //  menu_t.FxSub_02_key=7;
                         menu_t.menuTitle_03=submenu_F7;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf70;  //the third sub open
            
                       //f7menu_t.F7_03_subMenuTop=f7menu_t.F7SubMenu_Id;
                        menu_t.menu_F1Sub_03_xx_key=f7menu_t.F7SubMenu_Id;
                        printf("f7_03_Top = %d\n",f7menu_t.F7_03_subMenuTop);
                  }    
                  else{
                        
                        menu_t.menuId= F7;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0; 
                       menu_t.FxSub_02_key=0xf70; 
                        menu_t.menuTitle_03=0;
				menu_t.menuTitle_02=7; 
                        f7menu_t.F7_SubMenuTop=f7menu_t.F7SubMenu_Id;
                     
                        printf("f7_04_enkey = %d\n",f7menu_t.F7_03_subMenuTop);
                    }

            } 
           break;
          //F8 -01-> Enter KEY 
          case F8:
          
               if(f8menu_t.menuF8Sub_first==0){  //F8- 01 
                  f8menu_t.menuF8Sub_first++;
                  menuFxSubTop=-1;
                  mainitem_t.task_MainMenu=TheSecond_Menu;

                  menu_t.menuTitle_02=8; //the second menu 
                  menu_t.FxMainMenu_key =0xB0;
                   menu_t.FxSub_02_key=0xf80;
                  f8menu_t.F8_SubMenuTop = PushSub_Menu(F8Mnumbers);
                  printf("f8_theFirst_enkey = %d\n",menu_t.menuTitle_02);
		} 
            else{ //F801-> 01
                  key_t.f8keyReturn_flag = key_t.f8keyReturn_flag^ 0x01;
                  printf("f8keyenter = %d\n",key_t.f8keyReturn_flag);
                  if(key_t.f8keyReturn_flag== 1){
                 
                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                       
                         menu_t.menuTitle_03=submenu_F8;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf80;  //the third sub open
            
                       //f7menu_t.F7_03_subMenuTop=f7menu_t.F7SubMenu_Id;
                        menu_t.menu_F1Sub_03_xx_key=f8menu_t.F8SubMenu_Id;
                        printf("f8_03_Top = %d\n",f8menu_t.F8_03_subMenuTop);
                  }    
                  else{
                        
                        menu_t.menuId= F8;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0; 
                       menu_t.FxSub_02_key=0xf80; 
                        menu_t.menuTitle_03=0;
				menu_t.menuTitle_02=8; 
                        f8menu_t.F8_SubMenuTop=f8menu_t.F8SubMenu_Id;
                     
                        printf("f8_04_enkey = %d\n",f8menu_t.F8_03_subMenuTop);
                    }

            }          

          break; 
          
          case F9:
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

      
     static uint8_t f1r01,f1r02,f1r03,f1r04,f1r05,f2r,f3r,f7r,f8r,f9r,f1temp;
	
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

      case 0xc0: //the third Menu
        switch( menu_t.FxSub_03_key){

            case 0xf10:
            switch(menu_t.menu_F1Sub_03_xx_key){

                  case 0x00: //F1-01-01  -8bit flash_t.pointer = 
                        if(f1r01 == 0) {
                        f1r01++;
                        Flash_Read();
                          f1temp= ( flash_t.flashData[0]  & 0xff000000) >> 24;
                        
                          menu_t.F1_Sub01_Top=   f1temp;
                           menuFxSub_03_Top= f1temp;
                          printf("f1sub_00_03_flash = %d\n",menu_t.F1_Sub01_Top);
                        }
                        if(f1r01==1){ 
                        f1r01++;
                        }
                        else{
                              menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                        }
                        Flash_Data_Buffer[0] = menu_t.F1_Sub01_Top <<    24 ; //SRAM_Data_Buffer[0]= menu_t.F1_Sub01_Top
                                    
                                    
                        printf("f1sub_01_n_Top = %d\n",menu_t.F1_Sub01_Top);
                        key_t.keyReturn_flag=1;
                  break;

                  case 0x01: //F1-02-01 -8bit

                        if(f1r02== 0) {
                        f1r02++;
                        Flash_Read();

                        menu_t.unit=(flash_t.flashData[0] & 0xFF) >> 0; //form flas read data 

                        menu_t.decade=(flash_t.flashData[0]  & 0x0000ff00) >> 8;

                        menu_t.hundred=(flash_t.flashData[0]  & 0x00ff0000) >> 16; 
                        
                         printf("f1sub_01_03_Top = %d\n",menu_t.unit);
                        }

                        if(f1r02==1){
                              f1r02++;

                        }
                        else{

                        RunDispDigital_Fun(Number_Digital_3bit_AddSelect);

                        }
                        menu_t. F1_Sub02_unit= menu_t.unit;
                        menu_t.F1_Sub02_decade=menu_t.decade;
                        menu_t.F1_Sub02_hundred =menu_t.hundred;
                             
                  
                       // *pfdata 	= 0x1 ; //(menu_t.unit & 0xff)<<0 ; //save flash data 

                       // *pfdata  = 0x02 <<8 ; //(menu_t.decade & 0xff)<<8;

                        //*pfdata   = 0x3 << 16;//(menu_t.hundred  & 0xff)<<16; //MSB  
                         *pfdata = (SpecDisplay_Number(menu_t.hundred )<< 16)  | (SpecDisplay_Number(menu_t.decade)<<8) |SpecDisplay_Number(menu_t.unit);

                        printf("f1sub_01_03_n_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;
                  break;

                  case 0x02: //F1-03-01  
                        menu_t.unit=(SRAM_Data_Buffer[1] & 0x00ff0000) >> 16; //form flas read data 

                        menu_t.decade=(SRAM_Data_Buffer[1] & 0x0000ff00) >> 8;

                        menu_t.hundred=(SRAM_Data_Buffer[1] & 0x000000ff) >> 0;


                        RunDispDigital_Fun(Number_Digital_3bit_AddSelect);
                        menu_t. F1_Sub03_unit= menu_t.unit;
                        menu_t.F1_Sub03_decade=menu_t.decade;
                        menu_t.F1_Sub03_hundred =menu_t.hundred;
                        key_t.keyReturn_flag=1;

                        menu_t.unit =0x01;
                        menu_t.decade =0x02;
                        menu_t.hundred =0x03;

                        SRAM_Data_Buffer[1]   = menu_t.unit << 16 ; //save flash data 

                        SRAM_Data_Buffer[1] = menu_t.decade <<8;

                        SRAM_Data_Buffer[1] = menu_t.hundred <<0;


                  break;

                  case 0x03: //F1-04-01

                        AF104[0]=(SRAM_Data_Buffer[2] & 0xFF000000) >> 24; //form flas read data 

                        AF104[1]=(SRAM_Data_Buffer[2] & 0x0000ff00) >> 16;

                        AF104[2]=(SRAM_Data_Buffer[2] & 0x000000ff) >> 8;

                        AF104[3]=(SRAM_Data_Buffer[2] & 0x000000ff) >> 0;


                        Number_Digital_4bit_AddSelect(AF104);

                        SRAM_Data_Buffer[2] = AF104[0] & 0XFF << 24;

                        SRAM_Data_Buffer[2] = AF104[1] & 0XFF <<16;

                        SRAM_Data_Buffer[2] = AF104[2] & 0XFF << 8;

                        SRAM_Data_Buffer[2] = AF104[3] & 0XFF <<0;

                        key_t.keyReturn_flag=1;
                  break;

                                case 0x04://F1-05-01

									
								  AF105[0]=(SRAM_Data_Buffer[3] & 0xFF000000) >> 24; //form flas read data 
								   
								  AF105[1]=(SRAM_Data_Buffer[3] & 0x0000ff00) >> 16;

								
                                   Number_Digital_2bit_AddSelect(AF105);

                                   	SRAM_Data_Buffer[3] = AF105[0] & 0XFF << 24;

									SRAM_Data_Buffer[3] = AF105[1] & 0XFF <<16;
								   
                                   printf("F1_01_05_AddKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
                                 key_t.keyReturn_flag=1;
                              break;

                              case 0x05://F1-06-01


									AF106[0]=(SRAM_Data_Buffer[3] & 0x000000FF) >> 0;

							        AF106[1]=(SRAM_Data_Buffer[4] & 0xFF000000) >> 24; //form flas read data 

									AF106[2]=(SRAM_Data_Buffer[4] & 0x0000ff00) >> 16;

									AF106[3]=(SRAM_Data_Buffer[4] & 0x000000ff) >> 8;

									AF106[4]=(SRAM_Data_Buffer[4] & 0x000000ff) >> 0;
									
                                    Number_Digital_5bit_AddSelect(AF106);

									SRAM_Data_Buffer[3] = AF106[0] & 0XFF << 0;

									SRAM_Data_Buffer[4] = AF106[0] & 0XFF << 24;

									SRAM_Data_Buffer[4] = AF106[1] & 0XFF <<16;

									SRAM_Data_Buffer[4] = AF106[2] & 0XFF << 8;

									SRAM_Data_Buffer[4] = AF106[3] & 0XFF <<0;
							  


									
                                      key_t.keyReturn_flag=1;
                              break;

                               case 0x06: //F1-07-01

							   		AF107[0]=(SRAM_Data_Buffer[5] & 0xFF000000) >> 24;

							        AF107[1]=(SRAM_Data_Buffer[5] & 0x00FF0000) >> 16; //form flas read data 

									AF107[2]=(SRAM_Data_Buffer[5] & 0x0000ff00) >> 8;

									AF107[3]=(SRAM_Data_Buffer[5] & 0x000000ff) >> 0;

									AF107[4]=(SRAM_Data_Buffer[6] & 0xFF000000) >> 24;
									
                                     Number_Digital_5bit_AddSelect(AF107);

									

									SRAM_Data_Buffer[5] = AF107[0] & 0XFF << 24;

									SRAM_Data_Buffer[5] = AF107[1] & 0XFF <<16;

									SRAM_Data_Buffer[5] = AF107[2] & 0XFF << 8;

									SRAM_Data_Buffer[5] = AF107[3] & 0XFF <<0;

									SRAM_Data_Buffer[6] = AF107[0] & 0XFF << 24;
									
                                    key_t.keyReturn_flag=1;
                              break;

                               case 0x07: //F1-08-01
                                   AF108[0]=(SRAM_Data_Buffer[6] & 0x00FF0000) >> 16;

							       AF108[1]=(SRAM_Data_Buffer[6] & 0x0000FF00) >> 8; //form flas read data 
                               
                                   Number_Digital_2bit_AddSelect(AF108);
										
									 SRAM_Data_Buffer[6] = AF108[1] & 0XFF <<16;
									 
									SRAM_Data_Buffer[6] = AF108[2] & 0XFF << 8;
								   
                                     key_t.keyReturn_flag=1;
                              break;

                              case 0x08: //F1-09-01

							  		AF109[0]=(SRAM_Data_Buffer[7] & 0xFF000000) >> 24;

							        AF109[1]=(SRAM_Data_Buffer[7] & 0x00FF0000) >> 16; //form flas read data 

									AF109[2]=(SRAM_Data_Buffer[7] & 0x0000ff00) >> 8;

									AF109[3]=(SRAM_Data_Buffer[7] & 0x000000ff) >> 0;

									AF109[4]=(SRAM_Data_Buffer[8] & 0xFF000000) >> 24;
									
                                    Number_Digital_4bit_AddSelect(AF109);

									

									SRAM_Data_Buffer[7] = AF109[0] & 0XFF << 24;

									SRAM_Data_Buffer[7] = AF109[1] & 0XFF <<16;

									SRAM_Data_Buffer[7] = AF109[2] & 0XFF << 8;

									SRAM_Data_Buffer[7] = AF109[3] & 0XFF <<0;

									SRAM_Data_Buffer[8] = AF109[4] & 0XFF << 24;

									
                              break;

                              case 0x09: //F1-10-01
                              		AF110[0]=(SRAM_Data_Buffer[9] & 0xFF000000) >> 24;

							        AF110[1]=(SRAM_Data_Buffer[9] & 0x00FF0000) >> 16; //form flas read data 

									AF110[2]=(SRAM_Data_Buffer[9] & 0x0000ff00) >> 8;

									AF110[3]=(SRAM_Data_Buffer[9] & 0x000000ff) >> 0;
									
                                     Number_Digital_5bit_AddSelect(AF110);

									 SRAM_Data_Buffer[9] = AF110[0] & 0XFF << 24;

									SRAM_Data_Buffer[9] = AF110[1] & 0XFF <<16;

									SRAM_Data_Buffer[9] = AF110[2] & 0XFF << 8;

									SRAM_Data_Buffer[9] = AF110[3] & 0XFF <<0;


									 
                              break;

                               case 0x0A://F1-11-01 ->display 4 bit

								    AF111[0]=(SRAM_Data_Buffer[10] & 0xFF000000) >> 24;

							        Number_Digital_F111_4bit_AddSelect(AF111);
							   
                                    SRAM_Data_Buffer[10] = AF111[0] & 0XFF << 24;
                              break;

                               case 0x0B://F1-12-01

							         
									AF112[0]=(SRAM_Data_Buffer[10] & 0x00FF0000) >> 16; //form flas read data 
									 
									AF112[1]=(SRAM_Data_Buffer[10] & 0x0000ff00) >> 8;
                                     
                                     Number_Digital_2bit_AddSelect(AF112);

									 
								  SRAM_Data_Buffer[10] = AF112[0] & 0XFF <<16;
								  
								  SRAM_Data_Buffer[10] = AF112[1] & 0XFF << 8;

									 
                              break;

                               case 0x0C://F1-13-01

							   		AF113[0]=(SRAM_Data_Buffer[11] & 0xFF000000) >> 24;

							        AF113[1]=(SRAM_Data_Buffer[11] & 0x00FF0000) >> 16; //form flas read data 
							        
                                    Number_Digital_2bit_AddSelect(AF113);

									SRAM_Data_Buffer[11] = AF113[0] & 0XFF << 24;

									SRAM_Data_Buffer[11] = AF113[1] & 0XFF <<16;
                              break;

                          }
                    break;

                    case 0xf20://F2-01->Control
                        switch(menu_t.menu_F1Sub_03_xx_key){

                           case F201:
                              Number_Digital_Set5bit_AddSelect(AF201,3);
                           break;

                           case F202:
                              Number_Digital_5bit_AddSelect(AF202);
                           break;

                           case F203:
                               Number_Digital_5bit_AddSelect(AF203);
                           break;

                           case F204:
                               Number_Digital_Set5bit_AddSelect(AF204,3);
                           break;

                           case F205:
                               Number_Digital_5bit_AddSelect(AF205);
                           break;

                           case F206:
                               Number_Digital_5bit_AddSelect(AF206);
                           break;


                        }
                    break;

                    case 0xf30://F3-01 ->Control F3-1.1 --KEY UP +
                        switch(menu_t.menu_F1Sub_03_xx_key){
                        case F301:
                              AF3401[0]= F3_04_PushSub_Item(7);    // Number_Digital_Set5bit_AddSelect(AF3401,7);
                              break;

                        case F302:
                               AF3402[0]= F3_04_PushSub_Item(7);    // Number_Digital_Set5bit_twoAddSelect(AF3402,7);
                              break;
                        

                        }
                        printf("f1f30_c_keyd+ = %d\n",menu_t.menu_F1Sub_03_xx_key);
                    break;

                  

                    case 0xf70:
                          switch(menu_t.menu_F1Sub_03_xx_key){
                              case 0x00: //F1-01-01
                                  f7menu_t.F7_03_00_Id=  PushSub_03_Menu(2);
                                  printf("f7_03_Upkey = %d\n",f7menu_t.F7_03_01_Id);
                                   key_t.f7keyReturn_flag=1;
                              break;

                              case 0x01: //F1-02-01
                                    f7menu_t.F7_03_01_Id=  PushSub_03_Menu(8);
                                
                                    printf("f7_03_upkey = %d\n",menu_t.F1_Sub02_Top);
                                   key_t.f7keyReturn_flag=1;
                              break;

                               case 0x02: //F1-03-01
                                   RunDispDigital_Fun(Number_Digital_3bit_AddSelect);
                                   f7menu_t.unit= menu_t.unit;
                                   f7menu_t.decade=menu_t.decade;
                                   f7menu_t.hundred =menu_t.hundred;
                                   key_t.f7keyReturn_flag=1;
                                   
                              break;

                               case 0x03: //F1-04-01
                                    f7menu_t.F7_03_03_Id=PushSub_03_Menu(7);
                                     key_t.f7keyReturn_flag=1;
                              break;

                                case 0x04://F1-05-01
                                    RunDispDigital_Fun(Number_Digital_3bit_AddSelect);
                                   f7menu_t.unit= menu_t.unit;
                                   f7menu_t.decade=menu_t.decade;
                                   f7menu_t.hundred =menu_t.hundred;
                                   key_t.f7keyReturn_flag=1;
                                 
                              break;

                              case 0x05://F1-06-01
                                   f7menu_t.F7_03_05_Id=PushSub_03_Menu(2);
                                    key_t.f7keyReturn_flag=1;
                              break;

                               case 0x06: //F1-07-01
                                    
                                   key_t.f7keyReturn_flag=1;
                              break;

                              
                         }
                    break;
                    //F8 - 01 -> the thrid menu
                    case 0xf80:

                         switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0:
                                    f8menu_t.F8_03_01_Id=  PushSub_03_Menu(3);
                              break;

                              case 1:
                                    f8menu_t.F8_03_02_Id =  PushSub_03_Menu(6);
                              break;

                              case 2:
                                      Number_Digital_5bitPoint_AddSelect(AF803);
                                      f8menu_t.unit =AF803[0];
                                      f8menu_t.decade = AF803[1];
                                      f8menu_t.hundred = AF803[2];
                                      f8menu_t.onethousand= AF803[3];
                                      f8menu_t.tenthousand= AF803[4];
                              break;

                              case 3:
                                    Number_Digital_5bitPoint_AddSelect(AF804);
                                      f8menu_t.unit =AF804[0];
                                      f8menu_t.decade = AF804[1];
                                      f8menu_t.hundred = AF804[2];
                                      f8menu_t.onethousand= AF804[3];
                                      f8menu_t.tenthousand= AF804[4];
                                     

                              break;

                               case 4:
                                 Number_Digital_5bitPoint_AddSelect(AF805);
                                      f8menu_t.unit =AF805[0];
                                      f8menu_t.decade = AF805[1];
                                      f8menu_t.hundred = AF805[2];
                                      f8menu_t.onethousand= AF805[3];
                                      f8menu_t.tenthousand= AF805[4];

                              break;

                              case 5:
                                      Number_Digital_5bitPoint_AddSelect(AF806);
                                      f8menu_t.unit =AF806[0];
                                      f8menu_t.decade = AF806[1];
                                      f8menu_t.hundred = AF806[2];
                                      f8menu_t.onethousand= AF806[3];
                                      f8menu_t.tenthousand= AF806[4];

                              break;

                              case 6:
                                    f8menu_t.F8_03_07_Id= PushSub_03_Menu(3);
                              break;

                               case 7:
                                    f8menu_t.F8_03_08_Id= PushSub_03_Menu(3);
                              break;

                        }

                    break;

                    case 0xf90:

                    break;


                }
                 
         break;

         case 0xD0:
              switch(menu_t.menu_F1Sub_03_xx_key){

                  case F3401:
                      AF301[0]= F3_05_PushSub_Item(3); //Number_Digital_Set5bit_ZeroAddSelect(AF301,3);
                  break;

                  case F3402:
                       AF302[0] = F3_05_PushSub_Item(1);//Number_Digital_Set5bit_ZeroAddSelect(AF302,1);
                  break;

                  case F3403:
                       AF303[0] = F3_05_PushSub_Item(6);  //Number_Digital_Set5bit_ZeroAddSelect(AF303,6);
                  break;

                  case F3404:
                       AF304[F305_tmp4] = F3_05_PushSub_Item(3);  //Number_Digital_Set5bit_ZeroAddSelect(AF304,3);
                       F305_tmp4++;
                       if(F305_tmp4>2)F305_tmp4=0;
                  break;

                  case F3405:
                      AF305[F305_tmp5] = F3_05_PushSub_Item(5);  //Number_Digital_Set5bit_ZeroAddSelect(AF305,5);
                      F305_tmp5++;
                      if(F305_tmp5>4)F305_tmp5=0;
                  break;

                  case F3406:
                      AF306[F305_tmp6] = F3_05_PushSub_Item(5);  //Number_Digital_Set5bit_ZeroAddSelect(AF306,5);
                      F305_tmp6++;
                      if(F305_tmp6>4)F305_tmp6=0;
                  break;

                  case F3407:
                
                     AF307[F305_tmp7] = F3_05_PushSub_Item(5);//   Number_Digital_Set5bit_ZeroAddSelect(AF307,5);
                     F305_tmp7++;
                     if(F305_tmp7>4)F305_tmp7=0;
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
                          switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0x00:
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                                  printf("f1sub_01_n_Top- = %d\n",menu_t.F1_Sub01_Top);
                                    key_t.keyReturn_flag=1;
                              break;

                              case 0x01:
                             
                                  RunDispDigital_Fun(Number_Digital_3bit_DecSelect);
                                  menu_t. F1_Sub02_unit= menu_t.unit;
                                  menu_t.F1_Sub02_decade=menu_t.decade;
                                  menu_t.F1_Sub02_hundred =menu_t.hundred;
                              
                              key_t.keyReturn_flag=1;
                              break;

                               case 0x02:
                               	 RunDispDigital_Fun(Number_Digital_3bit_DecSelect);
                                  menu_t. F1_Sub03_unit= menu_t.unit;
                                  menu_t.F1_Sub03_decade=menu_t.decade;
                                  menu_t.F1_Sub03_hundred =menu_t.hundred;
                              
                              key_t.keyReturn_flag=1;
                              break;

                               case 0x03: //F1-04-01
                                    Number_Digital_4bit_DecSelect(AF104);
                                    key_t.keyReturn_flag=1;
                              break;

                                case 0x04: //F1-05-01
                                  Number_Digital_2bit_DecSelect(AF105);
                                  printf("F1_01_05_DecKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
                                  key_t.keyReturn_flag=1;
                              break;

                              case 0x05: //F1-06-01 --5bit
                                    Number_Digital_5bit_DecSelect(AF106);
                                    key_t.keyReturn_flag=1;
                              break;

                               case 0x06: //F1-07-01
                                   Number_Digital_5bit_DecSelect(AF107);
                                   key_t.keyReturn_flag=1;
                              break;

                               case 0x07://F1-08-01
                                    Number_Digital_2bit_DecSelect(AF108);
                                    key_t.keyReturn_flag=1;
                              break;

                              case 0x08://F1-09-01
                                 Number_Digital_4bit_DecSelect(AF109);
                                 key_t.keyReturn_flag=1;
                              break;

                              case 0x09://F1-10-01
                                   Number_Digital_5bit_DecSelect(AF110);
                                   key_t.keyReturn_flag=1;
                              break;

                               case 0x0A://F1-11-01
                                     Number_Digital_F111_4bit_DecSelect(AF111);
                                     key_t.keyReturn_flag=1;
                              break;

                               case 0x0B: //F1-12-01
                                       Number_Digital_2bit_DecSelect(AF112);
                                       key_t.keyReturn_flag=1;
                              break;

                               case 0x0C:
                                   Number_Digital_2bit_DecSelect(AF113);
                                   key_t.keyReturn_flag=1;
                              break;

                          }
                    break;

                    case 0xf20:
                        switch(menu_t.menu_F1Sub_03_xx_key){

                             case F201:
                              Number_Digital_Set5bit_DecSelect(AF201,3);
                           break;

                           case F202:
                              Number_Digital_5bit_DecSelect(AF202);
                           break;

                           case F203:
                               Number_Digital_5bit_DecSelect(AF203);
                           break;

                           case F204:
                               Number_Digital_Set5bit_DecSelect(AF204,3);
                           break;

                           case F205:
                               Number_Digital_5bit_DecSelect(AF205);
                           break;

                           case F206:
                               Number_Digital_5bit_DecSelect(AF206);
                           break;


                        }

                    break;
                  //F3-1.1
                    case 0xf30: //KEY - DOWN -
                        switch(menu_t.menu_F1Sub_03_xx_key){
                        case F301:
                            
                          AF3401[0]=F3_04_PopSub_Item(7);//Number_Digital_Set5bit_DecSelect(AF3401,7);
                              
                           break;

                        case F302:
                           AF3402[0]= F3_04_PopSub_Item(7);//Number_Digital_Set5bit_twoDecSelect(AF3402,7);
                         break;

                         }
                        printf("F3f30_DecKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
                    break;

               
                   //F7 -01 -display
                    case 0xf70:
                    switch(menu_t.menu_F1Sub_03_xx_key){
                              case 0x00: //F1-01-01
                                  f7menu_t.F7_03_00_Id=  PopSub_03_Menu(2);
                                  printf("f7_03_Upkey = %d\n",f7menu_t.F7_03_01_Id);
                                   key_t.f7keyReturn_flag=1;
                              break;

                              case 0x01: //F1-02-01
                                    f7menu_t.F7_03_01_Id=  PopSub_03_Menu(8);
                                
                                    printf("f7_03_upkey = %d\n",menu_t.F1_Sub02_Top);
                                   key_t.f7keyReturn_flag=1;
                              break;

                               case 0x02: //F1-03-01
                                   RunDispDigital_Fun(Number_Digital_3bit_DecSelect);
                                   f7menu_t.unit= menu_t.unit;
                                   f7menu_t.decade=menu_t.decade;
                                   f7menu_t.hundred =menu_t.hundred;
                                   key_t.f7keyReturn_flag=1;
                                   
                              break;

                               case 0x03: //F1-04-01
                                    f7menu_t.F7_03_03_Id=PushSub_03_Menu(7);
                                     key_t.f7keyReturn_flag=1;
                              break;

                                case 0x04://F1-05-01
                                    RunDispDigital_Fun(Number_Digital_3bit_DecSelect);
                                   f7menu_t.unit= menu_t.unit;
                                   f7menu_t.decade=menu_t.decade;
                                   f7menu_t.hundred =menu_t.hundred;
                                   key_t.f7keyReturn_flag=1;
                                 
                              break;

                              case 0x05://F1-06-01
                                   f7menu_t.F7_03_05_Id=PopSub_03_Menu(2);
                                    key_t.f7keyReturn_flag=1;
                              break;

                               case 0x06: //F1-07-01
                                    
                                   key_t.f7keyReturn_flag=1;
                              break;

                             
                         }

                    break;

                    case 0xf80:
                      switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0:
                                    f8menu_t.F8_03_01_Id=  PopSub_03_Menu(3);
                              break;

                              case 1:
                                    f8menu_t.F8_03_02_Id =  PopSub_03_Menu(6);
                              break;

                              case 2:
                                      Number_Digital_5bitPoint_DecSelect(AF803);
                                      f8menu_t.unit =AF803[0];
                                      f8menu_t.decade = AF803[1];
                                      f8menu_t.hundred = AF803[2];
                                      f8menu_t.onethousand= AF803[3];
                                      f8menu_t.tenthousand= AF803[4];
                              break;

                              case 3:
                                    Number_Digital_5bitPoint_DecSelect(AF804);
                                      f8menu_t.unit =AF804[0];
                                      f8menu_t.decade = AF804[1];
                                      f8menu_t.hundred = AF804[2];
                                      f8menu_t.onethousand= AF804[3];
                                      f8menu_t.tenthousand= AF804[4];
                                     

                              break;

                               case 4:
                                 Number_Digital_5bitPoint_DecSelect(AF805);
                                      f8menu_t.unit =AF805[0];
                                      f8menu_t.decade = AF805[1];
                                      f8menu_t.hundred = AF805[2];
                                      f8menu_t.onethousand= AF805[3];
                                      f8menu_t.tenthousand= AF805[4];

                              break;

                              case 5:
                                      Number_Digital_5bitPoint_DecSelect(AF806);
                                      f8menu_t.unit =AF806[0];
                                      f8menu_t.decade = AF806[1];
                                      f8menu_t.hundred = AF806[2];
                                      f8menu_t.onethousand= AF806[3];
                                      f8menu_t.tenthousand= AF806[4];

                              break;

                              case 6:
                                    f8menu_t.F8_03_07_Id= PopSub_03_Menu(3);
                              break;

                               case 7:
                                    f8menu_t.F8_03_08_Id= PopSub_03_Menu(3);
                              break;

                        }


                    break;

                    case 0xf90:

                    break;

                   

                }

     break; 

     /*********the fourth menu ************/

     case 0xD0:

         switch(menu_t.menu_F1Sub_03_xx_key){

                  case F3401:
                       AF301[0]= F3_05_PopSub_Item(3);  //Number_Digital_Set5bit_ZeroDecSelect(AF301,3);
                  break;

                  case F3402:
                       AF302[0]= F3_05_PopSub_Item(1);  //Number_Digital_Set5bit_ZeroDecSelect(AF302,1);
                  break;

                  case F3403:
                       AF303[0]= F3_05_PopSub_Item(6);   //Number_Digital_Set5bit_ZeroDecSelect(AF303,6);
                  break;

                  case F3404:
                      AF304[F305_tmp4]= F3_05_PopSub_Item(3); 
                       F305_tmp4++;
                       if(F305_tmp4>2)F305_tmp4=0;   //Number_Digital_Set5bit_ZeroDecSelect(AF304,3);
                  break;

                  case F3405:
                       AF305[F305_tmp5]= F3_05_PopSub_Item(5); Number_Digital_Set5bit_ZeroDecSelect(AF305,5);
                         F305_tmp5++;
                      if(F305_tmp5>4)F305_tmp5=0;
                  break;

                  case F3406:
                       AF306[F305_tmp6]= F3_05_PopSub_Item(5);   //Number_Digital_Set5bit_ZeroDecSelect(AF306,5);
                        F305_tmp6++;
                      if(F305_tmp6>4)F305_tmp6=0;
                  break;

                  case F3407:
                          AF307[F305_tmp7]= F3_05_PopSub_Item(5);//Number_Digital_Set5bit_ZeroDecSelect(AF307,5);
                        F305_tmp7++;
                     if(F305_tmp7>4)F305_tmp7=0;
                  break;

              }
          
        
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
static void F1_01_xx_SelectCmd(void)
{
     switch(menu_t.F1SubMenu_Id){

      case F101:
            menu_t.F1_Sub01_Top=menu_t.F1SubMenu_Id;
      break;

      case F102:
            menu_t.F1_Sub02_Top=menu_t.F1SubMenu_Id;
      break;

      case F103:
            menu_t.F1_Sub03_Top=menu_t.F1SubMenu_Id;
      break;

      case F104:
            menu_t.F1_Sub04_Top=menu_t.F1SubMenu_Id;
      break;

      case F105:
            menu_t.F1_Sub05_Top=menu_t.F1SubMenu_Id;
      break;

      case F106:
            menu_t.F1_Sub06_Top=menu_t.F1SubMenu_Id;
      break;

      case F107:
            menu_t.F1_Sub07_Top=menu_t.F1SubMenu_Id;
      break;

      case F108:
            menu_t.F1_Sub08_Top=menu_t.F1SubMenu_Id;
      break;

      case F109:
            menu_t.F1_Sub09_Top=menu_t.F1SubMenu_Id;
      break;

      case F110:
            menu_t.F1_Sub10_Top=menu_t.F1SubMenu_Id;
      break;

      case F111:
            menu_t.F1_Sub11_Top=menu_t.F1SubMenu_Id;
      break;

      case F112:
            menu_t.F1_Sub12_Top=menu_t.F1SubMenu_Id;
      break;

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

void Number_Digital_3bit_AddSelect(void)
{
        if(menu_t.inputNumber_Select==0){
            menu_t.unit++ ;
            if(menu_t.unit >9){
               menu_t.unit=0;
            }
           
        }
        else if(menu_t.inputNumber_Select==1){
                  menu_t.decade++;
                  if(menu_t.decade >9){
                        menu_t.decade=0;
                  }
                   
       }
      else if(menu_t.inputNumber_Select ==2){
                  menu_t.hundred++;  
                  if(menu_t.hundred >9){
                  menu_t.hundred=0;
            }
           
      }  
}
void Number_Digital_3bit_DecSelect(void)
{
      if(menu_t.inputNumber_Select==0){
             menu_t.unit--;
            if(menu_t.unit < 0){
               menu_t.unit=9;
            }
            printf("s_1 = %d\n",menu_t.unit);
      }
      else if(menu_t.inputNumber_Select==1){
            menu_t.decade--;
            if(menu_t.decade< 0){
             menu_t.decade=9;
            }
            
            printf("s_2 = %d\n",menu_t.decade);
      
      }
      else if(menu_t.inputNumber_Select ==2){
            menu_t.hundred--;
            if(menu_t.hundred < 0){ 
              menu_t.hundred=9;
            }
         
            printf("s_3 = %d\n",menu_t.hundred);
          
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

static void Number_Digital_5bit_DecSelect(int8_t *ap)
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
      else if(menu_t.inputNumber_Select==3){
             four--;
            if( four < 0){ 
               four=9;
            }
			*(ap+3) = four;
            printf("s_4 = %d\n", *(ap+3));
          
      }
      else if(menu_t.inputNumber_Select ==4){
             five--;
            if( five < 0){ 
                five=9;
            }
		*(ap+4) = five;
            printf("s_4 = %d\n", *(ap+4));
          
      }

}
static void Number_Digital_5bit_AddSelect(int8_t *ap)
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
      else if(menu_t.inputNumber_Select==3){
                  four++;  
                  if(four >9){
                      four=0;
                    }
				  *(ap+3) = four; 
      } 
      else if(menu_t.inputNumber_Select ==4){
                  five++;  
                  if(five >9){
                      five=0;
                    }
			*(ap+4) = five; 
      } 

}
void Number_Digital_5bitPoint_DecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){ //one == -1 ->display "-"
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
      else if(menu_t.inputNumber_Select==3){
             four--;
            if( four < 0){ 
               four=9;
            }
			*(ap+3) = four;
            printf("s_4 = %d\n", *(ap+3));
          
      }
      else if(menu_t.inputNumber_Select ==4){
             five--;
            if( five == -2){ 
                five=9;
            }
		*(ap+4) = five;
            printf("s_4 = %d\n", *(ap+4));
          
      }

}
void Number_Digital_5bitPoint_AddSelect(int8_t *ap)
{
       if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9 ){
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
      else if(menu_t.inputNumber_Select==3){
                  four++;  
                  if(four >9){
                      four=0;
                    }
				  *(ap+3) = four; 
      } 
      else if(menu_t.inputNumber_Select ==4){
                  five++;  
                  if(five >10){
                      five=0;
                    }
			*(ap+4) = five; 
      } 

}


void Number_Digital_F111_4bit_AddSelect(int8_t *ap)
{
      uint8_t static i;
        if(i>3)i=0;
         *ap =i;
         i++;

}

void Number_Digital_F111_4bit_DecSelect(int8_t *ap)
{
      int8_t static i;
       i--;
       if(i ==-1)i=3;
       *ap =i;
        
}


void Number_Digital_Set5bit_AddSelect(int8_t *ap ,uint8_t n)
{
     static  uint8_t  i;
       i++;
       if(i>n)i=1;
       *ap =i;
       menu_t.F34_KEY_VALUE = i;
      
        
        

}
void Number_Digital_Set5bit_twoAddSelect(int8_t *ap ,uint8_t n)
{
    static  uint8_t  i;
       i++;
       if(i>n)i=1;
       *ap =i;
       menu_t.F34_KEY_VALUE = i;
      
        
        

}
void Number_Digital_Set5bit_DecSelect(int8_t *ap,uint8_t n)
{
     static  int8_t  i=2;
       i--;
      if(i ==0)i=n;
       *ap =i;
       
       menu_t.F34_KEY_VALUE = i;
        
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





