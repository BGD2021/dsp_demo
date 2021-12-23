/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#include "arm_math.h"
#include "base.h"
#include "outputdata.h"
#include "ADS8688.h"
#include "hmi_driver.h"
#include "hmi_user_uart.h"
#include "cmd_process.h"
#include "cmd_queue.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED0 PFout(9)	// DS0
#define LED1 PFout(10)	// DS1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
u32 capture_sta=0,period=0;
u8 flag,caltime=0;
u16 t=28;
u16 adcx[500],i=0;
float mean;

//iir
float input[1024],output[1024],IIR_State[8];
const float iir_params[10]={1.0f,2.0f,1.0f,1.4942806864993292f,-0.69434704310417339f,1.0f, 2.0f,1.0f,1.2287186180807914f,-0.39322938197740648f};
arm_biquad_casd_df1_inst_f32 S;
float ScaleValues=0.050016589151210988f*0.041127690974153711f;

//fft
#define FFT_SIZE 1024 //实数序列的长度
float Input[FFT_SIZE],Output[FFT_SIZE],Real_Output[FFT_SIZE];
arm_rfft_fast_instance_f32 FFT;
//初始化该结构体 arm_rfft_fast_f32(&S, Input, Output, 0);//ifft_flag=0是正变换， 为1则是逆 变换

float mean1;
float test[100],fx[500];
const float sin1[256]={/*256点正弦查找表*/
	  0.00000,0.02464,0.04926,0.07385,0.09840,0.12289,0.14730,0.17163,0.19585,0.21995,0.24391,
	  0.26773,0.29139,0.31487,0.33816,0.36124,0.38411,0.40674,0.42912,0.45124,0.47309,0.49466,
	  0.51592,0.53687,0.55749,0.57777,0.59771,0.61728,0.63647,0.65528,0.67370,0.69170,0.70928,
	  0.72643,0.74314,0.75940,0.77520,0.79053,0.80538,0.81974,0.83360,0.84696,0.85980,0.87212,
	  0.88391,0.89516,0.90587,0.91603,0.92564,0.93468,0.94315,0.95106,0.95838,0.96512,0.97128,
	  0.97685,0.98182,0.98620,0.98998,0.99316,0.99573,0.99771,0.99907,0.99983,0.99998,0.99953,
	  0.99846,0.99680,0.99452,0.99164,0.98817,0.98409,0.97941,0.97414,0.96828,0.96183,0.95479,
	  0.94718,0.93899,0.93023,0.92091,0.91102,0.90059,0.88960,0.87808,0.86603,0.85344,0.84034,
	  0.82673,0.81262,0.79802,0.78293,0.76736,0.75133,0.73484,0.71791,0.70054,0.68275,0.66454,
	  0.64593,0.62692,0.60754,0.58779,0.56767,0.54722,0.52643,0.50533,0.48391,0.46220,0.44022,
	  0.41796,0.39545,0.37270,0.34973,0.32654,0.30315,0.27958,0.25584,0.23195,0.20791,0.18375,
	  0.15948,0.13511,0.11065,0.08613,0.06156,0.03695,0.01232,-0.01232,-0.03695,-0.06156,
	  -0.08613,-0.11065,-0.13511,-0.15948,-0.18375,-0.20791,-0.23195,-0.25584,-0.27958,-0.30315,
	  -0.32654,-0.34973,-0.37270,-0.39545,-0.41796,-0.44022,-0.46220,-0.48391,-0.50533,-0.52643,
	  -0.54722,-0.56767,-0.58779,-0.60754,-0.62692,-0.64593,-0.66454,-0.68275,-0.70054,-0.71791,
	  -0.73484,-0.75133,-0.76736,-0.78293,-0.79802,-0.81262,-0.82673,-0.84034,-0.85344,-0.86603,
	  -0.87808,-0.88960,-0.90059,-0.91102,-0.92091,-0.93023,-0.93899,-0.94718,-0.95479,-0.96183,
	  -0.96828,-0.97414,-0.97941,-0.98409,-0.98817,-0.99164,-0.99452,-0.99680,-0.99846,-0.99953,
	  -0.99998,-0.99983,-0.99907,-0.99771,-0.99573,-0.99316,-0.98998,-0.98620,-0.98182,-0.97685,
	  -0.97128,-0.96512,-0.95838,-0.95106,-0.94315,-0.93468,-0.92564,-0.91603,-0.90587,-0.89516,
	  -0.88391,-0.87212,-0.85980,-0.84696,-0.83360,-0.81974,-0.80538,-0.79053,-0.77520,-0.75940,
	  -0.74314,-0.72643,-0.70928,-0.69170,-0.67370,-0.65528,-0.63647,-0.61728,-0.59771,-0.57777,
	  -0.55749,-0.53687,-0.51592,-0.49466,-0.47309,-0.45124,-0.42912,-0.40674,-0.38411,-0.36124,
	  -0.33816,-0.31487,-0.29139,-0.26773,-0.24391,-0.21995,-0.19585,-0.17163,-0.14730,-0.12289,
	  -0.09840,-0.07385,-0.04926,-0.02464,-0.00000};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void delay_out(u8 flag,u16 t);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM5_Init();
  MX_TIM14_Init();
  MX_USART2_UART_Init();
  MX_TIM4_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  delay_init(168);
  ADS8688_Init_Single();
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_IC_Start_IT(&htim5, TIM_CHANNEL_1);
  HAL_TIM_Base_Start(&htim14);
  HAL_TIM_PWM_Start(&htim14, TIM_CHANNEL_1);
  TFT_Init();
  arm_biquad_cascade_df1_init_f32(&S,2,(float *)iir_params,IIR_State);
  arm_rfft_fast_init_f32(&FFT,FFT_SIZE);
  for(i=0;i<1024;i++)
  {
	  fx[i] = 1500*sin(2*PI*i*350.0/6400)+1000+1500*sin(2*PI*i*600.0/6400);
	  input[i]=fx[i];
  }
  arm_biquad_cascade_df1_f32(&S, fx, output, 1024);
  arm_scale_f32(output, ScaleValues,output, 1024);
  arm_rfft_fast_f32(&FFT, output, Output, 0);
  arm_cmplx_mag_f32(Output, Real_Output, FFT_SIZE);
