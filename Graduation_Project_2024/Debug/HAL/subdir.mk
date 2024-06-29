################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/BUZZER.c \
../HAL/DC.c \
../HAL/LCD.c \
../HAL/LDR.c \
../HAL/ULTRASONIC.c 

OBJS += \
./HAL/BUZZER.o \
./HAL/DC.o \
./HAL/LCD.o \
./HAL/LDR.o \
./HAL/ULTRASONIC.o 

C_DEPS += \
./HAL/BUZZER.d \
./HAL/DC.d \
./HAL/LCD.d \
./HAL/LDR.d \
./HAL/ULTRASONIC.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/BUZZER.o: ../HAL/BUZZER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/BUZZER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/DC.o: ../HAL/DC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/DC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LDR.o: ../HAL/LDR.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LDR.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/ULTRASONIC.o: ../HAL/ULTRASONIC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/ULTRASONIC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

