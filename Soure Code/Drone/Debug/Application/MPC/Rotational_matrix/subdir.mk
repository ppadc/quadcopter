################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/MPC/Rotational_matrix/rotational_matrix.c 

OBJS += \
./Application/MPC/Rotational_matrix/rotational_matrix.o 

C_DEPS += \
./Application/MPC/Rotational_matrix/rotational_matrix.d 


# Each subdirectory must supply rules for building sources it contributes
Application/MPC/Rotational_matrix/rotational_matrix.o: E:/Drone/Soure\ Code/Drone/Core/Application/MPC/Rotational_matrix/rotational_matrix.c Application/MPC/Rotational_matrix/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Drone/Soure Code/Drone/Core/Application/MPC/Rotational_matrix" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-MPC-2f-Rotational_matrix

clean-Application-2f-MPC-2f-Rotational_matrix:
	-$(RM) ./Application/MPC/Rotational_matrix/rotational_matrix.d ./Application/MPC/Rotational_matrix/rotational_matrix.o ./Application/MPC/Rotational_matrix/rotational_matrix.su

.PHONY: clean-Application-2f-MPC-2f-Rotational_matrix

