################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ensayoclinico.cpp \
../src/paciente.cpp \
../src/pr_ensayoclinico.cpp \
../src/prog_principal.cpp \
../src/timer.cpp 

CPP_DEPS += \
./src/ensayoclinico.d \
./src/paciente.d \
./src/pr_ensayoclinico.d \
./src/prog_principal.d \
./src/timer.d 

OBJS += \
./src/ensayoclinico.o \
./src/paciente.o \
./src/pr_ensayoclinico.o \
./src/prog_principal.o \
./src/timer.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ensayoclinico.d ./src/ensayoclinico.o ./src/paciente.d ./src/paciente.o ./src/pr_ensayoclinico.d ./src/pr_ensayoclinico.o ./src/prog_principal.d ./src/prog_principal.o ./src/timer.d ./src/timer.o

.PHONY: clean-src

