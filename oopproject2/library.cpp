#include "library.h"



library::library()
{
	readers = gcnew Dictionary<String^, reader^>();
	books = gcnew Dictionary<String^, book^>();
	requests = gcnew Dictionary<String^, List<request^>^>();
	orderedlist = gcnew Dictionary<String^, Queue<request^>^>();
	admin.id = "admin";
	admin.passowerd = "admin";

}
book::book()
{
	ISBN = gcnew String("");
	title = gcnew String("");
	location = gcnew String("");
	int no_of_copies;
	double price;
	String^genre;
	String^author;
	int no_of_borrow = 0;
}
/*
buy::buy(){}

borrow::borrow(){}
*/

request::request()
{
	/*stat++;

	id=stat.ToString();*/



}

request::request(String^u_id, String^isbn, String ^ check,String^reqestdat)
{
	stat++;
	this->id = stat.ToString();
	this->isbn = isbn;
	this->checkrequest = check;
	this->user_id = u_id;
	this->requestdate = reqestdat;

	//	DateTime now=DateTime::Now;
	//	this->requestdate=now.Date;
	//this->duedata=gcnew DateTime();
	//	this->duedata=now.Date;
}
void request::buy(book^b, library^%lib, String ^check, reader^reade, String^reqestdat)
{

	request^req = gcnew request(reade->id, b->ISBN, check, reqestdat);
	if (b->no_of_copies == b->no_of_borrow || b->no_of_copies == 0)
	{
		DialogResult result = MessageBox::Show("this book is invalid now to add your self to ordered list press ok", "Caution"
			, MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);

		if (result == DialogResult::OK)
		{
			
		}
		return;
	}
	for each (KeyValuePair<String^, book^>^pair in lib->books)
	{
		if (pair->Key == b->title)
		{
			pair->Value->no_of_copies--;
			lib->admin.addrequest(req, lib);
			lib->admin.write_filerequest(lib->requests);
			
			lib->admin.write_filebook(lib->books);
			break;
		}
	}


}

void request::borrow(book^b, library^%lib, String ^check, reader^reade, String^reqestdat)
{


	request^req = gcnew request(reade->id, b->ISBN, check, reqestdat);
	if (b->no_of_copies == b->no_of_borrow || b->no_of_copies == 0)
	{
		DialogResult result = MessageBox::Show("this book is invalid now to add your self to ordered list press ok", "Caution"
			, MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);

		if (result == DialogResult::OK)
		{
			//add orderlist
		}
		return;
	}


	for each (KeyValuePair<String^, book^>^pair in lib->books)
	{
		if (pair->Key == b->title)
		{
			pair->Value->no_of_borrow++;
			lib->admin.addrequest(req, lib);
			lib->admin.write_filerequest(lib->requests);
			lib->admin.write_filebook(lib->books);
		}
	}
	MessageBox::Show("done");


}
void librarian::addrequest(request^req, library^%lib)
{
	for each (KeyValuePair<String^, List<request^>^>^ pair in lib->requests)
	{
		if (pair->Key == req->user_id)
		{
			pair->Value->Add(req);
			return;
		}
	}

	List<request^>^list = gcnew List<request^>();


	list->Add(req);

	lib->requests->Add(req->user_id, list);
	MessageBox::Show("done");
	

}

