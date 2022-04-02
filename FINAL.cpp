#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
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
                cout<<"\n   Code\tTitle\t\tAuthor"<<endl;
                cout<<"----------------------------------------------"<<endl;

                //display the list of books
                while (ptr != NULL)
                {
                    cout<<"   "<<ptr->code<<"\t"<<ptr->title<<"\t\t"<<ptr->author<<endl;
                    ptr = ptr->next;
                }
            }
        }

    void addNode(int qty)
    {
        int code;
        string title, author;

        cout<<"\n   Please enter the books' details."<<endl<<endl;

        for(int i=0; i<qty; i++)
        {
            fflush(stdin);
            cout<<"\tBook code: ";
            cin>>code;

            fflush(stdin);
            cout<<"\tBook Name: ";
            getline(cin,title);
            fflush(stdin);

            fflush(stdin);
            cout<<"\tBook Author: ";
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
            cout<<"\tCode\t: "<<current->code<<endl;
            cout<<"\tTitle\t: "<<current->title<<endl;
            cout<<"\tAuthor\t: "<<current->author<<"\n\n";
            current = current->next;
        }
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

                    cout<<"   Book with code "<<code<<" is sucessfully deleted"<<endl;
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
                    fflush(stdin);
                    cout<<"\n   Book Name: ";
                    getline(cin, ptr->title);
                    cout<<"   Book Author: ";
                    getline(cin, ptr->author);
                    cout<<endl;

                    cout<<"   Book Details with the code "<<code<<" is successfully updated."<<endl;
                }
                ptr = ptr->next;
            }
        }
        void sortCode() //BUBBLE SORT
        {
            //cout<<"can u enter this function"<<endl;
            int sorted=0;

            node *ptr=head;
            int holdCode;
            string holdTitle, holdAuthor;

            struct node* counter = head;//temp pointer points to head
            int count=0; //Initialize count variable

            //GETTING THE AMOUNT OF NODES IN THE LINKED LIST
            while(counter != NULL)
            {
                counter = counter->next;
                count++;
            }

            //cout<<"line 134"<<endl;

            struct node *current = NULL, *temp = NULL;

            //Bubble Sort
            int i = 0;
            while ( (i<count) && (sorted==0) )
            {
                sorted = 1;
                for (current = head; current->next != NULL; current = current->next)
                {
                    for (temp = current->next; temp != NULL; temp = temp->next)
                    {
                        if(current->code>temp->code)
                        {
                            holdCode = current->code;
                            holdTitle = current->title;
                            holdAuthor = current->author;

                            current->code = temp->code;
                            current->title = temp->title;
                            current->author = temp->author;

                            temp->code = holdCode;
                            temp->title = holdTitle;
                            temp->author = holdAuthor;

                            sorted = 0;
                        }
                    }
                }
            }

            node *newPtr = head;
            //Elements after being sorted
            cout<<"\n   Code\tTitle\t\tAuthor"<<endl;
            cout<<"----------------------------------------------"<<endl;
            while(newPtr != NULL)
            {
                cout<<"   "<<newPtr->code<<"\t"<<newPtr->title<<"\t\t"<<newPtr->author<<endl;
                newPtr=newPtr->next;
            }
        }

        void sortAuthor() //BUBBLE SORT
        {
            int sorted=0;

            node *ptr=head;
            int holdCode;
            string holdTitle, holdAuthor;

            struct node* counter = head;//temp pointer points to head
            int count=0; //Initialize count variable

            //GETTING THE AMOUNT OF NODES IN THE LINKED LIST
            while(counter != NULL)
            {
                counter = counter->next;
                count++;
            }

            struct node *current = NULL, *temp = NULL;

            //Bubble Sort
            int i = 0;
            while ( (i<count) && (sorted==0) )
            {
                sorted = 1;
                for (current = head; current->next != NULL; current = current->next)
                {
                    for (temp = current->next; temp != NULL; temp = temp->next)
                    {
                        if((current->author).at(0)>(temp->author).at(0))
                        {
                            holdCode = current->code;
                            holdTitle = current->title;
                            holdAuthor = current->author;

                            current->code = temp->code;
                            current->title = temp->title;
                            current->author = temp->author;

                            temp->code = holdCode;
                            temp->title = holdTitle;
                            temp->author = holdAuthor;

                            sorted = 0;
                        }
                    }
                }
            }

            node *newPtr = head;
            //Elements after being sorted
            cout<<"\n   Author\t\tCode\tTitle"<<endl;
            cout<<"----------------------------------------------"<<endl;
            while(newPtr != NULL)
            {
                cout<<"   "<<newPtr->author<<"\t\t"<<newPtr->code<<"\t"<<newPtr->title<<endl;
                newPtr=newPtr->next;
            }
        }

        void sortTitle() //BUBBLE SORT
        {
            int sorted=0;

            node *ptr=head;
            int holdCode;
            string holdTitle, holdAuthor;

            struct node* counter = head;//temp pointer points to head
            int count=0; //Initialize count variable

            //GETTING THE AMOUNT OF NODES IN THE LINKED LIST
            while(counter != NULL)
            {
                counter = counter->next;
                count++;
            }

            struct node *current = NULL, *temp = NULL;

            //Bubble Sort
            int i = 0;
            while ( (i<count) && (sorted==0) )
            {
                sorted = 1;
                for (current = head; current->next != NULL; current = current->next)
                {
                    for (temp = current->next; temp != NULL; temp = temp->next)
                    {
                        if((current->title).at(0)>(temp->title).at(0))
                        {
                            holdCode = current->code;
                            holdTitle = current->title;
                            holdAuthor = current->author;

                            current->code = temp->code;
                            current->title = temp->title;
                            current->author = temp->author;

                            temp->code = holdCode;
                            temp->title = holdTitle;
                            temp->author = holdAuthor;

                            sorted = 0;
                        }
                    }
                }
            }


            node *newPtr = head;
            //Elements after being sorted
            cout<<"\n   Title\t\tCode\tAuthor"<<endl;
            cout<<"----------------------------------------------"<<endl;
            while(newPtr != NULL)
            {
                cout<<"   "<<newPtr->title<<"\t\t"<<newPtr->code<<"\t"<<newPtr->author<<endl;
                newPtr=newPtr->next;
            }
        }

	//search using linearSearch
        void searchCode(int target)
        {
            int i;
            int found;

            node *ptr = head;

            if (ptr == NULL)
            {
                cout<<"   No Book Record Available"<<endl;
            }

            while ((ptr!=NULL)&&(found==0))
            {
                if (ptr->code == target)
                {
                    cout<<"   Book code is "<<ptr->code<<endl;
                    cout<<"   Title is "<<ptr->title<<endl;
                    cout<<"   Written by "<<ptr->author<<endl;

                    found=1;
                }
                ptr = ptr->next;
            }
        }

};

