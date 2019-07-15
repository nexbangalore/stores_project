#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode,fstream* my_file)
{
    // passing the file opening modes
    if(mode == mode_append)
    {
        (*my_file).open(filename,output | write | read);
    }
    else if(mode == mode_output)
    {
        (*my_file).open(filename,output);
    }
    else if(mode == mode_read)
    {
        (*my_file).open(filename,read);
    }
    else if(mode == mode_write)
    {
        (*my_file).open(filename,write);
    }
    else if(mode == mode_trunc)
    {
        (*my_file).open(filename,trunc);
    }

    return 0;
}

int File_opr::write_to_file(Employee* Employee_data,const char* filename,int mode)
{
    fstream my_file;
    File_opr write_obj;

    // opening the file
    write_obj.file_open(Employee_data,filename,4,&my_file);

    // writing employee email id as the first parameter
    my_file<<email_sym_l;
    my_file<<(*Employee_data).email;
    my_file<<email_sym_r;

    // writing the other parts of data 
    my_file<<data_sym_l;
    my_file<<(*Employee_data).username;
    my_file<<separator;
    my_file<<(*Employee_data).password;
    my_file<<separator;
    my_file<<(*Employee_data).email;
    my_file<<separator;
    my_file<<(*Employee_data).department;
    my_file<<data_sym_r<<endl;

    my_file.close();

    return 3;
}


