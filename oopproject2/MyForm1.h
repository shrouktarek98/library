#pragma once
#include"library.h"
#include"MyForm2.h"
#include<fstream>
#include<iostream>



namespace oopproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		library^read;
		int choise;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox7;
	public:
	private: System::Windows::Forms::TextBox^  textBox6;
	public:
		MyForm1()
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		///////////////////////////MyForm1_constructor /////////////////////////////////////////////
		MyForm1(library^r, int x)
		{
			read = gcnew library();
			read = r;
			choise = x;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(354, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(122, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(329, 16);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(122, 62);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(329, 65);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(122, 107);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(246, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(246, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(246, 110);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(329, 107);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(25, 157);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"label7";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(122, 154);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 14;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 359);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		///////////////////////////MyForm1_button1_Click /////////////////////////////////////////////
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		librarian^admincheack = gcnew librarian();

		if (choise == 0)//reader

		{
			if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "" || textBox5->Text == "")
			{
				MessageBox::Show("plese complete your data!!!");
				return;

			}
			else
			{

				String^ch = admincheack->cheak(textBox4->Text, read);
				if (ch == "-1")
				{
					read->admin.addreader(textBox1->Text, textBox2->Text, textBox3->Text,
						textBox4->Text, textBox5->Text, read->readers);

				}
				else
				{
					MessageBox::Show("invalid id (already exist)");
					return;
				}

				read->admin.write_filereader(read->readers);
			}
		}
		else if (choise == 1) //book
		{
			if (textBox1->Text == "" || textBox2->Text == "" || textBox4->Text == "" || textBox5->Text == "" ||
				textBox3->Text == "" || textBox6->Text == "" || textBox7->Text == "")
			{
				MessageBox::Show("plese complete your data!!!");
				return;

			}
			else
			{
				String^ch = admincheack->cheak(textBox2->Text, read);
				if (ch == "-1")
				{

					read->admin.addbook(textBox1->Text, textBox2->Text, textBox3->Text, int::Parse(textBox4->Text),
						double::Parse(textBox5->Text), textBox6->Text, textBox7->Text, read->books);
				}
				else if (ch == "0")
				{
					book ^b = gcnew book();
					b = admincheack->search(textBox2->Text, read->books);
					b->no_of_copies += int::Parse(textBox4->Text);
				}

				read->admin.write_filebook(read->books);
			}


		}

		//empty text box
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";
		textBox7->Text = "";





	}
			 ///////////////////////////MyForm1_Load /////////////////////////////////////////////
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		if (choise == 0)
		{
			label1->Text = "First Name";
			label2->Text = "Last Name";
			label3->Text = "Address";
			label4->Text = "Phone";
			label5->Text = "Email";
			label6->Visible = false;
			textBox6->Visible = false;
			label7->Visible = false;
			textBox7->Visible = false;

		}
		else if (choise == 1)
		{
			label1->Text = "ISBN";
			label2->Text = "Title";
			label3->Text = "Location";
			label4->Text = "No.Of Copies";
			label5->Text = "Price";
			label6->Text = "Genre";
			label6->Visible = true;
			textBox6->Visible = true;
			label7->Text = "author";
			label7->Visible = true;
			textBox7->Visible = true;
		}

	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
