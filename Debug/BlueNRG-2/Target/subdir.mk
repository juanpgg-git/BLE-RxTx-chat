################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BlueNRG-2/Target/hci_tl_interface.c 

OBJS += \
./BlueNRG-2/Target/hci_tl_interface.o 

C_DEPS += \
./BlueNRG-2/Target/hci_tl_interface.d 


# Each subdirectory must supply rules for building sources it contributes
BlueNRG-2/Target/%.o: ../BlueNRG-2/Target/%.c BlueNRG-2/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../BlueNRG-2/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../Middlewares/ST/BlueNRG-2/utils -I../Middlewares/ST/BlueNRG-2/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BlueNRG-2d-2-2f-Target

clean-BlueNRG-2d-2-2f-Target:
	-$(RM) ./BlueNRG-2/Target/hci_tl_interface.d ./BlueNRG-2/Target/hci_tl_interface.o

.PHONY: clean-BlueNRG-2d-2-2f-Target

