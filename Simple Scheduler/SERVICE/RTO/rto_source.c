#include "../../MCAL/TIMER/timer_interface.h"
#include "rto_privite.h"
#include "rto_interface.h"
#include "rto_configuration.h"
/********** Create array of structure task control block for tasks ***/
static TaskControlBlock TASkS[NUMBER_OF_TASKS];
/*** This function set the timer to calculate the tick time of scheduler ***/
void SCHEDULER_init(void)
{

	/******* SetCallBackFunction to set ISR of timer tack the scheduler mechanism function ***/
//	TIMERS_setCallBackFunction(SELECTION_TIMER,NORMAL_MODE,NUMBER_OF_INTERRUPT_TO_ACHIEVE_TICK_TIME,PRE_LOAD_VALUE,&SCHEDULER_andDispatcherHandling);
	TIMERS_setCallBackFunction(SELECTION_TIMER,NORMAL_MODE,NUMBER_OF_INTERRUPT_TO_ACHIEVE_TICK_TIME,&SCHEDULER_andDispatcherHandling);
	DUTY_cycleForTimers(SELECTION_TIMER,0,PRE_LOAD_VALUE);
	/**** in_it of timer**********/
	iniat_Timer();
}
/*** This respond to create task control block and its function ***/
uint8 TASK_controlBlockOfTask(uint8 PassedPeriorty,uint16 PassedPeriodicity,uint16 PassedFristDelay,void(*PassedPtrFunction)(void))
{
	uint8 LocalErrorStat = NOTOK;
	if((PassedPeriorty < NUMBER_OF_TASKS) && PassedPtrFunction != NULL_PTR)
	{
		TASkS[PassedPeriorty].Peroidicity = PassedPeriodicity ;
		TASkS[PassedPeriorty].FristDelay = PassedFristDelay ;
		TASkS[PassedPeriorty].PointerToFunctionOfTask = PassedPtrFunction;

		LocalErrorStat = OK;
	}
	return LocalErrorStat;
}
/*** This function of scheduler and dispatcher mechanism ***/
static void SCHEDULER_andDispatcherHandling(void)
{
	uint8 LocalCounter;
	for(LocalCounter = 0; LocalCounter < NUMBER_OF_TASKS;  LocalCounter ++)
	{
		if(!TASkS[LocalCounter].FristDelay)
		{
			TASkS[LocalCounter].PointerToFunctionOfTask();
			TASkS[LocalCounter].FristDelay = TASkS[LocalCounter].Peroidicity -TICK_TIME_INTERRUPT ;
		}
		else
		{
			TASkS[LocalCounter].FristDelay -= TICK_TIME_INTERRUPT;	// TASkS[LocalCounter].FristDelay - tick time
		}
	}

}


