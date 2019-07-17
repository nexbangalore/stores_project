#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode,fstream* my_file)
{
    // passing the file opening modes
    if(mode == MODE_APPEND)            // if(1 == 1)
    {
        (*my_file).open(filename,OUTPUT | APPEND | READ);
    }
    else if(mode == MODE_OUTPUT)       // if(2 == 2)
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

int File_opr::write_to_file(Employee* Employee_data,const char* filename,int MODE)
{
    // using fstream for both input and output
    fstream my_file;
    File_opr write;

    //user defined opening the file
    write.file_open(Employee_data,filename,MODE,&my_file);

    if(my_file.is_open())
    {
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
    }
    else
    {
        cout<<"file opening failed\n";
    }

    // closing the file
    my_file.close();

    return 3;
}

int File_opr::read_complete_data(const char *filename,int MODE)
{
    fstream my_file;
    
    File_opr read;
    linked_list link_obj;
    string line;

    char* token=NULL;
    char delim='>';
    
    Node* head=NULL;

    // user defined
    read.file_open(NULL,filename,MODE,&my_file);
                                                           
    //system("clear");

    // system defined
    if(my_file.is_open())
    {
        while(!(my_file.eof()))
        {
            while(getline(my_file,line))
            {
                token=strtok(&line[0]+1,&delim);
                link_obj.create_list(&head,token);
            }
        }
    }
    my_file.close();
    link_obj.display_data_linked_list(&head);
    
    return 1;
}

Node* linked_list::create_list(Node **head,char *str)
{
    // initialising the pointer with head address value
    Node* pointer=(*head);

    // storing the address of new node
    Node* new_node=new (Node);
    new_node->email=str;
   // cout<<new_node->email<<endl;
    new_node->next=NULL;

    if((*head)==NULL)
    {
        // if there is only a base node
        (*head)=new_node;
    }
    else
    {
        pointer=(*head);
        while(pointer->next != NULL)
        {
            // if the pointer has reached its end
            pointer=pointer->next;
        }
        pointer->next=new_node;
    }

    return (*head);
}

void linked_list::display_data_linked_list(Node** head)
{
    cout<<"printing the list"<<endl;
    Node* pointer=(*head);
    while(pointer != NULL)
    {
        std::cout<<pointer->email<<endl;
        pointer=pointer->next;
    }
}
