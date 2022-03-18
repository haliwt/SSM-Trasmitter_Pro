#include "f7menu.h"
 F7menu f7menu_t;
static void F7SubMenu_03_01_Dis(uint8_t mu);
static void F7SubMenu_03_02_Dis(uint8_t mu);
static void F7SubMenu_03_03_Dis(int8_t unit,int8_t decade,int8_t hundred);
static void F7SubMenu_03_04_Dis(uint8_t mu);
static void F7SubMenu_03_05_Dis(int8_t unit,int8_t decade,int8_t hundred);
static void F7SubMenu_03_06_Dis(uint8_t mu);
static void F7SubMenu_03_07_Dis(uint8_t mu);

void F7_MasterFunction_EnterKey(void)
{
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


}
/*********F7-01************/
void F7SubMenu_02_DIS(uint8_t f7m2)
{  
	switch(f7m2){
	
	       case F101:
			    f7menu_t.F7SubMenu_Id = F101;
				F1SubMenu_01(); //"F1 - 01"
			break;

			case F102:
			  f7menu_t.F7SubMenu_Id = F102;
			   
				 F1SubMenu_02(); //"F1-02"
			break;
			
			case F103://
			   f7menu_t.F7SubMenu_Id = F103;
				 F1SubMenu_03();
			break;
				
			case F104:
				f7menu_t.F7SubMenu_Id = F104;
				F1SubMenu_04();
			break;

			case F105:
				f7menu_t.F7SubMenu_Id = F105;
				F1SubMenu_05();
			break;
				
			case F106:
				f7menu_t.F7SubMenu_Id = F106;
				F1SubMenu_06();
			break;

			case F107:
				f7menu_t.F7SubMenu_Id = F107;
				 F1SubMenu_07();
			break;
	
	 

  }



}

void F7SubMenu_03_DIS(uint8_t f7mu)
{
     switch(f7mu){
	 
	
	
	case 0:
	     f7menu_t.F7_theThird_sub_Id =0x0;
		  F7SubMenu_03_01_Dis(f7menu_t.F7_03_00_Id);
		  printf("f703_dis = %d\n",f7menu_t.F7_03_00_Id);
	break;
		  
	case 1:
	    f7menu_t.F7_theThird_sub_Id =0x1;
		F7SubMenu_03_02_Dis(f7menu_t.F7_03_01_Id);
	break;
	
	case 2:
	    f7menu_t.F7_theThird_sub_Id =0x2;
		F7SubMenu_03_03_Dis(f7menu_t.unit,f7menu_t.decade,f7menu_t.hundred);
	break;
	
	case 3:
	    f7menu_t.F7_theThird_sub_Id =0x3;
		F7SubMenu_03_04_Dis(f7menu_t.F7_03_03_Id);
	break;
	
	case 4:
		f7menu_t.F7_theThird_sub_Id =0x04;
		F7SubMenu_03_05_Dis(f7menu_t.unit,f7menu_t.decade,f7menu_t.hundred);
	break;
	
	case 5:
		f7menu_t.F7_theThird_sub_Id =0x05;
		F7SubMenu_03_06_Dis(f7menu_t.F7_03_05_Id);
	break;
	
	case 6:
		f7menu_t.F7_theThird_sub_Id =0x06;
		F7SubMenu_03_07_Dis(f7menu_t.F7_03_07_Id);
	break;



	
	 
	 
	 }
}


static void F7SubMenu_03_01_Dis(uint8_t mu)
{

    switch(mu){
	
		case 0:
			 
			 SmgDisplay(digital_1,0x0b); //null
			 SmgDisplay(digital_2,0x0b); //null
			 SmgDisplay_Character(digital_3,0x04); //"F"
			 SmgDisplay_Character(digital_4,0x0b); //"r"
			 SmgDisplay_Character(digital_5,0x03); //"E"

			
		break;
		
		case 1:
		     SmgDisplay(digital_1,0x0b); //null
			 SmgDisplay(digital_2,0x0b); //null
			 SmgDisplay_Character(digital_3,0x0b); //"r"
			 SmgDisplay_Character(digital_4,0x0c); //"t"
			 SmgDisplay_Character(digital_5,0x11); //"u"
			
		break;
	
	}

}

