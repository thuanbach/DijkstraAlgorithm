################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dijkstra_althorighm.cpp \
../src/graph.cpp \
../src/main.cpp \
../src/prim_althorightm.cpp \
../src/utils.cpp 

OBJS += \
./src/dijkstra_althorighm.o \
./src/graph.o \
./src/main.o \
./src/prim_althorightm.o \
./src/utils.o 

CPP_DEPS += \
./src/dijkstra_althorighm.d \
./src/graph.d \
./src/main.d \
./src/prim_althorightm.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


