#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	fstream myFile;
	int a,choice,id;
	string aut;
	
	cout<<"1 Add Book"<<endl;
	cout<<"2 Book list"<<endl;
	cout<<"3 Exit"<<endl;
	cout<<"Enter u Choice: ";
	cin>>choice;
	
	do{
	if(choice==1){
	cout<<"Enter How many book to Enter:";
	cin>>a;
	
	string book[a];
	myFile.open("test.txt", ios::app);
	for(int i=0;i<a;i++){//user input about book 
		fflush(stdin);
		cout<<"Book ID:";
		cin>>id;
		fflush(stdin);
		cout<<"Book Name:";
		getline(cin,book[i]);
		cout<<"Book Author:";
		getline(cin,aut);
		cout<<endl;
	}
	cout<<"\nBook Saved"<<endl;
	
	if(myFile.is_open()){//storing book in text file
	for(int i=0;i<a;i++){
		myFile<<id<<" ";
		myFile<<book[i]<<" ";
		myFile<<aut<<endl;
    }
    myFile.close();
	}
	
   }else if(choice==2){
	   //print from text file
   }
   cout<<"Enter u Choice: ";
   cin>>choice;
}while(choice!=3);
}