void F7SubMenu_03_02_Dis(uint8_t mu)
{
        switch(mu){
		
		case 0:
		        SmgDisplay(digital_1,0x0b);//'NULL'
				SmgDisplay(digital_2,0x01);//'1'
				SmgDisplay(digital_3,0x2);//'2'
				SmgDisplay(digital_4,0x0);//'0'
				SmgDisplay(digital_5,0x0); //'0'

		break;

		case 1:
				 SmgDisplay(digital_1,0x0b);//'NULL'
				SmgDisplay(digital_2,0x02);//'2'
				SmgDisplay(digital_3,0x4);//'4'
				SmgDisplay(digital_4,0x0);//'0'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 2:
				 SmgDisplay(digital_1,0x0b);//'NULL'
				SmgDisplay(digital_2,0x04);//'4'
				SmgDisplay(digital_3,0x8);//'8'
				SmgDisplay(digital_4,0x0);//'0'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 3:
			 SmgDisplay(digital_1,0x0b);//'NULL'
				SmgDisplay(digital_2,0x09);//'NULL'
				SmgDisplay(digital_3,0x6);//'NULL'
				SmgDisplay(digital_4,0x0);//'NULL'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 4:
			 SmgDisplay(digital_1,0x01);//'NULL'
				SmgDisplay(digital_2,0x09);//'NULL'
				SmgDisplay(digital_3,0x2);//'NULL'
				SmgDisplay(digital_4,0x0);//'NULL'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 5:
				 SmgDisplay(digital_1,0x03);//'NULL'
				SmgDisplay(digital_2,0x08);//'NULL'
				SmgDisplay(digital_3,0x4);//'NULL'
				SmgDisplay(digital_4,0x0);//'NULL'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 6:
				 SmgDisplay(digital_1,0x05);//'NULL'
				SmgDisplay(digital_2,0x07);//'NULL'
				SmgDisplay(digital_3,0x6);//'NULL'
				SmgDisplay(digital_4,0x0);//'NULL'
				SmgDisplay(digital_5,0x0); //'0'
		break;

		case 7:
			    SmgDisplay(digital_1,0x01);//'NULL'
				SmgDisplay(digital_2,0x01);//'NULL'
				SmgDisplay(digital_3,0x5);//'NULL'
				SmgDisplay(digital_4,0x2);//'NULL'
				SmgDisplay(digital_5,0x0); //'0'

		break;

	}

}


static void F7SubMenu_03_03_Dis(int8_t unit,int8_t decade,int8_t hundred)
{

       
    SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,0x0b); // 0~100
   SmgDisplay(digital_3,hundred); // 0~100
   SmgDisplay(digital_4,decade); // 0~100
   SmgDisplay(digital_5,unit); // 0~100


}

void F7SubMenu_03_04_Dis(uint8_t mu)
{
      
     switch(mu){
		
		case 0:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X07); // 7
			 SmgDisplay_Character(digital_4,0x03); // E
			SmgDisplay(digital_5,0X01); //1
		break;

			case 1:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X07); // 7
			 SmgDisplay_Character(digital_4,0x08); // O
			SmgDisplay(digital_5,0X01); //1
		break;


        case 2:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X07); // 7
			 SmgDisplay_Character(digital_4,0x07); // n
			SmgDisplay(digital_5,0X02); //2
		break;

			case 3:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X08); // 8
			 SmgDisplay_Character(digital_4,0x03); // E
			SmgDisplay(digital_5,0X01); //1
		break;

			case 4:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X08); // 8
			 SmgDisplay_Character(digital_4,0x08); // o
			SmgDisplay(digital_5,0X01); //1
		break;

			case 5:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X07); // 8
			 SmgDisplay_Character(digital_4,0x07); // n
			SmgDisplay(digital_5,0X01); //1
		break;

			case 6:

			SmgDisplay(digital_1,0x0b); // null
			SmgDisplay(digital_2,0x0b); // null
			SmgDisplay(digital_3,0X08); // 8
			 SmgDisplay_Character(digital_4,0x07); // n
			SmgDisplay(digital_5,0X02); //1
		break;
   }
}



static void F7SubMenu_03_05_Dis(int8_t unit,int8_t decade,int8_t hundred)
{

       
    SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,0x0b); // 0~100
   SmgDisplay(digital_3,hundred); // 0~100
   SmgDisplay(digital_4,decade); // 0~100
   SmgDisplay(digital_5,unit); // 0~100


}

static void F7SubMenu_03_06_Dis(uint8_t mu)
{

    switch(mu){

     case 0: //oFF
             
			 SmgDisplay(digital_1,0x0B); //
			 SmgDisplay(digital_2,0x0B); //"u"
             SmgDisplay_Character(digital_3,0x08); //"o"
			 SmgDisplay_Character(digital_4,0x04); //"F"
			 SmgDisplay_Character(digital_5,0x4); //"F"
   break;

   case 1: //on
		      SmgDisplay(digital_1,0x0B); //
			 SmgDisplay(digital_2,0x0B); //"u"
			 SmgDisplay(digital_3,0x0B); //"u"
         
			 SmgDisplay_Character(digital_4,0x08); //"o"
			 SmgDisplay_Character(digital_5,0x7); //"n"

   break;

  
	}
}

static void F7SubMenu_03_07_Dis(uint8_t mu)
{
     uint8_t i;
	switch(mu){
	 
	     case 0:
			 
		   i++;
		 break;
		 
		 
		 default:
			 
		 break;
	 
	 
	 
	 }
		 



}

void F7_Add_TheThirdMenu_KeyFunction(uint8_t f7mu)
{

	switch(f7mu){
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
}

void F7_Dec_TheThirdMenu_KeyFunction(uint8_t f7mu3)
{
   switch(f7mu3){
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
}

