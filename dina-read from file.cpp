#include <iostream>
#include <fstream>
#include <string>
#define SIZE 100
using namespace std;

void search(string tp[SIZE])
{
	int first, last, mid;
	int i;
	int found;
	string target;
	
	first=0;
	last=SIZE-1;
	found=0;
	
	//Input the target
	cout<<"\nInput the target : ";
	getline(cin, target);
	
	//The binary search
	while((found==0)&&(first<=last))
	{
		mid=(first+last)/2;
		int x=target.compare(tp[mid]);
		if(x==1)
		{
			found=1;
		}	
		else
		{
			if(target<tp[mid])
				last=mid-1;
			else
				first=mid+1;
		}
	}
	
	if(found) //0 – false, 1 - true
		cout<<"\nPosition = "<<mid;
	else
		cout<<"\nTarget not found";
}

int main()
{
	char current;
	int j;
   	fstream newfile;
   	newfile.open("titles_authors.txt",ios::in); //open a file to perform read operation using file object
   	if (newfile.is_open())
	   	{ 	
		   	string tp[SIZE], current;
	      	for (int i=0; i<SIZE; i++)
	      	{
		        getline(newfile, tp[i]);
				cout << tp[i] << "\n"; 
				
				current = tp[i];
				j = i;
				 
				while ((j>0) && (current.at(0)<tp[j-1].at(0)))
				{
					tp[j] = tp[j-1];
			
					j--;
					tp[j] = current;
				}
			}
			
			cout<<"\nAfter sorting : "<<endl;
			for (int i=0; i<SIZE; i++)
			{
			    cout<<tp[i]<<endl;
			}
			
			search(tp);
	      	
      	newfile.close(); //close the file object.
   		}
}
