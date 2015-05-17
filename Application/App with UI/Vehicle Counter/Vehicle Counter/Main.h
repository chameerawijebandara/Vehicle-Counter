#pragma once

#include "ImageProcessor.h"
#include <msclr\marshal_cppstd.h>

namespace VehicleCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  labelOutputTxt;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button8;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->labelOutputTxt = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 171);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input File";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 289);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Output File";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(171, 168);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(464, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(171, 285);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(464, 26);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(675, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(675, 280);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Select";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 468);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Starting Time(HH MM SS)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(39, 517);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Number Of Lanes";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(525, 92);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(222, 51);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Start Counting";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(276, 464);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 29);
			this->label5->TabIndex = 11;
			this->label5->Text = L":";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(335, 464);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 29);
			this->label6->TabIndex = 13;
			this->label6->Text = L":";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(237, 465);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(39, 26);
			this->numericUpDown1->TabIndex = 15;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(296, 465);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(39, 26);
			this->numericUpDown2->TabIndex = 16;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(355, 465);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(39, 26);
			this->numericUpDown3->TabIndex = 17;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(237, 514);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(58, 26);
			this->numericUpDown4->TabIndex = 18;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(648, 172);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(99, 38);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Stop";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(39, 383);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 20);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Date";
			// 
			// button5
			// 
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(342, 12);
			this->button5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(130, 140);
			this->button5->TabIndex = 22;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// labelOutputTxt
			// 
			this->labelOutputTxt->AutoSize = true;
			this->labelOutputTxt->Location = System::Drawing::Point(39, 231);
			this->labelOutputTxt->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOutputTxt->Name = L"labelOutputTxt";
			this->labelOutputTxt->Size = System::Drawing::Size(123, 20);
			this->labelOutputTxt->TabIndex = 23;
			this->labelOutputTxt->Text = L"Output video file";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(675, 222);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(99, 38);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Select";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Main::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(171, 229);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(464, 26);
			this->textBox4->TabIndex = 25;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(39, 415);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(39, 26);
			this->numericUpDown5->TabIndex = 26;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(109, 383);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(54, 20);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Month";
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(109, 415);
			this->numericUpDown6->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDown6->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(53, 26);
			this->numericUpDown6->TabIndex = 28;
			this->numericUpDown6->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(189, 383);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 20);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Year";
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Location = System::Drawing::Point(189, 414);
			this->numericUpDown7->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2030, 0, 0, 0 });
			this->numericUpDown7->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2010, 0, 0, 0 });
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(63, 26);
			this->numericUpDown7->TabIndex = 30;
			this->numericUpDown7->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2010, 0, 0, 0 });
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(25, 343);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(777, 256);
			this->panel1->TabIndex = 31;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(525, 21);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(222, 51);
			this->button8->TabIndex = 21;
			this->button8->Text = L"Mark Lanes";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Main::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(525, 172);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(99, 38);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Test";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Main::button7_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(25, 151);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(777, 186);
			this->panel2->TabIndex = 32;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 611);
			this->Controls->Add(this->numericUpDown7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->numericUpDown6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->labelOutputTxt);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"Main";
			this->Text = L"Traffic Analyzer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ inFileName;
		String^ outFileName;
		String^ outFileNameTxt;
		int starth;
		int startm;
		int starts;
		int nol;
		ImageProcessor *imgp;

		void Validate()
		{
			starth = (int)numericUpDown1->Value;
			startm = (int)numericUpDown2->Value;
			starts = (int)numericUpDown3->Value;

			nol = (int)numericUpDown4->Value;
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 openFileDialog1->Filter = "Video Files|*.MTS";
				 openFileDialog1->Title = "Select a Video File";
				 openFileDialog1->FileName = "";
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 String^ _inputFileName = openFileDialog1->FileName;
					 textBox1->Text = _inputFileName;
					 inFileName = _inputFileName;
					 //MessageBox::Show(_inputFileName);
				 }


	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 saveFileDialog1->Filter = "AVI Video|*.avi";
				 saveFileDialog1->Title = "Save output Files";
				 saveFileDialog1->ShowDialog();
				 // If the file name is not an empty string, open it for saving.
				 if (saveFileDialog1->FileName != "")
				 {
					 String^ _outputFileName = saveFileDialog1->FileName;
					 textBox2->Text = _outputFileName;
					 outFileName = _outputFileName;
				 }

	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 imgp->Start();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 ImageProcessor::isVideoRun = false;
				 imgp->saveResults();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 saveFileDialog1->Filter = "Text File|*.txt";
				 saveFileDialog1->Title = "Save output Files";
				 saveFileDialog1->ShowDialog();
				 // If the file name is not an empty string, open it for saving.
				 if (saveFileDialog1->FileName != "")
				 {
					 String^ _outputFileName = saveFileDialog1->FileName;
					 textBox4->Text = _outputFileName;
					 outFileNameTxt = _outputFileName;
				 }
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				 Validate();
				 msclr::interop::marshal_context context;
				 if (ImageProcessor::isVideoRun)
				 {
					 return;
				 }
				 imgp = new ImageProcessor(context.marshal_as<std::string>(inFileName), context.marshal_as<std::string>(outFileName), context.marshal_as<std::string>(outFileNameTxt), starth, startm, starts, nol);
				 imgp->MarkTrackers();
	}
};
}
