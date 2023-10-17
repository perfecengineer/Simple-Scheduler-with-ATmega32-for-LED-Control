#ifndef RTO_PRIVTE_H
#define RTO_PRIVTE_H

#include "../../UTILS/STD_TYPES.h"
/*** Create structure contain of the task control block ***/
typedef struct{
	uint16 Peroidicity;
	uint16 FristDelay;
	void (*PointerToFunctionOfTask)(void);
}TaskControlBlock;
/*** This function of scheduler and dispatcher mechanism ***/
static void SCHEDULER_andDispatcherHandling(void);










#endif
