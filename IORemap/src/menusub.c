#include "menusub.h"



void StackStacksubmenu_03_Init(Stacksubmenu_03 *sm03)
{
    sm03->submenuTop_03 =-1;
}
int8_t Is_empty(Stacksubmenu_03 *sm03)
{
    if(sm03->submenuTop_03 !=-1)
	     return -1;
	else 
	   return 0;
}
int8_t Is_full(Stacksubmenu_03 *sm03)
{
    if(sm03->submenuTop_03 !=  MAX_SUB_SIZE_03 -1)
	    return -1;
	else 
	   return 0;
}
int8_t subPush_03(Stacksubmenu_03 *sm03,uint8_t dat)
{
    if(!Is_full(sm03)){
		return -1;
	}
	else{
		
		sm03->submenuTop_03++;
		sm03->subdata[sm03->submenuTop_03]=dat;
	}
	return 0;
}

int8_t subPop_03(Stacksubmenu_03 *sm03)
{
    if(!Is_empty(sm03)){
          return -1;
    }
	else{
		sm03->submenuTop_03--;
		return sm03->subdata[sm03->submenuTop_03];
	}
    
}
int8_t subTop_03(Stacksubmenu_03 *s)
{
    if(!Is_empty(s)){
        return -1;
    }
	else{
		return s->subdata[s->submenuTop_03];
	}
}

