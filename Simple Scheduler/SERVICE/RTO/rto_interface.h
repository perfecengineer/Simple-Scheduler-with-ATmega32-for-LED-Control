#ifndef RTO_INTERFACE_H
#define RTO_INTERFACE_H
#include "../../UTILS/STD_TYPES.h"

/*** This function set the timer to calculate the tick time of scheduler ***/
void SCHEDULER_init(void);
/*** This respond to create task control block and its function ***/
uint8 TASK_controlBlockOfTask(uint8 periorty,uint16 periodicity,uint16 frist_delay,void(*ptr_function)(void));








#endif
