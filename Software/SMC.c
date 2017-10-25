//******************************************************************************
//Software License Agreement                                         
//                                                                    
//The software supplied herewith by Microchip Technology             
//Incorporated (the "Company") is intended and supplied to you, the  
//Company’s customer, for use solely and exclusively on Microchip    
//products. The software is owned by the Company and/or its supplier,
//and is protected under applicable copyright laws. All rights are   
//reserved. Any use in violation of the foregoing restrictions may   
//subject the user to criminal sanctions under applicable laws, as   
//well as to civil liability for the breach of the terms and         
//conditions of this license.                                        
//                                                                    
//THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,  
//WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED  
//TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A       
//PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,  
//IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR         
//CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.       
// *******************************************************************
// PIC18F46K20 Starter Kit Lesson 1 - Hello LED
//
// This lesson turns on LED 7 on the demo board.
//
// *******************************************************************
// *    See included documentation for Lesson instructions           *
// *******************************************************************

/** C O N F I G U R A T I O N   B I T S ******************************/

#pragma config OSC = INTOSCPLL
#pragma config PLLSEL = PLL96 //96MHz PLL 
#pragma config PLLDIV = 2 //Divide by 2 (8 MHz oscillator input) 
#pragma config WDTEN = OFF
#pragma config CFGPLLEN = ON //PLL Enabled 
#pragma config XINST = OFF
#pragma config ADCSEL= BIT10
/*
#pragma config WDTEN = OFF // WDT disabled (control is placed on the SWDTEN bit)
#pragma config OSC = INTOSCPLL // Internal oscillator block, port function on RA6 and RA7 
#pragma config DSBOREN = OFF // Brown-Out OFF
#pragma config STVREN = ON // Stack full/underflow will cause Reset
#pragma config ADCSEL = BIT12
//#pragma config PLLSEL = PLL96*/

 
/** I N C L U D E S **************************************************/
#include <p18f47j13.h>
#include <delays.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <spi.h>
#include "testADC.h"
#include "declaration.h"
#include "temperature.h"


/** D E C L A R A T I O N S ******************************************/
unsigned char instruction1[4];
unsigned char instruction[3];
unsigned char MAC[6];
unsigned char SIGNATURE[1];
UINT32 temperature;
void main (void)
{
/**************************** test SPI *******************************/
// Initialisation + Ecriture EEPROM 25LC1024
/*	initialiserSPI();
 	while(1){
		while(SSP1STATbits.BF==0){
			SSPBUF=0xAF;
			LATAbits.LATA6 = 0;
		}
	}*//*
	initialiserSPI();
	instruction1[0]=0xAB;
	instruction1[1]=0xFF;
	instruction1[2]=0xFF;
	instruction1[3]=0xFF;
	while(1){
		LATAbits.LATA6 =0;
		putsSPI1(instruction1);
		getsSPI1(SIGNATURE,8);
		LATAbits.LATA6=1;
		}
*//*
// Initialisation + Lecture adresse MAC EEPROM 25AA02E48
	initialiserSPI();
	instruction[0]=0x03;
	instruction[1]=0xFA;
	instruction[2]=0x00;

		while(1){
		LATAbits.LATA7 =0;
		putsSPI1(instruction);
		getsSPI1(MAC,6);
		LATAbits.LATA7=1;
		Delay10TCYx(1);
		}*/

/*initialiserSPI();
 	while(1){
		while(SSP1STATbits.BF==0){
			SSPBUF=0xAF;
			LATEbits.LATE0= 0;
		}
	}
 */
	initialiserADC();
	while(1){
		temperature=lireTemp();
		//temperature=lireADC();
	}
}