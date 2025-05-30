/* Se citește de la tastatură o matrice cu n<=20
linii și coloane.
Să se memoreze într-un vector suma tuturor
elementelor de pe fiecare linie și într-un alt vector,
suma tuturor elementelor de pe fiecare coloană.
Să se afișeze cei doi vectori.
Se vor utiliza pointeri atât pentru vectori cât și
pentru matrici*/

#include<stdio.h>

int main()
{
    int n;
    int matrice[20][20];
    int suma_linii[20],coloane_suma[20];
    int *pLinii=suma_linii;
    int *pCol=coloane_suma;

    printf("Introduceti numarul de linii si coloane <=20");
    scanf("%d",&n);

    if(n>20 || n<=0){
        printf("n trebuia sa fie intre 1 si 20");
        return 1;
    }

    //citim matricea
    printf("Introduceti elementele matricei:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("matrice[%d][%d]= ",i,j);
            scanf("%d",&matrice[i][j]);
        }
    }

    //calculul sumelor pe inii si coloane
    for(int i=0; i<n; i++){
        *(pLinii+i)=0;
        *(pCol+i)=0;
        for(int j=0; j<n; j++){
            *(pLinii+i)+=matrice[i][j];//suma linie
            *(pCol+j)+=matrice[i][j];//suma coloana
        }
    }
    //afisare vectori
    printf("Suma pe fiecare linie:\n");
    for(int i=0; i<n; i++)
    {
        printf("Linia %d: %d\n",i,*(pLinii+i));
    }

    printf("Suma pe fiecare coloana:\n");
    for(int i=0; i<n; i++){
        printf("Coloana %d: %d\n",i,*(pCol+i));
    }
}