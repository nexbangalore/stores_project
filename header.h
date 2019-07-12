#pragma once

using namespace std;

#define choice_1 1
#define choice_2 2
#define choice_3 3

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
    
};

class regstr:public emp_username,public emp_password,public emp_department
{
    
};

   
void login_existing_user();
void register_new_user();
int options_display();
