#ifndef __CALIBRATION_H_
#define __CALIBRATION_H_

#include "main.h"
#define MAX 6

typedef struct POINT{
  
    float x;
    float y;

}Point;

extern Point point_t[MAX];

double GetWegithReal_Value(float n);







#endif 



  