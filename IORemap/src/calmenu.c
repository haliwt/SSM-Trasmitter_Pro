#include "calmenu.h"

cali cali_t;
 int8_t caliMainTop =-1  ;
int8_t caliSun_02_Top  = -1;
int8_t caliSubMenu_03_Top  =-1;


int8_t CAL1_Top =-1;
int8_t CAL2_Top =-1;
int8_t CAL3_Top =-1;


int cone,ctwo,cthree,cfour,cfive;

int8_t ACAL1_00[1];
int8_t ACAL1_01[5];
int8_t ACAL1_02[5];
int8_t ACAL1_021[5];
int8_t ACAL1_03[5];
int8_t ACAL1_031[5];

int8_t ACAL2_00[1];
int8_t ACAL2_01[5];
int8_t ACAL2_02[5];
int8_t ACAL2_021[5];
int8_t ACAL2_03[5];
int8_t ACAL2_031[5];
int8_t ACAL2_04[5];
int8_t ACAL2_041[5];
int8_t ACAL3_02[5];
int8_t ACAL3_021[5];

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



static void CaliSubMenu_fourPoint_3bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred);
static void CaliSubMenu_fourPoint_2bitPoint_Dis(int8_t unit,int8_t decade);
static void CaliSubMenu_fourPoint_5bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);

 static void CaliSubMenu_02_01_Dis(uint8_t n);
 
static void CaliSubMenu_02_02_Dis(uint8_t n);

static void CaliSubMenu_02_03_Dis(uint8_t);


 
 static void caliSubMenu_03_01_3bit_Dis(int8_t unit,int8_t decade,int8_t hundred);
 static void caliSubMenu_03_02_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand); //CaliSubMenu_03_01_01_5bitPoint(ACAL302);
 static void caliSubMenu_03_4bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   



static void caliSubMenu_onePoint_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
 
 static void Cali_CAL1_ducNumberDis(int8_t cal1);
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





static void  CaliSubMenu_fourPoint_5bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{

   SmgDisplay(digital_1,tenthousand); //null
   SmgDisplay(digital_2,onethousand); 
   SmgDisplay(digital_3,hundred); 
   SmgDisplay_Point(digital_4,decade); // pointer "."
   SmgDisplay(digital_5,unit); // 0~100


}
static void CaliSubMenu_fourPoint_3bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred)
{

   SmgDisplay(digital_1,0x0b); //null
   SmgDisplay(digital_2,0x0b); 
   SmgDisplay(digital_3,hundred); // 0~100
   SmgDisplay_Point(digital_4,decade); // pointer "."
   SmgDisplay(digital_5,unit); // 0~100


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

    
       default:

       break;
     }

}

void CALI_MENU_SUB_02_DIS(void)
{

     switch(cali_t.CaliMenu_Item){

        case CAL1://dC-u,CAP,2Ero, SPAn
              cali_t.CaliMenu_02_Id = CAL1;
              CaliSubMenu_02_01_Dis(cali_t.CaliSub_02_01_Item);
          

        break;

        case CAL2: //dC-u,CAP,2Ero,SEn,SPARn
                cali_t.CaliMenu_02_Id = CAL2;
                CaliSubMenu_02_02_Dis(cali_t.CaliSub_02_02_Item );
                
        break;

        case CAL3://CLS ,QtY,C-nS
             cali_t.CaliMenu_02_Id = CAL3;
            CaliSubMenu_02_03_Dis(cali_t.CaliSub_02_03_Item );
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
            cali_t.CaliMenu_02_sub_Id =0;
            Symbol_dC_u();
      break;
            
      case 1: //CAP
               cali_t.CaliMenu_02_sub_Id =1;
              Symbol_CAP();
      break;

      case 2: //2Ero
             cali_t.CaliMenu_02_sub_Id =2;
            Symbol_2Ero();
      break;

      case 3: //SPAn
             cali_t.CaliMenu_02_sub_Id =3;
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
               cali_t.CaliMenu_02_sub_Id =0;
               Symbol_dC_u();
        break;

        case 1: //CAP
                cali_t.CaliMenu_02_sub_Id =1;
                Symbol_CAP();
        break;

        case 2: //2Ero
                cali_t.CaliMenu_02_sub_Id =2;
                Symbol_2Ero();
        break;

         case 3:  //SEn
                 cali_t.CaliMenu_02_sub_Id =3;
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
             cali_t.CaliMenu_02_sub_Id =0;
              Symbol_CLS();
        break;

        case 1: //qtY
                 cali_t.CaliMenu_02_sub_Id =1;
                Symbol_qtY();
        break;

        case 2: //C-n5
             cali_t.CaliMenu_02_sub_Id =3;
             Symbol_C_nS() ;
        break;

        default:

        break;

     }
}



 void CALI_MENU_SUB_03_DIS(uint8_t item)
 {
     
     switch(cali_t.CaliMenu_Item){

           case CAL1:
             
                switch(item){
                 

                case 0:
                menu_t.DisplaySmgBit_Select_Numbers=3;
                 caliSubMenu_03_01_3bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred);  // CaliSubMenu_03_01_01_3bitPoint(ACAL301);   
                 printf("run_03_dis_cal1_0\n",cali_t.CaliSub_Menu_03_Title );
               
                break;

                case 1:
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                  caliSubMenu_03_02_5bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred,cali_t.onethousand,cali_t.tenthousand); //CaliSubMenu_03_01_01_5bitPoint(ACAL302);
                 printf("run_03_dis_cal1_1\n",cali_t.CaliSub_Menu_03_Title );
                break;

                case 2:
                     menu_t.DisplaySmgBit_Select_Numbers=3;
                   caliSubMenu_03_01_3bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   
                  printf("run_03_dis_cal1_2\n" ,cali_t.CaliSub_Menu_03_Title);
                break;

                case 3:
                    menu_t.DisplaySmgBit_Select_Numbers=4;
                    caliSubMenu_03_4bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred,cali_t.onethousand); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   
                  printf("run_03_dis_cal1_3\n", cali_t.CaliSub_Menu_03_Title);
                break;

               
                //add weight extra
                case 4:
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    caliSubMenu_03_02_5bit_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);//CaliSubMenu_03_01_01_5bitPoint(ACAL306);   
                break;

                }
           break;

           case CAL2:
               switch(item){
                 case 0:
                menu_t.DisplaySmgBit_Select_Numbers=3;
                 caliSubMenu_03_01_3bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred);  // CaliSubMenu_03_01_01_3bitPoint(ACAL301);   
                 printf("run_03_dis_02_0\n",cali_t.CaliSub_Menu_03_Title );
               
                break;

                case 1:
                     menu_t.DisplaySmgBit_Select_Numbers=4;
                  caliSubMenu_03_4bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred,cali_t.onethousand); //CaliSubMenu_03_01_01_5bitPoint(ACAL302);
                 printf("run_03_dis_02_1\n",cali_t.CaliSub_Menu_03_Title );
                break;

                case 2:
                     menu_t.DisplaySmgBit_Select_Numbers=3;
                   caliSubMenu_03_01_3bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   
                  printf("run_03_dis_02_2\n" ,cali_t.CaliSub_Menu_03_Title);
                break;

                case 3:
                    menu_t.DisplaySmgBit_Select_Numbers=5;
                    caliSubMenu_onePoint_5bit_Dis(cali_t.unit,cali_t.decade,cali_t.hundred,cali_t.onethousand,cali_t.tenthousand); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   
                  printf("run_03_dis_02_3\n", cali_t.CaliSub_Menu_03_Title);
                break;

               
                //add weight extra
                case 4:
                printf("run_03_dis_02_3\n", cali_t.CaliSub_Menu_03_Title);
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    caliSubMenu_03_02_5bit_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);//CaliSubMenu_03_01_01_5bitPoint(ACAL306);   
                break;


                //add weight extra
                  case 5:
                     caliSubMenu_03_02_5bit_Dis(f8menu_t.unit,f8menu_t.decade,f8menu_t.hundred,f8menu_t.onethousand,f8menu_t.tenthousand);
                break;
               }
           break;


           case CAL3:

               switch(item){

                case 0:
                    menu_t.DisplaySmgBit_Select_Numbers=2;
                    CaliSubMenu_fourPoint_2bitPoint_Dis(cali_t.unit,cali_t.decade);
                break;

                case 1:
                menu_t.DisplaySmgBit_Select_Numbers=5;
                   CaliSubMenu_fourPoint_5bitPoint_Dis(cali_t.unit,cali_t.decade,cali_t.hundred,cali_t.onethousand,cali_t.tenthousand);
                break;

                case 2:
                    menu_t.DisplaySmgBit_Select_Numbers=3;
                    CaliSubMenu_fourPoint_3bitPoint_Dis(cali_t.unit,cali_t.decade,cali_t.hundred);
                break;
                 //add weight extra
                case 3:
                      menu_t.DisplaySmgBit_Select_Numbers=0;
                      Symbol_ContC(); 
                break;

                
            }


           break;

           case CAL5:
                menu_t.DisplaySmgBit_Select_Numbers=0;
                Symbol_ContC(); 
          break;


        }
    }



 



