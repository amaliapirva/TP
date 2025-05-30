//lista dubla inlantuita
#include<stdio.h>
#include<stdlib.h>

typedef struct Nod{
    int val;
    struct Nod* prev;
    struct Nod* next;
}Nod;

void adaugaSfarsit(Nod** cap,Nod** coada,int val)
{
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    nou->val=val;
    nou->prev=NULL;
    nou->next=NULL;

    if(*cap==NULL)
    {
        *cap=*coada=nou;
    }
    else
    {
        nou->prev=*coada;
        (*coada)->next=nou;
        *coada=nou;
    }
}
void afiseazaDeLaCap(Nod* cap)
{
    while(cap){
        printf("%d",cap->val);
        cap=cap->next;
    }
    printf("\n");
}

void afiseazaDeLaCoada(Nod* coada)
{
    while(coada){
        printf("%d",coada->val);
        coada=coada->prev;
    }
    printf("\n");
}

int main()
{
    Nod* cap=NULL;
    Nod* coada=NULL;
    int n,x;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        adaugaSfarsit(&cap,&coada,x);
    }
    afiseazaDeLaCap(cap);
    afiseazaDeLaCoada(coada);

    return 0;
}