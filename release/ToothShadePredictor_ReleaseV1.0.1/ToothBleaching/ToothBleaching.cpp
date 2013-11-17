// ToothBleaching.cpp : main project file.

#include "stdafx.h"
#include "ToothShadePredict.h"
#include "tooth_shade_predictor.h"
#include "linreg.h"

using namespace ToothBleaching;
using namespace System;


void ToothBleaching::ToothShadePredict::InitialUI()
{
	//AllocConsole();
	//defCode  = new  DefCodeVitaShade();
	logger = new Logger();
	intf = new InterfaceUI();

	this->initialTextBox();

	// --- disable vita method && enable l,a,b method--- //
	this->inputLValue->Enabled = true ;
	this->inputAValue->Enabled = true ;
	this->inputBValue->Enabled = true ;
	this->inputVitaCode->Enabled = false ;

	//String ^currentDesktop = System::Environment::GetEnvironmentVariable( "USERPROFILE" + "\\Desktop" );
	//Console::WriteLine(currentDesktop);


}

void ToothBleaching::ToothShadePredict::initialTextBox()
{
	
	beforeShade = gcnew array<TextBox^>(NUM_CODE) ;
	afterShade = gcnew array<TextBox^>(NUM_CODE) ;
	after2Shade = gcnew array<TextBox^>(NUM_CODE) ;

	// --- Before Chart Level --- //
	beforeShade[0] = this->chartBf1 ;
	beforeShade[1] = this->chartBf2 ;
	beforeShade[2] = this->chartBf3 ;
	beforeShade[3] = this->chartBf4 ;
	beforeShade[4] = this->chartBf5 ;
	beforeShade[5] = this->chartBf6 ;
	beforeShade[6] = this->chartBf7 ;
	beforeShade[7] = this->chartBf8 ;
	beforeShade[8] = this->chartBf9 ;
	beforeShade[9] = this->chartBf10 ;
	beforeShade[10] = this->chartBf11 ;
	beforeShade[11] = this->chartBf12 ;
	beforeShade[12] = this->chartBf13 ;
	beforeShade[13] = this->chartBf14 ;
	beforeShade[14] = this->chartBf15 ;
	beforeShade[15] = this->chartBf16 ;


	// --- After Chart Level --- //
	afterShade[0] = this->chartAf1 ;
	afterShade[1] = this->chartAf2 ;
	afterShade[2] = this->chartAf3 ;
	afterShade[3] = this->chartAf4 ;
	afterShade[4] = this->chartAf5 ;
	afterShade[5] = this->chartAf6 ;
	afterShade[6] = this->chartAf7 ;
	afterShade[7] = this->chartAf8 ;
	afterShade[8] = this->chartAf9 ;
	afterShade[9] = this->chartAf10 ;
	afterShade[10] = this->chartAf11 ;
	afterShade[11] = this->chartAf12 ;
	afterShade[12] = this->chartAf13 ;
	afterShade[13] = this->chartAf14 ;
	afterShade[14] = this->chartAf15 ;
	afterShade[15] = this->chartAf16 ;

	// --- After 2 Weeks Chart Level --- //
	after2Shade[0] = this->chartAf2W1 ;
	after2Shade[1] = this->chartAf2W2 ;
	after2Shade[2] = this->chartAf2W3 ;
	after2Shade[3] = this->chartAf2W4 ;
	after2Shade[4] = this->chartAf2W5 ;
	after2Shade[5] = this->chartAf2W6 ;
	after2Shade[6] = this->chartAf2W7 ;
	after2Shade[7] = this->chartAf2W8 ;
	after2Shade[8] = this->chartAf2W9 ;
	after2Shade[9] = this->chartAf2W10 ;
	after2Shade[10] = this->chartAf2W11 ;
	after2Shade[11] = this->chartAf2W12 ;
	after2Shade[12] = this->chartAf2W13 ;
	after2Shade[13] = this->chartAf2W14 ;
	after2Shade[14] = this->chartAf2W15 ;
	after2Shade[15] = this->chartAf2W16 ;

}

void ToothBleaching::ToothShadePredict::paintShadeLevel()
{


	for(int i = 0 ; i < NUM_CODE; i++)
	{
		
		// --- Before Shade Level Paint --- //
		if(i < intf->getBfShadeLevel())
		{
			beforeShade[i]->BackColor = Color::Blue ;
		}
		else
		{
			beforeShade[i]->BackColor = Color::White ;
		}
		
		// --- After Shade Level Paint --- //
		if(i < intf->getAfShadeLevel())
		{
			afterShade[i]->BackColor = Color::Blue ;
		}
		else
		{
			afterShade[i]->BackColor = Color::White ;
		}
		
		// --- After 2 Weeks Shade Level Paint --- //
		if(i < intf->getAf2ShadeLevel())
		{
			after2Shade[i]->BackColor = Color::Blue ;
		}
		else
		{
			after2Shade[i]->BackColor = Color::White ;
		}
	}
}


// Before Image
void ToothBleaching::ToothShadePredict::changeImageBefore(int vitaCodeIndex)
{
	//Console::WriteLine(vitaCodeIndex);
	
}

// After Image
void ToothBleaching::ToothShadePredict::changeImageAfter(int vitaCodeIndex)
{
	//Console::WriteLine(vitaCodeIndex);
}

// After 2 Weeks Image
void ToothBleaching::ToothShadePredict::changeImageAfter2Week(int vitaCodeIndex)
{
	//Console::WriteLine(vitaCodeIndex);
}

bool ToothBleaching::ToothShadePredict::FileExists(string strFilename) {
	  struct stat stFileInfo;
	  bool blnReturn;
	  int intStat;

	  // Attempt to get the file attributes
	  intStat = stat(strFilename.c_str(),&stFileInfo);
	  if(intStat == 0) {
		// We were able to get the file attributes
		// so the file obviously exists.
		blnReturn = true;
	  } else {
		// We were not able to get the file attributes.
		// This may mean that we don't have permission to
		// access the folder which contains this file. If you
		// need to do that level of checking, lookup the
		// return values of stat which will give you
		// more details on why stat failed.
		blnReturn = false;
	  }

	  return(blnReturn);
}
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it

	Application::Run(gcnew ToothShadePredict());
	return 0;
}