uint8_t Push_stackCaliMain(int8_t maxsize)
{
     
    if(caliMainTop >= (maxsize -1)){
            caliMainTop=0;
    }
	else{
		
		 caliMainTop ++;
	}
   if(caliMainTop>maxsize) caliMainTop = 0;
	return  caliMainTop ;

}
uint8_t Pop_stackCaliMain(int8_t maxsize)
{
       caliMainTop-- ;
       if(caliMainTop ==-1 ||caliMainTop <0 ){
	      caliMainTop = (maxsize -1);
       }
	    if(caliMainTop>200) caliMainTop = (maxsize -1);
     return  caliMainTop ;


}
uint8_t CaliMain_stackTop(void)
{
    return caliMainTop;
}

int8_t Push_stackCaliMain_02(int8_t maxize)
{
    caliSubMenu_03_Top  ++;
    if(caliSubMenu_03_Top  == maxize || caliSubMenu_03_Top  >maxize  ){
            caliSubMenu_03_Top =0;
    }
    
	    
	return caliSubMenu_03_Top  ;

}

int8_t Pop_stackCaliMain_02(int8_t maxize)
{
     
     caliSubMenu_03_Top  --;
     if( caliSubMenu_03_Top   ==-1 || caliSubMenu_03_Top  <0){
	       caliSubMenu_03_Top   = (maxize -1);
    }
     if(caliSubMenu_03_Top <0 || caliSubMenu_03_Top  > maxize)  caliSubMenu_03_Top   = (maxize -1);
     return   caliSubMenu_03_Top   ;


}
int8_t CaliSub_02_stackTop(int8_t maxize)
{
    if(caliSubMenu_03_Top==-1)caliSubMenu_03_Top=0;
    if( caliSubMenu_03_Top >=(maxize-1))caliSubMenu_03_Top=0;
    return caliSubMenu_03_Top  ;
}

//CAL1
int8_t Push_stackCaliMain_CAL1(int8_t maxize)
{
     CAL1_Top  ++;
    if(CAL1_Top > (maxize-1) ){
            CAL1_Top =0;
    }
  
	    
	return  CAL1_Top ;

}

int8_t Pop_stackCaliMain_CAL1(int8_t maxize)
{
     
     CAL1_Top  --;
     if( CAL1_Top   ==-1 || CAL1_Top  <0){
	      CAL1_Top   = (maxize -1);
    }
    return  CAL1_Top   ;


}

int8_t CaliSub_CAL1_stackTop(int8_t maxize)
{
    if(CAL1_Top==-1)CAL1_Top=0;
    if( CAL1_Top >=(maxize-1))CAL1_Top=0;
    return CAL1_Top  ;
}
///---END CAL1

//CAL2
int8_t Push_stackCaliMain_CAL2(int8_t maxize)
{
   
     CAL2_Top  ++;
    if(CAL2_Top > (maxize-1) ){
            CAL2_Top =0;
    }
   
	    
	return  CAL2_Top ;

}

int8_t Pop_stackCaliMain_CAL2(int8_t maxize)
{
     
     CAL2_Top  --;
     if( CAL2_Top   ==-1 || CAL2_Top  <0){
	      CAL2_Top   = (maxize -1);
    }
    return  CAL2_Top   ;


}

int8_t CaliSub_CAL2_stackTop(int8_t maxize)
{
    if(CAL2_Top==-1)CAL2_Top=0;
    if( CAL2_Top >=(maxize-1))CAL2_Top=0;
    return CAL2_Top  ;
}
///---END CAL2

//CAL3
int8_t Push_stackCaliMain_CAL3(int8_t maxize)
{
   
     CAL3_Top  ++;
    if(CAL3_Top > (maxize-1) ){
            CAL3_Top =0;
    }
   
	    
	return  CAL3_Top ;

}

int8_t Pop_stackCaliMain_CAL3(int8_t maxize)
{
     
     CAL3_Top  --;
     if( CAL3_Top   ==-1 || CAL3_Top  <0){
	      CAL3_Top   = (maxize -1);
    }
    return  CAL3_Top   ;


}

int8_t CaliSub_CAL3_stackTop(int8_t maxize)
{
    if(CAL3_Top==-1)CAL3_Top=0;
    if( CAL3_Top >=(maxize-1))CAL3_Top=0;
    return CAL3_Top  ;
}
///---END CAL2

/*******************************************************************
 * 
 *  Function Name:void KEY4_InputCalibration_Mode(void)
 *  Function :
 *  Input Ref:NO
 *  Return Ref:NO
 *
 *******************************************************************/
void KEY4_InputCalibration_Mode(void)
{
     if(cali_t.Thefirst_InputKeyValue==0){
	     cali_t.Thefirst_InputKeyValue++;
	     cali_t.CaliControl_key=1; 
	     mainitem_t.task_MainMenu = caliTheFirst_Menu ;
	     caliMainTop=-1;
	     cali_t.CaliMenu_Item = Push_stackCaliMain(3);
	     key_t.keyPressedLongTimes=1;
	     key_t.caliKeyFun = 1;
         cali_t.runKeyMenu=mainitem_t.task_MainMenu;
	     printf("Cali_keyEnter_1 = %d\n",cali_t.CaliMenu_Item);
		   printf("task_MainMenu_1 = %d\n", caliTheFirst_Menu);
     }

	 
}
/****************************************************************
 * Enter Key
 ***************************************************************/
