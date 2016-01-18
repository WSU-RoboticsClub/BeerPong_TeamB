EESchema Schematic File Version 2
LIBS:74xgxx
LIBS:74xx
LIBS:ac-dc
LIBS:actel
LIBS:adc-dac
LIBS:analog_devices
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:brooktre
LIBS:cmos4000
LIBS:cmos_ieee
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:dc-dc
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:ir
LIBS:linear
LIBS:logo
LIBS:maxim
LIBS:memory
LIBS:microchip
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:microcontrollers
LIBS:motor_drivers
LIBS:motorola
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:opto
LIBS:philips
LIBS:power
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:regul
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:siliconi
LIBS:special
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:texas
LIBS:transf
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:xilinx
LIBS:external
LIBS:AVR_Beerpong_Board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA328P-P IC1
U 1 1 568E1367
P 3900 3200
F 0 "IC1" H 3150 4450 40  0000 L BNN
F 1 "ATMEGA328P-P" H 4300 1800 40  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm_LongPads" H 3900 3200 30  0000 C CIN
F 3 "" H 3900 3200 60  0000 C CNN
	1    3900 3200
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X03 P2
U 1 1 568E13DC
P 8150 2850
F 0 "P2" H 8150 3050 50  0000 C CNN
F 1 "CONN_02X03" H 8150 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 8150 1650 60  0001 C CNN
F 3 "" H 8150 1650 60  0000 C CNN
	1    8150 2850
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 568E1431
P 6350 2900
F 0 "Y1" H 6350 3050 50  0000 C CNN
F 1 "16MHz" H 6350 2750 50  0000 C CNN
F 2 "Crystals:Crystal_HC50-U_Vertical" H 6350 2900 60  0001 C CNN
F 3 "" H 6350 2900 60  0000 C CNN
	1    6350 2900
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 568E1480
P 5450 3300
F 0 "R1" V 5530 3300 50  0000 C CNN
F 1 "10k" V 5450 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5380 3300 30  0001 C CNN
F 3 "" H 5450 3300 30  0000 C CNN
	1    5450 3300
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 568E14F7
P 6050 3550
F 0 "SW1" H 6200 3660 50  0000 C CNN
F 1 "SW_PUSH" H 6050 3470 50  0000 C CNN
F 2 "external:Switch" H 6050 3550 60  0001 C CNN
F 3 "" H 6050 3550 60  0000 C CNN
	1    6050 3550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 568E1526
P 6750 2700
F 0 "C2" H 6775 2800 50  0000 L CNN
F 1 "18pF" H 6775 2600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6788 2550 30  0001 C CNN
F 3 "" H 6750 2700 60  0000 C CNN
	1    6750 2700
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 568E1547
P 6750 3050
F 0 "C3" H 6775 3150 50  0000 L CNN
F 1 "18pF" H 6775 2950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6788 2900 30  0001 C CNN
F 3 "" H 6750 3050 60  0000 C CNN
	1    6750 3050
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 568E156A
P 2550 2900
F 0 "C1" H 2575 3000 50  0000 L CNN
F 1 ".1uF" H 2575 2800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2588 2750 30  0001 C CNN
F 3 "" H 2550 2900 60  0000 C CNN
	1    2550 2900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P4
U 1 1 568E1C03
P 10150 2450
F 0 "P4" H 10150 2700 50  0000 C CNN
F 1 "UART+PWR" V 10250 2450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 10150 2450 60  0001 C CNN
F 3 "" H 10150 2450 60  0000 C CNN
	1    10150 2450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 568E2DD9
P 5450 3100
F 0 "#PWR01" H 5450 2950 50  0001 C CNN
F 1 "+5V" H 5450 3240 50  0000 C CNN
F 2 "" H 5450 3100 60  0000 C CNN
F 3 "" H 5450 3100 60  0000 C CNN
	1    5450 3100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 568E3259
P 2800 2050
F 0 "#PWR02" H 2800 1900 50  0001 C CNN
F 1 "+5V" H 2800 2190 50  0000 C CNN
F 2 "" H 2800 2050 60  0000 C CNN
F 3 "" H 2800 2050 60  0000 C CNN
	1    2800 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 568E3357
