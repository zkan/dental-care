#include "StdAfx.h"
#include "Logger.h"
#include <fstream>
#include <io.h>

using namespace System;


Logger::Logger(void)
{
}


void Logger::writeLog(LogData *logSave,string fName)
{
	// Copy Data Before Write Log CSV
	LogData logWrite ;

	// --- Profile Data --- //
	logWrite.sn_number = logSave->sn_number ;
	logWrite.name = logSave->name ;
	logWrite.lastname = logSave->lastname ;
	logWrite.dateBirth = logSave->dateBirth ;
	logWrite.gender = logSave->gender ;
	logWrite.timeStamp = logSave->timeStamp ;

	// --- Before ---- //
	logWrite.lBf	= logSave->lBf ;
	logWrite.aBf	= logSave->aBf ;
	logWrite.bBf	= logSave->bBf ;
	logWrite.vitaBf = logSave->vitaBf ;

	// --- After ---- //
	logWrite.vitaBf = logSave->vitaBf ;
	logWrite.lAf	= logSave->lAf ;
	logWrite.aAf	= logSave->aAf ;
	logWrite.bAf	= logSave->bAf ;
	logWrite.deAf   = logSave->deAf ;
	logWrite.vitaAf = logSave->vitaAf ;

	// --- After 2 Weeks --- //
	logWrite.lAf2	= logSave->lAf2 ;
	logWrite.aAf2	= logSave->aAf2 ;
	logWrite.bAf2	= logSave->bAf2 ;
	logWrite.deAf2   = logSave->deAf2 ;
	logWrite.vitaAf2 = logSave->vitaAf2 ;

	const char *fileName = fName.c_str() ;
	
	this->checkName(fileName); // Check Write Header

		// -- Start Normal Write Log --- //
	ofstream log_file(fileName, std::ios_base::out | std::ios_base::app );
	string endLind = "\n" ;
	string comma = "," ;
	string space = " " ;
	string profile = logWrite.sn_number+comma+logWrite.name+space+logWrite.lastname
					+comma+logWrite.dateBirth+comma+logWrite.gender+comma+logWrite.timeStamp ;

	string before = logWrite.lBf+comma+logWrite.aBf+comma
					+logWrite.bBf+comma+logWrite.vitaBf;

	string after  = logWrite.lAf+comma+logWrite.aAf+comma
					+logWrite.bAf+comma+logWrite.vitaAf+comma+logWrite.deAf;

	string after2 = logWrite.lAf2+comma+logWrite.aAf2+comma
					+logWrite.bAf2+comma+logWrite.vitaAf2+comma+logWrite.deAf2;



	string writeRecords = profile+comma+before+comma+after+comma+after2 ;
	log_file << writeRecords << endLind ; 

	

}


ifstream *openInputFile( const char *cFileName )
{
    // this function might be the pronblem.
    ifstream *inFile;
    inFile = new ifstream; 
    inFile->open( cFileName, ios::in );
    return inFile;
}

void  Logger::checkName( const char *filename )
{
	ifstream file (filename); 
	string value;
	if(file.good())
	{
		 getline ( file, value, ',' ); 
		 String ^get = gcnew String(value.c_str());
		 if(get->Equals("") || get->Equals(" "))
		 {
			ofstream log_file(filename, std::ios_base::out | std::ios_base::app );
			string endLind = "\n" ;
			string comma = "," ;
			string space = " " ;

			string profile = HEAD_SN+comma+HEAD_NAME+comma+HEAD_BIRTH+comma+HEAD_GENDER+comma+HEAD_CUR_DATE;

			string before = HEAD_lB+comma+HEAD_aB+comma+HEAD_bB+comma+HEAD_VITAB;
			string after =	HEAD_lA+comma+HEAD_aA+comma+HEAD_bA+comma+HEAD_VITAA+comma+HEAD_DEA;
			string after2 =	HEAD_lA2+comma+HEAD_aA2+comma+HEAD_bA2+comma+HEAD_VITAA2+comma+HEAD_DEA2;

			string writeHeader = profile+comma+before+comma+after+comma+after2 ;
			log_file << writeHeader << endLind ; 
		 }
		 Console::WriteLine("---"+get);
	}
	else
	{
		ofstream log_file(filename, std::ios_base::out | std::ios_base::app );
		string endLind = "\n" ;
		string comma = "," ;
		string space = " " ;

		string profile = HEAD_SN+comma+HEAD_NAME+comma+HEAD_BIRTH+comma+HEAD_GENDER+comma+HEAD_CUR_DATE;

		string before = HEAD_lB+comma+HEAD_aB+comma+HEAD_bB+comma+HEAD_VITAB;
		string after =	HEAD_lA+comma+HEAD_aA+comma+HEAD_bA+comma+HEAD_VITAA+comma+HEAD_DEA;
		string after2 =	HEAD_lA2+comma+HEAD_aA2+comma+HEAD_bA2+comma+HEAD_VITAA2+comma+HEAD_DEA2;

		string writeHeader = profile+comma+before+comma+after+comma+after2 ;
		log_file << writeHeader << endLind ; 


	}
		
	
}