int main()
{
    int a, choice, code;
    BS bs;

    cout<<"==================================================="<<endl;
	cout<<"\t\tWELCOME TO"<<endl;
	cout<<"\tLIBRARY MANAGEMENT SYSTEM"<<endl;
	cout<<"===================================================\n"<<endl;

	cout<<"\t***********************************"<<endl;
	cout<<"\t*\t(1) SEE BOOK LIST         *"<<endl<<endl;
	cout<<"\t*\t(2) Add Book              *"<<endl;

	cout<<"\t*\t(3) Delete Book           *"<<endl;
	cout<<"\t*\t(4) Update Book           *"<<endl<<endl;
	cout<<"\t*\tSORTING SECTION           *"<<endl;
	cout<<"\t*\t(5) Based on Book Code    *"<<endl;
	cout<<"\t*\t(6) Based on Author       *"<<endl;
	cout<<"\t*\t(7) Based on Title        *"<<endl<<endl;
	cout<<"\t*\tSEARCH SECTION            *"<<endl;
	cout<<"\t*\t(8) Based on Book Code    *"<<endl<<endl;
	cout<<"\t*\t(0) Exit                  *"<<endl;
	cout<<"\t***********************************"<<endl<<endl;

	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;


    cout<<"\n   Please enter your choice: ";
	cin>>choice;
	cout<<endl;

	do
    {
        switch(choice)
        {
            case 1: //works
                cout<<"   BOOK LIST : "<<endl;
                cout<<"   ------------"<<endl;
		        bs.Book_List();
                break;

            case 2: //works
                cout<<"   ADD NEW BOOK : "<<endl;
                cout<<"   ---------------"<<endl;
                cout<<"\n   How many books do you want to add? ";
                cin>>a;

                bs.addNode(a);

                bs.display();
                cout<<"   Book Details Inserted Sucessfully"<<endl;
                break;

            case 3 : //works
                cout<<"   DELETE BOOK : "<<endl;
                cout<<"   --------------"<<endl;
                cout<<"\n   Enter the book ID whose details is to be deleted: ";
                cin>>code;

                bs.deleteBook(code);
                break;

            case 4 : //works
                cout<<"   UPDATE BOOK : "<<endl;
                cout<<"   --------------"<<endl;
                cout<<"\n   Enter the book ID whose details is to be updated: ";
                cin>>code;

                bs.updateBook(code);
                break;

            case 5 : //works
                cout<<"   SORTING : CODE  "<<endl;
                cout<<"   ----------------"<<endl;
                bs.sortCode();
                break;

            case 6 : //works
                cout<<"   SORTING : AUTHOR"<<endl;
                cout<<"   ------------------"<<endl;
                bs.sortAuthor();
                break;

            case 7 : //works
                cout<<"   SORTING : TITLE  "<<endl;
                cout<<"   -----------------"<<endl;
		        bs.sortTitle();
                break;

            case 8 :
                cout<<"   SEARCH : CODE  "<<endl;
                cout<<"   ---------------"<<endl;
                cout<<"   Enter book code you want to search [NO to exit]: ";
                cin>>code;
                cout<<endl;
                bs.searchCode(code);
                break;
        }
        fflush(stdin);

        cout<<"\n==============================================\n"<<endl;
        cout<<"   Please enter your choice: ";
        cin>>choice;
        cout<<endl;
    } while (choice!=0);

    return 0;
}
