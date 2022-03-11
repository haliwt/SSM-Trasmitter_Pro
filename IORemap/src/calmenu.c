#include "calmenu.h"

cali cali_t;
 int8_t caliMainTop =-1  ;
int8_t caliSun_02_Top  = -1;




//cali_t.stackCali_02_01_Tp=-1;
//cali_t.stackCali_02_02_Tp =-1;
//cali_t.stackCali_02_03_Tp =-1;


//cali_t.stackCali_03_01_Tp =-1;
//cali_t.stackCali_03_02_Tp =-1;
//cali_t.stackCali_03_03_Tp =-1;

static void Symbol_CAL1(void);
static void Symbol_CAL2(void);
static void Symbol_dC_u(void);
static void Symbol_CAP(void);
static void Symbol_2Ero(void);
static void Symbol_SPAn(void);
static void Symbol_SEn(void);
static void Symbol_CLS(void);
static void Symbol_qtY(void);
static void Symbol_C_nS(void);
static void Symbol_ContC(void);

static CaliSubMenu_03_01_01_3bitPoint(uint8_t *pA);
static CaliSubMenu_03_01_01_4bitPoint(uint8_t *pA);
static CaliSubMenu_03_01_01_5bitPoint(uint8_t *pA);



 static void CaliSubMenu_02_01_Dis(uint8_t n);
 
static void CaliSubMenu_02_02_Dis(uint8_t n);

static void CaliSubMenu_02_03_Dis(uint8_t);
 
static void CaliSubMenu_02_04_Dis(uint8_t);
 
 
 
 

uint8_t cmu,*pA;

static void Symbol_CAL1(void)
{
   SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x01); //'1' 
   SmgDisplay_Character(digital_3,0x06); //"L"
   SmgDisplay_Character(digital_2,0x00); //"A"
   SmgDisplay_Character(digital_1,0x01); //"C"
}
static void Symbol_CAL2(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x02); //'2' 
   SmgDisplay_Character(digital_3,0x06); //"L"
   SmgDisplay_Character(digital_2,0x00); //"A"
   SmgDisplay_Character(digital_1,0x01); //"C"
}
static void Symbol_dC_u(void)
{
   SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay_Character(digital_3,0x11); //"u"
   SmgDisplay_Character(digital_2,0x0e); //"C-"
   SmgDisplay_Character(digital_1,0x02); //"d"
}
static void Symbol_CAP(void)
{
   SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay_Character(digital_3,0x09); //"P"
   SmgDisplay_Character(digital_2,0x00); //"A"
   SmgDisplay_Character(digital_1,0x01); //"C"
}
static void Symbol_2Ero(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay_Character(digital_4,0x08); //'o
   SmgDisplay_Character(digital_3,0x0b); //"r"
   SmgDisplay_Character(digital_2,0x03); //"E"
   SmgDisplay(digital_1,0x02); //"2"
}
static void Symbol_SPAn(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay_Character(digital_4,0x07); //'n' 
   SmgDisplay_Character(digital_3,0x00); //"A"
   SmgDisplay_Character(digital_2,0x09); //"P"
   SmgDisplay(digital_1,0x05); //"5"
}
static void Symbol_SEn(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay_Character(digital_3,0x07); //"n"
   SmgDisplay_Character(digital_2,0x03); //"E"
   SmgDisplay(digital_1,0x05); //"S"
}
static void Symbol_CLS(void)
{
   SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay(digital_3,0x05); //"5"
   SmgDisplay_Character(digital_2,0x06); //"L"
   SmgDisplay_Character(digital_1,0x01); //"C"

}
static void Symbol_qtY(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay_Character(digital_3,0x0d); //"y"
   SmgDisplay_Character(digital_2,0x0c); //"t"
   SmgDisplay_Character(digital_1,0x0a); //"q"
}
static void Symbol_C_nS(void)
{
    SmgDisplay(digital_5,0x0b); //null
   SmgDisplay(digital_4,0x0b); //null 
   SmgDisplay(digital_3,0x05); //"5"
   SmgDisplay_Character(digital_2,0x07); //"n"
   SmgDisplay_Character(digital_1,0x0e); //"c-"

}
static void Symbol_ContC(void)
{
    SmgDisplay_Character(digital_5,0x0e); //'C-'
   SmgDisplay_Character(digital_4,0x0c); //'t' 
   SmgDisplay_Character(digital_3,0x07); //"n"
   SmgDisplay_Character(digital_2,0x08); //"o"
   SmgDisplay_Character(digital_1,0x01); //"C"

}
static CaliSubMenu_03_01_01_3bitPoint(uint8_t *pA)
{
   SmgDisplay(digital_1,0x0b); //null
   SmgDisplay(digital_2,0x0b); //null
   SmgDisplay_Point(digital_3,*(pA+2)); // pointer "."
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100
}

