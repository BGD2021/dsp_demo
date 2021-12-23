################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_VisualTFT/cmd_process.c \
../Drivers/STM32F4xx_VisualTFT/cmd_queue.c \
../Drivers/STM32F4xx_VisualTFT/hmi_driver.c \
../Drivers/STM32F4xx_VisualTFT/hmi_user_uart.c 

OBJS += \
./Drivers/STM32F4xx_VisualTFT/cmd_process.o \
./Drivers/STM32F4xx_VisualTFT/cmd_queue.o \
./Drivers/STM32F4xx_VisualTFT/hmi_driver.o \
./Drivers/STM32F4xx_VisualTFT/hmi_user_uart.o 

C_DEPS += \
./Drivers/STM32F4xx_VisualTFT/cmd_process.d \
./Drivers/STM32F4xx_VisualTFT/cmd_queue.d \
./Drivers/STM32F4xx_VisualTFT/hmi_driver.d \
./Drivers/STM32F4xx_VisualTFT/hmi_user_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_VisualTFT/%.o: ../Drivers/STM32F4xx_VisualTFT/%.c Drivers/STM32F4xx_VisualTFT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -D__TARGET_FPU_VFP -DARM_MATH_CM4 -D__FPU_USED=1 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/ST/workspace/dsp_demo/Drivers/DSP/include" -I"D:/ST/workspace/dsp_demo/Drivers/base" -I"D:/ST/workspace/dsp_demo/Drivers/ADS8688" -I"D:/ST/workspace/dsp_demo/Drivers/STM32F4xx_VisualTFT" -I"D:/ST/workspace/dsp_demo/Drivers/outputdata" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

