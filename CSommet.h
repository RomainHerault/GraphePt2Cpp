#pragma once

#ifndef CSOMMET_H
#define CSOMMET_H
#include <vector>
#include "CArc.h"

class CArc;
using namespace std;

class CSommet
{
private:
	unsigned int uiSOMNumero;
	vector<CArc> * vARCSOMArrivant;
	vector<CArc> * vARCSOMPartant;
public:
	/**
	* \ brief Constructeur par defaut
	*
	*Entraîne :(Les parametres uiSOMNumero, uiSOMNumero, vARCSOMPartant sont correctements initialisés)
	*
	*/
	CSommet();

	/**
	* \brief Constructeur à 1 paramètre
	*
	* Initialise la varibale uiNumero avec le paramètre uiNumero
	*
	* E:
	* \param uiNumero unsigned int : Valeur à laquelle uiNumero est initialisée
	*
	*Entraîne : (CSommet correctement initialisé)
	*/
	CSommet(unsigned int uiNumero);

	/**
	* \brief Constructeur de recopie
	*
	* Permet de recopier l'objet passé en paramètre directement à l'objet actuel
	*
	* E:
	* \param SOMParam CSommet : Object contenant les valeurs à recopier
	*
	*Entra^ne : (CSommet initialisé comme étant une copie de SOMParam)
	*/
	CSommet(const CSommet & SOMParam);

	/**
	* \brief Destructeur
	*
	* Entraîne : (Detruit correctement l'objet actuel)
	*
	*/
	~CSommet();

	/**
	* \brief Surcharge de l'Opérateur d'affectation
	*
	* E:
	* \param SOMParam CSommet : Objet contenent les valeurs à recopier
	*
	*/
	void operator=(CSommet * SOMParam);

	/**
	* \brief Renvoie l'id du sommet
	*
	* S:
	* \return int :la valeur de uiNumero
	*
	*/
	int SOMLireNumero();

	/**
	* \brief Ajoute un arc arrivant au sommet
	*
	* E:
	* \param ARCArc CArc : Arc a ajouter dans la liste des arcs arrivants au sommet
	*
	*Entraîne : (Le vecteur des arcs arrivants contient en plus l'arc en paramètre)
	*/
	void SOMAffecterArcArrivant(CArc * ARCArc);

	/**
	* \brief Supprime un des arcs arrivant du sommet
	*
	* E:
	* \param ARCArc CArc : Arc à supprimer de la liste des arcs arrivants au sommet
	*
	*Entraîne : (Le vecteur des arcs arrivants ne contient plus l'arc en paramètre)
	*/
	void SOMSupprimerArcArrivant(CArc * ARCArc);

	/**
	* \brief retourne la liste des arcs arrivants
	*
	* S:
	* \return vector<CArc> : Liste des arcs arrivants au sommet
	*
	*/
	vector<CArc> * SOMLireArcArrivant();

	/**
	* \brief Ajoute un arc partant au sommet
	*
	* E:
	* \param ARCArc CArc : Arc a ajouter dans la liste des arcs partants du sommet
	*
	*Entraîne : (Le vecteur des arcs partants contient en plus l'arc en paramètre)
	*/
	void SOMAffecterArcPartant(CArc * ARCArc);

	/**
	* \brief Supprime un des arcs partant du sommet
	*
	* E:
	* \param ARCArc CArc : Arc à supprimer de la liste des arcs partants du sommet
	*
	*Entraîne : (Le vecteur des arcs partants ne contient plus l'arc en paramètre)
	*/
	void SOMSupprimerArcPartant(CArc * ARCArc);

	/**
	* \brief envoie la liste des arcs partants
	*
	* S:
	* \return vector<CArc> : Liste des arcs partants du sommet
	*
	*/
	vector<CArc> * SOMLireArcPartant();
};


#endif