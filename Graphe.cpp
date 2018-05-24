// Graphe.cpp : Définit le point d'entrée pour l'application console.
//
#include <vld.h>
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

	delete pLODLoader;
	cout << "Voici le graphe dans le fichier :" << endl;

	pGRAGraphe->GRAAfficher();

	

	//On prend les sommets de départ, on récupere les arcs et leur sommet de dest et on switch les 2 sommets

	vector<CSommet> * pvListeSommets = pGRAGraphe->GRALireSommets();

	CGraphe * pGRANewGraphe = new CGraphe();


	//la suite de ce programme créée les nouveaux sommets et les affecte au nouveau graphe
	for (unsigned int uiBoucle = 0; uiBoucle < pvListeSommets->size(); uiBoucle++)
	{
		CSommet * pSOMNewSommet = new CSommet(pvListeSommets->at(uiBoucle).SOMLireNumero());
		
		pGRANewGraphe->GRAAffecterSom(pSOMNewSommet);
		delete pSOMNewSommet;
	}



	//pour chaque sommets de l'ancien graphe
	for (unsigned int uiBoucle = 0; uiBoucle < pvListeSommets->size(); uiBoucle++)
	{
		CSommet SOMsomOldGraphe = pvListeSommets->at(uiBoucle); //sommet du vieux graphe
		CSommet * pSOMsomNewGraphe = pGRANewGraphe->GRATrouverParNum(SOMsomOldGraphe.SOMLireNumero()); //sommet de même numéro du nouveau graphe

		//liste des arcs qui  partent pour chaque sommet de l'ancien graphe
		vector<CArc> * pvListeArcPartant = SOMsomOldGraphe.SOMLireArcPartant();

		//pour chacun des arcs partants d'un sommet de l'ancien graphe
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < pvListeArcPartant->size(); uiBoucle2++)
		{
			CSommet * pSOMDestArcOldGraphe = pvListeArcPartant->at(uiBoucle2).ARCLiredest();
			CSommet * pSOMDepArcNewGraphe = pGRANewGraphe->GRATrouverParNum(pSOMDestArcOldGraphe->SOMLireNumero());

			CArc * pARCNewArc = new CArc(pSOMsomNewGraphe);
			pSOMsomNewGraphe->SOMAffecterArcArrivant(pARCNewArc);
			pSOMDepArcNewGraphe->SOMAffecterArcPartant(pARCNewArc);
			delete pARCNewArc;
		}


	}


	cout << "Voici le graphe inverse :" << endl;
	pGRANewGraphe->GRAAfficher();
	

	

	delete pGRAGraphe;
	delete pGRANewGraphe;


	
	}
	catch (CExceptions e)
	{
		
		e.EXCAfficheErreur();
	}

	


	system("pause");

	return 0;
}

