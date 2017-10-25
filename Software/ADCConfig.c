/**
 * \file adc.c
 * \brief en-tete du module adc.
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module adc *******
 *
 */
 
 #include "ADCConfig.h"
/**** fonction initialiserADC ****
* \fn void initialiserADC(void)
* fonction d'initialisation du convertisseur analogique numerique pour 
* l'acquisition d'un signal provenant de la broche AN0 (pin 19). La tension a  
* acquerir varie entre GND et Vdd. Le resultat sera aligne a droite.
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
void initialiserADC(){
	//	1. Configure Port:
	//		• Disable pin output driver
	PORTAbits.RA1 = 0;
	LATAbits.LATA1 = 0;
	TRISAbits.TRISA1 = 1;
	PORTAbits.RA2 = 0;
	LATAbits.LATA2 = 0;
	TRISAbits.TRISA2 = 1;

	//		• Configure pin as analog
	ANCON0bits.PCFG1 = 0;
	ANCON0bits.PCFG2 = 0;

	//	2. Configure the ADC module:
//	ADCON0 = 0x0D;
//	ADCON1 = 0xB6;

	//		• Select ADC conversion clock (Fosc/64)
	ADCON1bits.ADCS = 6;

	//		• Configure voltage reference (internal VDD & VSS)
	ADCON0bits.VCFG0 = 0; //Vss
	ADCON0bits.VCFG1 = 0; //Vdd

	//		• Select ADC input channel (CH3)
//	ADCON0bits.CHS = 1;

	//		• Select result format, ici on prendra un alignement a droite
	ADCON1bits.ADFM = 1;

	//		• Select acquisition delay (2 TAD)
	ADCON1bits.ACQT = 6; //16TAD sur combien de temps on fait l'acquisition

	//		• Turn on ADC module
 	ADCON0bits.ADON = 1;
	
	//	3. interruption, nous ne nous en servirons pas
	PIE1bits.ADIE = 0;

		
}

/**** fonction lireADC ****
* \fn UINT16 lireADC(void)
* fonction de lecture 'initialisation du convertisseur analogique numerique pour 
* l'acquisition d'un signal provenant de la broche AN0. La tension a  
* acquerir varie entre GND et Vdd. Le resultat sera aligne a droite.
* Pas de temps d'attente avant l'acquisition du signal
* \param[in] rien
* \return  UINT16 valeur sur 16 bit, resultat de la conversion analogique numerique
* @pre-condition : aucune
********************************/
UINT16 lireADC(){
	UINT16 res;    
	// Debut de la conversion en mettant GO\DONE à 1
	ADCON0bits.GO_DONE = 1; 
	//Attente en regardant la valeur du bit GO_DONE. Si elle passe a 0, 
	//c'est que l'acquisition est terminee et donc que l'on peut lire le resultat de conversion
	while(ADCON0bits.GO_DONE ==1){
	}
	res=ADRES; //L'acquisition est finie -- Lecture du resultat
	return res;	
}
