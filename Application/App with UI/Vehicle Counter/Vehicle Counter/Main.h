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



	private: System::Windows::Forms::Label^  labelOutputTxt;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox4;





	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;

	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;



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
			this->labelOutputTxt = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input File";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Output Video File";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(186, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(561, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(252, 180);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(495, 26);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(781, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(781, 175);
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
			this->label3->Location = System::Drawing::Point(39, 416);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Starting Time(HH MM SS)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(39, 465);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Number Of Lanes";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(626, 92);
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
			this->label5->Location = System::Drawing::Point(274, 116);
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
			this->label6->Location = System::Drawing::Point(363, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 29);
			this->label6->TabIndex = 13;
			this->label6->Text = L":";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(237, 413);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(58, 26);
			this->numericUpDown1->TabIndex = 15;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(299, 121);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(58, 26);
			this->numericUpDown2->TabIndex = 16;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(385, 119);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(58, 26);
			this->numericUpDown3->TabIndex = 17;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(237, 462);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(58, 26);
			this->numericUpDown4->TabIndex = 18;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(749, 172);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(99, 38);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Stop";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// labelOutputTxt
			// 
			this->labelOutputTxt->AutoSize = true;
			this->labelOutputTxt->Location = System::Drawing::Point(39, 126);
			this->labelOutputTxt->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOutputTxt->Name = L"labelOutputTxt";
			this->labelOutputTxt->Size = System::Drawing::Size(91, 20);
			this->labelOutputTxt->TabIndex = 23;
			this->labelOutputTxt->Text = L"Output  File";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(781, 117);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(99, 38);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Select";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Main::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(186, 124);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(561, 26);
			this->textBox4->TabIndex = 25;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->numericUpDown2);
			this->panel1->Controls->Add(this->numericUpDown3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(25, 291);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(905, 256);
			this->panel1->TabIndex = 31;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(134, 20);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Date of the Video";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(210, 69);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(233, 26);
			this->dateTimePicker2->TabIndex = 23;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 69);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 20);
			this->label10->TabIndex = 22;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(626, 21);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(222, 51);
			this->button8->TabIndex = 21;
			this->button8->Text = L"Mark Lanes";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Main::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(626, 172);
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
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(25, 36);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(905, 232);
			this->panel2->TabIndex = 32;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(16, 190);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(22, 21);
			this->checkBox2->TabIndex = 24;
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Main::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(16, 146);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(22, 21);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Main::checkBox1_CheckedChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(50, 190);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(147, 20);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Show Output Video";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(25, 595);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(905, 23);
			this->progressBar1->TabIndex = 33;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(25, 563);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 20);
			this->label12->TabIndex = 34;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 635);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->labelOutputTxt);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"Main";
			this->Text = L"Traffic Analyzer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ inFileName = "";
		String^ outFileName = "";
		String^ outFileNameTxt = "";
		int starth;
		int startm;
		int starts;
		int nol;
		ImageProcessor *imgp;

		bool Validate()
		{
			starth = (int)numericUpDown1->Value;
			startm = (int)numericUpDown2->Value;
			starts = (int)numericUpDown3->Value;

			nol = (int)numericUpDown4->Value;

			if (inFileName->Length == 0)
			{
				textBox1->BackColor = Color::Red;
				return false;
			}
			
			if (outFileNameTxt->Length == 0)
			{
				textBox4->BackColor = Color::Red;
				return false;
			}
			if (ImageProcessor::isVideoOut & outFileName->Length == 0)
			{
				textBox2->BackColor = Color::Red;
				return false;
			}
			return true;
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 textBox1->BackColor = Color::White;
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

				 textBox2->BackColor = Color::White;
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
				 timer1->Start();
				 imgp->Start();
				 imgp->saveResults();
				 timer1->Stop();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 ImageProcessor::isVideoRun = false;
				 imgp->saveResults();
				 timer1->Stop();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 textBox4->BackColor = Color::White;
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
				 if (!Validate())
				 {
					 return;
				 }
				 msclr::interop::marshal_context context;
				 if (ImageProcessor::isVideoRun)
				 {
					 return;
				 }
				 imgp = new ImageProcessor(context.marshal_as<std::string>(inFileName), context.marshal_as<std::string>(outFileName), context.marshal_as<std::string>(outFileNameTxt), starth, startm, starts, nol);
				 imgp->MarkTrackers();
	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Enabled = !textBox2->Enabled;
			 button2->Enabled = !button2->Enabled;
			 
			 ImageProcessor::isVideoOut = button2->Enabled;
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 ImageProcessor::isVideoShow = !ImageProcessor::isVideoShow;
}


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 progressBar1->Maximum = ImageProcessor::totFrams;
			 progressBar1->Value = ImageProcessor::currentFrame;

}
};
}
