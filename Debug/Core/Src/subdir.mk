################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/RTOS_Task_1.c \
../Core/Src/gpio.c \
../Core/Src/it.c \
../Core/Src/msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/RTOS_Task_1.o \
./Core/Src/gpio.o \
./Core/Src/it.o \
./Core/Src/msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/RTOS_Task_1.d \
./Core/Src/gpio.d \
./Core/Src/it.d \
./Core/Src/msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/RTOS_Task_1.cyclo ./Core/Src/RTOS_Task_1.d ./Core/Src/RTOS_Task_1.o ./Core/Src/RTOS_Task_1.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/it.cyclo ./Core/Src/it.d ./Core/Src/it.o ./Core/Src/it.su ./Core/Src/msp.cyclo ./Core/Src/msp.d ./Core/Src/msp.o ./Core/Src/msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.cyclo ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

