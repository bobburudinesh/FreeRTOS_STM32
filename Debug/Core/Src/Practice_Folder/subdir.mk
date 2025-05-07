################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.c 

OBJS += \
./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.o 

C_DEPS += \
./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Practice_Folder/%.o Core/Src/Practice_Folder/%.su Core/Src/Practice_Folder/%.cyclo: ../Core/Src/Practice_Folder/%.c Core/Src/Practice_Folder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/include" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/FreeRTOS_MAC/portable/GCC/ARM_CM4F" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/Config" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/OS" -I"/Users/dineshbobburu/Documents/Embedded Systems/Projects/STM32/FreeRTOS_STM32/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Practice_Folder

clean-Core-2f-Src-2f-Practice_Folder:
	-$(RM) ./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.cyclo ./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.d ./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.o ./Core/Src/Practice_Folder/E6_Btn_ISR_Task_Notify.su

.PHONY: clean-Core-2f-Src-2f-Practice_Folder

