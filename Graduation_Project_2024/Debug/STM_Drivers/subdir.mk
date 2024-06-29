################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM_Drivers/ADC.c \
../STM_Drivers/EXTI.c \
../STM_Drivers/GPIO.c \
../STM_Drivers/I2C.c \
../STM_Drivers/RCC.c \
../STM_Drivers/SPI.c \
../STM_Drivers/STK.c \
../STM_Drivers/TIMER.c \
../STM_Drivers/UART.c 

OBJS += \
./STM_Drivers/ADC.o \
./STM_Drivers/EXTI.o \
./STM_Drivers/GPIO.o \
./STM_Drivers/I2C.o \
./STM_Drivers/RCC.o \
./STM_Drivers/SPI.o \
./STM_Drivers/STK.o \
./STM_Drivers/TIMER.o \
./STM_Drivers/UART.o 

C_DEPS += \
./STM_Drivers/ADC.d \
./STM_Drivers/EXTI.d \
./STM_Drivers/GPIO.d \
./STM_Drivers/I2C.d \
./STM_Drivers/RCC.d \
./STM_Drivers/SPI.d \
./STM_Drivers/STK.d \
./STM_Drivers/TIMER.d \
./STM_Drivers/UART.d 


# Each subdirectory must supply rules for building sources it contributes
STM_Drivers/ADC.o: ../STM_Drivers/ADC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/EXTI.o: ../STM_Drivers/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/GPIO.o: ../STM_Drivers/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/I2C.o: ../STM_Drivers/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/RCC.o: ../STM_Drivers/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/SPI.o: ../STM_Drivers/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/STK.o: ../STM_Drivers/STK.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/STK.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/TIMER.o: ../STM_Drivers/TIMER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/TIMER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM_Drivers/UART.o: ../STM_Drivers/UART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/STM_Drivers/INC" -I"F:/00_SYSTEMS/01_Learn_In_Depth/07_STM32/Graduation_Project_2024/HAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM_Drivers/UART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

