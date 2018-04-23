#pragma once
#include "CSommet.h"

/**
	* \brief contient le sommet vers lequel l'arc se dirige
	*
*/
class CArc
{
private:
	CSommet * pSOMARCDestination;
public:
	/**
		* \brief Constructeur par defaut
		*
		* Le parametre SOMARCDestination est correctement initialisé
		*
	*/
	CArc();

	/**
		* \brief Constructeur à 1 paramètre 
		*
		* Initialise la variable SOMARCDestination avec la paramètre SOMSommet
		*
		* E:
		* \param SOMSommet CSommet : Valeur à laquelle SOMARCDestination est initialiser
		*
	*/
	CArc(CSommet * SOMSommet);

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
	CArc(const CArc & ARCParam);

	/**
		* \brief Destructeur
		* 
		* Detruit correctement la variable SOMARCDestination de la classe
		*
	*/
	~CArc();

	/**
		* \brief Operateur d'affectation
		*
		* E:
		* \param ARCParam CArc : Objet contenant les valeurs à recopier
		* \return CArc : 
	*/
	CArc & operator=(const CArc & ARCParam);

	/**
		* \brief Affecter un CSommet a la variable SOMARCDestination
		*
		* E:
		* \param SOMSommet CSommet : Objet de la classe CSommet vers lequel notre instance classe se dirige
		*
	*/
	void ARCAffecterDest(CSommet * pSOMSommet);

	/**
		* \brief envoie la valeur du paramètre SOMARCDestination
		* 
		* S:
		* \return CSommet : Sommet vers lequel l'arc se dirige
	*/
	CSommet * ARCLiredest();
};

