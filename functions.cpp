#include "functions.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void inputDataBase(struct Soc *A, int k, int numberOfElements)
{
    cin.ignore(1,'\n');
    for(int i=k; i<numberOfElements; i++)
    {
        cout<<"Enter surname: "<<endl;
        cin.getline(A[i].surname, 20,'\n');

        cout<<"Enter nik: "<<endl;
        cin.getline(A[i].nik, 20,'\n');

        cout<<"Enter data: "<<endl;
        cin.getline(A[i].data, 10,'\n');
    }
}

void outputDataBase(struct Soc *A, int numberOfElements)
{
    for(int i=0;i<numberOfElements;++i)
    {
        cout <<A[i].surname<< " ";
        cout <<A[i].nik<< " ";
        cout <<A[i].data<< "\n";
    }
}

void menuSort(struct Soc *A, int numberOfElements)
{
    typedef int (*pointer)(Soc, Soc);
    pointer point[3];
    point[0] = compareBySurname;
    point[1] = compareByNik;
    point[2] = compareByData;

    cout<<"   For sort from A to Z by surname enter 1"<<endl;
    cout<<"   For sort from Z to A by surname enter 2"<<endl;
    cout<<"   For sort from A to Z by nik enter 3"<<endl;
    cout<<"   For sort from Z to A by nik enter 4"<<endl;
    cout<<"   For sort from A to Z by data enter 5"<<endl;
    cout<<"   For sort from Z to A by data enter 6"<<endl;

    int operation;
    cout<<"   Enter the operation: ";
    cin>>operation;

    if(operation==1)
    {
        Sort (A, numberOfElements, point[0], 1);
    }
    if(operation==2)
    {
        Sort (A, numberOfElements, point[0], -1);
    }
    if(operation==3)
    {
        Sort (A, numberOfElements, point[1], 1);
    }
    if(operation==4)
    {
        Sort (A, numberOfElements, point[1], -1);
    }
    if(operation==5)
    {
        Sort (A, numberOfElements, point[2], 1);
    }
    if(operation==6)
    {
        Sort (A, numberOfElements, point[2], -1);
    }
    outputDataBase(A, numberOfElements);
    return;
}

int compareBySurname(struct Soc A1, struct Soc A2)
{
    return strcmp(A1.surname, A2.surname);
}

int compareByNik(struct Soc A1, struct Soc A2)
{
    return strcmp(A1.nik, A2.nik);
}

int compareByData(struct Soc A1, struct Soc A2)
{
    return strcmp(A1.data, A2.data);
}

void Repair(struct Soc *A, int n, int i, int (*fptr)(Soc, Soc), int param) //параметр влияет на то, в какую сторону сортируем
{
    int left=2*i+1;
    int right=2*i+2;
    int larg=i;
    if(left<=n&&(*fptr)(A[left], A[i])==param)
    {
        larg=left;
    }
    if(right<=n&&(*fptr)(A[larg], A[left])==param)
    {
        larg=right;
    }
    if(larg!=i)
    {
        Soc x;
        x=A[i];
        A[i]=A[larg];
        A[larg]=x;
        Repair(A, n, larg, (*fptr),param);
    }
}

void Build(struct Soc *A, int n, int (*fptr)(Soc, Soc), int param)
{
    for(int i=n/2; i>=0; --i)
    {
        Repair(A, n, i, (*fptr),param);
    }
}

void Sort(struct Soc *A, int n, int (*fptr)(Soc, Soc), int param)
{
    int larg;
    Build(A, n, (*fptr),param);
    for (int i=n-1; i>=1; --i)
    {
        Soc x;
        x=A[i];
        A[i]=A[larg];
        A[larg]=x;
        --n;
        Repair(A, n, larg, (*fptr),param);
    }
}

