// to include header only once
#pragma once

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstring>

using namespace std;

#define EMAIL_SYM_OPEN  '<'
#define EMAIL_SYM_CLOSE '>'
#define DATA_SYM_OPEN   '{'
#define DATA_SYM_CLOSE  '}'
#define SEPARATOR       ','

#define CHOICE_1 1
#define CHOICE_2 2
#define CHOICE_3 3
#define CHOICE_4 4
#define CHOICE_5 5
#define CHOICE_6 6
#define CHOICE_7 7

#define APPEND  std::fstream::app
#define OUTPUT  std::fstream::ate  
#define READ    std::fstream::in
#define WRITE   std::fstream::out
#define TRUNC   std::fstream::trunc

#define MODE_APPEND 1
#define MODE_OUTPUT 2
#define MODE_READ   3
#define MODE_WRITE  4
#define MODE_TRUNC  5

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

class Node
{
    public:
       char* email;
       Node* next;
};

// class for performing file operations
// file_opr is inheriting class Employee
class File_opr:public Employee 
{
    public:
        const char* filename;
        int is_found;

    public:
        int file_open(Employee*,const char *,int,fstream*);
        int read_complete_data(const char*,int);
        int create_linked_list();
        int write_to_file(Employee*,const char*,int);
        Node* create_node(char*);
        Node* create_list(Node **,char *);
        void display_data_linked_list(Node **);
};

// function prototypes
int options_display();
void exit();
void read_data_from_user(Employee *);
