################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MWDT/MWDT_program.c 

OBJS += \
./MCAL/MWDT/MWDT_program.o 

C_DEPS += \
./MCAL/MWDT/MWDT_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MWDT/%.o: ../MCAL/MWDT/%.c MCAL/MWDT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


