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

    return 3;
}


