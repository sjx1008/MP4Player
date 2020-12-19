#ifndef __App_key_H
#define __App_key_H

#include "Include.h"

#define  key2   LL_GPIO_IsInputPinSet(GPIOE, LL_GPIO_PIN_2)
#define  key1   LL_GPIO_IsInputPinSet(GPIOE, LL_GPIO_PIN_3)
#define  key0   LL_GPIO_IsInputPinSet(GPIOE, LL_GPIO_PIN_4)
#define  wk_up  LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0)

typedef enum KEYBIT
{
	KEY_MODE=0x02,//s3
	KEY_ADD=0x04,//s2
	KEY_SUB=0x02,//s1
	KEY_M =0x08,
	KEY_MODE_ADD=0x06,//
	KEY_MODE_SUB=0x04,//
//  KEY_ADD_SUB=0x03,
	KEY_NOP=0xFF,
}KEYBIT;

typedef struct 
{
	uint8_t	R_key_anxia;			//按下
	uint8_t	R_key_Open;				//松开
	uint8_t	R_key_anxiaOpen;	//短按松开
	uint8_t	R_key_anzhuOpen;	//长按松开
	uint8_t	R_key_keep;				//长按按下
	uint8_t	R_key_super_keep;	//超长按按下
	uint8_t	R_key_1C;					//按键1次
	uint8_t	R_key_3C;					//按键3次
	uint8_t	R_key_5C;					//按键5次
	uint8_t	R_key_anzhu;			//长按按住
	uint8_t	B_Key_release;		//是否返回按键键值，按键全部释放才清零
	
}KVALUE;
extern  KVALUE kvalue;

void Key_Init(void);

#endif  

