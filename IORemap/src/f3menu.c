#include "f3menu.h"








/*******************F3-01-01**********************************
 * 
 * Display F3-1.1 F3-2.2 /F3-1.2 F3-2.2 /F3-1.3 F3-2.3
 * 
 * 
 * 
*************************************************************/
void F3SubMenu_03_Item(uint8_t mf301)
{

       switch(mf301){

        case F301 : //display -> 3bit
           // menu_t.F3SubMenu_Id_03=F301;

           switch(AF3401[0]){

               case 0:

               break;

               case 1:
                        SmgDisplay(digital_5,0x01); // 0~100
               break;

                case 2:
                        SmgDisplay(digital_5,0x02); // 0~100
               break;

             case 3:
                        SmgDisplay(digital_5,0x03); // 0~100
               break;

               case 4:
                        SmgDisplay(digital_5,0x04); // 0~100
               break;

                case 5:
                        SmgDisplay(digital_5,0x05); // 0~100
               break;

                case 6:
                        SmgDisplay(digital_5,0x07); // 0~100
               break;

                case 7:
                        SmgDisplay(digital_5,0x07); // 0~100
               break;


           }
            
        break;

        case F302 : //"5BIT" has "-"

              switch(AF3402[0]){

               case 0:

               break;

               case 1:
                        SmgDisplay(digital_5,0x01); // 0~100
               break;

                case 2:
                        SmgDisplay(digital_5,0x02); // 0~100
               break;

             case 3:
                        SmgDisplay(digital_5,0x03); // 0~100
               break;

               case 4:
                        SmgDisplay(digital_5,0x04); // 0~100
               break;

                case 5:
                        SmgDisplay(digital_5,0x05); // 0~100
               break;

                case 6:
                        SmgDisplay(digital_5,0x07); // 0~100
               break;

                case 7:
                        SmgDisplay(digital_5,0x07); // 0~100
               break;


           }
            
        break;
          
        break;

        default:

        break;
    }



}