P 2750 4450
F 0 "#PWR03" H 2750 4200 50  0001 C CNN
F 1 "GND" H 2750 4300 50  0000 C CNN
F 2 "" H 2750 4450 60  0000 C CNN
F 3 "" H 2750 4450 60  0000 C CNN
	1    2750 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 568E3AE1
P 6450 3600
F 0 "#PWR04" H 6450 3350 50  0001 C CNN
F 1 "GND" H 6450 3450 50  0000 C CNN
F 2 "" H 6450 3600 60  0000 C CNN
F 3 "" H 6450 3600 60  0000 C CNN
	1    6450 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 568E3DE1
P 7000 3150
F 0 "#PWR05" H 7000 2900 50  0001 C CNN
F 1 "GND" H 7000 3000 50  0000 C CNN
F 2 "" H 7000 3150 60  0000 C CNN
F 3 "" H 7000 3150 60  0000 C CNN
	1    7000 3150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 568E4A79
P 8450 2650
F 0 "#PWR06" H 8450 2500 50  0001 C CNN
F 1 "+5V" H 8450 2790 50  0000 C CNN
F 2 "" H 8450 2650 60  0000 C CNN
F 3 "" H 8450 2650 60  0000 C CNN
	1    8450 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 568E4ACE
P 8500 3050
F 0 "#PWR07" H 8500 2800 50  0001 C CNN
F 1 "GND" H 8500 2900 50  0000 C CNN
F 2 "" H 8500 3050 60  0000 C CNN
F 3 "" H 8500 3050 60  0000 C CNN
	1    8500 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X10 P5
U 1 1 568E5060
P 10150 3600
F 0 "P5" H 10150 4150 50  0000 C CNN
F 1 "Driver_Conn" V 10250 3600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x10" H 10150 3600 60  0001 C CNN
F 3 "" H 10150 3600 60  0000 C CNN
	1    10150 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P3
U 1 1 568E530F
P 9900 5050
F 0 "P3" H 9900 5350 50  0000 C CNN
F 1 "PWR" H 9900 4750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x05" H 9900 3850 60  0001 C CNN
F 3 "" H 9900 3850 60  0000 C CNN
	1    9900 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 568E56BB
P 9750 3050
F 0 "#PWR08" H 9750 2800 50  0001 C CNN
F 1 "GND" H 9750 2900 50  0000 C CNN
F 2 "" H 9750 3050 60  0000 C CNN
F 3 "" H 9750 3050 60  0000 C CNN
	1    9750 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 568E56E5
P 9550 3250
F 0 "#PWR09" H 9550 3100 50  0001 C CNN
F 1 "+5V" H 9550 3390 50  0000 C CNN
F 2 "" H 9550 3250 60  0000 C CNN
F 3 "" H 9550 3250 60  0000 C CNN
	1    9550 3250
	1    0    0    -1  
$EndComp
Text Label 9500 3350 0    60   ~ 0
in1
Text Label 9500 3550 0    60   ~ 0
in2
Text Label 9500 3750 0    60   ~ 0
in3
Text Label 9500 3950 0    60   ~ 0
in4
Text Label 9500 3650 0    60   ~ 0
CSA
Text Label 9500 4050 0    60   ~ 0
CSB
Text Label 9500 3450 0    60   ~ 0
ENA
Text Label 9500 3850 0    60   ~ 0
ENB
Text Label 9750 2500 0    60   ~ 0
RX
Text Label 9750 2600 0    60   ~ 0
TX
$Comp
L +5V #PWR010
U 1 1 568E5BA2
P 9800 2300
F 0 "#PWR010" H 9800 2150 50  0001 C CNN
F 1 "+5V" H 9800 2440 50  0000 C CNN
F 2 "" H 9800 2300 60  0000 C CNN
F 3 "" H 9800 2300 60  0000 C CNN
	1    9800 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 568E5BCC
