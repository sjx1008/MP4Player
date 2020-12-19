#include "App_led.h"

#define LED1_TASK_PRIO		3
#define LED1_STK_SIZE 		50  
TaskHandle_t LED1Task_Handler;
void led1_task(void *pvParameters);


void Led_Init(void)
{
	xTaskCreate(led1_task,"led1_task",LED1_STK_SIZE,NULL,LED1_TASK_PRIO,&LED1Task_Handler);
}

void led1_task(void *pvParameters)
{
	printf("led1\n");
	while(1)
	{
		vTaskDelay(500);
		LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_9 /*| LL_GPIO_PIN_10*/);
		vTaskDelay(500);
		LL_GPIO_ResetOutputPin(GPIOF, LL_GPIO_PIN_9 | LL_GPIO_PIN_10);
	}
}
