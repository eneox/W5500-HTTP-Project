################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ioLibrary_Driver/Internet/FTPClient/ftpc.c 

OBJS += \
./ioLibrary_Driver/Internet/FTPClient/ftpc.o 

C_DEPS += \
./ioLibrary_Driver/Internet/FTPClient/ftpc.d 


# Each subdirectory must supply rules for building sources it contributes
ioLibrary_Driver/Internet/FTPClient/ftpc.o: ../ioLibrary_Driver/Internet/FTPClient/ftpc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../ioLibrary_Driver -I../ioLibrary_Driver/Application/loopback -I../ioLibrary_Driver/Application/multicast -I../ioLibrary_Driver/Ethernet -I../ioLibrary_Driver/Internet -I../ioLibrary_Driver/Internet/httpServer -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ioLibrary_Driver/Internet/FTPClient/ftpc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

