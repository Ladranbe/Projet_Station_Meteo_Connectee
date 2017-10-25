# MPLAB IDE generated this makefile for use with GNU make.
# Project: SMC.mcp
# Date: Fri May 20 10:52:59 2016

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

SMC.cof : SMC.o SPI.o temperature.o testADC.o
	$(LD) /p18F47J13 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.47\lib" /k"C:\Program Files (x86)\Microchip\mplabc18\v3.47\bin\LKR" "SMC.o" "SPI.o" "temperature.o" "testADC.o" /u_CRUNTIME /u_DEBUG /m"SMC.map" /w /o"SMC.cof"

SMC.o : SMC.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdlib.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdio.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/math.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/spi.h SMC.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f47j13.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdarg.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/pconfig.h testADC.h declaration.h temperature.h
	$(CC) -p=18F47J13 /i"C:\Program Files (x86)\Microchip\mplabc18\v3.47\h" "SMC.c" -fo="SMC.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

SPI.o : SPI.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/spi.h SPI.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/pconfig.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f47j13.h
	$(CC) -p=18F47J13 /i"C:\Program Files (x86)\Microchip\mplabc18\v3.47\h" "SPI.c" -fo="SPI.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

temperature.o : temperature.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/math.h temperature.c adc.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f47j13.h declaration.h testADC.h temperature.h
	$(CC) -p=18F47J13 /i"C:\Program Files (x86)\Microchip\mplabc18\v3.47\h" "temperature.c" -fo="temperature.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

testADC.o : testADC.c testADC.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f47j13.h declaration.h
	$(CC) -p=18F47J13 /i"C:\Program Files (x86)\Microchip\mplabc18\v3.47\h" "testADC.c" -fo="testADC.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "SMC.o" "SPI.o" "temperature.o" "testADC.o" "SMC.cof" "SMC.hex" "SMC.map"

