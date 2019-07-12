#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#include <string.h>

void choice();
void display_user_details();
void modify_user_details();

std::ifstream ifs;

void user_choice(){
	
	int CHOICE;
	
	std::cout<<"\n Enter your choice";
	std::cout<<"\n 1. Display details";
	std::cout<<"\n 2. Modify details";
	std::cout<<"\n 3. Exit \n";

	std::cin>>CHOICE;

	// Condition to check the choice input
	switch(CHOICE){

		case CHOICE_1:
		// Fetch the record
		display_user_details();
		break;

		case CHOICE_2:	
		// Edit the record
		modify_user_details();
		break;

		case CHOICE_3:
		// Exit the program
		system("clear");
		exit(0);
		break;
	
		default:	
		std::cout<<"\n Please enter a correct input \n";
		user_choice();
	}
};

int read_file(){	
	std::cout<<"\n File read function: \n";	

	ifs.open ("it_details.txt", std::ifstream::in);

  	char details = ifs.get();

  	while (ifs.good()) {
    		std::cout << details;
    		details = ifs.get();
  	}

  	ifs.close();

	return 0;
};

void display_user_details(){

	std::string name, department;

	system("clear");	
	std::cout<<"From display function \n";
	
	std::cout<<"\n Enter the name of employee:"; 	
	std::cin>>name;	
	std::cout<<"\n Enter the department of employee:"; 
	std::cin>>department;	

	if(department == "IT"){
		read_file();
	}
	user_choice();
};

void modify_user_details(){
	system("clear");	
	std::cout<<"From modify function \n";	
	user_choice();		
};

int main(){

	std::cout<<"**************************** Employee Project ****************************";	
	user_choice();
	
	return 0;

}
