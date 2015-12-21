#makefile for the beerpong robot for linux distros
CC=avr-gcc
OCC=avr-objcopy
OCFLAGS= -j .text -j .data -O ihex
CFLAGS=-mmcu=atmega328p -Iinclude/ -Isublib_avr/include/ -L$(LIB_PATH)

LIB_PATH=sublib_avr/build/
LIB_NAME=SUBLIBinal_avr
SRC_DIR=src/
BUILD_DIR=build/

default: beerpong.hex

beerpong.hex : beerpong.elf
	$(OCC) $(OCFLAGS) $(BUILD_DIR)beerpong.elf $(BUILD_DIR)$@

beerpong.elf : main.o serial.o motors.o
	$(CC) $(CFLAGS) $(BUILD_DIR)main.o $(BUILD_DIR)serial.o $(BUILD_DIR)motors.o -o $(BUILD_DIR)$@ -l$(LIB_NAME)

main.o : $(SRC_DIR)main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)main.c -o $(BUILD_DIR)main.o -l$(LIB_NAME) 

serial.o : $(SRC_DIR)serial.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)serial.c -o $(BUILD_DIR)serial.o -l$(LIB_NAME) 

motors.o : $(SRC_DIR)motors.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)motors.c -o $(BUILD_DIR)motors.o -l$(LIB_NAME) 

$(shell mkdir -p $(BUILD_DIR))
