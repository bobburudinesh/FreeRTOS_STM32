################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.c 

OBJS += \
./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.o 

C_DEPS += \
./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Semaphores/%.o Core/Src/Semaphores/%.su Core/Src/Semaphores/%.cyclo: ../Core/Src/Semaphores/%.c Core/Src/Semaphores/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS/include" -I"D:/Embedded_Systems/Projects/STM32_Projects/FreeRTOS_STM32/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Semaphores

clean-Core-2f-Src-2f-Semaphores:
	-$(RM) ./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.cyclo ./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.d ./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.o ./Core/Src/Semaphores/Semaphores_Counting_Interrupt_And_Task_Sync.su

.PHONY: clean-Core-2f-Src-2f-Semaphores

