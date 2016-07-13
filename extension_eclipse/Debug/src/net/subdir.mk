################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/net/BaseNetDelegate.o 

CPP_SRCS += \
../src/net/BaseNetDelegate.cpp \
../src/net/ClientNetDelegate.cpp \
../src/net/ServerNetDelegate.cpp 

OBJS += \
./src/net/BaseNetDelegate.o \
./src/net/ClientNetDelegate.o \
./src/net/ServerNetDelegate.o 

CPP_DEPS += \
./src/net/BaseNetDelegate.d \
./src/net/ClientNetDelegate.d \
./src/net/ServerNetDelegate.d 


# Each subdirectory must supply rules for building sources it contributes
src/net/%.o: ../src/net/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


