/*Să se scrie un program care menține o bază de date cu produse, fiecare produs fiind definit prin
nume (max 28 caractere) și preț (float). Programul va implementa într-o buclă infinită următorul meniu:
1-adăugare produs, 2-afișare produse, 3-ieșire. La ieșirea din program, baza de date va fi scrisă automat pe disc*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nume[28];
    float pret;
}Produs;

Produs produse[100];
int nProduse;

void adaugare()
{
    Produs p;
    printf("nume: ");
    fgets(p.nume,28,stdin);
    p.nume[strcspn(p.nume,"\r\n")]='\0';
    printf("pret:");
    scanf("%g",&p.pret);
    produse[nProduse]=p;
    nProduse++;
}

void afisare()
{
    for(int i=0; i<nProduse; i++)
    {
        printf("%s %g\n",produse[i].nume,produse[i].pret);
    }
}

void scriere()
{
    FILE *fis;
    if((fis=fopen("produse.dat","wb"))==NULL)
    {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }
    fwrite(produse,sizeof(Produs),nProduse);
    fclose(fis);

}

int main()
{
    int optiune;
    do{
        switch (optiune)
        {
        case 1: adaugare();
            break;
        case 2:
        afisare();
        break;
        case 3:
        scriere;
        break;
        default:
            printf("Optiune invalida");
        }

    }while(optiune!=3);
    return 0;
}