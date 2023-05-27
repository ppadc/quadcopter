################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/sensor/mpu9250/mpu9250.c 

OBJS += \
./Core/Application/sensor/mpu9250/mpu9250.o 

C_DEPS += \
./Core/Application/sensor/mpu9250/mpu9250.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Application/sensor/mpu9250/%.o Core/Application/sensor/mpu9250/%.su: ../Core/Application/sensor/mpu9250/%.c Core/Application/sensor/mpu9250/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/Application/Buzzer -I../Core/Application/mav -I../Core/Application/mode -I../Core/Application/params -I../Core/Application/pid -I../Core/Application/sensor -I../Core/Application/timer -I../Core/Application/mav/mavlink -I../Core/Application/mav/mavlink/quadcopter_protocol -I../Core/Application/mav/uart -I../Core/Application/mav/utils/circular_buffer -I../Core/Application/sensor/bno055 -I../Core/Application/sensor/mpu9250 -I../Core/Application/sensor/bme680 -I../Core/Application/imu -I../Core/Application/motor -I../Core/Application/eeprom -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Application-2f-sensor-2f-mpu9250

clean-Core-2f-Application-2f-sensor-2f-mpu9250:
	-$(RM) ./Core/Application/sensor/mpu9250/mpu9250.d ./Core/Application/sensor/mpu9250/mpu9250.o ./Core/Application/sensor/mpu9250/mpu9250.su

.PHONY: clean-Core-2f-Application-2f-sensor-2f-mpu9250

