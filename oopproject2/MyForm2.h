#pragma once
#include"library.h"
#include"MyForm42.h"

namespace oopproject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		library^read;

	public:
		int choice, order;

	public:

	private: System::Windows::Forms::Button^  button3;
	public:
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		///////////////////////////MyForm2_constructor /////////////////////////////////////////////
		MyForm2(library ^r, int x, int y)
		{
			InitializeComponent();
			read = gcnew library();
			read = r;
			choice = x;
			order = y;
			//
			//TODO: Add the constructor code here
			//
		}

		///////////////////////////MyForm2_gridbook_header /////////////////////////////////////////////
		void gridbook_header(DataGridView^% datagrid)
		{
			if (datagrid->ColumnCount == 0)
			{
				datagrid->Columns->Add("ISBN", "ISBN");
				datagrid->Columns->Add("title", "title");
				datagrid->Columns->Add("location", "location");
				datagrid->Columns->Add("no_of_copies", "no_of_copies");
				datagrid->Columns->Add("price", "price");
				datagrid->Columns->Add("genre", "genre");
				datagrid->Columns->Add("author", "author");

			}
		}

		///////////////////////////MyForm2_gridbook_data /////////////////////////////////////////////
		void gridbook_data(book^ b, DataGridView^% datagrid)
		{
			ArrayList^ row = gcnew ArrayList;
			row->Add(b->ISBN);
			row->Add(b->title);
			row->Add(b->location);
			row->Add(b->no_of_copies);
			row->Add(b->price);
			row->Add(b->genre);
			row->Add(b->author);
			datagrid->Rows->Add(row->ToArray());

		}

		//readers
		///////////////////////////MyForm2_gridreader_header /////////////////////////////////////////////
		void gridreader_header(DataGridView^% datagrid)
		{
			if (datagrid->ColumnCount == 0)
			{
				datagrid->Columns->Add("firstname", "firstname");
				datagrid->Columns->Add("lastname", "lastname");
				datagrid->Columns->Add("address", "address");
				datagrid->Columns->Add("cellphone", "cellphone");
				datagrid->Columns->Add("email", "email");
				datagrid->Columns->Add("isblocked", "isblocked");


			}
		}

		///////////////////////////MyForm2_gridreader_data /////////////////////////////////////////////
		void gridreader_data(reader^ r, DataGridView^% datagrid)
		{
			ArrayList^ row = gcnew ArrayList;
			row->Add(r->firstname);
			row->Add(r->lastname);
			row->Add(r->address);
			row->Add(r->cellphone);
			row->Add(r->email);
			row->Add(r->isblocked);
			datagrid->Rows->Add(row->ToArray());

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 137);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(570, 269);
			this->dataGridView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(111, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(183, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"show data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(183, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(157, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(275, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"search";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(451, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"removeblocked";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 438);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		///////////////////////////MyForm2_Load /////////////////////////////////////////////
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e)
	{
		button3->Visible = false;
		if (choice == 1)
		{
			label1->Text = "Book Name";

		}
		else if (choice == 0)
		{
			label1->Text = "Reader Name";
		}
		if (order == 0)
		{
			button2->Text = "search";
		}
		else if (order == 1)
		{
			button2->Text = "remove";
			if (choice == 0)
			{
				button3->Visible = true;
			}
		}
	}

			 ///////////////////////////MyForm2_button1_Click /////////////////////////////////////////////
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView1->Columns->Clear();

		if (choice == 1)//book
		{
			gridbook_header(dataGridView1);
			for each (KeyValuePair<String^, book^> ^pair in read->books)
			{
				gridbook_data(pair->Value, dataGridView1);
			}


		}

		else if (choice == 0)           //reader
		{
			gridreader_header(dataGridView1);
			for each (KeyValuePair<String^, reader^> ^pair in read->readers)
			{
				gridreader_data(pair->Value, dataGridView1);
			}


		} //end else

	}
			 ///////////////////////////MyForm2_button2_Click /////////////////////////////////////////////
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{

		//----------------------------------------------//
		librarian^l = gcnew librarian();
		dataGridView1->Columns->Clear();
		if (textBox1->Text == "")
		{
			MessageBox::Show("please enter data !!!");
			return;
		}

		if (choice == 1 && order == 0)      //book search
		{
			book^ b = gcnew book();

			//user^ u = gcnew user();
			String^ch = l->cheak(textBox1->Text, read);
			if (ch == "-1")
			{
				MessageBox::Show("the book is not availabe");
			}
			else
			{
				b = l->search(textBox1->Text, read->books);
				gridbook_header(dataGridView1);
				gridbook_data(b, dataGridView1);
			}

		}

		else if (choice == 0 && order == 0)        //reader  search
		{
			reader^ r = gcnew reader();
			String^ ch = l->cheak(textBox1->Text, read);

			if (ch == "-1")
			{
				MessageBox::Show("the reader is not exist");
				return;
			}
			r = read->admin.search(textBox1->Text, read->readers);
			gridreader_header(dataGridView1);
			gridreader_data(r, dataGridView1);

		}

		else if (choice == 0 && order == 1) //remove reader
		{

			read->admin.removereader(textBox1->Text, read->readers);
			read->admin.write_filereader(read->readers);
		}
		else if (choice == 1 && order == 1) //remove book
		{

			read->admin.removebook(textBox1->Text, read->books);
			read->admin.write_filebook(read->books);
		}

		textBox1->Text = "";
	}
			 ///////////////////////////MyForm2_button3_Click /////////////////////////////////////////////
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		read->admin.remove_blocked(read->readers);
		read->admin.removereader(textBox1->Text, read->readers);
		read->admin.write_filereader(read->readers);
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

}
};
}