void CAL_KEY4_ENTER_Fun(void)
{
    static uint8_t currkey=0xff,currkey2=0xff,currkey3=0xff;

	 if(cali_t.Thefirst_InputKeyValue==1){
          key_t.getEnterValue > 7 ;
		  cali_t.Thefirst_InputKeyValue++;
		  SysTick_Delay_Ms(300);
		return ;
	}
	
    cali_t.keyEnter_flag++;
    printf("cali enterKey = %d \n", cali_t.keyEnter_flag);
    if(cali_t.keyEnter_flag ==0){

      
         mainitem_t.task_MainMenu = caliTheFirst_Menu ;
         caliMainTop=-1;
         cali_t.CaliMenu_Item = Push_stackCaliMain(3);
        cali_t.runKeyMenu=mainitem_t.task_MainMenu;

    }
    else if(cali_t.keyEnter_flag ==1){

       //CAL1->dC-u,-》display "dC-u"
       
        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
        cali_t.runKeyMenu=mainitem_t.task_MainMenu;
        switch(cali_t.CaliMenu_Item){

            case CAL1:
              cali_t.CaliSub_02_01_Item=  CaliSub_CAL1_stackTop(4);
              printf("CAL1_1enterKey = %d \n",  cali_t.CaliSub_02_01_Item);
            break;

            case CAL2:
         
                cali_t.CaliSub_02_02_Item =CaliSub_CAL2_stackTop(5);
              printf("CAL2_1enterKey = %d \n",  cali_t.CaliSub_02_02_Item);
            break;

            case CAL3:
          
                cali_t.CaliSub_02_03_Item =CaliSub_CAL3_stackTop(3);
             printf("CAL3_1enterKey = %d \n", cali_t.CaliSub_02_03_Item);
            break;


        }
    }
    else if(cali_t.keyEnter_flag ==2){ //caliTheThird_Menu 

     //case 2:// the second step -> opertaion input number EnterKey
       mainitem_t.task_MainMenu = caliTheThird_Menu; 
       cali_t.runKeyMenu=mainitem_t.task_MainMenu;
        switch( cali_t.CaliMenu_Item){

            case CAL1:
            
              cali_t.CaliSub_02_01_Item=CaliSub_CAL1_stackTop(4);
              printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
            break;

            case CAL2:
                  
                  cali_t.CaliSub_02_02_Item =CaliSub_CAL2_stackTop(5);
            break;

            case CAL3:
               cali_t.keyEnter_flag=1;
              cali_t.CaliSub_02_03_Item ++;
              if(cali_t.CaliSub_02_03_Item >2)cali_t.CaliSub_02_03_Item=0;
            break;
        }
      
    }
    else {
      
    //case 3://the third step continu
      	   mainitem_t.task_MainMenu = caliTheFourth_Menu; 
           cali_t.runKeyMenu=mainitem_t.task_MainMenu;
        switch(cali_t.CaliMenu_Item){

        case CAL1:
             printf("CAL----CAL1_Id = %d\n",cali_t.CAL1_Id);
                if(currkey != cali_t.CAL1_Id){
                       currkey= cali_t.CAL1_Id;
                       if(cali_t.CAL1_Id==0)
                         cali_t.CAL1_sequence_flag = cali_t.CAL1_Id;
                       else if(cali_t.CAL1_Id==1)
                            cali_t.CAL1_sequence_flag = cali_t.CAL1_Id+1;
                       else if(cali_t.CAL1_Id==2)
                            cali_t.CAL1_sequence_flag = cali_t.CAL1_Id+2;
                    else if(cali_t.CAL1_Id==3) 
                        cali_t.CAL1_sequence_flag=cali_t.CAL1_Id+4;;
                      
                    printf("CaliSub_02_01_Item = %d\n",cali_t.CaliSub_02_01_Item);
                 }
             
                 cali_t.CAL1_sequence_flag ++;
              printf("CAL1---seq-flag = %d\n", cali_t.CAL1_sequence_flag);

             if( cali_t.CAL1_sequence_flag  >9){
                cali_t.CAL1_sequence_flag=-1;
                cali_t.keyEnter_flag=0;
                mainitem_t.task_MainMenu = caliTheFirst_Menu ; 
                cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                caliMainTop=-1;
    
                cali_t.CaliMenu_Item = Push_stackCaliMain(3);
              }
            printf("CAL1_sequence_flag = %d\n",cali_t.CAL1_sequence_flag);
          
            break;
         //-----------------------------------------------------------/
         //CAL2 MENU 
        case CAL2:

              
               if(currkey2 != cali_t.CAL2_Id){
                   currkey2= cali_t.CAL2_Id;
                   if(cali_t.CAL2_Id==0)
                     cali_t.CAL2_sequence_flag = cali_t.CAL2_Id;
                   else if(cali_t.CAL2_Id==1)
                        cali_t.CAL2_sequence_flag = cali_t.CAL2_Id+1;
                   else if(cali_t.CAL2_Id==2)
                        cali_t.CAL2_sequence_flag = cali_t.CAL2_Id+2;
                   else if(cali_t.CAL2_Id==3)
                        cali_t.CAL2_sequence_flag = cali_t.CAL2_Id+4;
                  else if(cali_t.CAL2_Id==4)
                        cali_t.CAL2_sequence_flag = cali_t.CAL2_Id+5;
                 
                  
                  printf("CaliSub_02_02_Item = %d\n",cali_t.CaliSub_02_02_Item);
              }
              cali_t.CAL2_sequence_flag ++;

             if( cali_t.CAL2_sequence_flag  >11){
                cali_t.CAL2_sequence_flag=-1;
                cali_t.keyEnter_flag=0;
                mainitem_t.task_MainMenu = caliTheFirst_Menu ; 
                cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                caliMainTop=-1;
                cali_t.CaliMenu_Item = Push_stackCaliMain(3);
              }
            printf("CAL2_sequence_flag = %d\n",cali_t.CAL2_sequence_flag);
            break;

                
        break;

        //CAL3 MENU
        case CAL3:
            if(currkey3 != cali_t.CAL3_Id){
                   currkey3= cali_t.CAL3_Id;
                   if(cali_t.CAL3_Id==0)
                     cali_t.CAL3_sequence_flag = cali_t.CAL3_Id;
                   else if(cali_t.CAL3_Id==1)
                        cali_t.CAL3_sequence_flag = cali_t.CAL3_Id;
                   else if(cali_t.CAL3_Id==2)
                       cali_t.CAL3_sequence_flag = cali_t.CAL3_Id+2;
                printf("CaliSub_02_03_Item = %d\n",cali_t.CaliSub_02_03_Item);
              }
              else{
                cali_t.CAL2_sequence_flag++;
              }

            if(cali_t.CAL3_Id==2)cali_t.CAL2_sequence_flag++;
              

             if( cali_t.CAL2_sequence_flag >4){
                cali_t.CAL2_sequence_flag=-1;
                cali_t.keyEnter_flag=0;
                mainitem_t.task_MainMenu = caliTheFirst_Menu ; 
                cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                caliMainTop=-1;
                cali_t.CaliMenu_Item = Push_stackCaliMain(3);
              }
            printf("CAL2_sequence_flag = %d\n",cali_t.CAL2_sequence_flag);
           
              
        break;


      }
             
       
    }
    
}
/*******************************************************************
*
*Function :execute 
*
*******************************************************************/
 void  CALI_KEY1_UP_Fun(void)
{
    switch(cali_t.runKeyMenu){
   
    case caliTheFirst_Menu:

        cali_t.CaliMenu_Item = Push_stackCaliMain(3);
         printf("cali_t.CaliMenu_Item = %d\n", cali_t.CaliMenu_Item );
    break;

    case caliTheSecond_Menu:
         
   
          switch(cali_t.CaliMenu_Item){
    
          case CAL1:
                  
              cali_t.CaliSub_02_01_Item  =  Push_stackCaliMain_CAL1(4);
                 
          break;

          case CAL2:
                 
                  cali_t.CaliSub_02_02_Item  =  Push_stackCaliMain_CAL2(5);
                 
          break;

          case CAL3:
             
              cali_t.CaliSub_02_03_Item  =  Push_stackCaliMain_CAL3(3);
              printf("keyUp_CAL2_theSecond_Menu = %d\n", cali_t.CaliSub_02_03_Item );

          break;

        }
      break;

    case caliTheThird_Menu: //key Up ++

    switch(cali_t.CaliMenu_Item){
            case CAL1:
                switch( cali_t.CaliSub_02_01_Item){

                  case 0:
                        ACAL1_00[0] ++;
                        if(ACAL1_00[0]>15) ACAL1_00[0]=0;
                      
                  break;

                  case 1:
                    
                      Number_Digital_5bit_AddSelect(ACAL1_01);
                  break;

                  case 2:
                  
                      Number_Digital_5bitPoint_AddSelect(ACAL1_02);
                  break;

                  case 3:
                    
                       Number_Digital_5bit_AddSelect(ACAL1_03);
                  break;
              }       

            break;
            //CAL2 menu 
            case CAL2:
               switch( cali_t.CaliSub_02_02_Item){
               case 0:
                        ACAL2_00[0] ++;
                        if(ACAL2_00[0]>15) ACAL2_00[0]=0;
                      
                  break;

                  case 1:
                      
                      Number_Digital_5bit_AddSelect(ACAL2_01);
                  break;

                  case 2:
                    
                      Number_Digital_5bitPoint_AddSelect(ACAL2_02);
                  break;

                  case 3:
                   
                       Number_Digital_5bit_AddSelect(ACAL2_03);
                  break;

               break;


             }

            break;
         //CAL3 MENU ---theThird_Menu
            case CAL3:
               switch(cali_t.CAL3_sequence_flag){
                case 0:
                       
                break;

                case 1:
                        
                break;

                case 2:
                 
                break;

                case 3:
                      Number_Digital_5bit_AddSelect(ACAL3_02);
                break;

                case 4:
                     Number_Digital_5bitPoint_AddSelect(ACAL3_021);
                break;


                case 5:
                      
                break;


            }     
            
            break;

          }
      break;

      case caliTheFourth_Menu :
        switch(cali_t.CaliMenu_Item){

          case CAL1:
                switch(cali_t.CAL1_sequence_flag){

                  case 0:
                        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                        cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                        cali_t.keyEnter_flag=1;
                        CAL1_Top=0;
                        printf("CAL1_Top = %d\n",CAL1_Top);

                  break;

                  case 1:
                        ACAL1_00[0] ++;
                        if(ACAL1_00[0]>15) ACAL1_00[0]=0;
                      
                  break;

                  case 2:
                      mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                      cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                      cali_t.keyEnter_flag=1;
                  
                     CAL1_Top=1;
                     printf("CAL1_Top = %d\n",CAL1_Top);

                  break;

                  case 3:
                      
                      Number_Digital_5bit_AddSelect(ACAL1_01);
                  break;

                  case 4:
                     mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                     cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                     cali_t.keyEnter_flag=1;
                     CAL1_Top=2;

                  break;

                  case 5:
                    
                      Number_Digital_5bitPoint_AddSelect(ACAL1_02);
                  break;

                case 6:
                    
                      Number_Digital_5bitPoint_AddSelect(ACAL1_021);
                  break;

                  case 7:
                     mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL1_Top=3;
                    printf("CAL1_Top = %d\n",CAL1_Top);

                  break;

                  case 8:
                      
                      Number_Digital_5bit_AddSelect(ACAL1_03);
                  break;

                 case 9:
                      
                      Number_Digital_5bit_AddSelect(ACAL1_031);
                  break;

              }       

         break;

         //CAL2 MENU 
         case CAL2:
            switch(cali_t.CAL2_sequence_flag){

                  case 0:
                        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                        cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                        cali_t.keyEnter_flag=1;
                        CAL2_Top=0;
                        printf("CAL2_Top = %d\n",CAL2_Top);

                  break;

                  case 1:
                        ACAL2_00[0] ++;
                        if(ACAL2_00[0]>15) ACAL2_00[0]=0;
                      
                  break;

                  case 2:
                      mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                      cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                      cali_t.keyEnter_flag=1;
                  
                     CAL2_Top=1;
                     printf("CAL1_Top = %d\n",CAL2_Top);

                  break;

                  case 3:
                      
                      Number_Digital_5bit_AddSelect(ACAL2_01);
                  break;

                  case 4:
                     mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                     cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                     cali_t.keyEnter_flag=1;
                     CAL2_Top=2;

                  break;

                  case 5:
                    
                      Number_Digital_5bitPoint_AddSelect(ACAL2_02);
                  break;

                case 6:
                    
                      Number_Digital_5bitPoint_AddSelect(ACAL2_021);
                  break;

                  case 7:
                     mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL2_Top=3;
                    printf("CAL2_Top = %d\n",CAL2_Top);

                  break;

                  case 8:
                      
                      Number_Digital_5bit_AddSelect(ACAL2_03);
                  break;

                 case 9:
                    mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL2_Top=4;
                    printf("CAL2_Top = %d\n",CAL2_Top);
                     
                  break;

                  case 10:
                     Number_Digital_5bit_AddSelect(ACAL2_04);

                  break;

                  case 11:

                       Number_Digital_5bit_AddSelect(ACAL2_041);
                  break;

              }       

         break;


         //CAL3 MENU
        case CAL3:
              



        break;


    }
   

     
    } 
            
        
    
}



