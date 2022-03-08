#include "key.h"
#include "menu.h"

#define MAZ_F1_SUBMENU_SIZE   13

KEY key_t;
run run_t;
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

//*******************/
int8_t AF201[1];
int8_t AF202[5];
int8_t AF203[5];
int8_t AF204[1];
int8_t AF205[5];
int8_t AF206[5];




int8_t Amenu_Top = -1;

uint8_t Amenu[MAZ_F1_SUBMENU_SIZE];

int8_t one,two,three,four,five; 
void(*DispDigital_3BitSmg)(void);

static void Number_Digital_SetUp5bit_AddSelect(int8_t *ap ,uint8_t n);
static void Number_Digital_SetUp5bit_AddSelect(int8_t *ap ,uint8_t n);

static void Number_Digital_2bit_DecSelect(int8_t *ap);
static void Number_Digital_2bit_AddSelect(int8_t *ap);

static void Number_Digital_3bit_PointerDecSelect(int8_t *ap);
static void Number_Digital_3bit_PointerAddSelect(int8_t *ap);

static void Number_Digital_3bit_DecSelect(void);
static void Number_Digital_3bit_AddSelect(void);

static void Number_Digital_4bit_DecSelect(int8_t *ap);
static void Number_Digital_4bit_AddSelect(int8_t *ap);

static void Number_Digital_5bit_DecSelect(int8_t *ap);
static void Number_Digital_5bit_AddSelect(int8_t *ap);

static void Number_Digital_F111_4bit_AddSelect(int8_t *ap);
static void Number_Digital_F111_4bit_DecSelect(int8_t *ap);

//void RunDispDigital_Fun(void(*DisSmg)(void));
static void KEY1_ZERIO_UP_Fun(void);
static void KEY2_TRAE_DOWN_Fun(void);
static void KEY3_SWITCH_LEFT_Fun(void);
static void KEY4_SET_ENTER_Fun(void);
static void KEY_SubMenuFun_Enter(void);
static void F1_01_xx_SelectCmd(void);



int8_t ATop(void);

void GetKeyValua_Init(void)
{
   key_t.currkeyset =0xff;
   key_t.currkeytrae = 0xff;
   key_t.currkeyswitch = 0xff;
   key_t.currkeyzero = 0xff;   
   key_t.keyTimes=0;
   
}

