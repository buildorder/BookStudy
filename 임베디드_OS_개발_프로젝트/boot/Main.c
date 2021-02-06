#include "stdint.h"
#include "HalUart.h"
#include "HalInterrupt.h"
#include "stdio.h"
#include "HalTimer.h"
#include "stdlib.h"

static void Hw_init(void);
static void Printf_test(void);
static void Timer_test(void);

void User_task0(void);
void User_task1(void);
void User_task2(void);

void main(void)
{
	Hw_init();

	uint32_t i = 100;
	while(i--)
	{
		Hal_uart_put_char('N');
	}
	Hal_uart_put_char('\n');

	putstr("Hello World!\n");

	Printf_test();
	Timer_test();

	while(1);
}

static void Hw_init(void)
{
	Hal_interrupt_init();
	Hal_uart_init();
	Hal_timer_init();
}

static void Printf_test(void)
{
	char* str = "printf pointer test";
	char* nullptr = 0;
	uint32_t i = 5;

	debug_printf("%s\n", "Hello printf");
	debug_printf("output string pointer: %s\n", str);
	debug_printf("%s is null pointer, %u number\n", nullptr, 10);
	debug_printf("%u = 5\n", i);
	debug_printf("dec=%u hex=%x\n", 0xff, 0xff);
	debug_printf("print zero %u\n", 0);
}

static void Timer_test(void)
{
	while(1)
	{
		debug_printf("current count : %u\n", Hal_timer_get_1ms_counter());
		delay(1000);
	}
}

static void Kernel_init(void)
{
	uint32_t taskId;

	Kernel_task_init();

	taskId = Kernel_task_create(User_task0);
	if (NOT_ENOUGH_TASK_NUM == taskId)
	{
		putstr("Task0 creation fail\n");
	}
	
	taskId = Kernel_task_create(User_task1);
	if (NOT_ENOUGH_TASK_NUM == taskId)
	{
		putstr("Task0 creation fail\n");
	}
	
	taskId = Kernel_task_create(User_task2);
	if (NOT_ENOUGH_TASK_NUM == taskId)
	{
		putstr("Task0 creation fail\n");
	}
}

void User_task0(void)
{
	debug_printf("User Task #0\n");

	while(1);
}

void User_task1(void)
{
	debug_printf("User Task #1\n");

	while(1);
}

void User_task2(void)
{
	debug_printf("User Task #2\n");

	while(1);
}