void request::addorderlist(book^bookname,String^check, String^reqestdat, String^idreader, library^%lib)
{
	request^ req = gcnew request(idreader, bookname->ISBN, check, reqestdat);
	for each (KeyValuePair<String^, Queue<request^>^> ^pair in lib->orderedlist)
	{
		if (pair->Key == bookname->title)
		{
			pair->Value->Enqueue(req);
			lib->admin.write_fileorderlist(lib->orderedlist);
			return;
		}
	}
		
	Queue<request^>^ q = gcnew Queue<request^> ();
	q->Enqueue(req);
	lib->orderedlist->Add(bookname->title, q);
	lib->admin.write_fileorderlist(lib->orderedlist);	
}
///////////////////////////search reader /////////////////////////////////////////////
reader^ librarian::search(String^s_id, Dictionary<String^, reader^>^list)
{
	reader^r = gcnew reader;

	for each (KeyValuePair<String^, reader^> ^pair in list)
	{
		if (pair->Key == s_id)
		{
			r = pair->Value;
			return r;
		}
	}
	return r;

}
///////////////////////////add reader /////////////////////////////////////////////
void librarian::addreader(String^first, String^last, String^addres, String^ phone, String^emal, Dictionary<String^, reader^>^% dic)
{
	reader ^read = gcnew reader();

	read->firstname = first;
	read->lastname = last;
	read->address = addres;
	read->cellphone = phone;
	read->email = emal;
	read->id = phone;
	read->passowerd = first;
	read->isblocked = false;

	dic->Add(read->id, read);
}
///////////////////////////search book /////////////////////////////////////////////
book^ user::search(String^name, Dictionary<String^, book^>^%list)
{
	book^b = gcnew book;

	for each (KeyValuePair<String^, book^> ^pair in list)
	{
		if (pair->Key == name)
		{
			b = pair->Value;
			return b;
		}
	}

	return b;

}

