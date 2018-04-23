#include <vector>

#include "stdafx.h"
#include "CSommet.h"

using namespace std;

CSommet::CSommet()
{
	uiSOMNumero = 0;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

CSommet::CSommet(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
	vARCSOMArrivant = new vector<CArc>;
	vARCSOMPartant = new vector<CArc>;
}

CSommet::CSommet(const CSommet & SOMParam)
{
	uiSOMNumero = SOMParam.uiSOMNumero;
	vARCSOMArrivant = new vector<CArc>(*(SOMParam.vARCSOMArrivant));
	vARCSOMPartant = new vector<CArc>(*(SOMParam.vARCSOMPartant));
}

CSommet::~CSommet()
{
	for (unsigned int uiCompteur = 0; uiCompteur < vARCSOMArrivant->size(); uiCompteur++)
		delete &vARCSOMArrivant->at(uiCompteur);
	for (unsigned int uiCompteur = 0; uiCompteur < vARCSOMPartant->size(); uiCompteur++)
		delete &vARCSOMPartant->at(uiCompteur);
}

void CSommet::operator=(CSommet * SOMParam)
{
	uiSOMNumero = SOMParam->uiSOMNumero;
	for (unsigned int uiCompteur = 0; uiCompteur < SOMParam->vARCSOMArrivant->size(); uiCompteur++)
		vARCSOMArrivant->push_back(*(new CArc(SOMParam->vARCSOMArrivant->at(uiCompteur))));
	for (unsigned int uiCompteur = 0; uiCompteur < SOMParam->vARCSOMPartant->size(); uiCompteur++)
		vARCSOMPartant->push_back(*(new CArc(SOMParam->vARCSOMPartant->at(uiCompteur))));
}

void CSommet::SOMAffecterArcArrivant(CArc * ARCArc)
{
	vARCSOMArrivant->push_back(*(new CArc(*ARCArc)));
}

void CSommet::SOMSupprimerArcArrivant(CArc * ARCArc)
{
	unsigned int uiCompteur = 0;
	while (uiCompteur < vARCSOMArrivant->size() && &vARCSOMArrivant->at(uiCompteur) != ARCArc)
		uiCompteur++;
	vARCSOMArrivant->erase(vARCSOMArrivant->begin() + uiCompteur);
}

vector<CArc> * CSommet::SOMLireArcArrivant()
{
	return vARCSOMArrivant;
}

void CSommet::SOMAffecterArcPartant(CArc * ARCArc)
{
	vARCSOMPartant->push_back(*(new CArc(*ARCArc)));
}

void CSommet::SOMSupprimerArcPartant(CArc * ARCArc)
{
	unsigned int uiCompteur = 0;
	while (uiCompteur < vARCSOMPartant->size() && &vARCSOMPartant->at(uiCompteur) != ARCArc)
		uiCompteur++;
	vARCSOMPartant->erase(vARCSOMPartant->begin() + uiCompteur);
}

vector<CArc> * CSommet::SOMLireArcPartant()
{
	return vARCSOMPartant;
}