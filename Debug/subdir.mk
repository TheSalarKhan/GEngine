################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Errors.cpp \
../GLSLProgram.cpp \
../IOManager.cpp \
../ImageLoader.cpp \
../ResourceManager.cpp \
../Sprite.cpp \
../TextureCache.cpp \
../picopng.cpp 

OBJS += \
./Errors.o \
./GLSLProgram.o \
./IOManager.o \
./ImageLoader.o \
./ResourceManager.o \
./Sprite.o \
./TextureCache.o \
./picopng.o 

CPP_DEPS += \
./Errors.d \
./GLSLProgram.d \
./IOManager.d \
./ImageLoader.d \
./ResourceManager.d \
./Sprite.d \
./TextureCache.d \
./picopng.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


