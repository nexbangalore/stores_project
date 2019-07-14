// to include header only once
#pragma once

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define CHOICE_1 1
#define CHOICE_2 2
#define CHOICE_3 3
#define CHOICE_4 4
#define CHOICE_5 5
#define CHOICE_6 6
#define CHOICE_7 7

#define append  ios::app
#define output  ios::ate  
#define read    ios::in
#define write   ios::out
#define trunc   ios::trunc

#define mode_append 1
#define mode_output 2
#define mode_read   3
#define mode_write  4
#define mode_trunc  5

// basic class for performing employee operations
class Employee
{
    public:
        int id;
        string username;
        string password;
        string department;
        string email;
    
    public:
        void login_existing_user(Employee *);
        void display_employee_details(Employee *);
        void modify_employee_details(Employee *);
        void register_new_user(Employee *);
};

// class for performing file operations
class File_opr:public Employee
{
    public:
        const char* filename;
        int is_found;

    public:
        int file_open(Employee*,const char *,int);
        int read_complete_data();
        int create_linked_list();
        int write_to_file(Employee*,const char*);
};

// function prototypes
int options_display();
void exit();
void read_data_from_user(Employee *);
