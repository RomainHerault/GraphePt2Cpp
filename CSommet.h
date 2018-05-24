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
	*Entra�ne :(Les parametres uiSOMNumero, uiSOMNumero, vARCSOMPartant sont correctements initialis�s)
	*
	*/
	CSommet();

	/**
	* \brief Constructeur � 1 param�tre
	*
	* Initialise la varibale uiNumero avec le param�tre uiNumero
	*
	* E:
	* \param uiNumero unsigned int : Valeur � laquelle uiNumero est initialis�e
	*
	*Entra�ne : (CSommet correctement initialis�)
	*/
	CSommet(unsigned int uiNumero);

	/**
	* \brief Constructeur de recopie
	*
	* Permet de recopier l'objet pass� en param�tre directement � l'objet actuel
	*
	* E:
	* \param SOMParam CSommet : Object contenant les valeurs � recopier
	*
	*Entra^ne : (CSommet initialis� comme �tant une copie de SOMParam)
	*/
	CSommet(const CSommet & SOMParam);

	/**
	* \brief Destructeur
	*
	* Entra�ne : (Detruit correctement l'objet actuel)
	*
	*/
	~CSommet();

	/**
	* \brief Surcharge de l'Op�rateur d'affectation
	*
	* E:
	* \param SOMParam CSommet : Objet contenent les valeurs � recopier
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
	*Entra�ne : (Le vecteur des arcs arrivants contient en plus l'arc en param�tre)
	*/
	void SOMAffecterArcArrivant(CArc * ARCArc);

	/**
	* \brief Supprime un des arcs arrivant du sommet
	*
	* E:
	* \param ARCArc CArc : Arc � supprimer de la liste des arcs arrivants au sommet
	*
	*Entra�ne : (Le vecteur des arcs arrivants ne contient plus l'arc en param�tre)
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
	*Entra�ne : (Le vecteur des arcs partants contient en plus l'arc en param�tre)
	*/
	void SOMAffecterArcPartant(CArc * ARCArc);

	/**
	* \brief Supprime un des arcs partant du sommet
	*
	* E:
	* \param ARCArc CArc : Arc � supprimer de la liste des arcs partants du sommet
	*
	*Entra�ne : (Le vecteur des arcs partants ne contient plus l'arc en param�tre)
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