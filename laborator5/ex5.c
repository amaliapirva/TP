/*Se citesc m și n de la tastatură, iar apoi o matrice a[m][n] cu elemente de tip întreg.
Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele,
așa cum sunt dispuse ele în memorie.
Să se citească matricea din fișier într-o variabilă b și să se afișeze.*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int m,n;
    int matrice[20][30];
    int b[20][30];

    printf("Se citeste m:"); scanf("%d",&m);
    printf("Se citeste n:"); scanf("%d",&n);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("matrice[%d][%d]= ",i,j);
            scanf("%d",&matrice[i][j]);
        }
    }

    FILE *fis=fopen("fisier.bin","wb");
    if(fis==NULL)
    {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }
    
    fwrite(&m,sizeof(int),1,fis);
    fwrite(&n,sizeof(int),1,fis);
    fwrite(matrice,sizeof(int),m*n,fis);
    fclose(fis);

    fis=fopen("fisier.bin","rb");
    if(fis==NULL)
    {
        printf("eroare la deschiderea fisierului pentru citire");
        exit(EXIT_FAILURE);
    }

    fread(&m,sizeof(int),1,fis);
    fread(&n,sizeof(int),1,fis);
    fread(b,sizeof(int),m*n,fis);
    fclose(fis);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d",b[i][j]);
        }  
        printf("\n");      
    }
    return 0;
}