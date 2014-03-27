#include <iostream>
#include <fstream>
#include "functions.h"
#include <conio.h>
#include <windows.h>

using namespace std;

void menu(struct Soc *A, int n)
{
    int operation;
    int numberOfElements;
    while (true)
    {
        cout<<endl<<"Enter the operation: ";
        cin>>operation;
        if(operation==1)
        {
            cout<<"Enter the number of added elements (<20): "<<endl;
            cin>>numberOfElements;
            inputDataBase(A, 0, numberOfElements);
        }

        if(operation==2)
        {
            fstream mystream1;
            mystream1.open("numberOfElements.txt", ios::out|ios::binary|ios::trunc);
            mystream1.write((char *)&numberOfElements, sizeof(int))<<endl;
            mystream1.close();

            fstream mystream2;
            mystream2.open("DataBase.txt",ios::out|ios::binary|ios::trunc);
            mystream2.write((char *)A,numberOfElements*sizeof(Soc)) << "\n";
            mystream2.close();
        }

        if(operation==3)
        {
            outputDataBase(A,numberOfElements);
        }

        if(operation==4)
        {
            fstream mystream3;
            mystream3.open("numberOfElements.txt",ios::in|ios::binary);
            mystream3.read((char *)&numberOfElements,sizeof(int));
            mystream3.close();

            fstream mystream4("DataBase.txt",ios::in|ios::binary);
            mystream4.read((char *)A,numberOfElements*sizeof(Soc));
            mystream4.close();
            outputDataBase(A,numberOfElements);
        }

        if(operation==5)
        {
            int add;
            cout<<"Enter the number of added elements (<20): "<<endl;
            cin>>add;
            inputDataBase(A,numberOfElements,numberOfElements+add);
            numberOfElements+=add;

            fstream mystream5;
            mystream5.open("numberOfElements.txt",ios::out|ios::binary|ios::trunc);
            mystream5.write((char *)&numberOfElements, sizeof(int)) <<endl;
            mystream5.close();
        }

        if(operation==6)
        {
            menuSort(A, numberOfElements);
        }
        if(operation==0)
        {
            exit(0);
        }
    }
}

int main()
{
    cout<<"For create new database enter 1"<<endl;
    cout<<"For save the database enter 2"<<endl;
    cout<<"For output the database enter 3"<<endl;
    cout<<"For open and output the existing database enter 4"<<endl;
    cout<<"For add new element to existing database enter 5"<<endl;
    cout<<"For sorting the existing database enter 6"<<endl;
    cout<<"For exit enter 0"<<endl;

    const int n=20;
    Soc *A=new Soc[n];
    menu(A, n);
    delete []A;
    return 0;
}
