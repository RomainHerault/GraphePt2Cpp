#pragma once
#ifndef C_LOAD_H
#define C_LOAD_H
#include "CGraphe.h"
#include "CExceptions.h"
#include <string>
#include <iostream>
#include <assert.h>
#include <fstream>


class CLoad
{

private:

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
	CLoad(string psNomFichier);

	/** Lit le fichier et le converti en graphe
	*E:
	*
	*Necessite :
	*
	*S:
	*
	*Entraine :(Le graphe correspondant au contenu du fichier est créé)
	*/
	CGraphe  * LODParser();
};
#endif
