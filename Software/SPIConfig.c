/**
 * \file SPIConfig.c
 * \brief en-tete du module SPIConfig.
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module SPIConfig *******
 *
 */
 #include "SPIConfig.h"
 
/**** fonction initialiserSPI ****
* \fn void initialiserSPI(void)
* fonction d'initialisation des ports impliqués dans la liasion SPI.
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
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

/**** fonction WriteENC(void)
* fonction permettant d'écrire une donnée dans l'ENC28J60
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
void WriteENC(void){
		while(SSP1STATbits.BF==0){			
			SSPBUF=0xAF; //écriture de la donnée 0xAF;
			LATEbits.LATE0= 0; // Désactivation du CS
		}
}

/**** fonction WriteEEPROM(void)
* fonction permettant d'écrire une donnée dans l'EEPROM 25LC1024 
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
void WriteEEPROM(void){
	while(SSP1STATbits.BF==0){
			SSPBUF=0xAF;
			LATAbits.LATA6 = 0;
	}
}

/**** fonction WriteEEPROMAC(void)
* fonction permettant d'écrire une donnée dans l'EEPROM 25AA02E48
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
void WriteEEPROMAC(void){
	while(SSP1STATbits.BF==0){
			SSPBUF=0xAF;
			LATAbits.LATA7 = 0;
	}
}		