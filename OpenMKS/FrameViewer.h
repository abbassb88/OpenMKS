#include "ChartWindow.h"

#pragma once

namespace OpenMKS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrameViewer
	/// </summary>
	public ref class FrameViewer : public System::Windows::Forms::Form
	{
	public:
		FrameViewer(void)
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
		~FrameViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_RGB;
	protected:

	private: System::Windows::Forms::TabControl^ tabControl1;

	protected:

	protected:

	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Panel^ panel_Depth;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Panel^ panel_Undist;

	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Panel^ panel_DepthRGB;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Panel^ panel_UndistRGB;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_SaveDepthRGB;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_Calibrate;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView_CamParams;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::Button^ button_ApplyCamParams;
	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_Grid;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_Calculate;

	private: System::Windows::Forms::DataGridView^ dataGridView_Corners;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_SavePointsSet;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_PickColor;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_Draw;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_FillBlank;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_ExportBMP;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton_ImportBMP;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrameViewer::typeid));
			this->panel_RGB = (gcnew System::Windows::Forms::Panel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->panel_Depth = (gcnew System::Windows::Forms::Panel());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->panel_Undist = (gcnew System::Windows::Forms::Panel());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_ApplyCamParams = (gcnew System::Windows::Forms::Button());
			this->dataGridView_CamParams = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_DepthRGB = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_SaveDepthRGB = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_Calibrate = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel_UndistRGB = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_Calculate = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Corners = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_Grid = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_SavePointsSet = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_PickColor = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_Draw = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_FillBlank = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_ExportBMP = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_ImportBMP = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_CamParams))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Corners))->BeginInit();
			this->toolStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_RGB
			// 
			this->panel_RGB->BackColor = System::Drawing::Color::Black;
			this->panel_RGB->Location = System::Drawing::Point(0, 0);
			this->panel_RGB->Name = L"panel_RGB";
			this->panel_RGB->Size = System::Drawing::Size(1920, 1080);
			this->panel_RGB->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1254, 806);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->BackColor = System::Drawing::Color::Black;
			this->tabPage1->Controls->Add(this->panel_RGB);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1246, 777);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"RGB";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Black;
			this->tabPage2->Controls->Add(this->panel_Depth);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1246, 777);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Depth";
			// 
			// panel_Depth
			// 
			this->panel_Depth->BackColor = System::Drawing::Color::White;
			this->panel_Depth->Location = System::Drawing::Point(0, 0);
			this->panel_Depth->Name = L"panel_Depth";
			this->panel_Depth->Size = System::Drawing::Size(512, 424);
			this->panel_Depth->TabIndex = 0;
			this->panel_Depth->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrameViewer::panel_Depth_MouseDown);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Black;
			this->tabPage3->Controls->Add(this->panel_Undist);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1246, 777);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Undistorted";
			// 
			// panel_Undist
			// 
			this->panel_Undist->BackColor = System::Drawing::Color::White;
			this->panel_Undist->Location = System::Drawing::Point(0, 0);
			this->panel_Undist->Name = L"panel_Undist";
			this->panel_Undist->Size = System::Drawing::Size(512, 424);
			this->panel_Undist->TabIndex = 1;
			// 
			// tabPage4
			// 
			this->tabPage4->AutoScroll = true;
			this->tabPage4->BackColor = System::Drawing::Color::Black;
			this->tabPage4->Controls->Add(this->panel1);
			this->tabPage4->Controls->Add(this->panel_DepthRGB);
			this->tabPage4->Controls->Add(this->toolStrip1);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1246, 777);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Depth + RGB";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->button_ApplyCamParams);
			this->panel1->Controls->Add(this->dataGridView_CamParams);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(3, 30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 744);
			this->panel1->TabIndex = 2;
			// 
			// button_ApplyCamParams
			// 
			this->button_ApplyCamParams->Location = System::Drawing::Point(10, 390);
			this->button_ApplyCamParams->Name = L"button_ApplyCamParams";
			this->button_ApplyCamParams->Size = System::Drawing::Size(84, 26);
			this->button_ApplyCamParams->TabIndex = 0;
			this->button_ApplyCamParams->Text = L"Apply";
			this->button_ApplyCamParams->UseVisualStyleBackColor = true;
			this->button_ApplyCamParams->Click += gcnew System::EventHandler(this, &FrameViewer::button_ApplyCamParams_Click);
			// 
			// dataGridView_CamParams
			// 
			this->dataGridView_CamParams->AllowUserToAddRows = false;
			this->dataGridView_CamParams->AllowUserToDeleteRows = false;
			this->dataGridView_CamParams->AllowUserToResizeColumns = false;
			this->dataGridView_CamParams->AllowUserToResizeRows = false;
			this->dataGridView_CamParams->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView_CamParams->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView_CamParams->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_CamParams->ColumnHeadersVisible = false;
			this->dataGridView_CamParams->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView_CamParams->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGridView_CamParams->Location = System::Drawing::Point(0, 0);
			this->dataGridView_CamParams->Name = L"dataGridView_CamParams";
			this->dataGridView_CamParams->RowHeadersVisible = false;
			this->dataGridView_CamParams->RowHeadersWidth = 51;
			this->dataGridView_CamParams->RowTemplate->Height = 24;
			this->dataGridView_CamParams->Size = System::Drawing::Size(250, 384);
			this->dataGridView_CamParams->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Column1";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Column2";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// panel_DepthRGB
			// 
			this->panel_DepthRGB->BackColor = System::Drawing::Color::White;
			this->panel_DepthRGB->Location = System::Drawing::Point(280, 55);
			this->panel_DepthRGB->Name = L"panel_DepthRGB";
			this->panel_DepthRGB->Size = System::Drawing::Size(512, 424);
			this->panel_DepthRGB->TabIndex = 1;
			this->panel_DepthRGB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrameViewer::panel_DepthRGB_MouseDown);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton_SaveDepthRGB,
					this->toolStripButton_Calibrate
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 3);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1240, 27);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton_SaveDepthRGB
			// 
			this->toolStripButton_SaveDepthRGB->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_SaveDepthRGB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_SaveDepthRGB.Image")));
			this->toolStripButton_SaveDepthRGB->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_SaveDepthRGB->Name = L"toolStripButton_SaveDepthRGB";
			this->toolStripButton_SaveDepthRGB->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_SaveDepthRGB->Text = L"toolStripButton1";
			this->toolStripButton_SaveDepthRGB->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_SaveDepthRGB_Click);
			// 
			// toolStripButton_Calibrate
			// 
			this->toolStripButton_Calibrate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Calibrate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Calibrate.Image")));
			this->toolStripButton_Calibrate->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Calibrate->Name = L"toolStripButton_Calibrate";
			this->toolStripButton_Calibrate->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Calibrate->Text = L"Calibrate";
			this->toolStripButton_Calibrate->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton1_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::White;
			this->tabPage5->Controls->Add(this->panel3);
			this->tabPage5->Controls->Add(this->panel2);
			this->tabPage5->Controls->Add(this->toolStrip2);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1246, 777);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Undistored + RGB";
			// 
			// panel3
			// 
			this->panel3->AutoScroll = true;
			this->panel3->Controls->Add(this->panel_UndistRGB);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(253, 30);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(990, 744);
			this->panel3->TabIndex = 5;
			// 
			// panel_UndistRGB
			// 
			this->panel_UndistRGB->BackColor = System::Drawing::Color::White;
			this->panel_UndistRGB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_UndistRGB->Location = System::Drawing::Point(6, 3);
			this->panel_UndistRGB->Name = L"panel_UndistRGB";
			this->panel_UndistRGB->Size = System::Drawing::Size(512, 424);
			this->panel_UndistRGB->TabIndex = 2;
			this->panel_UndistRGB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrameViewer::panel_UndistRGB_MouseDown);
			this->panel_UndistRGB->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrameViewer::panel_UndistRGB_MouseMove);
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::SystemColors::Control;
			this->panel2->Controls->Add(this->button_Calculate);
			this->panel2->Controls->Add(this->dataGridView_Corners);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(3, 30);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(250, 744);
			this->panel2->TabIndex = 4;
			// 
			// button_Calculate
			// 
			this->button_Calculate->Location = System::Drawing::Point(10, 390);
			this->button_Calculate->Name = L"button_Calculate";
			this->button_Calculate->Size = System::Drawing::Size(84, 26);
			this->button_Calculate->TabIndex = 0;
			this->button_Calculate->Text = L"Calculate";
			this->button_Calculate->UseVisualStyleBackColor = true;
			this->button_Calculate->Click += gcnew System::EventHandler(this, &FrameViewer::button_Calculate_Click);
			// 
			// dataGridView_Corners
			// 
			this->dataGridView_Corners->AllowUserToAddRows = false;
			this->dataGridView_Corners->AllowUserToDeleteRows = false;
			this->dataGridView_Corners->AllowUserToResizeColumns = false;
			this->dataGridView_Corners->AllowUserToResizeRows = false;
			this->dataGridView_Corners->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView_Corners->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView_Corners->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Corners->ColumnHeadersVisible = false;
			this->dataGridView_Corners->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView_Corners->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGridView_Corners->Location = System::Drawing::Point(0, 0);
			this->dataGridView_Corners->Name = L"dataGridView_Corners";
			this->dataGridView_Corners->RowHeadersVisible = false;
			this->dataGridView_Corners->RowHeadersWidth = 51;
			this->dataGridView_Corners->RowTemplate->Height = 24;
			this->dataGridView_Corners->Size = System::Drawing::Size(250, 384);
			this->dataGridView_Corners->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Column1";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Column2";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// toolStrip2
			// 
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripButton_Grid,
					this->toolStripButton_SavePointsSet, this->toolStripSeparator1, this->toolStripButton_PickColor, this->toolStripButton_Draw,
					this->toolStripSeparator2, this->toolStripButton_FillBlank, this->toolStripSeparator3, this->toolStripButton_ExportBMP, this->toolStripButton_ImportBMP
			});
			this->toolStrip2->Location = System::Drawing::Point(3, 3);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(1240, 27);
			this->toolStrip2->TabIndex = 3;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// toolStripButton_Grid
			// 
			this->toolStripButton_Grid->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Grid->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Grid.Image")));
			this->toolStripButton_Grid->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Grid->Name = L"toolStripButton_Grid";
			this->toolStripButton_Grid->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Grid->Text = L"Detect Grid";
			this->toolStripButton_Grid->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_Grid_Click);
			// 
			// toolStripButton_SavePointsSet
			// 
			this->toolStripButton_SavePointsSet->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_SavePointsSet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_SavePointsSet.Image")));
			this->toolStripButton_SavePointsSet->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_SavePointsSet->Name = L"toolStripButton_SavePointsSet";
			this->toolStripButton_SavePointsSet->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_SavePointsSet->Text = L"Save Points Set";
			this->toolStripButton_SavePointsSet->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_SavePointsSet_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_PickColor
			// 
			this->toolStripButton_PickColor->CheckOnClick = true;
			this->toolStripButton_PickColor->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_PickColor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_PickColor.Image")));
			this->toolStripButton_PickColor->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_PickColor->Name = L"toolStripButton_PickColor";
			this->toolStripButton_PickColor->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_PickColor->Text = L"Pick Color";
			// 
			// toolStripButton_Draw
			// 
			this->toolStripButton_Draw->CheckOnClick = true;
			this->toolStripButton_Draw->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Draw->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Draw.Image")));
			this->toolStripButton_Draw->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Draw->Name = L"toolStripButton_Draw";
			this->toolStripButton_Draw->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Draw->Text = L"Draw";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_FillBlank
			// 
			this->toolStripButton_FillBlank->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_FillBlank->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_FillBlank.Image")));
			this->toolStripButton_FillBlank->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_FillBlank->Name = L"toolStripButton_FillBlank";
			this->toolStripButton_FillBlank->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_FillBlank->Text = L"Fill Blank";
			this->toolStripButton_FillBlank->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_FillBlank_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_ExportBMP
			// 
			this->toolStripButton_ExportBMP->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ExportBMP->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ExportBMP.Image")));
			this->toolStripButton_ExportBMP->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ExportBMP->Name = L"toolStripButton_ExportBMP";
			this->toolStripButton_ExportBMP->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ExportBMP->Text = L"Export to BMP";
			this->toolStripButton_ExportBMP->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_ExportBMP_Click);
			// 
			// toolStripButton_ImportBMP
			// 
			this->toolStripButton_ImportBMP->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ImportBMP->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ImportBMP.Image")));
			this->toolStripButton_ImportBMP->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ImportBMP->Name = L"toolStripButton_ImportBMP";
			this->toolStripButton_ImportBMP->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ImportBMP->Text = L"Import from BMP";
			this->toolStripButton_ImportBMP->Click += gcnew System::EventHandler(this, &FrameViewer::toolStripButton_ImportBMP_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// FrameViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1254, 806);
			this->Controls->Add(this->tabControl1);
			this->Name = L"FrameViewer";
			this->Text = L"FrameViewer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FrameViewer::FrameViewer_FormClosing);
			this->Load += gcnew System::EventHandler(this, &FrameViewer::FrameViewer_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_CamParams))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Corners))->EndInit();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->ResumeLayout(false);

		}
	public: int deviceIndex = -1;
		  System::Drawing::Bitmap^ bmp_rgb;
		  System::Drawing::Bitmap^ bmp_ir;
		  System::Drawing::Bitmap^ bmp_ir_undist;
		  System::Drawing::Bitmap^ bmp_ir_rgb;
		  System::Drawing::Bitmap^ bmp_ir_undist_rgb;
		  CVLib::CalibrationResults *CalibResults;
