//<<<<<<< HEAD
#pragma once

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define IT_FILE "/home/rachita/Documents/project_documents/it_details.txt"
#define FINANCE_FILE "/home/rachita/Documents/project_documents/finance_details.txt"

#define CHOICE_1 1
#define CHOICE_2 2
#define CHOICE_3 3
#define CHOICE_4 4
#define CHOICE_5 5
#define CHOICE_6 6
#define CHOICE_7 7

class emp_id
{
    public:
        int id;
};

class emp_username
{
    public:
        string username;
};

class emp_password
{
    public:
        string password;
};

class emp_department
{
    public:
        string department;
};

class login:public emp_username,public emp_password,public emp_department
{
    public:
};

class regstr:public emp_username,public emp_password,public emp_department
{
    public:
};

int options_display();
void exit();
void display_employee_details();
void modify_employee_details();
void register_new_user();
void login_existing_user();
