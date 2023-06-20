################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g070kbtx.s 

S_DEPS += \
./Core/Startup/startup_stm32g070kbtx.d 

OBJS += \
./Core/Startup/startup_stm32g070kbtx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32g070kbtx.o: ../Core/Startup/startup_stm32g070kbtx.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -c -I"C:/Data/Documents/STM32CubeIDE/YouTube/GyrocamDemoRecap/cpp/inc" -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32g070kbtx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

