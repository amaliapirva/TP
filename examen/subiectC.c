/*Se genereaza aleator un vector A format din numere naturale, din intervalul 1-100, pe un total de 20 pozitii. Se
genereaza tot aleator un numar natural B, in intervalul 1-2. Să se creeze o listă simplu înlănțuită cu elementele
vectorului. Sa se scrie o functie care parcurge lista, “eliminand” din ea elementele de pe pozitii impare, daca B=1 sau
pare daca B=2. Dupa fiecare parcurgere se afiseaza numarul iteratiei si lista. Se continua pana cand mai este doar un
singur element.
Exemplu: A= 2 5 7 8 9 10 1 3 6 4 (simplificat), B=1
Afiseaza:
Iteratia 1: 5 8 10 3 4
Iteratia 2: 8 3
Iteratia 3: 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nod {
    int val;
    struct Nod* next;
}Nod;

void adaugaSfarsit(Nod** cap, int val){
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    nou->val=val;
    nou->next=NULL;

    if(*cap==NULL){
        *cap=nou;
    }else{
        Nod* p=*cap;
        while(p->next)
            p=p->next;
        p->next=nou;
    }
}

void afiseazaLista(Nod* cap){
    while(cap){
        printf("%d",cap->val);
        cap=cap->next;
    }
    printf("\n");
}

int lungimeLista(Nod* cap){
    int cnt=0;
    while(cap){
        cnt++;
        cap=cap->next;
    }
    return cnt;
}

void eliminaPozitii(Nod** cap,int B)
{
    Nod* curent=*cap;
    Nod* anterior=NULL;
    int poz=1;

    while(curent){
        int elimina=((B==1 && poz%2==1)||(B==2 && poz%2==0));

        if(elimina){
            if(anterior==NULL)
            {
                *cap=curent->next;
                free(curent);
                curent=*cap;
            }else{
                anterior->next=curent->next;
                free(curent);
                curent=anterior->next;
            }
        }else{
            anterior=curent;
            curent=curent->next;
        }
        poz++;
    }
}
int  main()
{
    srand(time(NULL));
    int A[20];
    int B=rand()%2+1;
    printf("Vector A:");
    for(int i=0; i<20; i++)
    {
        A[i]=rand()%100+1;
        printf("%d",A[i]);
    }
    printf("\nB=%d\n\n",B);

    Nod* cap=NULL;
    for(int i=0; i<20; i++)
    {
        adaugaSfarsit(&cap,A[i]);
    }
    int iteratie=1;

    while(lungimeLista(cap)>1){
        printf("Iteratia %d",iteratie++);
        eliminaPozitii(&cap,B);
        afiseazaLista(cap);
    }
    return 0;
}