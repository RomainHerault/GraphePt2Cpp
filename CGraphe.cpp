
#include "CGraphe.h"

/**Constructor par défaut
*E:
*
*Necessite :
*
*S:
*
*Entraine : (L'objet est correctement initialisé)
*/
CGraphe::CGraphe()
{

	pvSOMGRASommet = new vector<CSommet>;

}

/** Constructeur de recopie
*E:
* GRAParam Cgraphe le graphe que l'on veut recopier
*Necessite :
*
*S:
*
*Entraine : (L'objet est correctement initialisé comme une copie du paramètre)
*/
CGraphe::CGraphe(const CGraphe & GRAParam)
{

	pvSOMGRASommet = new vector<CSommet>(*(GRAParam.pvSOMGRASommet));
}

/**
*E:Destructeur par défaut
*
*Necessite :
*
*S:
*
*Entraine :(L'objet est correctement détruit)
*/
CGraphe::~CGraphe()
{
	//pvSOMGRASommet->clear();
	//pvSOMGRASommet->erase(pvSOMGRASommet->begin(), pvSOMGRASommet->end());

	/*while (pvSOMGRASommet->size() != 0)
	{
	pvSOMGRASommet->pop_back();
	}*/



	delete pvSOMGRASommet;


}

/** Surcharge de l'opérateur =
*E:
* GRAParam CGraphe le graphe que l'on copier
*Necessite :
*
*S:
*
*Entraine :(L'objet devient une copie du paramètre)
*/
void CGraphe::operator=(CGraphe & GRAParam)
{
	pvSOMGRASommet = GRAParam.pvSOMGRASommet;
}

/** Ajoute un sommet au graphe
*E:
*SOMSommet CSommet le sommet à ajouter
*Necessite :
*
*S:
*
*Entraine :(Le sommet est ajouté au graphe)
*/
void CGraphe::GRAAffecterSom(CSommet * SOMSommet)
{
	pvSOMGRASommet->push_back(*SOMSommet);
}

/** Permet de récupérer les sommet du graphe
*E:
*
*Necessite :
*
*S:
* vector<CSommet> une vecteur contenant tous les sommets du graphe
*Entraine :(Retourne un vecteur contenant les sommets du graphe)
*/
vector<CSommet> * CGraphe::GRALireSommets()
{
	return pvSOMGRASommet;
}

/** Afficher le graphe
*E:
*
*Necessite :
*
*S:
*
*Entraine :(Le graphe est affiché)
*/
void CGraphe::GRAAfficher()
{
	vector<CArc> * vListeArc = 0;
	for (CSommet SOMSommet : *pvSOMGRASommet)
	{
		vListeArc = (SOMSommet.SOMLireArcPartant());
		for (unsigned int uiBoucle = 0; uiBoucle < vListeArc->size(); uiBoucle++)
			printf("Le sommet %d va vers le sommet %d, une distance de %dm les separe\n", SOMSommet.SOMLireNumero(), vListeArc->at(uiBoucle).ARCLiredest()->SOMLireNumero(), vListeArc->at(uiBoucle).ARCLirePoids());
	}

}

/** Renvoie un sommet a partir d'un ID donné en paramètre
*E:
* unsigned int uiNum : ID du sommet a trouver et renvoyer
*Necessite :
*
*S:
* CSommet : Sommet correspondant à l'ID donné en paramètre
*Entraine :
*/
CSommet * CGraphe::GRATrouverParNum(unsigned int uiNum)
{
	for (unsigned int uiBoucle = 0; uiBoucle < pvSOMGRASommet->size(); uiBoucle++)
	{
		if (pvSOMGRASommet->at(uiBoucle).SOMLireNumero() == uiNum)
			return &pvSOMGRASommet->at(uiBoucle);
	}
	throw new CExceptions(OBJECT_DOESNT_EXIST);
}

