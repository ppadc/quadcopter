/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "ssd1306.h"
#include "fonts.h"
#include "imu.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
uint8_t tmp, i,j,member;
float temp,roll,pitch,yaw;
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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_CAN2_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM8_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
  //HAL_TIM_Base_Start(&htim5);
  /* USER CODE END 2 */

  SSD1306_Init (); // initialize the display
  SSD1306_GotoXY (10,10); // goto 10, 10
  SSD1306_Puts ("HELLO", &Font_16x26, 1); // print Hello
//  SSD1306_GotoXY (10, 38);
//  SSD1306_Puts ("WORLD!!", &Font_7x10, 1);
  SSD1306_UpdateScreen(); // update screen
  /* Infinite loop */
  //bno055_initization();
    i = 0;
    j = 0;
    for(i=0;i<1;i++){
  	  for(j=0;j<3;j++){
  		  if(HAL_I2C_IsDeviceReady(&BNO055__I2C,BNO055_I2C_ADDR, 1, 100)==HAL_OK){
  			  HAL_GPIO_TogglePin(GPIOC, LED_Pin);
  			  HAL_Delay(500);
  		  	  }
  		  else{
  			  HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
  			  HAL_Delay(100);
  		  }
  	  }
    }
    HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, RESET);

      tmp = 0x20;
      if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,SYS_TRIGGER, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
      }
      else{
    	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	  HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
      }
      HAL_Delay(510);
      member = 0;
      if(HAL_I2C_Mem_Read(&BNO055__I2C,BNO055_I2C_ADDR,CHIP_ID_PAGE_0, I2C_MEMADD_SIZE_8BIT, &member, 1, I2C_TIMEOUT_MS)==HAL_OK){
      	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
      	  HAL_Delay(100);
      }
      else{
      	HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, SET);
      	HAL_Delay(100);
      	HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, RESET);
      	HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
      }
    if(member==BNO055_ID){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	 HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, SET);
    }

    //set operation_mode BNO055_OPERATION_CONFIG_MODE
    tmp = BNO055_OPERATION_CONFIG_MODE;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,OPR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }

    tmp = 0b00;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PWR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }

    //Move to Page 1//
    tmp = 0x01;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PAGE_ID, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }
    /* Configurations Accelerometer */
    tmp = ( 0b000<<5 | 0b011<<2 ) | 0b01;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,ACC_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }

    /* Configurations Gyroscope */
    tmp = 0b111<<3 | 0b000;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,GYR_CONFIG_0, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }
    tmp = 0b000;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,GYR_CONFIG_1, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }

    /* Configurations Magnetometer */
    tmp = (0b11<<5 | 0b11<<3)| 0b011;
    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,MAG_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    }
    else{
  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    }

  	/*Configuration Sensor Unit*/
  	//Move to Page 0//
    	tmp = 0x00;
    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PAGE_ID, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    	}
    	else{
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	}

    	//tmp = (((0b00<<4 | 0b00<<2)| 0b00<<1)| 0b00);
    	tmp = 0b0000000;
    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,UNIT_SEL, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    	}
    	else{
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	}
    	/* Configure axis mapping*/
    	tmp = REMAP_CONFIG_P1_2_4_7;
    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,AXIS_MAP_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    	}
    	else{
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	}

    	tmp = REMAP_SIGN_P1;
    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,AXIS_MAP_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    	}
    	else{
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	}
    //set BNO055_OPERATION_MODE_NDOF
    	tmp = BNO055_OPERATION_MODE_NDOF;
    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,OPR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
    	}
    	else{
    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
    	}
    	HAL_Delay(1000);
    	SSD1306_Clear();
    	char snum_roll[10];
    	char snum_pitch[10];
    	char snum_yaw[10];
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  bno055_get_temp(&temp);
	  	  temp = temp*1;
	  	  if(temp>20 && temp < 40){
	  		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
	  	  }
	  	  else
	  		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);

	  	  	bno055_get_elu_data(&roll, &pitch, &yaw);
	  	  	//sprintf(snum,"%f",roll);
	  	  	SSD1306_GotoXY (0, 0);
	  	  	SSD1306_Puts ("ROLL: ", &Font_11x18, 1);
	  	  	SSD1306_GotoXY (0, 20);
	  	  	SSD1306_Puts ("PITCH: ", &Font_11x18, 1);
	  	  	SSD1306_GotoXY (0, 40);
	  	  	SSD1306_Puts ("YAW: ", &Font_11x18, 1);
			itoa(roll, snum_roll, 10);
			itoa(pitch, snum_pitch, 10);
			itoa(yaw, snum_yaw, 10);
//			SSD1306_GotoXY (0, 0);
//			SSD1306_Puts ("             ", &Font_11x18, 1);
			SSD1306_UpdateScreen();
			if(roll < 10) {
				SSD1306_GotoXY (69, 0);  // 1 DIGIT
			}
			else if (roll < 100 ) {
				SSD1306_GotoXY (61, 0);  // 2 DIGITS
			}
			else if (roll < 1000 ) {
				SSD1306_GotoXY (53, 0);  // 3 DIGITS
			}
			else {
				SSD1306_GotoXY (45, 0);  // 4 DIGIS
			}

			SSD1306_Puts (snum_roll, &Font_11x18, 1);
			SSD1306_UpdateScreen();

			if(pitch < 10) {
				SSD1306_GotoXY (69, 20);  // 1 DIGIT
			}
			else if (pitch < 100 ) {
				SSD1306_GotoXY (61, 20);  // 2 DIGITS
			}
			else if (pitch < 1000 ) {
				SSD1306_GotoXY (53, 20);  // 3 DIGITS
			}
			else {
				SSD1306_GotoXY (45, 20);  // 4 DIGIS
			}

			SSD1306_Puts (snum_pitch, &Font_11x18, 1);
			SSD1306_UpdateScreen();

			if(yaw < 10) {
				SSD1306_GotoXY (69, 40);  // 1 DIGIT
			}
			else if (yaw < 100 ) {
				SSD1306_GotoXY (61, 40);  // 2 DIGITS
			}
			else if (yaw < 1000 ) {
				SSD1306_GotoXY (53, 40);  // 3 DIGITS
			}
			else {
				SSD1306_GotoXY (45, 40);  // 4 DIGIS
			}

			SSD1306_Puts (snum_yaw, &Font_11x18, 1);
			SSD1306_UpdateScreen();

			//SSD1306_Clear();
			HAL_Delay (100);
    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
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

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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