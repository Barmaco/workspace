################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../net/BaseNetDelegate.o 

CPP_SRCS += \
../net/BaseNetDelegate.cpp \
../net/ClientNetDelegate.cpp \
../net/ServerNetDelegate.cpp 

OBJS += \
./net/BaseNetDelegate.o \
./net/ClientNetDelegate.o \
./net/ServerNetDelegate.o 

CPP_DEPS += \
./net/BaseNetDelegate.d \
./net/ClientNetDelegate.d \
./net/ServerNetDelegate.d 


# Each subdirectory must supply rules for building sources it contributes
net/%.o: ../net/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


