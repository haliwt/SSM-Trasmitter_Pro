#include "key.h"
#include "menu.h"

#define MAZ_F1_SUBMENU_SIZE   13

KEY key_t;

run run_t;
subNumbers_TypedDef submenStruct;

int8_t Amenu_Top = -1;

uint8_t Amenu[MAZ_F1_SUBMENU_SIZE];



static void KEY1_ZERIO_UP_Fun(void);
static void KEY2_TRAE_DOWN_Fun(void);
static void KEY3_SWITCH_LEFT_Fun(void);
static void KEY4_SET_ENTER_Fun(void);
static void KEY_SubMenuFun_Enter(void);



int8_t ATop(void);

void GetKeyValua_Init(void)
{
   key_t.currkeyset =0xff;
   key_t.currkeytrae = 0xff;
   key_t.currkeyswitch = 0xff;
   key_t.currkeyzero = 0xff;   
   key_t.keyTimes=0;
   menu_t.inputNumber_Select=1;
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
                     if(key_t.keyTimes_2s <=2){
                      if(key_t.currkeyswitch !=key_t.keyswitch){
                            key_t.currkeyswitch = key_t.keyswitch;
                            KEY3_SWITCH_LEFT_Fun();
                      }
                     }
                     else{


                     }
                  key_t.keyset++;
                  key_t.keytrae++;
                  key_t.keyzero++; 
							 	      
               break;

                 case 0xf7://KEY4-SET/CAL-->Enter
                    run_t.dispCmd =1;
                    CH2_KeyLed();
                     key_t.keyTimes =1;
                     if(key_t.keyTimes_2s <= 2 ){
                          if(key_t.keyset !=key_t.currkeyset){
                               key_t.keyset = key_t.currkeyset;
                              KEY4_SET_ENTER_Fun();
                             
                         }
                    }
                     else{ //be pressed over 2s times
                          
                          
                     }
                     CH4_KeyLed();
                     
                 key_t.keyswitch++;
                 key_t.keytrae++;
                 key_t.keyzero++; 
								      
               break;

               default:     
			//SmgDisplay_Character(digital_5,0);
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
               menuFxSubTop=-1;
               menu_t.FxMainMenu_key =0xB0;
             //  menu_t.FxSub_02_key=0xf01;
               menu_t.F1_SubMenuTop= PushSub_Menu(F1Mnumbers);//subNumbers_TypedDef submenN;
               temp0=  SubMenu_02_Top();
               if(temp0==-1){
                     temp0= 0;
                        menu_t.F1_SubMenuTop=temp0;
               }
               else{

                      menu_t.F1_SubMenuTop=temp0;
               }
             }
             else{ //F1-01 ->next -> g ,H9,t,n,nonE
                 
                  f1key = f1key ^ 0x01;
                  if(f1key == 1){
                 
                        /*****************The third********************/
                        mainitem_t.task_MainMenu=TheThird_Menu; //open the third menu
                        menu_t.menuTitle_03=submenu_F1;
                        //runKey fun
                        menu_t.FxMainMenu_key =0xC0; //the third menu open 
                        menu_t.FxSub_03_key=0xf10;  //the third sub open
                  
                  //       temp=submenu_03_Top();
                  //      if(temp==-1){
                  //             temp =0;
                             
                  //       }
                        
                        switch(menu_t.F1SubMenu_Id){

                           case F101:
                                    menu_t.F1_Sub01_Top=temp;
                           break;

                           case F102:
                                    menu_t.F1_Sub02_Top=temp;
                           break;

                           case F103:
                                    menu_t.F1_Sub03_Top=temp;
                           break;


                        }
                       
                        menu_t.menu_F1Sub_03_xx_key=menu_t.F1SubMenu_Id;
                    }    
                  
                  else{
                        
                        menu_t.menuId= F1;
                       

                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                      
                        menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;

                       /*  temp0=  SubMenu_02_Top();
                        if(temp0==-1){
                              temp0= 0;
                             // menu_t.F1_SubMenuTop=temp0;
                        } */
                        switch(menu_t.F1SubMenu_Id){

                           case F101:
                                    menu_t.F1_Sub01_Top=temp0;
                           break;

                           case F102:
                                    menu_t.F1_Sub02_Top=temp0;
                           break;

                           case F103:
                                    menu_t.F1_Sub03_Top=temp0;
                           break;


                        }
                       
                     //   menu_t.F1_SubMenuTop=temp0;
                       
                  }
		}


            break;
         
          case F2:
            if(menu_t.menuF2Sub_first==0){  
				menu_t.menuF2Sub_first++;
                        menuTop= -1;
                        menuFxSubTop=-1;
				menu_t.menuMain=0;
				menu_t.active_Submenu=F2;//the second menu
				menu_t.menuTitle_03=submenu_F2; //RunCommand()
				menu_t.F2_SubMenuTop= PushSub_Menu(F2Mnumbers);
			}
            else{
                      menu_t.menuF2Sub_first=0;
                      menu_t.active_Submenu=F2; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = submenu_03_Top();
                      menu_t.FxSub_02_key =F101_02;
                      menu_t.F1SubMenu_Sub_02_Id=menu_t.F1_Sub01_Top ;

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
               menu_t.F1_SubMenuTop = PushSub_Menu(F1Mnumbers);
         break;

         case 0xc0: //the third Menu
            switch( menu_t.FxSub_03_key){

                    
                    case 0xf10:
                          switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0x00:
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                              break;

                              case 0x01:
                                    menu_t.F1_Sub02_Top=  PushSub_03_Menu(F101_01_02);
                              break;

                               case 0x02:
                                    menu_t.F1_Sub03_Top=  PushSub_03_Menu(F101_01_03);
                              break;

                               case 0x03:
                                    menu_t.F1_Sub04_Top=  PushSub_03_Menu(F101_01_04);
                              break;

                                case 0x04:
                                  menu_t.F1_Sub05_Top=  PushSub_03_Menu(F101_01_05);
                              break;

                              case 0x05:
                                    menu_t.F1_Sub06_Top=  PushSub_03_Menu(F101_01_06);
                              break;

                               case 0x06:
                                    menu_t.F1_Sub07_Top=  PushSub_03_Menu(F101_01_07);
                              break;

                               case 0x07:
                                    menu_t.F1_Sub08_Top=  PushSub_03_Menu(F101_01_08);
                              break;

                                case 0x08:
                                  menu_t.F1_Sub09_Top=  PushSub_03_Menu(F101_01_09);
                              break;

                              case 0x09:
                                    menu_t.F1_Sub10_Top=  PushSub_03_Menu(F101_01_10);
                              break;

                               case 0x0A:
                                    menu_t.F1_Sub11_Top=  PushSub_03_Menu(F101_01_11);
                              break;

                               case 0x0B:
                                    menu_t.F1_Sub12_Top=  PushSub_03_Menu(F101_01_12);
                              break;

                               case 0x0C:
                                    menu_t.F1_Sub13_Top=  PushSub_03_Menu(F101_01_13);
                              break;

                          }
                    break;

                    case 0xf20:

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
             menu_t.F1_SubMenuTop = PopSub_Menu(F1Mnumbers);
     break;   

     case 0xC0:
             switch( menu_t.FxSub_03_key){

                    
                    case 0xf10:
                          switch(menu_t.menu_F1Sub_03_xx_key){

                              case 0x00:
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                              break;

                              case 0x01:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_02);
                              break;

                               case 0x02:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_03);
                              break;

                               case 0x03:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_04);
                              break;

                                case 0x04:
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_05);
                              break;

                              case 0x05:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_06);
                              break;

                               case 0x06:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_07);
                              break;

                               case 0x07:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_08);
                              break;

                                case 0x08:
                                  menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_09);
                              break;

                              case 0x09:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_10);
                              break;

                               case 0x0A:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_11);
                              break;

                               case 0x0B:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_12);
                              break;

                               case 0x0C:
                                    menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_13);
                              break;

                          }
                    break;

                    case 0xf20:

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
 * Function :return last menu 
 * 
