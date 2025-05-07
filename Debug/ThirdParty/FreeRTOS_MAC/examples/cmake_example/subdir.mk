################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.c 

OBJS += \
./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.o 

C_DEPS += \
./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS_MAC/examples/cmake_example/%.o ThirdParty/FreeRTOS_MAC/examples/cmake_example/%.su ThirdParty/FreeRTOS_MAC/examples/cmake_example/%.cyclo: ../ThirdParty/FreeRTOS_MAC/examples/cmake_example/%.c ThirdParty/FreeRTOS_MAC/examples/cmake_example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/portable/GCC/ARM_CM4F" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS_MAC-2f-examples-2f-cmake_example

clean-ThirdParty-2f-FreeRTOS_MAC-2f-examples-2f-cmake_example:
	-$(RM) ./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.cyclo ./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.d ./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.o ./ThirdParty/FreeRTOS_MAC/examples/cmake_example/main.su

.PHONY: clean-ThirdParty-2f-FreeRTOS_MAC-2f-examples-2f-cmake_example

