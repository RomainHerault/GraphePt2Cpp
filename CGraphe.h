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

	/** Renvoie un sommet a partir d'un ID donné en paramètre
	*E:
	* unsigned int uiNum : ID du sommet a trouver et renvoyer
	*Necessite :
	*
	*S:
	* CSommet : Sommet correspondant à l'ID donné en paramètre
	*Entraine :
	*/
	CSommet * GRATrouverParNum(unsigned int uiNum);

	/**
	*Classe représentant un couple d'un arc et d'une longueur
	*Permet de remplir la file de priorité pour l'algorithme de Dijkstra
	*/
	class CoupleArcLg {
	public:
		CArc * ARCArc;
		unsigned int uiLongueur = 0;

	public:
		CoupleArcLg(CArc * arc, unsigned int uiLg) {
			ARCArc = arc;
			uiLongueur = uiLg;
		}
	};

	/** Algorithme de Dijkstra
	*E:
	*SOMSommet CSommet le sommet duquel on veut partir pour effectuer Dijkstra
	*Necessite :
	*
	*S:
	* unsigned int * : Tableau de naturels où t[i] est la distance minimale pour aller du sommet de départ jusqu'au sommet i
	*/
	unsigned int * GRADijkstra(CSommet * SOMSommet);

	/** Trouve le sommet de départ d'un arc
	*E:
	* CArc * ARCArc : l'arc auquel on veut trouver son sommet de départ
	*
	*Necessite :
	*
	*S:
	*CSommet * : le sommet de départ de l'arc ARCArc
	*Entraine :
	*/
	CSommet * GRATrouveSomDep(CArc * ARCArc);

	/** Extrait le couple de longueur minimale de vFile
	*E:
	* vector<CoupleArcLg> * vFile : la file de l'algorithme de Dijkstra
	*
	*Necessite :
	*vFile contient au moins un CoupleArcLg
	*S:
	*CoupleArcLg * : le couple de longueur minimale dans vFile
	*Entraine :(Retrait du couple de longueur minimale dans vFile et on retourne celui-ci)
	*/
	CoupleArcLg * GRAExtraireMin(vector<CoupleArcLg> * vFile);

	/** Supprime un CoupleArcLg d'un vetceur
	*E:
	* vector<CoupleArcLg> * vFile : la file de l'algorithme de Dijkstra
	*CoupleArcLg * cal : l'element a supprimer
	*Necessite :
	*
	*S:
	*
	*Entraine :(Supppression de CALcal dans VFile)
	*/
	void GRARemoveElement(vector<CoupleArcLg> * vFile, CoupleArcLg * cal);

	/** Ajoute un nouveau couple CoupleArcLg dans vFile
	*E:
	* vector<CoupleArcLg> * vFile : la file de l'algorithme de Dijkstra
	* CArc * ARCArc : l'arc que l'on veut ajouter
	* unsigned int uiLongueur : la longueur totale pour aller jusqu'à cet arc
	*
	*Necessite :
	*
	*S:
	*
	*Entraine :(Ajout du couple CoupleArcLg conteant ARCArc et uiLongueur dans vFile) OU (Actualisation de le longueur du couple
	*CoupleArcLg si il en existe déjà un contenant ARCArc dans vFile)
	*/
	void GRAInserer(std::vector<CoupleArcLg> * vFile, CArc * ARCArc, unsigned int uiLongueur);
};

#endif 