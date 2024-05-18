/*
 * Created on: 19/12/2023:08:25 PM
 * Author: Mohamed Ashour Hassan
 */
#include "../HAL/LED/led_interface.h"
#include "../SERVICE/RTO/rto_interface.h"
#include "../MCAL/GLOBAL_INTERRUPT/global.h"
/*** The prototype of Passed function to Task 1 ***/
void TASK_function1(void);
/*** The prototype of Passed function to Task 2 ***/
void TASK_function2(void);
/*** The prototype of Passed function to Task 3 ***/
void TASK_function3(void);
void main(void)
{
/*** Enable the Global interrupt ***/
	GLOBAL_interruptEnable();
/*** Active the First led for the First task ***/
	LED_initForPin(PORTA_ID,PIN0);
/*** Active the Second led for the Second task ***/
	LED_initForPin(PORTA_ID,PIN1);
/*** Active the Third led for the Third task ***/
	LED_initForPin(PORTA_ID,PIN2);
/*** The initial function to handle the Scheduler setting ***/
	SCHEDULER_init();
/*** Each Task Toggle certain led on port A ***/
/*
 * Run the first task by TCB:
 * 1- priority -> 0
 * 2- First Delay -> 300 ms
 * 3- periodicity -> 500 ms
 */
	TASK_controlBlockOfTask(0,500,300,&TASK_function1);
/*
 * Run the first task by TCB:
* 1- priority -> 1
* 2- First Delay -> 350 ms
* 3- periodicity -> 1500 ms
*/
	TASK_controlBlockOfTask(1,1500,350,&TASK_function2);
/*
* Run the first task by TCB:
* 1- priority -> 2
* 2- First Delay -> 1000 ms
* 3- periodicity -> 1700 ms
*/
	TASK_controlBlockOfTask(2,1700,1000,&TASK_function3);
	while(1);
}
/*** The implementation of Passed function to Task 1 ***/
void TASK_function1(void)
{
	/*** The function used to toggle led ***/
	LED_enable(PORTA_ID,PIN0,LED_TOGGLE);
}
/*** The implementation of Passed function to Task 2 ***/
void TASK_function2(void)
{
	/*** The function used to toggle led ***/
	LED_enable(PORTA_ID,PIN1,LED_TOGGLE);
}
/*** The implementation of Passed function to Task 3 ***/
void TASK_function3(void)
{
	/*** The function used to toggle led ***/
	LED_enable(PORTA_ID,PIN2,LED_TOGGLE);
}
