#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode)
{
    fstream my_file;

    if(mode == mode_append)
    {
        my_file.open(filename,output | write | read);
    }
    else if(mode == mode_output)
    {
        my_file.open(filename,output);
    }
    else if(mode == mode_read)
    {
        my_file.open(filename,read);
    }
    else if(mode == mode_write)
    {
        my_file.open(filename,write);
    }
    else if(mode == mode_trunc)
    {
        my_file.open(filename,trunc);
    }
    my_file.close();
}

int File_opr::write_to_file(Employee* Employee_data,const char* filename)
{
    File_opr write_obj;

    // opening the file
    write_obj.file_open(Employee_data,"database.txt",2);
}


