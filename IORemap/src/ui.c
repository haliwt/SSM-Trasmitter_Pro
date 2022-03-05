#include "ui.h"


void DisplayMode_Normal(void)
{
   SmgDisplay(digital_1,0x0b);//'NULL'
   SmgDisplay(digital_2,0x0b);//'NULL'
   SmgDisplay(digital_3,0x0b);//'NULL'
   SmgDisplay(digital_4,0x0b);//'NULL'
   SmgDisplay(digital_5,0x00); //'0'

}


void Menu_F1(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x01);//'1'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);
   
}

void Menu_F2(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x02); //'2'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);
   

}

void Menu_F3(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x03); //'3'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);
  

}
void Menu_F7(void)
{
    SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x07); //'7'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);


}
void Menu_F8(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x08); //'8'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);
   
}
void Menu_F9(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x09); //'9'
   SmgDisplay(digital_3,0x0b);
   SmgDisplay(digital_4,0x0b);
   SmgDisplay(digital_5,0x0b);
  

}
/***********************************************************
 * 
 * Function Name: void F1SubMenu_01(void)
 * Function: display nixie tube 
 * 
 * 
***********************************************************/
void F1_DIS(void)
{
 SmgDisplay_Character(digital_1,0x04); //"F"
 SmgDisplay(digital_2,0x01);//'1'

}
void F1SubMenu_01(void)
{
  // SmgDisplay_Character(digital_1,0x04); //"F"
  // SmgDisplay(digital_2,0x01);//'1'
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x01); //'1'
}
void F1SubMenu_02(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x02); //'2'

}
void F1SubMenu_03(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x03); //'3'
}
void F1SubMenu_04(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x04); //'4'
}
void F1SubMenu_05(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x05); //'5'
}
void F1SubMenu_06(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x06); //'6'
}
void F1SubMenu_07(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x07); //'7'
}
void F1SubMenu_08(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x08); //'8'
}
void F1SubMenu_09(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x09); //'9'
}
void F1SubMenu_10(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x01); //'0'
   SmgDisplay(digital_5,0x00); //'10'
}
void F1SubMenu_11(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x01); //'0'
   SmgDisplay(digital_5,0x01); //'11'
}
void F1SubMenu_12(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x01); //'0'
   SmgDisplay(digital_5,0x02); //'12'
}
void F1SubMenu_13(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x01); //'0'
   SmgDisplay(digital_5,0x03); //'13'
}
/***********************************************************
 * 
 * Function Name: void F1_SubMenu_Sub_01(void)
 * Function: The third menu display nixie tube 
 * 
 * 
***********************************************************/
void F1SubMenu_Sub_01_01(void)
{
    SmgDisplay(digital_5,0x09); //"9"
    SmgDisplay(digital_4,0x0B); // NULL
    SmgDisplay(digital_3,0x0B); // NULL
    SmgDisplay(digital_2,0x0B); // NULL
    SmgDisplay(digital_1,0x0B); // NULL
}
void F1SubMenu_Sub_01_02(void)
{
    
    SmgDisplay(digital_5,0x09); //"9"
    SmgDisplay_Character(digital_4,0x05); //"H"

    SmgDisplay(digital_3,0x0B); // NULL
    SmgDisplay(digital_2,0x0B); // NULL
    SmgDisplay(digital_1,0x0B); // NULL
}
void F1SubMenu_Sub_01_03(void)
{
      SmgDisplay_Character(digital_5,0x0c); //"t" 
     
      SmgDisplay(digital_4,0x0B); // NULL
      SmgDisplay(digital_3,0x0B); // NULL
      SmgDisplay(digital_2,0x0B); // NULL
      SmgDisplay(digital_1,0x0B); // NULL
}
void F1SubMenu_Sub_01_04(void)
{
   SmgDisplay_Character(digital_5,0x07); //"n" 
   
    SmgDisplay(digital_4,0x0B); // NULL
    SmgDisplay(digital_3,0x0B); // NULL
    SmgDisplay(digital_2,0x0B); // NULL
    SmgDisplay(digital_1,0x0B); // NULL

}
void F1SubMenu_Sub_01_05(void)
{
   SmgDisplay_Character(digital_5,0x03); //"E" 
   SmgDisplay_Character(digital_4,0x07); //"n"
   SmgDisplay_Character(digital_3,0x08); //"0"
   SmgDisplay_Character(digital_2,0x07); //"n"
   SmgDisplay(digital_1,0x0B); // NULL
   
}
/***********************************************************
 * 
 * Function Name: void F1SubMenu_Sub_02(void)
 * Function: the third menu display nixie tube 
 * 
 * 
***********************************************************/
void F1SubMenu_F1_02_01(int8_t unit,int8_t decade,int8_t hundred)
{
   
   SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,0x0b); // 0~100
   SmgDisplay(digital_3,hundred); // 0~100
   SmgDisplay(digital_4,decade); // 0~100
   SmgDisplay(digital_5,unit); // 0~100
 

}

/***********************************************************
 * 
 * Function Name: void F1SubMenu_Sub_03(void)
 * Function: the third menu display nixie tube 
 * 
 * 
***********************************************************/
void F1SubMenu_Sub_03(void)
{

}
void F1SubMenu_Sub_04(void)
{

}
void F1SubMenu_Sub_05(void)
{

}
void F1SubMenu_Sub_06(void)
{

}
void F1SubMenu_Sub_07(void)
{

}
void F1SubMenu_Sub_08(void)
{

}
void F1SubMenu_Sub_09(void)
{

}
void F1SubMenu_Sub_10(void)
{

}
void F1SubMenu_Sub_11(void)
{

}
void F1SubMenu_Sub_12(void)
{

}
void F1SubMenu_Sub_13(void)
{

}
/***********************************************************
 * 
 * Function Name: void F2_SubMenu_01(void)
 * Function: display nixie tube 
 * 
 * 
***********************************************************/
void F2_SubMenu_01(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x01); //'1'
   SmgDisplay(digital_5,0x01); //'1'

}
void F2_SubMenu_02(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x02); //'2'
}
void F2_SubMenu_03(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x03); //'3'
}
void F2_SubMenu_04(void)
{
    SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x04); //'4'
}
void F2_SubMenu_05(void)
{
    SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x05); //'4'
}
void F2_SubMenu_06(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay(digital_4,0x00); //'0'
   SmgDisplay(digital_5,0x06); //'4'
}

void F2SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x02); //'2'
  

}

void F3SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x03); //'3'
  

}

void F7SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x07); //'7'


}

void F8SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x08); //'8'
   

}

void F9SubMenu_Master_01(void)
{
   SmgDisplay_Character(digital_1,0x04); //"F"
   SmgDisplay(digital_2,0x09); //'9'
  

}
