################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../examples/test.o 

CPP_SRCS += \
../examples/NetDelegate.cpp \
../examples/server_test.cpp 

OBJS += \
./examples/NetDelegate.o \
./examples/server_test.o 

CPP_DEPS += \
./examples/NetDelegate.d \
./examples/server_test.d 


# Each subdirectory must supply rules for building sources it contributes
examples/%.o: ../examples/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


