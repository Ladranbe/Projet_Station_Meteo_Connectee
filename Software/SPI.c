/**
 * \file spi.c	
 * \brief en-tete du module spi.
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module spi *******
 *
 */
 #include <spi.h>
 
 void initialiserSPI(){
	TRISCbits.TRISC3=0; //SCK en sortie
	LATCbits.LATC3=0; //SCLK1 : SPI clock input
	TRISCbits.TRISC4=1; //SO //
	TRISCbits.TRISC5=0; //SI
	//Selection CS
	TRISAbits.TRISA6=0; //CS_EEPROM25LC
	LATAbits.LATA6 = 1; //CS_EEPROM25
	TRISAbits.TRISA7=0; // CS_EEPROM25AA
	LATAbits.LATA7=1;
	TRISEbits.TRISE0=0;//CS_ENC
	LATEbits.LATE0=1;
//	SSP1STAT |=0xC0;
//	SSP1CON1 |=0x31;
	OpenSPI1(SPI_FOSC_16,MODE_00,SMPMID);
 }
