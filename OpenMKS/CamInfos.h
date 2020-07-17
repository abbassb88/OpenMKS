#include "display.h"

#pragma once

namespace OpenMKS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CamInfos
	/// </summary>
	public ref class CamInfos : public System::Windows::Forms::Form
	{
	public:
		CamInfos(void)
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
		~CamInfos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ dataGridView_GridData;












	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataGridView^ dataGridView_Calib;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;

	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox_YAxis;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox_XAxis;

	private: System::Windows::Forms::Label^ label1;

















	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel_Inter;
















	private: System::Windows::Forms::ComboBox^ comboBox_Itervalue;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox_InterFrame;

	private: System::Windows::Forms::Panel^ panel_Scale;
	private: System::Windows::Forms::Label^ label_ScaleMin;


	private: System::Windows::Forms::Label^ label_ScaleMiddle;

	private: System::Windows::Forms::Label^ label_ScaleMax;

private: System::Windows::Forms::OpenFileDialog^ openFileDialog;

























private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_min;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_max;
private: System::Windows::Forms::CheckBox^ checkBox_FixedScale;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_ChartMin;

private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::NumericUpDown^ numericUpDown_ChartMax;

private: System::Windows::Forms::CheckBox^ checkBox_ChartScale;
private: System::Windows::Forms::Button^ button_SavePNG;






















private: System::Windows::Forms::ToolStrip^ toolStrip1;
private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_SaveExcel;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ExportGPD;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ImportGPD;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;



private: System::Windows::Forms::ToolStripLabel^ toolStripLabel3;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_LinearRegression;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_ExportLinearRegression;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column18;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column17;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column16;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column21;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column22;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column23;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column24;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column19;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column20;
private: System::Windows::Forms::ToolStripButton^ toolStripButton_Recalculate;
private: System::Windows::Forms::Button^ button_removeFrame;




































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CamInfos::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_GridData = (gcnew System::Windows::Forms::DataGridView());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripButton_SaveExcel = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_ExportGPD = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_ImportGPD = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripButton_LinearRegression = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_ExportLinearRegression = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton_Recalculate = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Calib = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox_YAxis = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown_ChartMin = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox_XAxis = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown_ChartMax = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox_ChartScale = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_min = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_FixedScale = (gcnew System::Windows::Forms::CheckBox());
			this->panel_Scale = (gcnew System::Windows::Forms::Panel());
			this->label_ScaleMin = (gcnew System::Windows::Forms::Label());
			this->label_ScaleMax = (gcnew System::Windows::Forms::Label());
			this->label_ScaleMiddle = (gcnew System::Windows::Forms::Label());
			this->panel_Inter = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_SavePNG = (gcnew System::Windows::Forms::Button());
			this->comboBox_InterFrame = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_Itervalue = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_removeFrame = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_GridData))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Calib))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChartMin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChartMax))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_min))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_max))->BeginInit();
			this->panel_Scale->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->ColumnHeadersVisible = false;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(3, 3);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 51;
			this->dataGridView->RowTemplate->Height = 24;
			this->dataGridView->Size = System::Drawing::Size(1286, 656);
			this->dataGridView->TabIndex = 0;
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
			this->tabControl1->Size = System::Drawing::Size(1300, 691);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1292, 662);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"General Info";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView_GridData);
			this->tabPage2->Controls->Add(this->toolStrip1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1292, 662);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Grid Data";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView_GridData
			// 
			this->dataGridView_GridData->AllowUserToAddRows = false;
			this->dataGridView_GridData->AllowUserToDeleteRows = false;
			this->dataGridView_GridData->AllowUserToResizeColumns = false;
			this->dataGridView_GridData->AllowUserToResizeRows = false;
			this->dataGridView_GridData->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView_GridData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_GridData->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(22) {
				this->Column3,
					this->Column18, this->Column17, this->Column4, this->Column5, this->Column6, this->Column7, this->Column12, this->Column13, this->Column14,
					this->Column8, this->Column9, this->Column15, this->Column16, this->Column10, this->Column11, this->Column21, this->Column22,
					this->Column23, this->Column24, this->Column19, this->Column20
			});
			this->dataGridView_GridData->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_GridData->Location = System::Drawing::Point(3, 30);
			this->dataGridView_GridData->Name = L"dataGridView_GridData";
			this->dataGridView_GridData->RowHeadersVisible = false;
			this->dataGridView_GridData->RowHeadersWidth = 51;
			this->dataGridView_GridData->RowTemplate->Height = 24;
			this->dataGridView_GridData->Size = System::Drawing::Size(1286, 629);
			this->dataGridView_GridData->TabIndex = 1;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Frame";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column18
			// 
			this->Column18->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column18->HeaderText = L"grid_y";
			this->Column18->MinimumWidth = 6;
			this->Column18->Name = L"Column18";
			this->Column18->ReadOnly = true;
			// 
			// Column17
			// 
			this->Column17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column17->HeaderText = L"grid_x";
			this->Column17->MinimumWidth = 6;
			this->Column17->Name = L"Column17";
			this->Column17->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"r";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"c";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column6->HeaderText = L"r - cy";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column7->HeaderText = L"c - cx";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column12
			// 
			this->Column12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column12->HeaderText = L"depth";
			this->Column12->MinimumWidth = 6;
			this->Column12->Name = L"Column12";
			this->Column12->ReadOnly = true;
			// 
			// Column13
			// 
			this->Column13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column13->HeaderText = L"H-Dist-Real";
			this->Column13->MinimumWidth = 6;
			this->Column13->Name = L"Column13";
			this->Column13->ReadOnly = true;
			// 
			// Column14
			// 
			this->Column14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column14->HeaderText = L"H-Dist-Meas";
			this->Column14->MinimumWidth = 6;
			this->Column14->Name = L"Column14";
			this->Column14->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column8->HeaderText = L"H-error";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column9
			// 
			this->Column9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column9->HeaderText = L"H-error %";
			this->Column9->MinimumWidth = 6;
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			// 
			// Column15
			// 
			this->Column15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column15->HeaderText = L"V-Dist-Real";
			this->Column15->MinimumWidth = 6;
			this->Column15->Name = L"Column15";
			this->Column15->ReadOnly = true;
			// 
			// Column16
			// 
			this->Column16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column16->HeaderText = L"V-Dist-Meas";
			this->Column16->MinimumWidth = 6;
			this->Column16->Name = L"Column16";
			this->Column16->ReadOnly = true;
			// 
			// Column10
			// 
			this->Column10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column10->HeaderText = L"V-error";
			this->Column10->MinimumWidth = 6;
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			// 
			// Column11
			// 
			this->Column11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column11->HeaderText = L"V-error %";
			this->Column11->MinimumWidth = 6;
			this->Column11->Name = L"Column11";
			this->Column11->ReadOnly = true;
			// 
			// Column21
			// 
			this->Column21->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column21->HeaderText = L"Depth Real";
			this->Column21->MinimumWidth = 6;
			this->Column21->Name = L"Column21";
			this->Column21->ReadOnly = true;
			// 
			// Column22
			// 
			this->Column22->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column22->HeaderText = L"Depth Meas";
			this->Column22->MinimumWidth = 6;
			this->Column22->Name = L"Column22";
			this->Column22->ReadOnly = true;
			// 
			// Column23
			// 
			this->Column23->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column23->HeaderText = L"Depth error";
			this->Column23->MinimumWidth = 6;
			this->Column23->Name = L"Column23";
			this->Column23->ReadOnly = true;
			// 
			// Column24
			// 
			this->Column24->HeaderText = L"Depth error %";
			this->Column24->MinimumWidth = 6;
			this->Column24->Name = L"Column24";
			this->Column24->ReadOnly = true;
			this->Column24->Width = 125;
			// 
			// Column19
			// 
			this->Column19->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column19->HeaderText = L"H square error";
			this->Column19->MinimumWidth = 6;
			this->Column19->Name = L"Column19";
			this->Column19->ReadOnly = true;
			// 
			// Column20
			// 
			this->Column20->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column20->HeaderText = L"V square error";
			this->Column20->MinimumWidth = 6;
			this->Column20->Name = L"Column20";
			this->Column20->ReadOnly = true;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripLabel1,
					this->toolStripButton_SaveExcel, this->toolStripButton_ExportGPD, this->toolStripButton_ImportGPD, this->toolStripSeparator1,
					this->toolStripLabel3, this->toolStripButton_LinearRegression, this->toolStripButton_ExportLinearRegression, this->toolStripSeparator3,
					this->toolStripButton_Recalculate
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 3);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1286, 27);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(48, 24);
			this->toolStripLabel1->Text = L"Data: ";
			// 
			// toolStripButton_SaveExcel
			// 
			this->toolStripButton_SaveExcel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_SaveExcel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_SaveExcel.Image")));
			this->toolStripButton_SaveExcel->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_SaveExcel->Name = L"toolStripButton_SaveExcel";
			this->toolStripButton_SaveExcel->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_SaveExcel->Text = L"Export to Excel";
			this->toolStripButton_SaveExcel->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_SaveExcel_Click);
			// 
			// toolStripButton_ExportGPD
			// 
			this->toolStripButton_ExportGPD->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ExportGPD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ExportGPD.Image")));
			this->toolStripButton_ExportGPD->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ExportGPD->Name = L"toolStripButton_ExportGPD";
			this->toolStripButton_ExportGPD->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ExportGPD->Text = L"Export Data to GPD";
			this->toolStripButton_ExportGPD->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_ExportGPD_Click);
			// 
			// toolStripButton_ImportGPD
			// 
			this->toolStripButton_ImportGPD->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ImportGPD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ImportGPD.Image")));
			this->toolStripButton_ImportGPD->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ImportGPD->Name = L"toolStripButton_ImportGPD";
			this->toolStripButton_ImportGPD->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ImportGPD->Text = L"Import Data from GPD";
			this->toolStripButton_ImportGPD->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_ImportGPD_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(132, 24);
			this->toolStripLabel3->Text = L"Linear Regression: ";
			// 
			// toolStripButton_LinearRegression
			// 
			this->toolStripButton_LinearRegression->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_LinearRegression->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_LinearRegression.Image")));
			this->toolStripButton_LinearRegression->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_LinearRegression->Name = L"toolStripButton_LinearRegression";
			this->toolStripButton_LinearRegression->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_LinearRegression->Text = L"Linear Regression";
			this->toolStripButton_LinearRegression->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_LinearRegression_Click);
			// 
			// toolStripButton_ExportLinearRegression
			// 
			this->toolStripButton_ExportLinearRegression->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_ExportLinearRegression->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_ExportLinearRegression.Image")));
			this->toolStripButton_ExportLinearRegression->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_ExportLinearRegression->Name = L"toolStripButton_ExportLinearRegression";
			this->toolStripButton_ExportLinearRegression->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_ExportLinearRegression->Text = L"toolStripButton2";
			this->toolStripButton_ExportLinearRegression->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_ExportLinearRegression_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButton_Recalculate
			// 
			this->toolStripButton_Recalculate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton_Recalculate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Recalculate.Image")));
			this->toolStripButton_Recalculate->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Recalculate->Name = L"toolStripButton_Recalculate";
			this->toolStripButton_Recalculate->Size = System::Drawing::Size(29, 24);
			this->toolStripButton_Recalculate->Text = L"Recalculate";
			this->toolStripButton_Recalculate->Click += gcnew System::EventHandler(this, &CamInfos::toolStripButton_Recalculate_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView_Calib);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1292, 662);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Calibration";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Calib
			// 
			this->dataGridView_Calib->AllowUserToAddRows = false;
			this->dataGridView_Calib->AllowUserToDeleteRows = false;
			this->dataGridView_Calib->AllowUserToResizeColumns = false;
			this->dataGridView_Calib->AllowUserToResizeRows = false;
			this->dataGridView_Calib->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView_Calib->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Calib->ColumnHeadersVisible = false;
			this->dataGridView_Calib->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView_Calib->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Calib->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Calib->Name = L"dataGridView_Calib";
			this->dataGridView_Calib->RowHeadersVisible = false;
			this->dataGridView_Calib->RowHeadersWidth = 51;
			this->dataGridView_Calib->RowTemplate->Height = 24;
			this->dataGridView_Calib->Size = System::Drawing::Size(1286, 656);
			this->dataGridView_Calib->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Column1";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Column2";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->chart);
			this->tabPage4->Controls->Add(this->panel1);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1292, 662);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Charts";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(3, 51);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(1286, 608);
			this->chart->TabIndex = 1;
			this->chart->Text = L"chart1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->comboBox_YAxis);
			this->panel1->Controls->Add(this->numericUpDown_ChartMin);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->comboBox_XAxis);
			this->panel1->Controls->Add(this->numericUpDown_ChartMax);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->checkBox_ChartScale);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1286, 48);
			this->panel1->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1023, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 17);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Min: ";
			// 
			// comboBox_YAxis
			// 
			this->comboBox_YAxis->FormattingEnabled = true;
			this->comboBox_YAxis->Location = System::Drawing::Point(302, 15);
			this->comboBox_YAxis->Name = L"comboBox_YAxis";
			this->comboBox_YAxis->Size = System::Drawing::Size(121, 24);
			this->comboBox_YAxis->TabIndex = 3;
			this->comboBox_YAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &CamInfos::comboBox_Chart_SelectedIndexChanged);
			// 
			// numericUpDown_ChartMin
			// 
			this->numericUpDown_ChartMin->DecimalPlaces = 7;
			this->numericUpDown_ChartMin->Location = System::Drawing::Point(1116, 14);
			this->numericUpDown_ChartMin->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_ChartMin->Name = L"numericUpDown_ChartMin";
			this->numericUpDown_ChartMin->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_ChartMin->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(250, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y Axis";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(751, 15);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 17);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Max: ";
			// 
			// comboBox_XAxis
			// 
			this->comboBox_XAxis->FormattingEnabled = true;
			this->comboBox_XAxis->Location = System::Drawing::Point(89, 15);
			this->comboBox_XAxis->Name = L"comboBox_XAxis";
			this->comboBox_XAxis->Size = System::Drawing::Size(121, 24);
			this->comboBox_XAxis->TabIndex = 1;
			this->comboBox_XAxis->SelectedIndexChanged += gcnew System::EventHandler(this, &CamInfos::comboBox_Chart_SelectedIndexChanged);
			// 
			// numericUpDown_ChartMax
			// 
			this->numericUpDown_ChartMax->DecimalPlaces = 7;
			this->numericUpDown_ChartMax->Location = System::Drawing::Point(844, 13);
			this->numericUpDown_ChartMax->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_ChartMax->Name = L"numericUpDown_ChartMax";
			this->numericUpDown_ChartMax->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_ChartMax->TabIndex = 9;
			this->numericUpDown_ChartMax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 196608 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X Axis";
			// 
			// checkBox_ChartScale
			// 
			this->checkBox_ChartScale->AutoSize = true;
			this->checkBox_ChartScale->Location = System::Drawing::Point(562, 14);
			this->checkBox_ChartScale->Name = L"checkBox_ChartScale";
			this->checkBox_ChartScale->Size = System::Drawing::Size(86, 21);
			this->checkBox_ChartScale->TabIndex = 8;
			this->checkBox_ChartScale->Text = L"Fix Scale";
			this->checkBox_ChartScale->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::White;
			this->tabPage5->Controls->Add(this->label6);
			this->tabPage5->Controls->Add(this->numericUpDown_min);
			this->tabPage5->Controls->Add(this->label5);
			this->tabPage5->Controls->Add(this->numericUpDown_max);
			this->tabPage5->Controls->Add(this->checkBox_FixedScale);
			this->tabPage5->Controls->Add(this->panel_Scale);
			this->tabPage5->Controls->Add(this->panel_Inter);
			this->tabPage5->Controls->Add(this->panel2);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1292, 662);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Inter";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(949, 202);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Min: ";
			// 
			// numericUpDown_min
			// 
			this->numericUpDown_min->DecimalPlaces = 7;
			this->numericUpDown_min->Location = System::Drawing::Point(1042, 200);
			this->numericUpDown_min->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_min->Name = L"numericUpDown_min";
			this->numericUpDown_min->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_min->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(949, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Max: ";
			// 
			// numericUpDown_max
			// 
			this->numericUpDown_max->DecimalPlaces = 7;
			this->numericUpDown_max->Location = System::Drawing::Point(1042, 158);
			this->numericUpDown_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_max->Name = L"numericUpDown_max";
			this->numericUpDown_max->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_max->TabIndex = 4;
			this->numericUpDown_max->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 196608 });
			// 
			// checkBox_FixedScale
			// 
			this->checkBox_FixedScale->AutoSize = true;
			this->checkBox_FixedScale->Location = System::Drawing::Point(943, 125);
			this->checkBox_FixedScale->Name = L"checkBox_FixedScale";
			this->checkBox_FixedScale->Size = System::Drawing::Size(86, 21);
			this->checkBox_FixedScale->TabIndex = 3;
			this->checkBox_FixedScale->Text = L"Fix Scale";
			this->checkBox_FixedScale->UseVisualStyleBackColor = true;
			this->checkBox_FixedScale->CheckedChanged += gcnew System::EventHandler(this, &CamInfos::comboBox_Itervalue_SelectedIndexChanged);
			// 
			// panel_Scale
			// 
			this->panel_Scale->BackColor = System::Drawing::Color::Transparent;
			this->panel_Scale->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_Scale.BackgroundImage")));
			this->panel_Scale->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel_Scale->Controls->Add(this->label_ScaleMin);
			this->panel_Scale->Controls->Add(this->label_ScaleMax);
			this->panel_Scale->Controls->Add(this->label_ScaleMiddle);
			this->panel_Scale->Location = System::Drawing::Point(558, 69);
			this->panel_Scale->Name = L"panel_Scale";
			this->panel_Scale->Size = System::Drawing::Size(150, 426);
			this->panel_Scale->TabIndex = 2;
			// 
			// label_ScaleMin
			// 
			this->label_ScaleMin->AutoSize = true;
			this->label_ScaleMin->Location = System::Drawing::Point(46, 409);
			this->label_ScaleMin->Name = L"label_ScaleMin";
			this->label_ScaleMin->Size = System::Drawing::Size(49, 17);
			this->label_ScaleMin->TabIndex = 7;
			this->label_ScaleMin->Text = L"-0.005";
			// 
			// label_ScaleMax
			// 
			this->label_ScaleMax->AutoSize = true;
			this->label_ScaleMax->Location = System::Drawing::Point(46, 0);
			this->label_ScaleMax->Name = L"label_ScaleMax";
			this->label_ScaleMax->Size = System::Drawing::Size(44, 17);
			this->label_ScaleMax->TabIndex = 5;
			this->label_ScaleMax->Text = L"0.005";
			// 
			// label_ScaleMiddle
			// 
			this->label_ScaleMiddle->AutoSize = true;
			this->label_ScaleMiddle->Location = System::Drawing::Point(46, 206);
			this->label_ScaleMiddle->Name = L"label_ScaleMiddle";
			this->label_ScaleMiddle->Size = System::Drawing::Size(44, 17);
			this->label_ScaleMiddle->TabIndex = 6;
			this->label_ScaleMiddle->Text = L"0.000";
			// 
			// panel_Inter
			// 
			this->panel_Inter->BackColor = System::Drawing::Color::Transparent;
			this->panel_Inter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel_Inter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Inter->Location = System::Drawing::Point(25, 70);
			this->panel_Inter->Name = L"panel_Inter";
			this->panel_Inter->Size = System::Drawing::Size(512, 424);
			this->panel_Inter->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->button_removeFrame);
			this->panel2->Controls->Add(this->button_SavePNG);
			this->panel2->Controls->Add(this->comboBox_InterFrame);
			this->panel2->Controls->Add(this->comboBox_Itervalue);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1286, 48);
			this->panel2->TabIndex = 0;
			// 
			// button_SavePNG
			// 
			this->button_SavePNG->Location = System::Drawing::Point(704, 9);
			this->button_SavePNG->Name = L"button_SavePNG";
			this->button_SavePNG->Size = System::Drawing::Size(75, 23);
			this->button_SavePNG->TabIndex = 8;
			this->button_SavePNG->Text = L"PNG";
			this->button_SavePNG->UseVisualStyleBackColor = true;
			this->button_SavePNG->Click += gcnew System::EventHandler(this, &CamInfos::button_SavePNG_Click);
			// 
			// comboBox_InterFrame
			// 
			this->comboBox_InterFrame->FormattingEnabled = true;
			this->comboBox_InterFrame->Location = System::Drawing::Point(89, 12);
			this->comboBox_InterFrame->Name = L"comboBox_InterFrame";
			this->comboBox_InterFrame->Size = System::Drawing::Size(186, 24);
			this->comboBox_InterFrame->TabIndex = 3;
			this->comboBox_InterFrame->SelectedIndexChanged += gcnew System::EventHandler(this, &CamInfos::comboBox_Itervalue_SelectedIndexChanged);
			// 
			// comboBox_Itervalue
			// 
			this->comboBox_Itervalue->FormattingEnabled = true;
			this->comboBox_Itervalue->Location = System::Drawing::Point(449, 12);
			this->comboBox_Itervalue->Name = L"comboBox_Itervalue";
			this->comboBox_Itervalue->Size = System::Drawing::Size(186, 24);
			this->comboBox_Itervalue->TabIndex = 2;
			this->comboBox_Itervalue->SelectedIndexChanged += gcnew System::EventHandler(this, &CamInfos::comboBox_Itervalue_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Frame:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(372, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 17);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Value:";
			// 
			// button_removeFrame
			// 
			this->button_removeFrame->Location = System::Drawing::Point(818, 9);
			this->button_removeFrame->Name = L"button_removeFrame";
			this->button_removeFrame->Size = System::Drawing::Size(75, 23);
			this->button_removeFrame->TabIndex = 9;
			this->button_removeFrame->Text = L"remove frame";
			this->button_removeFrame->UseVisualStyleBackColor = true;
			this->button_removeFrame->Click += gcnew System::EventHandler(this, &CamInfos::button_removeFrame_Click);
			// 
			// CamInfos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 691);
			this->Controls->Add(this->tabControl1);
			this->Name = L"CamInfos";
			this->Text = L"CamInfos";
			this->Load += gcnew System::EventHandler(this, &CamInfos::CamInfos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_GridData))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Calib))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChartMin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChartMax))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_min))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_max))->EndInit();
			this->panel_Scale->ResumeLayout(false);
			this->panel_Scale->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Drawing::Bitmap^ bmp_rgb;
		bool combochange = true;
	public: int camindex;
	private: System::Void CamInfos_Load(System::Object^ sender, System::EventArgs^ e) {
		combochange = false;
		float d;
		dataGridView->Rows->Clear();

		dataGridView->Rows->Add(L"IR Params", L"");
		dataGridView->Rows->Add(L"cx", L"" + myKinect2App[camindex].IrParameters.cx);
		dataGridView->Rows->Add(L"cy", L"" + myKinect2App[camindex].IrParameters.cy);
		dataGridView->Rows->Add(L"fx", L"" + myKinect2App[camindex].IrParameters.fx);
		dataGridView->Rows->Add(L"fy", L"" + myKinect2App[camindex].IrParameters.fy);
		dataGridView->Rows->Add(L"k1", L"" + myKinect2App[camindex].IrParameters.k1);
		dataGridView->Rows->Add(L"k2", L"" + myKinect2App[camindex].IrParameters.k2);
		dataGridView->Rows->Add(L"k3", L"" + myKinect2App[camindex].IrParameters.k3);
		dataGridView->Rows->Add(L"p1", L"" + myKinect2App[camindex].IrParameters.p1);
		dataGridView->Rows->Add(L"p2", L"" + myKinect2App[camindex].IrParameters.p2);
		dataGridView->Rows->Add(L"", L"");
		dataGridView->Rows->Add(L"Color Params", L"");
		dataGridView->Rows->Add(L"cx", L"" + myKinect2App[camindex].ColorParameters.cx);
		dataGridView->Rows->Add(L"cy", L"" + myKinect2App[camindex].ColorParameters.cy);
		dataGridView->Rows->Add(L"fx", L"" + myKinect2App[camindex].ColorParameters.fx);
		dataGridView->Rows->Add(L"fy", L"" + myKinect2App[camindex].ColorParameters.fy);
		dataGridView->Rows->Add(L"mx_x0y0", L"" + myKinect2App[camindex].ColorParameters.mx_x0y0);
		dataGridView->Rows->Add(L"mx_x0y1", L"" + myKinect2App[camindex].ColorParameters.mx_x0y1);
		dataGridView->Rows->Add(L"mx_x0y2", L"" + myKinect2App[camindex].ColorParameters.mx_x0y2);
		dataGridView->Rows->Add(L"mx_x0y3", L"" + myKinect2App[camindex].ColorParameters.mx_x0y3);
		dataGridView->Rows->Add(L"mx_x1y0", L"" + myKinect2App[camindex].ColorParameters.mx_x1y0);
		dataGridView->Rows->Add(L"mx_x1y1", L"" + myKinect2App[camindex].ColorParameters.mx_x1y1);
		dataGridView->Rows->Add(L"mx_x1y2", L"" + myKinect2App[camindex].ColorParameters.mx_x1y2);
		dataGridView->Rows->Add(L"mx_x2y0", L"" + myKinect2App[camindex].ColorParameters.mx_x2y0);
		dataGridView->Rows->Add(L"mx_x2y1", L"" + myKinect2App[camindex].ColorParameters.mx_x2y1);
		dataGridView->Rows->Add(L"mx_x3y0", L"" + myKinect2App[camindex].ColorParameters.mx_x3y0);
		dataGridView->Rows->Add(L"", L"");

		for (int i = 0; i < myKinect2App[camindex].RefPoints.size(); i++)
		{
			dataGridView->Rows->Add(L"Points Sets Group " + i, L"");
			for( int j=0; j< myKinect2App[camindex].RefPoints.at(i).size(); j++)
				dataGridView->Rows->Add(L"Pset " + (j + 1), L"" + myKinect2App[camindex].RefPoints.at(i).at(j)(0) + L", " + myKinect2App[camindex].RefPoints.at(i).at(j)(1) + L", " + myKinect2App[camindex].RefPoints.at(i).at(j)(2));
		}

		//Grid Data
		dataGridView_GridData->Rows->Clear();
		
		if (myKinect2App[camindex].GridPointsData.rows() > 0 && myKinect2App[camindex].GridPointsData.cols() >= 16)
			for (int i = 0; i < myKinect2App[camindex].GridPointsData.rows(); i++)
				dataGridView_GridData->Rows->Add(
					L"" + myKinect2App[camindex].GridPointsData(i, 0),
					L"" + myKinect2App[camindex].GridPointsData(i, 1),
					L"" + myKinect2App[camindex].GridPointsData(i, 2),
					L"" + myKinect2App[camindex].GridPointsData(i, 3),
					L"" + myKinect2App[camindex].GridPointsData(i, 4),
					L"" + myKinect2App[camindex].GridPointsData(i, 5),
					L"" + myKinect2App[camindex].GridPointsData(i, 6),
					L"" + myKinect2App[camindex].GridPointsData(i, 7),
					L"" + myKinect2App[camindex].GridPointsData(i, 8),
					L"" + myKinect2App[camindex].GridPointsData(i, 9),
					L"" + myKinect2App[camindex].GridPointsData(i, 10),
					L"" + myKinect2App[camindex].GridPointsData(i, 11),
					L"" + myKinect2App[camindex].GridPointsData(i, 12),
					L"" + myKinect2App[camindex].GridPointsData(i, 13),
					L"" + myKinect2App[camindex].GridPointsData(i, 14),
					L"" + myKinect2App[camindex].GridPointsData(i, 15),
					L"" + myKinect2App[camindex].GridPointsData(i, 16),
					L"" + myKinect2App[camindex].GridPointsData(i, 17),
					L"" + myKinect2App[camindex].GridPointsData(i, 18),
					L"" + myKinect2App[camindex].GridPointsData(i, 19),
					L"" + myKinect2App[camindex].GridPointsData(i, 20),
					L"" + myKinect2App[camindex].GridPointsData(i, 21)
				);
		
		
		//Calibration Data
		dataGridView_Calib->Rows->Clear();

		dataGridView_Calib->Rows->Add(L"cx", L"" + myKinect2App[camindex].CalibResults.cx);
		dataGridView_Calib->Rows->Add(L"cy", L"" + myKinect2App[camindex].CalibResults.cy);
		dataGridView_Calib->Rows->Add(L"fx", L"" + myKinect2App[camindex].CalibResults.fx);
		dataGridView_Calib->Rows->Add(L"fy", L"" + myKinect2App[camindex].CalibResults.fy);
		dataGridView_Calib->Rows->Add(L"k1", L"" + myKinect2App[camindex].CalibResults.k1);
		dataGridView_Calib->Rows->Add(L"k2", L"" + myKinect2App[camindex].CalibResults.k2);
		dataGridView_Calib->Rows->Add(L"k3", L"" + myKinect2App[camindex].CalibResults.k3);
		dataGridView_Calib->Rows->Add(L"p1", L"" + myKinect2App[camindex].CalibResults.p1);
		dataGridView_Calib->Rows->Add(L"p2", L"" + myKinect2App[camindex].CalibResults.p2);

		//comboboxes
		comboBox_XAxis->Items->Clear(); comboBox_YAxis->Items->Clear();  comboBox_Itervalue->Items->Clear();  comboBox_InterFrame->Items->Clear();
		comboBox_XAxis->Items->Add(L"frame");			comboBox_YAxis->Items->Add(L"frame");					comboBox_Itervalue->Items->Add(L"frame");
		comboBox_XAxis->Items->Add(L"grid_y");			comboBox_YAxis->Items->Add(L"grid_y");					comboBox_Itervalue->Items->Add(L"grid_y");
		comboBox_XAxis->Items->Add(L"grid_x");			comboBox_YAxis->Items->Add(L"grid_x");					comboBox_Itervalue->Items->Add(L"grid_x");
		comboBox_XAxis->Items->Add(L"r");				comboBox_YAxis->Items->Add(L"r");						comboBox_Itervalue->Items->Add(L"r");
		comboBox_XAxis->Items->Add(L"c");				comboBox_YAxis->Items->Add(L"c");						comboBox_Itervalue->Items->Add(L"c");
		comboBox_XAxis->Items->Add(L"r - cy");			comboBox_YAxis->Items->Add(L"r - cy");					comboBox_Itervalue->Items->Add(L"r - cy");
		comboBox_XAxis->Items->Add(L"c - cx");			comboBox_YAxis->Items->Add(L"c - cx");					comboBox_Itervalue->Items->Add(L"c - cx");
		comboBox_XAxis->Items->Add(L"depth");			comboBox_YAxis->Items->Add(L"depth");					comboBox_Itervalue->Items->Add(L"depth");
		comboBox_XAxis->Items->Add(L"H dist Real (m)");		comboBox_YAxis->Items->Add(L"H dist Real (m)");		comboBox_Itervalue->Items->Add(L"H dist Real (m)");
		comboBox_XAxis->Items->Add(L"H dist Measured (m)");		comboBox_YAxis->Items->Add(L"H dist Measured (m)");	comboBox_Itervalue->Items->Add(L"H dist Measured (m)");
		comboBox_XAxis->Items->Add(L"H error (m)");		comboBox_YAxis->Items->Add(L"H error (m)");				comboBox_Itervalue->Items->Add(L"H error (m)");
		comboBox_XAxis->Items->Add(L"H error (%)");		comboBox_YAxis->Items->Add(L"H error (%)");				comboBox_Itervalue->Items->Add(L"H error (%)");
		comboBox_XAxis->Items->Add(L"V dist Real (m)");		comboBox_YAxis->Items->Add(L"V dist Real (m)");		comboBox_Itervalue->Items->Add(L"V dist Real (m)");
		comboBox_XAxis->Items->Add(L"V dist Measured (m)");		comboBox_YAxis->Items->Add(L"V dist Measured (m)");	comboBox_Itervalue->Items->Add(L"V dist Measured (m)");
		comboBox_XAxis->Items->Add(L"V error (m)");		comboBox_YAxis->Items->Add(L"V error (m)");				comboBox_Itervalue->Items->Add(L"V error (m)");
		comboBox_XAxis->Items->Add(L"V error (%)");		comboBox_YAxis->Items->Add(L"V error (%)");				comboBox_Itervalue->Items->Add(L"V error (%)");
		
		comboBox_XAxis->Items->Add(L"Depth Real (m)");		comboBox_YAxis->Items->Add(L"Depth Real (m)");		comboBox_Itervalue->Items->Add(L"Depth Real (m)");
		comboBox_XAxis->Items->Add(L"Depth Measured (m)");		comboBox_YAxis->Items->Add(L"Depth Measured (m)");	comboBox_Itervalue->Items->Add(L"Depth Measured (m)");
		comboBox_XAxis->Items->Add(L"Depth error (m)");		comboBox_YAxis->Items->Add(L"Depth error (m)");				comboBox_Itervalue->Items->Add(L"Depth error (m)");
		comboBox_XAxis->Items->Add(L"Depth error (%)");		comboBox_YAxis->Items->Add(L"Depth error (%)");				comboBox_Itervalue->Items->Add(L"Depth error (%)");

		
		
		comboBox_XAxis->Items->Add(L"H square error (m)");		comboBox_YAxis->Items->Add(L"H square error (m)");				comboBox_Itervalue->Items->Add(L"H square error (m)");
		comboBox_XAxis->Items->Add(L"V square error (m)");		comboBox_YAxis->Items->Add(L"V square error (m)");				comboBox_Itervalue->Items->Add(L"V square error (m)");


		if( comboBox_XAxis->Items->Count > 0 )
			comboBox_XAxis->SelectedIndex = 0;

		if (comboBox_YAxis->Items->Count > 0)
		comboBox_YAxis->SelectedIndex = 9;

		if (comboBox_Itervalue->Items->Count > 0)
		comboBox_Itervalue->SelectedIndex = 9;

		//frame comboBox
		int frame = -9999;
		for( int i=0; i<  myKinect2App[camindex].GridPointsData.rows(); i++)
			if (myKinect2App[camindex].GridPointsData(i, 0) != frame)
			{
				frame = myKinect2App[camindex].GridPointsData(i, 0);
				comboBox_InterFrame->Items->Add(L"" + frame);
			}

		if (comboBox_InterFrame->Items->Count > 0)
		comboBox_InterFrame->SelectedIndex = 0;

		combochange = true;
	}
	private: System::Void comboBox_Chart_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (combochange)
		{
			float limit = 10; int N = 0;
			Eigen::VectorXf x = Eigen::VectorXf::Zero(SETTINGS::Scan::regression_order);
			Eigen::VectorXf CorrX = Eigen::VectorXf::Zero(0);
			Eigen::VectorXf CorrY = Eigen::VectorXf::Zero(0);

			float min = 99999, max = -99999;
			float MIN = -99999, MAX = 99999;
			float valueX, valueY;

			//check if min max are set by the user
			if (checkBox_ChartScale->Checked)
			{
				MIN = Convert::ToDouble(numericUpDown_ChartMin->Value);
				MAX = Convert::ToDouble(numericUpDown_ChartMax->Value);
			}

			//set the indexes of the 2 selected variables
			int indexX = comboBox_XAxis->SelectedIndex;
			int indexY = comboBox_YAxis->SelectedIndex;

			//counting rows
			for (int i = 0; i < myKinect2App[camindex].GridPointsData.rows(); i++)
				if (fabs(myKinect2App[camindex].GridPointsData(i, indexY)) <= limit) N++;


			//----------
			MLLib::LINEAR_REGRESSION_CLASS Regression;
			Regression.Clear();
			Regression.SetDimensions(N, SETTINGS::Scan::regression_order);

			chart->Series[0]->Points->Clear();
			chart->Series[1]->Points->Clear();
			N = 0;
			for (int i = 0; i < myKinect2App[camindex].GridPointsData.rows(); i++)
			{
				valueX = myKinect2App[camindex].GridPointsData(i, indexX);
				valueY = myKinect2App[camindex].GridPointsData(i, indexY);

				if (fabs(valueY) <= limit)
					chart->Series[0]->Points->AddXY(valueX, valueY);

				if (fabs(valueY) <= limit)
				{
					for (int k = 0; k < SETTINGS::Scan::regression_order; k++)  x(k) = pow(valueX, float(k + 1));

					if (valueY <= MAX && valueY >= MIN)
					{
						Regression.AddDataRow(N, valueY, x);
						CorrX.conservativeResize(CorrX.size() + 1);		CorrX(CorrX.size() - 1) = valueX;
						CorrY.conservativeResize(CorrY.size() + 1);		CorrY(CorrX.size() - 1) = valueY;
					}
					if (x(0) < min) min = x(0);   if (x(0) > max) max = x(0);
					N++;
				}
			}

			//show the correlation between the two variables in console screen
			Console::WriteLine("Correlation =  " + MathLib::Correlation(CorrX, CorrY));

			//calculate regression to plot the regression curve
			if (Regression.Calculate() && min < max)
			{
				//show regression infos in console screen
				Console::WriteLine(gcnew String(Regression.ConvertToStream().str().c_str()));

				for (float i = min; i <= max; i += (max - min) / 100)
				{
					for (int k = 0; k < SETTINGS::Scan::regression_order; k++)  x(k) = pow(i, float(k + 1));
					chart->Series[1]->Points->AddXY(i, Regression.CalculateValue(x));
				}
			}
		}
	}
	private: System::Void toolStripButton_SaveExcel_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog->FileName = L"";
		saveFileDialog->Filter = L"CSV File | *.csv";
		saveFileDialog->ShowDialog();
		if (saveFileDialog->FileName->Length > 0)
		{
			char filename[500];
			sprintf_s(filename, "%s", saveFileDialog->FileName);
			myKinect2App[camindex].ExportGridPointsData_CSV(filename);
		}
	}
	private: System::Void comboBox_Itervalue_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		//interpolation
		Eigen::MatrixXf M = Eigen::MatrixXf::Zero(424, 512);
		Eigen::MatrixXd ARGB;
		int rows = 0, cols = 0;
		if (comboBox_InterFrame->Items->Count > 0 && comboBox_Itervalue->Items->Count > 0
			&& comboBox_InterFrame->SelectedIndex >= 0 && comboBox_Itervalue->SelectedIndex >= 0)
		{
			int frame = Convert::ToInt32(comboBox_InterFrame->Text);
			int valueindex = comboBox_Itervalue->SelectedIndex;

			double min = 99999, max = -99999;

			InterLib::INTER2D_REGULAR Int2D(512, 424);

			vector<Eigen::Vector3f> points;
			Eigen::Vector3f point;



			for (int i = 0; i < myKinect2App[camindex].GridPointsData.rows(); i++)
				if (frame == myKinect2App[camindex].GridPointsData(i, 0))
				{
					if (rows <= myKinect2App[camindex].GridPointsData(i, 1))
						rows = myKinect2App[camindex].GridPointsData(i, 1) + 1;

					if (cols <= myKinect2App[camindex].GridPointsData(i, 2))
						cols = myKinect2App[camindex].GridPointsData(i, 2) + 1;

					point.y() = myKinect2App[camindex].GridPointsData(i, 3);
					point.x() = myKinect2App[camindex].GridPointsData(i, 4);
					point.z() = myKinect2App[camindex].GridPointsData(i, valueindex);

					if (point.z() < min) min = point.z();
					if (point.z() > max) max = point.z();

					points.push_back(point);
				}


			Int2D.SetGridPoints(points, cols, rows);
			M = Int2D.Interpolate(4);

			min = float(int(min * 100000 - 1)) / 100000;
			max = float(int(max * 100000 + 1)) / 100000;

			if (checkBox_FixedScale->Checked)
			{
				min = Convert::ToDouble(numericUpDown_min->Value);
				max = Convert::ToDouble(numericUpDown_max->Value);
			}

			InterLib::ScalarMatrixToRainbow(M, ARGB, min, max);


			bmp_rgb = gcnew System::Drawing::Bitmap(512, 424);

			for (int r = 0; r < 424; r++) for (int c = 0; c < 512; c++)
				bmp_rgb->SetPixel(c, r, System::Drawing::Color::FromArgb(ARGB(r, c)));

			panel_Inter->BackgroundImage = bmp_rgb;
			panel_Inter->Size = System::Drawing::Size(512, 424);

			panel_Scale->Size = System::Drawing::Size(150, 426);
			panel_Scale->Location = System::Drawing::Point(panel_Inter->Location.X + panel_Inter->Width + 10, panel_Inter->Location.Y - 2);

			label_ScaleMax->Location = System::Drawing::Point(46, 0);
			label_ScaleMiddle->Location = System::Drawing::Point(46, 206);
			label_ScaleMin->Location = System::Drawing::Point(46, 409);

			label_ScaleMax->Text = L"" + max;
			label_ScaleMiddle->Text = L"" + (max + min) / 2;
			label_ScaleMin->Text = L"" + min;
		}
	}
	private: System::Void toolStripButton_ImportGPD_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->FileName = L"";
		openFileDialog->Filter = L"Grid Points Data File | *.GPD";
		openFileDialog->ShowDialog();
		if (openFileDialog->FileName->Length > 0)
		{
			char filename[500];
			sprintf_s(filename, "%s", openFileDialog->FileName);
			myKinect2App[camindex].ImportGridPointsData_GPD(filename);
		}
	}
	private: System::Void toolStripButton_LinearRegression_Click(System::Object^ sender, System::EventArgs^ e) {
		int nan_nb = 0;
		float limit = 10;
		int Nx, Ny, Nd;
		int rows = myKinect2App[camindex].GridPointsData.rows();
		int inputsNB = SETTINGS::Scan::regression_order * 3;

		if (rows > 0)
		{
			//count valid data
			Nx = Ny = Nd = 0;
			for (int i = 0; i < rows; i++)
				if (myKinect2App[camindex].GridPointsData(i, 5) != 0 && myKinect2App[camindex].GridPointsData(i, 6) != 0 && myKinect2App[camindex].GridPointsData(i, 7) != 0)
				{
					if (fabs(myKinect2App[camindex].GridPointsData(i, 11)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 11))) Nx++;

					if (fabs(myKinect2App[camindex].GridPointsData(i, 15)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 15))) Ny++;

					if (fabs(myKinect2App[camindex].GridPointsData(i, 19)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 19))) Nd++;
				}

			Console::WriteLine("NAN NB = " + nan_nb);

			//regression
			Eigen::VectorXf xx = Eigen::VectorXf::Zero(inputsNB);
			myKinect2App[camindex].Regression_calibration_x.Clear();
			myKinect2App[camindex].Regression_calibration_y.Clear();
			myKinect2App[camindex].Regression_calibration_d.Clear();


			myKinect2App[camindex].Regression_calibration_x.SetDimensions(Nx, inputsNB);
			myKinect2App[camindex].Regression_calibration_y.SetDimensions(Ny, inputsNB);
			myKinect2App[camindex].Regression_calibration_d.SetDimensions(Nd, inputsNB);

			int ix = 0, iy = 0, id = 0;
			for (int i = 0; i < rows; i++)
				if (myKinect2App[camindex].GridPointsData(i, 5) != 0 && myKinect2App[camindex].GridPointsData(i, 6) != 0 && myKinect2App[camindex].GridPointsData(i, 7) != 0)
				{
					for (int k = 0; k < SETTINGS::Scan::regression_order; k++)
					{
						xx(0 + k * 3) = pow(myKinect2App[camindex].GridPointsData(i, 5), k + 1);
						xx(1 + k * 3) = pow(myKinect2App[camindex].GridPointsData(i, 6), k + 1);
						xx(2 + k * 3) = pow(myKinect2App[camindex].GridPointsData(i, 7), k + 1);
					}


					if (fabs(myKinect2App[camindex].GridPointsData(i, 11)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 11)))
					{
						myKinect2App[camindex].Regression_calibration_x.AddDataRow(ix, myKinect2App[camindex].GridPointsData(i, 11), xx);
						ix++;
					}

					if (fabs(myKinect2App[camindex].GridPointsData(i, 15)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 15)))
					{
						myKinect2App[camindex].Regression_calibration_y.AddDataRow(iy, myKinect2App[camindex].GridPointsData(i, 15), xx);
						iy++;
					}

					if (fabs(myKinect2App[camindex].GridPointsData(i, 19)) <= limit && !isnan(myKinect2App[camindex].GridPointsData(i, 19)))
					{
						myKinect2App[camindex].Regression_calibration_d.AddDataRow(id, myKinect2App[camindex].GridPointsData(id, 19), xx);
						id++;
					}
				}



			bool BBB = myKinect2App[camindex].Regression_calibration_x.Calculate() && myKinect2App[camindex].Regression_calibration_y.Calculate() && myKinect2App[camindex].Regression_calibration_d.Calculate();


			// showing result
			myKinect2App[camindex].PrintRegressionData();

			for (int k = 0; k < SETTINGS::Scan::regression_order; k++)
			{
				xx(0 + k * 3) = pow(myKinect2App[camindex].GridPointsData(rows - 1, 5), k + 1);
				xx(1 + k * 3) = pow(myKinect2App[camindex].GridPointsData(rows - 1, 6), k + 1);
				xx(2 + k * 3) = pow(myKinect2App[camindex].GridPointsData(rows - 1, 7), k + 1);
			}

			System::String^ S;


			if (BBB)
			{

				Console::WriteLine(L"Regression Done");
				S = L"H e = " + myKinect2App[camindex].GridPointsData(rows - 1, 11) + L"     ex = " + myKinect2App[camindex].Regression_calibration_x.CalculateValue(xx);
				Console::WriteLine(S);

				S = L"V e = " + myKinect2App[camindex].GridPointsData(rows - 1, 15) + L"     ey = " + myKinect2App[camindex].Regression_calibration_y.CalculateValue(xx);
				Console::WriteLine(S);

				S = L"D e = " + myKinect2App[camindex].GridPointsData(rows - 1, 19) + L"     ed = " + myKinect2App[camindex].Regression_calibration_d.CalculateValue(xx);
				Console::WriteLine(S);
			}
			else Console::WriteLine("Error Regression");

			//

		}

	}
	private: System::Void toolStripButton_ExportGPD_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog->FileName = L"";
		saveFileDialog->Filter = L"Grid Points Data File | *.GPD";
		saveFileDialog->ShowDialog();
		if (saveFileDialog->FileName->Length > 0)
		{
			char filename[500];
			sprintf_s(filename, "%s", saveFileDialog->FileName);
			myKinect2App[camindex].ExportGridPointsData_GPD(filename);
		}
	}
	private: System::Void toolStripButton_ExportLinearRegression_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog->FileName = L"";
		saveFileDialog->Filter = L"Linear Regression File | *.klr";
		saveFileDialog->ShowDialog();
		if (saveFileDialog->FileName->Length > 0)
		{
			char filename[500];
			sprintf_s(filename, "%s", saveFileDialog->FileName);
			myKinect2App[camindex].ExportLinearRegression(filename);
		}
	}
