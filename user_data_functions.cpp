#include"header.h"

int Emp_cred_ver::user_is_present(Employee* member,Node* node)
{
    Emp_cred_ver object;

    // calling string compare function_strcmp
    int result_of_comp=object.result_of_strcmp(&(((*member).email)[0]),node->email);
    if(result_of_comp == MATCH_FOUND)
    {
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// function_strcmp
int Emp_cred_ver::result_of_strcmp(char *email_from_user,char *email_from_database)
{
    int result;

    result=strcmp(email_from_user,email_from_database);
    if(result==0)
    {
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// function_all_data_parsing
int Emp_cred_ver::parse_data_link_list(Employee* member,Node* head)
{
    Emp_cred_ver object;
    Node* pointer=head;
    int return_result_each_node;
    if(pointer==NULL)
    {
        cout<<"no data";
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
            pointer=pointer->next;
        }
    }
    return MATCH_NOT_FOUND;
}

