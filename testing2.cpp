#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
struct bookk {
	
	int id;
	string title;
	string aut;
};


class node
{
	public:
		int data;
		int ID;
		string book_name, author;
		node *next;
};
//store the head of linked list
node *head = new node;

//to insert book's details
void Insert_book(int Id, string Book, string Author)
{
	//create new node to insert book details
	node *temp = new node;
	temp->ID = Id;
	temp->book_name = Book;
	temp->author = Author;
	temp->next = NULL;
	
	//insert node at the beginning 
	if(head == NULL || head->data >= temp->ID)
	{
		temp->next = head;
		head = temp;
	}
	//insert node at the middle or end
	else
	{
		node *t = head;
		while(t->next != NULL && t->next->data < t->ID)
		{
			t = t->next;
		}
		
		temp->next = t->next;
		t->next = temp;
	}
	
	cout<<"   Book Details Inserted Sucessfully"<<endl;
}

void Book_List()
{
    node* ptr = head;
    if (ptr == NULL) 
	{
        cout<<"   No Book Record Available"<<endl;
    }
    else 
	{
        cout<<"\n   ID\t   Book Name\tAuthor"<<endl;
        
        //display the list of books
        while (ptr != NULL) 
		{
            cout<<"   "<< ptr->ID<<"    "<< ptr->book_name<<"    \t"<< ptr->author<<endl;
            ptr = ptr->next;
        }
    }
}
//delete record
int Delete_book(int ID)
{
	node *temp = head;
	node *ptr = NULL;
	
	if(temp != NULL && temp->ID == ID) //check
	{
		head = temp->next;
		delete temp;
		
		cout<<"   The book with the ID "<<ID<<" has been deleted sucessfully"<<endl;
	}
	while(temp != NULL && temp->ID != ID)
	{
		ptr = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		cout<<"   The book does not exist"<<endl;
		return -1;
		
		ptr->next = temp->next;
		
		delete temp;
		cout<<"   The book with the ID "<<ID<<" has been deleted sucessfully"<<endl;
		
		return 0;
	}
}
void header(){
	cout<<"=============================================="<<endl;
	cout<<"\t\tWELCOME TO"<<endl;
	cout<<"\tLIBRARY MANAGEMENT SYSTEM"<<endl;
	cout<<"==============================================\n"<<endl;
	
	cout<<"\t*****************************"<<endl;
	cout<<"\t*\t(1) Add Book\t    *"<<endl;
	cout<<"\t*\t(2) Book list\t    *"<<endl;
	cout<<"\t*\t(3) Delete Book\t    *"<<endl;
	cout<<"\t*\t(4) Exit\t    *"<<endl;
	cout<<"\t*****************************\n"<<endl;
}
void rename_file(){
	if (remove("book.txt") != 0)
		{
			cout << "\nBook is not deleted";
		}
		else {
			cout << "\n";
		}
		if (rename("new.txt", "book.txt") != 0) {
			cout << "\nFile does not rename";
		}
		else {
			cout << "\n";
		}
}

int main() {

loop:
	bookk s;
	int choice, b,a;
	
	
	header();
	
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"   Please enter your choice: ";
	cin>>choice;
	switch (choice) {
	case 1:
	{
		cout<<"\n   How many books do you want to add? ";
		cin>>a;
		for(int i=0;i<a;i++){
		
		cout << "\nEnter book ID: ";
		cin >> s.id;
		fflush(stdin);
		cout << "Enter book title: ";
		getline(cin,s.title);
		cout << "Enter book aut: ";
		getline(cin,s.aut);
		
		Insert_book(s.id, s.title, s.aut);
		
		ofstream sdata;
		sdata.open("book.txt", ios::app);
		sdata << endl << s.id << endl << s.title << endl <<s.aut;
		sdata.close();
		}
		goto loop;
		break;
	}
	case 2:
	{
		
		Book_List();
		/*ifstream tdata;
		tdata.open("book.txt");
		cout << "\nBooks registered:";
		string line;
		while(getline(tdata,line)){
		tdata >> s.id >> s.title >> s.aut;
		cout << endl << s.id << " , " << s.title << " , "<< s.aut;
		}
		
		while (!tdata.eof()) {
			tdata >> s.id >> s.title >> s.aut;
			cout << endl << s.id << " , " << s.title << " , "<< s.aut;
		}
		tdata.close();*/
		goto loop;
		break;

	}
	case 3:
	{
		cout << "\nEnter ID of book to delete: ";
		cin >> b;
		
		Delete_book(b);
		
		ifstream read;
		read.open("book.txt");
		ofstream write;
		write.open("new.txt");
		while (!read.eof()) {
			read >> s.id >> s.title >> s.aut;
			if (s.id != b)
			{
				write << endl << s.id << endl << s.title << endl << s.aut;
			}
			else {
				cout << "\n Book deleted";
			}
		}
		write.close();
		read.close();
		rename_file();
		goto loop;
		break;
		
	}
	case 4:
		break;
	}

}

