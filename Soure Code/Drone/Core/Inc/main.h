/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUZZER_Pin GPIO_PIN_13
#define BUZZER_GPIO_Port GPIOC
#define LED_Pin GPIO_PIN_14
#define LED_GPIO_Port GPIOC
#define BTN_Pin GPIO_PIN_15
#define BTN_GPIO_Port GPIOC
#define MCU_RF_LORA_PWR_Pin GPIO_PIN_0
#define MCU_RF_LORA_PWR_GPIO_Port GPIOC
#define MCU_ADC_1_Pin GPIO_PIN_1
#define MCU_ADC_1_GPIO_Port GPIOC
#define MCU_ADC_2_Pin GPIO_PIN_2
#define MCU_ADC_2_GPIO_Port GPIOC
#define MCU_ADC_3_Pin GPIO_PIN_3
#define MCU_ADC_3_GPIO_Port GPIOC
#define MCU_ESP32_TX_Pin GPIO_PIN_0
#define MCU_ESP32_TX_GPIO_Port GPIOA
#define MCU_ESP32_RX_Pin GPIO_PIN_1
#define MCU_ESP32_RX_GPIO_Port GPIOA
#define MCU_USART2_TX_Pin GPIO_PIN_2
#define MCU_USART2_TX_GPIO_Port GPIOA
#define MCU_USART2_RX_Pin GPIO_PIN_3
#define MCU_USART2_RX_GPIO_Port GPIOA
#define ADNS_SPI_CSn_Pin GPIO_PIN_4
#define ADNS_SPI_CSn_GPIO_Port GPIOA
#define MCU_SPI_SCK_Pin GPIO_PIN_5
#define MCU_SPI_SCK_GPIO_Port GPIOA
#define MCU_SPI_MISO_Pin GPIO_PIN_6
#define MCU_SPI_MISO_GPIO_Port GPIOA
#define MCU_SPI_MOSI_Pin GPIO_PIN_7
#define MCU_SPI_MOSI_GPIO_Port GPIOA
#define LORA_SPI_CSn_2_Pin GPIO_PIN_4
#define LORA_SPI_CSn_2_GPIO_Port GPIOC
#define ADD_SPI_CSn_3_Pin GPIO_PIN_5
#define ADD_SPI_CSn_3_GPIO_Port GPIOC
#define MCU_CAN_RX_Pin GPIO_PIN_12
#define MCU_CAN_RX_GPIO_Port GPIOB
#define MCU_CAN_TX_Pin GPIO_PIN_13
#define MCU_CAN_TX_GPIO_Port GPIOB
#define MCU_GPIO_OUT1_Pin GPIO_PIN_14
#define MCU_GPIO_OUT1_GPIO_Port GPIOB
#define MCU_GPIO_OUT2_Pin GPIO_PIN_15
#define MCU_GPIO_OUT2_GPIO_Port GPIOB
#define MCU_USART6_TX_Pin GPIO_PIN_6
#define MCU_USART6_TX_GPIO_Port GPIOC
#define MCU_USART6_RX_Pin GPIO_PIN_7
#define MCU_USART6_RX_GPIO_Port GPIOC
#define MCU_PWM_TIM8_CH3_Pin GPIO_PIN_8
#define MCU_PWM_TIM8_CH3_GPIO_Port GPIOC
#define LED_5050_PWM_IN_Pin GPIO_PIN_9
#define LED_5050_PWM_IN_GPIO_Port GPIOC
#define MTR1_PWM_MCU_Pin GPIO_PIN_8
#define MTR1_PWM_MCU_GPIO_Port GPIOA
#define MTR2_PWM_MCU_Pin GPIO_PIN_9
#define MTR2_PWM_MCU_GPIO_Port GPIOA
#define MTR3_PWM_MCU_Pin GPIO_PIN_10
#define MTR3_PWM_MCU_GPIO_Port GPIOA
#define MTR4_PWM_MCU_Pin GPIO_PIN_11
#define MTR4_PWM_MCU_GPIO_Port GPIOA
#define MCU_LORA_RST_Pin GPIO_PIN_12
#define MCU_LORA_RST_GPIO_Port GPIOA
#define MCU_CIA_MTR1_Pin GPIO_PIN_15
#define MCU_CIA_MTR1_GPIO_Port GPIOA
#define MCU_HLBr_TX_Pin GPIO_PIN_10
#define MCU_HLBr_TX_GPIO_Port GPIOC
#define MCU_HLBr_RX_Pin GPIO_PIN_11
#define MCU_HLBr_RX_GPIO_Port GPIOC
#define MCU_UART5_TX_Pin GPIO_PIN_12
#define MCU_UART5_TX_GPIO_Port GPIOC
#define MCU_UART5_RX_Pin GPIO_PIN_2
#define MCU_UART5_RX_GPIO_Port GPIOD
#define MCU_CIA_MTR2_Pin GPIO_PIN_3
#define MCU_CIA_MTR2_GPIO_Port GPIOB
#define MCU_USART1_TX_Pin GPIO_PIN_6
#define MCU_USART1_TX_GPIO_Port GPIOB
#define MCU_USART1_RX_Pin GPIO_PIN_7
#define MCU_USART1_RX_GPIO_Port GPIOB
#define MCU_I2C_SCL_Pin GPIO_PIN_8
#define MCU_I2C_SCL_GPIO_Port GPIOB
#define MCU_I2C_SDA_Pin GPIO_PIN_9
#define MCU_I2C_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