/***************************************************************************
*
*Function KEY ---
*
*
*
*******************************************************************************/
void CALI_KEY2_DOWN_Fun(void)
{
    switch( cali_t.runKeyMenu){
   
    case caliTheFirst_Menu:


        cali_t.CaliMenu_Item = Pop_stackCaliMain(3);
        printf("cali_t.CaliMenu_Item_pop = %d\n", cali_t.CaliMenu_Item );
    break;

    case caliTheSecond_Menu:
          
     switch(cali_t.CaliMenu_Item){ //dwon Key  ---
    
          case CAL1:
                  
                  cali_t.CaliSub_02_01_Item  =  Pop_stackCaliMain_CAL1(4);
                 
                
              break;

          case CAL2:
                  cali_t.CaliSub_02_02_Item  =  Pop_stackCaliMain_CAL2(5);
                 
          break;

          case CAL3:
              cali_t.CaliSub_02_03_Item  =  Pop_stackCaliMain_CAL3(3);
             

          break;

        }
      break;

     case caliTheThird_Menu:  //Key Up --
          
          switch(cali_t.CaliMenu_Item){
            case CAL1:
                switch( cali_t.CaliSub_02_01_Item){

                  case 0:
                        ACAL1_00[0] --;
                        if(ACAL1_00[0]==-1) ACAL1_00[0]=15;
                        printf("key down - = %d\n", ACAL1_00[0]);
                  break;

                  case 1:
                      Number_Digital_5bit_DecSelect(ACAL1_01);
                  break;

                  case 2:
                      Number_Digital_5bitPoint_DecSelect(ACAL1_02);
                  break;

                  case 3:
                       Number_Digital_5bit_DecSelect(ACAL1_03);
                  break;
              }       

            break;
            //CAL2 MENU
            case CAL2:
             switch(cali_t.CaliMenu_Item){
            case CAL1:
                switch( cali_t.CaliSub_02_01_Item){

                  case 0:
                        ACAL1_00[0] --;
                        if(ACAL1_00[0]==-1) ACAL1_00[0]=15;
                        printf("key down - = %d\n", ACAL1_00[0]);
                  break;

                  case 1:
                      Number_Digital_5bit_DecSelect(ACAL1_01);
                  break;

                  case 2:
                      Number_Digital_5bitPoint_DecSelect(ACAL1_02);
                  break;

                  case 3:
                       Number_Digital_5bit_DecSelect(ACAL1_03);
                  break;
              }       

            break;

            case CAL3:
                 switch( cali_t.CaliSub_02_03_Item){
                case 0:
                       
                break;

                case 1:
                      
                break;

                case 2:
                    
                    Number_Digital_5bitPoint_DecSelect(ACAL3_02);
                break;

            }

            break;

        }


      break;

      case caliTheFourth_Menu: //key Down --
       switch(cali_t.CaliMenu_Item){

         case CAL1:
                switch(cali_t.CAL1_sequence_flag){

                case 0:
                        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                        cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                        cali_t.keyEnter_flag=1;
                        CAL1_Top=0;
                        printf("CAL1_Top = %d\n",CAL1_Top);

                  break;


                  case 1:
                        ACAL1_00[0] --;
                        if(ACAL1_00[0]==-1) ACAL1_00[0]=15;
                        printf("key down - = %d\n", ACAL1_00[0]);
                  break;

                   case 2:
                      mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                      cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                      cali_t.keyEnter_flag=1;
                  
                     CAL1_Top=1;
                     printf("CAL1_Top = %d\n",CAL1_Top);

                  break;

                  case 3:
                      Number_Digital_5bit_DecSelect(ACAL1_01);
                  break;

                  case 4:
                     mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                     cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                     cali_t.keyEnter_flag=1;
                     CAL1_Top=2;

                  break;


                  case 5:
                      Number_Digital_5bitPoint_DecSelect(ACAL1_02);
                  break;

                   case 6:
                    
                      Number_Digital_5bitPoint_DecSelect(ACAL1_021);
                  break;

                  case 7:
                     mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL1_Top=3;
                    printf("CAL1_Top = %d\n",CAL1_Top);

                  break;

                    case 8:
                       Number_Digital_5bit_DecSelect(ACAL1_03);
                  break;

                  case 9:
                       Number_Digital_5bit_DecSelect(ACAL1_031);
                  break;
              }       

         break;
           //CAL2 MENU 
            case CAL2:
             switch(cali_t.CAL2_sequence_flag){

                case 0:
                        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                        cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                        cali_t.keyEnter_flag=1;
                        CAL2_Top=0;
                        printf("CAL2_Top = %d\n",CAL2_Top);

                  break;


                  case 1:
                        ACAL2_00[0] --;
                        if(ACAL2_00[0]==-1) ACAL2_00[0]=15;
                        printf("key down - = %d\n", ACAL2_00[0]);
                  break;

                   case 2:
                      mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                      cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                      cali_t.keyEnter_flag=1;
                  
                     CAL2_Top=1;
                     printf("CAL2_Top = %d\n",CAL2_Top);

                  break;

                  case 3:
                      Number_Digital_5bit_DecSelect(ACAL2_01);
                  break;

                  case 4:
                     mainitem_t.task_MainMenu = caliTheSecond_Menu; 
                     cali_t.runKeyMenu=mainitem_t.task_MainMenu;
                     cali_t.keyEnter_flag=1;
                     CAL2_Top=2;

                  break;


                  case 5:
                      Number_Digital_5bitPoint_DecSelect(ACAL2_02);
                  break;

                   case 6:
                    
                      Number_Digital_5bitPoint_DecSelect(ACAL2_021);
                  break;

                  case 7:
                     mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL2_Top=3;
                    printf("CAL2_Top = %d\n",CAL2_Top);

                  break;

                 case 8:
                      
                      Number_Digital_5bit_AddSelect(ACAL2_03);
                  break;

                 case 9:
                    mainitem_t.task_MainMenu=caliTheSecond_Menu;
                     cali_t.runKeyMenu=caliTheSecond_Menu;
                     CAL2_Top=4;
                    printf("CAL2_Top = %d\n",CAL2_Top);
                     
                  break;

                  case 10:
                     Number_Digital_5bit_DecSelect(ACAL2_04);

                  break;

                  case 11:

                       Number_Digital_5bit_DecSelect(ACAL2_041);
                  break;
              }       


            break;

            case CAL3:

                switch(cali_t.CAL3_sequence_flag){
                case 0:
                       
                break;

                case 1:
                        
                break;

                case 2:
                 
                break;

                case 3:
                      Number_Digital_5bit_DecSelect(ACAL3_02);
                break;

                case 4:
                     Number_Digital_5bitPoint_DecSelect(ACAL3_021);
                break;


                case 5:
                      
                break;


            }
            break;

        }

    

     
 }
}
}
/**********************************************************************
 *
 * Return KEY
 * 
 * 
 ********************************************************************/
 void CALI_KEY3_SWITCH_Fun(void )
 {
     
      
      if(mainitem_t.task_MainMenu == caliTheFirst_Menu )
      {
         cali_t.keyEnter_flag =0;//the second enter key function
          run_t.keySetValue = 1; //return normal display flag
         run_t.dispCmd=0; //key be pressed flag 
         run_t.keyReturn =0; //return 
        
         key_t.keyPressedLongTimes=0;
         cali_t.CaliControl_key=0; //F1~F9 function and calibration funcont flag
         cali_t.Thefirst_InputKeyValue=0;
         key_t.keyGetLong_Numbers=0;
         run_t.EnterKey_flag =0;
		 key_t.keyadjust_flag =0;
        
       
          printf("key3_switch_dispCmd=0= %d\n", run_t.keySetValue);
          return ;
          
      }
      
      if(mainitem_t.task_MainMenu == caliTheSecond_Menu )
      {
          mainitem_t.task_MainMenu = caliTheFirst_Menu;
          if(caliMainTop==-1){
            cali_t.CaliMenu_Item=0;
          }
          else
           cali_t.CaliMenu_Item = CaliMain_stackTop();
           cali_t.keyEnter_flag=0;
           printf("key3_switch_theFirst= %d\n",mainitem_t.task_MainMenu);
          return ;
          
      }

      
      if(menu_t.DisplaySmgBit_Select_Numbers ==0)
      {
        
        mainitem_t.task_MainMenu = caliTheFirst_Menu;
         printf("key3_switch_theFirst= %d\n",mainitem_t.task_MainMenu);
        return;
          
      }
      
      //2BIT
      
       if(menu_t.DisplaySmgBit_Select_Numbers ==2){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >1){
                  menu_t.inputNumber_Select =0;
            }
            
             return ; 
       }
      
      //3BIT
     if(menu_t.DisplaySmgBit_Select_Numbers ==3){
               
            menu_t.inputNumber_Select ++;
            if(menu_t.inputNumber_Select >2){
                  menu_t.inputNumber_Select =0;
            }
            
            return ; 
       }
    //4IBIT
    if(menu_t.DisplaySmgBit_Select_Numbers ==4){
          menu_t.inputNumber_Select ++;
        if(menu_t.inputNumber_Select >3){
                  menu_t.inputNumber_Select =0;
          }
        return;
    }
    //5BIT
    if(menu_t.DisplaySmgBit_Select_Numbers ==5){
            menu_t.inputNumber_Select ++;
           if(menu_t.inputNumber_Select >4){
              menu_t.inputNumber_Select =0;
          }
        printf("key3_right= %d\n",menu_t.inputNumber_Select);
		  return ;
      }
      
 }
