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
    cout<<"--------------Employee Project-----------\n"<<flush;

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
    //user_choice();

    return ;
}

void Employee::display_employee_details(Employee* disp_ptr){
    
    system("clear");
    cout<<"welcome to display\n"<<flush;
    
    read_data_from_user(disp_ptr);
    //user_choice();

    return;
}

void Employee::modify_employee_details(Employee* modify_ptr){
    
    system("clear");
    cout<<"welcome to modify\n"<<flush;
    
    read_data_from_user(modify_ptr);
    //user_choice();
    return;
}

void Employee::login_existing_user(Employee* login_ptr){

    system("clear");
    cout<<"-------welcome to login page-------"<<"\n"<<flush;

    read_data_from_user(login_ptr);
    //user_choice();
}

void Employee::register_new_user(Employee* regt_ptr){

    // object for performing file operations
    File_opr file_op_obj;

    // filename
    file_op_obj.filename="database.txt";

    //system("clear");
    //cout<<"-------welcome to registration page------"<<"\n"<<flush;

    // for reading credentials
    read_data_from_user(regt_ptr);

    // step 1
    file_op_obj.write_to_file(regt_ptr,file_op_obj.filename,MODE_APPEND); 
    //step 2
    file_op_obj.read_complete_data(file_op_obj.filename,MODE_READ);

    return;
}

// generic read user data function
void read_data_from_user(Employee* user_input){

    cout<<"-------enter the credentials-------"<<"\n";

    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*user_input).username;

    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*user_input).password;

    cout<<"\n"<<"enter your email id:"<<endl;
    cin>>(*user_input).email;

    cout<<"\n"<<"enter your department:"<<endl;
    cin>>(*user_input).department;
 
    return;
}
