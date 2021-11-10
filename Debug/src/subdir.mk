################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ebentoak.c \
../src/graphics.c \
../src/imagen.c \
../src/ourWiringPi.c \
../src/sinfo.c \
../src/soinua.c 

OBJS += \
./src/ebentoak.o \
./src/graphics.o \
./src/imagen.o \
./src/ourWiringPi.o \
./src/sinfo.o \
./src/soinua.o 

C_DEPS += \
./src/ebentoak.d \
./src/graphics.d \
./src/imagen.d \
./src/ourWiringPi.d \
./src/sinfo.d \
./src/soinua.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"/home/unai/eclipse-workspace/sinfo2/headers" -I/home/unai/Escritorio/wiringPi/wiringPi -I/home/unai/Escritorio/SDL2_PI/SDL_PI/include/SDL2 -I/home/unai/Escritorio/SDL2_PI/SDL_PI/include -I/home/unai/Escritorio/SDL2_mixer-2.0.1 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


