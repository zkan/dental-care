#include "StdAfx.h"
#include "InterfaceUI.h"
#include "tooth_shade_predictor.h"
#include "linreg.h"

ToothShadePredictor tsp ;

template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); } 

InterfaceUI::InterfaceUI(void)
{
	this->method = LAB_METHOD ;

	this->after.outL = "0.00" ;
	this->after.outA = "0.00"  ;
	this->after.outB = "0.00"  ;
	this->after.outVita = "C4" ;
	this->after2Weeks.outL = "0.00"  ;
	this->after2Weeks.outA = "0.00"  ;
	this->after2Weeks.outB = "0.00"  ;
	this->after2Weeks.outVita = "C4" ;
	
	def = new DefCodeVitaShade();

	this->bfShadeLevel = 0 ;
	this->afShadeLevel = 0 ;
	this->af2ShadeLevel = 0 ;

}


void  InterfaceUI::InitialDataProcess(ToothShadePredictor tsp_global)
{
	tsp  =  tsp_global;
	//Console::WriteLine("-- Tooth Shade Predictor --");
	//Console::WriteLine("--------\n");
    
    // Read the shade tabs first.
    tsp.set_standard_vita_data( "data/input/shade-tabs.txt" );
    vector<vita> standard_vita_data = tsp.get_standard_vita_data();

	//Console::WriteLine("Shade Tabs: ");
    for ( unsigned int i = 0; i < standard_vita_data.size(); i++ ) {
		String ^tmp_str1 = gcnew String(standard_vita_data[ i ].label.c_str());
		//Console::WriteLine(tmp_str1);
        for ( unsigned int j = 0; j < standard_vita_data[i].val.size(); j++ ) {
			String ^tmp_str2 = gcnew String(""+standard_vita_data[ i ].val[j]);
			//Console::WriteLine(tmp_str2);
        }
		//Console::WriteLine("\n");
    }
   
    //Console::WriteLine("\n");
}


void  InterfaceUI::setInptL_a_b(float l,float a,float b)
{
	// Input from user (L, a, and b).
    vector<double> X;
    X.push_back( l );
    X.push_back( a );
    X.push_back( b );

	string vitaAfter , vitaAfter2Weeks;

    // --------------------------------------------------------------
	//Console::Write("Input X( ");
    for ( unsigned int i = 0; i < X.size(); i++ ) {
		Console::Write(X[ i ]);
        if ( i < X.size() - 1 ) {
			Console::Write(", ");
        }
    }
	//Console::Write(" ) maps to ");
    string vita = tsp.map_to_vita( X[0], X[1], X[2] );
	String^ tmp_str4  =  gcnew String(vita.c_str());
	//Console::WriteLine(tmp_str4 );
	//Console::WriteLine("\n");
	// --- Set Shade Level Before --- //
	setBfShadeLevel(def->getVitaCodeIndex(vita));

    
    // --------------------------------------------------------------
	// Start the training and testing processes (After finishing 
    // the entire tooth bleeching process).
    tsp.train( 
        "data/input/training/L.txt", 
        "data/input/training/a.txt", 
        "data/input/training/b.txt" 
    );

    tsp.test(
        "data/input/testing/L.txt", 
        "data/input/testing/a.txt", 
        "data/input/testing/b.txt" 
    );
    tsp.print_vMSE();
    
    vector<double> results = tsp.estimate( X );
	//Console::Write("Results for X( ");
    for ( unsigned int i = 0; i < X.size(); i++ ) {
		Console::Write(X[i]);
        if ( i < X.size() - 1 ) {
			Console::Write(", ");
        }
    }
	//Console::Write(" ): ");
    for ( unsigned int i = 0; i < results.size(); i++ ) {
		Console::Write(results[ i ]+" ");
    }
	//Console::WriteLine("\n");


	//Console::Write("Delta E: ");
	//Console::Write(tsp.compute_delta_E( X, results )+"\n");
	double dEAfter =  tsp.compute_delta_E( X, results ) ;
	//Console::Write("Output Y( ");
    for ( unsigned int i = 0; i < results.size(); i++ ) {
		Console::Write(results[ i ]);
        if ( i < results.size() - 1 ) {
			Console::Write(", ");
        }
    }
	//Console::Write(" ) maps to ");
    vita = tsp.map_to_vita( results[0], results[1], results[2] );
	String ^tmp_str5  =  gcnew  String(vita.c_str());
	//Console::WriteLine(tmp_str5+"\n");
	vitaAfter = vita ;


	// --------------------------------------------------------------
    // Start the training and testing processes (After finishing 
    // the entire tooth bleeching process).
    tsp.train2weeks( 
        "data/input/training/L_after2weeks.txt", 
        "data/input/training/a_after2weeks.txt", 
        "data/input/training/b_after2weeks.txt" 
    );

    tsp.test2weeks(
        "data/input/testing/L_after2weeks.txt", 
        "data/input/testing/a_after2weeks.txt", 
        "data/input/testing/b_after2weeks.txt" 
    );
    
    tsp.print_vMSE_2weeks();
    
    vector<double> results2weeks = tsp.estimate2weeks( X );
	//Console::Write("Results for X( ");
    for ( unsigned int i = 0; i < X.size(); i++ ) {
        Console::Write(X[i]);
        if ( i < X.size() - 1 ) {
            Console::Write(", ");
        }
    }
	//Console::Write(" ) after 2 weeks: ");
    for ( unsigned int i = 0; i < results2weeks.size(); i++ ) {
		Console::Write(results2weeks[ i ]+" ");
    }
	//Console::WriteLine("\n");


	//Console::Write("Delta E after 2 weeks: ");
	//Console::WriteLine(tsp.compute_delta_E( X, results2weeks ));
	double dEAfter2Week = tsp.compute_delta_E( X, results2weeks ) ;


	//Console::Write("Output after 2 weeks Y( ");
    for ( unsigned int i = 0; i < results2weeks.size(); i++ ) {
		Console::Write(results2weeks[ i ]);
        if ( i < results2weeks.size() - 1 ) {
			Console::Write(", ");
        }
    }
	//Console::Write(" ) maps to ");
    vita = tsp.map_to_vita( results2weeks[0], results2weeks[1], results2weeks[2] );
	String ^tmp_str6  =  gcnew  String(vita.c_str());
	//Console::WriteLine(tmp_str6+"\n");
	vitaAfter2Weeks = vita ;

	OUTPUT_DATA tmpOutputAfter , tmpOutputAfter2Weeks ;

	// --- Set data after --- //
	tmpOutputAfter.outL = tostr(results[0]) ;
	tmpOutputAfter.outA = tostr(results[1]) ;
	tmpOutputAfter.outB = tostr(results[2]) ;
	tmpOutputAfter.deE = tostr(dEAfter);
	tmpOutputAfter.outVita = vitaAfter ;
	resultAfter(&tmpOutputAfter);


	// --- Set data after 2 weeks --- //
	tmpOutputAfter2Weeks.outL = tostr(results2weeks[0]) ;
	tmpOutputAfter2Weeks.outA = tostr(results2weeks[1]) ;
	tmpOutputAfter2Weeks.outB = tostr(results2weeks[2]) ;
	tmpOutputAfter2Weeks.deE = tostr(dEAfter2Week);
	tmpOutputAfter2Weeks.outVita = vitaAfter2Weeks ;
	resultAfter2Weeks(&tmpOutputAfter2Weeks);

	// --- Sel Shade Level Vita Code --- //
	setAfShadeLevel(def->getVitaCodeIndex(vitaAfter));
	setAf2ShadeLevel(def->getVitaCodeIndex(vitaAfter2Weeks));
	//Console::WriteLine(def->getVitaCodeIndex(vitaAfter));
	//Console::WriteLine(def->getVitaCodeIndex(vitaAfter2Weeks));
	


}

