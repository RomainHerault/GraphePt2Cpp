
#include "CArc.h"


CArc::CArc()
{
	pSOMARCDestination = new CSommet();
}

CArc::CArc(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

CArc::CArc(const CArc & ARCParam)
{
	pSOMARCDestination = ARCParam.pSOMARCDestination;
}

CArc::~CArc()
{
	pSOMARCDestination = 0;
}

void CArc::operator=(CArc & ARCParam)
{
	pSOMARCDestination = new CSommet(*(ARCParam.ARCLiredest()));
}

void CArc::ARCAffecterDest(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

CSommet * CArc::ARCLiredest()
{
	return pSOMARCDestination;
}