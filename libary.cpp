
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct book {
	
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

//delete record
void Delete_book(int Id)
{
	node *temp = head;
	node *ptr = head;
	
	while(temp != NULL)
	{
		if(temp->ID==Id)
		{
			cout<<"   Book with ID "<<Id<<" Found !!!"<<endl;
			
			if(temp == ptr)
			{
				head = head->next;
				delete temp;
			}
			else
			{
				ptr->next = temp->next;
				delete temp;
			}
			
			cout<<"   Book with ID "<<Id<<" is Sucessfully Deleted"<<endl;
		}
		ptr = temp;
		temp = temp->next;
	}	
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
void Update_Book(int Id)
{
	node *ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->ID==Id)
		{
			cout<<"   Book with ID "<<Id<<" Found !!!"<<endl;
			
			fflush(stdin);
			cout<<"\n   Book Name: ";
			getline(cin, ptr->book_name);
			cout<<"   Book Author: ";
			getline(cin, ptr->author);
			cout<<endl;
			
			cout<<"   Book Details with the ID "<<Id<<" is successfully updated !!!"<<endl;
		}
		ptr = ptr->next;
	}
}

int main()
{
	book s;
	head = NULL;
	int a,choice,id, i,b;
	string myString;
	
	cout<<"=============================================="<<endl;
	cout<<"\t\tWELCOME TO"<<endl;
	cout<<"\tLIBRARY MANAGEMENT SYSTEM"<<endl;
	cout<<"==============================================\n"<<endl;
	
	cout<<"\t*****************************"<<endl;
	cout<<"\t*\t(1) Add Book\t    *"<<endl;
	cout<<"\t*\t(2) Book list\t    *"<<endl;
	cout<<"\t*\t(3) Delete Book\t    *"<<endl;
	cout<<"\t*\t(4) Update Book\t    *"<<endl;
	cout<<"\t*\t(5) Exit\t    *"<<endl;
	cout<<"\t*****************************\n"<<endl;
	
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"   Please enter your choice: ";
	cin>>choice;
	
	do
	{
		if(choice==1)
		{
			cout<<"\n   How many books do you want to add? ";
			cin>>a;
			
			
			for(i=0; i<a; i++)
			{
				cout<<"\n   Please enter the books' details."<<endl;
			
				fflush(stdin);
				cout<<"   Book ID: ";
				cin>>s.id;
				fflush(stdin);
				cout<<"   Book Name: ";
				getline(cin,s.title);
				cout<<"   Book Author: ";
				getline(cin,s.aut);
				cout<<endl;
					
				Insert_book(s.id, s.title, s.aut); //to insert details to the node
				
			
			}
   		}
	    else if(choice==2) //caling book list function
	    {
		   Book_List();
		}
	    else if(choice==3) //calling delete function 
	    {
	   	cout<<"\n   Enter the book ID whose details is to be deleted: ";
	   	cin>>b;
	   		
	   	Delete_book(b);
	    }
	    else if(choice==4){
	    	cout<<"\n   Enter the book ID whose details is to be updated: ";
			cin>>id;
			
			Update_Book(id);
		}
	    cout<<"\n   Please enter your choice: ";
	    cin>>choice;
   
   }while(choice!=5);
}
