#include "dis.h"

static int8_t one,two,three,four,five;

void Number_Digital_3bit_NoRefDecSelect(void)
{
      if(menu_t.inputNumber_Select==0){
             menu_t.unit--;
            if(menu_t.unit < 0){
               menu_t.unit=9;
            }
            printf("s_1 = %d\n",menu_t.unit);
      }
      else if(menu_t.inputNumber_Select==1){
            menu_t.decade--;
            if(menu_t.decade< 0){
             menu_t.decade=9;
            }
            
            printf("s_2 = %d\n",menu_t.decade);
      
      }
      else if(menu_t.inputNumber_Select ==2){
            menu_t.hundred--;
            if(menu_t.hundred < 0){ 
              menu_t.hundred=9;
            }
         
            printf("s_3 = %d\n",menu_t.hundred);
          
      }
}

void Number_Digital_3bit_NoRefAddSelect(void)
{
        if(menu_t.inputNumber_Select==0){
            menu_t.unit++ ;
            if(menu_t.unit >9){
               menu_t.unit=0;
            }
           
        }
        else if(menu_t.inputNumber_Select==1){
                  menu_t.decade++;
                  if(menu_t.decade >9){
                        menu_t.decade=0;
                  }
                   
       }
      else if(menu_t.inputNumber_Select ==2){
                  menu_t.hundred++;  
                  if(menu_t.hundred >9){
                  menu_t.hundred=0;
            }
           
      }  
}
/*********************************************************************
**********************************************************************/
void Number_Digital_5bit_AddSelect(int8_t *ap)
{
       if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9){
               one=0;
            }
			*ap = one;
      }
      else if(menu_t.inputNumber_Select==1){
                  two++;
                  if(two >9){
                        two=0;
                  }
				  *(ap+1) = two;
       }
      else if(menu_t.inputNumber_Select==2){
                  three++;  
                  if(three >9){
                      three=0;
                   }
				  *(ap+2)=three;
      } 
      else if(menu_t.inputNumber_Select==3){
                  four++;  
                  if(four >9){
                      four=0;
                    }
				  *(ap+3) = four; 
      } 
      else if(menu_t.inputNumber_Select ==4){
                  five++;  
                  if(five >9){
                      five=0;
                    }
			*(ap+4) = five; 
      } 

}

void Number_Digital_5bit_DecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){
               one=9;
            }
			*ap= one;
            printf("s_1 = %d\n",one);
      }
      else if(menu_t.inputNumber_Select==1){
            two--;
            if(two< 0){
               two=9;
            }
			*(ap+1) = two;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select==2){
            three--;
            if(three< 0){ 
               three=9;
            }
			*(ap+2) = three;
            printf("s_3 = %d\n",*(ap+2));
          
      }
      else if(menu_t.inputNumber_Select==3){
             four--;
            if( four < 0){ 
               four=9;
            }
			*(ap+3) = four;
            printf("s_4 = %d\n", *(ap+3));
          
      }
      else if(menu_t.inputNumber_Select ==4){
             five--;
            if( five < 0){ 
                five=9;
            }
		*(ap+4) = five;
            printf("s_4 = %d\n", *(ap+4));
          
      }

}
/************************************************************************/
void Number_Digital_Set5bit_RefAddSelect(int8_t *ap ,uint8_t n)
{
     static  uint8_t  i;
       i++;
       if(i>n)i=1;
       *ap =i;
    //   menu_t.F34_KEY_VALUE = i;
      
}

void Number_Digital_Set5bit_RefDecSelect(int8_t *ap,uint8_t n)
{
     static  int8_t  i=2;
       i--;
      if(i ==0)i=n;
       *ap =i;
       
    //   menu_t.F34_KEY_VALUE = i;
        
}

void Number_Digital_5bitPoint_DecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){ //one == -1 ->display "-"
               one=9;
            }
		*ap= one;
            printf("s_1 = %d\n",one);
      }
      else if(menu_t.inputNumber_Select==1){
            two--;
            if(two< 0){
               two=9;
            }
			*(ap+1) = two;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select==2){
            three--;
            if(three< 0){ 
               three=9;
            }
			*(ap+2) = three;
            printf("s_3 = %d\n",*(ap+2));
          
      }
      else if(menu_t.inputNumber_Select==3){
             four--;
            if( four < 0){ 
               four=9;
            }
			*(ap+3) = four;
            printf("s_4 = %d\n", *(ap+3));
          
      }
      else if(menu_t.inputNumber_Select ==4){
             five--;
            if( five == -2){ 
                five=9;
            }
		*(ap+4) = five;
            printf("s_4 = %d\n", *(ap+4));
          
      }

}

void Number_Digital_5bitPoint_AddSelect(int8_t *ap)
{
       if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9 ){
               one=0;
            }
		*ap = one;
      }
      else if(menu_t.inputNumber_Select==1){
                  two++;
                  if(two >9){
                        two=0;
                  }
				  *(ap+1) = two;
       }
      else if(menu_t.inputNumber_Select==2){
                  three++;  
                  if(three >9){
                      three=0;
                   }
				  *(ap+2)=three;
      } 
      else if(menu_t.inputNumber_Select==3){
                  four++;  
                  if(four >9){
                      four=0;
                    }
				  *(ap+3) = four; 
      } 
      else if(menu_t.inputNumber_Select ==4){
                  five++;  
                  if(five >10){
                      five=0;
                    }
			*(ap+4) = five; 
      } 

}

/*********************************************************************
**********************************************************************/
void Number_Digital_3bit_AddSelect(int8_t *ap)
{
       if(menu_t.inputNumber_Select==0){
            one++ ;
            if(one >9){
               one=0;
            }
			*ap = one;
      }
      else if(menu_t.inputNumber_Select==1){
                  two++;
                  if(two >9){
                        two=0;
                  }
				  *(ap+1) = two;
       }
      else if(menu_t.inputNumber_Select==2){
                  three++;  
                  if(three >9){
                      three=0;
                   }
				  *(ap+2)=three;
      } 

}

void Number_Digital_3bit_DecSelect(int8_t *ap)
{
      if(menu_t.inputNumber_Select==0){
             one--;
            if(one < 0){
               one=9;
            }
			*ap= one;
            printf("s_1 = %d\n",one);
      }
      else if(menu_t.inputNumber_Select==1){
            two--;
            if(two< 0){
               two=9;
            }
			*(ap+1) = two;
            printf("s_2 = %d\n",*(ap+1));
      
      }
      else if(menu_t.inputNumber_Select==2){
            three--;
            if(three< 0){ 
               three=9;
            }
			*(ap+2) = three;
            printf("s_3 = %d\n",*(ap+2));
          
      }
   

}