void KEY_Function(uint8_t keydata)
{
             switch(keydata){

               case 0:
                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    key_t.keyzero++; 
                    key_t.keyTimes =0;
	
			break;
   
               case 0xf4://KEY1-ZERO--up
                    run_t.dispCmd =1;
                    Net_KeyLed();
                   
                    if(key_t.currkeyzero != key_t.keyzero){
                           key_t.currkeyzero = key_t.keyzero; 
                           KEY1_ZERIO_UP_Fun();
                          
                    }
                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                     Valley_KeyLed();
                  
               break;
                   
               case 0xf6://KEY2 -TARE-donwn
                    run_t.dispCmd =1;
                    // Peak_KeyLed();
                     Mot_KeyLed();
                     if(key_t.currkeytrae != key_t.keytrae){
                           key_t.currkeytrae = key_t.keytrae;
                          KEY2_TRAE_DOWN_Fun();
                     }
											
                   key_t.keyset++;
                 key_t.keyswitch++;
                
                 key_t.keyzero++; 
               break;

               case 0xf5: //KEY3 -SWITCH   <-
                    run_t.dispCmd =1;
                    // CH1_KeyLed();
                     CH3_KeyLed();
                     key_t.keyTimes=1;
                     if(key_t.currkeyswitch !=key_t.keyswitch){
                            key_t.currkeyswitch = key_t.keyswitch;
                            KEY3_SWITCH_LEFT_Fun();
                      }
                    
                  Valley_KeyLed();
                  key_t.keyset++;
                  key_t.keytrae++;
                  key_t.keyzero++; 
							 	      
               break;

                 case 0xf7://KEY4-SET/CAL-->Enter
                    run_t.dispCmd =1;
                    CH2_KeyLed();
                     key_t.keyTimes =1;
                     if(key_t.keyset !=key_t.currkeyset){
                          key_t.keyset = key_t.currkeyset;
                              KEY4_SET_ENTER_Fun();
                             
                         
                    }
                  
                     CH4_KeyLed();
                     
                 key_t.keyswitch++;
                 key_t.keytrae++;
                 key_t.keyzero++; 
								      
               break;

               default:     
			 key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    key_t.keyzero++; 
                    key_t.keyTimes =0;
               break;

               
            }

}
/**********************************************************
 * 
 * Function Name:static void KEY_MainMenuFun(void)
 * Function : the first be pressed Enter key
 * 
********************************************************/  
static void	KEY4_SET_ENTER_Fun(void)
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
      static int8_t temp=0,temp0,F1currkey= 0XFF,f1key=0;
      switch(menu_t.menuId){
               
          case F1: //F1 - 01
            
		if( menu_t.menuF1Sub_first== 0){ //"F1- 01"
             
               menu_t.menuF1Sub_first++;
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
                  
                  else{
                        
                        menu_t.menuId= F1;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                        
                        menu_t.F1_SubMenuTop=menu_t.F1SubMenu_Id;
                     
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
            if(menu_t.menuF3Sub_first==0){  
				menu_t.menuF3Sub_first++;
				menu_t.menuMain=0;
                    menuTop= -1;
                    menuFxSubTop=-1;
				menu_t.active_Submenu=F3;//the second menu
				menu_t.menuTitle_03=submenu_F3; //RunCommand()
				menu_t.F3_SubMenuTop= PushSub_Menu(F3Mnumbers);
			} 
            else{
                    menu_t.menuF2Sub_first=0;
                      menu_t.active_Submenu=F3; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = submenu_03_Top();
                      menu_t.FxSub_02_key =F101_03;
                      menu_t.F1SubMenu_Sub_02_Id=menu_t.F1_Sub01_Top ;

            }   
          break;
          
         case F7:
            if(menu_t.menuF7Sub_first==0){  
				menu_t.menuF7Sub_first++;
				menu_t.menuMain=0;
                    menuTop= -1;
                    menuFxSubTop=-1;
				menu_t.active_Submenu=F7;//the second menu
				menu_t.menuTitle_03=submenu_F7; //RunCommand()
				menu_t.F7_SubMenuTop = PushSub_Menu(7);
			} 
            else{
                      menu_t.menuF7Sub_first=0;
                      menu_t.active_Submenu=F7; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top =submenu_03_Top();
                      menu_t.FxSub_02_key =F101_07;
                      menu_t.F1SubMenu_Sub_02_Id=menu_t.F1_Sub01_Top ;


            } 
            
          case F8:
            if(menu_t.menuF8Sub_first==0){  
				menu_t.menuF8Sub_first++;
				menu_t.menuMain=0;
				menuTop= -1;
				menuFxSubTop=-1;
				menu_t.active_Submenu=F8;//the second menu
				menu_t.menuTitle_03=submenu_F8; //RunCommand()
				menu_t.F8_SubMenuTop= PushSub_Menu(F8Mnumbers);
			}  
            else{
                      menu_t.menuF8Sub_first=0;
                      menu_t.active_Submenu=F8; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = submenu_03_Top();
                      menu_t.FxSub_02_key =F101_08;
                      menu_t.F1SubMenu_Sub_02_Id=menu_t.F1_Sub01_Top -1 ;


            }  
          break; 
          
          case F9:
            if(menu_t.menuF9Sub_first==0){  
				menu_t.menuF9Sub_first++;
				menu_t.menuMain=0;
				menuTop= -1;
				menuFxSubTop=-1;
				menu_t.active_Submenu=F9;//the second menu
				menu_t.menuTitle_03=submenu_F9; //RunCommand()
				menu_t.F9_SubMenuTop= PushSub_Menu(F9Mnumbers);
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
     
     switch(menu_t.FxMainMenu_key){

         case 0:

         break;

         case 0xA0:  //the first Menu 
             
               menu_t.mainTop= PushMainMenu(); 
                 
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

               }
         break;

         case 0xc0: //the third Menu
            switch( menu_t.FxSub_03_key){

                    
                    case 0xf10:
                          switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0x00: //F1-01-01
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                                  printf("f1sub_01_n_Top = %d\n",menu_t.F1_Sub01_Top);
                                   key_t.keyReturn_flag=1;
                              break;

                              case 0x01: //F1-02-01
                                   RunDispDigital_Fun(Number_Digital_3bit_AddSelect);
                                   menu_t. F1_Sub02_unit= menu_t.unit;
                                    menu_t.F1_Sub02_decade=menu_t.decade;
                                   menu_t.F1_Sub02_hundred =menu_t.hundred;
                                
                                    printf("f1sub_02_n_Top = %d\n",menu_t.F1_Sub02_Top);
                                    key_t.keyReturn_flag=1;
                              break;

                               case 0x02: //F1-03-01
                                   RunDispDigital_Fun(Number_Digital_3bit_AddSelect);
                                   menu_t. F1_Sub03_unit= menu_t.unit;
                                    menu_t.F1_Sub03_decade=menu_t.decade;
                                   menu_t.F1_Sub03_hundred =menu_t.hundred;
                                     key_t.keyReturn_flag=1;
                                   
                              break;

                               case 0x03: //F1-04-01
                                    Number_Digital_4bit_AddSelect(AF104);
                                      key_t.keyReturn_flag=1;
                              break;

                                case 0x04://F1-05-01
                                   Number_Digital_2bit_AddSelect(AF105);
                                   printf("F1_01_05_AddKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
                                 key_t.keyReturn_flag=1;
                              break;

                              case 0x05://F1-06-01
                                    Number_Digital_5bit_AddSelect(AF106);
                                      key_t.keyReturn_flag=1;
                              break;

                               case 0x06: //F1-07-01
                                     Number_Digital_5bit_AddSelect(AF107);
                                    key_t.keyReturn_flag=1;
                              break;

                               case 0x07: //F1-08-01
                                   Number_Digital_2bit_AddSelect(AF108);
                                     key_t.keyReturn_flag=1;
                              break;

                              case 0x08: //F1-09-01
                                  Number_Digital_4bit_AddSelect(AF109);
                              break;

                              case 0x09: //F1-10-01
                                     Number_Digital_5bit_AddSelect(AF110);
                              break;

                               case 0x0A://F1-11-01 ->display 4 bit
                                   Number_Digital_F111_4bit_AddSelect(AF111);
                                    
                              break;

                               case 0x0B://F1-12-01
                                     Number_Digital_2bit_AddSelect(AF112);
                              break;

                               case 0x0C://F1-13-01
                                    Number_Digital_2bit_AddSelect(AF113);
                              break;

                          }
                    break;

                    case 0xf20:
                        switch(menu_t.menu_F1Sub_03_xx_key){

                           case F201:
                              Number_Digital_SetUp5bit_AddSelect(AF201,3);
                           break;

                           case F202:
                              Number_Digital_5bit_AddSelect(AF202);
                           break;

                           case F203:
                               Number_Digital_5bit_AddSelect(AF203);
                           break;

                           case F204:
                               Number_Digital_SetUp5bit_AddSelect(AF204,3);
                           break;

                           case F205:
                               Number_Digital_5bit_AddSelect(AF205);
                           break;

                           case F206:
                               Number_Digital_5bit_AddSelect(AF206);
                           break;


                        }
                    break;

                    case 0xf30:

                    break;

                    case 0xf40:

                    break;

                    case 0xf50:

                    break;

                    case 0xf60:

                    break;

                    case 0xf70:

                    break;

                    case 0xf80:

                    break;

                    case 0xf90:

                    break;

                    case 0xfa0:

                    break;

                    case 0xfb0:

                    break;

                    case 0xfc0:

                    break;

                    case 0xf13:

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
    
    case 0xA0 :
            menu_t.mainTop=PopMainMenu();
     break;
      
     case 0xB0:
      switch(menu_t.FxSub_02_key){

                case 0xf10: //F1-01
                        menu_t.F1_SubMenuTop = PopSub_Menu(F1Mnumbers);
                        printf("f1sub_Top_keyd = %d\n",menu_t.F1_SubMenuTop);
                break;

                case 0xf20: //F2-01
                       menu_t.F2_SubMenuTop = PopSub_Menu(F2Mnumbers);
                break;

                case 0xf30: //F3-01

                break;

                case 0xf70:

                break;

                case 0xf80:

                break;

                case 0xf90:

                break;
                default:

                break;
      }
     break;   

     case 0xC0:
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
                                Number_Digital_SetUp5bit_AddSelect(AF201,3);          
                           break;

                           case F202:

                           break;

                           case F203:

                           break;

                           case F204:

                           break;

                           case F205:

                           break;

                           case F206:

                           break;


                        }

                    break;

                    case 0xf30:

                    break;

                    case 0xf40:

                    break;

                    case 0xf50:

                    break;

                    case 0xf60:

                    break;

                    case 0xf70:

                    break;

                    case 0xf80:

                    break;

                    case 0xf90:

                    break;

                    case 0xfa0:

                    break;

                    case 0xfb0:

                    break;

                    case 0xfc0:

                    break;

                    case 0xf13:

                    break;

                }

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
     
    
      
      //2BIT
      if(menu_t.F1SubMenu_Sub_02_Id ==0x04|| menu_t.F1SubMenu_Sub_02_Id ==0x07||menu_t.F1SubMenu_Sub_02_Id ==0x0B\
         ||menu_t.F1SubMenu_Sub_02_Id ==0x0C){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >1){
                  menu_t.inputNumber_Select =0;
            }
            
              
       }
      
      //3BIT
      if(menu_t.F1SubMenu_Sub_02_Id ==0x01 ||  menu_t.F1SubMenu_Sub_02_Id ==0x02 || menu_t.F2SubMenu_Id==F201\
          ||menu_t.F2SubMenu_Id==F204){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >2){
                  menu_t.inputNumber_Select =0;
            }
            
              
       }
    //4IBIT
    if(menu_t.F1SubMenu_Sub_02_Id ==0x03|| menu_t.F1SubMenu_Sub_02_Id ==0x08|| menu_t.F1SubMenu_Sub_02_Id ==0x0A){
          menu_t.inputNumber_Select ++;
        if(menu_t.inputNumber_Select >3){
                  menu_t.inputNumber_Select =0;
          }
    }
    //5BIT
    if(menu_t.F1SubMenu_Sub_02_Id ==0x05 ||menu_t.F1SubMenu_Sub_02_Id ==0x06||menu_t.F1SubMenu_Sub_02_Id ==0x09\
            ||menu_t.F2SubMenu_Id==F202||menu_t.F2SubMenu_Id==F203||menu_t.F2SubMenu_Id==F205||menu_t.F2SubMenu_Id==F206){
            menu_t.inputNumber_Select ++;
           if(menu_t.inputNumber_Select >4){
              menu_t.inputNumber_Select =0;
          }



    }

//     if(menu_t.F1SubMenu_Id != 0xff){
//            mainitem_t.task_MainMenu =TheFirst_Menu;
//            menu_t.mainTop =  MainMenu_Top();
//            return ;
//    }
      


   
      
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
static void Number_Digital_2bit_DecSelect(int8_t *ap)
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
static void Number_Digital_2bit_AddSelect(int8_t *ap)
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
      else if(menu_t.inputNumber_Select >=2){
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
      else if(menu_t.inputNumber_Select >=2){
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

static void Number_Digital_3bit_PointerDecSelect(int8_t *ap)
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
static void Number_Digital_3bit_PointerAddSelect(int8_t *ap)
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


void Number_Digital_SetUp5bit_AddSelect(int8_t *ap ,uint8_t n)
{
      uint8_t static i;
        if(i>(n-1))i=0;
         *ap =i;
         i++;

}

void Number_Digital_SetUp_5bit_DecSelect(int8_t *ap,uint8_t n)
{
      int8_t static i;
       i--;
       if(i ==-1)i=(n-1);
       *ap =i;
        
}
