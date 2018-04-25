
#include "CLoad.h"


/** Ajoute le fichier
*E:
*
*Necessite :
*
*S:
*
*Entraine :(Le nom du fichier est stocké dans la variable de la classe)
*/
void CLoad::LODAjouterFichier(string psNomFichier)
{
	sLODNomFichier = psNomFichier;
}

/** Lit le fichier et le converti en graphe
*E:
*
*Necessite :
*
*S:
*
*Entraine :(Le graphe correspondant au contenu du fichier est créé)
*/
CGraphe * CLoad::LODParser()
{
	string sData("");
	CGraphe * pGRAgraphe = new CGraphe();

	
	ifstream infile;
	infile.open(sLODNomFichier.c_str());
	infile >> sData;

		
		
	unsigned int uiNbSom = atoi(sData.substr(10, 100).c_str());
	infile >> sData;
	unsigned int uiNbArcs = atoi(sData.substr(7, 100).c_str());
	infile >> sData;

	//lecture des sommets
	if (sData.compare(0, 100, "Sommets=[") == 0)
	{
		for (int uiSom = 0; uiSom < uiNbSom; uiSom++)
		{
			infile >> sData;
			unsigned int uiNumSom = atoi(sData.c_str());
			pGRAgraphe->GRAAffecterSom(new CSommet(uiNumSom));
		}
	}
	else
		throw new CExceptions(BAD_INPUT);

	infile >> sData;
	//lecture des arcs
	if (sData.compare(0, 100, "Arcs=[") == 0)
	{
		CSommet * pSOMDest = 0;
		CSommet * pSOMDep = 0;
		for (int uiArc = 0; uiArc < uiNbArcs; uiArc++)
		{
			infile >> sData;
			unsigned int uiSomDep = atoi(sData.c_str());
					

			infile >> sData;
			unsigned int uiSomArr = atoi(sData.c_str());
			
			for each (CSommet SOMSom in pGRAgraphe->GRALireSommets())
			{
				if (SOMSom.SOMLireNumero() == uiSomArr)
					pSOMDest = &SOMSom;
				else
					throw new CExceptions(OBJECT_DOESNT_EXIST);

				if (SOMSom.SOMLireNumero() == uiSomDep)
					pSOMDep = &SOMSom;
				else
					throw new CExceptions(OBJECT_DOESNT_EXIST);
			}
					
			CArc * ARCArc = new CArc(pSOMDest);

			pSOMDest->SOMAffecterArcArrivant(ARCArc);

			pSOMDep->SOMAffecterArcPartant(ARCArc);


		}
	}
	else
		throw new CExceptions(BAD_INPUT);

	return pGRAgraphe;



	
}