#pragma once
#include <string>

#define NO_INPUT		"NONE"
#define HEAD_SN			"H.N."
#define HEAD_NAME		"Name"
#define HEAD_BIRTH		"Date of birth"
#define HEAD_GENDER		"Gender"
#define HEAD_CUR_DATE	"Current Date"
#define HEAD_lB			"L-Before"
#define HEAD_aB			"a-Before"
#define HEAD_bB			"b-Before"
#define HEAD_VITAB		"Vitacode-Before"
#define HEAD_lA			"L-After"
#define HEAD_aA			"a-After"
#define HEAD_bA			"b-After"
#define HEAD_VITAA		"Vitacode-After"
#define HEAD_DEA		"Delta E After"
#define HEAD_lA2		"L-After 2 Weeks"
#define HEAD_aA2		"a-After 2 Weeks"
#define HEAD_bA2		"b-After 2 Weeks"
#define HEAD_VITAA2		"Vitacode-After 2 Weeks"
#define HEAD_DEA2		"Delta E After 2 Weeks"


using namespace std ;
using namespace System::Diagnostics;


typedef struct
{
	string sn_number ;
	string name ;
	string lastname ;
	string dateBirth ;
	string gender ;
	string timeStamp ;
	string lBf , aBf , bBf ,vitaBf ;
	string lAf , aAf , bAf , vitaAf , deAf ;
	string lAf2 , aAf2 , bAf2 , vitaAf2 , deAf2 ;
	
}LogData;

class Logger
{
public:
	Logger(void);
	void writeLog(LogData *logSave,string fileName);
	void checkName( const char *cFileName );
	//void writeLog(string fileName,string  data[]);
};
