//    i = 0;
//    j = 0;
//    for(i=0;i<1;i++){
//  	  for(j=0;j<3;j++){
//  		  if(HAL_I2C_IsDeviceReady(&BNO055__I2C,BNO055_I2C_ADDR, 1, 100)==HAL_OK){
//  			  HAL_GPIO_TogglePin(GPIOC, LED_Pin);
//  			  HAL_Delay(500);
//  		  	  }
//  		  else{
//  			  HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
//  			  HAL_Delay(100);
//  		  }
//  	  }
//    }
//    HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
//    HAL_Delay(500);
//    HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, RESET);
//
//      tmp = 0x20;
//      if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,SYS_TRIGGER, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//      }
//      else{
//    	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	  HAL_GPIO_WritePin(GPIOC,BUZZER_Pin, SET);
//      }
//      HAL_Delay(510);
//      member = 0;
//      if(HAL_I2C_Mem_Read(&BNO055__I2C,BNO055_I2C_ADDR,CHIP_ID_PAGE_0, I2C_MEMADD_SIZE_8BIT, &member, 1, I2C_TIMEOUT_MS)==HAL_OK){
//      	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//      	  HAL_Delay(100);
//      }
//      else{
//      	HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, SET);
//      	HAL_Delay(100);
//      	HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, RESET);
//      	HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//      }
//    if(member==BNO055_ID){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	 HAL_GPIO_WritePin(GPIOC, BUZZER_Pin, SET);
//    }
//
//    //set operation_mode BNO055_OPERATION_CONFIG_MODE
//    tmp = BNO055_OPERATION_CONFIG_MODE;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,OPR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//
//    tmp = 0b00;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PWR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//
//    //Move to Page 1//
//    tmp = 0x01;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PAGE_ID, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//    /* Configurations Accelerometer */
//    tmp = ( 0b000<<5 | 0b011<<2 ) | 0b01;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,ACC_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//
//    /* Configurations Gyroscope */
//    tmp = 0b111<<3 | 0b000;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,GYR_CONFIG_0, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//    tmp = 0b000;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,GYR_CONFIG_1, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//
//    /* Configurations Magnetometer */
//    tmp = (0b11<<5 | 0b11<<3)| 0b011;
//    if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,MAG_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    }
//    else{
//  	  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    }
//
//  	/*Configuration Sensor Unit*/
//  	//Move to Page 0//
//    	tmp = 0x00;
//    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,PAGE_ID, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    	}
//    	else{
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	}
//
//    	//tmp = (((0b00<<4 | 0b00<<2)| 0b00<<1)| 0b00);
//    	tmp = 0b0000000;
//    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,UNIT_SEL, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    	}
//    	else{
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	}
//    	/* Configure axis mapping*/
//    	tmp = REMAP_CONFIG_P1_2_4_7;
//    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,AXIS_MAP_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    	}
//    	else{
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	}
//
//    	tmp = REMAP_SIGN_P1;
//    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,AXIS_MAP_CONFIG, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    	}
//    	else{
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	}
//    //set BNO055_OPERATION_MODE_NDOF
//    	tmp = BNO055_OPERATION_MODE_NDOF;
//    	if(HAL_I2C_Mem_Write(&BNO055__I2C, BNO055_I2C_ADDR,OPR_MODE, I2C_MEMADD_SIZE_8BIT, &tmp, 1, I2C_TIMEOUT_MS)==HAL_OK){
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, SET);
//    	}
//    	else{
//    		  HAL_GPIO_WritePin(GPIOC, LED_Pin, RESET);
//    	}