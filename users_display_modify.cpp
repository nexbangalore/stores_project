#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

void choice();
void display_user_details();
void modify_user_details();
void exit();

void user_choice(){
	int choice;
	
	std::cout<<"\n Enter your choice";
	std::cout<<"\n 1. Display details";
	std::cout<<"\n 2. Modify details";
	std::cout<<"\n 3. Exit \n";

	std::cin>>choice;

	// Condition to check the choice input
	switch(choice){

		case 1:
		// Fetch the record
		display_user_details();
		break;

		case 2:	
		// Edit the record
		modify_user_details();
		break;

		case 3:
		// Exit the program
		exit(0);
		break;
	
		default:	
		std::cout<<"\n Please enter a correct input \n";
		user_choice();
	}
};

void display_user_details(){
	system("clear");	
	std::cout<<"From display function \n";
	user_choice();

};

void modify_user_details(){
	system("clear");	
	std::cout<<"From modify function \n";	
	user_choice();		
};

void exit(){
	exit();
}

int main(){

	std::cout<<"**************************** Employee Project ****************************";	
	user_choice();
	
	return 0;

}
