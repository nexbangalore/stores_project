#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode,fstream* my_file)
{
    // passing the file opening modes
    if(mode == MODE_APPEND)
    {
        (*my_file).open(filename,OUTPUT | WRITE | READ);
    }
    else if(mode == MODE_OUTPUT)
    {
        (*my_file).open(filename,OUTPUT);
    }
    else if(mode == MODE_READ)
    {
        (*my_file).open(filename,READ);
    }
    else if(mode == MODE_WRITE)
    {
        (*my_file).open(filename,WRITE);
    }
    else if(mode == MODE_TRUNC)
    {
        (*my_file).open(filename,TRUNC);
    }

    return 0;
}

int File_opr::write_to_file(Employee* Employee_data,const char* filename,int mode)
{
    // using fstream for both input and output
    fstream my_file;
    File_opr write_obj;

    // opening the file
    write_obj.file_open(Employee_data,filename,mode,&my_file);

    // writing employee email id as the first parameter
    // enclosing <emailid>
    my_file<<EMAIL_SYM_OPEN;
    my_file<<(*Employee_data).email;
    my_file<<EMAIL_SYM_CLOSE;

    // writing the other parts of data 
    // {data1,data2}
    my_file<<DATA_SYM_OPEN;
    my_file<<(*Employee_data).username;
    my_file<<SEPARATOR;
    my_file<<(*Employee_data).password;
    my_file<<SEPARATOR;
    my_file<<(*Employee_data).email;
    my_file<<SEPARATOR;
    my_file<<(*Employee_data).department;
    my_file<<DATA_SYM_CLOSE<<endl;

    // closing the file
    my_file.close();

    //write_obj.read_complete_data(filename,MODE_READ);

    return 3;
}

int File_opr::read_complete_data(const char *filename,int mode)
{
    fstream my_file;
    File_opr read_obj;
    string line;
    char *token=NULL;
    char delim='>';
    Node* head=NULL;

    read_obj.file_open(NULL,filename,MODE_READ,&my_file);

    if(my_file.is_open())
    {
        while(getline(my_file,line))
        {
            token=strtok(&line[0]+1,&delim);
            cout<<token;
        }
        my_file.close();
    }
    return 1;
}

Node* File_opr::create_node(char* str)
{
    Node* new_node=new Node;
    new_node->email=str;
    new_node->next=NULL;

    return new_node;
}

Node* File_opr::create_list(Node **head,char *str)
{
    File_opr object;
    Node* pointer=(*head);
    Node* new_node=object.create_node(str);
    if((*head)==NULL)
    {
        (*head)=new_node;
    }
    else
    {
        while(pointer->next != NULL)
        {
            pointer=pointer->next;
        }
        pointer=new_node;
    }
}
