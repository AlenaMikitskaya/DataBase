#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Soc
{
    char surname[20];
    char nik[20];
    char data[10];
};

void inputDataBase(struct Soc *A, int k, int numberOfElements);
void outputDataBase(struct Soc *A, int numberOfElements);

void menuSort(struct Soc *A, int numberOfElements);

int compareBySurname(struct Soc A1, struct Soc A2);
int compareByNik(struct Soc A1, struct Soc A2);
int compareByData(struct Soc A1, struct Soc A2);

void Repair(struct Soc *A, int n, int i, int (*fptr)(Soc, Soc), int param);
void Build(struct Soc *A, int n, int (*fptr)(Soc, Soc), int param);
void Sort(struct Soc *A, int n, int (*fptr)(Soc, Soc), int param);

#endif
