#include<iostream>
#include"header.h"
using namespace std;

int main()
{
    int choice;
    while(1)
    {
        choice=options_display();

        switch(choice)
        {
            case 1:
                register_new_user();
                break;
            case 2:
                login_existing_user();
                break;
        }
    }
}
