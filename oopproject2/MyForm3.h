#pragma once
#include"library.h"
namespace oopproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		library^read;
		reader^READER;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button5;
	public:
	private: System::Windows::Forms::Button^  button4;
	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		///////////////////////////MyForm3_constructor/////////////////////////////////////////////
		MyForm3(reader^%u_r, library^% re)
		{
			InitializeComponent();
			read = gcnew library();
			READER = gcnew reader();
			read = re;
			READER = u_r;

			//
			//TODO: Add the constructor code here
			//
		}

	public:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}

		///////////////////////////MyForm3_gridbook_header/////////////////////////////////////////////
		void gridbook_header(DataGridView^% datagrid)
		{
			if (datagrid->ColumnCount == 0)
			{
				datagrid->Columns->Add("title", "title");
				datagrid->Columns->Add("price", "price");
				datagrid->Columns->Add("genre", "genre");
				datagrid->Columns->Add("author", "author");
			}
		}

		///////////////////////////MyForm3_gridbook_data/////////////////////////////////////////////
		void gridbook_data(book^ b, DataGridView^% datagrid)
		{
			ArrayList^ row = gcnew ArrayList;
			row->Add(b->title);
			row->Add(b->price);
			row->Add(b->genre);
			row->Add(b->author);
			datagrid->Rows->Add(row->ToArray());

		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"name book";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(111, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(111, 82);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"show";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(218, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"search";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(24, 111);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(437, 221);
			this->dataGridView1->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(326, 46);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"buy";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm3::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(326, 82);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"borrow";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm3::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(44, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"request date";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(339, 9);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"ordered";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm3::button5_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 344);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		///////////////////////////MyForm3_button2_Click/////////////////////////////////////////////
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{

		librarian^ li = gcnew librarian();
		dataGridView1->Columns->Clear();
		if (textBox1->Text == "")
		{
			MessageBox::Show("please enter data !!!");
			return;
		}

		book^ b = gcnew book();
		//	user^ u = gcnew user();

		String^ s = li->cheak(textBox1->Text, read);
		if (s == "-1")
		{
			MessageBox::Show("the book is not availabe");
			return;
		}
		else
		{
			b = li->search(textBox1->Text, read->books);
			gridbook_header(dataGridView1);
			gridbook_data(b, dataGridView1);
		}
	}
			 ///////////////////////////MyForm3_button1_Click/////////////////////////////////////////////
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView1->Columns->Clear();


		gridbook_header(dataGridView1);
		for each (KeyValuePair<String^, book^> ^pair in read->books)
		{
			gridbook_data(pair->Value, dataGridView1);
		}


	}

	private: System::Void MyForm3_Load(System::Object^  sender, System::EventArgs^  e)
	{
		button3->Visible = false;
		button4->Visible = false;
		label2->Visible = false;
	   textBox2->Visible = false;

	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)     //buy button

	{

		if (textBox1->Text == "")
		{
			MessageBox::Show("Please enter book name ");
			return;
		}
		if (READER->isblocked == true)
		{
			MessageBox::Show("you are blocked!!!");
			return;
		}
		String^check = read->admin.cheak(textBox1->Text, read);
		if (check == "-1") {
			MessageBox::Show("this book doesn't exist !!!");
			return;
		}
		if (check == "0") //book
		{
			book^BOOK = gcnew book();
			BOOK = read->admin.search(textBox1->Text, read->books);

			request ^reque = gcnew request();

			// buy(book^b,library^%lib,String ^check,reader^reade)
			reque->buy(BOOK, read, "1", READER,textBox2->Text);

		}
		else {}

		read->admin.write_filerequest(read->requests);
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{

		if (textBox1->Text == "")
		{
			MessageBox::Show("Please enter book name ");
			return;
		}
		if (READER->isblocked == true)
		{
			MessageBox::Show("you are blocked!!!");
			return;
		}
		String^check = read->admin.cheak(textBox1->Text, read);
		if (check == "-1") {
			MessageBox::Show("this book doesn't exist !!!");
			return;
		}
		if (check == "0")
		{
			book^BOOK = gcnew book();
			BOOK = read->admin.search(textBox1->Text, read->books);
			request ^reque = gcnew request();
			reque->buy(BOOK, read, "0", READER,textBox2->Text);
		}
		else {}

	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		button3->Visible = true;
		button4->Visible = true;
		label2->Visible = true;
		textBox2->Visible = true;
	}
};
}
