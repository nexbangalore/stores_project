#include"header.h"

int Emp_cred_ver::user_is_present(Employee* member,Node* node)
{
    Emp_cred_ver object;
    int result_cmp_email,result_cmp_usrname,result_cmp_pswd;

    // calling string compare function_strcmp
    result_cmp_email=object.result_of_strcmp(&(((*member).email)[0]),&((node->email)[0]));
    result_cmp_usrname=object.result_of_strcmp(&(((*member).username)[0]),&((node->username)[0]));
    result_cmp_pswd=object.result_of_strcmp(&(((*member).password)[0]),&((node->password)[0]));

    if((result_cmp_email== MATCH_FOUND) && (result_cmp_usrname==MATCH_FOUND) && (result_cmp_pswd==MATCH_FOUND))
    {
        // to parse_data_link_list()
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// function_strcmp
int Emp_cred_ver::result_of_strcmp(char *member_from_user,char *member_from_database)
{
    int result;

    result=strcmp(member_from_user,member_from_database);
    if(result==0)
    {
        // to user_is_present function
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// head has to be passed from main_opt function
// function_all_data_parsing
int Emp_cred_ver::parse_data_link_list(Employee* member,Node* head)
{
    Emp_cred_ver object;
    Node* pointer=head;
    int return_result_each_node;
    if(pointer==NULL)
    {
        cout<<"no data"<<endl;
    }
    else
    {
        pointer=head;

        while(pointer != NULL)
        {
            return_result_each_node=object.user_is_present(member,pointer);
            if(return_result_each_node == MATCH_FOUND)
            {
                return MATCH_FOUND;
                break;
            }
            else
            {
                pointer=pointer->next;
            }
        }
    }

    // to fun_opt_function.cpp function()
    return MATCH_NOT_FOUND;
}




