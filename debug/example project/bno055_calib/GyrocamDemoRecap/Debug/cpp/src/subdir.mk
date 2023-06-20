################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/src/BNO055.cpp \
../cpp/src/HM11.cpp \
../cpp/src/NRF24L01.cpp \
../cpp/src/main.cpp 

OBJS += \
./cpp/src/BNO055.o \
./cpp/src/HM11.o \
./cpp/src/NRF24L01.o \
./cpp/src/main.o 

CPP_DEPS += \
./cpp/src/BNO055.d \
./cpp/src/HM11.d \
./cpp/src/NRF24L01.d \
./cpp/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/src/BNO055.o: ../cpp/src/BNO055.cpp cpp/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32G070xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Data/Documents/STM32CubeIDE/YouTube/GyrocamDemoRecap/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/BNO055.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/HM11.o: ../cpp/src/HM11.cpp cpp/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32G070xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Data/Documents/STM32CubeIDE/YouTube/GyrocamDemoRecap/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/HM11.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/NRF24L01.o: ../cpp/src/NRF24L01.cpp cpp/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32G070xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Data/Documents/STM32CubeIDE/YouTube/GyrocamDemoRecap/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/NRF24L01.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/main.o: ../cpp/src/main.cpp cpp/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32G070xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Data/Documents/STM32CubeIDE/YouTube/GyrocamDemoRecap/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

