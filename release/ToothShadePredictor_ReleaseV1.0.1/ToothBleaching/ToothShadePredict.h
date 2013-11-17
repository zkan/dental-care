#pragma once

#include "DefCodeVitaShade.h" 
#include "Logger.h"
#include "InterfaceUI.h"
#include <float.h>
#include <string>
#include <iomanip>
#include <sys/stat.h>


using namespace System;


namespace ToothBleaching {

	using namespace std ;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::IO;

	
	
	

	/// <summary>
	/// Summary for ToothShadePredict
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ToothShadePredict : public System::Windows::Forms::Form
	{
	public:
		void InitialUI(void);
		void initialTextBox(void);
		void paintShadeLevel();
		void changeImageBefore(int vitaCodeIndex);
		void changeImageAfter(int vitaCodeIndex);
		void changeImageAfter2Week(int vitaCodeIndex);
		bool FileExists(string strFilename);
		array<TextBox^> ^beforeShade , ^afterShade , ^after2Shade ;
		InterfaceUI *intf ;
		//DefCodeVitaShade *defCode ;
		Logger *logger ;
		String ^pathFileSave  ;
		

	public: 

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::PictureBox^  picBefore;

	private: System::Windows::Forms::ComboBox^  inputVitaCode;

	private: System::Windows::Forms::NumericUpDown^  inputAValue;

	private: System::Windows::Forms::RadioButton^  selLAB;
	private: System::Windows::Forms::NumericUpDown^  inputBValue;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  inputLValue;

	private: System::Windows::Forms::RadioButton^  selVita;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::DateTimePicker^  datebirth;

	private: System::Windows::Forms::TextBox^  txtSNNum;
	private: System::Windows::Forms::ComboBox^  gender;


	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  txtLName;

	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::TextBox^  chartBf1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::CheckBox^  chkLog;



	public: 
		

		ToothShadePredict(void)
		{
			InitializeComponent();
			this->InitialUI();
			pathFileSave = "tooth_color_predictor.csv" ;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToothShadePredict()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  vitaOutAfter;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  lAfter;
	private: System::Windows::Forms::TextBox^  aAfter;
	private: System::Windows::Forms::TextBox^  bAfter;



	private: System::Windows::Forms::TextBox^  deltaEAfter;
	private: System::Windows::Forms::PictureBox^  picAfter;




	private: System::Windows::Forms::Button^  button3;


	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  vitaOutAfter2;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::TextBox^  lAfter2;
private: System::Windows::Forms::TextBox^  aAfter2;
private: System::Windows::Forms::TextBox^  bAfter2;



private: System::Windows::Forms::TextBox^  deltaEAfter2;
private: System::Windows::Forms::PictureBox^  picAfter2;





	private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::PictureBox^  picLogo;


	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;


private: System::Windows::Forms::TextBox^  chartAf3;




private: System::Windows::Forms::TextBox^  chartAf2;

private: System::Windows::Forms::TextBox^  chartAf1;

private: System::Windows::Forms::TextBox^  chartBf16;

private: System::Windows::Forms::TextBox^  chartBf15;

private: System::Windows::Forms::TextBox^  chartBf14;

private: System::Windows::Forms::TextBox^  chartBf13;

private: System::Windows::Forms::TextBox^  chartBf12;

private: System::Windows::Forms::TextBox^  chartBf11;

private: System::Windows::Forms::TextBox^  chartBf10;

private: System::Windows::Forms::TextBox^  chartBf9;

private: System::Windows::Forms::TextBox^  chartBf8;

private: System::Windows::Forms::TextBox^  chartBf7;

private: System::Windows::Forms::TextBox^  chartBf6;

private: System::Windows::Forms::TextBox^  chartBf5;

private: System::Windows::Forms::TextBox^  chartBf4;

private: System::Windows::Forms::TextBox^  chartBf3;

private: System::Windows::Forms::TextBox^  chartBf2;


private: System::Windows::Forms::TextBox^  chartAf2W16;


private: System::Windows::Forms::TextBox^  chartAf2W15;

private: System::Windows::Forms::TextBox^  chartAf2W14;

private: System::Windows::Forms::TextBox^  chartAf2W13;

private: System::Windows::Forms::TextBox^  chartAf2W12;

private: System::Windows::Forms::TextBox^  chartAf2W11;

private: System::Windows::Forms::TextBox^  chartAf2W10;

private: System::Windows::Forms::TextBox^  chartAf2W9;

private: System::Windows::Forms::TextBox^  chartAf2W8;

private: System::Windows::Forms::TextBox^  chartAf2W7;

private: System::Windows::Forms::TextBox^  chartAf2W6;

private: System::Windows::Forms::TextBox^  chartAf2W5;

private: System::Windows::Forms::TextBox^  chartAf2W4;

private: System::Windows::Forms::TextBox^  chartAf2W3;

private: System::Windows::Forms::TextBox^  chartAf2W2;

private: System::Windows::Forms::TextBox^  chartAf2W1;

private: System::Windows::Forms::TextBox^  chartAf16;

private: System::Windows::Forms::TextBox^  chartAf15;

private: System::Windows::Forms::TextBox^  chartAf14;

private: System::Windows::Forms::TextBox^  chartAf13;

private: System::Windows::Forms::TextBox^  chartAf12;

private: System::Windows::Forms::TextBox^  chartAf11;

private: System::Windows::Forms::TextBox^  chartAf10;

private: System::Windows::Forms::TextBox^  chartAf9;

private: System::Windows::Forms::TextBox^  chartAf8;

private: System::Windows::Forms::TextBox^  chartAf7;

private: System::Windows::Forms::TextBox^  chartAf6;

private: System::Windows::Forms::TextBox^  chartAf5;

private: System::Windows::Forms::TextBox^  chartAf4;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ToothShadePredict::typeid));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->vitaOutAfter = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lAfter = (gcnew System::Windows::Forms::TextBox());
			this->aAfter = (gcnew System::Windows::Forms::TextBox());
			this->bAfter = (gcnew System::Windows::Forms::TextBox());
			this->deltaEAfter = (gcnew System::Windows::Forms::TextBox());
			this->picAfter = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->vitaOutAfter2 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lAfter2 = (gcnew System::Windows::Forms::TextBox());
			this->aAfter2 = (gcnew System::Windows::Forms::TextBox());
			this->bAfter2 = (gcnew System::Windows::Forms::TextBox());
			this->deltaEAfter2 = (gcnew System::Windows::Forms::TextBox());
			this->picAfter2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->chkLog = (gcnew System::Windows::Forms::CheckBox());
			this->chartBf16 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf15 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf14 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf13 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf12 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf11 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf10 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf9 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf8 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf7 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf6 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf5 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf4 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf3 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf2 = (gcnew System::Windows::Forms::TextBox());
			this->chartBf1 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W16 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W15 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W14 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W13 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W12 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W11 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W10 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W9 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W8 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W7 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W6 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W5 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W4 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W3 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W2 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2W1 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf16 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf15 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf14 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf13 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf12 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf11 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf10 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf9 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf8 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf7 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf6 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf5 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf4 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf3 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf2 = (gcnew System::Windows::Forms::TextBox());
			this->chartAf1 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->picLogo = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->txtLName = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtSNNum = (gcnew System::Windows::Forms::TextBox());
			this->gender = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->datebirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->picBefore = (gcnew System::Windows::Forms::PictureBox());
			this->inputVitaCode = (gcnew System::Windows::Forms::ComboBox());
			this->inputAValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->selLAB = (gcnew System::Windows::Forms::RadioButton());
			this->inputBValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputLValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->selVita = (gcnew System::Windows::Forms::RadioButton());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picAfter))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picAfter2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLogo))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBefore))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputAValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputBValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputLValue))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->vitaOutAfter);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->lAfter);
			this->groupBox2->Controls->Add(this->aAfter);
			this->groupBox2->Controls->Add(this->bAfter);
			this->groupBox2->Controls->Add(this->deltaEAfter);
			this->groupBox2->Controls->Add(this->picAfter);
			this->groupBox2->ForeColor = System::Drawing::Color::Blue;
			this->groupBox2->Location = System::Drawing::Point(40, 30);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(265, 200);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"After";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(43, 137);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(82, 15);
			this->label9->TabIndex = 9;
			this->label9->Text = L"VITA-CODE:";
			// 
			// vitaOutAfter
			// 
			this->vitaOutAfter->BackColor = System::Drawing::Color::White;
			this->vitaOutAfter->ForeColor = System::Drawing::Color::Blue;
			this->vitaOutAfter->Location = System::Drawing::Point(130, 134);
			this->vitaOutAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->vitaOutAfter->Name = L"vitaOutAfter";
			this->vitaOutAfter->ReadOnly = true;
			this->vitaOutAfter->Size = System::Drawing::Size(40, 21);
			this->vitaOutAfter->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(178, 137);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 15);
			this->label8->TabIndex = 7;
			this->label8->Text = L"ΔE:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(187, 169);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 15);
			this->label7->TabIndex = 6;
			this->label7->Text = L"b:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(112, 169);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 15);
			this->label6->TabIndex = 5;
			this->label6->Text = L"a:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 169);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"L:";
			// 
			// lAfter
			// 
			this->lAfter->BackColor = System::Drawing::Color::White;
			this->lAfter->ForeColor = System::Drawing::Color::Blue;
			this->lAfter->Location = System::Drawing::Point(52, 163);
			this->lAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lAfter->Name = L"lAfter";
			this->lAfter->ReadOnly = true;
			this->lAfter->Size = System::Drawing::Size(50, 21);
			this->lAfter->TabIndex = 3;
			// 
			// aAfter
			// 
			this->aAfter->BackColor = System::Drawing::Color::White;
			this->aAfter->ForeColor = System::Drawing::Color::Blue;
			this->aAfter->Location = System::Drawing::Point(130, 163);
			this->aAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->aAfter->Name = L"aAfter";
			this->aAfter->ReadOnly = true;
			this->aAfter->Size = System::Drawing::Size(50, 21);
			this->aAfter->TabIndex = 3;
			// 
			// bAfter
			// 
			this->bAfter->BackColor = System::Drawing::Color::White;
			this->bAfter->ForeColor = System::Drawing::Color::Blue;
			this->bAfter->Location = System::Drawing::Point(208, 163);
			this->bAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bAfter->Name = L"bAfter";
			this->bAfter->ReadOnly = true;
			this->bAfter->Size = System::Drawing::Size(50, 21);
			this->bAfter->TabIndex = 3;
			// 
			// deltaEAfter
			// 
			this->deltaEAfter->BackColor = System::Drawing::Color::White;
			this->deltaEAfter->ForeColor = System::Drawing::Color::Blue;
			this->deltaEAfter->Location = System::Drawing::Point(208, 134);
			this->deltaEAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->deltaEAfter->Name = L"deltaEAfter";
			this->deltaEAfter->ReadOnly = true;
			this->deltaEAfter->Size = System::Drawing::Size(50, 21);
			this->deltaEAfter->TabIndex = 2;
			// 
			// picAfter
			// 
			this->picAfter->BackColor = System::Drawing::Color::Transparent;
			this->picAfter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picAfter->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picAfter.Image")));
			this->picAfter->Location = System::Drawing::Point(64, 35);
			this->picAfter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picAfter->Name = L"picAfter";
			this->picAfter->Size = System::Drawing::Size(185, 80);
			this->picAfter->TabIndex = 1;
			this->picAfter->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->ForeColor = System::Drawing::Color::Blue;
			this->button3->Location = System::Drawing::Point(700, 2);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 24);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Output ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ToothShadePredict::button3_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Transparent;
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->vitaOutAfter2);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->lAfter2);
			this->groupBox3->Controls->Add(this->aAfter2);
			this->groupBox3->Controls->Add(this->bAfter2);
			this->groupBox3->Controls->Add(this->deltaEAfter2);
			this->groupBox3->Controls->Add(this->picAfter2);
			this->groupBox3->ForeColor = System::Drawing::Color::Blue;
			this->groupBox3->Location = System::Drawing::Point(469, 30);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Size = System::Drawing::Size(265, 200);
			this->groupBox3->TabIndex = 30;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"After 2 Weeks";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(44, 140);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(82, 15);
			this->label10->TabIndex = 9;
			this->label10->Text = L"VITA-CODE:";
			// 
			// vitaOutAfter2
			// 
			this->vitaOutAfter2->BackColor = System::Drawing::Color::White;
			this->vitaOutAfter2->ForeColor = System::Drawing::Color::Blue;
			this->vitaOutAfter2->Location = System::Drawing::Point(130, 137);
			this->vitaOutAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->vitaOutAfter2->Name = L"vitaOutAfter2";
			this->vitaOutAfter2->ReadOnly = true;
			this->vitaOutAfter2->Size = System::Drawing::Size(40, 21);
			this->vitaOutAfter2->TabIndex = 8;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(178, 140);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(28, 15);
			this->label11->TabIndex = 7;
			this->label11->Text = L"ΔE:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(187, 172);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(19, 15);
			this->label12->TabIndex = 6;
			this->label12->Text = L"b:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(112, 172);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(19, 15);
			this->label13->TabIndex = 5;
			this->label13->Text = L"a:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(28, 172);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 15);
			this->label14->TabIndex = 4;
			this->label14->Text = L"L:";
			// 
			// lAfter2
			// 
			this->lAfter2->BackColor = System::Drawing::Color::White;
			this->lAfter2->ForeColor = System::Drawing::Color::Blue;
			this->lAfter2->Location = System::Drawing::Point(52, 166);
			this->lAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lAfter2->Name = L"lAfter2";
			this->lAfter2->ReadOnly = true;
			this->lAfter2->Size = System::Drawing::Size(50, 21);
			this->lAfter2->TabIndex = 3;
			// 
			// aAfter2
			// 
			this->aAfter2->BackColor = System::Drawing::Color::White;
			this->aAfter2->ForeColor = System::Drawing::Color::Blue;
			this->aAfter2->Location = System::Drawing::Point(130, 166);
			this->aAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->aAfter2->Name = L"aAfter2";
			this->aAfter2->ReadOnly = true;
			this->aAfter2->Size = System::Drawing::Size(50, 21);
			this->aAfter2->TabIndex = 3;
			// 
			// bAfter2
			// 
			this->bAfter2->BackColor = System::Drawing::Color::White;
			this->bAfter2->ForeColor = System::Drawing::Color::Blue;
			this->bAfter2->Location = System::Drawing::Point(208, 166);
			this->bAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bAfter2->Name = L"bAfter2";
			this->bAfter2->ReadOnly = true;
			this->bAfter2->Size = System::Drawing::Size(50, 21);
			this->bAfter2->TabIndex = 3;
			// 
			// deltaEAfter2
			// 
			this->deltaEAfter2->BackColor = System::Drawing::Color::White;
			this->deltaEAfter2->ForeColor = System::Drawing::Color::Blue;
			this->deltaEAfter2->Location = System::Drawing::Point(208, 137);
			this->deltaEAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->deltaEAfter2->Name = L"deltaEAfter2";
			this->deltaEAfter2->ReadOnly = true;
			this->deltaEAfter2->Size = System::Drawing::Size(50, 21);
			this->deltaEAfter2->TabIndex = 2;
			// 
			// picAfter2
			// 
			this->picAfter2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picAfter2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picAfter2.Image")));
			this->picAfter2->Location = System::Drawing::Point(64, 35);
			this->picAfter2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picAfter2->Name = L"picAfter2";
			this->picAfter2->Size = System::Drawing::Size(185, 80);
			this->picAfter2->TabIndex = 1;
			this->picAfter2->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->chkLog);
			this->panel2->Controls->Add(this->chartBf16);
			this->panel2->Controls->Add(this->chartBf15);
			this->panel2->Controls->Add(this->chartBf14);
			this->panel2->Controls->Add(this->chartBf13);
			this->panel2->Controls->Add(this->chartBf12);
			this->panel2->Controls->Add(this->chartBf11);
			this->panel2->Controls->Add(this->chartBf10);
			this->panel2->Controls->Add(this->chartBf9);
			this->panel2->Controls->Add(this->chartBf8);
			this->panel2->Controls->Add(this->chartBf7);
			this->panel2->Controls->Add(this->chartBf6);
			this->panel2->Controls->Add(this->chartBf5);
			this->panel2->Controls->Add(this->chartBf4);
			this->panel2->Controls->Add(this->chartBf3);
			this->panel2->Controls->Add(this->chartBf2);
			this->panel2->Controls->Add(this->chartBf1);
			this->panel2->Controls->Add(this->chartAf2W16);
			this->panel2->Controls->Add(this->chartAf2W15);
			this->panel2->Controls->Add(this->chartAf2W14);
			this->panel2->Controls->Add(this->chartAf2W13);
			this->panel2->Controls->Add(this->chartAf2W12);
			this->panel2->Controls->Add(this->chartAf2W11);
			this->panel2->Controls->Add(this->chartAf2W10);
			this->panel2->Controls->Add(this->chartAf2W9);
			this->panel2->Controls->Add(this->chartAf2W8);
			this->panel2->Controls->Add(this->chartAf2W7);
			this->panel2->Controls->Add(this->chartAf2W6);
			this->panel2->Controls->Add(this->chartAf2W5);
			this->panel2->Controls->Add(this->chartAf2W4);
			this->panel2->Controls->Add(this->chartAf2W3);
			this->panel2->Controls->Add(this->chartAf2W2);
			this->panel2->Controls->Add(this->chartAf2W1);
			this->panel2->Controls->Add(this->chartAf16);
			this->panel2->Controls->Add(this->chartAf15);
			this->panel2->Controls->Add(this->chartAf14);
			this->panel2->Controls->Add(this->chartAf13);
			this->panel2->Controls->Add(this->chartAf12);
			this->panel2->Controls->Add(this->chartAf11);
			this->panel2->Controls->Add(this->chartAf10);
			this->panel2->Controls->Add(this->chartAf9);
			this->panel2->Controls->Add(this->chartAf8);
			this->panel2->Controls->Add(this->chartAf7);
			this->panel2->Controls->Add(this->chartAf6);
			this->panel2->Controls->Add(this->chartAf5);
			this->panel2->Controls->Add(this->chartAf4);
			this->panel2->Controls->Add(this->chartAf3);
			this->panel2->Controls->Add(this->chartAf2);
			this->panel2->Controls->Add(this->chartAf1);
			this->panel2->Controls->Add(this->label17);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->pictureBox5);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox3);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(222)));
			this->panel2->Location = System::Drawing::Point(12, 223);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(780, 410);
			this->panel2->TabIndex = 31;
			// 
			// chkLog
			// 
			this->chkLog->AutoSize = true;
			this->chkLog->ForeColor = System::Drawing::Color::Blue;
			this->chkLog->Location = System::Drawing::Point(592, 5);
			this->chkLog->Name = L"chkLog";
			this->chkLog->Size = System::Drawing::Size(105, 19);
			this->chkLog->TabIndex = 86;
			this->chkLog->Text = L"Data Logger";
			this->chkLog->UseVisualStyleBackColor = true;
			this->chkLog->CheckedChanged += gcnew System::EventHandler(this, &ToothShadePredict::chkLog_CheckedChanged);
			// 
			// chartBf16
			// 
			this->chartBf16->BackColor = System::Drawing::Color::White;
			this->chartBf16->Location = System::Drawing::Point(695, 321);
			this->chartBf16->Name = L"chartBf16";
			this->chartBf16->ReadOnly = true;
			this->chartBf16->Size = System::Drawing::Size(36, 21);
			this->chartBf16->TabIndex = 85;
			// 
			// chartBf15
			// 
			this->chartBf15->BackColor = System::Drawing::Color::White;
			this->chartBf15->Location = System::Drawing::Point(659, 321);
			this->chartBf15->Name = L"chartBf15";
			this->chartBf15->ReadOnly = true;
			this->chartBf15->Size = System::Drawing::Size(36, 21);
			this->chartBf15->TabIndex = 84;
			// 
			// chartBf14
			// 
			this->chartBf14->BackColor = System::Drawing::Color::White;
			this->chartBf14->Location = System::Drawing::Point(623, 321);
			this->chartBf14->Name = L"chartBf14";
			this->chartBf14->ReadOnly = true;
			this->chartBf14->Size = System::Drawing::Size(36, 21);
			this->chartBf14->TabIndex = 83;
			// 
			// chartBf13
			// 
			this->chartBf13->BackColor = System::Drawing::Color::White;
			this->chartBf13->Location = System::Drawing::Point(587, 321);
			this->chartBf13->Name = L"chartBf13";
			this->chartBf13->ReadOnly = true;
			this->chartBf13->Size = System::Drawing::Size(36, 21);
			this->chartBf13->TabIndex = 82;
			// 
			// chartBf12
			// 
			this->chartBf12->BackColor = System::Drawing::Color::White;
			this->chartBf12->Location = System::Drawing::Point(551, 321);
			this->chartBf12->Name = L"chartBf12";
			this->chartBf12->ReadOnly = true;
			this->chartBf12->Size = System::Drawing::Size(36, 21);
			this->chartBf12->TabIndex = 81;
			// 
			// chartBf11
			// 
			this->chartBf11->BackColor = System::Drawing::Color::White;
			this->chartBf11->Location = System::Drawing::Point(515, 321);
			this->chartBf11->Name = L"chartBf11";
			this->chartBf11->ReadOnly = true;
			this->chartBf11->Size = System::Drawing::Size(36, 21);
			this->chartBf11->TabIndex = 80;
			// 
			// chartBf10
			// 
			this->chartBf10->BackColor = System::Drawing::Color::White;
			this->chartBf10->Location = System::Drawing::Point(479, 321);
			this->chartBf10->Name = L"chartBf10";
			this->chartBf10->ReadOnly = true;
			this->chartBf10->Size = System::Drawing::Size(36, 21);
			this->chartBf10->TabIndex = 79;
			// 
			// chartBf9
			// 
			this->chartBf9->BackColor = System::Drawing::Color::White;
			this->chartBf9->Location = System::Drawing::Point(443, 321);
			this->chartBf9->Name = L"chartBf9";
			this->chartBf9->ReadOnly = true;
			this->chartBf9->Size = System::Drawing::Size(36, 21);
			this->chartBf9->TabIndex = 78;
			// 
			// chartBf8
			// 
			this->chartBf8->BackColor = System::Drawing::Color::White;
			this->chartBf8->Location = System::Drawing::Point(407, 321);
			this->chartBf8->Name = L"chartBf8";
			this->chartBf8->ReadOnly = true;
			this->chartBf8->Size = System::Drawing::Size(36, 21);
			this->chartBf8->TabIndex = 77;
			// 
			// chartBf7
			// 
			this->chartBf7->BackColor = System::Drawing::Color::White;
			this->chartBf7->Location = System::Drawing::Point(371, 321);
			this->chartBf7->Name = L"chartBf7";
			this->chartBf7->ReadOnly = true;
			this->chartBf7->Size = System::Drawing::Size(36, 21);
			this->chartBf7->TabIndex = 76;
			// 
			// chartBf6
			// 
			this->chartBf6->BackColor = System::Drawing::Color::White;
			this->chartBf6->Location = System::Drawing::Point(335, 321);
			this->chartBf6->Name = L"chartBf6";
			this->chartBf6->ReadOnly = true;
			this->chartBf6->Size = System::Drawing::Size(36, 21);
			this->chartBf6->TabIndex = 75;
			// 
			// chartBf5
			// 
			this->chartBf5->BackColor = System::Drawing::Color::White;
			this->chartBf5->Location = System::Drawing::Point(299, 321);
			this->chartBf5->Name = L"chartBf5";
			this->chartBf5->ReadOnly = true;
			this->chartBf5->Size = System::Drawing::Size(36, 21);
			this->chartBf5->TabIndex = 74;
			// 
			// chartBf4
			// 
			this->chartBf4->BackColor = System::Drawing::Color::White;
			this->chartBf4->Location = System::Drawing::Point(263, 321);
			this->chartBf4->Name = L"chartBf4";
			this->chartBf4->ReadOnly = true;
			this->chartBf4->Size = System::Drawing::Size(36, 21);
			this->chartBf4->TabIndex = 73;
			// 
			// chartBf3
			// 
			this->chartBf3->BackColor = System::Drawing::Color::White;
			this->chartBf3->Location = System::Drawing::Point(227, 321);
			this->chartBf3->Name = L"chartBf3";
			this->chartBf3->ReadOnly = true;
			this->chartBf3->Size = System::Drawing::Size(36, 21);
			this->chartBf3->TabIndex = 72;
			// 
			// chartBf2
			// 
			this->chartBf2->BackColor = System::Drawing::Color::White;
			this->chartBf2->Location = System::Drawing::Point(191, 321);
			this->chartBf2->Name = L"chartBf2";
			this->chartBf2->ReadOnly = true;
			this->chartBf2->Size = System::Drawing::Size(36, 21);
			this->chartBf2->TabIndex = 71;
			// 
			// chartBf1
			// 
			this->chartBf1->BackColor = System::Drawing::Color::White;
			this->chartBf1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->chartBf1->Location = System::Drawing::Point(155, 321);
			this->chartBf1->Name = L"chartBf1";
			this->chartBf1->ReadOnly = true;
			this->chartBf1->Size = System::Drawing::Size(36, 21);
			this->chartBf1->TabIndex = 70;
			// 
			// chartAf2W16
			// 
			this->chartAf2W16->BackColor = System::Drawing::Color::White;
			this->chartAf2W16->Location = System::Drawing::Point(695, 375);
			this->chartAf2W16->Name = L"chartAf2W16";
			this->chartAf2W16->ReadOnly = true;
			this->chartAf2W16->Size = System::Drawing::Size(36, 21);
			this->chartAf2W16->TabIndex = 69;
			// 
			// chartAf2W15
			// 
			this->chartAf2W15->BackColor = System::Drawing::Color::White;
			this->chartAf2W15->Location = System::Drawing::Point(659, 375);
			this->chartAf2W15->Name = L"chartAf2W15";
			this->chartAf2W15->ReadOnly = true;
			this->chartAf2W15->Size = System::Drawing::Size(36, 21);
			this->chartAf2W15->TabIndex = 68;
			// 
			// chartAf2W14
			// 
			this->chartAf2W14->BackColor = System::Drawing::Color::White;
			this->chartAf2W14->Location = System::Drawing::Point(623, 375);
			this->chartAf2W14->Name = L"chartAf2W14";
			this->chartAf2W14->ReadOnly = true;
			this->chartAf2W14->Size = System::Drawing::Size(36, 21);
			this->chartAf2W14->TabIndex = 67;
			// 
			// chartAf2W13
			// 
			this->chartAf2W13->BackColor = System::Drawing::Color::White;
			this->chartAf2W13->Location = System::Drawing::Point(587, 375);
			this->chartAf2W13->Name = L"chartAf2W13";
			this->chartAf2W13->ReadOnly = true;
			this->chartAf2W13->Size = System::Drawing::Size(36, 21);
			this->chartAf2W13->TabIndex = 66;
			// 
			// chartAf2W12
			// 
			this->chartAf2W12->BackColor = System::Drawing::Color::White;
			this->chartAf2W12->Location = System::Drawing::Point(551, 375);
			this->chartAf2W12->Name = L"chartAf2W12";
			this->chartAf2W12->ReadOnly = true;
			this->chartAf2W12->Size = System::Drawing::Size(36, 21);
			this->chartAf2W12->TabIndex = 65;
			// 
			// chartAf2W11
			// 
			this->chartAf2W11->BackColor = System::Drawing::Color::White;
			this->chartAf2W11->Location = System::Drawing::Point(515, 375);
			this->chartAf2W11->Name = L"chartAf2W11";
			this->chartAf2W11->ReadOnly = true;
			this->chartAf2W11->Size = System::Drawing::Size(36, 21);
			this->chartAf2W11->TabIndex = 64;
			// 
			// chartAf2W10
			// 
			this->chartAf2W10->BackColor = System::Drawing::Color::White;
			this->chartAf2W10->Location = System::Drawing::Point(479, 375);
			this->chartAf2W10->Name = L"chartAf2W10";
			this->chartAf2W10->ReadOnly = true;
			this->chartAf2W10->Size = System::Drawing::Size(36, 21);
			this->chartAf2W10->TabIndex = 63;
			// 
			// chartAf2W9
			// 
			this->chartAf2W9->BackColor = System::Drawing::Color::White;
			this->chartAf2W9->Location = System::Drawing::Point(443, 375);
			this->chartAf2W9->Name = L"chartAf2W9";
			this->chartAf2W9->ReadOnly = true;
			this->chartAf2W9->Size = System::Drawing::Size(36, 21);
			this->chartAf2W9->TabIndex = 62;
			// 
			// chartAf2W8
			// 
			this->chartAf2W8->BackColor = System::Drawing::Color::White;
			this->chartAf2W8->Location = System::Drawing::Point(407, 375);
			this->chartAf2W8->Name = L"chartAf2W8";
			this->chartAf2W8->ReadOnly = true;
			this->chartAf2W8->Size = System::Drawing::Size(36, 21);
			this->chartAf2W8->TabIndex = 61;
			// 
			// chartAf2W7
			// 
			this->chartAf2W7->BackColor = System::Drawing::Color::White;
			this->chartAf2W7->Location = System::Drawing::Point(371, 375);
			this->chartAf2W7->Name = L"chartAf2W7";
			this->chartAf2W7->ReadOnly = true;
			this->chartAf2W7->Size = System::Drawing::Size(36, 21);
			this->chartAf2W7->TabIndex = 60;
			// 
			// chartAf2W6
			// 
			this->chartAf2W6->BackColor = System::Drawing::Color::White;
			this->chartAf2W6->Location = System::Drawing::Point(335, 375);
			this->chartAf2W6->Name = L"chartAf2W6";
			this->chartAf2W6->ReadOnly = true;
			this->chartAf2W6->Size = System::Drawing::Size(36, 21);
			this->chartAf2W6->TabIndex = 59;
			// 
			// chartAf2W5
			// 
			this->chartAf2W5->BackColor = System::Drawing::Color::White;
			this->chartAf2W5->Location = System::Drawing::Point(299, 375);
			this->chartAf2W5->Name = L"chartAf2W5";
			this->chartAf2W5->ReadOnly = true;
			this->chartAf2W5->Size = System::Drawing::Size(36, 21);
			this->chartAf2W5->TabIndex = 58;
			// 
			// chartAf2W4
			// 
			this->chartAf2W4->BackColor = System::Drawing::Color::White;
			this->chartAf2W4->Location = System::Drawing::Point(263, 375);
			this->chartAf2W4->Name = L"chartAf2W4";
			this->chartAf2W4->ReadOnly = true;
			this->chartAf2W4->Size = System::Drawing::Size(36, 21);
			this->chartAf2W4->TabIndex = 57;
			// 
			// chartAf2W3
			// 
			this->chartAf2W3->BackColor = System::Drawing::Color::White;
			this->chartAf2W3->Location = System::Drawing::Point(227, 375);
			this->chartAf2W3->Name = L"chartAf2W3";
			this->chartAf2W3->ReadOnly = true;
			this->chartAf2W3->Size = System::Drawing::Size(36, 21);
			this->chartAf2W3->TabIndex = 56;
			// 
			// chartAf2W2
			// 
			this->chartAf2W2->BackColor = System::Drawing::Color::White;
			this->chartAf2W2->Location = System::Drawing::Point(191, 375);
			this->chartAf2W2->Name = L"chartAf2W2";
			this->chartAf2W2->ReadOnly = true;
			this->chartAf2W2->Size = System::Drawing::Size(36, 21);
			this->chartAf2W2->TabIndex = 55;
			// 
			// chartAf2W1
			// 
			this->chartAf2W1->BackColor = System::Drawing::Color::White;
			this->chartAf2W1->Location = System::Drawing::Point(155, 375);
			this->chartAf2W1->Name = L"chartAf2W1";
			this->chartAf2W1->ReadOnly = true;
			this->chartAf2W1->Size = System::Drawing::Size(36, 21);
			this->chartAf2W1->TabIndex = 54;
			// 
			// chartAf16
			// 
			this->chartAf16->BackColor = System::Drawing::Color::White;
			this->chartAf16->Location = System::Drawing::Point(695, 348);
			this->chartAf16->Name = L"chartAf16";
			this->chartAf16->ReadOnly = true;
			this->chartAf16->Size = System::Drawing::Size(36, 21);
			this->chartAf16->TabIndex = 53;
			// 
			// chartAf15
			// 
			this->chartAf15->BackColor = System::Drawing::Color::White;
			this->chartAf15->Location = System::Drawing::Point(659, 348);
			this->chartAf15->Name = L"chartAf15";
			this->chartAf15->ReadOnly = true;
			this->chartAf15->Size = System::Drawing::Size(36, 21);
			this->chartAf15->TabIndex = 52;
			// 
			// chartAf14
			// 
			this->chartAf14->BackColor = System::Drawing::Color::White;
			this->chartAf14->Location = System::Drawing::Point(623, 348);
			this->chartAf14->Name = L"chartAf14";
			this->chartAf14->ReadOnly = true;
			this->chartAf14->Size = System::Drawing::Size(36, 21);
			this->chartAf14->TabIndex = 51;
			// 
			// chartAf13
			// 
			this->chartAf13->BackColor = System::Drawing::Color::White;
			this->chartAf13->Location = System::Drawing::Point(587, 348);
			this->chartAf13->Name = L"chartAf13";
			this->chartAf13->ReadOnly = true;
			this->chartAf13->Size = System::Drawing::Size(36, 21);
			this->chartAf13->TabIndex = 50;
			// 
			// chartAf12
			// 
			this->chartAf12->BackColor = System::Drawing::Color::White;
			this->chartAf12->Location = System::Drawing::Point(551, 348);
			this->chartAf12->Name = L"chartAf12";
			this->chartAf12->ReadOnly = true;
			this->chartAf12->Size = System::Drawing::Size(36, 21);
			this->chartAf12->TabIndex = 49;
			// 
			// chartAf11
			// 
			this->chartAf11->BackColor = System::Drawing::Color::White;
			this->chartAf11->Location = System::Drawing::Point(515, 348);
			this->chartAf11->Name = L"chartAf11";
			this->chartAf11->ReadOnly = true;
			this->chartAf11->Size = System::Drawing::Size(36, 21);
			this->chartAf11->TabIndex = 48;
			// 
			// chartAf10
			// 
			this->chartAf10->BackColor = System::Drawing::Color::White;
			this->chartAf10->Location = System::Drawing::Point(479, 348);
			this->chartAf10->Name = L"chartAf10";
			this->chartAf10->ReadOnly = true;
			this->chartAf10->Size = System::Drawing::Size(36, 21);
			this->chartAf10->TabIndex = 47;
			// 
			// chartAf9
			// 
			this->chartAf9->BackColor = System::Drawing::Color::White;
			this->chartAf9->Location = System::Drawing::Point(443, 348);
			this->chartAf9->Name = L"chartAf9";
			this->chartAf9->ReadOnly = true;
			this->chartAf9->Size = System::Drawing::Size(36, 21);
			this->chartAf9->TabIndex = 46;
			// 
			// chartAf8
			// 
			this->chartAf8->BackColor = System::Drawing::Color::White;
			this->chartAf8->Location = System::Drawing::Point(407, 348);
			this->chartAf8->Name = L"chartAf8";
			this->chartAf8->ReadOnly = true;
			this->chartAf8->Size = System::Drawing::Size(36, 21);
			this->chartAf8->TabIndex = 45;
			// 
			// chartAf7
			// 
			this->chartAf7->BackColor = System::Drawing::Color::White;
			this->chartAf7->Location = System::Drawing::Point(371, 348);
			this->chartAf7->Name = L"chartAf7";
			this->chartAf7->ReadOnly = true;
			this->chartAf7->Size = System::Drawing::Size(36, 21);
			this->chartAf7->TabIndex = 44;
			// 
			// chartAf6
			// 
			this->chartAf6->BackColor = System::Drawing::Color::White;
			this->chartAf6->ForeColor = System::Drawing::SystemColors::WindowText;
			this->chartAf6->Location = System::Drawing::Point(335, 348);
			this->chartAf6->Name = L"chartAf6";
			this->chartAf6->ReadOnly = true;
			this->chartAf6->Size = System::Drawing::Size(36, 21);
			this->chartAf6->TabIndex = 43;
			// 
			// chartAf5
			// 
			this->chartAf5->BackColor = System::Drawing::Color::White;
			this->chartAf5->Location = System::Drawing::Point(299, 348);
			this->chartAf5->Name = L"chartAf5";
			this->chartAf5->ReadOnly = true;
			this->chartAf5->Size = System::Drawing::Size(36, 21);
			this->chartAf5->TabIndex = 42;
			// 
			// chartAf4
			// 
			this->chartAf4->BackColor = System::Drawing::Color::White;
			this->chartAf4->Location = System::Drawing::Point(263, 348);
			this->chartAf4->Name = L"chartAf4";
			this->chartAf4->ReadOnly = true;
			this->chartAf4->Size = System::Drawing::Size(36, 21);
			this->chartAf4->TabIndex = 41;
			// 
			// chartAf3
			// 
			this->chartAf3->BackColor = System::Drawing::Color::White;
			this->chartAf3->Location = System::Drawing::Point(227, 348);
			this->chartAf3->Name = L"chartAf3";
			this->chartAf3->ReadOnly = true;
			this->chartAf3->Size = System::Drawing::Size(36, 21);
			this->chartAf3->TabIndex = 40;
			// 
			// chartAf2
			// 
			this->chartAf2->BackColor = System::Drawing::Color::White;
			this->chartAf2->Location = System::Drawing::Point(191, 348);
			this->chartAf2->Name = L"chartAf2";
			this->chartAf2->ReadOnly = true;
			this->chartAf2->Size = System::Drawing::Size(36, 21);
			this->chartAf2->TabIndex = 39;
			// 
			// chartAf1
			// 
			this->chartAf1->BackColor = System::Drawing::Color::White;
			this->chartAf1->Location = System::Drawing::Point(155, 348);
			this->chartAf1->Name = L"chartAf1";
			this->chartAf1->ReadOnly = true;
			this->chartAf1->Size = System::Drawing::Size(36, 21);
			this->chartAf1->TabIndex = 38;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->ForeColor = System::Drawing::Color::Blue;
			this->label17->Location = System::Drawing::Point(52, 380);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(98, 15);
			this->label17->TabIndex = 37;
			this->label17->Text = L"After 2 Weeks:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::Color::Blue;
			this->label16->Location = System::Drawing::Point(52, 352);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(40, 15);
			this->label16->TabIndex = 36;
			this->label16->Text = L"After:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ForeColor = System::Drawing::Color::Blue;
			this->label15->Location = System::Drawing::Point(52, 323);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(53, 15);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Before:";
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(152, 247);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(580, 70);
			this->pictureBox5->TabIndex = 31;
			this->pictureBox5->TabStop = false;
			// 
			// picLogo
			// 
			this->picLogo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picLogo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picLogo.Image")));
			this->picLogo->Location = System::Drawing::Point(598, 12);
			this->picLogo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picLogo->Name = L"picLogo";
			this->picLogo->Size = System::Drawing::Size(195, 90);
			this->picLogo->TabIndex = 32;
			this->picLogo->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->groupBox4);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(222)));
			this->panel1->Location = System::Drawing::Point(12, 4);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(577, 206);
			this->panel1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->txtLName);
			this->groupBox4->Controls->Add(this->txtName);
			this->groupBox4->Controls->Add(this->txtSNNum);
			this->groupBox4->Controls->Add(this->gender);
			this->groupBox4->Controls->Add(this->label22);
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->datebirth);
			this->groupBox4->Controls->Add(this->label20);
			this->groupBox4->Controls->Add(this->label19);
			this->groupBox4->Controls->Add(this->label18);
			this->groupBox4->ForeColor = System::Drawing::Color::Blue;
			this->groupBox4->Location = System::Drawing::Point(7, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(228, 193);
			this->groupBox4->TabIndex = 30;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Profile";
			// 
			// txtLName
			// 
			this->txtLName->ForeColor = System::Drawing::Color::Blue;
			this->txtLName->Location = System::Drawing::Point(97, 90);
			this->txtLName->Name = L"txtLName";
			this->txtLName->Size = System::Drawing::Size(120, 21);
			this->txtLName->TabIndex = 9;
			// 
			// txtName
			// 
			this->txtName->ForeColor = System::Drawing::Color::Blue;
			this->txtName->Location = System::Drawing::Point(97, 56);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(120, 21);
			this->txtName->TabIndex = 8;
			// 
			// txtSNNum
			// 
			this->txtSNNum->ForeColor = System::Drawing::Color::Blue;
			this->txtSNNum->Location = System::Drawing::Point(97, 22);
			this->txtSNNum->Name = L"txtSNNum";
			this->txtSNNum->Size = System::Drawing::Size(120, 21);
			this->txtSNNum->TabIndex = 7;
			// 
			// gender
			// 
			this->gender->ForeColor = System::Drawing::Color::Blue;
			this->gender->FormattingEnabled = true;
			this->gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Male", L"Female"});
			this->gender->Location = System::Drawing::Point(97, 161);
			this->gender->Name = L"gender";
			this->gender->Size = System::Drawing::Size(120, 23);
			this->gender->TabIndex = 6;
			this->gender->Text = L"Male";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(6, 169);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(58, 15);
			this->label22->TabIndex = 5;
			this->label22->Text = L"Gender:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(4, 132);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(91, 15);
			this->label21->TabIndex = 4;
			this->label21->Text = L"Date of Birth:";
			// 
			// datebirth
			// 
			this->datebirth->CalendarForeColor = System::Drawing::Color::Blue;
			this->datebirth->CalendarMonthBackground = System::Drawing::Color::Blue;
			this->datebirth->CalendarTitleBackColor = System::Drawing::Color::Blue;
			this->datebirth->CalendarTitleForeColor = System::Drawing::Color::Blue;
			this->datebirth->CalendarTrailingForeColor = System::Drawing::Color::Blue;
			this->datebirth->CustomFormat = L"dd/MM/yyyy";
			this->datebirth->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datebirth->Location = System::Drawing::Point(97, 127);
			this->datebirth->Name = L"datebirth";
			this->datebirth->Size = System::Drawing::Size(120, 21);
			this->datebirth->TabIndex = 3;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 96);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(80, 15);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Last Name:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 59);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(49, 15);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Name:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 22);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(39, 15);
			this->label18->TabIndex = 0;
			this->label18->Text = L"H.N.:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->picBefore);
			this->groupBox1->Controls->Add(this->inputVitaCode);
			this->groupBox1->Controls->Add(this->inputAValue);
			this->groupBox1->Controls->Add(this->selLAB);
			this->groupBox1->Controls->Add(this->inputBValue);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->inputLValue);
			this->groupBox1->Controls->Add(this->selVita);
			this->groupBox1->ForeColor = System::Drawing::Color::Blue;
			this->groupBox1->Location = System::Drawing::Point(242, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(324, 193);
			this->groupBox1->TabIndex = 29;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Before";
			// 
			// picBefore
			// 
			this->picBefore->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picBefore->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picBefore.Image")));
			this->picBefore->Location = System::Drawing::Point(133, 56);
			this->picBefore->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picBefore->Name = L"picBefore";
			this->picBefore->Size = System::Drawing::Size(185, 80);
			this->picBefore->TabIndex = 15;
			this->picBefore->TabStop = false;
			// 
			// inputVitaCode
			// 
			this->inputVitaCode->ForeColor = System::Drawing::Color::Blue;
			this->inputVitaCode->FormattingEnabled = true;
			this->inputVitaCode->Items->AddRange(gcnew cli::array< System::Object^  >(16) {L"B1", L"A1", L"B2", L"D2", L"A2", L"C1", L"C2", 
				L"D4", L"A3", L"D3", L"B3", L"A3.5", L"B4", L"C3", L"A4", L"C4"});
			this->inputVitaCode->Location = System::Drawing::Point(244, 161);
			this->inputVitaCode->Name = L"inputVitaCode";
			this->inputVitaCode->Size = System::Drawing::Size(69, 23);
			this->inputVitaCode->TabIndex = 28;
			this->inputVitaCode->Text = L"C4";
			this->inputVitaCode->SelectedIndexChanged += gcnew System::EventHandler(this, &ToothShadePredict::inputVitaCode_SelectedIndexChanged);
			// 
			// inputAValue
			// 
			this->inputAValue->DecimalPlaces = 2;
			this->inputAValue->ForeColor = System::Drawing::Color::Blue;
			this->inputAValue->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->inputAValue->Location = System::Drawing::Point(17, 104);
			this->inputAValue->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->inputAValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->inputAValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, System::Int32::MinValue});
			this->inputAValue->Name = L"inputAValue";
			this->inputAValue->Size = System::Drawing::Size(65, 21);
			this->inputAValue->TabIndex = 23;
			// 
			// selLAB
			// 
			this->selLAB->AutoSize = true;
			this->selLAB->Checked = true;
			this->selLAB->ForeColor = System::Drawing::Color::Blue;
			this->selLAB->Location = System::Drawing::Point(10, 18);
			this->selLAB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->selLAB->Name = L"selLAB";
			this->selLAB->Size = System::Drawing::Size(109, 19);
			this->selLAB->TabIndex = 17;
			this->selLAB->TabStop = true;
			this->selLAB->Text = L"L,a,b Method";
			this->selLAB->UseVisualStyleBackColor = true;
			this->selLAB->CheckedChanged += gcnew System::EventHandler(this, &ToothShadePredict::selLAB_CheckedChanged);
			// 
			// inputBValue
			// 
			this->inputBValue->DecimalPlaces = 2;
			this->inputBValue->ForeColor = System::Drawing::Color::Blue;
			this->inputBValue->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->inputBValue->Location = System::Drawing::Point(17, 149);
			this->inputBValue->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->inputBValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->inputBValue->Name = L"inputBValue";
			this->inputBValue->Size = System::Drawing::Size(65, 21);
			this->inputBValue->TabIndex = 24;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(11, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 15);
			this->label3->TabIndex = 26;
			this->label3->Text = L"a:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Blue;
			this->label4->Location = System::Drawing::Point(11, 133);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 15);
			this->label4->TabIndex = 27;
			this->label4->Text = L"b:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Blue;
			this->label2->Location = System::Drawing::Point(11, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 15);
			this->label2->TabIndex = 25;
			this->label2->Text = L"L:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(156, 164);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 21;
			this->label1->Text = L"VITA-CODE:";
			// 
			// inputLValue
			// 
			this->inputLValue->DecimalPlaces = 2;
			this->inputLValue->ForeColor = System::Drawing::Color::Blue;
			this->inputLValue->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->inputLValue->Location = System::Drawing::Point(17, 60);
			this->inputLValue->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->inputLValue->Name = L"inputLValue";
			this->inputLValue->Size = System::Drawing::Size(65, 21);
			this->inputLValue->TabIndex = 22;
			// 
			// selVita
			// 
			this->selVita->AutoSize = true;
			this->selVita->ForeColor = System::Drawing::Color::Blue;
			this->selVita->Location = System::Drawing::Point(128, 18);
			this->selVita->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->selVita->Name = L"selVita";
			this->selVita->Size = System::Drawing::Size(146, 19);
			this->selVita->TabIndex = 18;
			this->selVita->Text = L"Vita Shade Method";
			this->selVita->UseVisualStyleBackColor = true;
			this->selVita->CheckedChanged += gcnew System::EventHandler(this, &ToothShadePredict::selVita_CheckedChanged);
			// 
			// ToothShadePredict
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(804, 642);
			this->Controls->Add(this->picLogo);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"ToothShadePredict";
			this->Text = L"ToothColorPredictor";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picAfter))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picAfter2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLogo))->EndInit();
			this->panel1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBefore))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputAValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputBValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputLValue))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		void MarshalString ( String ^ s, string& os ) {
		   using namespace Runtime::InteropServices;
		   const char* chars = 
			  (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		   os = chars;
		   Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void MarshalString ( String ^ s, wstring& os ) {
		   using namespace Runtime::InteropServices;
		   const wchar_t* chars = 
			  (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		   os = chars;
		   Marshal::FreeHGlobal(IntPtr((void*)chars));
		}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			

			 LogData tmpData ;
			 DateTime dateTime = DateTime::Now ;
			 float lBf , aBf , bBf ;

			 // Profile
			 MarshalString(this->txtSNNum->Text->ToString(),tmpData.sn_number);
			 MarshalString(this->txtName->Text->ToString(),tmpData.name);
			 MarshalString(this->txtLName->Text->ToString(),tmpData.lastname);
			 MarshalString(this->datebirth->Value.Date.ToShortDateString(),tmpData.dateBirth);
			 MarshalString(this->gender->Text->ToString(),tmpData.gender);	
			 MarshalString(dateTime.Date.ToShortDateString(),tmpData.timeStamp);



			 /*Console::WriteLine("----Profile Person");
			 Console::WriteLine(this->txtSNNum->Text->ToString());
			 Console::WriteLine(this->txtName->Text->ToString());
			 Console::WriteLine(this->txtLName->Text->ToString());
			 Console::WriteLine(this->datebirth->Value.Date.ToLongDateString());
			 Console::WriteLine(this->gender->Text->ToString());
			 Console::WriteLine(dateTime.Date.ToLongDateString());*/
			
			 // --- Before Input Data Predictor --- //

			 ToothShadePredictor *tsp = new ToothShadePredictor() ;
			 intf->InitialDataProcess(*tsp);

			 if(intf->getMethod() == LAB_METHOD)
			 {
					//--- L , a , b Before set none VitaCode 
				 MarshalString(this->inputLValue->Text->ToString(),tmpData.lBf);
				 MarshalString(this->inputAValue->Text->ToString(),tmpData.aBf);
				 MarshalString(this->inputBValue->Text->ToString(),tmpData.bBf);
				 MarshalString(NO_INPUT,tmpData.vitaBf);
				 	
				 /*Console::WriteLine("----Before Data:");
				 Console::WriteLine(this->inputLValue->Text->ToString());
				 Console::WriteLine(this->inputAValue->Text->ToString());
				 Console::WriteLine(this->inputBValue->Text->ToString());
				 Console::WriteLine(NO_INPUT);*/
				 
				 
				 lBf = (float)Double::Parse(this->inputLValue->Text,System::Globalization::NumberStyles::Float);
				 aBf = (float)Double::Parse(this->inputAValue->Text,System::Globalization::NumberStyles::Float);
				 bBf = (float)Double::Parse(this->inputBValue->Text,System::Globalization::NumberStyles::Float);
				//  intf->setInptL_a_b(77.1,-0.5f,16.8f);
				 intf->setInptL_a_b(lBf,aBf,bBf);

			 }
			 else if(intf->getMethod() == VITA_METHOD)
			 {
					//--- VitaCode Before set none L , a ,b 
				 //--- L , a , b Before set none VitaCode 
				 tmpData.vitaBf = "NULL";
				 MarshalString(NO_INPUT,tmpData.lBf);
				 MarshalString(NO_INPUT,tmpData.aBf);
				 MarshalString(NO_INPUT,tmpData.bBf);
				 MarshalString(this->inputVitaCode->Text->ToString(),tmpData.vitaBf);

				 if(this->inputVitaCode->Text->Trim() != "")
				 {
					 /*Console::WriteLine("----Before Data:");
					 Console::WriteLine(NO_INPUT);
					 Console::WriteLine(NO_INPUT);
					 Console::WriteLine(NO_INPUT);
					 Console::WriteLine(this->inputVitaCode->Text->ToString());*/
					 
					 intf->setInputVitaCode(tmpData.vitaBf);
				 }
				 	
				

				
			 }

			 

			 delete tsp;

			 if(this->inputVitaCode->Text->Trim() != "")
			 {

				 // --- After Data Output --- //
				 double tmpL = atof(intf->outputLAfter().c_str());
				 double tmpA = atof(intf->outputAAfter().c_str());
				 double tmpB = atof(intf->outputBAfter().c_str());
				 double tmpDE = atof(intf->outputDEAfter().c_str());
				 char lDigit[10] , aDigit[10] , bDigit[10] , deAfter[10] ;
				 sprintf(lDigit,"%.2f",tmpL);
				 sprintf(aDigit,"%.2f",tmpA);
				 sprintf(bDigit,"%.2f",tmpB);
				 sprintf(deAfter,"%.2f",tmpDE);

				 String ^getLAfter  = gcnew String(lDigit);
				 String ^getAAfter  = gcnew String(aDigit);
				 String ^getBAfter  = gcnew String(bDigit);
				 String ^getDEAfter = gcnew String(deAfter);
				 String ^getViAfter = gcnew String(intf->outputVitaAfter().c_str());

				 lAfter->Text = getLAfter ;
				 aAfter->Text = getAAfter ;
				 bAfter->Text = getBAfter ;
				 deltaEAfter->Text = getDEAfter ; 
				 vitaOutAfter->Text = getViAfter ;

				 MarshalString(getLAfter,tmpData.lAf);
				 MarshalString(getAAfter,tmpData.aAf);
				 MarshalString(getBAfter,tmpData.bAf);
				 MarshalString(getDEAfter,tmpData.deAf);
				 MarshalString(getViAfter,tmpData.vitaAf);
				 

				 // --- After 2 Weeks Output --- //
				 double tmpL2 = atof(intf->outputLAfter2Week().c_str());
				 double tmpA2 = atof(intf->outputAAfter2Week().c_str());
				 double tmpB2 = atof(intf->outputBAfter2Week().c_str());
				 double tmpDE2 = atof(intf->outputDEAfter2Week().c_str());
				 char lDigit2[10] , aDigit2[10] , bDigit2[10] , deAfter2[10] ;
				 sprintf(lDigit2,"%.2f",tmpL2);
				 sprintf(aDigit2,"%.2f",tmpA2);
				 sprintf(bDigit2,"%.2f",tmpB2);
				 sprintf(deAfter2,"%.2f",tmpDE2);

				 String ^getLAfter2  = gcnew String(lDigit2);
				 String ^getAAfter2  = gcnew String(aDigit2);
				 String ^getBAfter2  = gcnew String(bDigit2);
				 String ^getDEAfter2 = gcnew String(deAfter2);
				 String ^getViAfter2 = gcnew String(intf->outputVitaAfter2Week().c_str());
				 lAfter2->Text = getLAfter2 ;
				 aAfter2->Text = getAAfter2 ;
				 bAfter2->Text = getBAfter2 ;
				 deltaEAfter2->Text = getDEAfter2 ; 
				 vitaOutAfter2->Text = getViAfter2 ;

				 MarshalString(getLAfter2,tmpData.lAf2);
				 MarshalString(getAAfter2,tmpData.aAf2);
				 MarshalString(getBAfter2,tmpData.bAf2);
				 MarshalString(getDEAfter2,tmpData.deAf2);
				 MarshalString(getViAfter2,tmpData.vitaAf2);


				 // Show Shade Level --- //
				 this->paintShadeLevel();

				 // --- Change Image Output --- //
				 String ^pathImgAfter = IMG_FOLDER+getViAfter+".jpg" ;
				 this->picAfter->Image = Image::FromFile(pathImgAfter);
				 String ^pathImgAfter2 = IMG_FOLDER+getViAfter2+".jpg" ;
				 this->picAfter2->Image = Image::FromFile(pathImgAfter2);

				 Console::WriteLine(this->chkLog->Checked);

				 // --- Save Log File --- //
				 if(this->chkLog->Checked == true)
				 {
					 string getPath ;
					 MarshalString(this->pathFileSave,getPath);
					 this->logger->writeLog(&tmpData,getPath);
					 //Console::WriteLine(this->pathFileSave);
				 }
					

				 
			 }

		 }


private: System::Void selLAB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 intf->setMethod(LAB_METHOD);

			 // --- disable vita method && enable l,a,b method--- //
			 this->inputLValue->Enabled = true ;
			 this->inputAValue->Enabled = true ;
			 this->inputBValue->Enabled = true ;
			 this->inputVitaCode->Enabled = false ;

		 }
private: System::Void selVita_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 intf->setMethod(VITA_METHOD);

			 // --- enable vita method && disble l,a,b method--- //
			 this->inputLValue->Enabled = false ;
			 this->inputAValue->Enabled = false ;
			 this->inputBValue->Enabled = false ;
			 this->inputVitaCode->Enabled = true ;
		 }
