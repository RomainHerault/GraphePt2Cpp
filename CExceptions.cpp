#include"CExceptions.h"

#include <string>
#include <vector>
#include <list>
#include <iostream>

/********************************************//**
* \brief Constructeur par défaut
***********************************************/
CExceptions::CExceptions()
{
	//ctor
	uiEXCValeur = 0;
}


/********************************************//**
* \brief Constructeur à 1 argument
*
* \param uiVal unsigned int la valeur de l'exception
*
***********************************************/
CExceptions::CExceptions(unsigned int uiVal)
{
	//ctor
	uiEXCValeur = uiVal;
}

/********************************************//**
* \brief Destructeur
***********************************************/
CExceptions::~CExceptions()
{
	//dtor
}


/** \brief Affiche l'exception
*/
void CExceptions::EXCAfficheErreur()
{
	std::cout << "Erreur numero " << uiEXCValeur << std::endl;
}

