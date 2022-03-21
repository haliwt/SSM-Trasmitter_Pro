#include "f2menu.h"


void F2_MasterFunction_EnterKey(void)
{
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
                      
                     key_t.keyReturn_F2_flag ++;
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
                     else if(key_t.keyReturn_F2_flag ==2){
                        key_t.keyReturn_F2_flag =0;
                        menu_t.menuId= F2;
                       

                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                      
                        menu_t.FxMainMenu_key =0xB0;
                         menu_t.menuTitle_02=2;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                   
                        menu_t.F2_SubMenuTop=menu_t.F2SubMenu_Id;
                         if(key_t.F2_0102FlashSave_flag==1){
                            key_t.F2_0102FlashSave_flag=0;
                            if(flash_t.saveDataNumber_flag >=1 ||flash_t.saveDataNumber_flag==1)
                                     FlashSaveData();
                                     
                            if(flash_t.saveDataTheSecondNumber_flag >=1){
                                 FlashSaveData(); 
                                  
                            }
                            printf("flash_save_________OK\n");
                          
				   }
                         flash_t.saveDataNumber_flag=0;
                         flash_t.saveDataTheSecondNumber_flag=0;
				          key_t.keyReturn_flag =0;
                        printf("F2_0102FlashSave_flag = %d\n", key_t.F2_0102FlashSave_flag);
                        printf("f2_enterKey_retrunMenu = %d\n", menu_t.F2_SubMenuTop);
                               
                       }
                     
                      
              }


}


void F2_Add_TheThirdMenu_KeyFunction(uint8_t f2mu)
{
     // switch(menu_t.menu_F1Sub_03_xx_key){
        switch(f2mu){

                  case F201:
                    key_t.F2_0102FlashSave_flag=1;
                  // if(f2r01==0){
                  //    f2r01++;
                  //       Flash_Read(); 
                  //     AF201[0] = ( flash_t.flashData[56] & 0xff000000) >> 24;
                  
                  // }
                  Number_Digital_Set5bit_RefAddSelect(AF201,3);
                  f1menu_t.f2r01_reg = ((SpecDisplay_Number(AF201[0]))<<24);
                  *(pfdata + 14) =f1menu_t.f2r01_reg  | f1menu_t.f2r02_reg;
                  break;

                  case F202:
                  key_t.F2_0102FlashSave_flag=1;
     
                  Number_Digital_5bit_AddSelect(AF202);
                  f1menu_t.f2r02_reg  = ((SpecDisplay_Number(AF202[4]))<<0);
                  *(pfdata + 14) =f1menu_t.f2r02_reg | f1menu_t.f2r01_reg;
                  *(pfdata+15) =(((SpecDisplay_Number( AF202[3]))<< 24)|((SpecDisplay_Number( AF202[2]))<< 16)  | ((SpecDisplay_Number( AF202[1]))<<8) 
                        |((SpecDisplay_Number( AF202[0]))<<0));
                  break;

                  case F203:
                  key_t.F2_0102FlashSave_flag=1;
                  
                    Number_Digital_5bit_AddSelect(AF203);
                    
                  
                  
                  *(pfdata+16) =(((SpecDisplay_Number( AF203[4]))<< 24)|((SpecDisplay_Number( AF203[3]))<< 16)  | ((SpecDisplay_Number( AF203[2]))<<8) 
                        |((SpecDisplay_Number( AF203[01]))<<0));
                  
                   f1menu_t.f2r03_reg  = ((SpecDisplay_Number(AF203[0]))<<24);
                  *(pfdata + 17) =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg); 
                    
                  break;

                  case F204:
                  key_t.F2_0102FlashSave_flag=1;

                   Number_Digital_Set5bit_RefAddSelect(AF204,3);
                  f1menu_t.f2r04_reg = ((SpecDisplay_Number(AF204[0]))<<16);
                  *(pfdata +17)  =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg);
                       
                  break;

                  case F205:
                  key_t.F2_0102FlashSave_flag=1;
                
                  Number_Digital_5bit_AddSelect(AF205);
                  
                  
                 flash_t.saveDataNumber_flag++;
                 
                 flash_t.saveDataTheSecondNumber_flag++;
                 if(flash_t.saveDataNumber_flag >=1){
                        f1menu_t.f2r05_reg  =(((SpecDisplay_Number(AF205[4]))<<8)|((SpecDisplay_Number(AF205[3]))<<0));
                  
                         *(pfdata + 17) =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg); 
                 }
                  if( flash_t.saveDataTheSecondNumber_flag >=1){
                              f1menu_t.f2r05_reg_next = (((SpecDisplay_Number( AF205[2]))<< 24)|((SpecDisplay_Number( AF205[1]))<< 16)  | ((SpecDisplay_Number( AF205[0]))<<8)) ;
                              *(pfdata+18) = f1menu_t.f2r05_reg_next |f1menu_t.f2r06_reg;
                   }
                  
                
                  
                  break;

                  case F206:
                  
                  key_t.F2_0102FlashSave_flag=1;
                  //  if(f2r06==0){
                  //       f2r06++;
                  //        Flash_Read(); 
                         
                  //        AF206[4]=((flash_t.flashData[72] & 0xff)>>0);
                  //             printf("f1sub_01_05_AF106[0] = %d\n",AF206[4]);
                  //       //next word
                  //        AF206[3]=((flash_t.flashData[76] & 0xFF000000) >>24); //form flas read data 
                  //        AF206[2]=((flash_t.flashData[76] & 0x00FF0000) >> 16); //form flas read data 
                  //             printf("f1sub_01_05_AF106[3] = %d\n",AF206[2]);
                  //       AF206[1]=((flash_t.flashData[76] & 0xff00) >> 8);
                  //             printf("f1sub_01_05_AF106[2] = %d\n",AF206[21]);
                  //       AF206[0]=((flash_t.flashData[76] & 0xff) >> 0);
                  //             printf("f1sub_01_05_AF106[1] = %d\n",AF206[01]);
                  

                        
                  // }
                  Number_Digital_5bit_AddSelect(AF206);
                  flash_t.saveDataNumber_flag++;
                  flash_t.saveDataTheSecondNumber_flag++;
                  if(flash_t.saveDataNumber_flag>=1){
                        
                         f1menu_t.f2r06_reg  =(((SpecDisplay_Number(AF206[4])) <<0));
                        *(pfdata+18) = f1menu_t.f2r05_reg_next |f1menu_t.f2r06_reg;
                  }
                  if(flash_t.saveDataTheSecondNumber_flag >=1){
                  
                     *(pfdata +19) = (((SpecDisplay_Number( AF206[3]))<< 24)|((SpecDisplay_Number( AF206[2]))<< 16)  | ((SpecDisplay_Number( AF206[1]))<<8)
                                    |((SpecDisplay_Number( AF206[0]))<<0)) ;
                  }
                  
                  break;

              }


}