private: System::Void inputVitaCode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {


			 String ^pathImg = IMG_FOLDER+this->inputVitaCode->Text->ToString()+".jpg" ;
			 this->picBefore->Image = Image::FromFile(pathImg);
			 

		 }
private: System::Void chkLog_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 
			 if(this->chkLog->Checked == true)
			 {
				 this->saveFileDialog->Filter = "csv files (*.csv)|*.csv|All files (*.*)|*.*";
				 this->saveFileDialog->FilterIndex = 1;
				 this->saveFileDialog->RestoreDirectory = true;

				 if( this->saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 string fileName ;
					 MarshalString(this->saveFileDialog->FileName,fileName);
					 Stream^ myStream;

					 if ( this->FileExists(fileName) )  
					 {
						 if( (myStream = this->saveFileDialog->OpenFile()) != nullptr )
						 {

							// Code to write the stream goes here.
							 MessageBox::Show(this->saveFileDialog->FileName+"\r\n\tCreate and Save Data File Complete.");
							 myStream->Close();
							 this->pathFileSave = this->saveFileDialog->FileName ;
						 }
					 }
					 else
					 {
						 if ( (myStream = this->saveFileDialog->OpenFile()) != nullptr )
						 {
							// Code to write the stream goes here.
							 MessageBox::Show(this->saveFileDialog->FileName+"\r\n\tCreate and Save Data File Complete.");
							 myStream->Close();
							 this->pathFileSave = this->saveFileDialog->FileName ;
						 }
					 }
					 
					 // write the code using the Append function
					 //MessageBox::Show( "OK" );
				 }
				 else
				 {
					 this->chkLog->Checked = false ;
					
				 }
				 

			 }
		 }
};
}

