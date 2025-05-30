/*Se cer de la tastatură m și n, fiecare mai mici decat 10. Se cer apoi elementele unei matrici a[m][n]. Să se afișeze dacă matricea a are toate elementele pozitive. */

#include<stdio.h>

int main()
{
    int m,n;
    int a[10][10];
    printf("Se citesc m si n de la tastatura mai mici decat 10:\n");
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    int toate=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]<0)
            {
                toate=0;
                break;
            }
            if(!toate){
                break;
            }
        }
}

    if(toate){
        printf("matricea are toate elementele pozitive");
    }else{
        printf("matricea are si elemente negative");
    }
    return 0;
}