#include "ui.h"
static void Symbol_HrL(void);
static void Symbol_ECH(void);
static void Symbol_Por(void);
static void Symbol_EEr(void);
static void Symbol_PRS(void);
static void Symbol_CnoSS(void);
static void Symbol_nEt(void);
static void Symbol_PERH(void);
static void Symbol_uRLEy(void);
static void Symbol_p_u(void);

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

static void Symbol_HrL(void)
{
   SmgDisplay_Character(digital_5,0x06); //"L" 
   SmgDisplay_Character(digital_4,0x0B); //"r"
   SmgDisplay_Character(digital_3,0x05); //"H"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

}

static void Symbol_ECH(void)
{
   SmgDisplay_Character(digital_5,0x05); //"H" 
   SmgDisplay_Character(digital_4,0x0E); //"C"
   SmgDisplay_Character(digital_3,0x03); //"E"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

}
static void Symbol_Por(void)
{
   SmgDisplay_Character(digital_5,0x0B); //"r" 
   SmgDisplay_Character(digital_4,0x08); //"O"
   SmgDisplay_Character(digital_3,0x09); //"P"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"


}
static void Symbol_EEr(void)
{
   SmgDisplay_Character(digital_5,0x0B); //"r" 
   SmgDisplay_Character(digital_4,0x03); //"E"
   SmgDisplay_Character(digital_3,0x03); //"E"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"


}
static void Symbol_PRS(void)
{
   SmgDisplay(digital_5,0x05); //"S" 
   SmgDisplay_Character(digital_4,0x10); //"R"
   SmgDisplay_Character(digital_3,0x03); //"E"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

}
static void Symbol_CnoSS(void)
{
   SmgDisplay_Character(digital_5,0x0B); //"r" 
   SmgDisplay_Character(digital_4,0x03); //"E"
   SmgDisplay_Character(digital_3,0x03); //"E"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

}
static void Symbol_nEt(void)
{
   SmgDisplay_Character(digital_5,0x0c); //"t" 
   SmgDisplay_Character(digital_4,0x03); //"E"
   SmgDisplay_Character(digital_3,0x07); //"n"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

}
static void Symbol_PERH(void)
{
   SmgDisplay_Character(digital_5,0x05); //"H" 
   SmgDisplay_Character(digital_4,0x10); //"R"
   SmgDisplay_Character(digital_3,0x03); //"E"
   SmgDisplay_Character(digital_2,0x09); //"P"
   SmgDisplay(digital_1,0x0B); // NULL//"n"
}
static void Symbol_uRLEy(void)
{
   SmgDisplay_Character(digital_5,0x05); //"Y" 
   SmgDisplay_Character(digital_4,0x10); //"E"
   SmgDisplay_Character(digital_3,0x03); //"L"
   SmgDisplay_Character(digital_2,0x09); //"R"
   SmgDisplay_Character(digital_1,0x0B); //"u"

}
static void Symbol_p_u(void)
{
   SmgDisplay_Character(digital_5,0x11); //"u" 
   SmgDisplay_Character(digital_4,0x0f); //"-"
   SmgDisplay_Character(digital_3,0x09); //"P"
   SmgDisplay(digital_2,0x0B); // NULL//"n"
   SmgDisplay(digital_1,0x0B); // NULL//"n"

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
void F2_Stacksubmenu_03(void)
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

void F1SubMenu_F104_01_Select_DIS(int8_t *p)
{
   
   SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,*(p+3)); // 0~100
   SmgDisplay_Point(digital_3,*(p+2)); // pointer "."
   SmgDisplay(digital_4,*(p+1)); // 0~100
   SmgDisplay(digital_5,*p); // 0~100
  

}

/***********************************************
*
*Smg F1-05 display  2 bit 1-5.0
*
**********************************************/
void F1SubMenu_F105_01_Select_DIS(int8_t *pA)
{
   
   SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,0x0b); // 0~100
   SmgDisplay(digital_3,0x0b); // 0~100
   SmgDisplay_Point(digital_4,*(pA+1)); // pointer "."
   SmgDisplay(digital_5,*pA); // 0~100
  

}
/***********************************************
*
*Smg F1-06 display  2 bit 0~99999
*
**********************************************/
void F1SubMenu_F106_01_Select_DIS(int8_t *pA)
{
   
   SmgDisplay(digital_1,*(pA+4)); // 0~100
   SmgDisplay(digital_2,*(pA+3)); // 0~100
   SmgDisplay(digital_3,*(pA+2)); // pointer "."
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
  

}

void F1SubMenu_F109_01_Select_DIS(int8_t *pA)
{
   SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,*(pA+3)); // 0~100
   SmgDisplay(digital_3,*(pA+2)); // 
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
   
   
}

void F1SubMenu_F110_01_Select_DIS(int8_t *pA)
{
   SmgDisplay(digital_1,*(pA+4)); // 0~100
   SmgDisplay(digital_2,*(pA+3)); // 0~100
   SmgDisplay(digital_3,*(pA+2)); // pointer "."
   SmgDisplay_Point(digital_4,*(pA+1)); // pointer "." //SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
}

 void F1SubMenu_F111_01_Select_DIS(int8_t *pA)
 {
   
   if(*pA==0){ //"10"
       SmgDisplay(digital_1,0x0b); // 0~100
      SmgDisplay(digital_2,0x0b); // 0~100
      SmgDisplay(digital_3,0x0b); // 
      SmgDisplay(digital_4,0x01); // 0~100
      SmgDisplay(digital_5,0x00); // 0~100

   }
   else if(*pA==1){ //'40'
      SmgDisplay(digital_1,0x0b); // 0~100
      SmgDisplay(digital_2,0X0B); // 0~100
      SmgDisplay(digital_3,0X0B); // 
      SmgDisplay(digital_4,0X04); // 0~100
      SmgDisplay(digital_5,0X00); // 0~100
   }
   else if(*pA==2){ //'640'
      SmgDisplay(digital_1,0x0b); // 0~100
      SmgDisplay(digital_2,0X0B); // 0~100
      SmgDisplay(digital_3,0X06); // 
      SmgDisplay(digital_4,0X04); // 0~100
      SmgDisplay(digital_5,0X00); // 0~100
   }
   else if(*pA==3){ //"1280"
      SmgDisplay(digital_1,0x0B); // 0~100
      SmgDisplay(digital_2,0X01); // 0~100
      SmgDisplay(digital_3,0X02); // 
      SmgDisplay(digital_4,0X08); // 0~100
      SmgDisplay(digital_5,0X00); // 0~100
   }
    
 }
 
 
