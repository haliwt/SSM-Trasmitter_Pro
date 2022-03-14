#include "run.h"
 mainitem mainitem_t;
submenublinkmenu blinkMenu;

uint8_t csmu;
void CheckMode(uint8_t mydata)
{
    KEY_Function(mydata);

}

void RunCommand(void)
{
    
    if(cali_t.CaliControl_key==0){
     switch(mainitem_t.task_MainMenu){

        
         case TheFirst_Menu:
              
                 MainMenu(menu_t.mainTop);
         break;

         case TheSecond_Menu:
               
                switch(menu_t.menuTitle_02){
                 case 0:

                 break;
               
                 case 1://F1-01
                     menu_t.F1_Submenu_Check_flag =0x01;
                     F1_DIS();
                    F1SubMenu(menu_t.F1_SubMenuTop); //"Fx - 01"
                    printf("runCmd_thSecondMenu_01\n");
                    key_t.keyReturn_flag=0;

                 break;

                 case 2://F2-01
                     menu_t.F1_Submenu_Check_flag =0x02;
                     F2SubMenu_Master_01();
                     F2SubMenu_02(menu_t.F2_SubMenuTop);
                 break;

                 case 3: //F3-01-
                     menu_t.F1_Submenu_Check_flag =0x03;
                     F3SubMenu_Master_01();
                     F3SubMenu_02_DispSelect(menu_t.F3_SubMenuTop);
                 break;

                 case 7: //F7-01-
                       
                        F7SubMenu_Master_01();
                       F7SubMenu_02_DIS(f7menu_t.F7_SubMenuTop) ;
                 break; 

                 case 8: //F8-01-
                    F8SubMenu_Master_01();
                    F8SubMenu_02_DIS(f8menu_t.F8_SubMenuTop) ;
                 break; 

                 case 9: //F8-01-
                       F9SubMenu_Master_01();
                       F9SubMenu_02_DIS(f9menu_t.F9_SubMenuTop) ;
                 break; 

               
                }
         break;

         case TheThird_Menu:
        
               switch(menu_t.menuTitle_03){

                   case 0:
                         
                    break;

                   case submenu_F1: //F1-01:
                         TheThird_F1_03_Menu();
                    break;
                    
                    case submenu_F2:
                           F2SubMenu_03_Item();//TheThird_F2_03_Menu();
                    break;

                    case submenu_F3:
                           F3SubMenu_03_Item(menu_t.menu_F1Sub_03_xx_key);//TheThird_F2_03_Menu();

                    break;

                    case submenu_F7:
                            F7SubMenu_03_DIS(menu_t.menu_F1Sub_03_xx_key);
                         
                    break;

                    case submenu_F8:
                          //F8SubMenu_03_DIS();
                          F8SubMenu_03_DIS(menu_t.menu_F1Sub_03_xx_key);
                    break;

                    case submenu_F9:
                         // F9SubMenu_03_DIS();
                          F9SubMenu_03_DIS(menu_t.menu_F1Sub_03_xx_key);
                    break;

                   

              }
              
             

         break;
         
         case TheFourth_Menu: //F3->F3-1->F3-1.1 -> ;F3-2 ->F3-2.1
              
           
             switch(menu_t.menuTitle_04){

                case F3401: //3bit
                            menu_t.F3_04_ID = F3401;
                            F3SubMenu_F301_11_Select_DIS(AF301);

                    break;

                    case F3402: //bit  1
                            menu_t.F3_04_ID = F3402;
                            F3SubMenu_F301_12_Select_DIS(AF302);
                    break;


                    case F3403://bit 6
                            menu_t.F3_04_ID = F3403;
                        F3SubMenu_F301_13_Select_DIS(AF303);
                    break;

                    case F3404: //bit 3 point
                            menu_t.F3_04_ID = F3404;
                            F3SubMenu_F301_14_Select_DIS(AF304);
                    break;

                    case F3405://  5 bit
                            menu_t.F3_04_ID = F3405;
                        F2SubMenu_F202_01_Select_DIS(AF305);
                    break;

                    case F3406:
                        menu_t.F3_04_ID = F3406;
                    F2SubMenu_F202_01_Select_DIS(AF306);
                    break;

                    case F3407:
                        menu_t.F3_04_ID = F3407;
                    F2SubMenu_F202_01_Select_DIS(AF307);
                    break;

            }
                         
            break;

          

         default:
                    key_t.keyset++;
                    key_t.keyswitch++;
                    key_t.keytrae++;
                    key_t.keyzero++; 
                 
					run_t.dispCmd=0;

         break;
    }
  }
  else{

    RunCalibration_Command();

  }

}


/***************************************************************
 * 
 * Function Name :void RunCalibration_Command(void)
 * Function : Display for Smg 
 * 
 * 
 ***************************************************************/
void RunCalibration_Command(void)
{

      switch(mainitem_t.task_MainMenu){
          
          
           case caliTheFirst_Menu: //Calibration Function //CAL1 ,CAL2,CAL3 ,CAL5
         
                  CALI_MENU_01_DIS(cali_t.CaliMenu_Item);
                    printf("Cali_theFirstMenu = %d\n",cali_t.CaliMenu_Item);
            break;

            case caliTheSecond_Menu: //Calibration Function //dC-u CAP,2Ero
                    if(cali_t.Thefirst_InputKeyValue==0 ){
                                mainitem_t.task_MainMenu=caliTheFirst_Menu;
                    }
                    else{
                    CALI_MENU_SUB_02_DIS( cali_t.CaliSub_theSecond_02_Item);
                    printf("runTheSecond = %d\n", cali_t.CaliSub_theSecond_02_Item);
                    // printf("runSencod_02_Title = %d\n",  cali_t.CaliSub_Menu_02_Title);
                    }
            break;

            case caliTheThird_Menu: //Calibration Function //0000,1.230,0000
                    
                     CALI_MENU_SUB_03_DIS( cali_t.CaliMenu_02_sub_Id);
                    printf("RunThethird  = %d\n",  cali_t.CaliMenu_Item);
                     //printf("RunThird_sub  = %d\n",  cali_t.CaliMenu_02_sub_Id);
            break;


      }

}

	
