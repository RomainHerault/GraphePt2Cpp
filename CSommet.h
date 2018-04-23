#pragma once
#include <vector>
#include "CArc.h"

using namespace std;

class CSommet
{
private:
	unsigned int uiSOMNumero;
	vector<CArc> * vARCSOMArrivant;
	vector<CArc> * vARCSOMPartant;
public:
	CSommet();
	CSommet(unsigned int uiNumero);
	CSommet(const CSommet & SOMParam);
	~CSommet();
	void operator=(CSommet * SOMParam);
	void SOMAffecterArcArrivant(CArc * ARCArc);
	void SOMSupprimerArcArrivant(CArc * ARCArc);
	vector<CArc> * SOMLireArcArrivant();
	void SOMAffecterArcPartant(CArc * ARCArc);
	void SOMSupprimerArcPartant(CArc * ARCArc);
	vector<CArc> * SOMLireArcPartant();
};