///////////////////////////addbook/////////////////////////////////////////////
void librarian::addbook(String^isb, String^tit, String^loc, int num, double pri, String^ gen,
	String^ au, Dictionary<String^, book^>^%dic)
{
	String^b;
	library^l = gcnew library();
	b = cheak(tit, l);
	if (b == "-1")
	{

		book^ boo = gcnew book();
		boo->ISBN = isb;
		boo->title = tit;
		boo->location = loc;
		boo->no_of_copies = num;
		boo->genre = gen;
		boo->price = pri;
		boo->author = au;
		boo->no_of_borrow = 0;
		dic->Add(boo->title, boo);
	}
	else
	{
		for each (KeyValuePair<String^, book^>^ pair in dic)
		{
			if (pair->Key == tit)
			{
				pair->Value->no_of_copies += num;
			}
		}
	}

	//write_filebook(dic);

}
///////////////////////////write_filebook/////////////////////////////////////////////
void librarian::write_filebook(Dictionary<String^, book^>^%dic)
{
	if (File::Exists("Book.xml"))
	{
		XmlDocument ^doc = gcnew XmlDocument();
		doc->Load("Book.xml");
		XmlWriter^ writer = XmlWriter::Create("Book.xml");
		writer->WriteStartDocument();
		writer->WriteStartElement("root");
		writer->Close();
	}

	for each (KeyValuePair <String^, book^>^pair  in dic)
	{
		if (!File::Exists("Book.xml"))
		{
			MessageBox::Show("file not exist start");
			XmlWriter^ writer = XmlWriter::Create("Book.xml");
			writer->WriteStartDocument();
			writer->WriteStartElement("root");

			writer->WriteStartElement("Book");

			writer->WriteStartElement("ISBN");
			writer->WriteString(pair->Value->ISBN);
			writer->WriteEndElement();

			writer->WriteStartElement("title");
			writer->WriteString(pair->Value->title);
			writer->WriteEndElement();

			writer->WriteStartElement("location");
			writer->WriteString(pair->Value->location);
			writer->WriteEndElement();

			writer->WriteStartElement("no_of_copies");
			writer->WriteString((pair->Value->no_of_copies).ToString());
			writer->WriteEndElement();

			writer->WriteStartElement("price");
			writer->WriteString((pair->Value->price).ToString());
			writer->WriteEndElement();

			writer->WriteStartElement("genre");
			writer->WriteString(pair->Value->genre);
			writer->WriteEndElement();

			writer->WriteStartElement("author");
			writer->WriteString(pair->Value->genre);
			writer->WriteEndElement();

			writer->WriteStartElement("no_of_borrow");
			writer->WriteString((pair->Value->no_of_borrow).ToString());
			writer->WriteEndElement();

			writer->WriteEndElement();
			writer->WriteEndElement();
			writer->WriteEndDocument();
			writer->Close();
			MessageBox::Show("file not exist end");
		}
		else {
			XmlDocument^doc = gcnew XmlDocument();
			MessageBox::Show("file is exist start");

			XmlElement^ Book = doc->CreateElement("Book");
			XmlElement^ node = doc->CreateElement("ISBN");
			node->InnerText = pair->Value->ISBN;
			Book->AppendChild(node);

			node = doc->CreateElement("title");
			node->InnerText = pair->Value->title;
			Book->AppendChild(node);

			node = doc->CreateElement("location");
			node->InnerText = pair->Value->location;
			Book->AppendChild(node);

			node = doc->CreateElement("no_of_copies");
			node->InnerText = (pair->Value->no_of_copies).ToString();
			Book->AppendChild(node);

			node = doc->CreateElement("price");
			node->InnerText = (pair->Value->price).ToString();
			Book->AppendChild(node);

			node = doc->CreateElement("genre");
			node->InnerText = pair->Value->genre;
			Book->AppendChild(node);

			node = doc->CreateElement("author");
			node->InnerText = pair->Value->author;
			Book->AppendChild(node);

			node = doc->CreateElement("no_of_borrow");
			node->InnerText = (pair->Value->no_of_borrow).ToString();
			Book->AppendChild(node);

			doc->Load("Book.xml");

			XmlElement^ root = doc->DocumentElement;
			root->AppendChild(Book);
			doc->Save("Book.xml");
			MessageBox::Show("file is exist start");
		}

	} //for each

}
///////////////////////////write_filereader/////////////////////////////////////////////
void librarian::write_filereader(Dictionary<String^, reader^>^%dic)
{
	if (File::Exists("Reader.xml"))
	{
		MessageBox::Show("crate start");
		XmlDocument ^doc = gcnew XmlDocument();
		doc->Load("Reader.xml");
		XmlWriter^ writer = XmlWriter::Create("Reader.xml");
		writer->WriteStartDocument();
		writer->WriteStartElement("root");
		writer->Close();
		MessageBox::Show("create end");
	}

	for each (KeyValuePair <String^, reader^>^pair  in dic)
	{
		if (!File::Exists("Reader.xml"))
		{
			MessageBox::Show("file not exist start");
			XmlWriter^ writer = XmlWriter::Create("Reader.xml");
			writer->WriteStartDocument();
			writer->WriteStartElement("root");

			writer->WriteStartElement("Reader");

			writer->WriteStartElement("firstname");
			writer->WriteString(pair->Value->firstname);
			writer->WriteEndElement();

			writer->WriteStartElement("lastname");
			writer->WriteString(pair->Value->lastname);
			writer->WriteEndElement();

			writer->WriteStartElement("address");
			writer->WriteString(pair->Value->address);
			writer->WriteEndElement();

			writer->WriteStartElement("cellphone");
			writer->WriteString(pair->Value->cellphone);
			writer->WriteEndElement();

			writer->WriteStartElement("email");
			writer->WriteString(pair->Value->email);
			writer->WriteEndElement();

			writer->WriteStartElement("isblocked");
			writer->WriteString((pair->Value->isblocked).ToString());
			writer->WriteEndElement();

			writer->WriteStartElement("id");
			writer->WriteString(pair->Value->id);
			writer->WriteEndElement();

			writer->WriteStartElement("passowerd");
			writer->WriteString(pair->Value->passowerd);
			writer->WriteEndElement();

			writer->WriteEndElement();
			writer->WriteEndElement();
			writer->WriteEndDocument();
			writer->Close();
			MessageBox::Show("file not exist end");
		}
		else {
			XmlDocument^doc = gcnew XmlDocument();
			MessageBox::Show("file is exist start");

			XmlElement^ Reader = doc->CreateElement("Reader");
			XmlElement^ node = doc->CreateElement("firstname");
			node->InnerText = pair->Value->firstname;
			Reader->AppendChild(node);

			node = doc->CreateElement("lastname");
			node->InnerText = pair->Value->lastname;
			Reader->AppendChild(node);

			node = doc->CreateElement("address");
			node->InnerText = pair->Value->address;
			Reader->AppendChild(node);

			node = doc->CreateElement("cellphone");
			node->InnerText = (pair->Value->cellphone);
			Reader->AppendChild(node);

			node = doc->CreateElement("email");
			node->InnerText = (pair->Value->email);
			Reader->AppendChild(node);

			node = doc->CreateElement("isblocked");
			node->InnerText = pair->Value->isblocked.ToString();
			Reader->AppendChild(node);

			node = doc->CreateElement("id");
			node->InnerText = pair->Value->id;
			Reader->AppendChild(node);

			node = doc->CreateElement("passowerd");
			node->InnerText = pair->Value->passowerd;
			Reader->AppendChild(node);

			doc->Load("Reader.xml");

			XmlElement^ root = doc->DocumentElement;
			root->AppendChild(Reader);
			doc->Save("Reader.xml");
			MessageBox::Show("file is exist start");
		}

	} //for each

}
///////////////////////////write_fileorderlist/////////////////////////////////////////////
void librarian::write_fileorderlist(Dictionary<String^, Queue<request^>^>^%dic)
{
	if (File::Exists("OrderList.xml"))
	{
		MessageBox::Show("crate start");
		XmlDocument ^doc = gcnew XmlDocument();
		doc->Load("OrderList.xml");
		XmlWriter^ writer = XmlWriter::Create("OrderList.xml");
		writer->WriteStartDocument();
		writer->WriteStartElement("root");
		writer->Close();
		MessageBox::Show("create end");
	}
	for each (KeyValuePair <String^, Queue<request^>^>^pair  in dic)
	{
		if (!File::Exists("OrderList.xml"))
		{
			MessageBox::Show("file not exist start");
			XmlWriter^ writer = XmlWriter::Create("OrderList.xml");
			writer->WriteStartDocument();
			writer->WriteStartElement("root");

			writer->WriteStartElement("OrderList");
			Queue<request^>^q = pair->Value;
			while (q->Count != 0)
			{
				request^r = q->Dequeue();
				writer->WriteStartElement("request");

				writer->WriteStartElement("isbn");
				writer->WriteString(r->isbn);
				writer->WriteEndElement();

				writer->WriteStartElement("id");
				writer->WriteString(r->id);
				writer->WriteEndElement();

				writer->WriteStartElement("user_id");
				writer->WriteString(r->user_id);
				writer->WriteEndElement();

				writer->WriteStartElement("checkrequest");
				writer->WriteString(r->checkrequest);
				writer->WriteEndElement();

				writer->WriteStartElement("requestdate");
				writer->WriteString(r->requestdate);
				writer->WriteEndElement();

				writer->WriteStartElement("duedata");
				writer->WriteString(r->duedata);
				writer->WriteEndElement();

				writer->WriteEndElement();
			}
			writer->WriteEndElement();
			writer->Close();
			MessageBox::Show("file not exist end");
		}
		else
		{
			XmlDocument^doc = gcnew XmlDocument();
			MessageBox::Show("file is exist start");
			XmlElement^ OrderList = doc->CreateElement("OrderList");

			Queue<request^>^q = pair->Value;
			while (q->Count != 0)
			{
				request^r = q->Dequeue();
				XmlElement^ request = doc->CreateElement("request");

				XmlElement^ node = doc->CreateElement("isbn");
				node->InnerText = r->isbn;
				request->AppendChild(node);

			    node = doc->CreateElement("id");
				node->InnerText = r->id;
				request->AppendChild(node);

				node = doc->CreateElement("user_id");
				node->InnerText = r->user_id;
				request->AppendChild(node);

				node = doc->CreateElement("checkrequest");
				node->InnerText = r->checkrequest;
				request->AppendChild(node);

				node = doc->CreateElement("requestdate");
				node->InnerText = r->requestdate;
				request->AppendChild(node);

				node = doc->CreateElement("duedata");
				node->InnerText = r->duedata;
				request->AppendChild(node);

				OrderList->AppendChild(request);
			}
			doc->Load("OrderList.xml");

			XmlElement^ root = doc->DocumentElement;
			root->AppendChild(OrderList);
			doc->Save("OrderList.xml");
			MessageBox::Show("file is exist start");

		}
	}
}
///////////////////////////write_filerequest/////////////////////////////////////////////
void librarian::write_filerequest(Dictionary<String^, List<request^>^>^%dic)
{
	if (File::Exists("ListRequest.xml"))
	{
		MessageBox::Show("crate start");
		XmlDocument ^doc = gcnew XmlDocument();
		doc->Load("ListRequest.xml");
		MessageBox::Show("crate start");
		XmlWriter^ writer = XmlWriter::Create("ListRequest.xml");
		MessageBox::Show("crate end");
		writer->WriteStartDocument();
		writer->WriteStartElement("root");
		writer->Close();
		MessageBox::Show("create end");
	}
	for each (KeyValuePair<String^, List<request^>^>^pair  in dic)
	{
		if (!File::Exists("ListRequest.xml"))
		{
			MessageBox::Show("file not exist start");
			MessageBox::Show("show1");
			XmlWriter^ writer = XmlWriter::Create("ListRequest.xml");
			MessageBox::Show("show2");
			writer->WriteStartDocument();
			MessageBox::Show("show3");
			writer->WriteStartElement("root");
			MessageBox::Show("show4");

			writer->WriteStartElement("list");
			List<request^>^l = pair->Value;
			for (int i = 0; i < l->Count; i++)
			{
				request^r = l[i];
				writer->WriteStartElement("request");

				writer->WriteStartElement("user_id");
				writer->WriteString(r->user_id);
				writer->WriteEndElement();

				writer->WriteStartElement("id");
				writer->WriteString(r->id);
				writer->WriteEndElement();				
				
				writer->WriteStartElement("isbn");
				writer->WriteString(r->isbn);
				writer->WriteEndElement();

				writer->WriteStartElement("checkrequest");
				writer->WriteString(r->checkrequest);
				writer->WriteEndElement();

				writer->WriteStartElement("requestdate");
				writer->WriteString(r->requestdate);
				writer->WriteEndElement();

				writer->WriteStartElement("duedata");
				writer->WriteString(r->duedata);
				writer->WriteEndElement();

				writer->WriteEndElement();
			}
			writer->WriteEndElement();
			writer->Close();
			MessageBox::Show("file not exist end");
		}
		else
		{
			XmlDocument^doc = gcnew XmlDocument();
			MessageBox::Show("file is exist start");
			XmlElement^ list = doc->CreateElement("list");

			List<request^>^l = pair->Value;
			for (int i = 0; i < l->Count; i++)
			{
				request^r = l[i];
				XmlElement^ request = doc->CreateElement("request");

				XmlElement^ node = doc->CreateElement("user_id");
				node->InnerText = r->user_id;
				request->AppendChild(node);

				node = doc->CreateElement("id");
				node->InnerText = r->id;
				request->AppendChild(node);

				node = doc->CreateElement("isbn");
				node->InnerText = r->isbn;
				request->AppendChild(node);

				node = doc->CreateElement("checkrequest");
				node->InnerText = r->checkrequest;
				request->AppendChild(node);

				node = doc->CreateElement("requestdate");
				node->InnerText = r->requestdate;
				request->AppendChild(node);

				node = doc->CreateElement("duedata");
				node->InnerText = r->duedata;
				request->AppendChild(node);

				list->AppendChild(request);
			}
			doc->Load("ListRequest.xml");

			XmlElement^ root = doc->DocumentElement;
			root->AppendChild(list);
			doc->Save("ListRequest.xml");
			MessageBox::Show("file is exist start");
		}
	}

}

