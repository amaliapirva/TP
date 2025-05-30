/*Se consideră o structură Produs care conține un câmp nume și altul pret.
Să se scrie o funcție care primește ca parametru un produs și un procent reprezentând o reducere de preț.
Funcția va modifica prețul produsului conform cu reducerea dată. 
În programul principal se vor introduce un număr n de produse, cu n citit de la tastatură.
Folosind funcția definită anterior, să se modifice prețurile produselor și să se afișeze.*/

#include<stdio.h>
#include<string.h>
typedef struct{
    char nume[100];
    float pret;
}Produs;

void reduce(Produs *p,float reducere)// transmite prin adresa a structurii, ca sa se poata modifica pretul
{
    p->pret*=1-reducere/100;
}

int main()
{
    int n,i;
    float r;
    Produs produse[50];
    printf("Reducere:");
    scanf("%f",&r);
    printf("n:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        getchar();
        printf("nume %d",i);
        fgets(produse[i].nume,100,stdin);
        produse[i].nume[strcspn(produse[i].nume,"\n")]='\0';
        printf("pret %d:",i);
        scanf("%g",&produse[i].pret);
    }
    for(i=0; i<n; i++)
    {
        reduce(&produse[i],r);
    }
    for(i=0; i<n; i++)
    {
        printf("%s %g\n",produse[i].nume,produse[i].pret);
    }
}
