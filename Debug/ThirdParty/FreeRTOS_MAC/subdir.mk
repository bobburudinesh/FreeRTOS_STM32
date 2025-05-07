################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS_MAC/croutine.c \
../ThirdParty/FreeRTOS_MAC/event_groups.c \
../ThirdParty/FreeRTOS_MAC/list.c \
../ThirdParty/FreeRTOS_MAC/queue.c \
../ThirdParty/FreeRTOS_MAC/stream_buffer.c \
../ThirdParty/FreeRTOS_MAC/tasks.c \
../ThirdParty/FreeRTOS_MAC/timers.c 

OBJS += \
./ThirdParty/FreeRTOS_MAC/croutine.o \
./ThirdParty/FreeRTOS_MAC/event_groups.o \
./ThirdParty/FreeRTOS_MAC/list.o \
./ThirdParty/FreeRTOS_MAC/queue.o \
./ThirdParty/FreeRTOS_MAC/stream_buffer.o \
./ThirdParty/FreeRTOS_MAC/tasks.o \
./ThirdParty/FreeRTOS_MAC/timers.o 

C_DEPS += \
./ThirdParty/FreeRTOS_MAC/croutine.d \
./ThirdParty/FreeRTOS_MAC/event_groups.d \
./ThirdParty/FreeRTOS_MAC/list.d \
./ThirdParty/FreeRTOS_MAC/queue.d \
./ThirdParty/FreeRTOS_MAC/stream_buffer.d \
./ThirdParty/FreeRTOS_MAC/tasks.d \
./ThirdParty/FreeRTOS_MAC/timers.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS_MAC/%.o ThirdParty/FreeRTOS_MAC/%.su ThirdParty/FreeRTOS_MAC/%.cyclo: ../ThirdParty/FreeRTOS_MAC/%.c ThirdParty/FreeRTOS_MAC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/SEGGER" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/portable/GCC/ARM_CM4F" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS_MAC

clean-ThirdParty-2f-FreeRTOS_MAC:
	-$(RM) ./ThirdParty/FreeRTOS_MAC/croutine.cyclo ./ThirdParty/FreeRTOS_MAC/croutine.d ./ThirdParty/FreeRTOS_MAC/croutine.o ./ThirdParty/FreeRTOS_MAC/croutine.su ./ThirdParty/FreeRTOS_MAC/event_groups.cyclo ./ThirdParty/FreeRTOS_MAC/event_groups.d ./ThirdParty/FreeRTOS_MAC/event_groups.o ./ThirdParty/FreeRTOS_MAC/event_groups.su ./ThirdParty/FreeRTOS_MAC/list.cyclo ./ThirdParty/FreeRTOS_MAC/list.d ./ThirdParty/FreeRTOS_MAC/list.o ./ThirdParty/FreeRTOS_MAC/list.su ./ThirdParty/FreeRTOS_MAC/queue.cyclo ./ThirdParty/FreeRTOS_MAC/queue.d ./ThirdParty/FreeRTOS_MAC/queue.o ./ThirdParty/FreeRTOS_MAC/queue.su ./ThirdParty/FreeRTOS_MAC/stream_buffer.cyclo ./ThirdParty/FreeRTOS_MAC/stream_buffer.d ./ThirdParty/FreeRTOS_MAC/stream_buffer.o ./ThirdParty/FreeRTOS_MAC/stream_buffer.su ./ThirdParty/FreeRTOS_MAC/tasks.cyclo ./ThirdParty/FreeRTOS_MAC/tasks.d ./ThirdParty/FreeRTOS_MAC/tasks.o ./ThirdParty/FreeRTOS_MAC/tasks.su ./ThirdParty/FreeRTOS_MAC/timers.cyclo ./ThirdParty/FreeRTOS_MAC/timers.d ./ThirdParty/FreeRTOS_MAC/timers.o ./ThirdParty/FreeRTOS_MAC/timers.su

.PHONY: clean-ThirdParty-2f-FreeRTOS_MAC