///////////////////////////removereader/////////////////////////////////////////////
void librarian::removereader(String^name, Dictionary<String^, reader^>^%dic)
{
	MessageBox::Show("remove start");
	for each (KeyValuePair <String^, reader^>^pair  in dic)
	{
		if (pair->Value->id == name)
		{
			dic->Remove(pair->Key);
			MessageBox::Show("" + dic->Count);
			break;
		}
	}
	MessageBox::Show("remove end");
}
///////////////////////////removebook/////////////////////////////////////////////
void librarian::removebook(String^name, Dictionary<String^, book^>^%dic)
{
	MessageBox::Show("remove start");
	for each (KeyValuePair <String^, book^>^pair  in dic)
	{
		if (pair->Value->title == name)
		{
			dic->Remove(pair->Key);
			break;
		}
	}
	MessageBox::Show("remove end");
}
///////////////////////////remove_blocked/////////////////////////////////////////////
void librarian::remove_blocked(Dictionary<String^, reader^>^%dic)
{
	MessageBox::Show("remove start");
	int x = 0;
	for each (KeyValuePair <String^, reader^>^pair  in dic)
	{
		if (pair->Value->isblocked == true)
		{
			x++;
		}
	}
	while (x != 0)
	{
		for each (KeyValuePair <String^, reader^>^pair  in dic)
		{
			if (pair->Value->isblocked == true)
			{
				dic->Remove(pair->Key);
				x--;
				break;
			}
		}
	}
	MessageBox::Show("remove end");
}

