################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera2d.cpp \
../Errors.cpp \
../GLSLProgram.cpp \
../GameEngineCore.cpp \
../IOManager.cpp \
../ImageLoader.cpp \
../ResourceManager.cpp \
../Sprite.cpp \
../TextureCache.cpp \
../Window.cpp \
../picopng.cpp 

OBJS += \
./Camera2d.o \
./Errors.o \
./GLSLProgram.o \
./GameEngineCore.o \
./IOManager.o \
./ImageLoader.o \
./ResourceManager.o \
./Sprite.o \
./TextureCache.o \
./Window.o \
./picopng.o 

CPP_DEPS += \
./Camera2d.d \
./Errors.d \
./GLSLProgram.d \
./GameEngineCore.d \
./IOManager.d \
./ImageLoader.d \
./ResourceManager.d \
./Sprite.d \
./TextureCache.d \
./Window.d \
./picopng.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/salar/workspace/GameEngineCore" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


