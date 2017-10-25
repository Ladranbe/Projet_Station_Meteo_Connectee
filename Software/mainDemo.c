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
#pragma config ADCSEL= BIT10 // ADC sur 10 bits.
#pragma config RTCOSC = INTOSCREF	//RTCC uses INTRC as the reference clock

/** I N C L U D E S **************************************************/
#include <p18f47j13.h>
#include <delays.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <spi.h>
#include <adc.h>
#include "ADCConfig.h"
#include "declaration.h"
#include "temperature.h"
#include "SPIConfig.h"
#include "humidite.h"
#include "rtcc.h"

/** D E C L A R A T I O N S ******************************************/
unsigned char instruction1[4];
unsigned char instruction[3];
unsigned char MAC[6]; 
unsigned char SIGNATURE[1];
UINT32 temperature=0;
UINT32 hum=0;
int portADC=0;
//Déclaration variable pour test RTCC
int sec=0;
int min=0;
int hour=0;
int wday=0;
int mday=0;
int mon=0;
int year=0;
void main (void)
{
/**************************** Test SPI *******************************/
// Initialisation + Ecriture EEPROM 25LC1024
/*	initialiserSPI();
 	while(1){
		WriteEEPROM();
	}
*/
//Initialisation + Lecture EEPROM 25LC1024
/*	initialiserSPI();
	instruction1[0]=0xAB;
	instruction1[1]=0xFF;
	instruction1[2]=0xFF;
	instruction1[3]=0xFF;
	while(1){
		LATAbits.LATA6 =0;
		putsSPI1(instruction1); //Envoie instruction
		getsSPI1(SIGNATURE,8); //Récupération adresse signature électronique
		LATAbits.LATA6=1;
		}
/*

// Initialisation + Ecriture EEPROM 25AA02E48
/*	initialiserSPI();
 	while(1){
		WriteEEPROMAC();
	}
*/
// Initialisation + Lecture adresse MAC EEPROM 25AA02E48
	/*initialiserSPI();
	instruction[0]=0x03;
	instruction[1]=0xFA;
	instruction[2]=0x00;

		while(1){
		LATAbits.LATA7 =0;
		putsSPI1(instruction); //Envoie instruction
		getsSPI1(MAC,6);	//Récupération adresse MAC
		LATAbits.LATA7=1;
		Delay10TCYx(1);
		}*/

// Test écriture dans l'ENC25J60 
/*	initialiserSPI();
 	while(1){
		WriteENC();
	}
*/

/**************************** Test Capteurs *******************************/
	initialiserADC(); 			//Initialisation ADC
	SetChanADC(ADC_CH1);		//Choix port ADC
	portADC=1;				
	while(1){
		portADC=1;
		temperature=lireTemp();	//Récupération de la mesure de température
		if(portADC==1){
			SetChanADC(ADC_CH2); //Changement port ADC
			hum=lireHumidite(); //Récupération du taux d'humidité
			portADC=2;		
			SetChanADC(ADC_CH1); //On rechange le port ADC
		}
	} 

/**************************** Test RTCC *******************************/
/*
	sec=0; 
	min=36;
	hour=20;
	wday=2;
	mday=30;
	mon=5;
	year=16;
	initialiser_rtcc(sec,min,hour,wday,mday,mon,year);
	do {
		lancer_rtcc();
	}while(1);
*/

}