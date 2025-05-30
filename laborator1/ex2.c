/*: Se citește de la tastatură un număr natural n<=10. Se citesc apoi elementele întregi ale unei matrici a[n][n]. Să se afișeze dacă matricea „a” este o matrice unitate. Notă: o matrice unitate are pe diagonala principală 1 și în rest 0. */

#include<stdio.h>

int main()
{
    int n,esteUnitate=1;
    int a[10][10];
    printf("Se citeste de la tastatura un numar n<=10:");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("a[%d][%d]=:",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0; i<n && esteUnitate; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i==j && a[i][j]!=1) || (i!=j && a[i][j]!=0))
            {
                esteUnitate=0;
                break;
            }
        }
    }
    if(esteUnitate){
        printf("Matricea este o matrice unitate");
    }else
    {
        printf("Matricea nu respecta conditia ca diagonala principala sa fie 1 si in rest 0 si nu este o matrice unitate");
    }

    return 0;
}

