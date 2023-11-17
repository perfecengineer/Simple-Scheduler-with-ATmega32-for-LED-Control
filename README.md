# Simple-Scheduler-with-ATmega32-for-LED-Control
Title: Real-Time Operating System (RTOS) Scheduler for LED Control with ATmega32

Description:

This embedded system project focuses on implementing a simple Real-Time Operating System (RTOS) scheduler using the ATmega32 microcontroller. The project's goal is to manage three independent tasks that control the state of three LEDs, turning them on and off in specific time intervals. The RTOS scheduler ensures precise timing and synchronization of these tasks.

Components:

ATmega32 Microcontroller: The ATmega32 serves as the central unit for task scheduling and execution, managing the timing of LED control tasks.

3 LEDs: Three LEDs serve as the output devices that will be controlled by the tasks to indicate their state (on or off).

Timer Peripheral: A timer peripheral in the ATmega32 is used to generate accurate time intervals and execute tasks at specified time points.

Functionality:

Task Management: The RTOS scheduler manages three independent LED control tasks.

Task Execution: Each task is responsible for toggling the state of one of the three LEDs (on/off) at predefined time intervals.

Precise Timing: The timer peripheral ensures accurate timing, allowing each task to execute its control actions at the specified time points.
