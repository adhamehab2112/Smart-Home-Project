################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MUART/MUART_program.c 

OBJS += \
./MCAL/MUART/MUART_program.o 

C_DEPS += \
./MCAL/MUART/MUART_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MUART/%.o: ../MCAL/MUART/%.c MCAL/MUART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

