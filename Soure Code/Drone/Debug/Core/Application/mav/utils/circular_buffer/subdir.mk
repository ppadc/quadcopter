################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/mav/utils/circular_buffer/circular_buffer.c 

OBJS += \
./Core/Application/mav/utils/circular_buffer/circular_buffer.o 

C_DEPS += \
./Core/Application/mav/utils/circular_buffer/circular_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Application/mav/utils/circular_buffer/%.o Core/Application/mav/utils/circular_buffer/%.su: ../Core/Application/mav/utils/circular_buffer/%.c Core/Application/mav/utils/circular_buffer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/Application/Buzzer -I../Core/Application/mav -I../Core/Application/mode -I../Core/Application/params -I../Core/Application/pid -I../Core/Application/sensor -I../Core/Application/timer -I../Core/Application/mav/mavlink -I../Core/Application/mav/mavlink/quadcopter_protocol -I../Core/Application/mav/uart -I../Core/Application/mav/utils/circular_buffer -I../Core/Application/sensor/bno055 -I../Core/Application/sensor/mpu9250 -I../Core/Application/sensor/bme680 -I../Core/Application/imu -I../Core/Application/motor -I../Core/Application/eeprom -I../Core/Application/lcd -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Application-2f-mav-2f-utils-2f-circular_buffer

clean-Core-2f-Application-2f-mav-2f-utils-2f-circular_buffer:
	-$(RM) ./Core/Application/mav/utils/circular_buffer/circular_buffer.d ./Core/Application/mav/utils/circular_buffer/circular_buffer.o ./Core/Application/mav/utils/circular_buffer/circular_buffer.su

.PHONY: clean-Core-2f-Application-2f-mav-2f-utils-2f-circular_buffer

