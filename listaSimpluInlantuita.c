#include<stdio.h>
#include<stdlib.h>

typedef struct Nod {
    int val;
    struct Nod* next;
}Nod;

void adaugaSfarsit(Nod** cap,int val)
{
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    nou->val=val;
    nou->next=NULL;

    if(*cap==NULL){
        *cap=nou;
    }else{
        Nod* p=*cap;
        while(p->next!=NULL)
            p=p->next;
        p->next=nou;
           
    }
}

void afiseazaLista(Nod* cap){
    printf("Lista: ");
    while(cap!=NULL){
        printf(" %d ",cap->val);
        cap=cap->next;
    }
    printf("\n");
}

int main()
{
    Nod* cap=NULL;
    int n,val;

    printf("Citim cate elemente vrei sa introduci in lista: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Introdu valoarea %d:",i+1);
        scanf("%d",&val);
        adaugaSfarsit(&cap,val);
    }
    afiseazaLista(cap);
}