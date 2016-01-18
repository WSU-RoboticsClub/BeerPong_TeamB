#makefile for the beerpong robot for linux distros
CC=avr-gcc
OCC=avr-objcopy
OCFLAGS= -j .text -j .data -O ihex
CFLAGS=-mmcu=atmega328p -Iinclude/ -Isublib_avr/include/ -L$(LIB_PATH) -Wall

LIB_PATH=sublib_avr/build/
LIB_NAME=SUBLIBinal_avr
SRC_DIR=src/
BUILD_DIR=build/

default: beerpong.hex

beerpong.hex : beerpong.elf
	$(OCC) $(OCFLAGS) $(BUILD_DIR)beerpong.elf $(BUILD_DIR)$@

beerpong.elf : main.o serial.o motors.o PID.o
	$(CC) $(CFLAGS) $(BUILD_DIR)main.o $(BUILD_DIR)serial.o $(BUILD_DIR)motors.o $(BUILD_DIR)PID.o -o $(BUILD_DIR)$@ -l$(LIB_NAME)

main.o : $(SRC_DIR)main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)main.c -o $(BUILD_DIR)main.o 

serial.o : $(SRC_DIR)serial.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)serial.c -o $(BUILD_DIR)serial.o

motors.o : $(SRC_DIR)motors.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)motors.c -o $(BUILD_DIR)motors.o

PID.o : $(SRC_DIR)PID.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)PID.c -o $(BUILD_DIR)PID.o

$(shell mkdir -p $(BUILD_DIR))
