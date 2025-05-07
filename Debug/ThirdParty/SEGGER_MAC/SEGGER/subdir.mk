################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.c \
../ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.c \
../ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.o \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.o \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.d \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.d \
./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/SEGGER_MAC/SEGGER/%.o ThirdParty/SEGGER_MAC/SEGGER/%.su ThirdParty/SEGGER_MAC/SEGGER/%.cyclo: ../ThirdParty/SEGGER_MAC/SEGGER/%.c ThirdParty/SEGGER_MAC/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/SEGGER" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/portable/GCC/ARM_CM4F" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ThirdParty/SEGGER_MAC/SEGGER/%.o: ../ThirdParty/SEGGER_MAC/SEGGER/%.S ThirdParty/SEGGER_MAC/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER_MAC/Config" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-ThirdParty-2f-SEGGER_MAC-2f-SEGGER

clean-ThirdParty-2f-SEGGER_MAC-2f-SEGGER:
	-$(RM) ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.cyclo ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.d ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.o ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT.su ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.cyclo ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.d ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.o ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_RTT_printf.su ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.cyclo ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.d ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.o ./ThirdParty/SEGGER_MAC/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-ThirdParty-2f-SEGGER_MAC-2f-SEGGER