//  for(i=0;i<1024;i++)
//  {
//	  OutData[1]=Real_Output[i];
//	  OutData[0]=fx[i];
//	  OutPut_Data();
//  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(caltime)
	  {
		  arm_mean_f32((float *)&adcx, 500, &mean );
		  caltime=0;
		  HAL_TIM_Base_Start(&htim3);
		  LED1=!LED1;
		  SetTextFloat(0, 16, mean,3, 0);
		  printf("123\r\n");

	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM5)
	{
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1)
		{
			if(!capture_sta)
			{
				delay_out(0,t);
				HAL_TIM_Base_Stop(htim);
				__HAL_TIM_SET_COUNTER(&htim5,0);
				__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_RISING);
				HAL_TIM_Base_Start(htim);
				capture_sta=1;
			}
			else
			{
				delay_out(1,t);
				period=__HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1);
				__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_FALLING);
				capture_sta=0;
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim3)
	{
		adcx[i]=(float)(get_ADS_ch1()-32767)*4096/13128;
		i++;
		if(i>=500)
		{
			i=0;
			caltime=1;
			HAL_TIM_Base_Stop(htim);
		}
	}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_2)
	{
		t+=28;
	}
	else if(GPIO_Pin==GPIO_PIN_3)
	{
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	}
	else if(GPIO_Pin==GPIO_PIN_4)
	{
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	}
}

void delay_out(u8 flag,u16 t)
{
	if(flag)
	{
		delay_us(t);
		LED0=1;
	}
	else
	{
		delay_us(t);
		LED0=0;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
