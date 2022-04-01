################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/BlueNRG-2/hci/bluenrg1_devConfig.c \
../Middlewares/ST/BlueNRG-2/hci/bluenrg1_events.c \
../Middlewares/ST/BlueNRG-2/hci/bluenrg1_events_cb.c \
../Middlewares/ST/BlueNRG-2/hci/bluenrg1_hci_le.c 

OBJS += \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_devConfig.o \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events.o \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events_cb.o \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_hci_le.o 

C_DEPS += \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_devConfig.d \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events.d \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events_cb.d \
./Middlewares/ST/BlueNRG-2/hci/bluenrg1_hci_le.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/BlueNRG-2/hci/%.o: ../Middlewares/ST/BlueNRG-2/hci/%.c Middlewares/ST/BlueNRG-2/hci/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../BlueNRG-2/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../Middlewares/ST/BlueNRG-2/utils -I../Middlewares/ST/BlueNRG-2/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci

clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci:
	-$(RM) ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_devConfig.d ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_devConfig.o ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events.d ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events.o ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events_cb.d ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_events_cb.o ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_hci_le.d ./Middlewares/ST/BlueNRG-2/hci/bluenrg1_hci_le.o

.PHONY: clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci

