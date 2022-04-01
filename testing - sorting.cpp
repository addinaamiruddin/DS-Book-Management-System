#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct node
{
    int code;
	string title;
	string author;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail = NULL;

class BookSystem
{
    //store the head of linked list
    struct node *head = new node;

	public:
        //to insert book's details
        void addBook(int code, string title, string author)
        {
            struct node* newNode = new node;
            newNode->code = code;
            newNode->title = title;
            newNode->author = author;

            //If list is empty
            if(head == NULL) {
                //Both head and tail will point to newNode
                head = tail = newNode;
                //head's prev will point to NULL
                head->prev = NULL;
                //tail's next will point to NULL, as it is the last node of the list
                tail->next = NULL;
            }
            else {
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

        //sort using linear search
        void sortTitle()
        {
            struct node *temp = head->next;
            struct node *ptr = head;
            int j, i;

            //Insertion Sort
            if (ptr==NULL)
            {
                cout<<"   System Empty "<<endl;
            }
            else if (ptr!=NULL)
            {
                string currentAuthor = ptr->author;
                int currentCode = ptr->code;
                string currentTitle = ptr->title;

                j = i;
                while ( (j>0) && (currentTitle.at(0)<(temp->title).at(0)) )
                {
                    ptr->title=temp->title;
                    ptr->author=temp->author;
                    ptr->code=temp->code;

                    temp->author = currentAuthor;
                    temp->title = currentTitle;
                    temp->code = currentCode;

                    ptr=ptr->next;
                    temp=temp->next;
                }
            }

            node *newPtr = head;
            //Elements after being sorted
            cout<<"Sorted titles list : "<<endl;
            cout<<" Title\t\t\t\t    | CODE |  Author"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;

            while(newPtr != NULL)
            {
                cout<<newPtr->title<<"\t\t\t\t    | "<<newPtr->code<<" | "<<newPtr->author<<endl;
                newPtr=newPtr->next;
            }
        }

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

        }
};

int main()
{
	//struct node *head = NULL;
	int choice, i , b, target;

	int a, code;
    string title, author;
    BookSystem bs;

	for(int i=0; i<3; i++)
	{
        bs.addBook(10, "angsa", "testing");
        bs.addBook(80, "yang", "pofsd");
        bs.addBook(40, "haste", "dfsAF");
	}

    bs.sortTitle();
    bs.sortAuthor();
    bs.sortCode();


}
