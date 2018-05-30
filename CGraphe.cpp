
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

class CoupleArcLg {
public : 
	CArc * ARCArc;
	unsigned int uiLongueur;

public : 
	CoupleArcLg(CArc * arc, unsigned int uiLg) {
		ARCArc = arc;
		uiLongueur = uiLg;

		/*ARCArc getArc() {
			return ARCArc;
		}*/

	}
};

vector<unsigned int> CGraphe::GRADijkstra(CSommet * SOMSommet)
{
	
	vector<CoupleArcLg> * vFile = new vector<CoupleArcLg>();
	      
	unsigned int * puiDsTab  = (unsigned int *) malloc(pvSOMGRASommet->size() * sizeof(unsigned int));

	vector<CSommet> * vVus = new vector<CSommet>();



	vVus->push_back(*SOMSommet);

	for (CArc ARCArc : *(SOMSommet->SOMLireArcPartant()))
	{
		unsigned int uiLongueur = 0 /*ds[s] = 0*/ + ARCArc.ARCLirePoids();
		GRAInserer(vuiFile, ARCArc, uiLongueur);
	}

	while (vFile->size() > 0)
	{
		CoupleArcLg newCouple = GRAExtraireMin(vFile);
		CSommet * v = newCouple.ARCArc->ARCLiredest();
		int isIn = 0;
		for (CSommet SOMSom : *vVus)
		{
			if (&SOMSom == v)// a vérifier
				isIn = 1;

		}
		if (isIn == 0)
		{

			if (isIn == 0)
			{
				puiDsTab[v->SOMLireNumero()] = newCouple.uiLongueur;
				vVus->push_back(*v);


			}



		

		}
	}


}