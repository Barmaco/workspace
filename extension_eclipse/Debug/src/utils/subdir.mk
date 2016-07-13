################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/utils/Buffer.o \
../src/utils/ChineseData.o \
../src/utils/XTimeUtil.o 

CPP_SRCS += \
../src/utils/Buffer.cpp \
../src/utils/ChineseData.cpp \
../src/utils/XTimeUtil.cpp 

OBJS += \
./src/utils/Buffer.o \
./src/utils/ChineseData.o \
./src/utils/XTimeUtil.o 

CPP_DEPS += \
./src/utils/Buffer.d \
./src/utils/ChineseData.d \
./src/utils/XTimeUtil.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/%.o: ../src/utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