**************************************************************/
static void KEY3_SWITCH_LEFT_Fun(void)
{ 
    
        if(menu_t.menuTitle_03 == mainmenuItem){
                menu_t.menuTitle_03 =0xf0;
                return ;

          }
           
          if(menu_t.F1SubMenu_Sub_02_Id==F101_01 || menu_t.F1SubMenu_Sub_02_Id==F101_02 || menu_t.F1SubMenu_Sub_02_Id==F101_02 || menu_t.F1SubMenu_Sub_02_Id==F101_03 \
               || menu_t.F1SubMenu_Sub_02_Id==F101_04 || menu_t.F1SubMenu_Sub_02_Id==F101_05 || menu_t.F1SubMenu_Sub_02_Id==F101_06 || menu_t.F1SubMenu_Sub_02_Id==F101_07 \
               || menu_t.F1SubMenu_Sub_02_Id==F101_08 || menu_t.F1SubMenu_Sub_02_Id==F101_09 || menu_t.F1SubMenu_Sub_02_Id==F101_09 || menu_t.F1SubMenu_Sub_02_Id==F101_10 \
               || menu_t.F1SubMenu_Sub_02_Id==F101_11 || menu_t.F1SubMenu_Sub_02_Id==F101_12 || menu_t.F1SubMenu_Sub_02_Id==F101_13 ){
                menu_t.inputNumber_Select ++;
             if(menu_t.inputNumber_Select == 4){
				 menu_t.inputNumber_Select=0;
			 }
               return ;
           }
    
          
          //the third menu select digital numbers
           if(menu_t.F1SubMenu_Sub_02_Id==F101){

             menu_t.menuTitle_03=mainmenuItem;
              
          }

}

int8_t ATop(void)
{
	return  Amenu[Amenu_Top];
}
