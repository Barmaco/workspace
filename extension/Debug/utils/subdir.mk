################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utils/Buffer.cpp \
../utils/ChineseData.cpp \
../utils/FileManager.cpp \
../utils/XTimeUtil.cpp 

OBJS += \
./utils/Buffer.o \
./utils/ChineseData.o \
./utils/FileManager.o \
./utils/XTimeUtil.o 

CPP_DEPS += \
./utils/Buffer.d \
./utils/ChineseData.d \
./utils/FileManager.d \
./utils/XTimeUtil.d 


# Each subdirectory must supply rules for building sources it contributes
utils/%.o: ../utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


