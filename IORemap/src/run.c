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
                  key_t.keyTimes=0;
                 MainMenu(menu_t.mainTop);
         break;

         case TheSecond_Menu:
               
                switch(menu_t.menuTitle_02){
                 case 0:

                 break;
               
                 case 1://F1-01
                      key_t.keyTimes=0;
                     menu_t.F1_Submenu_Check_flag =0x01;
                     F1_DIS();
                    F1SubMenu(menu_t.F1_SubMenuTop); //"Fx - 01"
                  //  printf("runCmd_thSecondMenu_01\n");
                 

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
              
             F3_SubMenu_TheFourth_RunCmdDis( menu_t.menu_F1Sub_03_xx_key);
            
                         
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
                  cali_t.keyEnter_flag =0;
                  //printf("Cali_theFirstMenu = %d\n",cali_t.CaliMenu_Item);
            break;

            case caliTheSecond_Menu: //Calibration Function //dC-u CAP,2Ero
                   Calibration_TheSecondRunDis_Cmd();
                  printf("Cali_runCmd_theSencodMenu = %d\n",cali_t.CAL1_Id);
            break;

            case caliTheThird_Menu: //Calibration Function //0000,1.230,0000
                    
                   Calibration_TheThirdRunDis_Cmd();
                    printf("RunThethird_run \n");
                    
            break;

             case caliTheFourth_Menu: //Calibration Function //0000,1.230,0000
                 
            break;


      }

}

	
