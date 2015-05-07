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
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;



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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 111);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input File";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 146);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Output File";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(104, 109);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(311, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(104, 144);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(311, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(450, 106);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(450, 140);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 25);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Select";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 222);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Starting Time(HH MM SS)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 254);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Number Of Lanes";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(357, 191);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(148, 33);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Start Counting";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(188, 222);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(11, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L":";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(225, 222);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(11, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L":";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(158, 220);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {23, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(26, 20);
			this->numericUpDown1->TabIndex = 15;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(199, 220);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(26, 20);
			this->numericUpDown2->TabIndex = 16;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(238, 220);
			this->numericUpDown3->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(26, 20);
			this->numericUpDown3->TabIndex = 17;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(158, 252);
			this->numericUpDown4->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(39, 20);
			this->numericUpDown4->TabIndex = 18;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(439, 237);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 25);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Stop";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 190);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Date";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(104, 186);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(122, 20);
			this->textBox3->TabIndex = 21;
			// 
			// button5
			// 
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(228, 8);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(87, 91);
			this->button5->TabIndex = 22;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 312);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Traffic Analyzer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ inFileName;
		String^ outFileName;
		int starth;
		int startm;
		int starts;
		int nol;

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
			 Validate();
			 msclr::interop::marshal_context context;
			 if (ImageProcessor::isVideoRun)
			 {
				 return;
			 }
			 ImageProcessor imgp(context.marshal_as<std::string>(inFileName), context.marshal_as<std::string>(outFileName), starth, startm, starts, nol);
			 imgp.Start();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 ImageProcessor::isVideoRun = false;
}
};
}