#pragma endregion
	private: System::Void FrameViewer_Load(System::Object^ sender, System::EventArgs^ e) {
		int n = SETTINGS::Scan::upsampling_factor;
		CalibResults = new CVLib::CalibrationResults();

		//panel_RgbSelect->Location = System::Drawing::Point(-20, -20);
		bmp_rgb = gcnew System::Drawing::Bitmap(1920, 1080);
		bmp_ir = gcnew System::Drawing::Bitmap(512, 424);
		bmp_ir_undist = gcnew System::Drawing::Bitmap(512, 424);
		bmp_ir_rgb = gcnew System::Drawing::Bitmap(512 * n, 424 * n);
		bmp_ir_undist_rgb = gcnew System::Drawing::Bitmap(512 * n, 424 * n);

		//myKinect2App[deviceIndex].RgbToBitmap(bmp_rgb);
		//myKinect2App[deviceIndex].DepthToBitmap(bmp_ir);
		//myKinect2App[deviceIndex].UndistortedDepthToBitmap(bmp_ir_undist);
		//myKinect2App[deviceIndex].DepthRGBToBitmap(bmp_ir_rgb);
		myKinect2App[deviceIndex].UndistRGBToBitmap(bmp_ir_undist_rgb);

		panel_RGB->BackgroundImage = bmp_rgb;
		panel_RGB->Size = System::Drawing::Size(1920, 1080);

		panel_Depth->BackgroundImage = bmp_ir;
		panel_Depth->Size = System::Drawing::Size(512, 424);

		panel_Undist->BackgroundImage = bmp_ir_undist;
		panel_Undist->Size = System::Drawing::Size(512, 424);

		panel_DepthRGB->BackgroundImage = bmp_ir_rgb;
		panel_DepthRGB->Size = System::Drawing::Size(512 * n, 424 * n);

		panel_UndistRGB->BackgroundImage = bmp_ir_undist_rgb;
		panel_UndistRGB->Size = System::Drawing::Size(512 * n, 424 * n);

		//fill cam params data
		dataGridView_CamParams->Rows->Clear();
		dataGridView_CamParams->Rows->Add(L"fx", L"" + myKinect2App[deviceIndex].IrParameters.fx);
		dataGridView_CamParams->Rows->Add(L"fy", L"" + myKinect2App[deviceIndex].IrParameters.fy);
		dataGridView_CamParams->Rows->Add(L"cx", L"" + myKinect2App[deviceIndex].IrParameters.cx);
		dataGridView_CamParams->Rows->Add(L"cy", L"" + myKinect2App[deviceIndex].IrParameters.cy);
		dataGridView_CamParams->Rows->Add(L"k1", L"" + myKinect2App[deviceIndex].IrParameters.k1);
		dataGridView_CamParams->Rows->Add(L"k2", L"" + myKinect2App[deviceIndex].IrParameters.k2);
		dataGridView_CamParams->Rows->Add(L"k3", L"" + myKinect2App[deviceIndex].IrParameters.k3);
		dataGridView_CamParams->Rows->Add(L"p1", L"" + myKinect2App[deviceIndex].IrParameters.p1);
		dataGridView_CamParams->Rows->Add(L"p2", L"" + myKinect2App[deviceIndex].IrParameters.p2);
	}
