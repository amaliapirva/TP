/*Sa se scrie o functie care primeste o lista de numere intregi si un numar n si returneaza un pointer catre o noua lista
care contine toate elementele listei initiale mai putin elementele de pe pozitii multiplu de n
input: lista initiala: 1 2 3 4 5 6 7 8 9 10, n=3
output: lista finala: 1 2 4 5 7 8 10*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Nod{
    int val;
    struct Nod* next;
}Nod;

void adaugaSfarsit(Nod** cap,int val)
{
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    nou->val=val;
    nou->next=NULL;

    if(*cap==NULL)
    {
        *cap=nou;
    }else{
        Nod* p=*cap;
        while(p->next!=NULL)
            p=p->next;
        p->next=nou;
    }
}

void afiseazaLista(Nod* cap)
{
    Nod* p=cap;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

Nod* multiplu(Nod* cap,int n)
{
    Nod* noualista=NULL;
    Nod* p=cap;
    int poz=1;
    while(p!=NULL)
    {
        if(poz%n!=0)
        {
            adaugaSfarsit(&noualista,p->val);
        }
        p=p->next;
        poz++;
    }
    return noualista;
}

int main()
{
    int x;
    Nod* lista=NULL;

    printf("x=");
    scanf("%d",&x);
    for(int i=0; i<x; i++)
    {
        int valoare;
        scanf("%d",&valoare);
        adaugaSfarsit(&lista,valoare);
    }
    printf("lista initiala: ");
    afiseazaLista(lista);

    Nod* listaNoua=multiplu(lista,3);
    afiseazaLista(listaNoua);
}