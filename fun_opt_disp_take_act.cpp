#include<iostream>
#include"header.h"
#include<stdlib.h>
using namespace std;

int options_display()
{   
    int option; 
    cout<<"welcome"<<"\n"; 
    cout<<"choose your option"<<"\n";
    cout<<"1.register"<<"\n"<<"2.login"<<"\n";
    cin>>option;

    return option;
}

void login_existing_user()
{
    system("CLS");
    cout<<"welcome to login page"<<"\n";
}

void register_new_user()
{
    system("CLS");
    cout<<"welcome to registration page"<<"\n";
}