private: System::Void panel_Depth_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	const float color_cx = myKinect2App[deviceIndex].ColorParameters.cx + 0.5f;
	float rx = -1, ry = -1;
	float mx = e->X, my = e->Y;
	float shift_m = myKinect2App[deviceIndex].ColorParameters.shift_m;
	float fx = myKinect2App[deviceIndex].ColorParameters.fx;
	float z = myKinect2App[deviceIndex].depth_data[int(mx) + int(my) * 512];
	myKinect2App[deviceIndex].depth_to_color(mx, my, rx, ry);
	rx = (rx + (shift_m / z)) * fx + color_cx;
	Text = L"" + mx + L"   |   " + my + L"       |      [ " + rx + L" , " + ry + L" ]";
	//panel_RgbSelect->Location = System::Drawing::Point(rx, ry);
}
private: System::Void toolStripButton_SaveDepthRGB_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"PNG Image | *.png";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		panel_DepthRGB->BackgroundImage->Save(saveFileDialog->FileName, System::Drawing::Imaging::ImageFormat::Png);
	}
}
private: System::Void panel_DepthRGB_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void panel_UndistRGB_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int n = SETTINGS::Scan::upsampling_factor;
	int x = e->X, y = e->Y;
	float index_x = float(x) / float(n), index_y = float(y) / float(n);
	int size_depth = 512 * 424 * n;
	float z, d[4], f1_x, f2_x, f1_y, f2_y; int indexes[4];

	indexes[0] = int(index_x) + int(index_y) * 512;

	if (toolStripButton_PickColor->Checked)
	{
		toolStripButton_PickColor->BackColor = System::Drawing::Color::FromArgb(myKinect2App[deviceIndex].UndistRGBpixel(y, x));
		toolStripButton_PickColor->Checked = false;
	}
	else if (index_x == float(int(index_x)) && index_y == float(int(index_y)))
		z = myKinect2App[deviceIndex].depth_data[indexes[0]];
	else
	{
		indexes[0] = int(index_x) + int(index_y) * 512;
		indexes[1] = int(index_x + 1) + int(index_y) * 512;
		indexes[2] = int(index_x) + int(index_y + 1) * 512;
		indexes[3] = int(index_x + 1) + int(index_y + 1) * 512;

		f1_x = index_x - int(index_x); f2_x = 1 - f1_x;
		f1_y = index_y - int(index_y); f2_y = 1 - f1_y;

		d[0] = pow(sqrt(f1_x * f1_x + f1_y * f1_y), SETTINGS::Scan::interpolation_factor);
		d[1] = pow(sqrt(f2_x * f2_x + f1_y * f1_y), SETTINGS::Scan::interpolation_factor);
		d[2] = pow(sqrt(f1_x * f1_x + f2_y * f2_y), SETTINGS::Scan::interpolation_factor);
		d[3] = pow(sqrt(f2_x * f2_x + f2_y * f2_y), SETTINGS::Scan::interpolation_factor);

		z = 0; float w = 0;
		for (int k = 0; k < 4; k++) if (indexes[k] < size_depth && myKinect2App[deviceIndex].depth_data[indexes[k]] > 0.5)
		{
			z += myKinect2App[deviceIndex].depth_data[indexes[k]] / d[k];
			w += 1 / d[k];
		}
		if (w == 0) z = 0;
		else z /= w;
	}
	Text = L"" + x + L"   |   " + y + L"   |   " + z;
}
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	unsigned int *IMAGE;

	//Image dimensions
	int width = bmp_ir_rgb->Size.Width, height = bmp_ir_rgb->Size.Height;

	//IMAGE POINTER
	IMAGE = new unsigned int[width * height];


	//Fill Image
	for( int r=0; r < height; r++)
		for (int c = 0; c < width; c++)
		{
			System::Drawing::Color ^C = bmp_ir_rgb->GetPixel(c, r);
			IMAGE[r * width + c] = C->ToArgb();
		}
	CVLib::CalibrationSettings s; CVLib::CalibrationResults r; CVLib::CalibrationResults r2;
	s.squareSize = 0.0896666;
	if (CalibrateCameraFromImage(IMAGE, width, height, s, &r))
	{
		DrawCorners(panel_DepthRGB, bmp_ir_rgb, &r);
	}

	//delete IMAGE pointer
	delete[] IMAGE;

	//fill cam params data
	dataGridView_CamParams->Rows->Clear();
	dataGridView_CamParams->Rows->Add(L"fx", L"" + r.fx);
	dataGridView_CamParams->Rows->Add(L"fy", L"" + r.fy);
	dataGridView_CamParams->Rows->Add(L"cx", L"" + r.cx);
	dataGridView_CamParams->Rows->Add(L"cy", L"" + r.cy);
	dataGridView_CamParams->Rows->Add(L"k1", L"" + r.k1);
	dataGridView_CamParams->Rows->Add(L"k2", L"" + r.k2);
	dataGridView_CamParams->Rows->Add(L"k3", L"" + r.k3);
	dataGridView_CamParams->Rows->Add(L"p1", L"" + r.p1);
	dataGridView_CamParams->Rows->Add(L"p2", L"" + r.p2);
}
private: System::Void button_ApplyCamParams_Click(System::Object^ sender, System::EventArgs^ e) {
	myKinect2App[deviceIndex].IrParameters.fx = Convert::ToDouble(dataGridView_CamParams[1, 0]->Value);
	myKinect2App[deviceIndex].IrParameters.fy = Convert::ToDouble(dataGridView_CamParams[1, 1]->Value);
	myKinect2App[deviceIndex].IrParameters.cx = Convert::ToDouble(dataGridView_CamParams[1, 2]->Value);
	myKinect2App[deviceIndex].IrParameters.cy = Convert::ToDouble(dataGridView_CamParams[1, 3]->Value);
	myKinect2App[deviceIndex].IrParameters.k1 = Convert::ToDouble(dataGridView_CamParams[1, 4]->Value);
	myKinect2App[deviceIndex].IrParameters.k2 = Convert::ToDouble(dataGridView_CamParams[1, 5]->Value);
	myKinect2App[deviceIndex].IrParameters.k3 = Convert::ToDouble(dataGridView_CamParams[1, 6]->Value);
	myKinect2App[deviceIndex].IrParameters.p1 = Convert::ToDouble(dataGridView_CamParams[1, 7]->Value);
	myKinect2App[deviceIndex].IrParameters.p2 = Convert::ToDouble(dataGridView_CamParams[1, 8]->Value);

	myKinect2App[deviceIndex].CreateParams();
	myKinect2App[deviceIndex].CreatePointCloud();
	myKinect2App[deviceIndex].CalculateTransformedCoordinates(myKinect2App[deviceIndex].Rotation, myKinect2App[deviceIndex].Translation);
	myKinect2App[deviceIndex].DeleteParams();
}
private: System::Void toolStripButton_Grid_Click(System::Object^ sender, System::EventArgs^ e) {

	myKinect2App[deviceIndex].DetectChessBoardCorner2D(SETTINGS::calibsettings, CalibResults);
	dataGridView_Corners->Rows->Clear();
	if (CalibResults->GetFramesNB() > 0)
	{
		int frame = CalibResults->GetFramesNB() - 1;
		if (CalibResults->GetCornersNB(frame) > 0)
		{
			float x, y;
			for (int i = 0; i < CalibResults->GetCornersNB(frame); i++)
			{
				CalibResults->GetCornerPoint(frame, i, x, y);
				dataGridView_Corners->Rows->Add(L"" + x, L"" + y);
			}
			DrawCorners(panel_UndistRGB, bmp_ir_undist_rgb, CalibResults);
		}
	}
	Text = L"" + CalibResults->GridColsNB + L"    " + CalibResults->GridRowsNB;
}
private: System::Void FrameViewer_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	delete bmp_rgb;
	delete bmp_ir;
	delete bmp_ir_undist;
	delete bmp_ir_rgb;
	delete bmp_ir_undist_rgb;
	if (CalibResults != NULL) { delete CalibResults; CalibResults = NULL; }
}
private: void DrawCorners(System::Windows::Forms::Panel ^p, System::Drawing::Bitmap ^bmp, CVLib::CalibrationResults *r)
{
	int frame = r->GetFramesNB() - 1;
	int PNB = r->GetCornersNB(frame);
	float x = 0, y = 0;
	System::Drawing::Graphics^ g = p->CreateGraphics();
	g->Clear(System::Drawing::Color::White);
	g->DrawImage(bmp, 0, 0, bmp->Width, bmp->Height);

	System::Drawing::Brush^ b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
	for (int i = 0; i < PNB; i++)
	{
		r->GetCornerPoint(frame, i, x, y);
		g->FillEllipse(b, int(x - 6), int(y - 6), 13, 13);
	}

	Text = L"" + r->GridColsNB + L"    " + r->GridRowsNB;
}
private: vector<Eigen::Vector3f> CalculateGird3D(CVLib::CalibrationResults* r){
	vector<Eigen::Vector3f> Points3D;
	myKinect2App[deviceIndex].CreateParams();
	Points3D = myKinect2App[deviceIndex].ConvertChessBoardTo3D(r);
	myKinect2App[deviceIndex].DeleteParams();
	return Points3D;
}
private: System::Void button_Calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	if(CalibResults->GetFramesNB()>0)
		if (CalibResults->GetCornersNB(CalibResults->GetFramesNB() - 1) > 0)
		{
			vector<Eigen::Vector3f> Points3D;
			myKinect2App[deviceIndex].ClearGridPointsData();
			Points3D = myKinect2App[deviceIndex].ConvertChessBoardTo3D(CalibResults);
			myKinect2App[deviceIndex].CalculateGridDimensionsErrors(Points3D, CalibResults);
			myKinect2App[deviceIndex].AddPointsSet(Points3D, deviceIndex);

			ChartWindow ChartWnd;
			ChartWnd.FillData(myKinect2App[deviceIndex].GridPointsData);
			ChartWnd.ShowDialog();
		}
}
private: System::Void toolStripButton_SavePointsSet_Click(System::Object^ sender, System::EventArgs^ e) {
	if(CalibResults->GetFramesNB() > 0)
		if(CalibResults->GetCornersNB(CalibResults->GetFramesNB()-1) > 0)
		CalibResults->write("imagepoints.pset");
}
private: System::Void panel_UndistRGB_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int x = e->X, y = e->Y;
	if (e->Button == System::Windows::Forms::MouseButtons::Left && toolStripButton_Draw->Checked)
	{
		for (int c = x - 1; c <= x + 1; c++) for (int r = y - 1; r <= y + 1; r++)
			if (c >= 0 && c < bmp_ir_undist_rgb->Width && r >= 0 && r < bmp_ir_undist_rgb->Height)
			{
				myKinect2App[deviceIndex].ModifyUndistRGBpixel(r, c, toolStripButton_PickColor->BackColor.ToArgb());
				bmp_ir_undist_rgb->SetPixel(c, r, toolStripButton_PickColor->BackColor);
			}

		System::Drawing::Graphics^ g = panel_UndistRGB->CreateGraphics();
		System::Drawing::Brush^ b = gcnew System::Drawing::SolidBrush(toolStripButton_PickColor->BackColor);
		panel_UndistRGB->BackgroundImage = bmp_ir_undist_rgb;
		g->FillRectangle(b, System::Drawing::Rectangle(x-1, y-1, 3, 3));
	}
}
private: System::Void toolStripButton_FillBlank_Click(System::Object^ sender, System::EventArgs^ e) {
	unsigned int color = toolStripButton_PickColor->BackColor.ToArgb();
	myKinect2App[deviceIndex].UndistRGB_FillBlank(color);

	myKinect2App[deviceIndex].UndistRGBToBitmap(bmp_ir_undist_rgb);
	panel_UndistRGB->BackgroundImage = bmp_ir_undist_rgb;
	panel_UndistRGB->Invalidate();
}
private: System::Void toolStripButton_ExportBMP_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"PNG Image|*.png";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		bmp_ir_undist_rgb->Save(saveFileDialog->FileName);
	}
}
private: System::Void toolStripButton_ImportBMP_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog->FileName = L"";
	openFileDialog->Filter = L"PNG Image|*.png";
	openFileDialog->ShowDialog();
	if (openFileDialog->FileName->Length > 0)
	{
		System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(openFileDialog->FileName);
		myKinect2App[deviceIndex].UndistRGB_FromBMP(bmp);
		panel_UndistRGB->BackgroundImage = bmp;
		panel_UndistRGB->Invalidate();
	}
}
};
}
