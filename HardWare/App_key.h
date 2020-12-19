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
	uint8_t	R_key_anxia;			//����
	uint8_t	R_key_Open;				//�ɿ�
	uint8_t	R_key_anxiaOpen;	//�̰��ɿ�
	uint8_t	R_key_anzhuOpen;	//�����ɿ�
	uint8_t	R_key_keep;				//��������
	uint8_t	R_key_super_keep;	//����������
	uint8_t	R_key_1C;					//����1��
	uint8_t	R_key_3C;					//����3��
	uint8_t	R_key_5C;					//����5��
	uint8_t	R_key_anzhu;			//������ס
	uint8_t	B_Key_release;		//�Ƿ񷵻ذ�����ֵ������ȫ���ͷŲ�����
	
}KVALUE;
extern  KVALUE kvalue;

void Key_Init(void);

#endif  

