EESchema Schematic File Version 4
EELAYER 30 0
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
Wire Wire Line
	6950 3750 6950 3800
Wire Wire Line
	7100 3800 6950 3800
Wire Wire Line
	7350 3100 7100 3100
Wire Wire Line
	7100 3100 7100 3800
Connection ~ 6950 3800
Wire Wire Line
	6350 4000 6350 4100
Wire Wire Line
	6750 3000 7450 3000
Wire Wire Line
	7450 3000 7450 3100
Wire Wire Line
	6750 3100 7000 3100
Wire Wire Line
	7000 3100 7000 2900
Wire Wire Line
	7000 2900 7650 2900
Wire Wire Line
	7650 2900 7650 3100
Wire Wire Line
	6750 3200 7050 3200
Wire Wire Line
	7050 3200 7050 3300
Wire Wire Line
	7050 3300 7250 3300
Wire Wire Line
	6750 3300 7000 3300
Wire Wire Line
	7000 3300 7000 3500
Wire Wire Line
	7000 3500 7250 3500
NoConn ~ 6750 3400
NoConn ~ 6750 3500
NoConn ~ 6750 3600
NoConn ~ 5950 3600
NoConn ~ 5950 3500
NoConn ~ 5950 3400
Wire Wire Line
	4800 4150 4800 4050
Wire Wire Line
	5100 4050 5100 4150
Wire Wire Line
	5400 4050 5400 4150
Wire Wire Line
	5700 4050 5700 4150
Wire Wire Line
	4800 3750 4800 3700
Wire Wire Line
	5100 3700 5100 3750
Wire Wire Line
	5400 3700 5400 3750
Wire Wire Line
	5700 3700 5700 3750
Wire Wire Line
	4250 3300 5700 3300
Wire Wire Line
	5700 3300 5700 3400
Wire Wire Line
	4250 3200 5400 3200
Wire Wire Line
	5400 3200 5400 3400
Wire Wire Line
	4250 3100 5100 3100
Wire Wire Line
	5100 3100 5100 3400
Wire Wire Line
	4250 3000 4800 3000
Wire Wire Line
	4800 3000 4800 3400
Connection ~ 4800 3000
Connection ~ 5100 3100
Connection ~ 5400 3200
Connection ~ 5700 3300
Wire Wire Line
	4250 3400 4400 3400
Wire Wire Line
	4400 3400 4400 3550
Wire Wire Line
	4250 2900 4400 2900
Wire Wire Line
	4400 2900 4400 2850
Wire Wire Line
	6950 3800 6750 3800
Wire Wire Line
	4800 3000 5950 3000
Wire Wire Line
	5100 3100 5950 3100
Wire Wire Line
	5400 3200 5950 3200
Wire Wire Line
	5700 3300 5950 3300
$Comp
L Transistor_Array:ULN2003 U1
U 1 1 5EA79ACE
P 6350 3400
F 0 "U1" H 6350 3975 50  0000 C CNN
F 1 "ULN2003" H 6350 4066 50  0000 C CNN
F 2 "" H 6400 2850 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2003a.pdf" H 6450 3200 50  0001 C CNN
	1    6350 3400
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 5EA7CD03
P 4050 3100
F 0 "J1" H 4158 3389 50  0000 C CNN
F 1 "Conn_01x06_Male" H 4158 3390 50  0001 C CNN
F 2 "" H 4050 3100 50  0001 C CNN
F 3 "~" H 4050 3100 50  0001 C CNN
	1    4050 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5EA7D7BB
P 4400 3550
F 0 "#PWR02" H 4400 3300 50  0001 C CNN
F 1 "GND" H 4405 3377 50  0000 C CNN
F 2 "" H 4400 3550 50  0001 C CNN
F 3 "" H 4400 3550 50  0001 C CNN
	1    4400 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR01
U 1 1 5EA827FD
P 4400 2850
F 0 "#PWR01" H 4400 2700 50  0001 C CNN
F 1 "+12V" H 4415 3023 50  0000 C CNN
F 2 "" H 4400 2850 50  0001 C CNN
F 3 "" H 4400 2850 50  0001 C CNN
	1    4400 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5EA8405F
P 6350 4100
F 0 "#PWR07" H 6350 3850 50  0001 C CNN
F 1 "GND" H 6355 3927 50  0000 C CNN
F 2 "" H 6350 4100 50  0001 C CNN
F 3 "" H 6350 4100 50  0001 C CNN
	1    6350 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR08
