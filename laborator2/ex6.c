/* Se introduce un număr întreg n<10 și apoi n numere de tip float.
Să se folosească funcția qsort pentru a sorta aceste numere în mod crescător. 
Se va introduce apoi un număr x de tip float.
Folosind funcția bsearch, să se determine dacă x există în vectorul sortat.
Se pot consulta paginile de manual pentru funcțiile qsort și bsearch. */

#include<stdio.h>
#include<stdlib.h>

int compara(const void *a, const void *b)
{
    float fa=*(float *)a;
    float fb=*(float *)b;

    if(fa<fb) return -1;
    else if (fa>fb) return 1;
    else return 0;

}


int main()
{
    int n;
    printf("Citim n<10: ");
    scanf("%d",&n);
    float v[10],x;

    printf("Citim n numere de tip float:");
    for(int i=0; i<n; i++)
    {
        printf("v[%d]=",i);
        scanf("%f",&v[i]);
    }

    qsort(v,n,sizeof(float),compara);

    printf("Vectorul sortat: ");
    for(int i=0; i<n; i++)
    {
        printf(" %f ",v[i]);
    }
    printf("\n");

    printf("Introduceti valoarea cautata x: ");
    scanf("%f",&x);

    float *rezultat=(float *)bsearch(&x,v,n,sizeof(float),compara);

    if(rezultat!=NULL)
    {
        printf("Valoarea %f a fost gasita in vector\n",x);
    }
    else{
        printf("Valoarea %f nu a fost gasita in vctor\n",x);
    }

    return 0;
}