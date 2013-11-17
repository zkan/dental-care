#include "StdAfx.h"
#include "DefCodeVitaShade.h"



using namespace std ;
using namespace System;

//SimpleHash<int> hash_vita(NUM_CODE);

DefCodeVitaShade::DefCodeVitaShade(void)
{
	//this->InitialData();
}


void DefCodeVitaShade::InitialData(void)
{



}

int DefCodeVitaShade::getVitaCodeIndex(string vitacode)
{
	int getCode ;
	for(int i = 0 ; i < NUM_CODE ; i++)
	{
		if(_SVita_Code[i] == vitacode)
		{
			getCode = i+1 ;
			break ;
		}
			
	}
	return getCode;
}

string DefCodeVitaShade::convertInt(int number)
{
	std::stringstream ss;
	ss << number;
	std::string numberAsString(ss.str());
	return numberAsString ;//return a string with the contents of the stream
}