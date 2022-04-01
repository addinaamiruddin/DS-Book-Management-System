#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#define SIZE 100
using namespace std;

struct node
{
    string title, author;
    int code;
    node *next;
    node *prev;
};

struct node *head, *tail = NULL;

class BS
{
    public :

	//displaying the book list
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
                    cout<<"   "<< ptr->code<<"    "<< ptr->title<<"    \t"<< ptr->author<<endl;
                    ptr = ptr->next;
                }
            }
        }
	
    void addNode(int qty)
    {
        int code;
        string title, author;

        cout<<"\n   Please enter the books' details."<<endl;

        for(int i=0; i<qty; i++)
        {
            fflush(stdin);
            cout<<"   Book code: ";
            cin>>code;

            fflush(stdin);
            cout<<"   Book Name: ";
            getline(cin,title);

            fflush(stdin);
            cout<<"   Book Author: ";
            getline(cin,author);
            cout<<endl;

            fflush(stdin);

            //Create a new node
            //struct node *newNode = (struct node*)malloc(sizeof(struct node));
            struct node* newNode = new node;
            newNode->code = code;
            newNode->title = title;
            newNode->author = author;

            //If list is empty
            if(head == NULL)
            {
                //Both head and tail will point to newNode
                head = tail = newNode;
                //head's prev will point to NULL
                head->prev = NULL;
                //tail's next will point to NULL, as it is the last node of the list
                tail->next = NULL;
            }
            else
            {
                //newNode will be added after tail such that tail's next will point to newNode
                tail->next = newNode;
                //newNode's prev will point to tail
                newNode->prev = tail;
                //newNode will become new tail
                tail = newNode;
                //As it is last node, tail's next will point to NULL
                tail->next = NULL;
            }

        }

    }

    //display() will print out the nodes of the list
    void display()
    {
        //Node current will point to head
        struct node *current = head;
        if(head == NULL)
        {
            cout<<"List is empty\n";
            return;
        }
        while(current != NULL)
        {
            //Prints each node by incrementing pointer.
            cout<<"Code\t: "<<current->code<<endl;
            cout<<"Title\t:"<<current->title<<endl;
            cout<<"Author\t:"<<current->author<<"\n\n";
            current = current->next;
        }
        cout<<"\n";
    }

//delete record
        void deleteBook(int code)
        {
            struct node *temp = head;
            struct node *ptr = head;

            while(temp != NULL)
            {
                if(temp->code==code)
                {
                    cout<<"   Book with ID "<<code<<" Found !!!"<<endl;

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

                    cout<<"   Book with ID "<<code<<" is sucessfully Deleted"<<endl;
                }
                ptr = temp;
                temp = temp->next;
            }
        }

        //update book
        void updateBook(int code)
        {
            node *ptr = head;

            while(ptr != NULL)
            {
                if(ptr->code==code)
                {
                    cout<<"   Book with ID "<<code<<" Found !!!"<<endl;

                    fflush(stdin);
                    cout<<"\n   Book Name: ";
                    getline(cin, ptr->title);
                    cout<<"   Book Author: ";
                    getline(cin, ptr->author);
                    cout<<endl;

                    cout<<"   Book Details with the ID "<<code<<" is successfully updated !!!"<<endl;
                }
                ptr = ptr->next;
            }
        }
        void sortCode() //BUBBLE SORT
        {
            //Bubble Sort
            int i = 0, j;
            int sorted;

            struct node *ptr=head;
            struct node *temp=head->next;
            int hold;

            //Node current will point to head
            //going through the linked list
            if(head == NULL)
            {
                cout<<"List is empty\n";
                return;
            }
            else if ((ptr!=NULL) && (sorted==0))
            {
                sorted = 1;
                while (ptr!=NULL)
                {
                    if(ptr->code>temp->code)
                    {
                        hold = ptr->code;
                        ptr->code = temp->code;
                        temp->code = hold;
                        sorted = 0;
                    }
                }
                ptr=ptr->next;
                temp=temp->next;
            }

            struct node *newPtr=head;
            //Elements after being sorted
            cout<<"Sorted codes list : "<<endl;
            for(i=0; i<SIZE; i++)
            {
                cout<<newPtr->code<<endl;
                newPtr=newPtr->next;
            }
        }

        void sortAuthor() //BUBBLE SORT
        {
            node *temp = head->next;
            node *ptr = head;
            int j, i, sorted;
            string hold;

            if (ptr == NULL)
            {
                cout<<"   System Empty "<<endl;
            }
            else if (ptr!=NULL)
            {
                i = 0;
                while (ptr!=NULL)
                {
                    sorted = 1;
                    while (ptr!=NULL)
                    {
                        if((ptr->author).at(0)>(temp->author).at(0))
                        {
                            hold = ptr->author;
                            ptr->author = temp->author;
                            temp->author = hold;
                            sorted = 0;
                        }
                    }
                    ptr=ptr->next;
                    temp=temp->next;
                }
            }

            node *newPtr = head;
            //Elements after being sorted
            cout<<"Sorted authors list : "<<endl;
            cout<<" Author  | CODE |  Title\t\t\t\t  "<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;

            while(newPtr != NULL)
            {
                cout<<newPtr->author<<" | "<<newPtr->code<<" | "<<newPtr->title<<endl;
                newPtr=newPtr->next;
            }
        }

        void sortTitle() //BUBBLE SORT
        {
            node *temp = head->next;
            node *ptr = head;
            int j, i, sorted;
            string hold;

            if (ptr == NULL)
            {
                cout<<"   System Empty "<<endl;
            }
            else if (ptr!=NULL)
            {
                i = 0;
                while (ptr!=NULL)
                {
                    sorted = 1;
                    while (ptr!=NULL)
                    {
                        if((ptr->title).at(0)>(temp->title).at(0))
                        {
                            hold = ptr->title;
                            ptr->title= temp->title;
                            temp->title = hold;
                            sorted = 0;
                        }
                    }
                    ptr=ptr->next;
                    temp=temp->next;
                }
            }

            node *newPtr = head;
            //Elements after being sorted
            cout<<"Sorted Title list : "<<endl;
            cout<<"  Title\t\t\t\t | CODE |  Author  "<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;

            while(newPtr != NULL)
            {
                cout<<newPtr->title<<" | "<<newPtr->code<<" | "<<newPtr->author<<endl;
                newPtr=newPtr->next;
            }
        }
	
	//search using linearSearch
        void searchCode(int target)
        {
            int i;
            int found;

            node *temp = head;
            node *ptr = head;

            if (target==0)
                return;

            if (ptr == NULL)
            {
                cout<<"   No Book Record Available"<<endl;
            }
            else if ((ptr != NULL) && (found=0))
            {
                if (ptr->code == target)
                {
                    cout<<ptr->code<<endl;
                    cout<<"\nBook title is "<<ptr->title<<endl;
                    cout<<"Written by "<<ptr->author<<endl;
                    ptr = ptr->next;
                    found=1;
                }
            }
            cout<<endl;
        }

};

