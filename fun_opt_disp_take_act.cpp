#include<iostream>
#include<string.h>
#include"header.h"
#include<stdlib.h>
using namespace std;

int options_display()
{   
    int option; 
    cout<<"welcome"<<"\n"; 
    cout<<"choose your option"<<"\n";
    cout<<"1.register"<<"\n"<<"2.login"<<"\n"<<"3.confirm"<<"\n";
    cin>>option;

    return option;
}

void user_choice()
{
    system("clear");
    int choice=options_display();
    switch(choice)
    {
        case choice_1:
            register_new_user();
            break;
        case choice_2:
            login_existing_user();
            break;
        case choice_3:
            user_choice();
            break;
        default:
            cout<<"wrong choice"<<endl;
    }
}

void login_existing_user()
{
    login login_object;
    system("clear");
    cout<<"welcome to login page"<<"\n";

    cout<<"enter the credentials:"<<"\n";

    cout<<"enter your username:"<<endl;
    cin>>login_object.username;

    cout<<"enter your password:"<<endl;
    cin>>login_object.password;

    user_choice();
}

void register_new_user()
{
    regstr regt_object;
    system("clear");

    cout<<"welcome to registration page"<<"\n";
    
    cout<<"enter the credentials:"<<"\n";
    cout<<"enter your username:"<<endl;
    cin>>regt_object.username;

    cout<<"enter your password:"<<endl;
    cin>>regt_object.password;

    user_choice();
}
