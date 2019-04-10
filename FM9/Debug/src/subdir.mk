################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FM9.c \
../src/connection.c \
../src/consola.c \
../src/error.c \
../src/file_conf.c 

OBJS += \
./src/FM9.o \
./src/connection.o \
./src/consola.o \
./src/error.o \
./src/file_conf.o 

C_DEPS += \
./src/FM9.d \
./src/connection.d \
./src/consola.d \
./src/error.d \
./src/file_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/git/tp-2018-2c-Hackers-Reloaded/Shared_Library" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