/************************************************
*
*Function Name :void TheThird_F1_03_Menu(void)
*Function :selected the be going to run cmd
*Input Refer:NO
*Return Refer:NO
*
************************************************/
void TheThird_F1_03_Menu(void)
{
     static uint8_t f1r01,f1r02,f1r03,f1r04,f1r05,f1temp;
	 static uint8_t f1r06,f1r07,f1r08,f1r09,f1r10,f1r11,f1r12;
     

     
     switch(menu_t.menu_F1Sub_03_xx_key){
				   
				   case 0: //F1-01-01
                       menu_t.F1SubMenu_Sub_02_Id =0;
                        if(f1r01 == 0) {
                        f1r01++;
                         Flash_Read();
                          menu_t.F1_Sub01_Top= ( flash_t.flashData[0] & 0xff000000) >> 24;
                        

                          printf("f1sub_00_03_flash = %d\n",menu_t.F1_Sub01_Top);
                        }
                        if(f1r01==1){ 
                        f1r01++;
                        }
                        else{
                            F1SubMenu_F101_01_Select_DIS(menu_t.F1_Sub01_Top);
                        }

                     //  printf("f1sub_01_03_Top = %d\n",menu_t.F1_Sub01_Top);
                       key_t.keyReturn_flag=1;
                      
				   break;
				   
				   case 0x01: //F1-02-01 ->
                       menu_t.F1SubMenu_Sub_02_Id =0x01;
                       menu_t.DisplaySmgBit_Select_Numbers =3;
                           if(f1r02== 0) {
                        f1r02++;
                        Flash_Read();

                        menu_t.F1_Sub02_unit=(flash_t.flashData[0] & 0xFF) >> 0; //form flas read data 
							printf("f1subRun_01_03_unit = %d\n",menu_t.unit);
                        menu_t.F1_Sub02_decade=( flash_t.flashData[0]  & 0xff00) >> 8;
							printf("f1subRun_01_03_decade = %d\n",menu_t.decade);
                        menu_t.F1_Sub02_hundred=(flash_t.flashData[0]  & 0xff0000) >> 16; 
                        printf("f1subRun_01_03_hundred = %d\n",menu_t.hundred);
                         
                        }
                        F1SubMenu_F1_02_01(menu_t.F1_Sub02_unit,menu_t.F1_Sub02_decade,menu_t.F1_Sub02_hundred);
                        
                     //  printf("f1sub_02_03_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;
                       
				   break;

                   case 0x02:
                      menu_t.F1SubMenu_Sub_02_Id =0x02;
                      menu_t.DisplaySmgBit_Select_Numbers =3;
                        if(f1r02==0){
					       f1r02++;
                             menu_t. F1_Sub03_unit=(flash_t.flashData[4] & 0xFF) >> 0; //form flas read data 
                                                printf("f1sub_01_03_unit = %d\n",menu_t.unit);
                              menu_t.F1_Sub03_decade=( flash_t.flashData[4]  & 0xff00) >> 8;
                                                printf("f1sub_01_03_decade = %d\n",menu_t.decade);
                             menu_t.F1_Sub03_hundred=(flash_t.flashData[4]  & 0xff0000) >> 16; 
                                    printf("f1sub_01_03_hundred = %d\n",menu_t.hundred);
                        }
                        else{
                            F1SubMenu_F1_02_01(menu_t. F1_Sub03_unit,menu_t.F1_Sub03_decade,menu_t.F1_Sub03_hundred);
                        }
                     //  printf("f1sub_02_03_Top = %d\n",menu_t.F1_Sub02_Top);
                        key_t.keyReturn_flag=1;

                   break;

                   case 0x03://F1-04-01
                        menu_t.F1SubMenu_Sub_02_Id =0x03;
                         menu_t.DisplaySmgBit_Select_Numbers =4;
                         if(f1r03==0){
                            f1r03++;
				            Flash_Read();
                        AF104[3]=((flash_t.flashData[8] & 0xFF000000) >> 24); //form flas read data 
                               printf("f1sub_01_03_AF104[3] = %d\n",AF104[3]);
                        AF104[2]=((flash_t.flashData[8] & 0x00ff0000) >> 16);
                                printf("f1sub_01_03_AF104[2] = %d\n",AF104[2]);
                        AF104[1]=((flash_t.flashData[8] & 0x0000ff00) >> 8);
                                      printf("f1sub_01_03_AF104[1] = %d\n",AF104[1]);
                        AF104[0]=((flash_t.flashData[8] & 0xff) >> 0);
                          printf("f1sub_01_03_AF104[0] = %d\n",AF104[0]);
                              
                              
                        }
                        F1SubMenu_F104_01_Select_DIS(AF104);
                        key_t.keyReturn_flag=1;
                   break;

                   break;

                   case 0x04://F1-05-01 
                      menu_t.F1SubMenu_Sub_02_Id =0x04;
                       key_t.keyReturn_flag=1;
                        menu_t.DisplaySmgBit_Select_Numbers =2;
                        if(f1r04==0){
                              f1r04++;
                              Flash_Read();
                              AF105[1]=((flash_t.flashData[12] & 0xFF000000) >> 24); //form flas read data 
                              AF105[0]=((flash_t.flashData[12] & 0x00ff0000) >> 16);

                        }
                        
                        F1SubMenu_F105_01_Select_DIS(AF105);

                   break;
                   case 0x05 : //F1-06-01 -->5bit
                       menu_t.F1SubMenu_Sub_02_Id =0x05;
                        menu_t.DisplaySmgBit_Select_Numbers =5;
                         if(f1r05 ==0){
                              f1r05++;
                              Flash_Read();
                              
                        AF106[4]=((flash_t.flashData[16] & 0xFF000000) >> 24); //form flas read data 
                               printf("f1sub_01_05_AF106[3] = %d\n",AF106[3]);
                        AF106[3]=((flash_t.flashData[16] & 0x00ff0000) >> 16);
                                printf("f1sub_01_05_AF106[2] = %d\n",AF106[2]);
                        AF106[2]=((flash_t.flashData[16] & 0x0000ff00) >> 8);
                                      printf("f1sub_01_05_AF106[1] = %d\n",AF106[1]);
                        AF106[1]=((flash_t.flashData[16] & 0xff) >> 0);
                          printf("f1sub_01_05_AF106[0] = %d\n",AF106[0]);
                          
                          
                        AF106[0]=(flash_t.flashData[20] & 0xff000000) >> 24;  //next word   
                               printf("f1sub_01_05_AF106[0] = %d\n",AF106[0]);
                          
                              
                        }
                        
                        F1SubMenu_F106_01_Select_DIS(AF106);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x06 : //F1-07-01 -->5bit 
                        menu_t.F1SubMenu_Sub_02_Id =0x06;
                         menu_t.DisplaySmgBit_Select_Numbers =5;
                          if(f1r06==0){
                              f1r06++;
                                Flash_Read();
                              
                        AF107[4]=((flash_t.flashData[20] & 0x00FF0000) >> 16); //form flas read data 
                               printf("f1sub_01_05_AF106[3] = %d\n",AF107[3]);
                        AF107[3]=((flash_t.flashData[20] & 0x0000ff00) >> 8);
                                printf("f1sub_01_05_AF106[2] = %d\n",AF107[2]);
                        AF107[2]=((flash_t.flashData[20] & 0xff) >> 0);
                                      printf("f1sub_01_05_AF106[1] = %d\n",AF107[1]);
                        //next words 
                        AF107[1]=((flash_t.flashData[24] & 0xff000000) >> 24);
                          printf("f1sub_01_05_AF106[0] = %d\n",AF107[0]);
                          
                          
                        AF107[0]=(flash_t.flashData[24] & 0x00ff0000) >> 16;  //next word   
                               printf("f1sub_01_05_AF106[0] = %d\n",AF107[0]);
                              
                        }
                        F1SubMenu_F106_01_Select_DIS(AF107);
                        key_t.keyReturn_flag=1;
				   break;

                  case 0x07 : //F1-08-01
                        menu_t.F1SubMenu_Sub_02_Id =0x07;
                         menu_t.DisplaySmgBit_Select_Numbers =2;
                         if(f1r07==0){
                        
                        f1r07++;
                         Flash_Read();
                         
                              
                        AF108[1]=((flash_t.flashData[28] & 0xFF000000) >> 24); //form flas read data 
                               printf("f1sub_01_05_AF106[3] = %d\n",AF108[3]);
                        AF108[0]=((flash_t.flashData[28] & 0x00ff0000) >> 16);
                                printf("f1sub_01_05_AF106[2] = %d\n",AF108[2]);
                        
                        }
                         
                         F1SubMenu_F105_01_Select_DIS(AF108);
                        key_t.keyReturn_flag=1;
				   break;

                  case 0x08 : //F1-09-01 ->4bit
                         menu_t.F1SubMenu_Sub_02_Id =0x08;
                        menu_t.DisplaySmgBit_Select_Numbers =5;
                        if(f1r08==0){
                       f1r08++; 
                       Flash_Read(); 
                        AF109[4]=((flash_t.flashData[32] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF106[3] = %d\n",AF109[3]);
                        AF109[3]=((flash_t.flashData[32] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF109[2]);
                        AF109[2]=((flash_t.flashData[32] & 0xff00) >> 8);
                        printf("f1sub_01_05_AF106[1] = %d\n",AF109[1]);
                        AF109[1]=((flash_t.flashData[32] & 0xff) >> 0);
                        printf("f1sub_01_05_AF106[0] = %d\n",AF109[0]);

                        //next word 
                        AF109[0]=(flash_t.flashData[36] & 0xff0000) >> 24;  //next word   
                        printf("f1sub_01_05_AF106[0] = %d\n",AF109[0]);
                        }
                        F1SubMenu_F109_01_Select_DIS(AF109);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x09 : //F1-10-01 -> 5bit
                        menu_t.F1SubMenu_Sub_02_Id =0x09;
                         menu_t.DisplaySmgBit_Select_Numbers =4;
                          if(f1r09==0){
                        f1r09++;
                        Flash_Read(); 
                        AF110[3]=((flash_t.flashData[40] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF106[3] = %d\n",AF110[3]);
                        AF110[2]=((flash_t.flashData[40] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF110[2]);
                        AF110[1]=((flash_t.flashData[40] & 0xff00) >> 8);
                        printf("f1sub_01_05_AF106[1] = %d\n",AF110[1]);
                        AF110[0]=((flash_t.flashData[40] & 0xff) >> 0);
                        printf("f1sub_01_05_AF106[0] = %d\n",AF110[0]);
                        
                    }
                  
                        F1SubMenu_F110_01_Select_DIS(AF110);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0A : //F1-11-01 -> 4bit
                         menu_t.F1SubMenu_Sub_02_Id =0x0A;
                          menu_t.DisplaySmgBit_Select_Numbers =1;
                        if(f1r10==0){
                        f1r10++;
                         Flash_Read(); 
                        AF111[0]=((flash_t.flashData[44] & 0xFF000000) >> 24); //form flas read data 
                        
                         }
                        F1SubMenu_F111_01_Select_DIS(AF111);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0B : //F1-12-01 -> 2bit
                        menu_t.F1SubMenu_Sub_02_Id =0x0B;
                        menu_t.DisplaySmgBit_Select_Numbers =2;
                         
                        if(f1r11==0){
                            f1r11++;
                          Flash_Read(); 
                        AF112[1]=((flash_t.flashData[48] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF112[1] = %d\n",AF112[1]);
                       AF112[0]=((flash_t.flashData[48] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF112[0]);
                        }
                         
                        F1SubMenu_F112_01_Select_DIS(AF112);
                        key_t.keyReturn_flag=1;
				   break;

                   case 0x0C : //F1-13-01
                        menu_t.F1SubMenu_Sub_02_Id =0x0C;
                         menu_t.DisplaySmgBit_Select_Numbers =2;
                       if(f1r12==0){
                       f1r12++; 
                        Flash_Read(); 
                        AF113[1]=((flash_t.flashData[52] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF106[3] = %d\n",AF113[1]);
                        AF113[0]=((flash_t.flashData[52] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF113[0]);
                        }
                
                         F1SubMenu_F112_01_Select_DIS(AF113);
                        key_t.keyReturn_flag=1;
				   break;

		}
}



void F2SubMenu_03_Item(void)
{
   
   static uint8_t f2r01,f2r02,f2r03,f2r04,f2r05,f2r06;
   
    switch(menu_t.menu_F1Sub_03_xx_key){
                 
                 case F201 : //display -> 3bit
                        menu_t.F2SubMenu_Id=F201;
                      menu_t.DisplaySmgBit_Select_Numbers =1;
                      if(f2r01==0){
                      f2r01++;
                        Flash_Read(); 
                      AF201[0] = (flash_t.flashData[56] & 0xff000000) >> 24;
                  
                  }
                    F2SubMenu_F201_01_Select_DIS(AF201);
                 break;

                 case F202 : //"5BIT" has "-"
                        menu_t.F2SubMenu_Id=F202;
                         menu_t.DisplaySmgBit_Select_Numbers =5;
                         if(f2r02==0){
                        f2r02++;
                         Flash_Read(); 
                          AF202[4]=((flash_t.flashData[56] & 0xFF) >>0); //form flas read data 
                         
                         //next Words
                         
                        AF202[3]=((flash_t.flashData[60] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF106[3] = %d\n",AF202[3]);
                        AF202[2]=((flash_t.flashData[60] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF202[2]);
                        AF202[1]=((flash_t.flashData[60] & 0xff00) >> 8);
                        printf("f1sub_01_05_AF106[1] = %d\n",AF202[1]);
                        AF202[0]=((flash_t.flashData[60] & 0xff) >> 0);
                        printf("f1sub_01_05_AF106[0] = %d\n",AF202[0]);

                        
                  }
                        F2SubMenu_F202_01_Select_DIS(AF202);
                 break;

                 case F203 : //5BIT 
                         menu_t.F2SubMenu_Id=F203;
                          menu_t.DisplaySmgBit_Select_Numbers =5;
                          if(f2r03 ==0){
                           
                           f2r03++;
                         Flash_Read(); 
                       
                         
                         AF203[4]=((flash_t.flashData[64] & 0xFF000000) >> 24); //form flas read data 
                        printf("f1sub_01_05_AF106[3] = %d\n",AF203[3]);
                        AF203[3]=((flash_t.flashData[64] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[2] = %d\n",AF203[2]);
                        AF203[2]=((flash_t.flashData[64] & 0xff00) >> 8);
                        printf("f1sub_01_05_AF106[1] = %d\n",AF203[1]);
                        AF203[1]=((flash_t.flashData[64] & 0xff) >> 0);
                        printf("f1sub_01_05_AF106[1] = %d\n",AF203[1]);
                        
                        //next  Words 
                        AF203[0]=((flash_t.flashData[68] & 0xff000000) >> 24);
                        printf("f1sub_01_05_AF106[0] = %d\n",AF203[0]);
                           
                     }
                         F2SubMenu_F203_01_Select_DIS(AF203);
                 break;

                 case F204 : //3bit
                         menu_t.F2SubMenu_Id=F204;
                        menu_t.DisplaySmgBit_Select_Numbers =1;
                        if(f2r04==0){
                        f2r04++;
                         Flash_Read(); 
                        AF204[0]=((flash_t.flashData[68] & 0x00ff0000) >> 16);
                        printf("f1sub_01_05_AF106[0] = %d\n",AF204[0]);
                        
                      }
                         F2SubMenu_F201_01_Select_DIS(AF204);//F2SubMenu_F204_01_Select_DIS(AF204);
                 break;
                
                case F205 : //"5BIT" has "-"
                        menu_t.F2SubMenu_Id=F205;
                         menu_t.DisplaySmgBit_Select_Numbers =5;
                          if(f2r05==0){
                        f2r05++;
                         Flash_Read(); 
                         
                         AF205[4]=((flash_t.flashData[68] & 0xFF00) >>8); //form flas read data 
                        
                         AF205[3]=((flash_t.flashData[68] & 0xFF) >> 0); //form flas read data 
                         
                         //next word
                              printf("f1sub_01_05_AF106[3] = %d\n",AF205[3]);
                        AF205[2]=((flash_t.flashData[72] & 0xff000000) >> 24);
                              printf("f1sub_01_05_AF106[2] = %d\n",AF205[2]);
                        AF205[1]=((flash_t.flashData[72] & 0xff0000) >> 16);
                              printf("f1sub_01_05_AF106[1] = %d\n",AF205[1]);
                        AF205[0]=((flash_t.flashData[72] & 0xff00)>>8);
                              printf("f1sub_01_05_AF106[0] = %d\n",AF205[0]);
                              
                       
                      }
                        F2SubMenu_F202_01_Select_DIS(AF205); //F2SubMenu_F205_01_Select_DIS(AF205);
                 break;

                 case F206 ://"5BIT"
                        menu_t.F2SubMenu_Id=F206;
                         menu_t.DisplaySmgBit_Select_Numbers =5;
                        if(f2r06==0){
                        f2r06++;
                         Flash_Read(); 
                         
                         AF206[4]=((flash_t.flashData[72] & 0xff)>>0);
                              printf("f1sub_01_05_AF106[0] = %d\n",AF206[4]);
                        //next word
                         AF206[3]=((flash_t.flashData[76] & 0xFF000000) >>24); //form flas read data 
                         AF206[2]=((flash_t.flashData[76] & 0x00FF0000) >> 16); //form flas read data 
                              printf("f1sub_01_05_AF106[3] = %d\n",AF206[2]);
                        AF206[1]=((flash_t.flashData[76] & 0xff00) >> 8);
                              printf("f1sub_01_05_AF106[2] = %d\n",AF206[21]);
                        AF206[0]=((flash_t.flashData[76] & 0xff) >> 0);
                              printf("f1sub_01_05_AF106[1] = %d\n",AF206[01]);
                  

                        
                  }
                        F2SubMenu_F203_01_Select_DIS(AF206);//F2SubMenu_F206_01_Select_DIS(AF206);
                 break;
                 default:

                 break;


            }
			



}

