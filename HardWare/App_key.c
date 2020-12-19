#include "App_key.h"

#define KEY1_TASK_PRIO		2
#define KEY1_STK_SIZE 		50  
TaskHandle_t KEY1Task_Handler;
void KEY1_task(void *pvParameters);

void Key_Init(void)
{
	xTaskCreate(KEY1_task,"KEY1_task",KEY1_STK_SIZE,NULL,KEY1_TASK_PRIO,&KEY1Task_Handler);
}

uint8_t key_value=0;
KEYBIT keybit ;
KVALUE kvalue;
void Key_Scan(void)
{
	key_value=0;
	if(!key0)
		key_value |= 0x01;
	if(!key1)
		key_value |= 0x02;
	if(!key2)
		key_value |= 0x04;
	if(wk_up)
		key_value |= 0x08;
}

void Key_Value(void)
{
	static  uint8_t   key_value0=0;//前一次按键值寄存器
	static  uint8_t   key_value1=0;    //按键释放后的按键值寄存器
	static  uint8_t   key_value2=0;    //按键释放后的按键值寄存器
	static  uint8_t   key_longtime=0;//长按时间累积寄存器1
	static  uint8_t   key_longtime1=0;//长按时间累积寄存器2
	static  uint8_t   key_super_longtime=0;	//超长按时间累积寄存器
	static  uint8_t   F_longkey=0;//长按
	static  uint8_t   F_super_longkey=0;//超长按
	static 	uint8_t	 f_onkey=0;
	static 	uint8_t 	 Key_Hda;
	static	uint8_t 	 KEY_data=0;
	
	if(key_value == key_value0)
	{
		if(key_value>0)
		{
			if(!f_onkey)
			{
				f_onkey = 1;
				if(key_value!=key_value2)
				{
					KEY_data=0;
				}
				if(!kvalue.B_Key_release)
					kvalue.R_key_anxia=key_value;
				key_value1 = key_value;
				key_value2 = key_value;
			}
			else
			{
				
			}
		}
		else
		{
			f_onkey =0;
			if(!kvalue.B_Key_release)
					kvalue.R_key_Open=key_value1;
			else
				{
					kvalue.B_Key_release=0;
					KEY_data=0;
				}
			key_value1 =1;
		}
	}
	else
	{	
		key_value0=key_value;
	}
}

void KEY1_task(void *pvParameters)
{
	while(1)
	{
		Key_Scan();
		Key_Value();
		if(kvalue.R_key_anxia == KEY_MODE)
			LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_10 );
		vTaskDelay(10);//10ms Delay
	}
}

