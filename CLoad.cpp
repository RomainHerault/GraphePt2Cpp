
#include "CLoad.h"


/** Constructeur
*E:
*
*Necessite :
*
*S:
*
*Entraine :(Le nom du fichier est stocké dans la variable de la classe)
*/
CLoad::CLoad(string psNomFichier)
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
		for (unsigned int uiSom = 0; uiSom < uiNbSom; uiSom++)
		{
			infile >> sData;
			unsigned int uiNumSom = atoi(sData.c_str());
			CSommet * SOMNewSommet = new CSommet(uiNumSom);
			pGRAgraphe->GRAAffecterSom(SOMNewSommet);
			delete SOMNewSommet;
		}
	}
	else
		throw new CExceptions(BAD_INPUT);

	infile >> sData;
	infile >> sData;
	//lecture des arcs
	if (sData.compare(0, 100, "Arcs=[") == 0)
	{
		CSommet * pSOMDest = 0;
		CSommet * pSOMDep = 0;
		CArc * pARCArc = 0;
		for (unsigned int uiArc = 0; uiArc < uiNbArcs; uiArc++)
		{
			infile >> sData;
			unsigned int uiSomDep = atoi(sData.c_str());


			infile >> sData;
			unsigned int uiSomArr = atoi(sData.c_str());

			infile >> sData;
			unsigned int uiPoids = atoi(sData.c_str());

			vector<CSommet> * vListeSommet = pGRAgraphe->GRALireSommets();

			for (unsigned int uiBoucle = 0; uiBoucle < vListeSommet->size(); uiBoucle++)
			{
				if (vListeSommet->at(uiBoucle).SOMLireNumero() == uiSomDep)
				{
					pSOMDep = &vListeSommet->at(uiBoucle);
				}
				

				if (vListeSommet->at(uiBoucle).SOMLireNumero() == uiSomArr)
				{
					pSOMDest = &vListeSommet->at(uiBoucle);
				}
			}

			if (pSOMDep == 0 || pSOMDest == 0)
				throw new CExceptions(OBJECT_DOESNT_EXIST);


			pARCArc = new CArc(pSOMDest, uiPoids);

			pSOMDest->SOMAffecterArcArrivant(pARCArc);
			pSOMDep->SOMAffecterArcPartant(pARCArc);

			delete pARCArc;

		}
		
	}
	else
		throw new CExceptions(BAD_INPUT);

	return  pGRAgraphe;




}