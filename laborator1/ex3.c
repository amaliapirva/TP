/*Se cer de la tastatură m și n, fiecare mai mici decat 10. 
Să se creeze o matrice în care la fiecare poziție să fie media aritmetică a indecșilor acelei poziții și să se afișeze matricea. */

#include<stdio.h>

int main()
{

    float a[10][10];
    int m,n;

    printf("Se citeste n:");
    scanf("%d",&n);
    printf("Se citeste m:");
    scanf("%d",&m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            a[i][j]=(i+j)/2.0;
        }
    }

    //afisare
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %g ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}