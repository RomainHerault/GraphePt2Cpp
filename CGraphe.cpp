
#include "CGraphe.h"

/**Constructor par d�faut
*E:
*
*Necessite :
*
*S:
*
*Entraine : (L'objet est correctement initialis�)
*/
CGraphe::CGraphe()
{
	uiGRANbSommet = 0;
	pvSOMGRASommet = new vector<CSommet>;

}

/** Constructeur de recopie
*E:
* GRAParam Cgraphe le graphe que l'on veut recopier
*Necessite :
*
*S:
*
*Entraine : (L'objet est correctement initialis� comme une copie du param�tre)
*/
CGraphe::CGraphe(const CGraphe & GRAParam)
{
	uiGRANbSommet = GRAParam.uiGRANbSommet;
	pvSOMGRASommet = new vector<CSommet>(*(GRAParam.pvSOMGRASommet));
}

/**
*E:Destructeur par d�faut
*
*Necessite :
*
*S:
*
*Entraine :(L'objet est correctement d�truit)
*/
CGraphe::~CGraphe()
{
	delete pvSOMGRASommet;
}

/** Surcharge de l'op�rateur =
*E:
* GRAParam CGraphe le graphe que l'on copier
*Necessite :
*
*S:
*
*Entraine :(L'objet devient une copie du param�tre)
*/
void CGraphe::operator=(CGraphe & GRAParam)
{
	uiGRANbSommet = GRAParam.uiGRANbSommet;
	pvSOMGRASommet = new vector<CSommet>(*GRAParam.pvSOMGRASommet);
}

/** Ajoute un sommet au graphe
*E:
*SOMSommet CSommet le sommet � ajouter
*Necessite :
*
*S:
*
*Entraine :(Le sommet est ajout� au graphe)
*/
void CGraphe::GRAAffecterSom(CSommet * SOMSommet)
{
	pvSOMGRASommet->push_back(*SOMSommet);
}

/** Permet de r�cup�rer les sommet du graphe
*E:
*
*Necessite :
*
*S:
* vector<CSommet> une vecteur contenant tous les sommets du graphe
*Entraine :(Retourne un vecteur contenant les sommets du graphe)
*/
vector<CSommet> CGraphe::GRALireSommets()
{

	return * pvSOMGRASommet;
}

/** Afficher le graphe
*E:
*
*Necessite :
*
*S:
*
*Entraine :(Le graphe est affich�)
*/
void CGraphe::GRAAfficher()
{
	for (CSommet SOMSommet : *pvSOMGRASommet)
	{
		for (CArc ARCArc : * (SOMSommet.SOMLireArcPartant()))
			printf("Le sommet %d va vers le sommet %d", SOMSommet.SOMLireNumero(), ARCArc.ARCLiredest()->SOMLireNumero());
	}
}