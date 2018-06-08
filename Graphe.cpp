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

	
/*
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
	*/
	unsigned int * ds = pGRAGraphe->GRADijkstra(&(pGRAGraphe->GRALireSommets()->at(0)));
	
	printf("on part du noeud %d\n", pGRAGraphe->GRALireSommets()->at(0).SOMLireNumero());
	for (unsigned int uiNoeud = 0  ; uiNoeud < pGRAGraphe->GRALireSommets()->size(); uiNoeud++)
	{
		printf("Noeud %d : longueur %d \n",uiNoeud+1, ds[uiNoeud]);
	
	}

	free(ds);

	delete pGRAGraphe;
	


	
	}
	catch (CExceptions e)
	{
		
		e.EXCAfficheErreur();
	}

	


	system("pause");

	return 0;
}

