/*Să se scrie un program care primește 2 fișiere în linia de comandă și le compară între ele. 
Pentru fiecare octet diferit găsit, se afișează offsetul acestuia și valorile sale din fiecare fișier, în hexazecimal, pe câte 2 cifre.
Dacă fișierele sunt de dimensiuni diferite, în final se vor afișa toți octeții din fișierul mai mare. 
Dacă fișierele sunt identice, programul nu va afișa nimic.*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Utilizare: %s fisier 1 fisier2\n",argv[0]);
        return 1;
    }
    FILE *f1=fopen(argv[1],"rb");
    FILE *f2=fopen(argv[2],"rb");

    if(!f1 || !f2){
        perror("Eroare la deschidere fisierelor");
        return 2;
    }
    int b1,b2;
    long offset=0;
    int diferit=0;

    while(1)
    {
        b1=fgetc(f1);
        b2=fgetc(f2);

        if(b1==EOF && b2==EOF)
            break;
        
        if(b1!=b2){
            printf("Offset %06lx: %02x %02x\n",offset,b1==EOF ? 0:b1, b2==EOF ? 0:b2);
            diferit=1;
        }
        offset++;
    }
    fclose(f1);
    fclose(f2);
}