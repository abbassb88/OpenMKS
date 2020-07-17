#include "Settings.h"
#include "FrameViewer.h"
#pragma once

namespace OpenMKS {

	using namespace System;
	using namespace System::ComponentModel;

	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: OpenTK::GLControl^ glControl;
	private: System::Windows::Forms::Panel^ panel1;







	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;

	private: System::Windows::Forms::Button^ button_Cam1Stop;

	private: System::Windows::Forms::Button^ button_Cam1Start;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::GroupBox^ groupBox1;












































































private: System::Windows::Forms::Button^ button_OneShot;

private: System::Windows::Forms::Button^ button_Filter1;
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ importToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ exportToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ cloudPointsToolStripMenuItem;


private: System::Windows::Forms::ToolStrip^ toolStrip1;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_Settings;

private: System::Windows::Forms::StatusStrip^ statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel;
private: System::Windows::Forms::ToolStrip^ toolStrip_View;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ShowPointCloud;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::ComboBox^ comboBox_ListOfDevices;



































private: System::Windows::Forms::Button^ button_Clear;
private: System::Windows::Forms::Button^ button_StopAll;
private: System::Windows::Forms::Button^ button_StartAll;
private: System::Windows::Forms::Button^ button_FilterAll;
private: System::Windows::Forms::Button^ button_MeshAll;
private: System::Windows::Forms::ToolStripMenuItem^ cloudPointToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ sTLFileToolStripMenuItem;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_Refresh;
private: System::Windows::Forms::ColorDialog^ colorDialog;
private: System::Windows::Forms::Button^ button_Color;
private: System::Windows::Forms::ToolStripMenuItem^ sTLFileToolStripMenuItem1;


















private: System::Windows::Forms::ToolStrip^ toolStrip3;


private: System::Windows::Forms::ToolStripButton^ toolStripButton_RealColors;


private: System::Windows::Forms::ToolStripMenuItem^ calibrationToolStripMenuItem_Export;
private: System::Windows::Forms::ToolStripMenuItem^ calibrationToolStripMenuItem_Import;



private: System::Windows::Forms::ToolStripButton^ toolStripButton_Infos;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_KinectDisplay;











private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton1;
private: System::Windows::Forms::ToolStripMenuItem^ fromSTLFileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ fromPointCloudFileToolStripMenuItem;

private: System::Windows::Forms::Button^ button_RemoveDupFaces;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::DataGridView^ dataGridView_Pset;

private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::ToolStrip^ toolStrip4;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_RefPoint;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator6;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ImportPset;



private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton2;
private: System::Windows::Forms::ToolStripMenuItem^ depthRGBFrameToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ pointCloudToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ fromFrameFileToolStripMenuItem;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_Frame;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator7;
private: System::Windows::Forms::Button^ button_Align;


private: System::Windows::Forms::ToolStripMenuItem^ calibrationToolStripMenuItem;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ChessBoardDetect;


private: System::Windows::Forms::ToolStripMenuItem^ lRErrorCompensationToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_slicingpoint1;


private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_rightindex;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_leftindex;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Button^ button_CreateRefPoints;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_slicingpoint3;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_slicingpoint2;

private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Button^ button_AlignWithLeftSensor;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_AlignRef;






















	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->glControl = (gcnew OpenTK::GLControl());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_Align = (gcnew System::Windows::Forms::Button());
			this->button_RemoveDupFaces = (gcnew System::Windows::Forms::Button());
			this->button_MeshAll = (gcnew System::Windows::Forms::Button());
			this->button_FilterAll = (gcnew System::Windows::Forms::Button());
			this->button_StopAll = (gcnew System::Windows::Forms::Button());
			this->button_StartAll = (gcnew System::Windows::Forms::Button());
			this->button_OneShot = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_AlignWithLeftSensor = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_slicingpoint3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_slicingpoint2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_CreateRefPoints = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_slicingpoint1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_rightindex = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_leftindex = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView_Pset = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown_AlignRef = (gcnew System::Windows::Forms::NumericUpDown());
			this->toolStrip4 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_RefPoint = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_ImportPset = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStrip3 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_Infos = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_Frame = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSplitButton2 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->depthRGBFrameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pointCloudToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->fromSTLFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fromPointCloudFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fromFrameFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lRErrorCompensationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_KinectDisplay = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_ChessBoardDetect = (gcnew System::Windows::Forms::ToolStripButton());
			this->button_Color = (gcnew System::Windows::Forms::Button());
			this->button_Clear = (gcnew System::Windows::Forms::Button());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->comboBox_ListOfDevices = (gcnew System::Windows::Forms::ComboBox());
			this->button_Filter1 = (gcnew System::Windows::Forms::Button());
			this->button_Cam1Stop = (gcnew System::Windows::Forms::Button());
			this->button_Cam1Start = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cloudPointToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sTLFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrationToolStripMenuItem_Import = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cloudPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sTLFileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calibrationToolStripMenuItem_Export = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_Settings = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_Refresh = (gcnew System::Windows::Forms::ToolStripButton());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStrip_View = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_ShowPointCloud = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_RealColors = (gcnew System::Windows::Forms::ToolStripButton());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_rightindex))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_leftindex))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Pset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AlignRef))->BeginInit();
			this->toolStrip4->SuspendLayout();
			this->toolStrip3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->toolStrip_View->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// glControl
			// 
			this->glControl->BackColor = System::Drawing::Color::Black;
			this->glControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->glControl->Location = System::Drawing::Point(298, 55);
			this->glControl->Margin = System::Windows::Forms::Padding(4);
			this->glControl->Name = L"glControl";
			this->glControl->Size = System::Drawing::Size(816, 684);
			this->glControl->TabIndex = 0;
			this->glControl->VSync = false;
			this->glControl->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::GlControl_Paint);
			this->glControl->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::GlControl_MouseDown);
			this->glControl->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::GlControl_MouseMove);
			this->glControl->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::GlControl_MouseUp);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->button_Align);
			this->panel1->Controls->Add(this->button_RemoveDupFaces);
			this->panel1->Controls->Add(this->button_MeshAll);
			this->panel1->Controls->Add(this->button_FilterAll);
			this->panel1->Controls->Add(this->button_StopAll);
			this->panel1->Controls->Add(this->button_StartAll);
			this->panel1->Controls->Add(this->button_OneShot);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(298, 684);
			this->panel1->TabIndex = 1;
			// 
			// button_Align
			// 
			this->button_Align->Location = System::Drawing::Point(31, 694);
			this->button_Align->Name = L"button_Align";
			this->button_Align->Size = System::Drawing::Size(213, 28);
			this->button_Align->TabIndex = 33;
			this->button_Align->Text = L"Align All";
			this->button_Align->UseVisualStyleBackColor = true;
			this->button_Align->Click += gcnew System::EventHandler(this, &MyForm::button_Align02_Click);
			// 
			// button_RemoveDupFaces
			// 
			this->button_RemoveDupFaces->Location = System::Drawing::Point(31, 765);
			this->button_RemoveDupFaces->Name = L"button_RemoveDupFaces";
			this->button_RemoveDupFaces->Size = System::Drawing::Size(214, 28);
			this->button_RemoveDupFaces->TabIndex = 31;
			this->button_RemoveDupFaces->Text = L"Remove Duplicated Faces";
			this->button_RemoveDupFaces->UseVisualStyleBackColor = true;
			this->button_RemoveDupFaces->Click += gcnew System::EventHandler(this, &MyForm::button_RemoveDupFaces_Click);
			// 
			// button_MeshAll
			// 
			this->button_MeshAll->Location = System::Drawing::Point(31, 731);
			this->button_MeshAll->Name = L"button_MeshAll";
			this->button_MeshAll->Size = System::Drawing::Size(214, 28);
			this->button_MeshAll->TabIndex = 26;
			this->button_MeshAll->Text = L"Create Mesh";
			this->button_MeshAll->UseVisualStyleBackColor = true;
			this->button_MeshAll->Click += gcnew System::EventHandler(this, &MyForm::Button_MeshAll_Click);
			// 
			// button_FilterAll
			// 
			this->button_FilterAll->Location = System::Drawing::Point(31, 657);
			this->button_FilterAll->Name = L"button_FilterAll";
			this->button_FilterAll->Size = System::Drawing::Size(214, 28);
			this->button_FilterAll->TabIndex = 25;
			this->button_FilterAll->Text = L"Filter";
			this->button_FilterAll->UseVisualStyleBackColor = true;
			this->button_FilterAll->Click += gcnew System::EventHandler(this, &MyForm::Button_FilterAll_Click);
			// 
			// button_StopAll
			// 
			this->button_StopAll->Location = System::Drawing::Point(144, 588);
			this->button_StopAll->Name = L"button_StopAll";
			this->button_StopAll->Size = System::Drawing::Size(99, 28);
			this->button_StopAll->TabIndex = 24;
			this->button_StopAll->Text = L"Stop All";
			this->button_StopAll->UseVisualStyleBackColor = true;
			this->button_StopAll->Click += gcnew System::EventHandler(this, &MyForm::Button_StopAll_Click);
			// 
			// button_StartAll
			// 
			this->button_StartAll->Location = System::Drawing::Point(30, 588);
			this->button_StartAll->Name = L"button_StartAll";
			this->button_StartAll->Size = System::Drawing::Size(109, 28);
			this->button_StartAll->TabIndex = 23;
			this->button_StartAll->Text = L"Start All";
			this->button_StartAll->UseVisualStyleBackColor = true;
			this->button_StartAll->Click += gcnew System::EventHandler(this, &MyForm::Button_StartAll_Click);
			// 
			// button_OneShot
			// 
			this->button_OneShot->Location = System::Drawing::Point(30, 623);
			this->button_OneShot->Name = L"button_OneShot";
			this->button_OneShot->Size = System::Drawing::Size(214, 28);
			this->button_OneShot->TabIndex = 22;
			this->button_OneShot->Text = L"Scan";
			this->button_OneShot->UseVisualStyleBackColor = true;
			this->button_OneShot->Click += gcnew System::EventHandler(this, &MyForm::Button_OneShot_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_AlignWithLeftSensor);
			this->groupBox1->Controls->Add(this->numericUpDown_slicingpoint3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->numericUpDown_slicingpoint2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button_CreateRefPoints);
			this->groupBox1->Controls->Add(this->numericUpDown_slicingpoint1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->numericUpDown_rightindex);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->numericUpDown_leftindex);
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Controls->Add(this->toolStrip3);
			this->groupBox1->Controls->Add(this->button_Color);
			this->groupBox1->Controls->Add(this->button_Clear);
			this->groupBox1->Controls->Add(this->label29);
			this->groupBox1->Controls->Add(this->comboBox_ListOfDevices);
			this->groupBox1->Controls->Add(this->button_Filter1);
			this->groupBox1->Controls->Add(this->button_Cam1Stop);
			this->groupBox1->Controls->Add(this->button_Cam1Start);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(3, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(276, 559);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Individual Control";
			// 
			// button_AlignWithLeftSensor
			// 
			this->button_AlignWithLeftSensor->Location = System::Drawing::Point(23, 329);
			this->button_AlignWithLeftSensor->Name = L"button_AlignWithLeftSensor";
			this->button_AlignWithLeftSensor->Size = System::Drawing::Size(213, 28);
			this->button_AlignWithLeftSensor->TabIndex = 66;
			this->button_AlignWithLeftSensor->Text = L"Align with Left Sensor";
			this->button_AlignWithLeftSensor->UseVisualStyleBackColor = true;
			this->button_AlignWithLeftSensor->Click += gcnew System::EventHandler(this, &MyForm::button_AlignWithLeftSensor_Click);
			// 
			// numericUpDown_slicingpoint3
			// 
			this->numericUpDown_slicingpoint3->Location = System::Drawing::Point(143, 253);
			this->numericUpDown_slicingpoint3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->numericUpDown_slicingpoint3->Name = L"numericUpDown_slicingpoint3";
			this->numericUpDown_slicingpoint3->Size = System::Drawing::Size(60, 24);
			this->numericUpDown_slicingpoint3->TabIndex = 65;
			this->numericUpDown_slicingpoint3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_leftindex_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label5->Location = System::Drawing::Point(24, 255);
			this->label5->MaximumSize = System::Drawing::Size(262, 20);
			this->label5->MinimumSize = System::Drawing::Size(175, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(175, 15);
			this->label5->TabIndex = 64;
			this->label5->Text = L"Slicing Point 3:";
			// 
			// numericUpDown_slicingpoint2
			// 
			this->numericUpDown_slicingpoint2->Location = System::Drawing::Point(142, 225);
			this->numericUpDown_slicingpoint2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->numericUpDown_slicingpoint2->Name = L"numericUpDown_slicingpoint2";
			this->numericUpDown_slicingpoint2->Size = System::Drawing::Size(60, 24);
			this->numericUpDown_slicingpoint2->TabIndex = 63;
			this->numericUpDown_slicingpoint2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_leftindex_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Location = System::Drawing::Point(24, 227);
			this->label4->MaximumSize = System::Drawing::Size(262, 20);
			this->label4->MinimumSize = System::Drawing::Size(175, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 15);
			this->label4->TabIndex = 62;
			this->label4->Text = L"Slicing Point 2:";
			// 
			// button_CreateRefPoints
			// 
			this->button_CreateRefPoints->Location = System::Drawing::Point(23, 295);
			this->button_CreateRefPoints->Name = L"button_CreateRefPoints";
			this->button_CreateRefPoints->Size = System::Drawing::Size(213, 28);
			this->button_CreateRefPoints->TabIndex = 34;
			this->button_CreateRefPoints->Text = L"Create Ref Points";
			this->button_CreateRefPoints->UseVisualStyleBackColor = true;
			this->button_CreateRefPoints->Click += gcnew System::EventHandler(this, &MyForm::button_CreateRefPoints_Click);
			// 
			// numericUpDown_slicingpoint1
			// 
			this->numericUpDown_slicingpoint1->Location = System::Drawing::Point(143, 197);
			this->numericUpDown_slicingpoint1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->numericUpDown_slicingpoint1->Name = L"numericUpDown_slicingpoint1";
			this->numericUpDown_slicingpoint1->Size = System::Drawing::Size(60, 24);
			this->numericUpDown_slicingpoint1->TabIndex = 61;
			this->numericUpDown_slicingpoint1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_leftindex_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Location = System::Drawing::Point(24, 199);
			this->label3->MaximumSize = System::Drawing::Size(262, 20);
			this->label3->MinimumSize = System::Drawing::Size(175, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(175, 15);
			this->label3->TabIndex = 60;
			this->label3->Text = L"Slicing Point 1:";
			// 
			// numericUpDown_rightindex
			// 
			this->numericUpDown_rightindex->Location = System::Drawing::Point(145, 152);
			this->numericUpDown_rightindex->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_rightindex->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
			this->numericUpDown_rightindex->Name = L"numericUpDown_rightindex";
			this->numericUpDown_rightindex->Size = System::Drawing::Size(57, 24);
			this->numericUpDown_rightindex->TabIndex = 58;
			this->numericUpDown_rightindex->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_leftindex_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->Location = System::Drawing::Point(27, 154);
			this->label2->MaximumSize = System::Drawing::Size(262, 20);
			this->label2->MinimumSize = System::Drawing::Size(175, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 15);
			this->label2->TabIndex = 59;
			this->label2->Text = L"Right Sensor index:";
			// 
			// numericUpDown_leftindex
			// 
			this->numericUpDown_leftindex->Location = System::Drawing::Point(145, 125);
			this->numericUpDown_leftindex->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_leftindex->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
			this->numericUpDown_leftindex->Name = L"numericUpDown_leftindex";
			this->numericUpDown_leftindex->Size = System::Drawing::Size(57, 24);
			this->numericUpDown_leftindex->TabIndex = 7;
			this->numericUpDown_leftindex->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_leftindex_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridView_Pset);
			this->panel2->Controls->Add(this->numericUpDown_AlignRef);
			this->panel2->Controls->Add(this->toolStrip4);
			this->panel2->Location = System::Drawing::Point(5, 376);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(265, 132);
			this->panel2->TabIndex = 6;
			// 
			// dataGridView_Pset
			// 
			this->dataGridView_Pset->AllowUserToAddRows = false;
			this->dataGridView_Pset->AllowUserToOrderColumns = true;
			this->dataGridView_Pset->AllowUserToResizeColumns = false;
			this->dataGridView_Pset->AllowUserToResizeRows = false;
			this->dataGridView_Pset->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView_Pset->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Pset->ColumnHeadersVisible = false;
			this->dataGridView_Pset->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView_Pset->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Pset->Location = System::Drawing::Point(0, 27);
			this->dataGridView_Pset->Name = L"dataGridView_Pset";
			this->dataGridView_Pset->RowHeadersWidth = 51;
			this->dataGridView_Pset->RowTemplate->Height = 24;
			this->dataGridView_Pset->Size = System::Drawing::Size(265, 105);
			this->dataGridView_Pset->TabIndex = 6;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Column1";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Column2";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Column3";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// numericUpDown_AlignRef
			// 
			this->numericUpDown_AlignRef->Location = System::Drawing::Point(144, 3);
			this->numericUpDown_AlignRef->Name = L"numericUpDown_AlignRef";
			this->numericUpDown_AlignRef->Size = System::Drawing::Size(46, 24);
			this->numericUpDown_AlignRef->TabIndex = 6;
			this->numericUpDown_AlignRef->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown_AlignRef_ValueChanged);
			// 
			// toolStrip4
			// 
			this->toolStrip4->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip4->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripButton_RefPoint,
					this->toolStripSeparator6, this->toolStripButton_ImportPset, this->toolStripSeparator1, this->toolStripLabel1
			});
			this->toolStrip4->Location = System::Drawing::Point(0, 0);
			this->toolStrip4->Name = L"toolStrip4";
			this->toolStrip4->Size = System::Drawing::Size(265, 27);
			this->toolStrip4->TabIndex = 0;
			this->toolStrip4->Text = L"toolStrip4";
			// 
			// toolStripButton_RefPoint
			// 
			this->toolStripButton_RefPoint->CheckOnClick = true;
			this->toolStripButton_RefPoint->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_RefPoint->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_RefPoint.Image")));
			this->toolStripButton_RefPoint->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_RefPoint->Name = L"toolStripButton_RefPoint";
			this->toolStripButton_RefPoint->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_RefPoint->Text = L"Select Ref Point";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_ImportPset
			// 
			this->toolStripButton_ImportPset->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ImportPset->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ImportPset.Image")));
			this->toolStripButton_ImportPset->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ImportPset->Name = L"toolStripButton_ImportPset";
			this->toolStripButton_ImportPset->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ImportPset->Text = L"Import Set of Points";
			this->toolStripButton_ImportPset->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_ImportPset_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(73, 24);
			this->toolStripLabel1->Text = L"Align Ref.";
			// 
			// toolStrip3
			// 
			this->toolStrip3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripButton_Infos,
					this->toolStripSeparator4, this->toolStripButton_Frame, this->toolStripSeparator7, this->toolStripSplitButton2, this->toolStripSplitButton1,
					this->toolStripSeparator5, this->toolStripButton_KinectDisplay, this->toolStripButton_ChessBoardDetect
			});
			this->toolStrip3->Location = System::Drawing::Point(3, 529);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->Size = System::Drawing::Size(270, 27);
			this->toolStrip3->TabIndex = 56;
			this->toolStrip3->Text = L"toolStrip3";
			// 
			// toolStripButton_Infos
			// 
			this->toolStripButton_Infos->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Infos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Infos.Image")));
			this->toolStripButton_Infos->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Infos->Name = L"toolStripButton_Infos";
			this->toolStripButton_Infos->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Infos->Text = L"Infos";
			this->toolStripButton_Infos->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_Infos_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_Frame
			// 
			this->toolStripButton_Frame->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Frame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Frame.Image")));
			this->toolStripButton_Frame->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Frame->Name = L"toolStripButton_Frame";
			this->toolStripButton_Frame->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Frame->Text = L"Frame";
			this->toolStripButton_Frame->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_Frame_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripSplitButton2
			// 
			this->toolStripSplitButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSplitButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->depthRGBFrameToolStripMenuItem,
					this->pointCloudToolStripMenuItem
			});
			this->toolStripSplitButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSplitButton2.Image")));
			this->toolStripSplitButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton2->Name = L"toolStripSplitButton2";
			this->toolStripSplitButton2->Size = System::Drawing::Size(39, 24);
			this->toolStripSplitButton2->Text = L"toolStripSplitButton2";
			// 
			// depthRGBFrameToolStripMenuItem
			// 
			this->depthRGBFrameToolStripMenuItem->Name = L"depthRGBFrameToolStripMenuItem";
			this->depthRGBFrameToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->depthRGBFrameToolStripMenuItem->Text = L"Depth & RGB Frame";
			this->depthRGBFrameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::depthRGBFrameToolStripMenuItem_Click);
			// 
			// pointCloudToolStripMenuItem
			// 
			this->pointCloudToolStripMenuItem->Name = L"pointCloudToolStripMenuItem";
			this->pointCloudToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->pointCloudToolStripMenuItem->Text = L"Point Cloud";
			this->pointCloudToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pointCloudToolStripMenuItem_Click);
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSplitButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fromSTLFileToolStripMenuItem,
					this->fromPointCloudFileToolStripMenuItem, this->fromFrameFileToolStripMenuItem, this->calibrationToolStripMenuItem, this->lRErrorCompensationToolStripMenuItem
			});
			this->toolStripSplitButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSplitButton1.Image")));
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(39, 24);
			this->toolStripSplitButton1->Text = L"toolStripSplitButton_Import";
			// 
			// fromSTLFileToolStripMenuItem
			// 
			this->fromSTLFileToolStripMenuItem->Name = L"fromSTLFileToolStripMenuItem";
			this->fromSTLFileToolStripMenuItem->Size = System::Drawing::Size(244, 26);
			this->fromSTLFileToolStripMenuItem->Text = L"From STL File";
			this->fromSTLFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fromSTLFileToolStripMenuItem_Click);
			// 
			// fromPointCloudFileToolStripMenuItem
			// 
			this->fromPointCloudFileToolStripMenuItem->Name = L"fromPointCloudFileToolStripMenuItem";
			this->fromPointCloudFileToolStripMenuItem->Size = System::Drawing::Size(244, 26);
			this->fromPointCloudFileToolStripMenuItem->Text = L"From Point Cloud File";
			this->fromPointCloudFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_Import_Click);
			// 
			// fromFrameFileToolStripMenuItem
			// 
			this->fromFrameFileToolStripMenuItem->Name = L"fromFrameFileToolStripMenuItem";
			this->fromFrameFileToolStripMenuItem->Size = System::Drawing::Size(244, 26);
			this->fromFrameFileToolStripMenuItem->Text = L"From Frame File";
			this->fromFrameFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fromFrameFileToolStripMenuItem_Click);
			// 
			// calibrationToolStripMenuItem
			// 
			this->calibrationToolStripMenuItem->Name = L"calibrationToolStripMenuItem";
			this->calibrationToolStripMenuItem->Size = System::Drawing::Size(244, 26);
			this->calibrationToolStripMenuItem->Text = L"Intrinsic Parameters";
			this->calibrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::calibrationToolStripMenuItem_Click);
			// 
			// lRErrorCompensationToolStripMenuItem
			// 
			this->lRErrorCompensationToolStripMenuItem->Name = L"lRErrorCompensationToolStripMenuItem";
			this->lRErrorCompensationToolStripMenuItem->Size = System::Drawing::Size(244, 26);
			this->lRErrorCompensationToolStripMenuItem->Text = L"LR Error Compensation";
			this->lRErrorCompensationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lRErrorCompensationToolStripMenuItem_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_KinectDisplay
			// 
			this->toolStripButton_KinectDisplay->Checked = true;
			this->toolStripButton_KinectDisplay->CheckOnClick = true;
			this->toolStripButton_KinectDisplay->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripButton_KinectDisplay->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_KinectDisplay->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_KinectDisplay.Image")));
			this->toolStripButton_KinectDisplay->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_KinectDisplay->Name = L"toolStripButton_KinectDisplay";
			this->toolStripButton_KinectDisplay->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_KinectDisplay->Text = L"Display";
			this->toolStripButton_KinectDisplay->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_KinectDisplay_Click);
			// 
			// toolStripButton_ChessBoardDetect
			// 
			this->toolStripButton_ChessBoardDetect->CheckOnClick = true;
			this->toolStripButton_ChessBoardDetect->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ChessBoardDetect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ChessBoardDetect.Image")));
			this->toolStripButton_ChessBoardDetect->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ChessBoardDetect->Name = L"toolStripButton_ChessBoardDetect";
			this->toolStripButton_ChessBoardDetect->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ChessBoardDetect->Text = L"Detect ChessBoard Grid";
			this->toolStripButton_ChessBoardDetect->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_ChessBoardDetect_Click);
			// 
			// button_Color
			// 
			this->button_Color->BackColor = System::Drawing::Color::Transparent;
			this->button_Color->Location = System::Drawing::Point(242, 46);
			this->button_Color->Name = L"button_Color";
			this->button_Color->Size = System::Drawing::Size(23, 26);
			this->button_Color->TabIndex = 53;
			this->button_Color->UseVisualStyleBackColor = false;
			this->button_Color->Click += gcnew System::EventHandler(this, &MyForm::Button_Color_Click);
			// 
			// button_Clear
			// 
			this->button_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Clear->Location = System::Drawing::Point(130, 79);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(51, 28);
			this->button_Clear->TabIndex = 52;
			this->button_Clear->Text = L"Clear";
			this->button_Clear->UseVisualStyleBackColor = true;
			this->button_Clear->Click += gcnew System::EventHandler(this, &MyForm::Button_Clear_Click);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label29->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label29->Location = System::Drawing::Point(20, 26);
			this->label29->MaximumSize = System::Drawing::Size(262, 20);
			this->label29->MinimumSize = System::Drawing::Size(175, 15);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(175, 15);
			this->label29->TabIndex = 25;
			this->label29->Text = L"Selected Device:";
			// 
			// comboBox_ListOfDevices
			// 
			this->comboBox_ListOfDevices->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_ListOfDevices->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox_ListOfDevices->FormattingEnabled = true;
			this->comboBox_ListOfDevices->Location = System::Drawing::Point(21, 46);
			this->comboBox_ListOfDevices->Name = L"comboBox_ListOfDevices";
			this->comboBox_ListOfDevices->Size = System::Drawing::Size(210, 24);
			this->comboBox_ListOfDevices->TabIndex = 24;
			this->comboBox_ListOfDevices->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox_ListOfDevices_SelectedIndexChanged);
			// 
			// button_Filter1
			// 
			this->button_Filter1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Filter1->Location = System::Drawing::Point(185, 79);
			this->button_Filter1->Name = L"button_Filter1";
			this->button_Filter1->Size = System::Drawing::Size(51, 28);
			this->button_Filter1->TabIndex = 21;
			this->button_Filter1->Text = L"Filter";
			this->button_Filter1->UseVisualStyleBackColor = true;
			this->button_Filter1->Click += gcnew System::EventHandler(this, &MyForm::Button_Filter1_Click);
			// 
			// button_Cam1Stop
			// 
			this->button_Cam1Stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Cam1Stop->Location = System::Drawing::Point(76, 79);
			this->button_Cam1Stop->Name = L"button_Cam1Stop";
			this->button_Cam1Stop->Size = System::Drawing::Size(51, 28);
			this->button_Cam1Stop->TabIndex = 5;
			this->button_Cam1Stop->Text = L"Stop";
			this->button_Cam1Stop->UseVisualStyleBackColor = true;
			this->button_Cam1Stop->Click += gcnew System::EventHandler(this, &MyForm::Button_Cam1Stop_Click);
			// 
			// button_Cam1Start
			// 
			this->button_Cam1Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Cam1Start->Location = System::Drawing::Point(22, 79);
			this->button_Cam1Start->Name = L"button_Cam1Start";
			this->button_Cam1Start->Size = System::Drawing::Size(51, 28);
			this->button_Cam1Start->TabIndex = 4;
			this->button_Cam1Start->Text = L"Start";
			this->button_Cam1Start->UseVisualStyleBackColor = true;
			this->button_Cam1Start->Click += gcnew System::EventHandler(this, &MyForm::Button_Cam1Start_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(27, 127);
			this->label1->MaximumSize = System::Drawing::Size(262, 20);
			this->label1->MinimumSize = System::Drawing::Size(175, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 15);
			this->label1->TabIndex = 57;
			this->label1->Text = L"Left Sensor index:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1114, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->importToolStripMenuItem,
					this->exportToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->cloudPointToolStripMenuItem,
					this->sTLFileToolStripMenuItem, this->calibrationToolStripMenuItem_Import
			});
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->importToolStripMenuItem->Text = L"Import";
			// 
			// cloudPointToolStripMenuItem
			// 
			this->cloudPointToolStripMenuItem->Name = L"cloudPointToolStripMenuItem";
			this->cloudPointToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->cloudPointToolStripMenuItem->Text = L"Points Cloud";
			this->cloudPointToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::CloudPointToolStripMenuItem_Click);
			// 
			// sTLFileToolStripMenuItem
			// 
			this->sTLFileToolStripMenuItem->Name = L"sTLFileToolStripMenuItem";
			this->sTLFileToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->sTLFileToolStripMenuItem->Text = L"STL File";
			this->sTLFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::STLFileToolStripMenuItem_Click);
			// 
			// calibrationToolStripMenuItem_Import
			// 
			this->calibrationToolStripMenuItem_Import->Name = L"calibrationToolStripMenuItem_Import";
			this->calibrationToolStripMenuItem_Import->Size = System::Drawing::Size(174, 26);
			this->calibrationToolStripMenuItem_Import->Text = L"Calibration";
			this->calibrationToolStripMenuItem_Import->Click += gcnew System::EventHandler(this, &MyForm::calibrationToolStripMenuItem_Import_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->cloudPointsToolStripMenuItem,
					this->sTLFileToolStripMenuItem1, this->calibrationToolStripMenuItem_Export
			});
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->exportToolStripMenuItem->Text = L"Export";
			// 
			// cloudPointsToolStripMenuItem
			// 
			this->cloudPointsToolStripMenuItem->Name = L"cloudPointsToolStripMenuItem";
			this->cloudPointsToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->cloudPointsToolStripMenuItem->Text = L"Points Cloud";
			this->cloudPointsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::CloudPointsToolStripMenuItem_Click);
			// 
			// sTLFileToolStripMenuItem1
			// 
			this->sTLFileToolStripMenuItem1->Name = L"sTLFileToolStripMenuItem1";
			this->sTLFileToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->sTLFileToolStripMenuItem1->Text = L"STL File";
			this->sTLFileToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::STLFileToolStripMenuItem1_Click);
			// 
			// calibrationToolStripMenuItem_Export
			// 
			this->calibrationToolStripMenuItem_Export->Name = L"calibrationToolStripMenuItem_Export";
			this->calibrationToolStripMenuItem_Export->Size = System::Drawing::Size(224, 26);
			this->calibrationToolStripMenuItem_Export->Text = L"Calibration";
			this->calibrationToolStripMenuItem_Export->Click += gcnew System::EventHandler(this, &MyForm::calibrationToolStripMenuItem_Export_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton_Settings,
					this->toolStripButton_Refresh
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 28);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1114, 27);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton_Settings
			// 
			this->toolStripButton_Settings->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Settings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Settings.Image")));
			this->toolStripButton_Settings->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Settings->Name = L"toolStripButton_Settings";
			this->toolStripButton_Settings->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Settings->Text = L"Settings";
			this->toolStripButton_Settings->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_Settings_Click);
			// 
			// toolStripButton_Refresh
			// 
			this->toolStripButton_Refresh->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Refresh->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Refresh.Image")));
			this->toolStripButton_Refresh->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Refresh->Name = L"toolStripButton_Refresh";
			this->toolStripButton_Refresh->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Refresh->Text = L"Refresh";
			this->toolStripButton_Refresh->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_Refresh_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel });
			this->statusStrip1->Location = System::Drawing::Point(0, 739);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 12, 0);
			this->statusStrip1->Size = System::Drawing::Size(1114, 26);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Size = System::Drawing::Size(50, 20);
			this->toolStripStatusLabel->Text = L"Ready";
			// 
			// toolStrip_View
			// 
			this->toolStrip_View->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip_View->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip_View->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton_ShowPointCloud,
					this->toolStripButton_RealColors
			});
			this->toolStrip_View->Location = System::Drawing::Point(298, 712);
			this->toolStrip_View->Name = L"toolStrip_View";
			this->toolStrip_View->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->toolStrip_View->Size = System::Drawing::Size(816, 27);
			this->toolStrip_View->TabIndex = 5;
			this->toolStrip_View->Text = L"View";
			// 
			// toolStripButton_ShowPointCloud
			// 
			this->toolStripButton_ShowPointCloud->Checked = true;
			this->toolStripButton_ShowPointCloud->CheckOnClick = true;
			this->toolStripButton_ShowPointCloud->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripButton_ShowPointCloud->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ShowPointCloud->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ShowPointCloud.Image")));
			this->toolStripButton_ShowPointCloud->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ShowPointCloud->Name = L"toolStripButton_ShowPointCloud";
			this->toolStripButton_ShowPointCloud->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ShowPointCloud->Text = L"Show PointCloud";
			this->toolStripButton_ShowPointCloud->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_ShowPointCloud_Click);
			// 
			// toolStripButton_RealColors
			// 
			this->toolStripButton_RealColors->CheckOnClick = true;
			this->toolStripButton_RealColors->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_RealColors->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_RealColors.Image")));
			this->toolStripButton_RealColors->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_RealColors->Name = L"toolStripButton_RealColors";
			this->toolStripButton_RealColors->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_RealColors->Text = L"Display Real Colors";
			this->toolStripButton_RealColors->Click += gcnew System::EventHandler(this, &MyForm::ToolStripButton_RealColors_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1114, 765);
			this->Controls->Add(this->toolStrip_View);
			this->Controls->Add(this->glControl);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->statusStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"OpenMKS";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_slicingpoint1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_rightindex))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_leftindex))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Pset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AlignRef))->EndInit();
			this->toolStrip4->ResumeLayout(false);
			this->toolStrip4->PerformLayout();
			this->toolStrip3->ResumeLayout(false);
			this->toolStrip3->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->toolStrip_View->ResumeLayout(false);
			this->toolStrip_View->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int TURN = 0; bool STREAMING = false;
		bool changeparam = true;
	private: void LoadCombos()
	{
		comboBox_ListOfDevices->Items->Clear();
		for (int i = 0; i < Kinect2NB; i++)
			comboBox_ListOfDevices->Items->Add(L"" + (i + 1) + L" - Kinect2 SN: " + myKinect2App[i].GetSerialNumber());
		if (comboBox_ListOfDevices->Items->Count > 0)
			comboBox_ListOfDevices->SelectedIndex = 0;

		LoadBoxColor();
	}
	private: void LoadBoxColor()
	{
		int device = comboBox_ListOfDevices->SelectedIndex;
		if (device >= 0 && device < Kinect2NB)
		{
			button_Color->BackColor = System::Drawing::Color::FromArgb(myKinect2App[device].GlobalColor[0] * 255, myKinect2App[device].GlobalColor[1] * 255, myKinect2App[device].GlobalColor[2] * 255);
		}
		else button_Color->BackColor = System::Drawing::Color::Transparent;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		SETTINGS::Init();
		LOAD_KINECTS_ONLINE();
		
		toolStripStatusLabel->Text = L"Number of Connected Kinects2.0 = " + Kinect2NB;

		LoadCombos();
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		SHUTDOWN_KINECTS_2();
	}
	private: System::Void GlControl_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		int dx = MouseX - e->X;
		int dy = MouseY - e->Y;
		MouseX = e->X;
		MouseY = e->Y;

		if (MouseClicked[0])
		{
			ZoomCam(double(dy) / 50);
			glControl->Invalidate();
		}
		else if (MouseClicked[1])
		{
			RotateCam(double(dy) / 100, double(dx) / 100);
			glControl->Invalidate();
		}
		else if (MouseClicked[2])
		{
			PanCam(-double(dx) / 100, -double(dy) / 100);
			glControl->Invalidate();
		}
	}
