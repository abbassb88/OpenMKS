#include "CamInfos.h"
#pragma once

namespace OpenMKS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChartWindow
	/// </summary>
	public ref class ChartWindow : public System::Windows::Forms::Form
	{
	public:
		ChartWindow(void)
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
		~ChartWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox_Y;
	private: System::Windows::Forms::ComboBox^ comboBox_X;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_data;
	private: System::Windows::Forms::Button^ button_save_data;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_save_data = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Y = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_X = (gcnew System::Windows::Forms::ComboBox());
			this->chart_data = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_data))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button_save_data);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->comboBox_Y);
			this->panel1->Controls->Add(this->comboBox_X);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1076, 54);
			this->panel1->TabIndex = 0;
			// 
			// button_save_data
			// 
			this->button_save_data->Location = System::Drawing::Point(498, 12);
			this->button_save_data->Name = L"button_save_data";
			this->button_save_data->Size = System::Drawing::Size(75, 26);
			this->button_save_data->TabIndex = 4;
			this->button_save_data->Text = L"save";
			this->button_save_data->UseVisualStyleBackColor = true;
			this->button_save_data->Click += gcnew System::EventHandler(this, &ChartWindow::button_save_data_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(261, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Y Axis:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"X Axis:";
			// 
			// comboBox_Y
			// 
			this->comboBox_Y->FormattingEnabled = true;
			this->comboBox_Y->Location = System::Drawing::Point(325, 12);
			this->comboBox_Y->Name = L"comboBox_Y";
			this->comboBox_Y->Size = System::Drawing::Size(121, 24);
			this->comboBox_Y->TabIndex = 1;
			this->comboBox_Y->SelectedIndexChanged += gcnew System::EventHandler(this, &ChartWindow::comboBoxes_SelectedIndexChanged);
			// 
			// comboBox_X
			// 
			this->comboBox_X->FormattingEnabled = true;
			this->comboBox_X->Location = System::Drawing::Point(89, 12);
			this->comboBox_X->Name = L"comboBox_X";
			this->comboBox_X->Size = System::Drawing::Size(121, 24);
			this->comboBox_X->TabIndex = 0;
			this->comboBox_X->SelectedIndexChanged += gcnew System::EventHandler(this, &ChartWindow::comboBoxes_SelectedIndexChanged);
			// 
			// chart_data
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart_data->ChartAreas->Add(chartArea1);
			this->chart_data->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart_data->Legends->Add(legend1);
			this->chart_data->Location = System::Drawing::Point(0, 54);
			this->chart_data->Name = L"chart_data";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart_data->Series->Add(series1);
			this->chart_data->Size = System::Drawing::Size(1076, 491);
			this->chart_data->TabIndex = 1;
			this->chart_data->Text = L"chart1";
			// 
			// ChartWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1076, 545);
			this->Controls->Add(this->chart_data);
			this->Controls->Add(this->panel1);
			this->Name = L"ChartWindow";
			this->Text = L"ChartWindow";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ChartWindow::ChartWindow_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ChartWindow::ChartWindow_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_data))->EndInit();
			this->ResumeLayout(false);

		}
		Eigen::MatrixXf* data = NULL;
#pragma endregion
	public: void FillData(Eigen::MatrixXf M)
	{
		int rows = M.rows();
		int cols = M.cols();
		if (data) delete data;
		data = new Eigen::MatrixXf();
		*data = M;
	}
	private: System::Void ChartWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox_X->Items->Clear();
		comboBox_Y->Items->Clear();
		comboBox_X->Items->Add(L"r");	comboBox_Y->Items->Add(L"r");
		comboBox_X->Items->Add(L"c");	comboBox_Y->Items->Add(L"c");
		comboBox_X->Items->Add(L"r - cy");	comboBox_Y->Items->Add(L"r - cy");
		comboBox_X->Items->Add(L"c - cx");	comboBox_Y->Items->Add(L"c - cx");
		comboBox_X->Items->Add(L"depth");	comboBox_Y->Items->Add(L"depth");
		comboBox_X->Items->Add(L"H-dist-real");	comboBox_Y->Items->Add(L"H-dist-real");
		comboBox_X->Items->Add(L"H-dist-meaure");	comboBox_Y->Items->Add(L"H-dist-meaure");
		comboBox_X->Items->Add(L"V-dist-real");	comboBox_Y->Items->Add(L"V-dist-real");
		comboBox_X->Items->Add(L"V-dist-meaure");	comboBox_Y->Items->Add(L"V-dist-meaure");

		comboBox_X->SelectedIndex = 0;
		comboBox_Y->SelectedIndex = 4;
	}
private: System::Void ChartWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (data) delete data;
}
private: System::Void comboBoxes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	chart_data->Series[0]->Points->Clear();
	int rows = data->rows();

	int Xaxis = comboBox_X->SelectedIndex + 1;
	int Yaxis = comboBox_Y->SelectedIndex + 1;

	for (int i = 0; i < rows; i++)
	{
		chart_data->Series[0]->Points->AddXY((*data)(i,Xaxis), (*data)(i, Yaxis));
	}
}
private: System::Void button_save_data_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog->FileName = L"";
	saveFileDialog->Filter = L"CSV File | *.csv";
	saveFileDialog->ShowDialog();
	if (saveFileDialog->FileName->Length > 0)
	{
		char filename[500];
		sprintf(filename, "%s", saveFileDialog->FileName);



		FILE* f;
		fopen_s(&f, filename, "wb");

		fprintf(f, "Point NB:, %d, \n ,\n", data->rows());
		fprintf(f, "r, c, r - cy, c - cx, H-error, H-error %%, V-error, V-error %%,\n");
		for (int i = 0; i < data->rows(); i++)
		{
			for (int k = 0; k < 8; k++) fprintf(f, "%f, ", (*data)(i, k));
			fprintf(f, "\n");
		}

		fclose(f);
	}
}
};
}
