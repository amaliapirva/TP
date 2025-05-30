/*Se citesc de la tastatură m și n, fiecare mai mici decat 10.
 Să se creeze o matrice în care la fiecare
poziție să fie maximul indecșilor acelei poziții și să se afișeze matricea.*/
#include<stdio.h>


int main()
{
    int a[9][9];
    int m,n;
    printf("Se citeste m:\n");
    scanf("%d",&m);
    printf("Se citeste n:\n");
    scanf("%d",&n);

    if(n>=10 || m>=10)
    {
        printf("Nu se respecta conditia ca n si m sa fie mai mici decat 10");
        return 1;
    }
    
    //cream si afisam matricea

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j)
            {
                printf(" a[%d][%d]=%d ",i,j,i);
            }
            else
            {
                printf(" a[%d][%d]=%d ",i,j,j);
            }
        }
        printf("\n");
    }

    return 0;
}