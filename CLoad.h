#pragma once

#include "CGraphe.h"

class CLoad
{

private : 
	CGraphe pGRALODGraphe;
	string sLODNomFichier;

public:
	/** Ajoute le fichier 
	*E:
	* 
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le nom du fichier est stocké dans la variable de la classe)
	*/
	void static LODAjouterFichier(string psNomFichier);

	/** Lit le fichier et le converti en graphe
	*E:
	* 
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le graphe correspondant au contenu du fichier est créé)
	*/
	CGraphe static LODParser();
};

