################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/SEGGER_MAC/OS/%.o ThirdParty/SEGGER_MAC/OS/%.su ThirdParty/SEGGER_MAC/OS/%.cyclo: ../ThirdParty/SEGGER_MAC/OS/%.c ThirdParty/SEGGER_MAC/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/SEGGER" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/portable/GCC/ARM_CM4F" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-SEGGER_MAC-2f-OS

clean-ThirdParty-2f-SEGGER_MAC-2f-OS:
	-$(RM) ./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.d ./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.o ./ThirdParty/SEGGER_MAC/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-ThirdParty-2f-SEGGER_MAC-2f-OS

