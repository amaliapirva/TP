/*Se citesc dintr-un fisier transmis ca si parametru in linie de comanda, un numar natural n (n<=100000) si apoi n
numere intregi. Numerele se vor salva într-o listă simplu înlănțuită. Să se implementeze o funcție care primește ca
parametru adresa primului element din listă și returnează o nouă listă care conține elemente sumele a câte două
elemente consecutive din prima listă. Aplicați aceasă funcție în mai multe iterații până se ajunge la o listă cu un
singur element. Dupa fiecare parcurgere se afiseaza numarul iteratiei si lista rezultată.
Exemplu: n = 5 lista= (2 5 7 -3 9)
Afiseaza:
Iteratia 1: 7 12 4 6
Iteratia 2: 19 16 10
Iteratia 3: 35 26
Iteratia 4: 61 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Nod{
    int val;
    struct Nod* next;
}Nod;

void adaugaSfarsit(Nod** cap,int val){
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

Nod* sumaPerechi(Nod* cap)
{
    Nod* rezultat=NULL;
    Nod* p=cap;

    while(p!=NULL && p->next!=NULL)
    {
        int suma=p->val+p->next->val;
        adaugaSfarsit(&rezultat,suma);
        p=p->next;
    }
    return rezultat;
}

int main(int argc,char* argv[])
{
    int n;
    Nod* lista=NULL;

    if(argc!=2)
    {
        printf("Eroare la numarul de argumente");
        return 1;
    }

    FILE* f=fopen(argv[1],"r");
    if(!f)
    {
        perror("Eroare la deschiderea fisierului");
        return 1;
    }

    fscanf(f,"%d",&n);
    for(int i=0; i<n; i++)
    {
        int x;
        fscanf(f,"%d",&x);
        adaugaSfarsit(&lista,x);
    }
    afiseazaLista(lista);
    fclose(f);

    int iteratie=1;
    while(lista!=NULL && lista->next!=NULL)
    {
        printf("Iteratie %d:",iteratie++);
        lista=sumaPerechi(lista);
        afiseazaLista(lista);
    }
    return 0;
}


