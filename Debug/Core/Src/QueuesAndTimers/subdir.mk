################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/QueuesAndTimers/led_effect.c \
../Core/Src/QueuesAndTimers/rtc.c \
../Core/Src/QueuesAndTimers/task_handler.c 

OBJS += \
./Core/Src/QueuesAndTimers/led_effect.o \
./Core/Src/QueuesAndTimers/rtc.o \
./Core/Src/QueuesAndTimers/task_handler.o 

C_DEPS += \
./Core/Src/QueuesAndTimers/led_effect.d \
./Core/Src/QueuesAndTimers/rtc.d \
./Core/Src/QueuesAndTimers/task_handler.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/QueuesAndTimers/%.o Core/Src/QueuesAndTimers/%.su Core/Src/QueuesAndTimers/%.cyclo: ../Core/Src/QueuesAndTimers/%.c Core/Src/QueuesAndTimers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-QueuesAndTimers

clean-Core-2f-Src-2f-QueuesAndTimers:
	-$(RM) ./Core/Src/QueuesAndTimers/led_effect.cyclo ./Core/Src/QueuesAndTimers/led_effect.d ./Core/Src/QueuesAndTimers/led_effect.o ./Core/Src/QueuesAndTimers/led_effect.su ./Core/Src/QueuesAndTimers/rtc.cyclo ./Core/Src/QueuesAndTimers/rtc.d ./Core/Src/QueuesAndTimers/rtc.o ./Core/Src/QueuesAndTimers/rtc.su ./Core/Src/QueuesAndTimers/task_handler.cyclo ./Core/Src/QueuesAndTimers/task_handler.d ./Core/Src/QueuesAndTimers/task_handler.o ./Core/Src/QueuesAndTimers/task_handler.su

.PHONY: clean-Core-2f-Src-2f-QueuesAndTimers