/** Algorithme de Dijkstra
*E:
*SOMSommet CSommet le sommet duquel on veut partir pour effectuer Dijkstra
*Necessite :
*
*S:
* unsigned int * : Tableau de naturels où t[i] est la distance minimale pour aller du sommet de départ jusqu'au sommet i
*/
unsigned int * CGraphe::GRADijkstra(CSommet * SOMSommet)
{
	
	vector<CoupleArcLg> * vFile = new vector<CoupleArcLg>(); //file de priorité contenant des couples Arc/distance totale
	      
	unsigned int * puiDsTab  = (unsigned int *) malloc(pvSOMGRASommet->size() * sizeof(unsigned int));//tableau contenant les distances finales

	for (int i = 0; i < pvSOMGRASommet->size(); i++)
	{
		puiDsTab[i] = 0;
	}

	vector<CSommet> * vVus = new vector<CSommet>();//Sommets que l'on a déjà parcourus

	vVus->push_back(*SOMSommet);
	unsigned int uiLongueur = 0;
	
	for (unsigned int uiBoucle = 0 ; uiBoucle < SOMSommet->SOMLireArcPartant()->size(); uiBoucle++)
	{

		uiLongueur = 0 /*ds[s] = 0*/ + SOMSommet->SOMLireArcPartant()->at(uiBoucle).ARCLirePoids();
		GRAInserer(vFile, &SOMSommet->SOMLireArcPartant()->at(uiBoucle), uiLongueur);
	}
	while (vFile->size() > 0)
	{
		CoupleArcLg * pCALnewCouple = GRAExtraireMin(vFile);
	
		CSommet * pSOMv = pCALnewCouple->ARCArc->ARCLiredest();
		
		int isIn = 0;
		for (unsigned int uiBoucle2 = 0 ; uiBoucle2 < vVus->size(); uiBoucle2++)
		{
			if (vVus->at(uiBoucle2).SOMLireNumero() == pSOMv->SOMLireNumero())
				isIn = 1;

		}
		if (isIn == 0)
		{
			puiDsTab[pSOMv->SOMLireNumero()-1] = pCALnewCouple->uiLongueur;
			vVus->push_back(*pSOMv); //on ajoute v à Vus
			for (unsigned int uiBoucle3 = 0; uiBoucle3 < pSOMv->SOMLireArcPartant()->size(); uiBoucle3++)
			{
				uiLongueur = puiDsTab[pSOMv->SOMLireNumero()-1] + pSOMv->SOMLireArcPartant()->at(uiBoucle3).ARCLirePoids();
				GRAInserer(vFile, &(pSOMv->SOMLireArcPartant()->at(uiBoucle3)), uiLongueur);
			}
		}
		delete pCALnewCouple;
	}
	delete vFile;
	delete vVus;
	return puiDsTab;
}

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
void CGraphe::GRAInserer(vector<CoupleArcLg> * vFile, CArc * ARCArc, unsigned int uiLongueur)
{
	int isUpdated = 0;
	for (unsigned int uiBoucle = 0; uiBoucle < vFile->size(); uiBoucle++)
	{
			if ((vFile->at(uiBoucle).ARCArc->ARCLiredest()->SOMLireNumero() == ARCArc->ARCLiredest()->SOMLireNumero() &&
			GRATrouveSomDep(vFile->at(uiBoucle).ARCArc)->SOMLireNumero() == GRATrouveSomDep(ARCArc)->SOMLireNumero()))
		{
			if (uiLongueur < vFile->at(uiBoucle).uiLongueur)
			{
				vFile->at(uiBoucle).uiLongueur = uiLongueur;
			}
			isUpdated = 1;
			
		}
	}

	if (isUpdated == 0)
	{
		CoupleArcLg * pCALCoupleAAjouter = new CoupleArcLg(ARCArc, uiLongueur);
		vFile->push_back(*pCALCoupleAAjouter);
		delete pCALCoupleAAjouter;
	}

}

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
CGraphe::CoupleArcLg * CGraphe::GRAExtraireMin(vector<CoupleArcLg> * vFile)
{
	CoupleArcLg * pCALCoupleMin = &(vFile->at(0)); 
	for (unsigned int uiBoucle = 0; uiBoucle < vFile->size(); uiBoucle++)
	{
		if (vFile->at(uiBoucle).uiLongueur < pCALCoupleMin->uiLongueur)
		{
			pCALCoupleMin = &vFile->at(uiBoucle);
		}
	}
	CoupleArcLg * pCALCoupleSauv = new CoupleArcLg(*pCALCoupleMin);
	GRARemoveElement(vFile, pCALCoupleMin);
	return pCALCoupleSauv;
}

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
void CGraphe::GRARemoveElement(vector<CoupleArcLg> * vFile, CoupleArcLg * CALcal)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vFile->size(); uiBoucle++)
	{
		if (vFile->at(uiBoucle).ARCArc == CALcal->ARCArc)
		{
			vFile->erase(vFile->begin() + uiBoucle);
			return;
		}
	}
		
}

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
CSommet * CGraphe::GRATrouveSomDep(CArc * ARCArc)
{

	for (unsigned int uiBoucle = 0 ; uiBoucle< pvSOMGRASommet->size(); uiBoucle++)
	{
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < pvSOMGRASommet->at(uiBoucle).SOMLireArcPartant()->size(); uiBoucle2++)
		{
			if (ARCArc->ARCLiredest()->SOMLireNumero() == pvSOMGRASommet->at(uiBoucle).SOMLireArcPartant()->at(uiBoucle2).ARCLiredest()->SOMLireNumero()
				&& ARCArc->ARCLirePoids() == pvSOMGRASommet->at(uiBoucle).SOMLireArcPartant()->at(uiBoucle2).ARCLirePoids())
			{
				return &(pvSOMGRASommet->at(uiBoucle));
			}
		}	
	}
	return 0;
}