P 9650 2400
F 0 "#PWR011" H 9650 2150 50  0001 C CNN
F 1 "GND" H 9650 2250 50  0000 C CNN
F 2 "" H 9650 2400 60  0000 C CNN
F 3 "" H 9650 2400 60  0000 C CNN
	1    9650 2400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 568E5EA5
P 9500 4750
F 0 "#PWR012" H 9500 4600 50  0001 C CNN
F 1 "+5V" H 9500 4890 50  0000 C CNN
F 2 "" H 9500 4750 60  0000 C CNN
F 3 "" H 9500 4750 60  0000 C CNN
	1    9500 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 568E5ECF
P 10300 5300
F 0 "#PWR013" H 10300 5050 50  0001 C CNN
F 1 "GND" H 10300 5150 50  0000 C CNN
F 2 "" H 10300 5300 60  0000 C CNN
F 3 "" H 10300 5300 60  0000 C CNN
	1    10300 5300
	1    0    0    -1  
$EndComp
Text Label 5100 2100 0    60   ~ 0
in1
Text Label 5100 2200 0    60   ~ 0
in2
Text Label 5100 2300 0    60   ~ 0
in3
Text Label 5350 2300 0    60   ~ 0
in4
Text Label 5100 4300 0    60   ~ 0
ENA
Text Label 5100 4200 0    60   ~ 0
ENB
Text Label 5050 2950 0    60   ~ 0
CSA
Text Label 5050 3050 0    60   ~ 0
CSB
Text Label 4800 5600 0    60   ~ 0
PB0
Text Label 4800 5700 0    60   ~ 0
PB1
Text Label 4800 5800 0    60   ~ 0
PB2
Text Label 4800 5900 0    60   ~ 0
PB3
Text Label 4800 6000 0    60   ~ 0
PB4
Text Label 4800 6100 0    60   ~ 0
PB5
Text Label 4800 6200 0    60   ~ 0
PB6
Text Label 4800 6300 0    60   ~ 0
PB7
Text Label 4800 6400 0    60   ~ 0
PC0
Text Label 5600 6400 0    60   ~ 0
PC1
Text Label 4800 6500 0    60   ~ 0
PC2
Text Label 5600 6500 0    60   ~ 0
PC3
Text Label 4800 6600 0    60   ~ 0
PC4
Text Label 5600 6600 0    60   ~ 0
PC5
$Comp
L CONN_02X12 P1
U 1 1 568E9748
P 5250 6150
F 0 "P1" H 5250 6800 50  0000 C CNN
F 1 "PIN_BREAKOUT" V 5250 6150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x12" H 5250 4950 60  0001 C CNN
F 3 "" H 5250 4950 60  0000 C CNN
	1    5250 6150
	1    0    0    -1  
$EndComp
Text Label 4800 6700 0    60   ~ 0
PC6
Text Label 5600 5600 0    60   ~ 0
PD0
Text Label 5600 5700 0    60   ~ 0
PD1
Text Label 5600 5800 0    60   ~ 0
PD2
Text Label 5600 5900 0    60   ~ 0
PD3
Text Label 5600 6000 0    60   ~ 0
PD4
Text Label 5600 6100 0    60   ~ 0
PD5
Text Label 5600 6200 0    60   ~ 0
PD6
Text Label 5600 6300 0    60   ~ 0
PD7
Text Label 5000 3700 0    60   ~ 0
RX
Text Label 5000 3800 0    60   ~ 0
TX
Text Label 5100 1950 0    60   ~ 0
PB0
Text Label 5350 1950 0    60   ~ 0
PB1
Text Label 5600 1950 0    60   ~ 0
PB2
Text Label 5850 1950 0    60   ~ 0
PB3
Text Label 6100 1950 0    60   ~ 0
PB4
Text Label 6350 1950 0    60   ~ 0
PB5
Text Label 6600 1950 0    60   ~ 0
PB6
Text Label 6850 1950 0    60   ~ 0
PB7
Text Label 5000 4550 0    60   ~ 0
PD0
Text Label 5250 4550 0    60   ~ 0
PD1
Text Label 5500 4550 0    60   ~ 0
PD2
Text Label 5750 4550 0    60   ~ 0
PD3
Text Label 6000 4550 0    60   ~ 0
PD4
Text Label 6250 4550 0    60   ~ 0
PD5
Text Label 6500 4550 0    60   ~ 0
PD6
Text Label 6750 4550 0    60   ~ 0
PD7
Wire Wire Line
	4900 3550 5750 3550
