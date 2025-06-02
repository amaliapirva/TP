//Să se scrie un program care creează lista din figura de mai sus și îi afișează conținutul:

#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int n; 
    struct elem *urm; 
 }elem;


elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

elem *adaugaInceput(elem *lista,int n)
{
    return nou(n,lista);
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(!lista)return nou(n,NULL);
    elem *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
    p->urm=nou(n,NULL);
    return lista;
}
void afisare(elem *lista)
{
    for(;lista;lista=lista->urm){
        printf("%d ",lista->n);
    }
    putchar('\n');
}
// elibereaza memoria ocupata de o lista
void eliberare(elem *lista)
{
    elem *p;
    while(lista){
    p=lista->urm;
    free(lista);
    lista=p;
    }
}

int main()
{
    elem *lista1=nou(108,nou(-1,nou(49,NULL)));
    afisare(lista1);
    eliberare(lista1);

    elem *lista2=NULL;
    lista2=adaugaInceput(lista2,49);
    lista2=adaugaInceput(lista2,-1);
    lista2=adaugaInceput(lista2,108);
    afisare(lista2);
    eliberare(lista2);
    
    elem *lista3=NULL;
    lista3=adaugaSfarsit(lista3,108);
    lista3=adaugaSfarsit(lista3,-1);
    lista3=adaugaSfarsit(lista3,49);
    afisare(lista3);
    eliberare(lista3);
    
    return 0;
}
