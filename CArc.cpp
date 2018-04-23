#include "stdafx.h"
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
	delete pSOMARCDestination;
}

CArc & CArc::operator=(const CArc & ARCParam)
{
	pSOMARCDestination = new CSommet(ARCParam);
}

void CArc::ARCAffecterDest(CSommet * pSOMSommet)
{
	pSOMARCDestination = pSOMSommet;
}

CSommet * CArc::ARCLiredest()
{
	return pSOMARCDestination;
}