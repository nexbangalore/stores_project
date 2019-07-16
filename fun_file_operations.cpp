#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode,fstream* my_file)
{
    // passing the file opening modes
    if(mode == MODE_APPEND)
    {
        (*my_file).open(filename,OUTPUT | APPEND | READ);
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

    write_obj.read_complete_data(filename,MODE_READ);

    return 3;
}

int File_opr::read_complete_data(const char *filename,int MODE)
{
    fstream my_file;
    File_opr read_obj;
    string line;
    char *token=NULL;
    char delim='>';
    Node* head;
    head=NULL;

    read_obj.file_open(NULL,filename,MODE,&my_file);

    system("clear");

    if(my_file.is_open())
    {
        while(!(my_file.eof()))
        {
            while(getline(my_file,line))
            {
                token=strtok(&line[0],&delim);
                //cout<<token;
                read_obj.create_list(&head,token);
            }
        }
    }
    my_file.close();
    //read_obj.display_data_linked_list(&head);
    return 1;
}

Node* File_opr::create_node(char* str)
{
    Node* new_node;
    new_node=new Node;
    
    new_node->email=str;

    new_node->next=NULL;

    return new_node;
}

Node* File_opr::create_list(Node **head,char *str)
{
    File_opr object;

    // initialising the pointer with head address value
    Node* pointer=(*head);

    // storing the address of new node
    Node* new_node=object.create_node(str);

    if((*head)==NULL)
    {
        // if there is only a base node
        (*head)=new_node;
        cout<<(*head)->email<<endl;
    }
    else
    {
        pointer=(*head);
        while(pointer->next != NULL)
        {
            // if the pointer has reached its end
            pointer=pointer->next;
        }
        // attaching the new node at the last
        pointer->next=new_node;
        cout<<pointer->next->email<<endl;
        object.display_data_linked_list(head);
    }

    return (*head);
}

void File_opr::display_data_linked_list(Node** head)
{
    int counter=0;
    cout<<"displaying the data in linked list\n";
    Node* pointer=*head;
    while(pointer != NULL)
    {
        ++counter;
        cout<<pointer->email<<flush;
        pointer=pointer->next;
    }
}
