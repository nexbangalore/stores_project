#include"header.h"

int options_display()
{   
    int option; 
    cout<<"\n Enter your choice";
	cout<<"\n 1. Register";
	cout<<"\n 2. login";
	cout<<"\n 3. Display details";
	cout<<"\n 4. Modify details";
	cout<<"\n 5. Exit \n";
    cin>>option;

    return option;
}

void user_choice()
{
    system("clear");
    int CHOICE=options_display();
    cout<<CHOICE;

    switch(CHOICE)
    {
        case CHOICE_1:
            // register new employee
            register_new_user();
            break;

        case CHOICE_2:
            // for logging in existing employee
            login_existing_user();
            break;

        case CHOICE_3:
            // Fetch the record
            display_employee_details();
            break;

        case CHOICE_4:	
            // Edit the record
            modify_employee_details();
            break;

        case CHOICE_5:
            // Exit the program
            exit(0);
            break;

        default:
            // if the user enter wrong choice    
            cout<<"\n Please enter a correct input \n";
            user_choice();
    }
}

void login_existing_user(){

    login login_object;
    
    system("clear");
    cout<<"-------welcome to login page-------"<<"\n";

    cout<<"-------enter the credentials-------"<<"\n";

    cout<<"\n"<<"enter your username:"<<endl;
    cin>>login_object.username;

    cout<<"\n"<<"enter your password:"<<endl;
    cin>>login_object.password;

    user_choice();
}

void register_new_user()
{
    regstr regt_object;
    
    system("clear");
    cout<<"-------welcome to registration page------"<<"\n";

    cout<<"-------enter the credentials:-------"<<"\n";
    cout<<"\nenter your username:"<<endl;
    cin>>regt_object.username;

    cout<<"\nenter your password:"<<endl;
    cin>>regt_object.password;

    user_choice();
}

void display_employee_details(){

    system("clear");	
    
    cout<<"From display function \n";
    
    user_choice();
};

void modify_employee_details(){
    
    system("clear");	

    cout<<"From modify function \n";	
    
    user_choice();		
};

