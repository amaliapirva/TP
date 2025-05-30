/*Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă
dintre ele. Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct.
Să se afișeze perechea de orașe cele mai apropiate între ele în mod direct.*/

#include<stdio.h>

int main()
{
    int n;
    int distanta[10][10];
    int distanta_minima=10000;
    int oras1=-1,oras2=-1;

    printf("Se citeste un numar de orase n<=10");
    scanf("%d",&n);

    if(n>10)
    {
        printf("Numarul citit este mai mare decat 10");
        return 1;
    }

    //citire matrice distante

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("Distanta dintre orasul %d si orasul %d este :",i,j);
            scanf("%d",&distanta[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(distanta[i][j]>0 && distanta[i][j]<distanta_minima)
            {
                distanta_minima=distanta[i][j];
                oras1=i;
                oras2=j;
            }
        }
    }
    if(oras1!=-1)
    {
        printf("Cele mai apopiate drumuri intre  orasul %d si orasul %d este: %d",oras1,oras2,distanta_minima);
    }
    else
    {
        printf("Nu exista drum drept intre niciun oras");
    }

}