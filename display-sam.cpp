#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	fstream myFile;
	int a,choice,id;
	string aut,myString;
	
	cout<<"=============================================="<<endl;
	cout<<"\t\tWELCOME TO"<<endl;
	cout<<"\tLIBRARY MANAGEMENT SYSTEM"<<endl;
	cout<<"==============================================\n"<<endl;
	
	cout<<"\t*****************************"<<endl;
	cout<<"\t*\t(1) Add Book\t    *"<<endl;
	cout<<"\t*\t(2) Book list\t    *"<<endl;
	cout<<"\t*\t(3) Exit\t    *"<<endl;
	cout<<"\t*****************************\n"<<endl;
	
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	cout<<"   Please enter your choice: ";
	cin>>choice;
	
	do{
	if(choice==1){
	cout<<"\n   How many books do you want to add? ";
	cin>>a;
	
	string book[a];
	myFile.open("test.txt", ios::app);
	cout<<"\n   Please enter the books' details."<<endl;
	for(int i=0;i<a;i++){//user input about book 
		fflush(stdin);
		cout<<"   Book ID: ";
		cin>>id;
		fflush(stdin);
		cout<<"   Book Name: ";
		getline(cin,book[i]);
		cout<<"   Book Author: ";
		getline(cin,aut);
		cout<<endl;
	}
	cout<<"   Book Saved."<<endl;
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	
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
	   ifstream MyReadFile("test.txt");
	   cout<<"\n   *************************************************"<<endl;
	   cout<<"   These are the books in the library: "<<endl;
	   while(getline(MyReadFile, myString))
	   {
	   		cout<<"\t\t"<<myString<<endl;
	   }
	   cout<<"   *************************************************"<<endl;
   }
   cout<<"\n   Please enter your choice: ";
   cin>>choice;
}while(choice!=3);
}
