################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/Source/TransformFunctions/arm_bitreversal.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_init_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_dct4_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_init_f32.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q31.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_q15.c \
../Drivers/DSP/Source/TransformFunctions/arm_rfft_q31.c 

S_UPPER_SRCS += \
../Drivers/DSP/Source/TransformFunctions/arm_bitreversal2.S 

OBJS += \
./Drivers/DSP/Source/TransformFunctions/arm_bitreversal.o \
./Drivers/DSP/Source/TransformFunctions/arm_bitreversal2.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_f32.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q31.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_q15.o \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_q31.o 

S_UPPER_DEPS += \
./Drivers/DSP/Source/TransformFunctions/arm_bitreversal2.d 

C_DEPS += \
./Drivers/DSP/Source/TransformFunctions/arm_bitreversal.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_init_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_dct4_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_f32.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_init_q31.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_q15.d \
./Drivers/DSP/Source/TransformFunctions/arm_rfft_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/Source/TransformFunctions/%.o: ../Drivers/DSP/Source/TransformFunctions/%.c Drivers/DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -D__TARGET_FPU_VFP -DARM_MATH_CM4 -D__FPU_USED=1 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/ST/workspace/dsp_demo/Drivers/DSP/include" -I"D:/ST/workspace/dsp_demo/Drivers/base" -I"D:/ST/workspace/dsp_demo/Drivers/ADS8688" -I"D:/ST/workspace/dsp_demo/Drivers/STM32F4xx_VisualTFT" -I"D:/ST/workspace/dsp_demo/Drivers/outputdata" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/DSP/Source/TransformFunctions/%.o: ../Drivers/DSP/Source/TransformFunctions/%.S Drivers/DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -D__TARGET_FPU_VFP -DARM_MATH_CM4 -D__FPU_USED=1 -D__FPU_PRESENT=1 -c -I"D:/ST/workspace/dsp_demo/Drivers/DSP/include" -I"D:/ST/workspace/dsp_demo/Drivers/base" -I"D:/ST/workspace/dsp_demo/Drivers/ADS8688" -I"D:/ST/workspace/dsp_demo/Drivers/STM32F4xx_VisualTFT" -I"D:/ST/workspace/dsp_demo/Drivers/outputdata" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

