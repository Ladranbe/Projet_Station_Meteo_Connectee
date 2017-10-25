/**
 * \file temperature.c
 * \brief en-tete du module temperature
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module temperature *******
 *
 */
 #include "ADCConfig.h"
 #include "temperature.h"
 #include "math.h"

/**** fonction lireTemp ****
* \fn void lireTemp(void)
* Fonction qui permet de récuperer la valeur de la température ambiante
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
 UINT32 lireTemp(){
	UINT32 resultatAdc=0;
	UINT32 tensionT=0;
	UINT32 temp=0;
	resultatAdc = lireADC();// Récupération de la valeur de l'ADC	
	tensionT=(resultatAdc*3300)/1024; //Conversion de la valeur de l'ADC en tension
	temp=(tensionT-250)/28 ; // Calcul de la température
	return temp;
}
