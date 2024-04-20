################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App.c \
../Src/DIO_Program.c \
../Src/Final_Project.c \
../Src/GI_program.c \
../Src/TIMER_Program.c \
../Src/UART_Program.c 

OBJS += \
./Src/App.o \
./Src/DIO_Program.o \
./Src/Final_Project.o \
./Src/GI_program.o \
./Src/TIMER_Program.o \
./Src/UART_Program.o 

C_DEPS += \
./Src/App.d \
./Src/DIO_Program.d \
./Src/Final_Project.d \
./Src/GI_program.d \
./Src/TIMER_Program.d \
./Src/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


