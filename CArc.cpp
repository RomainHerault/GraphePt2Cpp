
#include "CArc.h"


/**
* \brief Constructeur par defaut
*
* Le parametre SOMARCDestination est correctement initialisé
*
*/
CArc::CArc()
{
	pSOMARCDestination = 0;
}

/**
* \brief Constructeur à 1 paramètre
*
* Initialise la variable SOMARCDestination avec la paramètre SOMSommet
*
* E:
* \param SOMSommet CSommet : Valeur à laquelle SOMARCDestination est initialisée
*
*/
CArc::CArc(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

/**
* \brief Constructeur de recopie
*
* Permet de recopier la valeur SOMARCDestinationd e l'objet passé en paramètre directement
* dans this.SOMARCDestination
*
* E:
* \param ARCParam CArc : Objet contenant les valeurs à recopier
*
*/
CArc::CArc(const CArc & ARCParam)
{
	pSOMARCDestination = ARCParam.pSOMARCDestination;
}

/**
* \brief Destructeur
*
* Detruit correctement la variable SOMARCDestination de la classe
*
*/
CArc::~CArc()
{
	pSOMARCDestination = 0;	
}

/**
* \brief Operateur d'affectation
*
* E:
* \param ARCParam CArc : Objet contenant les valeurs à recopier
*
*/
void CArc::operator=(CArc & ARCParam)
{
	pSOMARCDestination = ARCParam.ARCLiredest();


}

/**
* \brief Affecter un CSommet a la variable SOMARCDestination
*
* E:
* \param SOMSommet CSommet : Objet de la classe CSommet vers lequel notre instance classe se dirige
*
*Entraîne : (Remplace la destination de l'arc par le sommet placé en paramètre)
*/
void CArc::ARCAffecterDest(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

/**
* \brief envoie la valeur du paramètre SOMARCDestination
*
* S:
* \return CSommet : Sommet vers lequel l'arc se dirige
*/
CSommet * CArc::ARCLiredest()
{
	return pSOMARCDestination;
}