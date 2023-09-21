/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void clearNumberOnClock(int);
void setNumberOnClock(int);
void clearAllClock (){
 // TODO
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4| GPIO_PIN_5|GPIO_PIN_6| GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, 1);
}
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int hour = 0, minute = 0,  second = 0;
  while (1)
  {
	  /* USER CODE END WHILE */
	  clearAllClock();
	  setNumberOnClock(second/5);
	  setNumberOnClock(minute/5);
	  setNumberOnClock(hour);
	  second++;
	  if(second == 60)
	  {
		  minute++;
		  second = 0;
		  if(minute /5 == 12)
		  {
			  minute = 0;
			  hour++;
		  }
		  if(hour == 12)
			  hour = 0;
	  }
	  HAL_Delay(10);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void setNumberOnClock(int num)
{
	 if (num >= 0 && num <= 11)
	 {
	switch (num)
	        {
	        case 0:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	            break;
	        case 1:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	        	break;
	        case 2:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
	            break;
	        case 3:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	            break;
	        case 4:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	            break;
	        case 5:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	            break;
	        case 6:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
	            break;
	        case 7:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
	            break;
	        case 8:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);
	            break;
	        case 9:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 0);
	            break;
	        case 10:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, 0);
	            break;
	        case 11:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
	            break;
	        }
	 }
}
void clearNumberOnClock(int num)
{
if (num >= 0 && num <= 11)
	 {
	switch (num)
	        {
	        case 0:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	            break;
	        case 1:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	        	break;
	        case 2:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
	            break;
	        case 3:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
	            break;
	        case 4:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
	            break;
	        case 5:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
	            break;
	        case 6:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
	            break;
	        case 7:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
	            break;
	        case 8:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
	            break;
	        case 9:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 1);
	            break;
	        case 10:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, 1);
	            break;
	        case 11:
	        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);
	            break;
	        }
	 }
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
