################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./Drivers/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/Source/ComplexMathFunctions/%.o: ../Drivers/DSP/Source/ComplexMathFunctions/%.c Drivers/DSP/Source/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -D__TARGET_FPU_VFP -DARM_MATH_CM4 -D__FPU_USED=1 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/ST/workspace/dsp_demo/Drivers/DSP/include" -I"D:/ST/workspace/dsp_demo/Drivers/base" -I"D:/ST/workspace/dsp_demo/Drivers/ADS8688" -I"D:/ST/workspace/dsp_demo/Drivers/STM32F4xx_VisualTFT" -I"D:/ST/workspace/dsp_demo/Drivers/outputdata" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

