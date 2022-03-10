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
				 f8menu_t.F8SubMenu_Id = F107;
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
		F8SubMenu_03_03_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 3:
		f8menu_t.F8_03_subMenuTop_Id = 0x03; 
		F8SubMenu_03_04_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 4:
		f8menu_t.F8_03_subMenuTop_Id = 0x04; 
		F8SubMenu_03_05_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
	break;
	
	case 5:
		f8menu_t.F8_03_subMenuTop_Id = 0x05; 
		F8SubMenu_03_06_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
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
			 SmgDisplay(digital_2,0x0f); //'-'
             SmgDisplay(digital_3,0x02); //'2'
            SmgDisplay(digital_4,0x00); //'0'
			 SmgDisplay_Character(digital_5,0x0e); //"C-"
			   

            break;

            case 1:
            SmgDisplay(digital_1,0x04); //'4'
			 SmgDisplay(digital_2,0x0f); //'-'
             SmgDisplay(digital_3,0x02); //'2'
            SmgDisplay(digital_4,0x00); //'0'
			 SmgDisplay_Character(digital_5,0x0e); //"C-"

            break;

            case 2:
            
             SmgDisplay(digital_1,0x00); //'n'
			 SmgDisplay(digital_2,0x0f); //'-'
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

    SmgDisplay(digital_1,tenthousand); // 0~100
    SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100



}
void F8SubMenu_03_04_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
    SmgDisplay(digital_1,tenthousand); // 0~100
    SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100

}
void F8SubMenu_03_05_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
    SmgDisplay(digital_1,tenthousand); // 0~100
    SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100


}
void F8SubMenu_03_06_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
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