U 1 1 5EA85353
P 6950 3750
F 0 "#PWR08" H 6950 3600 50  0001 C CNN
F 1 "+12V" H 6965 3923 50  0000 C CNN
F 2 "" H 6950 3750 50  0001 C CNN
F 3 "" H 6950 3750 50  0001 C CNN
	1    6950 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5EA86907
P 4800 3550
F 0 "R1" V 4700 3500 50  0000 L CNN
F 1 "500R" V 4900 3500 50  0000 L CNN
F 2 "" V 4730 3550 50  0001 C CNN
F 3 "~" H 4800 3550 50  0001 C CNN
	1    4800 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5EA888FF
P 5100 3550
F 0 "R2" V 5000 3500 50  0000 L CNN
F 1 "500R" V 5200 3500 50  0000 L CNN
F 2 "" V 5030 3550 50  0001 C CNN
F 3 "~" H 5100 3550 50  0001 C CNN
	1    5100 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5EA88B0C
P 5400 3550
F 0 "R3" V 5300 3500 50  0000 L CNN
F 1 "500R" V 5500 3500 50  0000 L CNN
F 2 "" V 5330 3550 50  0001 C CNN
F 3 "~" H 5400 3550 50  0001 C CNN
	1    5400 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5EA88ECE
P 5700 3550
F 0 "R4" V 5600 3500 50  0000 L CNN
F 1 "500R" V 5800 3500 50  0000 L CNN
F 2 "" V 5630 3550 50  0001 C CNN
F 3 "~" H 5700 3550 50  0001 C CNN
	1    5700 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5EA897AC
P 4800 3900
F 0 "D1" V 4793 3782 50  0000 R CNN
F 1 "LED" V 4748 3783 50  0001 R CNN
F 2 "" H 4800 3900 50  0001 C CNN
F 3 "~" H 4800 3900 50  0001 C CNN
	1    4800 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5EA8A24E
P 5100 3900
F 0 "D2" V 5093 3782 50  0000 R CNN
F 1 "LED" V 5048 3783 50  0001 R CNN
F 2 "" H 5100 3900 50  0001 C CNN
F 3 "~" H 5100 3900 50  0001 C CNN
	1    5100 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5EA8A80E
P 5400 3900
F 0 "D3" V 5393 3782 50  0000 R CNN
F 1 "LED" V 5348 3783 50  0001 R CNN
F 2 "" H 5400 3900 50  0001 C CNN
F 3 "~" H 5400 3900 50  0001 C CNN
	1    5400 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D4
U 1 1 5EA8AB92
P 5700 3900
F 0 "D4" V 5693 3782 50  0000 R CNN
F 1 "LED" V 5648 3783 50  0001 R CNN
F 2 "" H 5700 3900 50  0001 C CNN
F 3 "~" H 5700 3900 50  0001 C CNN
	1    5700 3900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5EA8B96A
P 4800 4150
F 0 "#PWR03" H 4800 3900 50  0001 C CNN
F 1 "GND" H 4805 3977 50  0000 C CNN
F 2 "" H 4800 4150 50  0001 C CNN
F 3 "" H 4800 4150 50  0001 C CNN
	1    4800 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5EA8BD07
P 5100 4150
F 0 "#PWR04" H 5100 3900 50  0001 C CNN
F 1 "GND" H 5105 3977 50  0000 C CNN
F 2 "" H 5100 4150 50  0001 C CNN
F 3 "" H 5100 4150 50  0001 C CNN
	1    5100 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5EA8BF74
P 5400 4150
F 0 "#PWR05" H 5400 3900 50  0001 C CNN
F 1 "GND" H 5405 3977 50  0000 C CNN
F 2 "" H 5400 4150 50  0001 C CNN
F 3 "" H 5400 4150 50  0001 C CNN
	1    5400 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5EA8C32D
P 5700 4150
F 0 "#PWR06" H 5700 3900 50  0001 C CNN
F 1 "GND" H 5705 3977 50  0000 C CNN
F 2 "" H 5700 4150 50  0001 C CNN
F 3 "" H 5700 4150 50  0001 C CNN
	1    5700 4150
	1    0    0    -1  
$EndComp
$Comp
L Motor:Stepper_Motor_unipolar_5pin M1
U 1 1 5EA8D85F
P 7550 3400
F 0 "M1" H 7738 3524 50  0000 L CNN
F 1 "Stepper_Motor_unipolar_5pin" H 7738 3433 50  0000 L CNN
F 2 "" H 7560 3390 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 7560 3390 50  0001 C CNN
	1    7550 3400
	1    0    0    -1  
$EndComp
$EndSCHEMATC