
#include "CArc.h"


/**
* \brief Constructeur par defaut
*
* Le parametre SOMARCDestination est correctement initialis�
*
*/
CArc::CArc()
{
	pSOMARCDestination = 0;
}

/**
* \brief Constructeur � 1 param�tre
*
* Initialise la variable SOMARCDestination avec la param�tre SOMSommet
*
* E:
* \param SOMSommet CSommet : Valeur � laquelle SOMARCDestination est initialis�e
*
*/
CArc::CArc(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

/**
* \brief Constructeur de recopie
*
* Permet de recopier la valeur SOMARCDestinationd e l'objet pass� en param�tre directement
* dans this.SOMARCDestination
*
* E:
* \param ARCParam CArc : Objet contenant les valeurs � recopier
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
* \param ARCParam CArc : Objet contenant les valeurs � recopier
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
*Entra�ne : (Remplace la destination de l'arc par le sommet plac� en param�tre)
*/
void CArc::ARCAffecterDest(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

/**
* \brief envoie la valeur du param�tre SOMARCDestination
*
* S:
* \return CSommet : Sommet vers lequel l'arc se dirige
*/
CSommet * CArc::ARCLiredest()
{
	return pSOMARCDestination;
}