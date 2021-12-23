#ifndef _ADS8688_H_ 
#define _ADS8688_H_ 
#include "base.h"
#define ADS_8688_DAISY_IN_H HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET) 
#define ADS_8688_DAISY_IN_L HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET) 
#define ADS_8688_SCLK_H HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET) 
#define ADS_8688_SCLK_L HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET)
#define ADS_8688_nCS_H HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET) 
#define ADS_8688_nCS_L HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET) 
#define ADS_8688_RST_PD_H HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET)
#define ADS_8688_RST_PD_L HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET) 
#define ADS_8688_SDI_H HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3,GPIO_PIN_SET) 
#define ADS_8688_SDI_L HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3,GPIO_PIN_RESET) 
#define ADS_8688_SDO HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6)

//Command Register 
#define NO_OP 0X0000 
#define STDBY 0X8200 
#define PWR_DN 0X8300 
#define RST 0X8500 
#define AUTO_RST 0XA000 
#define MAN_Ch_1 0XC000 
#define MAN_Ch_2 0XC400 
#define MAN_Ch_3 0XC800 
#define MAN_Ch_4 0XCC00 
#define MAN_Ch_5 0XD000
#define MAN_Ch_6 0XD400 
#define MAN_Ch_7 0XD800
#define MAN_Ch_8 0XDC00 
#define MAN_AUX 0XE000 
#define CH1 0x05 
#define CH2 0x06 
#define CH3 0x07 
#define CH4 0x08 
#define CH5 0x09 
#define CH6 0x0a 
#define CH7 0x0b 
#define CH8 0x0c 
void ADS8688_Init_Single(void); 
u16 get_ADS_ch1(void); 
void ADS8688_Init_Mult(void); 
void get_ADS_allch(float*result); 
void Get_AUTO_RST_Mode_Data(uint16_t* outputdata, uint8_t chnum); 
void AUTO_RST_Mode(void); 
#endif
