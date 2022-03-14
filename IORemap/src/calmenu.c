#include "calmenu.h"

cali cali_t;
 int8_t caliMainTop =-1  ;
int8_t caliSun_02_Top  = -1;
int8_t caliSubMenu_03_Top  =-1;


int cone,ctwo,cthree,cfour,cfive;

int8_t ACAL301[3];
int8_t ACAL302[5];
int8_t ACAL303[3];
int8_t ACAL304[4];
int8_t ACAL305[5];

int8_t ACAL30201[3];
int8_t ACAL30202[4];
int8_t ACAL30203[5];
int8_t ACAL30204[5];
int8_t ACAL30205[4];

int8_t ACAL30301[2];
int8_t ACAL30302[5];
int8_t ACAL30303[3];

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

 static void Number_Digital_0bit_(uint8_t unit);

static void CaliSubMenu_fourPoint_3bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred);
static void CaliSubMenu_fourPoint_2bitPoint_Dis(int8_t unit,int8_t decade);
static void CaliSubMenu_fourPoint_5bitPoint_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);

 static void CaliSubMenu_02_01_Dis(uint8_t n);
 
static void CaliSubMenu_02_02_Dis(uint8_t n);

static void CaliSubMenu_02_03_Dis(uint8_t);
static void CaliSubMenu_03_05_Dis(void);

 
 static void caliSubMenu_03_01_3bit_Dis(int8_t unit,int8_t decade,int8_t hundred);
 static void caliSubMenu_03_02_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand); //CaliSubMenu_03_01_01_5bitPoint(ACAL302);
 static void caliSubMenu_03_4bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand); //CaliSubMenu_03_01_01_3bitPoint(ACAL303);   

static void caliNumber_Digital_5bit_AddSelect(int8_t *ap);
static void caliNumber_Digital_5bit_DecSelect(int8_t *ap);

static void caliSubMenu_onePoint_5bit_Dis(int8_t unit,int8_t decade,int8_t hundred,int8_t onethousand,int8_t tenthousand);
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

       case CAL5: //CAL5
             cali_t.CaliMenu_01_Id =CAL5;
             SmgDisplay(digital_4,0x05); //'5' 
       break;
       default:

       break;
     }

}

