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

	}
	catch (CExceptions e)
	{
		e.EXCAfficheErreur();
	}

	


	system("pause");

	return 0;
}

