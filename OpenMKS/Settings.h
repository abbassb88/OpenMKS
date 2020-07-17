#pragma once
#include "io.h"

namespace OpenMKS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_NeighborsNB;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_OK;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshSS_Av;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_NormalSize;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_PointSize;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_FilterThresh;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeanK;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshSS_Samples;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshSS_NN;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RadioButton^ radioButton_MeshSpaceScale;

	private: System::Windows::Forms::RadioButton^ radioButton_MeshPoisson;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshP_TSize;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshP_Angle;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshP_NN;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_MeshP_Error;


	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_FrameNumber;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_UpSampling;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_Interpolation;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_SelectPointSize;


	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_SquareSize;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::CheckBox^ checkBox_CB_Auto_Size;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_CBW;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_CBH;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_toleranceCB;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::CheckBox^ checkBox_Online;
	private: System::Windows::Forms::RadioButton^ radioButton_MeshCombinedAlgorithm;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_PolyRegression;
	private: System::Windows::Forms::Label^ label22;



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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_NeighborsNB = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_MeshCombinedAlgorithm = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown_MeshP_Error = (gcnew System::Windows::Forms::NumericUpDown());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeshP_TSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeshP_Angle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeshP_NN = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->radioButton_MeshSpaceScale = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_MeshPoisson = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown_MeshSS_Samples = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeshSS_NN = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeshSS_Av = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_SelectPointSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_NormalSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_PointSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_FilterThresh = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_MeanK = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_FrameNumber = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_Interpolation = (gcnew System::Windows::Forms::NumericUpDown());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_UpSampling = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_SquareSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_toleranceCB = (gcnew System::Windows::Forms::NumericUpDown());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->checkBox_CB_Auto_Size = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown_CBW = (gcnew System::Windows::Forms::NumericUpDown());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_CBH = (gcnew System::Windows::Forms::NumericUpDown());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_Online = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_PolyRegression = (gcnew System::Windows::Forms::NumericUpDown());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NeighborsNB))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_Error))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_TSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_Angle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_NN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_Samples))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_NN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_Av))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SelectPointSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NormalSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PointSize))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FilterThresh))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeanK))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FrameNumber))->BeginInit();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Interpolation))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_UpSampling))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SquareSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_toleranceCB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CBW))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CBH))->BeginInit();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PolyRegression))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numericUpDown_NeighborsNB);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 183);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(294, 60);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Normals Estimation";
			// 
			// numericUpDown_NeighborsNB
			// 
			this->numericUpDown_NeighborsNB->Location = System::Drawing::Point(213, 24);
			this->numericUpDown_NeighborsNB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_NeighborsNB->Name = L"numericUpDown_NeighborsNB";
			this->numericUpDown_NeighborsNB->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_NeighborsNB->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Neighbors Number:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->button_OK);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 764);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(614, 40);
			this->panel1->TabIndex = 1;
			// 
			// button_OK
			// 
			this->button_OK->Location = System::Drawing::Point(542, 7);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(64, 25);
			this->button_OK->TabIndex = 0;
			this->button_OK->Text = L"OK";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &Settings::Button_OK_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton_MeshCombinedAlgorithm);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshP_Error);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshP_TSize);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshP_Angle);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshP_NN);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->radioButton_MeshSpaceScale);
			this->groupBox2->Controls->Add(this->radioButton_MeshPoisson);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshSS_Samples);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshSS_NN);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->numericUpDown_MeshSS_Av);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(12, 249);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(590, 209);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Mesh Creation";
			// 
			// radioButton_MeshCombinedAlgorithm
			// 
			this->radioButton_MeshCombinedAlgorithm->AutoSize = true;
			this->radioButton_MeshCombinedAlgorithm->Checked = true;
			this->radioButton_MeshCombinedAlgorithm->Location = System::Drawing::Point(22, 30);
			this->radioButton_MeshCombinedAlgorithm->Name = L"radioButton_MeshCombinedAlgorithm";
			this->radioButton_MeshCombinedAlgorithm->Size = System::Drawing::Size(155, 21);
			this->radioButton_MeshCombinedAlgorithm->TabIndex = 16;
			this->radioButton_MeshCombinedAlgorithm->TabStop = true;
			this->radioButton_MeshCombinedAlgorithm->Text = L"Combined Algorithm";
			this->radioButton_MeshCombinedAlgorithm->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_MeshP_Error
			// 
			this->numericUpDown_MeshP_Error->DecimalPlaces = 3;
			this->numericUpDown_MeshP_Error->Location = System::Drawing::Point(490, 179);
			this->numericUpDown_MeshP_Error->Name = L"numericUpDown_MeshP_Error";
			this->numericUpDown_MeshP_Error->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_MeshP_Error->TabIndex = 15;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(321, 179);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(44, 17);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Error:";
			// 
			// numericUpDown_MeshP_TSize
			// 
			this->numericUpDown_MeshP_TSize->DecimalPlaces = 3;
			this->numericUpDown_MeshP_TSize->Location = System::Drawing::Point(490, 151);
			this->numericUpDown_MeshP_TSize->Name = L"numericUpDown_MeshP_TSize";
			this->numericUpDown_MeshP_TSize->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_MeshP_TSize->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(321, 151);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(95, 17);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Triangle Size:";
			// 
			// numericUpDown_MeshP_Angle
			// 
			this->numericUpDown_MeshP_Angle->Location = System::Drawing::Point(490, 123);
			this->numericUpDown_MeshP_Angle->Name = L"numericUpDown_MeshP_Angle";
			this->numericUpDown_MeshP_Angle->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_MeshP_Angle->TabIndex = 11;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(321, 123);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 17);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Smooth Angle:";
			// 
			// numericUpDown_MeshP_NN
			// 
			this->numericUpDown_MeshP_NN->Location = System::Drawing::Point(490, 95);
			this->numericUpDown_MeshP_NN->Name = L"numericUpDown_MeshP_NN";
			this->numericUpDown_MeshP_NN->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_MeshP_NN->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(321, 95);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(131, 17);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Neighbors Number:";
			// 
			// radioButton_MeshSpaceScale
			// 
			this->radioButton_MeshSpaceScale->AutoSize = true;
			this->radioButton_MeshSpaceScale->Location = System::Drawing::Point(22, 66);
			this->radioButton_MeshSpaceScale->Name = L"radioButton_MeshSpaceScale";
			this->radioButton_MeshSpaceScale->Size = System::Drawing::Size(172, 21);
			this->radioButton_MeshSpaceScale->TabIndex = 7;
			this->radioButton_MeshSpaceScale->Text = L"Space-Scale Algorithm";
			this->radioButton_MeshSpaceScale->UseVisualStyleBackColor = true;
			// 
			// radioButton_MeshPoisson
			// 
			this->radioButton_MeshPoisson->AutoSize = true;
			this->radioButton_MeshPoisson->Location = System::Drawing::Point(322, 66);
			this->radioButton_MeshPoisson->Name = L"radioButton_MeshPoisson";
			this->radioButton_MeshPoisson->Size = System::Drawing::Size(134, 21);
			this->radioButton_MeshPoisson->TabIndex = 6;
			this->radioButton_MeshPoisson->Text = L"Poisson Algrithm";
			this->radioButton_MeshPoisson->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_MeshSS_Samples
			// 
			this->numericUpDown_MeshSS_Samples->Location = System::Drawing::Point(213, 152);
			this->numericUpDown_MeshSS_Samples->Name = L"numericUpDown_MeshSS_Samples";
			this->numericUpDown_MeshSS_Samples->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_MeshSS_Samples->TabIndex = 5;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(19, 152);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Samples";
			// 
			// numericUpDown_MeshSS_NN
			// 
			this->numericUpDown_MeshSS_NN->Location = System::Drawing::Point(213, 124);
			this->numericUpDown_MeshSS_NN->Name = L"numericUpDown_MeshSS_NN";
			this->numericUpDown_MeshSS_NN->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_MeshSS_NN->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 124);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(131, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Neighbors Number:";
			// 
			// numericUpDown_MeshSS_Av
			// 
			this->numericUpDown_MeshSS_Av->Location = System::Drawing::Point(213, 96);
			this->numericUpDown_MeshSS_Av->Name = L"numericUpDown_MeshSS_Av";
			this->numericUpDown_MeshSS_Av->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_MeshSS_Av->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(188, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Average Sparing Parameter:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->numericUpDown_SelectPointSize);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->numericUpDown_NormalSize);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->numericUpDown_PointSize);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(12, 66);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(294, 109);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"PointCloud Display";
			// 
			// numericUpDown_SelectPointSize
			// 
			this->numericUpDown_SelectPointSize->DecimalPlaces = 1;
			this->numericUpDown_SelectPointSize->Location = System::Drawing::Point(190, 54);
			this->numericUpDown_SelectPointSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_SelectPointSize->Name = L"numericUpDown_SelectPointSize";
			this->numericUpDown_SelectPointSize->Size = System::Drawing::Size(70, 22);
			this->numericUpDown_SelectPointSize->TabIndex = 5;
			this->numericUpDown_SelectPointSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(19, 54);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(137, 17);
			this->label16->TabIndex = 4;
			this->label16->Text = L"Selection Point Size:";
			// 
			// numericUpDown_NormalSize
			// 
			this->numericUpDown_NormalSize->DecimalPlaces = 3;
			this->numericUpDown_NormalSize->Location = System::Drawing::Point(190, 82);
			this->numericUpDown_NormalSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_NormalSize->Name = L"numericUpDown_NormalSize";
			this->numericUpDown_NormalSize->Size = System::Drawing::Size(70, 22);
			this->numericUpDown_NormalSize->TabIndex = 3;
			this->numericUpDown_NormalSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 196608 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 82);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 17);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Normal Size:";
			// 
			// numericUpDown_PointSize
			// 
			this->numericUpDown_PointSize->DecimalPlaces = 1;
			this->numericUpDown_PointSize->Location = System::Drawing::Point(190, 26);
			this->numericUpDown_PointSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_PointSize->Name = L"numericUpDown_PointSize";
			this->numericUpDown_PointSize->Size = System::Drawing::Size(70, 22);
			this->numericUpDown_PointSize->TabIndex = 1;
			this->numericUpDown_PointSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 17);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Cloud Point Size:";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown_FilterThresh);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->numericUpDown_MeanK);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Location = System::Drawing::Point(312, 71);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(294, 104);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"PointCloud Filter";
			// 
			// numericUpDown_FilterThresh
			// 
			this->numericUpDown_FilterThresh->DecimalPlaces = 1;
			this->numericUpDown_FilterThresh->Location = System::Drawing::Point(190, 64);
			this->numericUpDown_FilterThresh->Name = L"numericUpDown_FilterThresh";
			this->numericUpDown_FilterThresh->Size = System::Drawing::Size(70, 22);
			this->numericUpDown_FilterThresh->TabIndex = 1;
			this->numericUpDown_FilterThresh->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Threshold:";
			// 
			// numericUpDown_MeanK
			// 
			this->numericUpDown_MeanK->DecimalPlaces = 1;
			this->numericUpDown_MeanK->Location = System::Drawing::Point(190, 32);
			this->numericUpDown_MeanK->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown_MeanK->Name = L"numericUpDown_MeanK";
			this->numericUpDown_MeanK->Size = System::Drawing::Size(70, 22);
			this->numericUpDown_MeanK->TabIndex = 1;
			this->numericUpDown_MeanK->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 17);
			this->label6->TabIndex = 0;
			this->label6->Text = L"MeanK:";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->numericUpDown_FrameNumber);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Location = System::Drawing::Point(312, 183);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(294, 60);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Scan Parameters";
			// 
			// numericUpDown_FrameNumber
			// 
			this->numericUpDown_FrameNumber->Location = System::Drawing::Point(213, 27);
			this->numericUpDown_FrameNumber->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_FrameNumber->Name = L"numericUpDown_FrameNumber";
			this->numericUpDown_FrameNumber->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_FrameNumber->TabIndex = 1;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(19, 27);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(113, 17);
			this->label13->TabIndex = 0;
			this->label13->Text = L"Frames Number:";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->numericUpDown_Interpolation);
			this->groupBox6->Controls->Add(this->label15);
			this->groupBox6->Controls->Add(this->numericUpDown_UpSampling);
			this->groupBox6->Controls->Add(this->label14);
			this->groupBox6->Location = System::Drawing::Point(12, 464);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(590, 60);
			this->groupBox6->TabIndex = 6;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Points Cloud Resolution";
			// 
			// numericUpDown_Interpolation
			// 
			this->numericUpDown_Interpolation->Location = System::Drawing::Point(513, 27);
			this->numericUpDown_Interpolation->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_Interpolation->Name = L"numericUpDown_Interpolation";
			this->numericUpDown_Interpolation->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_Interpolation->TabIndex = 3;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(319, 27);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(130, 17);
			this->label15->TabIndex = 2;
			this->label15->Text = L"Interpolation Factor";
			// 
			// numericUpDown_UpSampling
			// 
			this->numericUpDown_UpSampling->Location = System::Drawing::Point(213, 27);
			this->numericUpDown_UpSampling->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_UpSampling->Name = L"numericUpDown_UpSampling";
			this->numericUpDown_UpSampling->Size = System::Drawing::Size(47, 22);
			this->numericUpDown_UpSampling->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(19, 27);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(130, 17);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Upsampling Factor:";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label20);
			this->groupBox7->Controls->Add(this->numericUpDown_SquareSize);
			this->groupBox7->Controls->Add(this->numericUpDown_toleranceCB);
			this->groupBox7->Controls->Add(this->label19);
			this->groupBox7->Controls->Add(this->checkBox_CB_Auto_Size);
			this->groupBox7->Controls->Add(this->numericUpDown_CBW);
			this->groupBox7->Controls->Add(this->label17);
			this->groupBox7->Controls->Add(this->numericUpDown_CBH);
			this->groupBox7->Controls->Add(this->label18);
			this->groupBox7->Location = System::Drawing::Point(12, 530);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(590, 132);
			this->groupBox7->TabIndex = 7;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Registation Settings";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(19, 102);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(112, 17);
			this->label20->TabIndex = 7;
			this->label20->Text = L"Tolerance Pixels";
			// 
			// numericUpDown_SquareSize
			// 
			this->numericUpDown_SquareSize->DecimalPlaces = 6;
			this->numericUpDown_SquareSize->Location = System::Drawing::Point(461, 27);
			this->numericUpDown_SquareSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_SquareSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 262144 });
			this->numericUpDown_SquareSize->Name = L"numericUpDown_SquareSize";
			this->numericUpDown_SquareSize->Size = System::Drawing::Size(101, 22);
			this->numericUpDown_SquareSize->TabIndex = 6;
			this->numericUpDown_SquareSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericUpDown_toleranceCB
			// 
			this->numericUpDown_toleranceCB->DecimalPlaces = 1;
			this->numericUpDown_toleranceCB->Location = System::Drawing::Point(201, 102);
			this->numericUpDown_toleranceCB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_toleranceCB->Name = L"numericUpDown_toleranceCB";
			this->numericUpDown_toleranceCB->Size = System::Drawing::Size(59, 22);
			this->numericUpDown_toleranceCB->TabIndex = 7;
			this->numericUpDown_toleranceCB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(321, 27);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(110, 17);
			this->label19->TabIndex = 5;
			this->label19->Text = L"Square Size (m)";
			// 
			// checkBox_CB_Auto_Size
			// 
			this->checkBox_CB_Auto_Size->AutoSize = true;
			this->checkBox_CB_Auto_Size->Location = System::Drawing::Point(20, 28);
			this->checkBox_CB_Auto_Size->Name = L"checkBox_CB_Auto_Size";
			this->checkBox_CB_Auto_Size->Size = System::Drawing::Size(187, 21);
			this->checkBox_CB_Auto_Size->TabIndex = 4;
			this->checkBox_CB_Auto_Size->Text = L"Automatic Size Detection";
			this->checkBox_CB_Auto_Size->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_CBW
			// 
			this->numericUpDown_CBW->Location = System::Drawing::Point(505, 55);
			this->numericUpDown_CBW->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown_CBW->Name = L"numericUpDown_CBW";
			this->numericUpDown_CBW->Size = System::Drawing::Size(57, 22);
			this->numericUpDown_CBW->TabIndex = 3;
			this->numericUpDown_CBW->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(321, 55);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(124, 17);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Chessboard Width";
			// 
			// numericUpDown_CBH
			// 
			this->numericUpDown_CBH->Location = System::Drawing::Point(201, 55);
			this->numericUpDown_CBH->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown_CBH->Name = L"numericUpDown_CBH";
			this->numericUpDown_CBH->Size = System::Drawing::Size(59, 22);
			this->numericUpDown_CBH->TabIndex = 1;
			this->numericUpDown_CBH->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(19, 55);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(129, 17);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Chessboard Height";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->checkBox_Online);
			this->groupBox8->Location = System::Drawing::Point(12, 7);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(594, 53);
			this->groupBox8->TabIndex = 8;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Platform";
			// 
			// checkBox_Online
			// 
			this->checkBox_Online->AutoSize = true;
			this->checkBox_Online->Location = System::Drawing::Point(22, 21);
			this->checkBox_Online->Name = L"checkBox_Online";
			this->checkBox_Online->Size = System::Drawing::Size(235, 21);
			this->checkBox_Online->TabIndex = 5;
			this->checkBox_Online->Text = L"Work with Kinect Sensors Online";
			this->checkBox_Online->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->numericUpDown_PolyRegression);
			this->groupBox9->Controls->Add(this->label22);
			this->groupBox9->Location = System::Drawing::Point(12, 668);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(590, 60);
			this->groupBox9->TabIndex = 9;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Points Cloud Resolution";
			// 
			// numericUpDown_PolyRegression
			// 
			this->numericUpDown_PolyRegression->Location = System::Drawing::Point(222, 25);
			this->numericUpDown_PolyRegression->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_PolyRegression->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_PolyRegression->Name = L"numericUpDown_PolyRegression";
			this->numericUpDown_PolyRegression->Size = System::Drawing::Size(55, 22);
			this->numericUpDown_PolyRegression->TabIndex = 1;
			this->numericUpDown_PolyRegression->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(19, 27);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(197, 17);
			this->label22->TabIndex = 0;
			this->label22->Text = L"Polynomial Regression Order:";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(614, 804);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NeighborsNB))->EndInit();
			this->panel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_Error))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_TSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_Angle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshP_NN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_Samples))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_NN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeshSS_Av))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SelectPointSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NormalSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PointSize))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FilterThresh))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_MeanK))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_FrameNumber))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Interpolation))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_UpSampling))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SquareSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_toleranceCB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CBW))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CBH))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_PolyRegression))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e) {

	//Platform
	checkBox_Online->Checked = SETTINGS::load_kinect_online;

	//
	numericUpDown_NeighborsNB->Value = SETTINGS::Mesh::normals_estimation_neighbors_nb;
	numericUpDown_MeshSS_Av->Value = SETTINGS::Mesh::meshSS_average_space;
	numericUpDown_MeshSS_NN->Value = SETTINGS::Mesh::meshSS_neighbors_nb;
	numericUpDown_MeshSS_Samples->Value = SETTINGS::Mesh::meshSS_samples;
	numericUpDown_MeshP_NN->Value = SETTINGS::Mesh::meshP_neighbors_nb;
	numericUpDown_MeshP_Angle->Value = SETTINGS::Mesh::meshP_smoothangle;
	numericUpDown_MeshP_TSize->Value = Convert::ToDecimal(SETTINGS::Mesh::meshP_triangleSize);
	numericUpDown_MeshP_Error->Value = Convert::ToDecimal(SETTINGS::Mesh::meshP_error);
	numericUpDown_PointSize->Value = Convert::ToDecimal(SETTINGS::Display::cloud_point_size);
	numericUpDown_SelectPointSize->Value = Convert::ToDecimal(SETTINGS::Display::selection_point_size);
	numericUpDown_NormalSize->Value = Convert::ToDecimal(SETTINGS::Display::cloud_normal_size);
	numericUpDown_MeanK->Value = Convert::ToDecimal(SETTINGS::Mesh::filter_meank);
	numericUpDown_FilterThresh->Value = Convert::ToDecimal(SETTINGS::Mesh::filter_threshold);
	numericUpDown_FrameNumber->Value = SETTINGS::Scan::frames_number;
	numericUpDown_UpSampling->Value = SETTINGS::Scan::upsampling_factor;
	numericUpDown_Interpolation->Value = Convert::ToDecimal(SETTINGS::Scan::interpolation_factor);

	radioButton_MeshPoisson->Checked = (SETTINGS::Mesh::mesh_algorithm == 1);
	radioButton_MeshSpaceScale->Checked = (SETTINGS::Mesh::mesh_algorithm == 2);
	radioButton_MeshCombinedAlgorithm->Checked = (SETTINGS::Mesh::mesh_algorithm == 3);

	//calibration settings
	numericUpDown_CBH->Value = Convert::ToDecimal(SETTINGS::calibsettings.boardHeight);
	numericUpDown_CBW->Value = Convert::ToDecimal(SETTINGS::calibsettings.boardWidth);
	numericUpDown_SquareSize->Value = Convert::ToDecimal(SETTINGS::calibsettings.squareSize);
	checkBox_CB_Auto_Size->Checked = SETTINGS::calibsettings.flexiblesize;
	numericUpDown_toleranceCB->Value = Convert::ToDecimal(SETTINGS::Scan::chessboard_tolerance);

	//Error Compenstation
	numericUpDown_PolyRegression->Value = Convert::ToDecimal(SETTINGS::Scan::regression_order);
}
private: System::Void Button_OK_Click(System::Object^ sender, System::EventArgs^ e) {
	SETTINGS::Mesh::normals_estimation_neighbors_nb = Convert::ToInt32(numericUpDown_NeighborsNB->Value);
	SETTINGS::Mesh::meshSS_neighbors_nb = Convert::ToInt32(numericUpDown_MeshSS_NN->Value);
	SETTINGS::Mesh::meshSS_average_space = Convert::ToInt32(numericUpDown_MeshSS_Av->Value);
	SETTINGS::Mesh::meshSS_samples = Convert::ToInt32(numericUpDown_MeshSS_Samples->Value);
	SETTINGS::Mesh::meshP_neighbors_nb = Convert::ToInt32(numericUpDown_MeshP_NN->Value);
	SETTINGS::Mesh::meshP_smoothangle = Convert::ToInt32(numericUpDown_MeshP_Angle->Value);
	SETTINGS::Mesh::meshP_triangleSize = Convert::ToDouble(numericUpDown_MeshP_TSize->Value);
	SETTINGS::Mesh::meshP_error = Convert::ToDouble(numericUpDown_MeshP_Error->Value);
	SETTINGS::Display::cloud_point_size = Convert::ToDouble(numericUpDown_PointSize->Value);
	SETTINGS::Display::selection_point_size = Convert::ToDouble(numericUpDown_SelectPointSize->Value);
	SETTINGS::Display::cloud_normal_size = Convert::ToDouble(numericUpDown_NormalSize->Value);
	SETTINGS::Mesh::filter_meank = Convert::ToDouble(numericUpDown_MeanK->Value);
	SETTINGS::Mesh::filter_threshold = Convert::ToDouble(numericUpDown_FilterThresh->Value);
	SETTINGS::Scan::frames_number = Convert::ToInt32(numericUpDown_FrameNumber->Value);
	SETTINGS::Scan::upsampling_factor = Convert::ToInt32(numericUpDown_UpSampling->Value);
	SETTINGS::Scan::interpolation_factor = Convert::ToDouble(numericUpDown_Interpolation->Value);

	if (radioButton_MeshPoisson->Checked) SETTINGS::Mesh::mesh_algorithm = 1;
	else if (radioButton_MeshSpaceScale->Checked) SETTINGS::Mesh::mesh_algorithm = 2;
	else if (radioButton_MeshCombinedAlgorithm->Checked) SETTINGS::Mesh::mesh_algorithm = 3;

	//Registation settings
	SETTINGS::calibsettings.boardHeight = Convert::ToInt32(numericUpDown_CBH->Value);
	SETTINGS::calibsettings.boardWidth = Convert::ToInt32(numericUpDown_CBW->Value);
	SETTINGS::calibsettings.squareSize = Convert::ToDouble(numericUpDown_SquareSize->Value);
	SETTINGS::calibsettings.flexiblesize = checkBox_CB_Auto_Size->Checked;
	SETTINGS::Scan::chessboard_tolerance = Convert::ToDouble(numericUpDown_toleranceCB->Value);

	// Error compenstation
	int regression_order = Convert::ToInt32(numericUpDown_PolyRegression->Value);
	if (regression_order != SETTINGS::Scan::regression_order)
		SETTINGS::Scan::regression_order = regression_order;

	//platform
	SETTINGS::load_kinect_online = checkBox_Online->Checked;


	this->Close();
}
};
}
