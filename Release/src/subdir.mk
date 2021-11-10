################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ebentoak.c \
../src/graphics.c \
../src/imagen.c \
../src/sinfo.c \
../src/soinua.c 

OBJS += \
./src/ebentoak.o \
./src/graphics.o \
./src/imagen.o \
./src/sinfo.o \
./src/soinua.o 

C_DEPS += \
./src/ebentoak.d \
./src/graphics.d \
./src/imagen.d \
./src/sinfo.d \
./src/soinua.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