static CaliSubMenu_03_01_01_4bitPoint(uint8_t *pA)
{

   SmgDisplay(digital_1,0x0b); //null
   SmgDisplay(digital_2,*(pA+3)); 
   SmgDisplay_Point(digital_3,*(pA+2)); // pointer "."
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100


}
static CaliSubMenu_03_01_01_5bitPoint(uint8_t *pA)
{

   SmgDisplay(digital_1,*(pA+4)); //null
   SmgDisplay(digital_2,*(pA+3)); 
   SmgDisplay_Point(digital_3,*(pA+2)); // pointer "."
   SmgDisplay(digital_4,*(pA+1)); // 0~100
   SmgDisplay(digital_5,*pA); // 0~100


}
static void CaliSubMenu_02_04_Dis(uint8_t dat)
{


}
/*****************************************************************
 * 
 * Function Name: void CALI_MENU_01_DIS(uint8_t mu)
 * 
 * 
 *
 ****************************************************************/
void CALI_MENU_01_DIS(uint8_t mu)
{
      switch(mu){

     
       
       case CAL1: //CAL1
          cali_t.CaliMenu_01_Id =CAL1;
          Symbol_CAL1();

       break;
          
       case CAL2: //CAL2
           cali_t.CaliMenu_01_Id =CAL2;
           Symbol_CAL2();
       break;
           
       case CAL3: //CAL3
           cali_t.CaliMenu_01_Id =CAL3;
          SmgDisplay(digital_4,0x03); //'3' 
       break;

       case CAL5: //CAL5
             cali_t.CaliMenu_01_Id =CAL5;
             SmgDisplay(digital_4,0x05); //'5' 
       break;
       default:

       break;
     }

}

void CALI_MENU_SUB_02_DIS(uint8_t mu,uint8_t sub03)
{

     switch(mu){

        case CAL1://dC-u,CAP,2Ero, SPAn
              
              CaliSubMenu_02_01_Dis(sub03);

        break;

        case CAL2: //dC-u,CAP,2Ero,SEn,SPARn
               
                CaliSubMenu_02_02_Dis(sub03);
        break;

        case CAL3://CLS ,QtY,C-nS
            
            CaliSubMenu_02_03_Dis(sub03);
        break;

        case CAL5:
           
            CaliSubMenu_02_04_Dis(sub03);
        break;




     }


}

/*****************************************************
 * 
 * The firs MENU : CAL1 of child
 * 
 * 
 ****************************************************/
 static void CaliSubMenu_02_01_Dis(uint8_t n)
 {

     switch(n){

      case 0:  //dC-u
            cali_t.CaliMenu_02_Id =0;
            Symbol_dC_u();
      break;
            
      case 1: //CAP
               cali_t.CaliMenu_02_Id =1;
              Symbol_CAP();
      break;

      case 2: //2Ero
             cali_t.CaliMenu_02_Id =2;
            Symbol_2Ero();
      break;

      case 3: //SPAn
             cali_t.CaliMenu_02_Id =3;
            Symbol_SPAn();
      break;

      default:

      break;

      }

}
/*****************************************************
 * 
 * The firs MENU : CAL2 of child
 * 
 * 
 ****************************************************/
 void CaliSubMenu_02_02_Dis(uint8_t n)
 {
     switch(n){
 
        case 0://dC-u
               Symbol_dC_u();
        break;

        case 1: //CAP
                Symbol_CAP();
        break;

        case 2: //2Ero
                Symbol_2Ero();
        break;

         case 3:  //SEn
                Symbol_SEn();
        break;

        case 4: //SPARn
                Symbol_SPAn();
        break;

        default:

        break;

     }
}
/*****************************************************
 * 
 * The firs MENU : CAL3 of child
 * 
 * 
 ****************************************************/
