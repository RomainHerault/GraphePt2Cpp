#include <vector>

#include "CSommet.h"

using namespace std;


/**
* \ brief Constructeur par defaut
*
*Entra�ne :(Les parametres uiSOMNumero, uiSOMNumero, vARCSOMPartant sont correctements initialis�s)
*
*/
CSommet::CSommet()
{
	
	uiSOMNumero = 0;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

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
CSommet::CSommet(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

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
CSommet::CSommet(const CSommet & SOMParam)
{
	
	uiSOMNumero = SOMParam.uiSOMNumero;
	vARCSOMArrivant = new vector<CArc>(*(SOMParam.vARCSOMArrivant));
	vARCSOMPartant = new vector<CArc>(*(SOMParam.vARCSOMPartant));
}


/**
* \brief Destructeur
*
* Entra�ne : (Detruit correctement l'objet actuel)
*
*/
CSommet::~CSommet()
{
	delete vARCSOMArrivant;
	delete vARCSOMPartant;
}

/**
* \brief Surcharge de l'Op�rateur d'affectation
*
* E:
* \param SOMParam CSommet : Objet contenent les valeurs � recopier
*
*/
void CSommet::operator=( CSommet  * SOMParam)
{
	
	uiSOMNumero = SOMParam->uiSOMNumero;
	vARCSOMArrivant = SOMParam->vARCSOMArrivant;
	vARCSOMPartant = SOMParam->vARCSOMPartant;

}

/**
* \brief Renvoie l'id du sommet
*
* S:
* \return int :la valeur de uiNumero
*
*/
int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}

/**
* \brief Ajoute un arc arrivant au sommet
*
* E:
* \param ARCArc CArc : Arc a ajouter dans la liste des arcs arrivants au sommet
*
*Entra�ne : (Le vecteur des arcs arrivants contient en plus l'arc en param�tre)
*/
void CSommet::SOMAffecterArcArrivant(CArc * ARCArc)
{
	vARCSOMArrivant->push_back(*ARCArc);
	
}

/**
* \brief Supprime un des arcs arrivant du sommet
*
* E:
* \param ARCArc CArc : Arc � supprimer de la liste des arcs arrivants au sommet
*
*Entra�ne : (Le vecteur des arcs arrivants ne contient plus l'arc en param�tre)
*/
void CSommet::SOMSupprimerArcArrivant(CArc * ARCArc)
{
	unsigned int uiCompteur = 0;
	while (uiCompteur < vARCSOMArrivant->size() && &vARCSOMArrivant->at(uiCompteur) != ARCArc)
		uiCompteur++;
	vARCSOMArrivant->erase(vARCSOMArrivant->begin() + uiCompteur);
}

/**
* \brief retourne la liste des arcs arrivants
*
* S:
* \return vector<CArc> : Liste des arcs arrivants au sommet
*
*/
vector<CArc> * CSommet::SOMLireArcArrivant()
{
	return vARCSOMArrivant;
}

/**
* \brief Ajoute un arc partant au sommet
*
* E:
* \param ARCArc CArc : Arc a ajouter dans la liste des arcs partants du sommet
*
*Entra�ne : (Le vecteur des arcs partants contient en plus l'arc en param�tre)
*/
void CSommet::SOMAffecterArcPartant(CArc * ARCArc)
{
	vARCSOMPartant->push_back(*ARCArc);
}

/**
* \brief Supprime un des arcs partant du sommet
*
* E:
* \param ARCArc CArc : Arc � supprimer de la liste des arcs partants du sommet
*
*Entra�ne : (Le vecteur des arcs partants ne contient plus l'arc en param�tre)
*/
void CSommet::SOMSupprimerArcPartant(CArc * ARCArc)
{
	unsigned int uiCompteur = 0;
	while (uiCompteur < vARCSOMPartant->size() && &vARCSOMPartant->at(uiCompteur) != ARCArc)
		uiCompteur++;
	vARCSOMPartant->erase(vARCSOMPartant->begin() + uiCompteur);
}

/**
* \brief envoie la liste des arcs partants
*
* S:
* \return vector<CArc> : Liste des arcs partants du sommet
*
*/
vector<CArc> * CSommet::SOMLireArcPartant()
{
	return  vARCSOMPartant;
}