//////////////////////cheak reader////////////////////////////////////////////////////////
String^ reader::cheak(String^name, library^lib)
{
	book^b = gcnew book;

	for each (KeyValuePair<String^, book^> ^pair in lib->books)
	{
		if (pair->Key == name)
		{
			b = pair->Value;
			return b->title;
		}
	}
	b->title = "-1";
	return b->title;


}
//////////////////////cheak librarian////////////////////////////////////////////////////////
String^ librarian::cheak(String^id, library^lib)
{
	for each (KeyValuePair<String^, reader^> ^pair in lib->readers)
	{
		if (pair->Key == id)
		{

			return "1";
		}
	}
	for each (KeyValuePair<String^, book^> ^pair in lib->books)
	{
		if (pair->Key == id)
		{
			return "0";
		}
	}
	return "-1";
}
//////////////////////removeorderedlist////////////////////////////////////////////////////////
void librarian::removeorderedlist(String^u_id, String^id_request, String^namebook, String^duedat, library^lib)
{
	
		reader^reade = gcnew reader();
		reade = lib->admin.search(u_id, lib->readers);

		book^BOOK = lib->admin.search(namebook, lib->books);

		while (BOOK->no_of_copies > BOOK->no_of_borrow)
		{
			for each (KeyValuePair<String^, Queue<request^>^>^pa in lib->orderedlist)
			{
				//7sa kda 2n fe 7aga hna m4 mzbota 22ri kda
				if (pa->Key == BOOK->title)
				{
					
					Queue<request^>^q = gcnew Queue<request^>();
					request^ req = q->Dequeue();
					req->duedata = duedat;
					
					if (req->checkrequest == "1")
					{
						for each (KeyValuePair<String^, book^>^pair in lib->books)
						{
							if (pair->Key == BOOK->title)
							{
								pair->Value->no_of_copies--;
								lib->admin.addrequest(req, lib);
								lib->admin.write_filerequest(lib -> requests);
								lib->admin.write_filebook(lib->books);
							}
						}
						
					}
					else if (req->checkrequest == "0")
					{
						for each (KeyValuePair<String^, book^>^pair in lib->books)
						{
							if (pair->Key == BOOK->title)
							{
							
								pair->Value->no_of_borrow++;
								lib->admin.addrequest(req, lib);
								lib->admin.write_filerequest(lib->requests);
								lib->admin.write_filebook(lib->books);
							}
						}
					}

				}
			}
		}
		lib->admin.write_fileorderlist(lib->orderedlist);

			
}