void CaliSubMenu_02_03_Dis(uint8_t n)
 {
     switch(n){
 
        case 0://CLS
              Symbol_CLS();
        break;

        case 1: //qtY
                Symbol_qtY();
        break;

        case 2: //C-n5
             Symbol_C_nS() ;
        break;

        default:

        break;

     }
}



 void CALI_MENU_SUB_03_DIS(uint8_t item, uint8_t itsub)
 {
     
     switch(item){

           case CAL1:
             
                switch(itsub){
                 

                case 0:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 1:
                   CaliSubMenu_03_01_01_5bitPoint(pA);
                break;

                case 2:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 3:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 4:
                    CaliSubMenu_03_01_01_4bitPoint(pA);   
                break;
                //add weight extra
                case 5:
                    CaliSubMenu_03_01_01_5bitPoint(pA);   
                break;

                }
           break;

           case CAL2:
               switch(itsub){
                case 0:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 1:
                   CaliSubMenu_03_01_01_4bitPoint(pA);
                break;

                case 2:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 3:
                    CaliSubMenu_03_01_01_5bitPoint(pA);   
                break;

                
                 case 4:
                    CaliSubMenu_03_01_01_4bitPoint(pA);   
                break;

                //add weight extra
                  case 5:
                    CaliSubMenu_03_01_01_5bitPoint(pA);   
                break;
               }
           break;


           case CAL3:

               switch(itsub){

                case 0:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;

                case 1:
                   CaliSubMenu_03_01_01_4bitPoint(pA);
                break;

                case 2:
                    CaliSubMenu_03_01_01_3bitPoint(pA);   
                break;
                 //add weight extra
                case 3:
                    CaliSubMenu_03_01_01_5bitPoint(pA);   
                break;

                
            }


           break;

           case CAL5:


           break;


        }
    }



 



uint8_t Push_stackCaliMain(int8_t maxsize)
{
     
    if(caliMainTop > (maxsize -1)){
            caliMainTop=0;
    }
	else{
		
		 caliMainTop ++;
	}
	return  caliMainTop ;

}
uint8_t Pop_stackCaliMain(int8_t maxsize)
{
       if(caliMainTop ==-1){
	      caliMainTop = (maxsize -1);
       }
	   else{
           caliMainTop--;
		
	   }
     return  caliMainTop ;


}
uint8_t CaliMain_stackTop(void)
{
    return caliMainTop;
}

int8_t Push_stackCaliMain_02(int8_t maxize,int8_t ntop)
{
    if(ntop > (maxize -1) || ntop == -1){
            ntop=0;
    }
	else{
		
		 ntop ++;
	}
	return ntop ;

}

int8_t Pop_stackCaliMain_02(int8_t maxize,int8_t ntop)
{
     if( ntop ==-1){
	       ntop = (maxize -1);
       }
	   else{
            ntop--;
		
	   }
     return   ntop ;


}

int8_t CaliSub_02_stackTop(int8_t ntop)
{

    return ntop;
}

