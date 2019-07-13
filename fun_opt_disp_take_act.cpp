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
    int choice=0;
    Employee operation;
    system("clear");

    choice=options_display();

    switch(choice)
    {
        case CHOICE_1:
            // register new employee
            operation.register_new_user(&operation);
            break;

        case CHOICE_2:
            // for logging in existing employee
            operation.login_existing_user(&operation);
            break;

        case CHOICE_3:
            // Fetch the record
            operation.display_employee_details(&operation);
            break;

        case CHOICE_4:	
            // Edit the record
            operation.modify_employee_details(&operation);
            break;

        case CHOICE_5:
            // Exit the program
            exit(0);
            break;

        default:
            // if the user enter wrong choice    
            cout<<"\n Please enter a correct input \n";
            //user_choice();
    }
    user_choice();

    return ;
}

void Employee::display_employee_details(Employee* dips_ptr){
    
    system("clear");
    cout<<"welcome to display\n"<<flush;
    
    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*dips_ptr).username;
    
    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*dips_ptr).password;
    
    return;
}

void Employee::modify_employee_details(Employee* modify_ptr){
    
    system("clear");
    cout<<"welcome to modify\n"<<flush;
    
    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*modify_ptr).username;
    
    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*modify_ptr).password;
    
    return;
}

void Employee::login_existing_user(Employee* login_ptr){

    system("clear");
    cout<<"-------welcome to login page-------"<<"\n"<<flush;

    cout<<"-------enter the credentials-------"<<"\n";

    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*login_ptr).username;

    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*login_ptr).password;

    //user_choice();
}

void Employee::register_new_user(Employee* regt_ptr)
{
    system("clear");
    cout<<"-------welcome to registration page------"<<"\n"<<flush;

    cout<<"-------enter the credentials:-------"<<"\n";
    cout<<"\nenter your username:"<<endl;
    cin>>(*regt_ptr).username;

    cout<<"\nenter your password:"<<endl;
    cin>>(*regt_ptr).password;

    //user_choice();
}


