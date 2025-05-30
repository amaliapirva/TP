/*Sa se implementeze o functie în C care primeste un numar natural n, construieste si afiseaza o listă dublu
înlănțuită formată din primele 2
𝑛 numere naturale, dispuse astfel:
• se pleacă de la lista 1 2
• exact la mijlocul acestei liste se inserează elementele 3 4 și se obține 1 3 4 2
• exact la mijlocul acestei liste se inserează elementele 5 6 7 8 și se obține 1 3 5 6 7 8 4 2
• etc.
• în general, la mijlocul șirului format din primele 2
𝑘 numere naturale se inserează șirul ordonat format din
următoarele 2
𝑘 numere naturale.
Se va implemente o functie main() adecvata si orice alte functii necesare. Să se afișeze toate listele intermediare obținute.*/


#include<stdio.h>
#include<stdlib.h>

//structura nodului dublu inlantuit
typedef struct Nod{
    int val;
    struct Nod* prev;
    struct Nod* next;
}Nod;

Nod* creeazaNod(int val)
{
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    nou->val=val;
    nou->prev=NULL;
    nou->next=NULL;
    return nou;
}

void afiseazaLista(Nod* cap){
    Nod* p=cap;
    while(p)
    {
        printf("%d",p->val);
        p=p->next;
    }
    printf("\n");
}

Nod* gasesteMijloc(Nod* cap)
{
    Nod* slow=cap;
    Nod* fast=cap;
    while(fast && fast->next){
        fast=fast->next->next;
        if(fast)
        slow=slow->next;
    }
    return slow;
}

void insereazaLaMijloc(Nod** cap, Nod* startNou,Nod* endNou){
    Nod* mijloc=gasesteMijloc(*cap);

    if(mijloc->prev){
        mijloc->prev->next=starNou;
        startNou->prev=mijloc->prev;
    }else{
        *cap=startNou;
    }

    endNou->next=mijloc;
    mijloc->prev=endNou;
}

void creeazaSublista(int start,int end,Nod** prim,Nod** ultim){
    *prim=NULL;
    *ultim=NULL;
    for(int i=start; i<=end; i++)
    {
        Nod* nod=creeazaNod(i);
        if(*prim==NULL){
            *prim=*ultim=nod;
        }else{
            (*ultim)->next=nod;
            nod->prev=*ultim;
            *ultim=nod;
        }
    }
}

int main()
{
    int n;
    printf("Introduceti valoarea n:");
    scanf("%d",&n);

    if(n<=0){
        printf("n trebuie sa fie pozitiv");
        return 1;
    }

    Nod* cap=creeazaNod(1);
    cap->next=creeazaNod(2);
    cap->next->prev=cap;
    printf("Iteratia 1:");
    afiseazaLista(cap);

    int curent=3;
    int pas=2;
    int iter=2;

    while(curent<=2*n)
    {
        Nod *primNou=NULL,*ultimNou=NULL;
        int final=curent+pas-1;

        if(final>2*n);
            final=2*n;
        
        creeazaSublista(curent,final,&primNou,&ultimNou);
        insereazaLaMijloc(&cap,primNou,ultimNou);

        printf("Iteratia %d:",iter++);
        afiseazaLista(cap);

        curent=final+1;
        pas*=2;
    }
    return 0;
}