/*******************************************************************
 * 
 * Calibration of key Function
 * 
 * 
 * 
 *******************************************************************/
 void KEY4_InputCalibration_Mode(void)
 {
     cali_t.CaliControl_key=1;
     mainitem_t.task_MainMenu = caliTheFirst_Menu ;
     caliMainTop=-1;
    cali_t.CaliMenu_Item = Push_stackCaliMain(4);
	 printf("Cali_keyEnter = %d\n",cali_t.CaliMenu_Item);
	 printf("task_MainMenu = %d\n", caliTheFirst_Menu);

 }
 
 
 
 
 void CAL_KEY4_ENTER_Fun(void)
 {
     cali_t.keyEnter_flag = cali_t.keyEnter_flag ^ 0x01;

     if(cali_t.keyEnter_flag == 1){
            
          mainitem_t.task_MainMenu = caliTheSecond_Menu;
          cali_t.CaliSub_Menu_02_Title= Push_stackCaliMain_02(4,cali_t.stackCali_02_01_Tp);
          printf("keyEnter_second = %d\n",  mainitem_t.task_MainMenu );
        
     }
     else{


     }
      

}

 void  CALI_KEY1_UP_Fun(void)
{
    switch( mainitem_t.task_MainMenu){
   
    case caliTheFirst_Menu:


        cali_t.CaliMenu_Item = Push_stackCaliMain(3);
         printf("cali_t.CaliMenu_Item = %d\n", cali_t.CaliMenu_Item );
    break;

    case caliTheSecond_Menu:
          
          switch(cali_t.CaliMenu_Item){
     
           case CAL1:

                cali_t.CaliSub_02_01_Itme  =  Push_stackCaliMain_02(4,cali_t.stackCali_02_01_Tp);
                 cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_01_Itme;
            break;

          case CAL2:
                cali_t.CaliSub_02_02_Item  =  Push_stackCaliMain_02(5,cali_t.stackCali_02_02_Tp);
                cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_02_Item;
          break;

          case CAL3:
               cali_t.CaliSub_02_03_Item  =  Push_stackCaliMain_02(3,cali_t.stackCali_02_03_Tp);
               cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_03_Item;

          break;

          case CAL5:
                  
          break;
	  }
          

      break;


     case caliTheThird_Menu:
         
          switch(cali_t.CaliMenu_Item){

              case CAL1:
                      
              cali_t.CaliSub_03_01_Itme  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_01_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_01_Itme;
              break;

              case CAL2:
                        cali_t.CaliSub_03_02_Item  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_02_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_02_Item;
              break;

              case CAL3:
                    cali_t.CaliSub_03_03_Item  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_03_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_03_Item;
              break;

              case CAL5:

              break;




        } 


     break;





}
}

 void CALI_KEY3_SWITCH_Fun(void )
 {
 
 
 }

void CALI_KEY2_DOWN_Fun(void)
{
    switch( mainitem_t.task_MainMenu){
   
    case caliTheFirst_Menu:


        cali_t.CaliMenu_Item = Pop_stackCaliMain(3);
    break;

    case caliTheSecond_Menu:
          
          switch(cali_t.CaliMenu_Item){
     
           case CAL1:

                cali_t.CaliSub_02_01_Itme  =  Push_stackCaliMain_02(4,cali_t.stackCali_02_01_Tp);
                 cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_01_Itme;
            break;

          case CAL2:
                cali_t.CaliSub_02_02_Item  =  Push_stackCaliMain_02(5,cali_t.stackCali_02_02_Tp);
                cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_02_Item;
          break;

          case CAL3:
               cali_t.CaliSub_02_03_Item  =  Push_stackCaliMain_02(3,cali_t.stackCali_02_03_Tp);
               cali_t.CaliSub_Menu_02_Title =cali_t.CaliSub_02_03_Item;

          break;

          case CAL5:
                  
          break;
	  }
          

      break;


     case caliTheThird_Menu:
         
          switch(cali_t.CaliMenu_Item){

              case CAL1:
                      
              cali_t.CaliSub_03_01_Itme  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_01_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_01_Itme;
              break;

              case CAL2:
                        cali_t.CaliSub_03_02_Item  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_02_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_02_Item;
              break;

              case CAL3:
                    cali_t.CaliSub_03_03_Item  =  Push_stackCaliMain_02(4,cali_t.stackCali_03_03_Tp);
                 cali_t.CaliSub_Menu_03_Title =cali_t.CaliSub_03_03_Item;
              break;

              case CAL5:

              break;




        } 


     break;





}

}


