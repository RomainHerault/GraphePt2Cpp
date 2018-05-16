// Graphe.cpp : Définit le point d'entrée pour l'application console.
//

#include "CArc.h"
#include"CSommet.h"
#include"CGraphe.h"
#include"CLoad.h"


using namespace std;

int main()
{
	string sFileName;


	cout << "Nom du fichier :" << endl;
	cin >> sFileName;

	try {

	
	CLoad * pLODLoader = new CLoad(sFileName);

	CGraphe * pGRAGraphe = pLODLoader->LODParser();

	pGRAGraphe->GRAAfficher();

	

	//On prend les sommets de départ, on récupere les arcs et leur sommet de dest et on switch les 2 sommets

	vector<CSommet> * pvListeSommets = pGRAGraphe->GRALireSommets();

	CGraphe * pGRANewGraphe = new CGraphe();


	//la suite de ce programme créée les nouveaux sommets et les affecte au nouveau graphe
	for (unsigned int uiBoucle = 0; uiBoucle < pvListeSommets->size(); uiBoucle++)
	{
		CSommet * pSOMNewSommet = new CSommet(pvListeSommets->at(uiBoucle).SOMLireNumero());
		
		pGRANewGraphe->GRAAffecterSom(pSOMNewSommet);
	}



	//TODO 
	for (unsigned int uiBoucle = 0; uiBoucle < pvListeSommets->size(); uiBoucle++)
	{

		vector<CArc> * pvListeArcPartant = pvListeSommets->at(uiBoucle).SOMLireArcPartant();

		for (unsigned int uiBoucle2 = 0; uiBoucle2 < pvListeArcPartant->size(); uiBoucle2++)
		{
			//for(unsigned int uiBoucle3 = 0; uiBoucle3 < pvListeArcPartant->size(); uiBoucle3++
				
				)
			CArc * pARCNewArc = new CArc(pSOMNewSommet);
			pSOMNewSommet->SOMAffecterArcArrivant(pARCNewArc);
		}

		/*vector<CArc> * pvListeArcArrivant = pvListeSommets->at(uiBoucle).SOMLireArcArrivant();

		for (unsigned int uiBoucle3 = 0; uiBoucle3 < pvListeArcArrivant->size(); uiBoucle3++)
		{
			pSOMNewSommet->SOMAffecterArcPartant(&pvListeArcArrivant->at(uiBoucle3));
		}
		*/

	}



	pGRANewGraphe->GRAAfficher();

	}
	catch (CExceptions e)
	{
		e.EXCAfficheErreur();
	}


	system("pause");

	return 0;
}