void CALI_MENU_SUB_02_DIS(uint8_t mu)
{

     switch(cali_t.CaliMenu_Item){

        case CAL1://dC-u,CAP,2Ero, SPAn
              cali_t.CaliMenu_02_Id = CAL1;
              CaliSubMenu_02_01_Dis(mu);
          

        break;

        case CAL2: //dC-u,CAP,2Ero,SEn,SPARn
                cali_t.CaliMenu_02_Id = CAL2;
                CaliSubMenu_02_02_Dis(mu);
                
        break;

        case CAL3://CLS ,QtY,C-nS
             cali_t.CaliMenu_02_Id = CAL3;
            CaliSubMenu_02_03_Dis(mu);
        break;

        case CAL5:
            cali_t.CaliMenu_02_Id = CAL5;
            cali_t.CaliMenu_02_sub_Id =0xff;
             menu_t.DisplaySmgBit_Select_Numbers=0;
            CaliSubMenu_03_05_Dis();
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
	return  caliMainTop ;

}
uint8_t Pop_stackCaliMain(int8_t maxsize)
{
       caliMainTop-- ;
       if(caliMainTop ==-1 ||caliMainTop <0 ){
	      caliMainTop = (maxsize -1);
       }
	  
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

int8_t CaliSub_02_stackTop(void)
{
    
    return caliSubMenu_03_Top  ;
}

/*******************************************************************
 * 
 * Calibration of key Function "Item"
 *
 *Function :select which's menu item ?  adjust how many sub menu ?
 *
 *
 *******************************************************************/
void KEY4_InputCalibration_Mode(void)
{
     if(cali_t.Thefirst_InputKeyValue==0){
       cali_t.Thefirst_InputKeyValue++;
      cali_t.CaliControl_key=1; 
     mainitem_t.task_MainMenu = caliTheFirst_Menu ;
     caliMainTop=-1;
     cali_t.CaliMenu_Item = Push_stackCaliMain(4);
     key_t.keyPressedLongTimes=1;

     printf("Cali_keyEnter_1 = %d\n",cali_t.CaliMenu_Item);
	   printf("task_MainMenu_1 = %d\n", caliTheFirst_Menu);
     }

	 
}

void CAL_KEY4_ENTER_Fun(void)
{
    

     
     cali_t.keyEnter_flag ++; //= cali_t.keyEnter_flag ^ 0x01;

     if(cali_t.keyEnter_flag == 1){//{ //CAL1->{dC-u,CAP,2Ero,SPARn}
            
        mainitem_t.task_MainMenu = caliTheSecond_Menu; 
        if(run_t.keyReturn ==1){
          cali_t.CaliMenu_02_sub_Id=0;
          cali_t.CaliSub_theSecond_02_Item=0;
          run_t.keyReturn=0;
          mainitem_t.task_MainMenu = caliTheFirst_Menu; 
		  printf("run_t.keyReturn " );
        }
        else 
             cali_t.CaliSub_theSecond_02_Item=cali_t.CaliMenu_02_sub_Id;
          printf("keyEnter_second = %d\n",  cali_t.CaliMenu_02_sub_Id );
        //By test is success
     }
     else if(cali_t.keyEnter_flag == 2){//CAL->dC-u -> 0.00
         
            if(menu_t.DisplaySmgBit_Select_Numbers==0){
                mainitem_t.task_MainMenu = caliTheFirst_Menu ;
                menu_t.DisplaySmgBit_Select_Numbers=0xff;
                return ;
              }
            else{
            mainitem_t.task_MainMenu = caliTheThird_Menu;  //select Item
            cali_t.CaliSub_Menu_03_Title = cali_t.CaliMenu_02_sub_Id; //execut codes
            }
             
        }
     else{
         cali_t.keyEnter_flag=0;
        mainitem_t.task_MainMenu = caliTheFirst_Menu ;
        cali_t.CaliMenu_Item=CaliMain_stackTop();
        
       

     }
      cali_t.runKeyMenu=mainitem_t.task_MainMenu;
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

        cali_t.CaliMenu_Item = Push_stackCaliMain(4);
         printf("cali_t.CaliMenu_Item = %d\n", cali_t.CaliMenu_Item );
    break;

    case caliTheSecond_Menu:
         
           switch(cali_t.CaliMenu_Item){
           
        
            case CAL1:
                    
                    cali_t.CaliSub_02_01_Item  =  Push_stackCaliMain_02(4);
                    cali_t.CaliSub_theSecond_02_Item =cali_t.CaliSub_02_01_Item;
                   
                break;

            case CAL2:
                    cali_t.CaliSub_02_02_Item  =  Push_stackCaliMain_02(5);
                    cali_t.CaliSub_theSecond_02_Item  =cali_t.CaliSub_02_02_Item;
            break;

            case CAL3:
                cali_t.CaliSub_02_03_Item  =  Push_stackCaliMain_02(3);
                cali_t.CaliSub_theSecond_02_Item  =cali_t.CaliSub_02_03_Item;

            break;

            case CAL5:
                    
            break;
            } 
            
        
      break;


     case caliTheThird_Menu:
         
          switch(cali_t.CaliMenu_Item){
                case CAL1:

                  switch(cali_t.CaliSub_Menu_03_Title){

                     case 0:
                       printf("upkey_03_cal_0 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                      Number_Digital_3bit_PointerAddSelect(ACAL301);
                        cali_t.unit =ACAL301[0];
                        cali_t.decade = ACAL301[1];
                        cali_t.hundred = ACAL301[2];
                        
                break;

                case 1: //up+
                  printf("upkey_03_cal_1 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    caliNumber_Digital_5bit_AddSelect(ACAL302);
                        cali_t.unit =ACAL302[0];
                        cali_t.decade = ACAL302[1];
                        cali_t.hundred = ACAL302[2];
                        cali_t.onethousand=ACAL302[3];
                        cali_t.tenthousand =ACAL302[4];

                        break;

                case 2:
                  printf("upkey_03_cal_2 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    Number_Digital_3bit_PointerAddSelect(ACAL303);
                    cali_t.unit =ACAL303[0];
                        cali_t.decade = ACAL303[1];
                        cali_t.hundred = ACAL303[2];
                    

                break;

                case 3:
                          printf("upkey_03_cal_3 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                        Number_Digital_4bit_AddSelect(ACAL304);
                        cali_t.unit =ACAL304[0];
                        cali_t.decade = ACAL304[1];
                        cali_t.hundred = ACAL304[2];
                        cali_t.onethousand= ACAL304[3];
                        

                break;




                  }
            break;
           //CAL2 -------------------------------
           case CAL2:
           
            switch(cali_t.CaliSub_Menu_03_Title){

                     case 0: //dC-u
                       printf("upkey_03_cal_0 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                      Number_Digital_3bit_PointerAddSelect(ACAL30201);
                        cali_t.unit =ACAL30201[0];
                        cali_t.decade = ACAL30201[1];
                        cali_t.hundred = ACAL30201[2];
                        
                break;

                case 1: //up+ //CAP
                  printf("upkey_03_cal_1 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    Number_Digital_4bit_AddSelect(ACAL30202);
                        cali_t.unit =ACAL30202[0];
                        cali_t.decade = ACAL30202[1];
                        cali_t.hundred = ACAL30202[2];
                        cali_t.onethousand=ACAL30202[3];
                      

                        break;

                case 2: //2Ero
                  printf("upkey_03_cal_2 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                     caliNumber_Digital_5bit_AddSelect(ACAL30203);
                    cali_t.unit =ACAL30203[0];
                        cali_t.decade = ACAL30203[1];
                        cali_t.hundred = ACAL30203[2];
                         cali_t.onethousand = ACAL30203[3];
                           cali_t.tenthousand = ACAL30203[4];
                    

                break;

                case 3:
                
                          printf("upkey_03_cal_3 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                        caliNumber_Digital_5bit_AddSelect(ACAL30204);
                        cali_t.unit =ACAL30204[0];
                        cali_t.decade = ACAL30204[1];
                        cali_t.hundred = ACAL30204[2];
                        cali_t.onethousand= ACAL30204[3];
                         cali_t.tenthousand= ACAL30204[4];

                break;
                case 4:
                          printf("upkey_03_cal_3 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                        Number_Digital_4bit_AddSelect(ACAL30205); //  Number_Digital_4bit_AddSelect(ACAL304);
                        cali_t.unit =ACAL30205[0];
                        cali_t.decade = ACAL30205[1];
                        cali_t.hundred = ACAL30205[2];
                        cali_t.onethousand= ACAL30205[3];
                        

                break;
           

		 }
        break;
        
        
        //CAL3------------------------------------------------------------
        case CAL3:
            switch(cali_t.CaliSub_Menu_03_Title){
                    case 0: //dC-u
                       printf("upkey_03_cal_0 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                     Number_Digital_2bit_AddSelect(ACAL30301);
                        cali_t.unit =ACAL30301[0];
                        cali_t.decade = ACAL30301[1];
                      
                        
                break;

                case 1: //up+ //CAP
                  printf("upkey_03_cal_2 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    caliNumber_Digital_5bit_AddSelect(ACAL30302);
                    cali_t.unit =ACAL30302[0];
                        cali_t.decade = ACAL30302[1];
                        cali_t.hundred = ACAL30302[2];
                         cali_t.onethousand= ACAL30302[3];
                           cali_t.tenthousand = ACAL30302[4];
                    

                        break;

                case 2: //2Ero
                      Number_Digital_3bit_PointerAddSelect(ACAL30303);
                        cali_t.unit =ACAL30303[0];
                        cali_t.decade = ACAL30303[1];
                        cali_t.hundred = ACAL30303[2];
                        

                break;
                
                case 3:
                    Number_Digital_0bit_(0);
                       
                break;
            }
        
        break;
        
        case CAL5:
            
              
          Number_Digital_0bit_(0);
                       
       
        
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


        cali_t.CaliMenu_Item = Pop_stackCaliMain(4);
        printf("cali_t.CaliMenu_Item_pop = %d\n", cali_t.CaliMenu_Item );
    break;

    case caliTheSecond_Menu:
          
          switch(cali_t.CaliMenu_Item){
           
        
     
           case CAL1:

                cali_t.CaliSub_02_01_Item  =  Pop_stackCaliMain_02(4);
                 cali_t.CaliSub_theSecond_02_Item =cali_t.CaliSub_02_01_Item;
            break;

          case CAL2:
                cali_t.CaliSub_02_02_Item  =  Pop_stackCaliMain_02(5);
               cali_t.CaliSub_theSecond_02_Item =cali_t.CaliSub_02_02_Item;
          break;

          case CAL3:
               cali_t.CaliSub_02_03_Item  =  Pop_stackCaliMain_02(3);
              cali_t.CaliSub_theSecond_02_Item =cali_t.CaliSub_02_03_Item;

          break;

          case CAL5:
                  
          break;
	  }
          

      break;


     case caliTheThird_Menu:
         
          switch(cali_t.CaliMenu_Item){

            case CAL1:

                  switch(cali_t.CaliSub_Menu_03_Title){

                     case 0:
                      Number_Digital_3bit_PointerDecSelect(ACAL301);
                        cali_t.unit =ACAL301[0];
                        cali_t.decade = ACAL301[1];
                        cali_t.hundred = ACAL301[2];
                        
                break;

                case 1: //up+
                    caliNumber_Digital_5bit_DecSelect(ACAL302);
                        cali_t.unit =ACAL302[0];
                        cali_t.decade = ACAL302[1];
                        cali_t.hundred = ACAL302[2];
                        cali_t.onethousand=ACAL302[3];
                        cali_t.tenthousand =ACAL302[4];

                        break;

                case 2:
                    Number_Digital_3bit_PointerDecSelect(ACAL303);
                    cali_t.unit =ACAL303[0];
                        cali_t.decade = ACAL303[1];
                        cali_t.hundred = ACAL303[2];
                    

                break;

                case 3:
                        Number_Digital_4bit_DecSelect(ACAL304);
                        cali_t.unit =ACAL304[0];
                        cali_t.decade = ACAL304[1];
                        cali_t.hundred = ACAL304[2];
                        cali_t.onethousand= ACAL304[3];
                        

                break;

                  }

            break;
                  
            //CAL2
            case CAL2:
                 switch(cali_t.CaliSub_Menu_03_Title){

                     case 0: //dC-u
                       printf("upkey_03_cal_0 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                      Number_Digital_3bit_PointerDecSelect(ACAL30201);
                        cali_t.unit =ACAL30201[0];
                        cali_t.decade = ACAL30201[1];
                        cali_t.hundred = ACAL30201[2];
                        
                break;

                case 1: //up+ //CAP
                  printf("upkey_03_cal_1 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                     Number_Digital_4bit_DecSelect(ACAL30202);
                        cali_t.unit =ACAL30202[0];
                        cali_t.decade = ACAL30202[1];
                        cali_t.hundred = ACAL30202[2];
                        cali_t.onethousand=ACAL30202[3];
                       

                        break;

                case 2: //2Ero
                  printf("upkey_03_cal_2 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    caliNumber_Digital_5bit_DecSelect(ACAL30203);
                    cali_t.unit =ACAL30203[0];
                        cali_t.decade = ACAL30203[1];
                        cali_t.hundred = ACAL30203[2];
                         cali_t.onethousand= ACAL30203[3];
                           cali_t.tenthousand = ACAL30203[4];
                    

                break;

                case 3:
                          printf("upkey_03_cal_3 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                        caliNumber_Digital_5bit_DecSelect(ACAL30204);
                        cali_t.unit =ACAL30204[0];
                        cali_t.decade = ACAL30204[1];
                        cali_t.hundred = ACAL30204[2];
                        cali_t.onethousand= ACAL30204[3];
                         cali_t.tenthousand= ACAL30204[4];

                break;
                case 4:
                          printf("upkey_03_cal_3 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                           Number_Digital_4bit_DecSelect(ACAL30205);
                        cali_t.unit =ACAL30205[0];
                        cali_t.decade = ACAL30205[1];
                        cali_t.hundred = ACAL30205[2];
                        cali_t.onethousand= ACAL30205[3];
                        

                break;
                  
                  
			  }
		break;
        
        //CAL3 down - 
        case CAL3:
               switch(cali_t.CaliSub_Menu_03_Title){
                    case 0: //dC-u
                       printf("upkey_03_cal_0 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                     Number_Digital_2bit_DecSelect(ACAL30301);
                        cali_t.unit =ACAL30301[0];
                        cali_t.decade = ACAL30301[1];
                      
                        
                break;

                case 1: //up+ //CAP
                  printf("upkey_03_cal_2 = %d\n" ,cali_t.CaliSub_Menu_03_Title);
                    caliNumber_Digital_5bit_DecSelect(ACAL30302);
                    cali_t.unit =ACAL30302[0];
                        cali_t.decade = ACAL30302[1];
                        cali_t.hundred = ACAL30302[2];
                         cali_t.onethousand= ACAL30302[3];
                           cali_t.tenthousand = ACAL30302[4];
                    

                        break;

                case 2: //2Ero
                      Number_Digital_3bit_PointerDecSelect(ACAL30303);
                        cali_t.unit =ACAL30303[0];
                        cali_t.decade = ACAL30303[1];
                        cali_t.hundred = ACAL30303[2];
                        

                break;
                
                case 3:
                        Number_Digital_0bit_(0);
                        
                        
                break;
            }
        
        break;
        
        case CAL5:
              
              Number_Digital_0bit_(0);
                       
        
        break;

        }
	break;

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
         key_t.RunCmd_flag=0; //normal display flag 
         key_t.keyPressedLongTimes=0;
         cali_t.CaliControl_key=0; //F1~F9 function and calibration funcont flag
         cali_t.Thefirst_InputKeyValue=0;
         key_t.keyGetLong_Numbers=0;
         run_t.Fx_Menu_Function=0;
        
       
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

static void caliNumber_Digital_5bit_AddSelect(int8_t *ap)
{
       if(menu_t.inputNumber_Select==0){
            cone++ ;
            if(cone >9){
               cone=0;
            }
			*ap = cone;
      }
      else if(menu_t.inputNumber_Select==1){
                  ctwo++;
                  if(ctwo >9){
                        ctwo=0;
                  }
				  *(ap+1) = ctwo;
       }
      else if(menu_t.inputNumber_Select==2){
                  cthree++;  
                  if(cthree >9){
                      cthree=0;
                   }
				  *(ap+2)=cthree;
      } 
      else if(menu_t.inputNumber_Select==3){
                  cfour++;  
                  if(cfour >9){
                      cfour=0;
                    }
				  *(ap+3) = cfour; 
      } 
      else if(menu_t.inputNumber_Select ==4){
                  cfive++;  
                  if(cfive >9){
                      cfive=0;
                    }
			*(ap+4) = cfive; 
      } 

}
static void caliNumber_Digital_5bit_DecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             cone--;
            if(cone < 0){ //one == -1 ->display "-"
               cone=9;
            }
		*ap= cone;
            printf("s_1 = %d\n",cone);
      }
      else if(menu_t.inputNumber_Select==1){
            ctwo--;
            if(ctwo< 0){
               ctwo=9;
            }
			*(ap+1) = ctwo;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select==2){
            cthree--;
            if(cthree< 0){ 
               cthree=9;
            }
			*(ap+2) = cthree;
            printf("s_3 = %d\n",*(ap+2));
          
      }
      else if(menu_t.inputNumber_Select==3){
             cfour--;
            if( cfour < 0){ 
               cfour=9;
            }
			*(ap+3) = cfour;
            printf("s_4 = %d\n", *(ap+3));
          
      }
      else if(menu_t.inputNumber_Select ==4){
             cfive--;
            if( cfive <0){ 
                cfive=9;
            }
		*(ap+4) = cfive;
            printf("s_4 = %d\n", *(ap+4));
          
      }

}
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

static void CaliSubMenu_03_05_Dis(void)
{
   Symbol_ContC(); 

}

static void Number_Digital_0bit_(uint8_t unit)
{
    
    unit =0;
    
}