private: System::Void GlControl_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == Windows::Forms::MouseButtons::Left) MouseClicked[0] = true;
	else if (e->Button == Windows::Forms::MouseButtons::Right) MouseClicked[1] = true;
	else if (e->Button == Windows::Forms::MouseButtons::Middle) MouseClicked[2] = true;
	MouseX = e->X;
	MouseY = e->Y;
	
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (MouseClicked[0] && device >= 0 && device < Kinect2NB)
	{
		int refindex = Convert::ToInt32(numericUpDown_AlignRef->Value);
		if (toolStripButton_RefPoint->Checked)
			if(myKinect2App[device].RefPoints.size() > refindex)
		{
			DISPLAY_ForSelection(glControl, device);
			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(glControl->Width, glControl->Height);
			System::Drawing::Imaging::BitmapData^ data =
				bmp->LockBits(glControl->ClientRectangle, System::Drawing::Imaging::ImageLockMode::WriteOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			OpenGL::GL::ReadPixels(0, 0, glControl->Width, glControl->Height, OpenGL::PixelFormat::Bgr, OpenGL::PixelType::UnsignedByte, data->Scan0);
			bmp->UnlockBits(data);
			System::Drawing::Color col = bmp->GetPixel(MouseX, glControl->Height - MouseY);
			int p;
			if (col.G == 0) p = -1;
			else
			{
				Eigen::Vector3f Point;
				p = myKinect2App[device].SelectedPoint(col.R, col.G, col.B);
				float V[3]; myKinect2App[device].Points.GetXYZ(p, V);
				myKinect2App[device].AddRefPoint(refindex, V);
				FillRefPointsData(device);

			}
			glControl->Invalidate();
		}
	}
}
private: System::Void GlControl_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	MouseClicked[0] = MouseClicked[1] = MouseClicked[2] = false;
}
private: System::Void GlControl_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	DISPLAY_3D(glControl);
}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (STREAMING && Kinect2NB> 0 )
	{

		FILE* f;
		fopen_s(&f, "debug.txt", "ab");

		toolStripStatusLabel->Text = L"Getting Frame... ";
		timer1->Enabled = false;
		while (TURN < Kinect2NB && !myKinect2App[TURN].started) TURN++;

		if (TURN < Kinect2NB)
		{
			fprintf(f, "Reading  .... Turn = %d ... K2NB = %d ... ", TURN, Kinect2NB);
			if (TURN < Kinect2NB)
			{
				fprintf(f, "OK kinect2   \n");
				if (myKinect2App[TURN].GetDepthFrame(1, SETTINGS::Scan::fill_gaps))
				{
					myKinect2App[TURN].CalculateTransformedCoordinates(myKinect2App[TURN].Rotation, myKinect2App[TURN].Translation);

					if (toolStripButton_ChessBoardDetect->Checked)
					{
						myKinect2App[TURN].DetectChessBoardCorner3D(TURN,-99999, 99999, true);
					}
					
					glControl->Invalidate();
				}
				else toolStripStatusLabel->Text += L"" + (TURN + 1) + L"-Kinect2 not working";
				Sleep(100);
				TURN++;
			}
			else fprintf(f, "  No Kinects  \n");
		}
		else fprintf(f, "  TURN EXCEEDED LIMIT  \n");
		TURN = TURN % Kinect2NB;
		timer1->Enabled = true;

		fclose(f);
	}
	STREAMING = !STREAMING;

}
private: System::Void TrackBar_Cam1thr_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button_Cam1Start_Click(System::Object^ sender, System::EventArgs^ e) {
	STREAMING = true;
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		toolStripButton_ShowPointCloud->Checked = true;
		Surface3D.Clear();
		myKinect2App[device].Clear();
		myKinect2App[device].CalibResults.ClearPoints();
		myKinect2App[device].Start();
		myKinect2App[device].ClearGridPointsData();
		timer1->Enabled = true;
	}
}
private: System::Void Button_Cam1Stop_Click(System::Object^ sender, System::EventArgs^ e) {
	STREAMING = false;
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		toolStripButton_ShowPointCloud->Checked = true;
		Surface3D.Clear();
		myKinect2App[device].Stop();
	}
}
private: void ScanFromAll()
{
	timer1->Enabled = false;
	toolStripButton_ShowPointCloud->Checked = true;
	double t = 0;

	//Sleep(7000);
	//Surface3D.Clear();
	for (int i = 0; i < Kinect2NB; i++)
	{
		myKinect2App[i].Stop(); myKinect2App[i].Clear();
	}


	/*
	FILE* f;
	fopen_s(&f, "kinects.csv", "wb");
	for (int i = 0; i < Kinect2NB; i++)
		fprintf_s(f, "%s, ", myKinect2App[i].serialnumber);
	fprintf_s(f, "\n\r");

	double N = 100;
	for (int n = 0; n < N; n++)
	{
		Sleep(100);
		for (int i = 0; i < Kinect2NB; i++)
		{
			double t = double(clock()) / double(CLOCKS_PER_SEC);;
			myKinect2App[i].Start();
			myKinect2App[i].Stop();
			t = double(clock()) / double(CLOCKS_PER_SEC) - t;
			fprintf_s(f, "%f, ", t);
		}
		fprintf_s(f, "\r");
	}
	fclose(f);
	*/
	t = double(clock()) / double(CLOCKS_PER_SEC);
	for (int i = 0; i < Kinect2NB; i++)
	{
		Sleep(150);
		myKinect2App[i].Start();
		myKinect2App[i].GetDepthFrame(SETTINGS::Scan::frames_number);
		myKinect2App[i].Stop();
	}
	t = double(clock()) / double(CLOCKS_PER_SEC) - t;
	toolStripStatusLabel->Text = L"Data Collection Time: " + t + L"s";

	for (int i = 0; i < Kinect2NB; i++)
		myKinect2App[i].CalculateTransformedCoordinates(myKinect2App[i].Rotation, myKinect2App[i].Translation);
}
private: System::Void Button_OneShot_Click(System::Object^ sender, System::EventArgs^ e) {
	ScanFromAll();
}
private: System::Void Button_Filter1_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		myKinect2App[device].Filter();
		glControl->Invalidate();
		toolStripStatusLabel->Text = L"Outliers from "+(device+1)+L"-Kinect2 pointscloud have been removed successfully";
	}
}
private: System::Void CloudPointToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	openFileDialog->FileName = L"";
	openFileDialog->Filter = L"";
	openFileDialog->ShowDialog();
	if (openFileDialog->FileName->Length > 0)
	{
		Surface3D.Clear();
		toolStripButton_ShowPointCloud->Checked = true;
		sprintf(FileName, "%s", openFileDialog->FileName);
		Surface3D.ImportPoints(FileName);
		glControl->Invalidate();
	}
}
private: System::Void STLFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	openFileDialog->FileName = L"";
	openFileDialog->Filter = L"STL FILE|*.stl";
	openFileDialog->ShowDialog();
	if (openFileDialog->FileName->Length > 0)
	{
		Surface3D.Clear();
		toolStripButton_ShowPointCloud->Checked = true;
		sprintf(FileName, "%s", openFileDialog->FileName);
		Surface3D.ImportPointsFromSTL(FileName);
		glControl->Invalidate();
	}
}
private: System::Void CloudPointsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		sprintf(FileName, "%s", saveFileDialog->FileName);
		Surface3D.ExtractPoints(FileName);
	}
}
private: System::Void STLFileToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"STL FILE|*.stl";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		sprintf(FileName, "%s", saveFileDialog->FileName);
		Surface3D.ExportToSTL(FileName);
	}
}
private: System::Void ToolStripButton_Settings_Click(System::Object^ sender, System::EventArgs^ e) {
	Settings Settings_Form;
	Settings_Form.ShowDialog();
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].ClearRegression();
}
private: System::Void ToolStripButton_ShowPointCloud_Click(System::Object^ sender, System::EventArgs^ e) {
	for( int i=0; i<Kinect2NB; i++)
		myKinect2App[i].DrawPoints = myKinect2App[i].DrawNormals = toolStripButton_ShowPointCloud->Checked;
	
	Surface3D.DrawPoints = toolStripButton_ShowPointCloud->Checked;
	
	glControl->Invalidate();
}
private: void FillRefPointsData(int device)
{
	int refindex = Convert::ToInt32(numericUpDown_AlignRef->Value);
	if (device >= 0 && device < Kinect2NB && refindex >= 0 && refindex < Kinect2NB )
		if (refindex < myKinect2App[device].RefPoints.size())
		{
			Eigen::Vector3f point;
			dataGridView_Pset->Rows->Clear();
			for (int i = 0; i < myKinect2App[device].RefPoints.at(refindex).size(); i++)
			{
				point = myKinect2App[device].RefPoints.at(refindex).at(i);
				dataGridView_Pset->Rows->Add(L"" + point(0), L"" + point(1), L"" + point(2));
			}
		}
}
private: System::Void ComboBox_ListOfDevices_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	float d[2], h[2], v[2];
	if (device >= 0 && device < Kinect2NB)
	{
		changeparam = false;
		FillRefPointsData(device);

		button_Color->BackColor = System::Drawing::Color::FromArgb(myKinect2App[device].GlobalColor[0] * 255, myKinect2App[device].GlobalColor[1] * 255, myKinect2App[device].GlobalColor[2] * 255);
		toolStripButton_KinectDisplay->Checked = myKinect2App[device].DrawPoints;
		numericUpDown_leftindex->Value = Convert::ToDecimal(myKinect2App[device].left_refindex);
		numericUpDown_rightindex->Value = Convert::ToDecimal(myKinect2App[device].right_refindex);
		numericUpDown_slicingpoint1->Value = Convert::ToDecimal(myKinect2App[device].slicing_points[0]);
		numericUpDown_slicingpoint2->Value = Convert::ToDecimal(myKinect2App[device].slicing_points[1]);
		numericUpDown_slicingpoint3->Value = Convert::ToDecimal(myKinect2App[device].slicing_points[2]);

		changeparam = true;
	}
}
private: System::Void Button_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		myKinect2App[device].Clear();
		glControl->Invalidate();
	}
}
private: System::Void Button_StartAll_Click(System::Object^ sender, System::EventArgs^ e) {
	Surface3D.Clear();
	toolStripButton_ShowPointCloud->Checked = true;
	for (int i = 0; i < Kinect2NB; i++)
	{
		myKinect2App[i].Clear();
		myKinect2App[i].Start();
	}
	timer1->Enabled = true;
}
private: System::Void Button_StopAll_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].Stop();
}
private: System::Void Button_FilterAll_Click(System::Object^ sender, System::EventArgs^ e) {
	double t = double(clock()) / double(CLOCKS_PER_SEC);
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].Filter();
	t = double(clock()) / double(CLOCKS_PER_SEC) - t;
	toolStripStatusLabel->Text = L"Filtering Time: " + t + L"s";
	glControl->Invalidate();
}
private: System::Void Button_MeshAll_Click(System::Object^ sender, System::EventArgs^ e) {
	double t = double(clock()) / double(CLOCKS_PER_SEC);
	float V[3];
	for (int i = 0; i < Kinect2NB; i++)
	{
		Surface3D.AddPoints(myKinect2App[i].Points);
		myKinect2App[i].Clear();
	}
	
	if (Surface3D.ClPointsNB > 5)
	{
		Surface3D.CreateMesh();


		t = double(clock()) / double(CLOCKS_PER_SEC) - t;
		System::Console::Write(L"Surface Reconstruction Time: " + t + L"s");
		glControl->Invalidate();
	}
	else System::Console::Write(L"Surface Reconstruction Failed !");
	
}
private: System::Void ToolStripButton_Refresh_Click(System::Object^ sender, System::EventArgs^ e) {
	AllocConsole();
	SHUTDOWN_KINECTS_2();
	LOAD_KINECTS_ONLINE();
	Surface3D.Clear();
	toolStripStatusLabel->Text = L"Number of Connected Kinects2.0 = " + Kinect2NB;
	LoadCombos();
	glControl->Invalidate();
}
private: System::Void Button_Color_Click(System::Object^ sender, System::EventArgs^ e) {

	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		colorDialog->Color = System::Drawing::Color::FromArgb(myKinect2App[device].GlobalColor[0]*255, myKinect2App[device].GlobalColor[1] * 255, myKinect2App[device].GlobalColor[2] * 255);
		colorDialog->ShowDialog();
		button_Color->BackColor = System::Drawing::Color::FromArgb(myKinect2App[device].GlobalColor[0] * 255, myKinect2App[device].GlobalColor[1] * 255, myKinect2App[device].GlobalColor[2] * 255);
		myKinect2App[device].SetGlobalColor(float(colorDialog->Color.R) / 255, float(colorDialog->Color.G) / 255, float(colorDialog->Color.B) / 255);
		
		glControl->Invalidate();
	}
}
private: System::Void ToolStripButton_AdjustTransformation_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB && myKinect2App[device].RefIndex!=-1)
	{
		vector<vector<Eigen::Vector3f>> reference_points;
		reference_points = CreateRefPointsVector(device);
		myKinect2App[device].CaluclateRotationTranslation(reference_points, device);
		//myKinect2App[device].ExportInfors("rotations.txt");

		FillRefPointsData(device);

		glControl->Invalidate();

		float mean, min, max;
		CalculateRegistationError(mean, min, max);
		Console::WriteLine("");
		Console::WriteLine(L"Registration errors:   mean = " + mean + L"      min = " + min + L"      max = " + max);
		Console::WriteLine("");
	}
}
private: System::Void ToolStripButton_ResetTransf_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 1 && device < Kinect2NB && myKinect2App[device].RefIndex!=-1)
	{
		/*
		for (int k = 0; k < 3; k++)
			myKinect2App[device].Pset[k] = myKinect2App[device].Rotation.inverse() * (myKinect2App[device].Pset[k] - myKinect2App[device].Translation);
			*/
		myKinect2App[device].Rotation << 1, 0, 0, 0, 1, 0, 0, 0, 1;
		myKinect2App[device].Translation << 0, 0, 0;
		
		glControl->Invalidate();
	}
}
private: System::Void ToolStripButton_KinectDisplay_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		myKinect2App[device].DrawPoints = toolStripButton_KinectDisplay->Checked;

		glControl->Invalidate();
	}
}
private: System::Void ToolStripButton_Infos_Click(System::Object^ sender, System::EventArgs^ e) {
	CamInfos CamInfos_Form;
	CamInfos_Form.camindex = comboBox_ListOfDevices->SelectedIndex;
	if (CamInfos_Form.camindex >= 0 && CamInfos_Form.camindex < Kinect2NB)
	{
		CamInfos_Form.ShowDialog();
	}
}
private: System::Void ToolStripButton_Import_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			myKinect2App[device].Clear();
			sprintf(FileName, "%s", openFileDialog->FileName);
			myKinect2App[device].ImportPoints(FileName);
			glControl->Invalidate();
		}
	}
}
private: System::Void ToolStripButton_RealColors_Click(System::Object^ sender, System::EventArgs^ e) {
	SETTINGS::Display::pointscolor = toolStripButton_RealColors->Checked;
	glControl->Invalidate();
}
private: System::Void Button_AutoMesh_Click(System::Object^ sender, System::EventArgs^ e) {

	//filter
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].Filter();

	//alighnment

	//filter
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].Filter();

	//send to surface3D
	for (int i = 0; i < Kinect2NB; i++)
	{
		Surface3D.AddPoints(myKinect2App[i].Points);
		myKinect2App[i].Clear();
	}

	//Mesh
	Surface3D.CreateMesh();

	glControl->Invalidate();
}
private: System::Void calibrationToolStripMenuItem_Export_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"CLBR FILE|*.clbr";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		Surface3D.Clear();
		toolStripButton_ShowPointCloud->Checked = true;
		sprintf(FileName, "%s", saveFileDialog->FileName);

		ExportCalibration(FileName);

		glControl->Invalidate();
	}
}
private: System::Void calibrationToolStripMenuItem_Import_Click(System::Object^ sender, System::EventArgs^ e) {
	char FileName[300];
	openFileDialog->FileName = L"";
	openFileDialog->Filter = L"CLBR FILE|*.clbr";
	openFileDialog->ShowDialog();
	if (openFileDialog->FileName->Length > 0)
	{
		Surface3D.Clear();
		toolStripButton_ShowPointCloud->Checked = true;
		sprintf(FileName, "%s", openFileDialog->FileName);

		ImportCalibration(FileName);

		glControl->Invalidate();
	}
}
private: System::Void numericUpDown_AlignRef_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
		FillRefPointsData(device);
}
private: System::Void fromSTLFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"STL FILE|*.stl";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			myKinect2App[device].Clear();
			sprintf(FileName, "%s", openFileDialog->FileName);
			myKinect2App[device].ImportFromSTL(FileName);
			glControl->Invalidate();
		}
	}
}
private: System::Void button_RemoveDupFaces_Click(System::Object^ sender, System::EventArgs^ e) {
	Surface3D.RemoveDuplicateFaces();
	glControl->Invalidate();
}
private: System::Void pointCloudToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		saveFileDialog->FileName = L"";
		saveFileDialog->Filter = L"";
		saveFileDialog->ShowDialog();
		if (saveFileDialog->FileName->Length > 0)
		{
			sprintf(FileName, "%s", saveFileDialog->FileName);
			myKinect2App[device].ExportPoints(FileName);
		}
	}
}
private: System::Void depthRGBFrameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		saveFileDialog->FileName = L"";
		saveFileDialog->Filter = L"Frame File | *.frm";
		saveFileDialog->ShowDialog();
		if (saveFileDialog->FileName->Length > 0)
		{
			sprintf(FileName, "%s", saveFileDialog->FileName);
			myKinect2App[device].ExportFrame(FileName);
		}
	}

}
private: System::Void fromFrameFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"Frame File | *.frm";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			sprintf(FileName, "%s", openFileDialog->FileName);
			myKinect2App[device].ImportFrame(FileName);
			//myKinect2App[device].FillDepthGapes();
			myKinect2App[device].CreateParams();
			myKinect2App[device].CreatePointCloud();
			if(SETTINGS::Scan::fill_gaps) myKinect2App[device].FillDepthGapes();
			myKinect2App[device].CalculateTransformedCoordinates(myKinect2App[device].Rotation, myKinect2App[device].Translation);
			myKinect2App[device].DeleteParams();

			toolStripStatusLabel->Text = L"";

		}
		glControl->Invalidate();
	}
}
private: System::Void toolStripButton_Frame_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		FrameViewer FrameViewer_Form;
		FrameViewer_Form.deviceIndex = device;
		FrameViewer_Form.ShowDialog();
		glControl->Invalidate();
	}
}
private: System::Void calibrationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			sprintf(FileName, "%s", openFileDialog->FileName);
			myKinect2App[device].ImportIntrinsicParams(FileName);
			myKinect2App[device].CreateParams();
			myKinect2App[device].CreatePointCloud();
			myKinect2App[device].CalculateTransformedCoordinates(myKinect2App[device].Rotation, myKinect2App[device].Translation);
			myKinect2App[device].DeleteParams();
		}
		glControl->Invalidate();
	}
}
private: System::Void toolStripButton_ImportPset_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		char FileName[300];
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"PSET File | *.pset";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			sprintf(FileName, "%s", openFileDialog->FileName);
			//FillPsetData(device);

		}
		glControl->Invalidate();
	}
}
private: System::Void toolStripButton_ChessBoardDetect_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		if (toolStripButton_ChessBoardDetect->Checked)
		{
			myKinect2App[device].ClearGridPointsData();
			myKinect2App[device].DetectChessBoardCorner3D(device);
		}

		glControl->Invalidate();
	}
}
private: System::Void lRErrorCompensationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"LR File | *.klr";
		openFileDialog->ShowDialog();

		if (openFileDialog->FileName->Length > 0)
		{
			char filename[500];
			sprintf(filename, "%s", openFileDialog->FileName);
			myKinect2App[device].ImportLinearRegression(filename);
		}
	}
}
private: System::Void numericUpDown_leftindex_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB && changeparam)
	{
		myKinect2App[device].left_refindex = Convert::ToInt32(numericUpDown_leftindex->Value);
		myKinect2App[device].right_refindex = Convert::ToInt32(numericUpDown_rightindex->Value);
		myKinect2App[device].slicing_points[0] = Convert::ToInt32(numericUpDown_slicingpoint1->Value);
		myKinect2App[device].slicing_points[1] = Convert::ToInt32(numericUpDown_slicingpoint2->Value);
		myKinect2App[device].slicing_points[2] = Convert::ToInt32(numericUpDown_slicingpoint3->Value);
	}
	float mean, min, max;
	CalculateRegistationError(mean, min, max);
	Console::WriteLine("");
	Console::WriteLine(L"Registration errors:   mean = " + mean + L"      min = " + min + L"      max = " + max);
	Console::WriteLine("");
}
private: System::Void button_CreateRefPoints_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB)
	{
		int left = myKinect2App[device].left_refindex;
		int right = myKinect2App[device].right_refindex;
		int slice1 = myKinect2App[device].slicing_points[0];
		int slice2 = myKinect2App[device].slicing_points[1];
		int slice3 = myKinect2App[device].slicing_points[2];

		myKinect2App[device].ClearGridPointsData();

		if (left >= 0 && left < Kinect2NB)
			myKinect2App[device].DetectChessBoardCorner3D(left, slice2, slice3, false);

		if( right >= 0 && right < Kinect2NB)
			myKinect2App[device].DetectChessBoardCorner3D(right, slice1, slice2, false);

		FillRefPointsData(device);

		glControl->Invalidate();
	}
}
private: System::Void button_Align02_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;

	for( int i = 1; i < Kinect2NB; i++)
	{
		vector<vector<Eigen::Vector3f>> reference_points;
		reference_points = CreateRefPointsVector(i);
		myKinect2App[i].CaluclateRotationTranslation(reference_points, i);
	}

	if (device >= 0 && device < Kinect2NB) FillRefPointsData(device);


	float mean, min, max;
	CalculateRegistationError(mean, min, max);
	Console::WriteLine("");
	Console::WriteLine(L"Registration errors:   mean = " + mean + L"      min = " + min + L"      max = " + max);
	Console::WriteLine("");

	glControl->Invalidate();
}
private: System::Void button_AlignWithLeftSensor_Click(System::Object^ sender, System::EventArgs^ e) {
	int device = comboBox_ListOfDevices->SelectedIndex;
	if (device >= 0 && device < Kinect2NB && myKinect2App[device].RefIndex != -1)
	{
		int left_index = Convert::ToInt32(numericUpDown_leftindex->Value);
		vector<Eigen::Vector3f> reference_points; reference_points.clear();
		reference_points = myKinect2App[left_index].RefPoints.at(device);
		myKinect2App[device].CaluclateRotationTranslation(reference_points, left_index);
		//myKinect2App[device].ExportInfors("rotations.txt");

		FillRefPointsData(device);

		glControl->Invalidate();

		float mean, min, max;
		CalculateRegistationError(mean, min, max);
		Console::WriteLine("");
		Console::WriteLine(L"Registration errors:   mean = " + mean + L"      min = " + min + L"      max = " + max);
		Console::WriteLine("");
	}
}
};
}
