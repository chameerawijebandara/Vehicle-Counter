#pragma once

#include "ImageProcessor.h"
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <String>
#include <Shlwapi.h>
#include <Windows.h>
#include <iostream>

namespace VehicleCounter {

	using namespace System;
	using namespace System::Collections::Generic;
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
			impgs= gcnew List<MyClass^>();
			testing = false;
			Video_No=0;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			inFileNames = "";
			outFileName = "";
			outFileNameTxt = "";
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
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::IO::FileSystemWatcher^  fileSystemWatcher1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 43);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input Files";
			this->label1->Click += gcnew System::EventHandler(this, &Main::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 247);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Output Video File";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(124, 41);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(375, 155);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(149, 240);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(331, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(502, 13);
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
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(499, 235);
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
			this->label3->Location = System::Drawing::Point(8, 86);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Starting Time(HH MM SS)";
			this->label3->Click += gcnew System::EventHandler(this, &Main::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 124);
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
			this->button3->Location = System::Drawing::Point(417, 62);
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
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(183, 75);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L":";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(242, 77);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L":";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(149, 80);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {23, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(39, 20);
			this->numericUpDown1->TabIndex = 15;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Main::numericUpDown1_ValueChanged);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(199, 79);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(39, 20);
			this->numericUpDown2->TabIndex = 16;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(257, 77);
			this->numericUpDown3->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(39, 20);
			this->numericUpDown3->TabIndex = 17;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(149, 122);
			this->numericUpDown4->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(39, 20);
			this->numericUpDown4->TabIndex = 18;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(499, 112);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 25);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Stop";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// labelOutputTxt
			// 
			this->labelOutputTxt->AutoSize = true;
			this->labelOutputTxt->Location = System::Drawing::Point(19, 193);
			this->labelOutputTxt->Name = L"labelOutputTxt";
			this->labelOutputTxt->Size = System::Drawing::Size(61, 13);
			this->labelOutputTxt->TabIndex = 23;
			this->labelOutputTxt->Text = L"Output  File";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(499, 181);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(66, 25);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Select";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Main::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(105, 186);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(375, 20);
			this->textBox4->TabIndex = 25;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Main::textBox4_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->numericUpDown4);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->numericUpDown2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->numericUpDown3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(17, 354);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(605, 168);
			this->panel1->TabIndex = 31;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 45);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(90, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Date of the Video";
			this->label7->Click += gcnew System::EventHandler(this, &Main::label7_Click);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(140, 45);
			this->dateTimePicker2->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(157, 20);
			this->dateTimePicker2->TabIndex = 23;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(8, 45);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 13);
			this->label10->TabIndex = 22;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(417, 10);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(148, 33);
			this->button8->TabIndex = 21;
			this->button8->Text = L"Mark Lanes";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Main::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(417, 112);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(66, 25);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Test";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Main::button7_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->labelOutputTxt);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(17, 23);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(605, 306);
			this->panel2->TabIndex = 32;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(502, 51);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(66, 23);
			this->button5->TabIndex = 26;
			this->button5->Text = L"Cancel";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Main::button5_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(11, 275);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(15, 14);
			this->checkBox2->TabIndex = 24;
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Main::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(11, 247);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Main::checkBox1_CheckedChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(33, 276);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(99, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Show Output Video";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(17, 538);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(603, 15);
			this->progressBar1->TabIndex = 33;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(17, 366);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 34;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 560);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->Text = L"Traffic Analyzer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ inFileNames;
		String^ outFileName;
		String^ outFileNameTxt;
		int starth;
		int startm;
		int starts;
		int nol;
		int Video_No;
		bool testing;
		ImageProcessor *imgp;
		ref class MyClass
		{
		public:
			String^ inFileNamee;
			ImageProcessor *imgpp;
			bool Marked;
		};
		List<MyClass^>^ impgs;
		List<String^>^ namelist;

		void MergeVideoProperties(int TotalFrames)
		{
							starts+=(TotalFrames/30)%60;
							startm+=(TotalFrames/1800)%60;
							starth+=(TotalFrames/1800)/60;
							msclr::interop::marshal_context context;
							impgs[Video_No]->imgpp = new ImageProcessor(context.marshal_as<std::string>(inFileNames), context.marshal_as<std::string>(outFileName), context.marshal_as<std::string>(outFileNameTxt), starth, startm, starts, nol);
							impgs[Video_No]->imgpp->w=impgs[Video_No-1]->imgpp->w;
							impgs[Video_No]->imgpp->h=impgs[Video_No-1]->imgpp->h;
							impgs[Video_No]->imgpp->x_cord=impgs[Video_No-1]->imgpp->x_cord;
							impgs[Video_No]->imgpp->y_cord=impgs[Video_No-1]->imgpp->y_cord;
							impgs[Video_No]->imgpp->Moving_flag=impgs[Video_No-1]->imgpp->Moving_flag;
							impgs[Video_No]->imgpp->Man_Move=impgs[Video_No-1]->imgpp->Man_Move;
							impgs[Video_No]->Marked=true;
		}

		bool Validate()
		{
			starth = (int)numericUpDown1->Value;
			startm = (int)numericUpDown2->Value;
			starts = (int)numericUpDown3->Value;

			nol = (int)numericUpDown4->Value;

			
			
			if (inFileNames->Length == 0)
			{
				MessageBox::Show("Error!!","",MessageBoxButtons::OK,
							MessageBoxIcon::Error);
				return false;
			}

			if (outFileNameTxt->Length == 0)
			{
				textBox4->BackColor = Color::Red;
				MessageBox::Show("Specify A Output File Location & Name!!","",MessageBoxButtons::OK,
							MessageBoxIcon::Error);
				return false;
			}
			if (ImageProcessor::isVideoOut & (outFileName->Length == 0))
			{
				textBox2->BackColor = Color::Red;
				return false;
			}
			return true;
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				// impgs= gcnew List<MyClass^>();				
				 textBox1->BackColor = Color::White;
				 openFileDialog1->Filter = "Video Files|*.MTS";
				 openFileDialog1->Title = "Select a Video File";
				 openFileDialog1->FileName = "";
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 String^ _inputFileName = openFileDialog1->FileName;
					 
					 if(textBox1->Text=="")
					 {
						textBox1->Text = _inputFileName;
						MyClass^ temp=gcnew MyClass;
						temp->inFileNamee=_inputFileName;
						temp->Marked=false;
						impgs->Add(temp);

					 }
					 else
					 {
						textBox1->Text += "\r\n"+_inputFileName;
						MyClass^ temp=gcnew MyClass;
						temp->inFileNamee=_inputFileName;
						temp->Marked=false;
						impgs->Add(temp);
						//MessageBox::Show(_inputFileName);
					 }
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
				if(impgs->Count==0)
				{
					textBox1->BackColor = Color::Red;
					MessageBox::Show("Select A Video(.MTS Format)!!","",MessageBoxButtons::OK,
									MessageBoxIcon::Error);
					return;
				}

				else
				{
					inFileNames=impgs[Video_No]->inFileNamee;
					if(!Validate())
						return;
					if(!impgs[Video_No]->Marked)
					{
						MessageBox::Show("Mark Lanes!!","",MessageBoxButtons::OK,
									MessageBoxIcon::Error);
						return;
					}
					timer1->Start();
					this->button4->Enabled=true;
					int TotalFrames=impgs[Video_No]->imgpp->Start();
					impgs[Video_No]->imgpp->saveResults(starth, startm, starts);
					Video_No++;
					timer1->Stop();

					if(impgs->Count==Video_No)
					{
						MessageBox::Show("            DONE     ");
						Video_No=0;
					}
					else
					{
						if(MessageBox::Show("Do you Want To Set Date & Time again or Mark Lanes again?","Message",MessageBoxButtons::YesNo,
							MessageBoxIcon::Question)==System::Windows::Forms::DialogResult::Yes){
							this->button4->Enabled=false;return;
						}
						else
						{
							inFileNames=impgs[Video_No]->inFileNamee;
							MergeVideoProperties(TotalFrames);
							button3_Click(gcnew System::Object, gcnew System::EventArgs);
						}
					}

				}

			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(MessageBox::Show("Do you want to Stop this video?","Message",MessageBoxButtons::YesNo,
					 MessageBoxIcon::Question)==System::Windows::Forms::DialogResult::Yes){
					 ImageProcessor::isVideoRun = false;
					 ImageProcessor::proccess_start=false;
					 if(!testing && MessageBox::Show("Do you want to Save results to ecxel file?","Message",MessageBoxButtons::YesNo,
					 MessageBoxIcon::Question)==System::Windows::Forms::DialogResult::Yes)		// save results if not testing
						impgs[Video_No]->imgpp->saveResults(starth, startm, starts);
					 timer1->Stop();
					 this->button4->Enabled=false;
				}
			 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 textBox4->BackColor = Color::White;
				 saveFileDialog1->Filter = "Excel File|*.xls";
				 saveFileDialog1->Title = "Save output Files";
				 saveFileDialog1->ShowDialog();
				 // If the file name is not an empty string, open it for saving.
				 if (saveFileDialog1->FileName != "")
				 {
					 String^ _outputFileName = saveFileDialog1->FileName;
					 textBox4->Text = _outputFileName;
					 outFileNameTxt = _outputFileName;
				 }

				 /*folderBrowserDialog1->Description = "Select output Files Location";
				 folderBrowserDialog1->ShowDialog();
				 if (folderBrowserDialog1->SelectedPath != "")
				 {
					 String^ _outputFileName = folderBrowserDialog1->SelectedPath;
					 textBox4->Text = _outputFileName;
					 outFileNameTxt = _outputFileName;
				 }*/
				

			 }
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				if(impgs->Count==0)
				{
					textBox1->BackColor = Color::Red;
					MessageBox::Show("Select A Video(.MTS Format)!!","",MessageBoxButtons::OK,
									MessageBoxIcon::Error);
					return;
				}

				else
				{
					inFileNames=impgs[Video_No]->inFileNamee;
					if(!Validate())
						return;
					if(!impgs[Video_No]->Marked)
					{
						MessageBox::Show("Mark Lanes!!","",MessageBoxButtons::OK,
									MessageBoxIcon::Error);
						return;
					}
					timer1->Start();
					this->button4->Enabled=true;
					testing = true;
					impgs[Video_No]->imgpp->Start();
					testing = false;
					this->button4->Enabled=false;
					timer1->Stop();


				}

			 }
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			outFileNameTxt = textBox4->Text;
			/*impgs = gcnew List<MyClass^>();

			String^ txt = textBox1->Text;
			String^ delimStr = "\n\r";
			array<Char>^ delimiter = delimStr->ToCharArray( );
			array<String^>^ paths;
			paths = txt->Split( delimiter );
			for (int word=0; word<paths->Length; word++){
				MyClass^ temp=gcnew MyClass;
				temp->inFileNamee=paths[word] ;
				if(word<Video_No)
					temp->Marked=true;
				else
					temp->Marked=false;
				impgs->Add(temp);
			}*/
				if(impgs->Count==0)
				{
					textBox1->BackColor = Color::Red;
					MessageBox::Show("Select A Video(.MTS Format)!!","",MessageBoxButtons::OK,
									MessageBoxIcon::Error);
					return;
				}
				else
				{
					inFileNames=impgs[Video_No]->inFileNamee;
					if (!Validate())
					{
						return;
					}
					msclr::interop::marshal_context context;
					if (ImageProcessor::isVideoRun)
					{
						return;
					}

					impgs[Video_No]->imgpp = new ImageProcessor(context.marshal_as<std::string>(inFileNames), context.marshal_as<std::string>(outFileName), context.marshal_as<std::string>(outFileNameTxt), starth, startm, starts, nol);
					impgs[Video_No]->Marked=impgs[Video_No]->imgpp->MarkTrackers();
					
				}
				 
				 
			 }
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 textBox2->Enabled = !textBox2->Enabled;
				 button2->Enabled = !button2->Enabled;
				 if(!textBox2->Enabled)
					 textBox2->BackColor = Color::White;
				 ImageProcessor::isVideoOut = button2->Enabled;
			 }
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 ImageProcessor::isVideoShow = !ImageProcessor::isVideoShow;
			 }

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 progressBar1->Maximum = ImageProcessor::totFrams;
				 progressBar1->Value = 2 * ImageProcessor::currentFrame;

			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			if(impgs->Count ==0)
				return;
			if(MessageBox::Show("Do you Really Want To Cancel Process?","Message",MessageBoxButtons::YesNo,
				MessageBoxIcon::Question)==System::Windows::Forms::DialogResult::No)
				return;
			Video_No = 0;
			impgs = gcnew List<MyClass^>();

			String^ txt = textBox1->Text;
			String^ delimStr = "\n\r";
			array<Char>^ delimiter = delimStr->ToCharArray( );
			array<String^>^ paths;
			paths = txt->Split( delimiter );
			for (int word=0; word<paths->Length; word++){
				
				MyClass^ temp=gcnew MyClass;
				temp->inFileNamee=paths[word] ;
				temp->Marked=false;
				impgs->Add(temp);
			}
		 }
};
}
