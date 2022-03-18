#include<iostream>
#include<string>
#include<fstream>

using namespace std;

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

int main()
{
	head = NULL;
	int a,choice,id, i;
	string aut, myString;
	fstream myFile;
	
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
	
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"   Please enter your choice: ";
	cin>>choice;
	
	do
	{
		if(choice==1)
		{
			cout<<"\n   How many books do you want to add? ";
			cin>>a;
			
			string book[a];
			for(i=0; i<a; i++)
			{
				cout<<"\n   Please enter the books' details."<<endl;
			
				fflush(stdin);
				cout<<"   Book ID: ";
				cin>>id;
				fflush(stdin);
				cout<<"   Book Name: ";
				getline(cin,book[i]);
				cout<<"   Book Author: ";
				getline(cin,aut);
				cout<<endl;
					
				Insert_book(id, book[i], aut); //to insert details to the node
				
				//save book details to txt file
			    myFile.open("test.txt", ios::app);
			   
			    if(myFile.is_open())
			    {
			   		myFile<<id<<"  ";
			   		myFile<<book[i]<<"  ";
			   		myFile<<aut<<" "<<endl;
				}
				myFile.close();
			}
   		}
	    else if(choice==2) //caling book list function
	    {
		   Book_List();
		   
		   //print from text file
		   /*ifstream MyReadFile("test.txt");
		   cout<<"\n   *************************************************"<<endl;
		   cout<<"   These are the books in the library: "<<endl;
		   
		   while(getline(MyReadFile, myString))
		   {
		   		cout<<"\t\t"<<myString<<endl;
		   }
		   
		   cout<<"   *************************************************"<<endl;*/
		}
	    else if(choice==3) //calling delete function 
	    {
	   		cout<<"\n   Enter the book ID whose details is to be deleted: ";
	   		cin>>id;
	   		
	   		Delete_book(id);
	    }
	    cout<<"\n   Please enter your choice: ";
	    cin>>choice;
   
   }while(choice!=4);
}