/**************************************************************************
**************************************************************************/


/***********************************************************************
 *
 * The third menu display Numbers 
 * 
 * 
 ************************************************************************/
static void CaliSubMenu_fourPoint_2bitPoint_Dis(int8_t unit,int8_t decade)
{
	SmgDisplay(digital_1,0x0b); // 0~100
    SmgDisplay(digital_2,0x0b);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,0x0b); // 0~100
    SmgDisplay_Point(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100




}
static void caliSubMenu_03_01_3bit_Dis(int8_t unit,int8_t decade,int8_t hundred)
{
    
	SmgDisplay(digital_1,0x0b); // null
    SmgDisplay(digital_2,0x0b); // null
    SmgDisplay_Point(digital_3,hundred);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100

}

static void caliSubMenu_03_02_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
 
	SmgDisplay(digital_1,tenthousand); // 0~100
    SmgDisplay(digital_2,onethousand);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay_Point(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100


}

static void caliSubMenu_03_4bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand)
{
    SmgDisplay(digital_1,0x0b); // 0~100
    SmgDisplay(digital_2,onethousand);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay_Point(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100


}   

static void caliSubMenu_onePoint_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand)
{
    SmgDisplay_Point(digital_1,tenthousand); // 0~100
    SmgDisplay(digital_2,onethousand);//SmgDisplay(digital_2,onethousand); // 0~100
    SmgDisplay(digital_3,hundred); // 0~100
    SmgDisplay(digital_4,decade); // 0~100
    SmgDisplay(digital_5,unit); // 0~100
    
    
}





 void Calibration_TheSecondRunDis_Cmd(void )
{
 

    CALI_MENU_SUB_02_DIS();
      
}  
  
