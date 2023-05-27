################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/Buzzer/buzzer.c 

OBJS += \
./Core/Application/Buzzer/buzzer.o 

C_DEPS += \
./Core/Application/Buzzer/buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Application/Buzzer/buzzer.o: ../Core/Application/Buzzer/buzzer.c Core/Application/Buzzer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Application/timer -I../Core/Application/Buzzer -I../Core/Application/params -I../Core/Application/pid -I../Core/Application/sensor/bno055 -I../Core/Application/sensor/mpu9250 -I../Core/Application/mav -I../Core/Application/mav/mavlink -I../Core/Application/mav/uart -I../Core/Application/mav/utils -I../Core/Application/mav/mavlink/quadcopter_protocol -I../Core/Application/mav/utils/circular_buffer -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Application-2f-Buzzer

clean-Core-2f-Application-2f-Buzzer:
	-$(RM) ./Core/Application/Buzzer/buzzer.d ./Core/Application/Buzzer/buzzer.o ./Core/Application/Buzzer/buzzer.su

.PHONY: clean-Core-2f-Application-2f-Buzzer

