	/**
 * \file RTCCConfig.c
 * \brief en-tete du module RTCCConfig.
 * \author B.LADRANGE && A.RANDOLPH
 * \version 0.1
 * \date 29/04/2016
 *
 * * C O R P S   module RTCCConfig*******
 *
 */

#include <rtcc.h>

rtccTimeDate depart;
rtccTime time;
rtccDate date;
/*int sec=0;
int min=0;
int hour=0;
int wday=0;
int mday=0;
int mon=0;
int year=0;*/

/*An attempt to write to the RTCEN bit while
RTCWREN = 0 will be ignored. RTCWREN must be
set before a write to RTCEN can take place.*/

/**** fonction initialiserRTCC ****
* \fn void initialiser_rtcc(void)
* Fonction qui permet d'intialiser la rtcc
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
void initialiser_rtcc(unsigned char sec, unsigned char min, unsigned char hour, unsigned char wday, unsigned char mday, unsigned char mon, unsigned char year){
	depart.f.year=year;
	depart.f.mday=mday;
	depart.f.mon=mon;
	depart.f.hour=hour;
	depart.f.wday=wday;
	depart.f.sec=sec;
	depart.f.min=min;
	RtccInitClock();    // Initialisation de la RTCC        
	RtccWrOn();         // Activation du bit WREN (Write Enable) permettant de pouvoir fixer la valeur de RTCEN plus loin (enable RTCC)         
	RtccWriteTimeDate(&depart,0);	//On fixe une date, heure, min et sec de départ à partir desquels la RTCC s'incrémentera
	mRtccOn();          // Activation de la RTCC         
	mRtccWrOff();       // On désactive le bit WREN         
 
	//RTCC source clock is selected for the RTCC pin (pin can be INTRC or T1OSC, depending on the RTCOSC (CONFIG3L<1>) setting)         
	
	PADCFG1bits.RTSECSEL1 = 1;         
	PADCFG1bits.RTSECSEL0 = 0;       
}

/**** fonction lancer_rtcc ****
* \fn void lire_rtcc(void)
* Stockage  des variables de la RTCC dans deux variables temps et date
* \param[in] rien
* \return rien
* @pre-condition : aucune
********************************/
 void lancer_rtcc(void){       
	RtccReadTime(&time);	//Lecture du temps placé dans la variable "time"
	RtccReadDate(&date);	//Lecture de la date placée dans la variable "date"
}