/* Să se implementeze o funcție care primește ca parametri un vector de întregi,
 numărul elementelor din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție.
Funcția va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu numărul de elemente rămas în vector.
Să se testeze funcția cu un predicat care testează dacă un număr este negativ și să se afișeze vectorul rezultat. */

#include<stdio.h>
#include<stdlib.h>

int negativ(int numar)
{
   return numar < 0;
}

void testare(int *v,int *n,int (*cond)(int))
{
    int i,j=0;
    for(i=0; i< *n; i++)
    {
        if(cond(v[i]))
        {
            v[j++]=v[i];//pastreaza doar valorile care respecta conditia
        }
    }
    *n=j;
}

int main()
{
    int v[100], n;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    printf("Introduceti %d numere intregi:\n", n);
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    
    testare(v,&n,negativ);

    printf("Vectorul testat:");
    for(int i=0; i<n; i++)
    {
        printf(" %d ",v[i]);
    }

    return 0;
}