bool library::will_blocked(String^reqdate, String^duedate)
{
	bool^b;
	//List<String^>^s=reqdate->Split('/');
	array<String^>^ date1 = reqdate->Split('/');
	array<String^>^ date2 = duedate->Split('/');
	int req_day = int::Parse(date1[0]);
	int req_month = int::Parse(date1[1]);
	int req_year = int::Parse(date1[2]);

	int due_day = int::Parse(date2[0]);
	int due_month = int::Parse(date2[1]);
	int due_year = int::Parse(date2[2]);
	if (due_month>req_month&&due_day>5)
	{
		return true;
	}
	if (due_month>req_month&&due_day<5)
	{
		if (due_month - req_month>1)
		{
			return true;
		}
		if ((30 - req_day) + due_day>5)
		{
			return true;
		}
		return false;
	}
}
bool librarian::blocked(String^u_id, String^id_request, String^namebook, String^duedat, library^%lib)
{
	String^ch = lib->admin.cheak(u_id, lib);
	bool d = false;
	for each (KeyValuePair<String^, reader^>^pair in lib->readers)
	{
		MessageBox::Show(""+u_id);
		if (pair->Key == u_id)d = true;
		
	}
	if (!d)
	{
		MessageBox::Show("" + u_id);
		MessageBox::Show("invalid reader id");
		return false;
	}
	else  //find user
	{
		reader^reade = gcnew reader();
		reade = lib->admin.search(u_id, lib->readers);
		book^BOOK = lib->admin.search(namebook, lib->books);
		for each (KeyValuePair<String^, List<request^>^>^pair in lib->requests)
		{
			if (pair->Key == u_id)
			{
				List<request^>^ list = pair->Value;
				for (int i = 0; i<list->Count; i++)
				{
					if (id_request == list[i]->id)
					{
						bool boo;
						boo = lib->will_blocked(list[i]->requestdate, duedat);
						//bool=function to sub and return bool
						if (boo == true)
						{
							for each (KeyValuePair<String^, reader^>^pa in lib->readers)
							{
								if (pa->Key == reade->id)
								{
									pa->Value->isblocked = true;
									lib->admin.write_filereader(lib->readers);
								}

							}

						}

					}

				}//end forloop
				for each (KeyValuePair<String^, book^>^pa in lib->books)
				{
					if (pa->Key == BOOK->title)
					{
						pa->Value->no_of_borrow--;
						lib->admin.write_filebook(lib->books);
						
					}
				}
			}
		}
		return true;
	}
}

