#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Xml;
using namespace System::IO;

ref class library;
ref class reader;
ref class librarian;
ref class request;

ref class book
{
public:
	String^ISBN;
	String^title;
	String^location;
	int no_of_copies;
	double price;
	String^genre;
	String^author;
	int no_of_borrow;
	book();

};
ref class user
{
public:
	String^ id;
	String^passowerd;
	book^ search(String^, Dictionary<String^, book^>^%);
	virtual String^cheak(String^, library^) = 0;

};
ref class reader :public user
{
public:
	String^firstname;
	String^lastname;
	String^address;
	String^ cellphone;
	String^email;
	bool isblocked;
	virtual String^cheak(String^, library^)override;
};


ref class library;

ref class request
{
public:
	static int stat = 0;
	String^ id;
	String^isbn;
	String ^user_id;
	String^checkrequest;

	String^requestdate;
	String^duedata;

	request();
	request(String ^u_id, String^isbn, String ^ check, String^reqestdat);

	void buy(book^b, library^%lib, String ^check, reader^reade, String^reqestdat);
	void borrow(book^b, library^%lib, String ^check, reader^reade, String^reqestdat);

	void addorderlist(book^bookname, String^check, String^reqestdat, String^idreader, library^%lib);

};



ref class librarian :public user
{
public:
	//virtual	book^ search(String^, Dictionary<String^, book^>^%)override;
	reader^ search(String^s_id, Dictionary<String^, reader^>^list);

	void addreader(String^, String^, String^, String^, String^, Dictionary<String^, reader^>^%);
	void addbook(String^isb, String^tit, String^loc, int num, double pri, String^ gen, String^ au, Dictionary<String^, book^>^%dic);

	void write_filebook(Dictionary<String^, book^>^%dic);
	void write_filereader(Dictionary<String^, reader^>^%dic);
	void write_filerequest(Dictionary<String^, List<request^>^>^%dic);
	void write_fileorderlist(Dictionary<String^, Queue<request^>^>^%dic);

	void removereader(String^name, Dictionary<String^, reader^>^%dic);
	void removebook(String^name, Dictionary<String^, book^>^%dic);
	void thebest(library^);


	void remove_blocked(Dictionary<String^, reader^>^%dic);
	//  void addorderlist(String^Bookname, library^%lib,request ^ reque);
	virtual String^cheak(String^, library^)override;

	void addrequest(request^req, library^%lib);
	void removeorderedlist(String^u_id, String^id_request, String^namebook, String^duedat, library^lib);
	//gdid
	bool blocked(String^, String^, String^, String^, library^%);

};



ref class library
{
public:
	Dictionary<String^, reader^>^readers;
	Dictionary<String^, book^>^books;
	Dictionary<String^, List<request^>^>^requests;
	Dictionary<String^, Queue<request^>^>^orderedlist;
	bool  will_blocked(String^, String^);

	librarian admin;
	void load_file_orderdic(Dictionary<String^, Queue<request^>^>^dic);
	library();
};


