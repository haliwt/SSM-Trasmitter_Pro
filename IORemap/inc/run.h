#ifndef __RUN_H_
#define __RUN_H_
#include "main.h"

typedef struct _RUN{
  
    uint8_t dispCmd;


}run;

extern run run_t;
void CheckMode(uint8_t mydata);
void RunCommand(void);




#endif 
