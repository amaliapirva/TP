/* Se citesc de la tastatură m și n, fiecare mai mici decat 10. 
Să se creeze o matrice în care la fiecare poziție să fie maximul indecșilor acelei poziții și să se afișeze matricea. */

#include<stdio.h>

int main()
{
    int m,n;
    int a[10][10];
    printf("Se citeste n de la tastatura:");
    scanf("%d",&n);
    printf("Se citeste m de la tastatura:");
    scanf("%d",&m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i>j)
            {
                a[i][j]=i;
            }else
            {
                a[i][j]=j;
            }
        }
    }

    //afisare
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}