Wire Wire Line
	3000 4400 2750 4400
Wire Wire Line
	2750 4300 2750 4450
Wire Wire Line
	2550 4300 3000 4300
Connection ~ 2750 4400
Wire Wire Line
	2550 4300 2550 3050
Connection ~ 2750 4300
Wire Wire Line
	3000 2100 2800 2100
Wire Wire Line
	2800 2050 2800 2700
Wire Wire Line
	2800 2400 3000 2400
Connection ~ 2800 2100
Wire Wire Line
	2550 2700 3000 2700
Connection ~ 2800 2400
Connection ~ 2800 2700
Wire Wire Line
	2550 2750 2550 2700
Wire Wire Line
	5450 3450 5450 3550
Connection ~ 5450 3550
Wire Wire Line
	5450 3100 5450 3150
Wire Wire Line
	6350 3550 6450 3550
Wire Wire Line
	6450 3550 6450 3600
Wire Wire Line
	4900 2800 5850 2800
Wire Wire Line
	5850 2800 5850 3050
Wire Wire Line
	5850 3050 6600 3050
Wire Wire Line
	4900 2700 6600 2700
Connection ~ 6350 3050
Wire Wire Line
	6350 2700 6350 2750
Connection ~ 6350 2700
Wire Wire Line
	6900 2700 6900 3050
Wire Wire Line
	7000 3150 7000 3050
Wire Wire Line
	7000 3050 6900 3050
Wire Wire Line
	4900 2500 7700 2500
Wire Wire Line
	7700 2500 7700 2750
Wire Wire Line
	7700 2750 7900 2750
Wire Wire Line
	8400 2850 8600 2850
Wire Wire Line
	8600 2850 8600 2400
Wire Wire Line
	8600 2400 4900 2400
Wire Wire Line
	8450 2650 8450 2750
Wire Wire Line
	8450 2750 8400 2750
Wire Wire Line
	8400 2950 8500 2950
Wire Wire Line
	8500 2950 8500 3050
Wire Wire Line
	7900 2850 7400 2850
Wire Wire Line
	7400 2850 7400 2550
Wire Wire Line
	7400 2550 5550 2550
Wire Wire Line
	5550 2550 5550 2600
Wire Wire Line
	5550 2600 4900 2600
Wire Wire Line
	7900 2950 7300 2950
Wire Wire Line
	7300 2950 7300 3350
Wire Wire Line
	7300 3350 5650 3350
Wire Wire Line
	5650 3350 5650 3550
Connection ~ 5650 3550
Wire Wire Line
	9950 3850 9500 3850
Wire Wire Line
	9500 3950 9950 3950
Wire Wire Line
	9950 4050 9500 4050
Wire Wire Line
	9500 3750 9950 3750
Wire Wire Line
	9950 3650 9500 3650
Wire Wire Line
	9500 3550 9950 3550
Wire Wire Line
	9950 3450 9500 3450
Wire Wire Line
	9500 3350 9950 3350
Wire Wire Line
	9950 3250 9550 3250
Wire Wire Line
	9950 3150 9950 3050
Wire Wire Line
	9950 3050 9750 3050
Wire Wire Line
	9950 2400 9650 2400
Wire Wire Line
	9800 2300 9950 2300
Wire Wire Line
	9750 2500 9950 2500
Wire Wire Line
	9950 2600 9750 2600
Wire Wire Line
	10150 4950 10300 4950
Wire Wire Line
	10300 4850 10300 5300
Wire Wire Line
	10300 4850 10150 4850
Wire Wire Line
	10300 5050 10150 5050
