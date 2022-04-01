################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.c \
../Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.c \
../Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.c \
../Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.c 

OBJS += \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.o \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.o \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.o \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.o 

C_DEPS += \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.d \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.d \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.d \
./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/BlueNRG-2/hci/controller/%.o: ../Middlewares/ST/BlueNRG-2/hci/controller/%.c Middlewares/ST/BlueNRG-2/hci/controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../BlueNRG-2/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../Middlewares/ST/BlueNRG-2/utils -I../Middlewares/ST/BlueNRG-2/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci-2f-controller

clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci-2f-controller:
	-$(RM) ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.d ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.o ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.d ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.o ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.d ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.o ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.d ./Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.o

.PHONY: clean-Middlewares-2f-ST-2f-BlueNRG-2d-2-2f-hci-2f-controller

