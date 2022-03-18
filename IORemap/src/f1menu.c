#include "f1menu.h"

f1menunew f1menu_t;

static void F1_01_xx_SelectCmd(void);
static void Number_Digital_F111_4bit_AddSelect(int8_t *ap);
static void Number_Digital_F111_4bit_DecSelect(int8_t *ap);



void F1_MasterFunction_EnterKey(void)
{
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
                  
                  key_t.keyReturn_flag ++;
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
                  else if( key_t.keyReturn_flag ==2){  //return last menu and save data
                        
                        menu_t.menuId= F1;
                        mainitem_t.task_MainMenu=TheSecond_Menu; //OPEN the second menu
                        menu_t.FxMainMenu_key =0xB0;
                        menu_t.FxSub_03_key=0xff;  
                        menu_t.menuTitle_03=0;
                        
                        menu_t.F1_SubMenuTop=menu_t.F1SubMenu_Id;
                       printf("F1_0102FlashSave_flag_prev= %d\n", key_t.F1_0102FlashSave_flag);
                        if(key_t.F1_0102FlashSave_flag==1){
                            flash_t.flashSave_flag =1; //flash save data
                            key_t.F1_0102FlashSave_flag=0;
                            FlashSaveData();
                            printf("flash_save_________OK\n");
                            flash_t.flashSave_flag=0;
						}
                         
							key_t.keyReturn_flag =0;
                        printf("F1_0102FlashSave_flag = %d\n", key_t.F1_0102FlashSave_flag);
                        printf("f1_enterKey_retrunMenu = %d\n", menu_t.F1_SubMenuTop);
                       }
		      }



}


void F1_Add_TheThirdMenu_KeyFunction(uint8_t f1mu)
{
     

    switch(f1mu){
            case 0xf10:
                  switch(menu_t.menu_F1Sub_03_xx_key){

                  case 0x00: //F1-01-01  -8bit flash_t.pointer = 
                     key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r01 == 0) {
                        f1menu_t.f1r01++;
                         //Flash_Read();
                         // menu_t.F1_Sub01_Top   = ( flash_t.flashData[0] & 0xff000000) >> 24;
                             menuFxSub_03_Top=menu_t.F1_Sub01_Top;
                             menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                          printf("f1sub_00_03_flash = %d\n",menu_t.F1_Sub01_Top);
                        }
                        else{
                              menu_t.F1_Sub01_Top=  PushSub_03_Menu(F101_01_01);
                        }
                        
                        Flash_Data_Buffer[0] = menu_t.F1_Sub01_Top <<    24 ; //SRAM_Data_Buffer[0]= menu_t.F1_Sub01_Top
                        f1menu_t.f1r01_reg = menu_t.F1_Sub01_Top;
                        
                        
                        *pfdata =((SpecDisplay_Number(f1menu_t.f1r01_reg)<<24) | f1menu_t.f1r12_reg);
				
                        		
                                    
                                    
                        printf("f1sub_01_n_Top = %d\n",menu_t.F1_Sub01_Top);
                        key_t.keyReturn_flag=1;
                  break;

                  case 0x01: //F1-02-01 -8bit
                        key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r02== 0) {
                           f1menu_t.f1r02++;
                           //Flash_Read();

                              //menu_t.unit=(flash_t.flashData[0] & 0xFF) >> 0; //form flas read data 
                                          //      printf("f1sub_01_03_unit = %d\n",menu_t.unit);
                             // menu_t.decade=( flash_t.flashData[0]  & 0xff00) >> 8;
                                            //    printf("f1sub_01_03_decade = %d\n",menu_t.decade);
                             // menu_t.hundred=(flash_t.flashData[0]  & 0xff0000) >> 16; 
                              menu_t.unit=menu_t.F1_Sub02_unit;
                              menu_t.decade=menu_t.F1_Sub02_decade;
                              menu_t.hundred=menu_t.F1_Sub02_hundred;
                              RunDispDigital_Fun(Number_Digital_3bit_NoRefAddSelect);
                              printf("f1sub_01_03_hundred = %d\n",menu_t.hundred);
                            
                        }
                        else{

                               RunDispDigital_Fun(Number_Digital_3bit_NoRefAddSelect);

                        }
                        menu_t. F1_Sub02_unit= menu_t.unit;
                        menu_t.F1_Sub02_decade=menu_t.decade;
                        menu_t.F1_Sub02_hundred =menu_t.hundred;
                      
                             
                      f1menu_t.f1r12_reg =(((SpecDisplay_Number(menu_t.hundred ))<< 16)  | ((SpecDisplay_Number(menu_t.decade))<<8) 
						|((SpecDisplay_Number(menu_t.unit))<<0));
                     *pfdata =((SpecDisplay_Number(f1menu_t.f1r01_reg)<<24)| f1menu_t.f1r12_reg); 
                   

                        printf("f1sub_01_03_n_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;
                  break;

                  case 0x02: //F1-03-01  
                        key_t.F1_0102FlashSave_flag=1;
                          if(f1menu_t.f1r02==0){
					f1menu_t.f1r02++;

                              // menu_t.unit=(flash_t.flashData[4] & 0xFF) >> 0; //form flas read data 
                              //                   printf("f1sub_01_03_unit = %d\n",menu_t.unit);
                              // menu_t.decade=( flash_t.flashData[4]  & 0xff00) >> 8;
                              //                   printf("f1sub_01_03_decade = %d\n",menu_t.decade);
                              // menu_t.hundred=(flash_t.flashData[4]  & 0xff0000) >> 16; 
                              //       printf("f1sub_01_03_hundred = %d\n",menu_t.hundred);
                             menu_t.unit=menu_t. F1_Sub03_unit;
                             
                             menu_t.decade =menu_t.F1_Sub03_decade;
                              
                           menu_t.hundred=menu_t.F1_Sub03_hundred;
                        
                        }
                        
                        RunDispDigital_Fun(Number_Digital_3bit_NoRefAddSelect);
                              
                        menu_t. F1_Sub03_unit= menu_t.unit;
                        menu_t.F1_Sub03_decade=menu_t.decade;
                        menu_t.F1_Sub03_hundred =menu_t.hundred;
                        key_t.keyReturn_flag=1;

                          *(pfdata+1) =(((SpecDisplay_Number(menu_t.hundred ))<< 16)  | ((SpecDisplay_Number(menu_t.decade))<<8) 
						|((SpecDisplay_Number(menu_t.unit))<<0));


                  break;

                  case 0x03: //F1-04-01
                        key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r03==0){
                            f1menu_t.f1r03++;
				// Flash_Read();
                        // AF104[3]=((flash_t.flashData[8] & 0xFF000000) >> 24); //form flas read data 
                        //        printf("f1sub_01_03_AF104[3] = %d\n",AF104[3]);
                        // AF104[2]=((flash_t.flashData[8] & 0x00ff0000) >> 16);
                        //         printf("f1sub_01_03_AF104[2] = %d\n",AF104[2]);
                        // AF104[1]=((flash_t.flashData[8] & 0x0000ff00) >> 8);
                        //               printf("f1sub_01_03_AF104[1] = %d\n",AF104[1]);
                        // AF104[0]=((flash_t.flashData[8] & 0xff) >> 0);
                        //   printf("f1sub_01_03_AF104[0] = %d\n",AF104[0]);
                            
                              // AF104[3]++;
                              // AF104[2]++;
                              // AF104[1]++;
                              // AF104[0]++;
                        Number_Digital_4bit_AddSelect(AF104);
                        }
                        else
                           Number_Digital_4bit_AddSelect(AF104);
                        
                        
                        
                        *(pfdata+2) =(((SpecDisplay_Number(AF104[3]))<<24)|((SpecDisplay_Number(AF104[2] ))<< 16)  | ((SpecDisplay_Number(AF104[1]))<<8) 
						      |((SpecDisplay_Number(AF104[0]))<<0));

                  

                        key_t.keyReturn_flag=1;
                  break;

                  case 0x04://F1-05-01
                        key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r04==0){
                              f1menu_t.f1r04++;
                              // Flash_Read();
                              // AF105[1]=((flash_t.flashData[12] & 0xFF000000) >> 24); //form flas read data 
                              // AF105[0]=((flash_t.flashData[12] & 0x00ff0000) >> 16);
                                    Number_Digital_2bit_AddSelect(AF105);
                        }
                        else
                            Number_Digital_2bit_AddSelect(AF105);

                       
                        *(pfdata+3) =(((SpecDisplay_Number(AF105[1]))<<24)|((SpecDisplay_Number(AF105[0] ))<< 16));
                        printf("F1_01_05_AddKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
                        key_t.keyReturn_flag=1;
                  break;

                  case 0x05://F1-06-01
                           key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r05 ==0){
                              f1menu_t.f1r05++;
                        //       Flash_Read();
                              
                        // AF106[4]=((flash_t.flashData[16] & 0xFF000000) >> 24); //form flas read data 
                        //        printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF106[3]=((flash_t.flashData[16] & 0x00ff0000) >> 16);
                        //         printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                        // AF106[2]=((flash_t.flashData[16] & 0x0000ff00) >> 8);
                        //               printf("f1sub_01_05_AF106[1] = %d\n",AF104[1]);
                        // AF106[1]=((flash_t.flashData[16] & 0xff) >> 0);
                        //   printf("f1sub_01_05_AF106[0] = %d\n",AF104[0]);
                          
                          
                        // AF106[0]=(flash_t.flashData[20] & 0xff000000) >> 24;  //next word   
                        //        printf("f1sub_01_05_AF106[0] = %d\n",AF104[0]);
                          
                         Number_Digital_5bit_AddSelect(AF106);
                        }
                        else
                              Number_Digital_5bit_AddSelect(AF106);
                              
                  *(pfdata + 4) =(((SpecDisplay_Number(AF106[4]))<<24)|((SpecDisplay_Number(AF106[3] ))<< 16)  | ((SpecDisplay_Number(AF106[2]))<<8) 
						      |((SpecDisplay_Number(AF106[1]))<<0));
                  
                  *(pfdata + 5) =((SpecDisplay_Number(AF106[0]))<<24);

                  key_t.keyReturn_flag=1;
                  break;

            case 0x06: //F1-07-01
                  key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r06==0){
                              f1menu_t.f1r06++;
                        //         Flash_Read();
                              
                        // AF107[4]=((flash_t.flashData[20] & 0x00FF0000) >> 16); //form flas read data 
                        //        printf("f1sub_01_05_AF106[3] = %d\n",AF107[3]);
                        // AF107[3]=((flash_t.flashData[20] & 0x0000ff00) >> 8);
                        //         printf("f1sub_01_05_AF106[2] = %d\n",AF107[2]);
                        // AF107[2]=((flash_t.flashData[20] & 0xff) >> 0);
                        //               printf("f1sub_01_05_AF106[1] = %d\n",AF107[1]);
                        // //next words 
                        // AF107[1]=((flash_t.flashData[24] & 0xff000000) >> 24);
                        //   printf("f1sub_01_05_AF106[0] = %d\n",AF107[0]);
                          
                          
                        // AF107[0]=(flash_t.flashData[24] & 0x00ff0000) >> 16;  //next word   
                        //        printf("f1sub_01_05_AF106[0] = %d\n",AF107[0]);
                          Number_Digital_5bit_AddSelect(AF107);

                        }
                        else
                             Number_Digital_5bit_AddSelect(AF107);


                        *(pfdata + 5) =(((SpecDisplay_Number(AF107[4] ))<< 16)  | ((SpecDisplay_Number(AF107[3]))<<8) 
						      |((SpecDisplay_Number(AF107[2]))<<0));
                  
                         *(pfdata + 6) =(((SpecDisplay_Number(AF107[1]))<<24)|((SpecDisplay_Number(AF107[0] ))<< 16));  
                       

                        key_t.keyReturn_flag=1;
            break;

            case 0x07: //F1-08-01
                  key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r07==0){
                        
                        f1menu_t.f1r07++;
                        //  Flash_Read();
                         
                              
                        // AF108[1]=((flash_t.flashData[28] & 0xFF000000) >> 24); //form flas read data 
                        //        printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF108[0]=((flash_t.flashData[28] & 0x00ff0000) >> 16);
                        //         printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                         Number_Digital_2bit_AddSelect(AF108);
                        
                  }
                  else
                        Number_Digital_2bit_AddSelect(AF108);

                  *(pfdata + 7) =(((SpecDisplay_Number(AF108[1]))<<24)|((SpecDisplay_Number(AF108[0] ))<< 16));  

                  key_t.keyReturn_flag=1;
            break;

            case 0x08: //F1-09-01
                  key_t.F1_0102FlashSave_flag=1;
                   if(f1menu_t.f1r08==0){
                       f1menu_t.f1r08++; 
                  //      Flash_Read(); 
                  //       AF109[4]=((flash_t.flashData[32] & 0xFF000000) >> 24); //form flas read data 
                  //       printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                  //       AF109[3]=((flash_t.flashData[32] & 0x00ff0000) >> 16);
                  //       printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                  //       AF109[2]=((flash_t.flashData[32] & 0xff00) >> 8);
                  //       printf("f1sub_01_05_AF106[1] = %d\n",AF104[1]);
                  //       AF109[1]=((flash_t.flashData[32] & 0xff) >> 0);
                  //       printf("f1sub_01_05_AF106[0] = %d\n",AF104[0]);

                  //       //next word 
                  //       AF109[0]=(flash_t.flashData[36] & 0xff0000) >> 24;  //next word   
                  //       printf("f1sub_01_05_AF106[0] = %d\n",AF104[0]);

                        Number_Digital_4bit_AddSelect(AF109);

                   }
                   else
                    Number_Digital_4bit_AddSelect(AF109);


                  *(pfdata + 8) =(((SpecDisplay_Number(AF109[4]))<<24)|((SpecDisplay_Number(AF109[3] ))<< 16)  | ((SpecDisplay_Number(AF109[2]))<<8) 
						      |((SpecDisplay_Number(AF109[1]))<<0));
                  
                  *(pfdata + 9) =((SpecDisplay_Number(AF109[0]))<<24);

            break;

            case 0x09: //F1-10-01
                   key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r09==0){
                        f1menu_t.f1r09++;
                        // Flash_Read(); 
                        // AF110[3]=((flash_t.flashData[40] & 0xFF000000) >> 24); //form flas read data 
                        // printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF110[2]=((flash_t.flashData[40] & 0x00ff0000) >> 16);
                        // printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                        // AF110[1]=((flash_t.flashData[40] & 0xff00) >> 8);
                        // printf("f1sub_01_05_AF106[1] = %d\n",AF104[1]);
                        // AF110[0]=((flash_t.flashData[40] & 0xff) >> 0);
                        // printf("f1sub_01_05_AF106[0] = %d\n",AF104[0]);
                         Number_Digital_5bit_AddSelect(AF110);
                  }
                  else
                    Number_Digital_5bit_AddSelect(AF110);

            *(pfdata + 10) =(((SpecDisplay_Number(AF110[3]))<<24)|((SpecDisplay_Number(AF110[2] ))<< 16)  | ((SpecDisplay_Number(AF110[1]))<<8) 
						      |((SpecDisplay_Number(AF110[0]))<<0));
            break;

            case 0x0A://F1-11-01 ->display 4 bit
            key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r10==0){
                        f1menu_t.f1r10++;
                        //  Flash_Read(); 
                        // AF111[0]=((flash_t.flashData[44] & 0xFF000000) >> 24); //form flas read data 
                         Number_Digital_F111_4bit_AddSelect(AF111);
                  }
                  else
                      Number_Digital_F111_4bit_AddSelect(AF111);

                  *(pfdata + 11) =(((SpecDisplay_Number(AF111[0]))<<24));
						     
            break;

            case 0x0B://F1-12-01
            key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r11==0){
                        f1menu_t.f1r11++;
                          Flash_Read(); 
                        // AF112[1]=((flash_t.flashData[48] & 0xFF000000) >> 24); //form flas read data 
                        // printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF112[0]=((flash_t.flashData[48] & 0x00ff0000) >> 16);
                        // printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                         Number_Digital_2bit_AddSelect(AF112);
                        
                  }
                  else
                     Number_Digital_2bit_AddSelect(AF112);

                   *(pfdata + 12) =(((SpecDisplay_Number(AF112[1]))<<24)|((SpecDisplay_Number(AF112[0] ))<< 16));
						     
            break;

            case 0x0C://F1-13-01
            key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r12==0){
                       f1menu_t.f1r12++; 
                        // Flash_Read(); 
                        // AF113[1]=((flash_t.flashData[52] & 0xFF000000) >> 24); //form flas read data 
                        // printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF113[0]=((flash_t.flashData[52] & 0x00ff0000) >> 16);
                        // printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                         Number_Digital_2bit_AddSelect(AF113);
                  }
                  else 
                        Number_Digital_2bit_AddSelect(AF113);
                  *(pfdata + 13) =(((SpecDisplay_Number(AF113[1]))<<24)|((SpecDisplay_Number(AF113[0] ))<< 16));
                       
            break;
            }
            



}
}
void F1_Dec_TheThirdMenu_KeyFunction(uint8_t f1mu3)
{
      switch(f1mu3){

                              case 0x00:
                                 key_t.F1_0102FlashSave_flag=1;
                                   if(f1menu_t.f1r01 == 0) {
                                    f1menu_t.f1r01++;
                                    //Flash_Read();
                                    // menu_t.F1_Sub01_Top   = ( flash_t.flashData[0] & 0xff000000) >> 24;
                                    menuFxSub_03_Top=menu_t.F1_Sub01_Top;
                                    menu_t.F1_Sub01_Top=  PopSub_03_Menu(F101_01_01);
                                    printf("f1sub_00_03_flash = %d\n",menu_t.F1_Sub01_Top);
                                    }
                                    else{
                                          menu_t.F1_Sub01_Top=  PopSub_03_Menu(F101_01_01);
                                    }
                                    
                                    Flash_Data_Buffer[0] = menu_t.F1_Sub01_Top <<    24 ; //SRAM_Data_Buffer[0]= menu_t.F1_Sub01_Top
                                    f1menu_t.f1r01_reg = menu_t.F1_Sub01_Top;
                                    
                                    
                                    *pfdata =((SpecDisplay_Number(f1menu_t.f1r01_reg)<<24) | f1menu_t.f1r12_reg);
                                    
                                                
                                                
                                                
                                    printf("f1sub_01_n_Top = %d\n",menu_t.F1_Sub01_Top);
                                    key_t.keyReturn_flag=1;
                              break;

      case 0x01:
            key_t.F1_0102FlashSave_flag=1;
            if(f1menu_t.f1r02== 0) {
            f1menu_t.f1r02++;
            //Flash_Read();

            //menu_t.unit=(flash_t.flashData[0] & 0xFF) >> 0; //form flas read data 
            //      printf("f1sub_01_03_unit = %d\n",menu_t.unit);
            // menu_t.decade=( flash_t.flashData[0]  & 0xff00) >> 8;
            //    printf("f1sub_01_03_decade = %d\n",menu_t.decade);
            // menu_t.hundred=(flash_t.flashData[0]  & 0xff0000) >> 16; 
            menu_t.unit=menu_t.F1_Sub02_unit;
            menu_t.decade=menu_t.F1_Sub02_decade;
            menu_t.hundred=menu_t.F1_Sub02_hundred;
            RunDispDigital_Fun(Number_Digital_3bit_NoRefDecSelect);
            printf("f1sub_01_03_hundred = %d\n",menu_t.hundred);

            }
            else{

            RunDispDigital_Fun(Number_Digital_3bit_NoRefDecSelect);

            }
            menu_t. F1_Sub02_unit= menu_t.unit;
            menu_t.F1_Sub02_decade=menu_t.decade;
            menu_t.F1_Sub02_hundred =menu_t.hundred;


            f1menu_t.f1r12_reg =(((SpecDisplay_Number(menu_t.hundred ))<< 16)  | ((SpecDisplay_Number(menu_t.decade))<<8) 
            |((SpecDisplay_Number(menu_t.unit))<<0));
            *pfdata =((SpecDisplay_Number(f1menu_t.f1r01_reg)<<24)| f1menu_t.f1r12_reg); 


            printf("f1sub_01_03_n_Top = %d\n",menu_t.F1_Sub02_Top);
            key_t.keyReturn_flag=1;
      break;

      case 0x02:
            key_t.F1_0102FlashSave_flag=1;
            if(f1menu_t.f1r02==0){
            f1menu_t.f1r02++;

            // menu_t.unit=(flash_t.flashData[4] & 0xFF) >> 0; //form flas read data 
            //                   printf("f1sub_01_03_unit = %d\n",menu_t.unit);
            // menu_t.decade=( flash_t.flashData[4]  & 0xff00) >> 8;
            //                   printf("f1sub_01_03_decade = %d\n",menu_t.decade);
            // menu_t.hundred=(flash_t.flashData[4]  & 0xff0000) >> 16; 
            //       printf("f1sub_01_03_hundred = %d\n",menu_t.hundred);
            menu_t.unit=menu_t. F1_Sub03_unit;

            menu_t.decade =menu_t.F1_Sub03_decade;

            menu_t.hundred=menu_t.F1_Sub03_hundred;

            }

            RunDispDigital_Fun(Number_Digital_3bit_NoRefDecSelect);

            menu_t. F1_Sub03_unit= menu_t.unit;
            menu_t.F1_Sub03_decade=menu_t.decade;
            menu_t.F1_Sub03_hundred =menu_t.hundred;
            key_t.keyReturn_flag=1;

            *(pfdata+1) =(((SpecDisplay_Number(menu_t.hundred ))<< 16)  | ((SpecDisplay_Number(menu_t.decade))<<8) 
            |((SpecDisplay_Number(menu_t.unit))<<0));

      break;

      case 0x03: //F1-04-01
            key_t.F1_0102FlashSave_flag=1;
            if(f1menu_t.f1r03==0){
            f1menu_t.f1r03++;
           
             Number_Digital_4bit_DecSelect(AF104);
            }
            else
              Number_Digital_4bit_DecSelect(AF104);



            *(pfdata+2) =(((SpecDisplay_Number(AF104[3]))<<24)|((SpecDisplay_Number(AF104[2] ))<< 16)  | ((SpecDisplay_Number(AF104[1]))<<8) 
            |((SpecDisplay_Number(AF104[0]))<<0));



            key_t.keyReturn_flag=1;
      break;

      case 0x04: //F1-05-01
             key_t.F1_0102FlashSave_flag=1;
            if(f1menu_t.f1r04==0){
                  f1menu_t.f1r04++;
            // Flash_Read();
            // AF105[1]=((flash_t.flashData[12] & 0xFF000000) >> 24); //form flas read data 
            // AF105[0]=((flash_t.flashData[12] & 0x00ff0000) >> 16);
                  Number_Digital_2bit_DecSelect(AF105);
            }
            else
                   Number_Digital_2bit_DecSelect(AF105);


            *(pfdata+3) =(((SpecDisplay_Number(AF105[1]))<<24)|((SpecDisplay_Number(AF105[0] ))<< 16));
            printf("F1_01_05_AddKey = %d\n",menu_t.menu_F1Sub_03_xx_key);
            key_t.keyReturn_flag=1;
      break;

            case 0x05: //F1-06-01 --5bit
                   key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r05 ==0){
                              f1menu_t.f1r05++;
                    
                              Number_Digital_5bit_DecSelect(AF106);
                        }
                        else
                              Number_Digital_5bit_DecSelect(AF106);
                              
                  *(pfdata + 4) =(((SpecDisplay_Number(AF106[4]))<<24)|((SpecDisplay_Number(AF106[3] ))<< 16)  | ((SpecDisplay_Number(AF106[2]))<<8) 
						      |((SpecDisplay_Number(AF106[1]))<<0));
                  
                  *(pfdata + 5) =((SpecDisplay_Number(AF106[0]))<<24);

                  key_t.keyReturn_flag=1;
            break;

            case 0x06: //F1-07-01
           key_t.F1_0102FlashSave_flag=1;
                        if(f1menu_t.f1r05==0){
                              f1menu_t.f1r05++;
                     
                          Number_Digital_5bit_DecSelect(AF107);

                        }
                        else
                             Number_Digital_5bit_DecSelect(AF107);


                        *(pfdata + 5) =(((SpecDisplay_Number(AF107[4] ))<< 16)  | ((SpecDisplay_Number(AF107[3]))<<8) 
						      |((SpecDisplay_Number(AF107[2]))<<0));
                  
                         *(pfdata + 6) =(((SpecDisplay_Number(AF107[1]))<<24)|((SpecDisplay_Number(AF107[0] ))<< 16));  
                       

                        key_t.keyReturn_flag=1;
            break;

            case 0x07://F1-08-01
             key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r05==0){
                        
                        f1menu_t.f1r05++;
                        //  Flash_Read();
                         
                              
                        // AF108[1]=((flash_t.flashData[28] & 0xFF000000) >> 24); //form flas read data 
                        //        printf("f1sub_01_05_AF106[3] = %d\n",AF104[3]);
                        // AF108[0]=((flash_t.flashData[28] & 0x00ff0000) >> 16);
                        //         printf("f1sub_01_05_AF106[2] = %d\n",AF104[2]);
                        Number_Digital_2bit_DecSelect(AF108);
                        
                  }
                  else
                       Number_Digital_2bit_DecSelect(AF108);

                  *(pfdata + 7) =(((SpecDisplay_Number(AF108[1]))<<24)|((SpecDisplay_Number(AF108[0] ))<< 16));  

                  key_t.keyReturn_flag=1;
            
            key_t.keyReturn_flag=1;
            break;

            case 0x08://F1-09-01
             key_t.F1_0102FlashSave_flag=1;
                   if(f1menu_t.f1r08==0){
                       f1menu_t.f1r08++; 
                        Number_Digital_4bit_DecSelect(AF109);

                   }
                   else
                   Number_Digital_4bit_DecSelect(AF109);


                  *(pfdata + 8) =(((SpecDisplay_Number(AF109[4]))<<24)|((SpecDisplay_Number(AF109[3] ))<< 16)  | ((SpecDisplay_Number(AF109[2]))<<8) 
						      |((SpecDisplay_Number(AF109[1]))<<0));
                  
                  *(pfdata + 9) =((SpecDisplay_Number(AF109[0]))<<24);

            
            key_t.keyReturn_flag=1;
            break;

            case 0x09://F1-10-01
             key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r09==0){
                        f1menu_t.f1r09++;
                        
                         Number_Digital_5bit_DecSelect(AF110);
                  }
                  else
                    Number_Digital_5bit_DecSelect(AF110);

            *(pfdata + 10) =(((SpecDisplay_Number(AF110[3]))<<24)|((SpecDisplay_Number(AF110[2] ))<< 16)  | ((SpecDisplay_Number(AF110[1]))<<8) 
						      |((SpecDisplay_Number(AF110[0]))<<0));
           
            key_t.keyReturn_flag=1;
            break;

            case 0x0A://F1-11-01
             key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r10==0){
                        f1menu_t.f1r10++;
                        //  Flash_Read(); 
                        // AF111[0]=((flash_t.flashData[44] & 0xFF000000) >> 24); //form flas read data 
                         Number_Digital_F111_4bit_DecSelect(AF111);
                  }
                  else
                      Number_Digital_F111_4bit_DecSelect(AF111);

                  *(pfdata + 11) =(((SpecDisplay_Number(AF111[0]))<<24));
						     
          
            key_t.keyReturn_flag=1;
            break;

            case 0x0B: //F1-12-01
            key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r11==0){
                        f1menu_t.f1r11++;
                          Flash_Read(); 
                         Number_Digital_2bit_DecSelect(AF112);
                        
                  }
                  else
                     Number_Digital_2bit_DecSelect(AF112);

                   *(pfdata + 12) =(((SpecDisplay_Number(AF112[1]))<<24)|((SpecDisplay_Number(AF112[0] ))<< 16));
           
            key_t.keyReturn_flag=1;
            break;

            case 0x0C:
              key_t.F1_0102FlashSave_flag=1;
                  if(f1menu_t.f1r12==0){
                       f1menu_t.f1r12++; 
                        Number_Digital_2bit_DecSelect(AF113);
                  }
                  else 
                        Number_Digital_2bit_DecSelect(AF113);
                  *(pfdata + 13) =(((SpecDisplay_Number(AF113[1]))<<24)|((SpecDisplay_Number(AF113[0] ))<< 16));
       
            key_t.keyReturn_flag=1;
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
