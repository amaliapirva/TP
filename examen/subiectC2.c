/* Se citeste un numar natural n din linia de comanda. Afisati permutarile multimii -n, -n+1, ...-3,-2,-1,0,1,2,3...n
in care elementele pare sunt puncte fixe și doar elementele impare își vor schimba poziția.
Exemplu:
n=5
permutarile care respecta conditia sunt (sunt doar câteva exemple din totalul soluțiilor):
-5 -4 -3 -2 -1 0 1 2 3 4 5
-5 -4 -3 -2 -1 0 1 2 5 4 3
-3 -4 -5 -2 -1 0 3 2 1 4 5
3 -4 -5 -2 -1 0 -3 2 5 4 1
3 -4 1 -2 -1 0 5 2 -5 4 -3
...
(-4, -2, 0, 2 si 4 sunt puncte fixe)*/

#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void afiseaza(int* V,int size){
    for(int i=0; i<size; i++)
    {
        printf("%d",V[i]);
    }
    printf("\n");
}

void permuteImpare(int* imp,int start,int len,int* V,int* idxImpare,int n)
{
    if(start==len)
    {
        int rez[100];
        for(int i=0; i<2*n+1; i++)
        {
            rez[i]=V[i];
        }
        for(int i=0; i<len; i++)
        {
            rez[idxImpare[i]]=imp[i];
        }
        afiseaza(rez,2*n+1);
        return;
    }
    for(int i=start; i<len; i++)
    {
        swap(&imp[start],&imp[i]);
        permuteImpare(imp,start+1,len,V,idxImpare,n);
        swap(&imp[start],&imp[i]);
    }
}

int main(int argc, char* argv[]){
    if(argc!=2)
    {
        printf("eroare la numarul de argumente");
        return 1;
    }
    int n=atoi(argv[1]);
    if(n<0 || n>20){
        printf("n trebuie sa fie intre 0 si 20\n");
        return 1;
    }
    int V[100];
    int imp[100];
    int idxImpare[100];
    int count=0;

    int idx=0;

    for(int i=-n; i<=n; i++)
    {
        V[idx]=i;
        if(i%2!=0){
            imp[count]=i;
            idxImpare[count]=idx;
            count++;
        }
        idx++;
    }
    permuteImpare(imp,0,count,V,idxImpare,n);
    return 0;
}