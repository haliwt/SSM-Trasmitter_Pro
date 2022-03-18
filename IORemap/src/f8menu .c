#include "f8menu.h"

F8menu f8menu_t;

static void F8SubMenu_03_01_Dis(uint8_t mu);
static void F8SubMenu_03_02_Dis(uint8_t mu);
static void F8SubMenu_03_03_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
static void F8SubMenu_03_04_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
static void F8SubMenu_03_05_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
static void F8SubMenu_03_06_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
static void F8SubMenu_03_07_Dis(uint8_t mu);
static void F8SubMenu_03_08_Dis(uint8_t mu);

void F8_MasterFunction_EnterKey(void)
{

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



}

void F8SubMenu_02_DIS(uint8_t mu)
{
	switch(mu){
    
    case F101:
			    f8menu_t.F8SubMenu_Id = F101;
				F1SubMenu_01(); //"F1 - 01"
			break;

			case F102:
			  //  F2SubMenu_Master_01();
			     f8menu_t.F8SubMenu_Id = F102;
				 F1SubMenu_02(); //"F1-02"
			break;
			
			case F103://
			     f8menu_t.F8SubMenu_Id = F103;
				 F1SubMenu_03();
			break;
				
			case F104:
				 f8menu_t.F8SubMenu_Id = F104;
				F1SubMenu_04();
			break;

			case F105:
				 f8menu_t.F8SubMenu_Id = F105;
				F1SubMenu_05();
			break;
				
			case F106:
				 f8menu_t.F8SubMenu_Id = F106;
				F1SubMenu_06();
			break;

			case F107:
				 f8menu_t.F8SubMenu_Id = F107;
				 F1SubMenu_07();
			break;

            case F108:
				 f8menu_t.F8SubMenu_Id = F108;
				 F1SubMenu_08();
			break;

    }
}

void F8SubMenu_03_DIS(uint8_t mu)
{
    switch(mu){
	 
	
	
	case 0:
		f8menu_t.F8_03_subMenuTop_Id = 0x00;  
		F8SubMenu_03_01_Dis(f8menu_t.F8_03_01_Id);
		   
	break;
		  
	case 1:
		f8menu_t.F8_03_subMenuTop_Id = 0x01; 
		F8SubMenu_03_02_Dis(f8menu_t.F8_03_02_Id);
	break;
	
	case 2:
		f8menu_t.F8_03_subMenuTop_Id = 0x02;
		 menu_t.DisplaySmgBit_Select_Numbers =5;
		F8SubMenu_03_03_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 3:
		f8menu_t.F8_03_subMenuTop_Id = 0x03; 
		 menu_t.DisplaySmgBit_Select_Numbers =5;
		F8SubMenu_03_03_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 4:
		f8menu_t.F8_03_subMenuTop_Id = 0x04;
		 menu_t.DisplaySmgBit_Select_Numbers =5;
		F8SubMenu_03_04_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 5:
		f8menu_t.F8_03_subMenuTop_Id = 0x05; 
		 menu_t.DisplaySmgBit_Select_Numbers =5;
		F8SubMenu_03_04_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 6:
		f8menu_t.F8_03_subMenuTop_Id = 0x06; 
		F8SubMenu_03_07_Dis(f8menu_t.F8_03_07_Id);
	break;
	case 7:
		f8menu_t.F8_03_subMenuTop_Id = 0x07; 
		F8SubMenu_03_08_Dis(f8menu_t.F8_03_08_Id);
	break;


}
}

 static void F8SubMenu_03_01_Dis(uint8_t mu)
 {
        switch(mu){

            case  0:

             SmgDisplay(digital_1,0x00); //'0'
			 SmgDisplay_Character(digital_2,0x0f); //'-'
             SmgDisplay(digital_3,0x02); //'2'
            SmgDisplay(digital_4,0x00); //'0'
			 SmgDisplay_Character(digital_5,0x0e); //"C-"
			   

            break;

            case 1:
            SmgDisplay(digital_1,0x04); //'4'
			 SmgDisplay_Character(digital_2,0x0f); //'-'
             SmgDisplay(digital_3,0x02); //'2'
            SmgDisplay(digital_4,0x00); //'0'
			 SmgDisplay_Character(digital_5,0x0e); //"C-"

            break;

            case 2:
            
             SmgDisplay_Character(digital_1,0x07); //'n'
			 SmgDisplay_Character(digital_2,0x0f); //'-'
             SmgDisplay(digital_3,0x01); //'1'
            SmgDisplay(digital_4,0x00); //'0'
			 SmgDisplay_Character(digital_5,0x11); //"u"

            break;

        }

}

void F8SubMenu_03_02_Dis(uint8_t mu)
{
     F8SubMenu_03_02_StandDis(mu);

}



void F8SubMenu_03_03_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
      if(tenthousand == 10 || tenthousand == -1){
           SmgDisplay_Character(digital_1,0x0f);
	}
	else 
	      SmgDisplay(digital_1,tenthousand); // 0~100
    SmgDisplay_Point(digital_2,onethousand);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100

}

//MSB has symbol "-"
void F8SubMenu_03_04_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
    
	  if(tenthousand == 10 || tenthousand == -1){
           SmgDisplay_Character(digital_1,0x0f);
	}
	else 
	      SmgDisplay(digital_1,tenthousand); // 0~100
	
    SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100

}


void F8SubMenu_03_07_Dis(uint8_t um)
{
       
	 if(um==0)
	     SmgDisplay_Character(digital_1,0x06); //'L'
	 else if(um==1)
	     SmgDisplay_Character(digital_1,0x07); //'n' 
	 else if(um==2)
	    SmgDisplay(digital_1,0x05); //'S' 
     SmgDisplay(digital_3,0x0b); //'null'
     SmgDisplay_Character(digital_4,0x00); //'A'
	 SmgDisplay_Character(digital_5,0x2); //"d"
}

void F8SubMenu_03_08_Dis(uint8_t um)
{
     if(um==0)
	     SmgDisplay_Character(digital_1,0x07); //'n'
	 else if(um==1)
	     SmgDisplay_Character(digital_1,0x06); //'L' 
	 else if(um==2)
	    SmgDisplay(digital_1,0x05); //'S' 
	 SmgDisplay(digital_2,0x02); //'1'
     SmgDisplay(digital_3,0x0b); //'null'
     SmgDisplay_Character(digital_4,0x00); //'A'
	 SmgDisplay_Character(digital_5,0x2); //"d"

}


void F8_Add_TheThirdMenu_KeyFunction(uint8_t f8mu)
{

	  switch(f8mu){

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

}

void F8_Dec_TheThirdMenu_KeyFunction(uint8_t f8mu3)
{
	switch(f8mu3){

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


}