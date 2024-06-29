################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/APP.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/APP.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APP.o: ../Src/APP.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

