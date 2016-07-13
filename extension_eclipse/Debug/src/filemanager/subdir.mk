################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/filemanager/FileManager.o 

CPP_SRCS += \
../src/filemanager/FileManager.cpp 

OBJS += \
./src/filemanager/FileManager.o 

CPP_DEPS += \
./src/filemanager/FileManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/filemanager/%.o: ../src/filemanager/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


