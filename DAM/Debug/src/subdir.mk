################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DAM.c \
../src/connection.c \
../src/error.c \
../src/file_conf.c \
../src/proceso.c 

OBJS += \
./src/DAM.o \
./src/connection.o \
./src/error.o \
./src/file_conf.o \
./src/proceso.o 

C_DEPS += \
./src/DAM.d \
./src/connection.d \
./src/error.d \
./src/file_conf.d \
./src/proceso.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/git/tp-2018-2c-Hackers-Reloaded/Shared_Library" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


