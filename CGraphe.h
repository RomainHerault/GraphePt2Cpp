#pragma once
#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <vector>
#include "CSommet.h"
#include "CExceptions.h"
#include <string>

using namespace std;

class CGraphe
{

private:

	vector<CSommet> * pvSOMGRASommet;

public:
	/**Constructor par d�faut
	*E:
	*
	*Necessite :
	*
	*S:
	*
	*Entraine : (L'objet est correctement initialis�)
	*/
	CGraphe();

	/** Constructeur de recopie
	*E:
	* GRAParam Cgraphe le graphe que l'on veut recopier
	*Necessite :
	*
	*S:
	*
	*Entraine : (L'objet est correctement initialis� comme une copie du param�tre)
	*/
	CGraphe(const CGraphe & GRAParam);

	/**
	*E:Destructeur par d�faut
	*
	*Necessite :
	*
	*S:
	*
	*Entraine :(L'objet est correctement d�truit)
	*/
	~CGraphe();

	/** Surcharge de l'op�rateur =
	*E:
	* GRAParam CGraphe le graphe que l'on copier
	*Necessite :
	*
	*S:
	*
	*Entraine :(L'objet devient une copie du param�tre)
	*/
	void operator=(CGraphe & GRAParam);

	/** Ajoute un sommet au graphe
	*E:
	*SOMSommet CSommet le sommet � ajouter
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le sommet est ajout� au graphe)
	*/
	void GRAAffecterSom(CSommet * SOMSommet);

	/** Permet de r�cup�rer les sommet du graphe
	*E:
	*
	*Necessite :
	*
	*S:
	* vector<CSommet> une vecteur contenant tous les sommets du graphe
	*Entraine :(Retourne un vecteur contenant les sommets du graphe)
	*/
	vector<CSommet> * GRALireSommets();

	/** Afficher le graphe
	*E:
	*
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le graphe est affich�)
	*/
	void GRAAfficher();


	CSommet * GRATrouverParNum(unsigned int uiNum);


	vector<unsigned int> GRADijkstra(CSommet * SOMSommet);
};

#endif 