Connection ~ 10300 4950
Wire Wire Line
	10300 5150 10150 5150
Connection ~ 10300 5050
Wire Wire Line
	10300 5250 10150 5250
Connection ~ 10300 5150
Connection ~ 10300 5250
Wire Wire Line
	9500 5250 9650 5250
Wire Wire Line
	9500 4750 9500 5250
Wire Wire Line
	9500 5150 9650 5150
Wire Wire Line
	9650 5050 9500 5050
Connection ~ 9500 5150
Wire Wire Line
	9650 4950 9500 4950
Connection ~ 9500 5050
Wire Wire Line
	9650 4850 9500 4850
Connection ~ 9500 4950
Connection ~ 9500 4850
Wire Wire Line
	5350 2300 5350 2400
Connection ~ 5350 2400
Wire Wire Line
	5100 2300 4900 2300
Wire Wire Line
	5100 2200 4900 2200
Wire Wire Line
	5100 2100 4900 2100
Wire Wire Line
	5100 4200 4900 4200
Wire Wire Line
	5100 4300 4900 4300
Wire Wire Line
	5050 3050 4900 3050
Wire Wire Line
	5050 2950 4900 2950
Wire Wire Line
	5500 5600 5600 5600
Wire Wire Line
	5600 5700 5500 5700
Wire Wire Line
	5500 5800 5600 5800
Wire Wire Line
	5600 5900 5500 5900
Wire Wire Line
	5500 6000 5600 6000
Wire Wire Line
	5600 6100 5500 6100
Wire Wire Line
	5500 6200 5600 6200
Wire Wire Line
	5600 6300 5500 6300
Wire Wire Line
	5500 6400 5600 6400
Wire Wire Line
	5600 6500 5500 6500
Wire Wire Line
	5500 6600 5600 6600
Wire Wire Line
	5000 6700 4800 6700
Wire Wire Line
	4800 6600 5000 6600
Wire Wire Line
	5000 6500 4800 6500
Wire Wire Line
	4800 6400 5000 6400
Wire Wire Line
	5000 6300 4800 6300
Wire Wire Line
	4800 6200 5000 6200
Wire Wire Line
	5000 6100 4800 6100
Wire Wire Line
	4800 6000 5000 6000
Wire Wire Line
	5000 5900 4800 5900
Wire Wire Line
	4800 5800 5000 5800
Wire Wire Line
	5000 5700 4800 5700
Wire Wire Line
	4800 5600 5000 5600
Wire Wire Line
	4900 3800 5300 3800
Wire Wire Line
	4900 3700 5000 3700
Wire Wire Line
	4900 2100 4900 1950
Wire Wire Line
	4900 1950 5100 1950
Wire Wire Line
	5350 1950 5350 2000
Wire Wire Line
	5350 2000 5000 2000
Wire Wire Line
	5000 2000 5000 2200
Connection ~ 5000 2200
Connection ~ 4900 2100
Wire Wire Line
	5600 1950 5600 2050
Wire Wire Line
	5600 2050 5050 2050
Wire Wire Line
	5050 2050 5050 2300
Connection ~ 5050 2300
Wire Wire Line
	5850 1950 5850 2400
Connection ~ 5850 2400
Wire Wire Line
	6100 1950 6100 2500
Connection ~ 6100 2500
Wire Wire Line
	6350 1950 6350 2550
Connection ~ 6350 2550
Wire Wire Line
	6600 1950 6600 2600
Wire Wire Line
	6600 2600 6500 2600
Wire Wire Line
	6500 2600 6500 2700
Connection ~ 6500 2700
Wire Wire Line
	6850 1950 6850 2300
Wire Wire Line
	6850 2300 5750 2300
Wire Wire Line
	5750 2300 5750 2800
Connection ~ 5750 2800
Wire Wire Line
	6750 4550 6750 4400
Wire Wire Line
	6750 4400 4900 4400
Wire Wire Line
	5000 4550 5000 4500
Wire Wire Line
	5000 4500 4950 4500
Wire Wire Line
	4950 4500 4950 3700
