#pragma once
#include "DefCodeVitaShade.h" 
#include "Logger.h"
#include "tooth_shade_predictor.h"
#include "linreg.h"


#define LAB_METHOD		0
#define VITA_METHOD		1

typedef struct
{
	string outL ;
	string outA ;
	string outB ;
	string deE ;
	string outVita ;
}OUTPUT_DATA;



class InterfaceUI
{
public:

	InterfaceUI(void);
	
	int method ;
	int bfShadeLevel , afShadeLevel , af2ShadeLevel ;
	OUTPUT_DATA after , after2Weeks ;
	DefCodeVitaShade *def ;
	void InitialDataProcess(ToothShadePredictor tspt);



	void setMethod(int method);
	int getMethod();

	void setBfShadeLevel(int bfShade);
	int getBfShadeLevel();

	void setAfShadeLevel(int afShade);
	int getAfShadeLevel();

	void setAf2ShadeLevel(int af2Shade);
	int getAf2ShadeLevel();

	void setInputVitaCode(string vitaCode);
	void setInptL_a_b(float l,float a,float b);

	void resultAfter(OUTPUT_DATA *after);
	void resultAfter2Weeks(OUTPUT_DATA *after2Weeks);

	string outputLAfter();
	string outputAAfter();
	string outputBAfter();
	string outputDEAfter();
	string outputVitaAfter();

	string outputLAfter2Week();
	string outputAAfter2Week();
	string outputBAfter2Week();
	string outputDEAfter2Week();
	string outputVitaAfter2Week();



	
};
