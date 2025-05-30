/*Se defineste o structura Dreptunghi care contine latimea si lungimea unui dreptunghi.
Se cere n<=10 si apoi n dreptunghiuri. Sa se afiseze dimensiunile dreptunghiului de arie maxima*/

#include<stdio.h>

struct Dreptunghi{
    int lungime,latime;
};

int main()
{
    int n;
    struct Dreptunghi v[10];
    printf("Se citeste numarul n<=10: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("latime %d:",i);
        scanf("%d",&v[i].latime);
        printf("lungime %d:",i);
        scanf("%d",&v[i].lungime);

    }
   int imax=0;
    for(int i=1; i<n; i++)
    {
        if(v[imax].latime*v[imax].lungime<v[i].latime*v[i].lungime){
            imax=i;
        }
    }
    printf("dreptunghi de arie maxima: %dx%d\n",v[imax].latime,v[imax].lungime);
    return 0;
}