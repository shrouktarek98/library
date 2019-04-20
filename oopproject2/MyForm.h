#pragma once
#include"MyForm1.h"
#include"MyForm2.h"
#include"MyForm3.h"
#include"MyForm42.h"
#include"library.h"
#include<queue>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;


namespace oopproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		

	public:
		library^read;
	
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm(library^re)
		{
			read = gcnew library();
			read = re;
		
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		///////////////////////////MyForm_load_file_requestdic/////////////////////////////////////////////
		void load_file_requestdic(Dictionary<String^, List<request^>^>^%dic)
		{
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("ListRequest.xml");
			XmlNodeList^ list = doc->GetElementsByTagName("list");
			
			String^us_id = "";
			for (int i = 0; i < list->Count; i++)
			{
				XmlNodeList ^req = list[i]->ChildNodes;
			
				List<request^>^lr= gcnew List<request^>();
			
				for (int j = 0; j < req->Count; j++)
				{	
					
				
					request^ requ = gcnew request();
					XmlNodeList ^childern = req[j]->ChildNodes;
					requ->user_id = childern[0]->InnerText;
				
						us_id= childern[0]->InnerText;
				
					requ->id = childern[1]->InnerText;
					requ->isbn = childern[2]->InnerText;
					requ->checkrequest = childern[3]->InnerText;
					requ->requestdate = childern[4]->InnerText;
					requ->duedata = childern[5]->InnerText;
				
						lr->Add(requ);
				}
				dic->Add(us_id, lr);
			}
		}
		///////////////////////////MyForm_load_file_bookdic/////////////////////////////////////////////
		void load_file_bookdic(Dictionary<String^, book^>^% dic)
		{
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Book.xml");
			XmlNodeList^ list = doc->GetElementsByTagName("Book");
			for (int i = 0; i < list->Count; i++)
			{
				XmlNodeList ^childern = list[i]->ChildNodes;
				book^ b = gcnew book();
				b->ISBN = childern[0]->InnerText;
				b->title = childern[1]->InnerText;
				b->location = childern[2]->InnerText;
				b->no_of_copies = int::Parse(childern[3]->InnerText);
				b->price = double::Parse(childern[4]->InnerText);
				b->genre = childern[5]->InnerText;
				b->author = childern[6]->InnerText;
				b->no_of_borrow = int::Parse(childern[7]->InnerText);;
				dic->Add(b->title, b);

			}
		}

		///////////////////////////MyForm_load_file_readerdic/////////////////////////////////////////////
		void load_file_readerdic(Dictionary<String^, reader^>^% dic)
		{
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("Reader.xml");
			XmlNodeList^ list = doc->GetElementsByTagName("Reader");
			for (int i = 0; i < list->Count; i++)
			{
				XmlNodeList ^childern = list[i]->ChildNodes;
				reader^ r = gcnew reader();
				r->firstname = childern[0]->InnerText;
				r->lastname = childern[1]->InnerText;
				r->address = childern[2]->InnerText;
				r->cellphone = childern[3]->InnerText;
				r->email = childern[4]->InnerText;
				r->id = childern[6]->InnerText;
				r->passowerd = childern[7]->InnerText;

				String^s;
				s = childern[5]->InnerText;
				if (s == "False")
					r->isblocked = false;
				else
					r->isblocked = true;
				dic->Add(r->id, r);

			}
		}
		///////////////////////////MyForm_load_file_orderdic/////////////////////////////////////////////
	
		
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(448, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(248, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(190, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"password";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"add", L"remove", L"search" });
			this->comboBox1->Location = System::Drawing::Point(50, 120);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 5;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"reader", L"book" });
			this->comboBox2->Location = System::Drawing::Point(248, 120);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(448, 120);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"change";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(50, 188);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"addorderedlist";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(248, 188);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(121, 24);
			this->button5->TabIndex = 9;
			this->button5->Text = L"removeorderedlist";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(443, 173);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 24);
			this->button3->TabIndex = 10;
			this->button3->Text = L"the best";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 342);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		///////////////////////////MyForm_button1_Click/////////////////////////////////////////////
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox1->Text == ""&&textBox2->Text == "")
		{
			MessageBox::Show("Please Enter Id and Passowrd");
			return;
		}
		else if (textBox1->Text == read->admin.id&&textBox2->Text == read->admin.passowerd)
		{
			comboBox1->Visible = true;
			comboBox2->Visible = true;
			button2->Visible = true;
			button4->Visible = true;
			button5->Visible = true;
			button3->Visible = true;
		}
		else
		{
			librarian^chec = gcnew librarian();
			String^ch = chec->cheak(textBox1->Text, read);

			if (ch == "-1")
			{
				MessageBox::Show("invalid Id ");
				textBox1->Text = "";
				textBox2->Text = "";
				return;
			}
			reader^ READER = gcnew reader;
			READER = read->admin.search(textBox1->Text, read->readers);

			if (READER->passowerd != textBox2->Text)
			{
				MessageBox::Show("invalid Id or password ");
				textBox1->Text = "";
				textBox2->Text = "";

			}
			else if (READER->passowerd == textBox2->Text)
			{
				textBox1->Text = "";
				textBox2->Text = "";
				MyForm3^ f = gcnew MyForm3(READER, read);
				f->ShowDialog();

			}



		}
	}
			 ///////////////////////////MyForm_Load/////////////////////////////////////////////
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		if (File::Exists("Book.xml"))
		{
			load_file_bookdic(read->books);
		}

		if (File::Exists("Reader.xml"))
		{
			load_file_readerdic(read->readers);
		}
		if (File::Exists("ListRequest.xml"))
		{
			load_file_requestdic(read->requests);
		}
		if (File::Exists("OrderList.xml"))
		{
			read->load_file_orderdic(read->orderedlist);
		}
		comboBox1->Visible = false;
		comboBox2->Visible = false;
		button2->Visible = false;
		button4->Visible = false;
		button5->Visible = false;
		button3->Visible = false;
	}

			 ///////////////////////////MyForm_button2_Click/////////////////////////////////////////////
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text == "" || comboBox2->Text == "")
		{
			MessageBox::Show("please complete your data!!! ");
			return;
		}
		if (comboBox1->Text == "add"&&comboBox2->Text == "reader")
		{

			MyForm1 ^f = gcnew MyForm1(read, 0);//reader=0

			f->ShowDialog();

		}
		else if (comboBox1->Text == "add"&&comboBox2->Text == "book")
		{
			MyForm1 ^f = gcnew MyForm1(read, 1);//book=1

			f->ShowDialog();
		}
		else if (comboBox1->Text == "search"&&comboBox2->Text == "book")
		{
			MyForm2 ^f = gcnew MyForm2(read, 1, 0);//book search=1,0

			f->ShowDialog();
		}
		else if (comboBox1->Text == "search"&&comboBox2->Text == "reader")
		{
			MyForm2 ^f = gcnew MyForm2(read, 0, 0);//reader search=0,0

			f->ShowDialog();
		}
		else if (comboBox1->Text == "remove"&&comboBox2->Text == "reader")
		{
			MyForm2 ^f = gcnew MyForm2(read, 0, 1);//reader remove=0,1

			f->ShowDialog();
		}
		else if (comboBox1->Text == "remove"&&comboBox2->Text == "book")
		{
			MyForm2 ^f = gcnew MyForm2(read, 1, 1);//book remove=1,1

			f->ShowDialog();
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		MyForm4 ^f = gcnew MyForm4(1);
		f->Show();
	}
    private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
    {
		MyForm4 ^f = gcnew MyForm4(0);
		f->Show();
    }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	read->admin.thebest(read);
}
};
}
