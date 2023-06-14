################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/bno055/bno055.c 

OBJS += \
./Core/bno055/bno055.o 

C_DEPS += \
./Core/bno055/bno055.d 


# Each subdirectory must supply rules for building sources it contributes
Core/bno055/%.o Core/bno055/%.su: ../Core/bno055/%.c Core/bno055/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/bno055 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-bno055

clean-Core-2f-bno055:
	-$(RM) ./Core/bno055/bno055.d ./Core/bno055/bno055.o ./Core/bno055/bno055.su

.PHONY: clean-Core-2f-bno055