void Calibration_TheThirdRunDis_Cmd(void)
{

    switch(cali_t.CaliMenu_Item){

      case CAL1:
        switch(cali_t.CaliSub_02_01_Item){

        case 0: //dCu numbers display
        menu_t.DisplaySmgBit_Select_Numbers=0;
        cali_t.CAL1_Id = 0;
        Cali_CAL1_ducNumberDis(ACAL1_00[0]);  
        // printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
        break;

        case 1: //CAP number display
        cali_t.CAL1_Id =1;

        menu_t.DisplaySmgBit_Select_Numbers=5;
        Number_5bit_DIS(ACAL1_01);
        break;

        case 2://2Ero number display 
        cali_t.CAL1_Id =2;

        menu_t.DisplaySmgBit_Select_Numbers=5;
        Number_5bit_Char_DIS(ACAL1_02);
        break;

        case 3: //SPARn
        cali_t.CAL1_Id =3;

        menu_t.DisplaySmgBit_Select_Numbers=5;
        Number_5bit_DIS(ACAL1_03);
        break;
             
    }
  break;

    //CAL2 MENU

    case CAL2:
       switch(cali_t.CaliSub_02_02_Item){

                  case 0: //dCu numbers display
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                    cali_t.CAL2_Id = 0;
                    Cali_CAL1_ducNumberDis(ACAL2_00[0]);  
                    // printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
                  break;
                  
                  case 1: //CAP number display
                     cali_t.CAL2_Id =1;
              
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                      Number_5bit_DIS(ACAL2_01);
                  break;

                  case 2://2Ero number display 
                  cali_t.CAL2_Id =2;
                
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                      Number_5bit_Char_DIS(ACAL2_02);
                  break;

                  case 3: //SEn 
                        cali_t.CAL2_Id =3;
                        Number_5bit_DIS(ACAL2_03);
                  break;

                  case 4: //SPARn
                      cali_t.CAL2_Id =4;
             
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                          Number_5bit_DIS(ACAL2_04);
                  break;
             
     

      }
    break;

   //CAL3 MENU
    case CAL3:
     switch(cali_t.CaliSub_02_03_Item){

                  case 0: //dCu numbers display
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                    cali_t.CAL3_Id = 0;
                    Symbol_CLS();
                   
                  break;
                  
                  case 1: //CAP number display
                     cali_t.CAL3_Id =1;
              
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                     Symbol_qtY();
                      //Number_5bit_DIS(ACAL3_01);
                  break;

                  case 2://2Ero number display 
                     cali_t.CAL3_Id =2;
                
                      menu_t.DisplaySmgBit_Select_Numbers=5;
                      Number_5bit_Char_DIS(ACAL3_02);
                  break;

                 
             
    }


    break;



   

}
}
/*******************************************************************
 * 
 * Function :display 
 * 
 * 
********************************************************************/
void Calibration_TheFourthRunDis_Cmd(void)
{
     switch(cali_t.CaliMenu_Item){

      case CAL1:
        switch(cali_t.CAL1_sequence_flag){

                  case 0:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                    Symbol_dC_u(); //---0
                  break;


                  case 1: //dCu numbers display
         
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                    cali_t.CAL1_Id = 0;
                    
                    Cali_CAL1_ducNumberDis(ACAL1_00[0]);  
                    // printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
                  break;

                  case 2:
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                       Symbol_CAP();  ///---1
                  break;
                  
                  case 3: //CAP number display
                     cali_t.CAL1_Id =1;
               
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                      Number_5bit_DIS(ACAL1_01);
                  break;

                  case 4:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                      Symbol_2Ero();  ///---2
                  break;

                  case 5://2Ero number display 
                  cali_t.CAL1_Id =2;
              
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    
                      Number_5bit_Char_DIS(ACAL1_02);
                  break;

                  case 6://2Ero number display 
                    cali_t.CAL1_Id =2;
            
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    
                      Number_5bit_Char_DIS(ACAL1_021);
                  break;


                  case 7://2Ero number 2 display
                        menu_t.DisplaySmgBit_Select_Numbers=0;
                        Symbol_SPAn(); ///----3
                  break;

                  case 8: //SPARn
                      cali_t.CAL1_Id =3;
         
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                        
                        Number_5bit_DIS(ACAL1_03);
                  break;

                   case 9: //SPARn number display 
                      cali_t.CAL1_Id =3;
       
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                        
                        Number_5bit_DIS(ACAL1_031);
                  break;
             
     

        }
        break;

        case CAL2:
            switch(cali_t.CAL2_sequence_flag){

                  case 0:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                    Symbol_dC_u(); ///--1
                  break;


                  case 1: //dCu numbers display
         
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                  
                    
                    Cali_CAL1_ducNumberDis(ACAL2_00[0]);  
                    // printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
                  break;

                  case 2:
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                       Symbol_CAP();  //---2
                  break;
                  
                  case 3: //CAP number display
                    
               
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                      Number_5bit_DIS(ACAL2_01);
                  break;

                  case 4:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                      Symbol_2Ero();  //---3
                  break;

                  case 5://2Ero number display 
                
              
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    
                      Number_5bit_Char_DIS(ACAL2_02);
                  break;

                  case 6://2Ero number display 
                
            
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    
                      Number_5bit_Char_DIS(ACAL2_021);
                  break;

                  case 7:
                     Symbol_SEn();
                  break;

                  case 8:
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                         Number_5bit_DIS(ACAL2_03);
                  break;


                  case 9://2Ero number 2 display
                        menu_t.DisplaySmgBit_Select_Numbers=0;
                        Symbol_SPAn();
                  break;

                  case 10: //SPARn
                    
         
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                        
                        Number_5bit_DIS(ACAL2_04);
                  break;

                   case 11: //SPARn number display 
                     
       
                        menu_t.DisplaySmgBit_Select_Numbers=5;
                        
                        Number_5bit_DIS(ACAL2_041);
                  break;
             
     

        }

        break;

        case CAL3:

            switch(cali_t.CAL3_sequence_flag){

                  case 0:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                   Symbol_CLS(); ///--1
                  break;


                  case 1: //dCu numbers display
                    Symbol_qtY();
                   
                    menu_t.DisplaySmgBit_Select_Numbers=0;
                  
                    
                 // printf("runCmd_theThird ACAL1_00 = %d\n",ACAL1_00[0]);
                  break;

                  case 2: //CnS
                      menu_t.DisplaySmgBit_Select_Numbers=0;
                     Symbol_C_nS();

                  break;

                  case 3:
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                     Number_5bit_Char_DIS(ACAL3_02);
                  break;

                  case 4:
                     menu_t.DisplaySmgBit_Select_Numbers=5;
                    Number_5bit_Char_DIS(ACAL3_021);
                  break;

                case 5:
                     menu_t.DisplaySmgBit_Select_Numbers=0;
                     Symbol_ContC();
                break;


         }


        break;

    }
    
}
 