void  InterfaceUI::setInputVitaCode(string vitacode)
{
	// If input from user is vita shade, then 
    // map it to L, a, and b first.

    string vita_input = vitacode;
	//setBfShadeLevel(def->getVitaCodeIndex(vita_input));
	float l_a_b[3] ;
	String ^tmp_str3  =  gcnew String(vita_input.c_str());
	//Console::Write("Input "+tmp_str3+" maps to ");
    vector<double> X_from_vita = tsp.map_to_Lab( vita_input );
    for ( unsigned int i = 0; i < X_from_vita.size(); i++ ) {
		l_a_b[i] = (float)X_from_vita[ i ];
		Console::Write(X_from_vita[ i ]);
        if ( i < X_from_vita.size() - 1 ) {
			Console::Write(", ");
        }
    }
	//Console::WriteLine("\n");
	//Console::WriteLine("\n");

	// --- Vita Code to L,a,b Process --- //
	setInptL_a_b(l_a_b[0],l_a_b[1],l_a_b[2]);
    // --------------------------------------------------------------
}



void InterfaceUI::setMethod(int method)
{
	this->method = method ;
}

int InterfaceUI::getMethod()
{
	return this->method ;
}


// --- Output Return Data ---- //

void InterfaceUI::resultAfter(OUTPUT_DATA *after)
{
	this->after.outL = after->outL ;
	this->after.outA = after->outA ;
	this->after.outB = after->outB ;
	this->after.deE = after->deE ;
	this->after.outVita = after->outVita ;

}

void InterfaceUI::resultAfter2Weeks(OUTPUT_DATA *after2Week)
{

	this->after2Weeks.outL = after2Week->outL ;
	this->after2Weeks.outA = after2Week->outA ;
	this->after2Weeks.outB = after2Week->outB ;
	this->after2Weeks.deE = after2Week->deE ;
	this->after2Weeks.outVita = after2Week->outVita ;
}


// after 
string InterfaceUI::outputLAfter()
{
	return this->after.outL ;
}

string InterfaceUI::outputAAfter()
{
	return this->after.outA ;
}

string InterfaceUI::outputBAfter()
{
	return this->after.outB ;
}

string InterfaceUI::outputDEAfter()
{
	return this->after.deE ;
}

string InterfaceUI::outputVitaAfter()
{
	return this->after.outVita ;
}

// after 2 weeks
string InterfaceUI::outputLAfter2Week()
{
	return this->after2Weeks.outL ;
}

string InterfaceUI::outputAAfter2Week()
{
	return this->after2Weeks.outA ;
}

string InterfaceUI::outputBAfter2Week()
{
	return this->after2Weeks.outB ;
}

string InterfaceUI::outputDEAfter2Week()
{
	return this->after2Weeks.deE ;
}

string InterfaceUI::outputVitaAfter2Week()
{
	return this->after2Weeks.outVita ;
}



// --- Determine VitaShade Level --- //
void InterfaceUI::setBfShadeLevel(int bfShade)
{
	this->bfShadeLevel = bfShade ;
}

void InterfaceUI::setAfShadeLevel(int afShade)
{
	this->afShadeLevel = afShade ;
}

void InterfaceUI::setAf2ShadeLevel(int af2Shade)
{
	this->af2ShadeLevel = af2Shade ;
}

int InterfaceUI::getBfShadeLevel()
{
	return this->bfShadeLevel ;
}

int InterfaceUI::getAfShadeLevel()
{
	return this->afShadeLevel ;
}

int InterfaceUI::getAf2ShadeLevel()
{
	return this->af2ShadeLevel ;
}