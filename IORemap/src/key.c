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

static void PushMenu_To_SubMenu(uint8_t submenuItem);
static void PopMenu_To_SubMenu(void);

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
                    Valley_KeyLed();
                    if(key_t.currkeyzero != key_t.keyzero){
                           key_t.currkeyzero = key_t.keyzero; 
                           KEY1_ZERIO_UP_Fun();
                          
                    }
                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    
                  
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
          menu_t.active_Submenu=0;
          menu_t.menuTitle=mainmenuItem;
          menu_t.FxSub_subMenu_key=0XFF;
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
    
      switch(menu_t.menuId){
               
          case F1: //F1 - 01
               
		     if( menu_t.menuF1Sub_first== 0){ //"F1- 01"
             
               menu_t.menuF1Sub_first++;
               menu_t.menuMain=0;
               menuFxSubTop=-1;
               menu_t.F1SubMenu_Sub_02_Id=F101;
               menu_t.active_Submenu=F1; //the second menu
               menu_t.menuTitle=submenu_F1; //RunCommand()
               menu_t.FxSub_subMenu_key=0XFF;
               menu_t.F1_SubMenuTop= PushSub_Menu(F1Mnumbers);//subNumbers_TypedDef submenN;
           
               }
               else{ //F1-01 ->next -> g ,H9,t,n,nonE
                       menu_t.menuF1Sub_first++;
                      if( menu_t.menuF1Sub_first==2){ //the second input menu
                          menu_t.menuTitle =submenu_F1;
                          menu_t.F1SubMenu_Sub_02_Id =0xff;
                          menu_t.F1SubMenu_Sub_03_Id=F101_01;
                          menu_t.F1_Sub01_Top=0;
                         menu_t.FxSub_subMenu_key=0XF1;      
                      }
                      else{ //the third 
                          
                          if(menu_t.F101_03_SubMeng_flag == 0x0){
                             
                              menu_t.menuF1Sub_first=0;
                              menu_t.menuId=F1;
                          }
                          else{
                              
                              
                            menu_t.menuTitle =submenu_F1;
                            menu_t.F1SubMenu_Sub_02_Id =0xff;
                            if(menu_t.F1SubMenu_Sub_03_Id ==F101_01){ //???
                              menu_t.F1_Sub01_Top=SubMenu_03_Top();
                              menu_t.menuF1Sub_first=0;
                               menu_t.FxSub_subMenu_key=0XF101;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_02){
                                menu_t.FxSub_subMenu_key=0XF102;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_03){
                                menu_t.FxSub_subMenu_key=0XF103;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_04){
                                menu_t.FxSub_subMenu_key=0XF104;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_05){
                                menu_t.FxSub_subMenu_key=0XF105;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_06){
                                menu_t.FxSub_subMenu_key=0XF106;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_07){
                                menu_t.FxSub_subMenu_key=0XF107;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_08){
                                menu_t.FxSub_subMenu_key=0XF108;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_09){
                                menu_t.FxSub_subMenu_key=0XF109;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_10){
                                menu_t.FxSub_subMenu_key=0XF110;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_11){
                                menu_t.FxSub_subMenu_key=0XF111;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_12){
                                menu_t.FxSub_subMenu_key=0XF112;
                                menu_t.menuF1Sub_first=0;
                            }
                            else if(menu_t.F1SubMenu_Sub_03_Id ==F101_13){
                                menu_t.FxSub_subMenu_key=0XF113;
                                menu_t.menuF1Sub_first=0;
                            }
                          }
                          
                          
                          
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
				menu_t.menuTitle=submenu_F2; //RunCommand()
				menu_t.F2_SubMenuTop= PushSub_Menu(F2Mnumbers);
			}
            else{
                      menu_t.menuF2Sub_first=0;
                      menu_t.active_Submenu=F2; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = SubMenu_03_Top();
                      menu_t.FxSub_subMenu_key =F101_02;
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
				menu_t.menuTitle=submenu_F3; //RunCommand()
				menu_t.F3_SubMenuTop= PushSub_Menu(F3Mnumbers);
			} 
            else{
                    menu_t.menuF2Sub_first=0;
                      menu_t.active_Submenu=F3; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = SubMenu_03_Top();
                      menu_t.FxSub_subMenu_key =F101_03;
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
				menu_t.menuTitle=submenu_F7; //RunCommand()
				menu_t.F7_SubMenuTop = PushSub_Menu(7);
			} 
            else{
                      menu_t.menuF7Sub_first=0;
                      menu_t.active_Submenu=F7; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = SubMenu_03_Top();
                      menu_t.FxSub_subMenu_key =F101_07;
                      menu_t.F1SubMenu_Sub_02_Id=menu_t.F1_Sub01_Top ;


            } 
            
          case F8:
            if(menu_t.menuF8Sub_first==0){  
				menu_t.menuF8Sub_first++;
				menu_t.menuMain=0;
				menuTop= -1;
				menuFxSubTop=-1;
				menu_t.active_Submenu=F8;//the second menu
				menu_t.menuTitle=submenu_F8; //RunCommand()
				menu_t.F8_SubMenuTop= PushSub_Menu(F8Mnumbers);
			}  
            else{
                      menu_t.menuF8Sub_first=0;
                      menu_t.active_Submenu=F8; //the first select F1-01->menu
                      //PushMenu_To_SubMenu(menu_t.F1SubMenu_Sub_02_Id);
                      menu_t.F1_Sub01_Top = SubMenu_03_Top();
                      menu_t.FxSub_subMenu_key =F101_08;
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
				menu_t.menuTitle=submenu_F9; //RunCommand()
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
     if(menu_t.menuTitle ==mainmenuItem){
          menu_t.mainTop= PushMainMenu(); 
     }
     else{
          switch(menu_t.active_Submenu){
               
               case F1: //F1 sub menu
               
                    switch(menu_t.FxSub_subMenu_key){
                         
                    case 0xff:
                       menu_t.F1_SubMenuTop= PushSub_Menu(F1Mnumbers);
                    
                    break;
                    case 0xf101:  //F101 
                       menu_t.F1_Sub01_Top = PushSub_03_Menu(5);//
                    break;
                    case 0xf102:
                        if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                       
                    break;
                    case 0xf103:
                       if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                    break;
                    
                    case 0xf104:
                         if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                    break;
                    
                    case 0xf105:
                         if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                    break;
                    
                    case 0xf106:
                    if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                    break;
                    
                    case F101_07:
                          if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    
                    case F101_08:
                     if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    
                     case F101_09:
                      if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    
                    case F101_10:
                     if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    
                    case F101_11:
                     if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    case F101_12:
                     if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    
                    case F101_13:
                     if(menu_t.inputNumber_Select==1){
                                menu_t. F1_Sub02_unit++ ;
                               if(menu_t. F1_Sub02_unit >9){
                                   menu_t. F1_Sub02_unit=0;
                              
                               }
                         }
                         else if(menu_t.inputNumber_Select==2){
                              menu_t.F1_Sub02_decade++;
                              if(menu_t.F1_Sub02_decade >9){
                                  menu_t.F1_Sub02_decade=0;
                         }
                         }
                        else if(menu_t.inputNumber_Select==3){
                                 menu_t.F1_Sub02_hundred++;  
                                 if(menu_t.F1_Sub02_hundred >9){
                                    menu_t.F1_Sub02_hundred=0;
                         }
                        }  
                   
                   
                    break;
                    default :
                    
                    break;
                    
               }
               break;
               case F2: //F2 sub menu 
                    menu_t.F2_SubMenuTop =PushSub_Menu(F2Mnumbers);
               break;
               
               case F3: //F3 sub menu
                    menu_t.F3_SubMenuTop =PushSub_Menu(F3Mnumbers);
               break;
               
               case F7: //F7
                    menu_t.F7_SubMenuTop =PushSub_Menu(7);
               break;
               
               case F8: //F8
                    menu_t.F8_SubMenuTop =PushSub_Menu(F8Mnumbers);
               break;
               
               case F9: //F9 sub menu 
                    menu_t.F9_SubMenuTop =PushSub_Menu(F9Mnumbers);
               break;
               
               default:
               
               break;
              }
        }
}
  

static void KEY2_TRAE_DOWN_Fun(void)
{
     
     if(menu_t.menuTitle ==mainmenuItem){
               menu_t.mainTop=PopMainMenu();
      } 
      else{
           switch(menu_t.active_Submenu){
              
            case F1: //F1 -SUB
                
               switch(menu_t.FxSub_subMenu_key){
                    
                case 0xff:
               
                    menu_t.F1_SubMenuTop = PopSub_Menu(F1Mnumbers);
               
               case 0XF1:
                     menu_t.F1_Sub01_Top = PopSub_03_Menu(5);
               
               case 0XF2:

                    if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
               case F101_03:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
                case F101_04:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
                case F101_05:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
                case F101_06:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
               
                case F101_07:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                break;
                
                case F101_08:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                break;
                
                case F101_09:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                break;
                case F101_10:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
               
                case F101_11:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
               
                case F101_12:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
               
                case F101_13:
                     if(menu_t.inputNumber_Select==1){
                         menu_t. F1_Sub02_unit--;
                         if(menu_t. F1_Sub02_unit < 0){
                             menu_t. F1_Sub02_unit=9;
                         }
                    } 
                    else if(menu_t.inputNumber_Select==2){
                          menu_t.F1_Sub02_decade--;
                        if(menu_t.F1_Sub02_decade < 0){
                            menu_t.F1_Sub02_decade=9;
                         }
                    }
                    else if(menu_t.inputNumber_Select==3){
                         menu_t.F1_Sub02_hundred--;
                        if(menu_t.F1_Sub02_hundred < 0){ 
                            menu_t.F1_Sub02_hundred=9;
                        }
                    }
                 
               break;
                 
              
                    
               }
            break;
            
            case F2: //F2 sub menu
                menu_t.F2_SubMenuTop = PopSub_Menu(F2Mnumbers);
            break;
            
            case F3: //F3 -SUB
               menu_t.F3_SubMenuTop = PopSub_Menu(F3Mnumbers);
            break;
            
           case F7: //F7 -SUB
               menu_t.F7_SubMenuTop = PopSub_Menu(7);
            break;
            
            case F8://F8 sub menu
                menu_t.F8_SubMenuTop = PopSub_Menu(F8Mnumbers);
            break;
            
            case F9://F9 sub menu
                menu_t.F9_SubMenuTop = PopSub_Menu(F9Mnumbers);
            break;
            
            default :
            
            break;
        }
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
    
        if(menu_t.menuTitle == mainmenuItem){
                menu_t.menuTitle =0xf0;
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

             menu_t.menuTitle=mainmenuItem;
              
          }

}
static void PushMenu_To_SubMenu(uint8_t submenuItem)
{
	if(Amenu_Top ==(MAZ_F1_SUBMENU_SIZE  -1)){
		//printf("Error :stack overflow \n");
		//return ;
          Amenu[Amenu_Top]=submenuItem;
	}
     else{
          Amenu_Top++;
          Amenu[Amenu_Top]=submenuItem; //A[++top] =x;
     }
}
static void PopMenu_To_SubMenu(void)
{
	 
     if(Amenu_Top ==-1){
	    //printf("Error : no element to Pop \n");
		//return ;
          Amenu_Top =0;	

	}
     else{
         Amenu_Top --;
     }
    
}

int8_t ATop(void)
{
	return  Amenu[Amenu_Top];
}