void Cali_CAL1_ducNumberDis(int8_t cal1)
 {
     
     switch(cal1){

        case 0:
              SmgDisplay_Point(digital_1,0); //0.
              SmgDisplay(digital_2,0x0); // 0
              SmgDisplay(digital_3,0x0); //0
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x01); //1
 

        break;

        case 1://0.0002
            SmgDisplay_Point(digital_1,0); //0.
              SmgDisplay(digital_2,0x0); // 0
              SmgDisplay(digital_3,0x0); //0
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x02); //2

        break;

        case 2://0.005
              SmgDisplay_Point(digital_1,0); //0.
              SmgDisplay(digital_2,0x0); // 0
              SmgDisplay(digital_3,0x0); //0
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x05); //5

        break;

        case 3://0.01
             SmgDisplay(digital_1,0x0b); //null
              SmgDisplay(digital_2,0x0b); //null
              SmgDisplay_Point(digital_3,0x0); //0
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x01); //1
        break;

        case 4://0.02
              SmgDisplay(digital_1,0x0b); //null
              SmgDisplay(digital_2,0x0b); //null
              SmgDisplay_Point(digital_3,0x0); //0.
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x02); //1

        break;

        case 5://0.05
           SmgDisplay(digital_1,0x0b); //null
              SmgDisplay(digital_2,0x0b); //null
              SmgDisplay_Point(digital_3,0x0); //0.
              SmgDisplay(digital_4,0x00); //0
              SmgDisplay(digital_5,0x05); //5

        break;

         case 6://0.1
              SmgDisplay(digital_1,0x0b); //null
              SmgDisplay(digital_2,0x0b); //null
              SmgDisplay(digital_3,0x0b); //null
              SmgDisplay_Point(digital_4,0x00); //0.
              SmgDisplay(digital_5,0x01); //1

        break;

        case 7://0.2
            SmgDisplay(digital_1,0x0b); //null
              SmgDisplay(digital_2,0x0b); //null
              SmgDisplay(digital_3,0x0b); //null
              SmgDisplay_Point(digital_4,0x00); //0.
              SmgDisplay(digital_5,0x02); //2


        break;

        case 8: //0.5
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay_Point(digital_4,0x00); //0.
          SmgDisplay(digital_5,0x01); //5


        break;

        case 9://1
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x0b); //null
          SmgDisplay(digital_5,0x01); //1

        break;

        case 10://2
           SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x0b); //null
          SmgDisplay(digital_5,0x02); //2
        break;

        case 11://5
           SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x0b); //null
          SmgDisplay(digital_5,0x05); //5

        break;

        case 12://10
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x01); //1
          SmgDisplay(digital_5,0x00); //0
        break;

        case 13://20
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x02); //2
          SmgDisplay(digital_5,0x00); //0

        break;

        case 14://20
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x02); //0
          SmgDisplay(digital_5,0x00); //0

        break;

        case 15://50
          SmgDisplay(digital_1,0x0b); //null
          SmgDisplay(digital_2,0x0b); //null
          SmgDisplay(digital_3,0x0b); //null
          SmgDisplay(digital_4,0x05); //5
          SmgDisplay(digital_5,0x00); //0

        break;




     }



 } 





