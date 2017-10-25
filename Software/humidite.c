/**
 * \file humidite.c
 * \brief en-tete du module humidite.
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module humidite *******
 *
 */
 #include "ADCConfig.h"
 #include "humidite.h"
 #include "math.h"

/**** fonction lireHumidite ****
* \fn void lireTemp(void)
* Fonction qui permet de récuperer la valeur du taux d'humidité
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/

UINT32 lireHumidite(){
	UINT32 resultAdc=0;
	UINT32 tensionH=0;
	UINT32 hum=0;
	resultAdc = lireADC();// Récupération de la valeur de l'ADC	
	tensionH=(resultAdc*1988)/1023; //Conversion de la valeur de l'ADC en tension
	hum=(tensionH-(8/1000))/(31); // Calcul taux d'humidité
	return hum;
}