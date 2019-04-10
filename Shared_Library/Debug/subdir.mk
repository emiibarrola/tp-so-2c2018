################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../diego_cpu.c \
../fm9_cpu.c \
../fm9_diego.c \
../mdj_diego.c \
../safa_cpu.c \
../safa_diego.c \
../shared.c 

OBJS += \
./diego_cpu.o \
./fm9_cpu.o \
./fm9_diego.o \
./mdj_diego.o \
./safa_cpu.o \
./safa_diego.o \
./shared.o 

C_DEPS += \
./diego_cpu.d \
./fm9_cpu.d \
./fm9_diego.d \
./mdj_diego.d \
./safa_cpu.d \
./safa_diego.d \
./shared.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


