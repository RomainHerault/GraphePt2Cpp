#include <vector>

#include "CSommet.h"

using namespace std;


/**
* \ brief Constructeur par defaut
*
*Entraîne :(Les parametres uiSOMNumero, uiSOMNumero, vARCSOMPartant sont correctements initialisés)
*
*/
CSommet::CSommet()
{
	
	uiSOMNumero = 0;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

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
CSommet::CSommet(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

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
CSommet::CSommet(const CSommet & SOMParam)
{
	
	uiSOMNumero = SOMParam.uiSOMNumero;
	vARCSOMArrivant = new vector<CArc>(*(SOMParam.vARCSOMArrivant));
	vARCSOMPartant = new vector<CArc>(*(SOMParam.vARCSOMPartant));
}


/**
* \brief Destructeur
*
* Entraîne : (Detruit correctement l'objet actuel)
*
*/
CSommet::~CSommet()
{
	delete vARCSOMArrivant;
	delete vARCSOMPartant;
}

/**
* \brief Surcharge de l'Opérateur d'affectation
*
* E:
* \param SOMParam CSommet : Objet contenent les valeurs à recopier
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
*Entraîne : (Le vecteur des arcs arrivants contient en plus l'arc en paramètre)
*/
void CSommet::SOMAffecterArcArrivant(CArc * ARCArc)
{
	vARCSOMArrivant->push_back(*ARCArc);
	
}

/**
* \brief Supprime un des arcs arrivant du sommet
*
* E:
* \param ARCArc CArc : Arc à supprimer de la liste des arcs arrivants au sommet
*
*Entraîne : (Le vecteur des arcs arrivants ne contient plus l'arc en paramètre)
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
*Entraîne : (Le vecteur des arcs partants contient en plus l'arc en paramètre)
*/
void CSommet::SOMAffecterArcPartant(CArc * ARCArc)
{
	vARCSOMPartant->push_back(*ARCArc);
}

/**
* \brief Supprime un des arcs partant du sommet
*
* E:
* \param ARCArc CArc : Arc à supprimer de la liste des arcs partants du sommet
*
*Entraîne : (Le vecteur des arcs partants ne contient plus l'arc en paramètre)
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