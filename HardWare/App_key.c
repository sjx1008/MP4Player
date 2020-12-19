#include "App_key.h"

#define KEY1_TASK_PRIO		2
#define KEY1_STK_SIZE 		50  
TaskHandle_t KEY1Task_Handler;
void KEY1_task(void *pvParameters);

void Key_Init(void)
{
	xTaskCreate(KEY1_task,"KEY1_task",KEY1_STK_SIZE,NULL,KEY1_TASK_PRIO,&KEY1Task_Handler);
}

void KEY1_task(void *pvParameters)
{
	while(1)
	{
		
		vTaskDelay(10);//10ms Delay
	}
}
