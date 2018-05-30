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
	/**Constructor par défaut
	*E:
	*
	*Necessite :
	*
	*S:
	*
	*Entraine : (L'objet est correctement initialisé)
	*/
	CGraphe();

	/** Constructeur de recopie
	*E:
	* GRAParam Cgraphe le graphe que l'on veut recopier
	*Necessite :
	*
	*S:
	*
	*Entraine : (L'objet est correctement initialisé comme une copie du paramètre)
	*/
	CGraphe(const CGraphe & GRAParam);

	/**
	*E:Destructeur par défaut
	*
	*Necessite :
	*
	*S:
	*
	*Entraine :(L'objet est correctement détruit)
	*/
	~CGraphe();

	/** Surcharge de l'opérateur =
	*E:
	* GRAParam CGraphe le graphe que l'on copier
	*Necessite :
	*
	*S:
	*
	*Entraine :(L'objet devient une copie du paramètre)
	*/
	void operator=(CGraphe & GRAParam);

	/** Ajoute un sommet au graphe
	*E:
	*SOMSommet CSommet le sommet à ajouter
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le sommet est ajouté au graphe)
	*/
	void GRAAffecterSom(CSommet * SOMSommet);

	/** Permet de récupérer les sommet du graphe
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
	*Entraine :(Le graphe est affiché)
	*/
	void GRAAfficher();


	CSommet * GRATrouverParNum(unsigned int uiNum);


	vector<unsigned int> GRADijkstra(CSommet * SOMSommet);
};

#endif 