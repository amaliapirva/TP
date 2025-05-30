/*: Să se scrie într-un fișier valoarea 0x1177AAEE de tip int, așa cum este ea reprezentată în memorie:*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fis;
    int n=0x1177AAEE;
    if((fis=fopen("1.dat","wb"))==NULL)
    {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }
    fwrite(&n,sizeof(int),1,fis);
    fclose(fis);

    return 0;
}