void F2_Dec_TheThirdMenu_KeyFunction(uint8_t f2mu3)
{
     switch(f2mu3){

                  case F201:
                       key_t.F2_0102FlashSave_flag=1;
                     Number_Digital_Set5bit_RefDecSelect(AF201,3);
                  f1menu_t.f2r01_reg = ((SpecDisplay_Number(AF201[0]))<<24);
                  *(pfdata + 14) =f1menu_t.f2r01_reg  | f1menu_t.f2r02_reg;
                 
                  break;

                  case F202:
                       key_t.F2_0102FlashSave_flag=1;
                  Number_Digital_5bit_DecSelect(AF202);
                  f1menu_t.f2r02_reg  = ((SpecDisplay_Number(AF202[4]))<<0);
                  *(pfdata + 14) =f1menu_t.f2r02_reg | f1menu_t.f2r01_reg;
                  *(pfdata+15) =(((SpecDisplay_Number( AF202[3]))<< 24)|((SpecDisplay_Number( AF202[2]))<< 16)  | ((SpecDisplay_Number( AF202[1]))<<8) 
                        |((SpecDisplay_Number( AF202[0]))<<0));
                  
                  break;

                  case F203:
                       key_t.F2_0102FlashSave_flag=1;
                        Number_Digital_5bit_DecSelect(AF203);
                         *(pfdata+16) =(((SpecDisplay_Number( AF203[4]))<< 24)|((SpecDisplay_Number( AF203[3]))<< 16)  | ((SpecDisplay_Number( AF203[2]))<<8) 
                        |((SpecDisplay_Number( AF203[01]))<<0));
                  
                   f1menu_t.f2r03_reg  = ((SpecDisplay_Number(AF203[0]))<<24);
                  *(pfdata + 17) =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg); 
                  break;

                  case F204:
                       key_t.F1_0102FlashSave_flag=1;
                        Number_Digital_Set5bit_RefDecSelect(AF204,3);
                         f1menu_t.f2r04_reg = ((SpecDisplay_Number(AF204[0]))<<16);
                           *(pfdata +17)  =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg);
                  break;

                  case F205:
                       key_t.F1_0102FlashSave_flag=1;
                        Number_Digital_5bit_DecSelect(AF205);
                   f1menu_t.f2r05_reg  =(((SpecDisplay_Number(AF205[4]))<<8)|((SpecDisplay_Number(AF205[3]))<<0));
                  
                  *(pfdata + 17) =f1menu_t.f2r04_reg |(f1menu_t.f2r03_reg ) |(f1menu_t.f2r05_reg); 
                  
                 f1menu_t.f2r05_reg_next = (((SpecDisplay_Number( AF205[2]))<< 24)|((SpecDisplay_Number( AF205[1]))<< 16)  | ((SpecDisplay_Number( AF205[0]))<<8)) ;
                  *(pfdata+18) = f1menu_t.f2r05_reg_next |f1menu_t.f2r06_reg;
                  break;

                  case F206:
                       key_t.F1_0102FlashSave_flag=1;
                        Number_Digital_5bit_DecSelect(AF206);
                         f1menu_t.f2r06_reg  =(((SpecDisplay_Number(AF206[4])) <<0));
                  *(pfdata+18)= f1menu_t.f2r05_reg_next |f1menu_t.f2r06_reg ;
                  
                   *(pfdata +19) = (((SpecDisplay_Number( AF206[3]))<< 24)|((SpecDisplay_Number( AF206[2]))<< 16)  | ((SpecDisplay_Number( AF206[1]))<<8)
                         |((SpecDisplay_Number( AF206[0]))<<0)) ;
                  break;


    }


}


