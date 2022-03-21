#include "calibration.h"
Point point_t[MAX];
static void Linear_Regression(void);

float a,b;
double  WeightRealValue;

static void Linear_Regression(void)
{
     uint8_t i;
     float mxy,xx,yy,x2,x22;

    for(i=0;i<5;i++){

         mxy =5.0*point_t[i].x *point_t[i].y+mxy;
         xx =1.0*point_t[i].x+xx;
         yy = 1.0*point_t[i].y +yy;
         x2=1.0*point_t[i].x * point_t[i].x*5.0+x2;
         x22 = 1.0*point_t[i].x+x22;
    }

    b= 1.0*(mxy-xx*yy)/(x2-x22*x22);
    a = 1.0*yy/5.0 - b*xx/5.0;


}


double GetWegithReal_Value(float n)
{
     Linear_Regression();
     WeightRealValue = a+ b*n;

     return WeightRealValue ;

}


