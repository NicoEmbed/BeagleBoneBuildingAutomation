################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Testina.c 

OBJS += \
./src/Testina.o 

C_DEPS += \
./src/Testina.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	/home/ubuntu/usr/local/angstrom/arm/bin/arm-angstrom-linux-gnueabi-gcc -I/home/ubuntu/usr/local/angstrom/arm/arm-angstrom-linux-gnueabi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


