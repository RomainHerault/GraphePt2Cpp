
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
/*
class CGraphe::CoupleArcLg {
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
/*
	}
};*/

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
	
	for (int j = 0 ; j < SOMSommet->SOMLireArcPartant()->size(); j++   /*CArc ARCArc : *(SOMSommet->SOMLireArcPartant())*/)
	{

		uiLongueur = 0 /*ds[s] = 0*/ + SOMSommet->SOMLireArcPartant()->at(j).ARCLirePoids();
		GRAInserer(vFile, &SOMSommet->SOMLireArcPartant()->at(j), uiLongueur);

		/*printf("Arc que l'on veut ajouter : %d\n", SOMSommet->SOMLireArcPartant()->at(j).ARCLiredest()->SOMLireNumero());
		for (int i = 0; i < vFile->size(); i++)
		{
			printf("%d, @: %d   ", vFile->at(i).ARCArc->ARCLiredest()->SOMLireNumero(), &(vFile->at(i)));
			
			//printf("%d\n", vFile->at(0).ARCArc->ARCLiredest()->SOMLireNumero());
			
		}
		printf("\n");*/
		
		//printf("%d", vFile->size());
	}

	while (vFile->size() > 0)
	{
		CoupleArcLg * newCouple = GRAExtraireMin(vFile);
		printf("Min : %d", newCouple->ARCArc->ARCLiredest()->SOMLireNumero());
		CSommet * v = newCouple->ARCArc->ARCLiredest();
		
		int isIn = 0;
		for (int i = 0 ; i < vVus->size(); i++   /*CSommet SOMSom : *vVus*/)
		{
			if (vVus->at(i).SOMLireNumero() == v->SOMLireNumero())// a vérifier
				isIn = 1;

		}
		if (isIn == 0)
		{
			puiDsTab[v->SOMLireNumero()-1] = newCouple->uiLongueur;
			vVus->push_back(*v); //on ajoute v à Vus
			for (int j = 0; j < v->SOMLireArcPartant()->size(); j++/*CArc ARCSortant : *(v->SOMLireArcPartant())*/)
			{
				uiLongueur = puiDsTab[v->SOMLireNumero()-1] + v->SOMLireArcPartant()->at(j).ARCLirePoids();
				GRAInserer(vFile, &(v->SOMLireArcPartant()->at(j)), uiLongueur);
			}
		}
	}
	return puiDsTab;
}

void CGraphe::GRAInserer(vector<CoupleArcLg> * vFile, CArc * ARCArc, unsigned int uiLongueur)
{
	int isUpdated = 0;
	printf("Destination : %d, longueur : %d \n", ARCArc->ARCLiredest()->SOMLireNumero(), uiLongueur);
	for (int i = 0; i < vFile->size(); i++)
	{
		printf("%d - %d \n%d - %d \n%d - %d\n\n", vFile->at(i).ARCArc->ARCLiredest()->SOMLireNumero(), ARCArc->ARCLiredest()->SOMLireNumero(),
			GRATrouveSomDep(vFile->at(i).ARCArc)->SOMLireNumero(), GRATrouveSomDep(ARCArc)->SOMLireNumero(),
			uiLongueur, vFile->at(i).uiLongueur);
		if ((vFile->at(i).ARCArc->ARCLiredest()->SOMLireNumero() == ARCArc->ARCLiredest()->SOMLireNumero() &&  
			GRATrouveSomDep(vFile->at(i).ARCArc)->SOMLireNumero() == GRATrouveSomDep(ARCArc)->SOMLireNumero()))
		{
			if (uiLongueur < vFile->at(i).uiLongueur)
			{
				printf("il entre dans le if");
				vFile->at(i).uiLongueur = uiLongueur;
			}
			isUpdated = 1;
			
		}
	}

	if (isUpdated == 0)
	{
		CoupleArcLg * CoupleAAjouter = new CoupleArcLg(ARCArc, uiLongueur);
		vFile->push_back(*CoupleAAjouter);
	}

	
	

	//pas là

}

CGraphe::CoupleArcLg * CGraphe::GRAExtraireMin(vector<CoupleArcLg> * vFile)
{
	CoupleArcLg * coupleMin = &(vFile->at(0)); // le sommet de la destination de l'arc de couplemin est null, whyyyyyy ???! (passage par valeur avant ?)
	//printf("%d", coupleMin->ARCArc->ARCLiredest()->SOMLireNumero());
	for (int i = 0; i < vFile->size(); i++   /*CoupleArcLg couple : *vFile*/)
	{
		if (vFile->at(i).uiLongueur < coupleMin->uiLongueur)
		{
			coupleMin = &vFile->at(i);
		}
	}
	GRARemoveElement(vFile, coupleMin);
	
	return coupleMin; //pb ici (devrait retourner l'arc du noeud 2 en premier
}

void CGraphe::GRARemoveElement(vector<CoupleArcLg> * vFile, CoupleArcLg * cal)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vFile->size(); uiBoucle++)
	{
		if (vFile->at(uiBoucle).ARCArc == cal->ARCArc)
		{
			vFile->erase(vFile->begin() + uiBoucle);
			return;
		}
	}
		
}

CSommet * CGraphe::GRATrouveSomDep(CArc * ARCArc)
{

	for (int i = 0 ; i< pvSOMGRASommet->size(); i++ /*CSommet Som : *pvSOMGRASommet*/)
	{
		for (int j = 0; j < pvSOMGRASommet->at(i).SOMLireArcPartant()->size(); j++/*CArc ARCArcPartant : *(Som.SOMLireArcPartant())*/)
		{
			if (ARCArc->ARCLiredest()->SOMLireNumero() == pvSOMGRASommet->at(i).SOMLireArcPartant()->at(j).ARCLiredest()->SOMLireNumero()
				&& ARCArc->ARCLirePoids() == pvSOMGRASommet->at(i).SOMLireArcPartant()->at(j).ARCLirePoids())
			{
				return &(pvSOMGRASommet->at(i));
			}
		}	
	}
	return 0;
}