void F1SubMenu_F112_01_Select_DIS(int8_t *pA)
{
   
   SmgDisplay(digital_1,0x0b); // 0~100
   SmgDisplay(digital_2,0x0b); // 0~100
   SmgDisplay(digital_3,0x0b); // 0~100
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
   
}
/**********************************************************
 * 
 * F2-01 /02/03/04/05/06 Sub menu 
 * 
 * 
 * 
***********************************************************/
 void F2SubMenu_F201_01_Select_DIS(int8_t *pA)
 {
      if(*pA == 0){
         F1SubMenu_Sub_01_05(); //"nonE"
      }
      else if(*pA==1){ //"HrL"
         Symbol_HrL();

      }
      else if(*pA==2){

          Symbol_ECH();
      }

 }

void F2SubMenu_F202_01_Select_DIS(int8_t *pA)
{
   SmgDisplay_Character(digital_1,0x0f); //"-"
   SmgDisplay(digital_1,*(pA+4)); // 0~100
   SmgDisplay(digital_2,*(pA+3)); // 0~100
   SmgDisplay(digital_3,*(pA+2)); // pointer "."
   SmgDisplay(digital_4,*(pA+1)); // pointer "."
   SmgDisplay(digital_5,*pA); // 0~100
   

}

void F2SubMenu_F203_01_Select_DIS(int8_t *pA)
{
    F1SubMenu_F106_01_Select_DIS(pA);

}

/*******************F3***************************************
 * 
 * F3 ITEM MENU 
 * 
 * 
 * 
 * 
************************************************************/
void F3SubMenu_01(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay_Point(digital_4,0x01); //'1.'
   SmgDisplay(digital_5,0x0B); //'NULL'

}
void F3SubMenu_02(void)
{
   SmgDisplay_Character(digital_3,0x0f); //"-"
   SmgDisplay_Point(digital_4,0x02); //'1.'
   SmgDisplay(digital_5,0x0B); //'NULL'
}
void F3SubMenu_F301_01_Select_DIS(int8_t *pA)
{
      if(*pA==0)*pA=1;
      SmgDisplay(digital_5,*pA); // 0~100
       
}
void F3SubMenu_F302_02_Select_DIS(int8_t *pA)
{
     if(*pA==0)*pA = 1;
     SmgDisplay(digital_5,*pA); // 0~100
}


/*****************F3 the furth menu*****************************/

 void F3SubMenu_F301_11_Select_DIS(int8_t *pA)
 {
      if(*pA == 0){
         F1SubMenu_Sub_01_05(); //"nonE"
      }
      else if(*pA==1){ //"Por"
         Symbol_Por();

      }
      else if(*pA==2){ //"EEr"

          Symbol_EEr();
      }

 }

 void F3SubMenu_F301_12_Select_DIS(int8_t *pA)
 {
   SmgDisplay(digital_1,0x0B); // 0~100
   SmgDisplay(digital_2,0x0B); // 0~100
   SmgDisplay(digital_3,0x0B); // pointer "."
   SmgDisplay(digital_4,0x0B); // pointer "."
   SmgDisplay(digital_5,*pA); // 0~100

 }

void F3SubMenu_F301_13_Select_DIS(int8_t *pA)
{
   
     if(*pA == 0){
         Symbol_PRS();
      }
      else if(*pA==1){ //"Por"
        Symbol_CnoSS();

      }
      else if(*pA==2){ //"EEr"
            Symbol_nEt();
      }
      else if(*pA==3){
         Symbol_PERH();
      }
      else if(*pA ==4){
         Symbol_uRLEy();
      }
      else if(*pA ==5){
         Symbol_p_u();
      }
}

void F3SubMenu_F301_14_Select_DIS(int8_t *pA)
{
    SmgDisplay(digital_1,0x0b); // null
   SmgDisplay(digital_2,0x0b); // null
   SmgDisplay(digital_3,*(pA+2)); // 0~100
   SmgDisplay_Point(digital_4,*(pA+1));  // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
}

void F3SubMenu_F301_16_Select_DIS(int8_t *pA)
{
   F2SubMenu_F202_01_Select_DIS(pA);

}



void F3SubMenu_04_Item(int8_t *pA,int8_t *pt)
{
      switch(*pA){

        case 0:

        break;

        case 1:
              F3SubMenu_F301_11_Select_DIS(pt);
        break; 

        case 2:
           F3SubMenu_F301_12_Select_DIS(pt);

        break;

        case 3:
          F3SubMenu_F301_13_Select_DIS(pt);

        break;
            
        case 4:
            F3SubMenu_F301_14_Select_DIS(pt);
        break;

        case 5:
            F2SubMenu_F202_01_Select_DIS(pt);
        break;

        case 6:
            F2SubMenu_F202_01_Select_DIS(pt);
        break;
            
        case 7:
            F2SubMenu_F202_01_Select_DIS(pt);
        break;





      }

}
 
 