private: System::Void button_SavePNG_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"PNG File|*.png";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		panel_Inter->BackgroundImage->Save(saveFileDialog->FileName, System::Drawing::Imaging::ImageFormat::Png);
	}
}
private: System::Void toolStripButton_Recalculate_Click(System::Object^ sender, System::EventArgs^ e) {
	float delta;

	for (int i = 0; i < myKinect2App[camindex].GridPointsData.rows(); i++)
	{
		delta = myKinect2App[camindex].GridPointsData(i, 7) - myKinect2App[camindex].GridPointsData(i, 17);

		myKinect2App[camindex].GridPointsData(i, 16) += delta - SETTINGS::Scan::depth_origin;
		myKinect2App[camindex].GridPointsData(i, 17) += delta - SETTINGS::Scan::depth_origin;

		myKinect2App[camindex].GridPointsData(i, 18) = myKinect2App[camindex].GridPointsData(i, 17) - myKinect2App[camindex].GridPointsData(i, 16);
		if (myKinect2App[camindex].GridPointsData(i, 17) == 0) myKinect2App[camindex].GridPointsData(i, 19) = 0;
		else myKinect2App[camindex].GridPointsData(i, 19) = myKinect2App[camindex].GridPointsData(i, 18) * 100 / myKinect2App[camindex].GridPointsData(i, 17);
	}
}
private: System::Void button_removeFrame_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox_InterFrame->Items->Count > 0 && comboBox_InterFrame->SelectedIndex >= 0)
	{
		int frame_id = Convert::ToInt32(comboBox_InterFrame->Text);

		int corners_nb = 0;
		int rows = myKinect2App[camindex].GridPointsData.rows();
		int cols = myKinect2App[camindex].GridPointsData.cols();
		int rowsToRemove;

		int row_start = 0, row_end = 0;


		while (row_start < rows && myKinect2App[camindex].GridPointsData(row_start, 0) != frame_id)
			row_start++;

		row_end = row_start;
		while (row_end + 1 < rows && myKinect2App[camindex].GridPointsData(row_end + 1, 0) == frame_id)
			row_end++;

		rowsToRemove = row_end - row_start + 1;

		if (row_end < rows - 1)
		{
			myKinect2App[camindex].GridPointsData.block(row_start, 0, rows - 1 - row_end, cols)
				= myKinect2App[camindex].GridPointsData.block(row_end + 1, 0, rows - 1 - row_end, cols);
		}

		myKinect2App[camindex].GridPointsData.conservativeResize(rows - rowsToRemove, cols);

	}
}
};
}
