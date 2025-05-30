/*Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. 
Fiecare rezultat este definit prin (nume,nota). 
Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari fiind primele.
Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nume[50];
    float nota;
}Student;

int compara(const void *a, const void *b)
{
    Student *s1=(Student *)a;
    Student *s2=(Student *)b;

    if(s1->nota <s2->nota)
        return 1;
    else if(s1->nota > s2->nota)
        return -1;
    else
        return strcmp(s1->nume,s2->nume); //sortare alfabetica daca notele sunt egale
    
}
int main()
{
    int n;
    Student v[100];
    printf("Se citeste n:");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Studentul %d:\n",i+1);
        printf(" Nume: ");
        scanf("%s",v[i].nume);
        printf(" Nota: ");
        scanf("%f",&v[i].nota);
    }

    qsort(v,n,sizeof(Student),compara);

    printf("\nStudentii sortati dupa nota (descrescator), apoi dupa nume:\n");
    for(int i=0; i<n; i++)
    {
        printf("%s - %.2f\n",v[i].nume, v[i].nota);
    }

    return 0;
}