Connection ~ 4950 3700
Wire Wire Line
	5300 3800 5300 4450
Wire Wire Line
	5300 4450 5250 4450
Wire Wire Line
	5250 4450 5250 4550
Wire Wire Line
	5500 4550 5500 3900
Wire Wire Line
	5500 3900 4900 3900
Wire Wire Line
	4900 4000 5750 4000
Wire Wire Line
	5750 4000 5750 4550
Wire Wire Line
	4900 4100 6000 4100
Wire Wire Line
	6000 4100 6000 4550
Wire Wire Line
	5050 4200 5050 4050
Wire Wire Line
	5050 4050 6250 4050
Wire Wire Line
	6250 4050 6250 4550
Connection ~ 5050 4200
Wire Wire Line
	5050 4300 5050 4350
Wire Wire Line
	5050 4350 6500 4350
Wire Wire Line
	6500 4350 6500 4550
Connection ~ 5050 4300
Text Label 7700 3450 0    60   ~ 0
PC0
Text Label 7700 3550 0    60   ~ 0
PC1
Text Label 7700 3650 0    60   ~ 0
PC2
Text Label 7700 3750 0    60   ~ 0
PC3
Text Label 7700 3850 0    60   ~ 0
PC4
Text Label 7700 3950 0    60   ~ 0
PC5
Text Label 7700 4050 0    60   ~ 0
PC6
Wire Wire Line
	7700 3450 6500 3450
Wire Wire Line
	6500 3450 6500 3150
Wire Wire Line
	6500 3150 5650 3150
Wire Wire Line
	5650 3150 5650 2850
Wire Wire Line
	5650 2850 5000 2850
Wire Wire Line
	5000 2850 5000 2950
Connection ~ 5000 2950
Wire Wire Line
	5000 3050 5000 3100
Wire Wire Line
	5000 3100 5300 3100
Wire Wire Line
	5300 3100 5300 2900
Wire Wire Line
	5300 2900 5600 2900
Wire Wire Line
	5600 2900 5600 3200
Wire Wire Line
	5600 3200 6450 3200
Wire Wire Line
	6450 3200 6450 3500
Wire Wire Line
	6450 3500 7550 3500
Wire Wire Line
	7550 3500 7550 3550
Wire Wire Line
	7550 3550 7700 3550
Connection ~ 5000 3050
Wire Wire Line
	7700 3650 6600 3650
Wire Wire Line
	6600 3650 6600 3800
Wire Wire Line
	6600 3800 5800 3800
Wire Wire Line
	5800 3800 5800 3500
Wire Wire Line
	5800 3500 5250 3500
Wire Wire Line
	5250 3500 5250 3150
Wire Wire Line
	5250 3150 4900 3150
Wire Wire Line
	4900 3250 5200 3250
Wire Wire Line
	5200 3250 5200 3600
Wire Wire Line
	5200 3600 5750 3600
Wire Wire Line
	5750 3600 5750 3850
Wire Wire Line
	5750 3850 6650 3850
Wire Wire Line
	6650 3850 6650 3750
Wire Wire Line
	6650 3750 7700 3750
Wire Wire Line
	7700 3850 6700 3850
Wire Wire Line
	6700 3850 6700 3900
Wire Wire Line
	6700 3900 5700 3900
Wire Wire Line
	5700 3900 5700 3650
Wire Wire Line
	5700 3650 5150 3650
Wire Wire Line
	5150 3650 5150 3350
Wire Wire Line
	5150 3350 4900 3350
Wire Wire Line
	4900 3450 6050 3450
Wire Wire Line
	6050 3450 6050 3400
Wire Wire Line
	6050 3400 7450 3400
Wire Wire Line
	7450 3400 7450 3950
Wire Wire Line
	7450 3950 7700 3950
Wire Wire Line
	7700 4050 6400 4050
Wire Wire Line
	6400 4050 6400 3950
Wire Wire Line
	6400 3950 5600 3950
Wire Wire Line
	5600 3950 5600 3550
Connection ~ 5600 3550
$EndSCHEMATC