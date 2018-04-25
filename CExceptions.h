
#pragma once
#ifndef CEXCEPTION_H
#define CEXCEPTION_H



#define POINTEUR_NULL		1
#define TAB_DEPPASSE		2
#define DIV_PAR_0			3
#define BAD_SIZE_OF_MAT		4
#define WRONG_TYPE			5
#define BAD_INPUT			6
#define OBJECT_DOESNT_EXIST	7

#include <string>
#include <vector>
#include <list>
#include <iostream>


class CExceptions
{
public:
	/********************************************//**
	* \brief Constructeur par défaut
	***********************************************/
	CExceptions();

	/********************************************//**
	* \brief Constructeur à 1 argument
	*
	* \param uiVal unsigned int la valeur de l'exception
	*
	***********************************************/
	CExceptions(unsigned int uiVal);

	/********************************************//**
	* \brief destructeur
	***********************************************/
	~CExceptions();

	/********************************************//**
	* \brief Retourne la valeur de l'exception
	*
	* \return unsigned int la valeur de l'exception
	*
	***********************************************/
	unsigned int GetuiEXCValeur() { return uiEXCValeur; }

	/********************************************//**
	* \brief Change la valeur de l'exception
	*
	* \param uiVal unsigned int la valeur de l'exception
	* \return void
	*
	***********************************************/
	void SetuiEXCValeur(unsigned int uiVal) { uiEXCValeur = uiVal; }

	/** \brief Affiche l'exception
	*/
	void EXCAfficheErreur();

protected:

private:
	unsigned int uiEXCValeur;
};

#endif // CEXCEPTIONS_H

