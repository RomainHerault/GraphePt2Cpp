#pragma once
#ifndef CARC_H
#define CARC_H

#include"CSommet.h"
class CSommet;

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
	* Le parametre SOMARCDestination est correctement initialis�
	*
	*/
	CArc();

	/**
	* \brief Constructeur � 1 param�tre
	*
	* Initialise la variable SOMARCDestination avec la param�tre SOMSommet
	*
	* E:
	* \param SOMSommet CSommet : Valeur � laquelle SOMARCDestination est initialis�e
	*
	*/
	CArc(CSommet * SOMSommet);

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
	* \param ARCParam CArc : Objet contenant les valeurs � recopier
	* 
	*/
	void operator=(CArc & ARCParam);

	/**
	* \brief Affecter un CSommet a la variable SOMARCDestination
	*
	* E:
	* \param SOMSommet CSommet : Objet de la classe CSommet vers lequel notre instance classe se dirige
	*
	*Entra�ne : (Remplace la destination de l'arc par le sommet plac� en param�tre)
	*/
	void ARCAffecterDest(CSommet * pSOMSommet);

	/**
	* \brief envoie la valeur du param�tre SOMARCDestination
	*
	* S:
	* \return CSommet : Sommet vers lequel l'arc se dirige
	*/
	CSommet * ARCLiredest();
};

#endif
