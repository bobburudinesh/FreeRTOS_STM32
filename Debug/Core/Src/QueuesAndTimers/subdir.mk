################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/QueuesAndTimers/Queues_And_Timers.c \
../Core/Src/QueuesAndTimers/led_effect.c \
../Core/Src/QueuesAndTimers/rtc.c \
../Core/Src/QueuesAndTimers/task_handler.c 

OBJS += \
./Core/Src/QueuesAndTimers/Queues_And_Timers.o \
./Core/Src/QueuesAndTimers/led_effect.o \
./Core/Src/QueuesAndTimers/rtc.o \
./Core/Src/QueuesAndTimers/task_handler.o 

C_DEPS += \
./Core/Src/QueuesAndTimers/Queues_And_Timers.d \
./Core/Src/QueuesAndTimers/led_effect.d \
./Core/Src/QueuesAndTimers/rtc.d \
./Core/Src/QueuesAndTimers/task_handler.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/QueuesAndTimers/%.o Core/Src/QueuesAndTimers/%.su Core/Src/QueuesAndTimers/%.cyclo: ../Core/Src/QueuesAndTimers/%.c Core/Src/QueuesAndTimers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS/include" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-QueuesAndTimers

clean-Core-2f-Src-2f-QueuesAndTimers:
	-$(RM) ./Core/Src/QueuesAndTimers/Queues_And_Timers.cyclo ./Core/Src/QueuesAndTimers/Queues_And_Timers.d ./Core/Src/QueuesAndTimers/Queues_And_Timers.o ./Core/Src/QueuesAndTimers/Queues_And_Timers.su ./Core/Src/QueuesAndTimers/led_effect.cyclo ./Core/Src/QueuesAndTimers/led_effect.d ./Core/Src/QueuesAndTimers/led_effect.o ./Core/Src/QueuesAndTimers/led_effect.su ./Core/Src/QueuesAndTimers/rtc.cyclo ./Core/Src/QueuesAndTimers/rtc.d ./Core/Src/QueuesAndTimers/rtc.o ./Core/Src/QueuesAndTimers/rtc.su ./Core/Src/QueuesAndTimers/task_handler.cyclo ./Core/Src/QueuesAndTimers/task_handler.d ./Core/Src/QueuesAndTimers/task_handler.o ./Core/Src/QueuesAndTimers/task_handler.su

.PHONY: clean-Core-2f-Src-2f-QueuesAndTimers