void library::load_file_orderdic(Dictionary<String^, Queue<request^>^>^dic)
{
	XmlDocument^ doc = gcnew XmlDocument();
	doc->Load("OrderList.xml");
	XmlNodeList^ list = doc->GetElementsByTagName("OrderList");

	String^us_id = L"";
	for (int i = 0; i < list->Count; i++)
	{
		XmlNodeList ^req = list[i]->ChildNodes;
		Queue<request^>^q = gcnew Queue<request^>();
		for (int j = 0; j < req->Count; j++)
		{

			request^ requ = gcnew request();
			XmlNodeList ^childern = req[j]->ChildNodes;
			
			requ->isbn = childern[0]->InnerText;

			requ->id = childern[1]->InnerText;
			requ->user_id = childern[2]->InnerText;
			requ->checkrequest = childern[3]->InnerText;
			requ->requestdate = childern[4]->InnerText;
			requ->duedata = childern[5]->InnerText;
			q->Enqueue(requ);

		}
		
		dic->Add(us_id, q);
	}
}
void librarian::thebest(library^lib){
	String^maxi;
	int max = 0;
	String ^bestuser;
    String^best;
	for each (KeyValuePair<String^, List<request^>^>^pair in lib->requests) 
	{
		if (pair->Value->Count > max) {
			max = pair->Value->Count;
			maxi = max.ToString();
			best = pair->Key;
		}
	}
	for each (KeyValuePair<String^, reader^>^pair in lib->readers) 
	{
		if (pair->Key == best) 
		{
			bestuser = pair->Value->firstname;
			bestuser += "  " + pair->Value->lastname;
			break;
		}
	}
	MessageBox::Show("best user : " + bestuser + " target : " + maxi);

}