int main()
{
    int a, choice, code;
    BS bs;
	
	cout<<"=============================================="<<endl;
	cout<<"\t\tWELCOME TO"<<endl;
	cout<<"\tLIBRARY MANAGEMENT SYSTEM"<<endl;
	cout<<"==============================================\n"<<endl;

	cout<<"\t*****************************"<<endl;
	cout<<"\t*\t(1) SEE BOOK LIST \t    *"<<endl<<endl;
	cout<<"\t*\t(2) Add Book\t    *"<<endl;

	cout<<"\t*\t(3) Delete Book\t    *"<<endl;
	cout<<"\t*\t(4) Update Book\t    *"<<endl<<endl;
	cout<<"\t*\tSORTING SECTION *"<<endl;
	cout<<"\t*\t(5) Based on Book Code\t    *"<<endl;
	cout<<"\t*\t(6) Based on Author\t    *"<<endl;
	cout<<"\t*\t(7) Based on Title\t    *"<<endl<<endl;
	cout<<"\t*\tSEARCH SECTION *"<<endl;
	cout<<"\t*\t(8) Based on Book Code *"<<endl<<endl<<endl;
	cout<<"\t*\t(0) Exit\t    *"<<endl;
	cout<<"\t*****************************\n"<<endl;

	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"   Please enter your choice: ";
	cin>>choice;

    cout<<"   Please enter your choice: ";
	cin>>choice;

	do
    {
        switch(choice)
        {
            case 1: //works
		bs.Book_List();
                break;

            case 2: //works
                cout<<"\n   How many books do you want to add? ";
                cin>>a;

                bs.addNode(a);

                bs.display();
                cout<<"   Book Details Inserted Sucessfully"<<endl;
                break;

            case 3 : //works
                cout<<"\n   Enter the book ID whose details is to be deleted: ";
                cin>>code;

                bs.deleteBook(code);
                break;

            case 4 : //works
                cout<<"\n   Enter the book ID whose details is to be updated: ";
                cin>>code;

                bs.updateBook(code);
                break;

            case 5 : //stopped running
                bs.sortCode();
                break;

            case 6 : 
                bs.sortAuthor();
                break;

            case 7 :
		bs.sortTitle();
                break;

            case 8 : //works
                cout<<"Enter book code you want to search [NO to exit]: ";
                cin>>target;
                bs.searchCode(target);
                break;
        }
        fflush(stdin);
        cout<<"   Please enter your choice: ";
        cin>>choice;
    } while (choice!=0);
	
    return 0;
}
