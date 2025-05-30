/*Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
caractere), nota.
Să se citească un element din structură și să se afișeze pe ecran.*/
#include<stdio.h>

typedef struct{
    char nume[20];
    int nota;
}Student;


int main()
{
    Student s1;
    printf("Numele studentului: ");
    scanf("%s",s1.nume);
    printf("Nota studentului:");
    scanf("%d",&s1.nota);

    printf("Nume: %s",s1.nume);
    printf("Nota: %d",s1.nota);
}