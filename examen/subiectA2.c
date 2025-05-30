/*Se consideră un triunghi format din n linii, pe fiecare linie i sunt i numere întregi pozitive, ca în exemplul de mai
jos:
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Să se scrie un program care calculează cea mai mare sumă a numerelor aflate pe un drum care leagă vârful de sus al
triunghiului cu baza. Drumul este astfel construit încât la fiecare pas se coboară în jos sau în dreapta. Datele se
citesc dintr-un fișier al cărui nume este dat ca argument în linia de comandă și se pot memora într-o matrice
pătratică.
Exemplu: pentru triunghiul de mai sus, drumul căutat este 7-3-8-7-5. (O variantă de rezolvare este că se pot genera cu
backtraking toate drumurile posibile și se alege în final cel cu suma cea mai mare*/

#include<stdio.h>
#include<stdlib.h>

int n;
int v[100];
int matrice[100][100];
int sumaMaxima=-1;
int caleMaxima[100];

int sumaCurenta(int k)
{
    int suma=0;
    for(int i=0; i<=k; i++)
    {
        suma=suma+matrice[i][v[i]];
    }
    return suma;
}
int valid(int k){

    if(k==0) return 1;
    return (v[k]==v[k-1] || v[k]==v[k-1]+1);
}
int solutie(int k)
{
    return k==n-1;
}

void afisare(int k)
{
    int suma=sumaCurenta(k);
    if(suma>sumaMaxima){
        sumaMaxima=suma;
        for(int i=0; i<=k; i++)
        caleMaxima[i]=v[i];
    }
}

void back(int k)
{   
    for(int i=0; i<k; i++)
    {
        v[k]=i;
        if(valid(k)){
            if(solutie(k))
                afisare(k);
            else
            back(k+1);
        }
    }
    
}

int main(int argc,char* argv[])
{
    
    if(argc!=2)
    {
        printf("Eroare la numarul de argumente");
        return 1;
    }

    FILE* f=fopen(argv[1],"r");
    if(!f)
    {
        printf("Eroare la deschiderea fisierului");
        exit(EXIT_FAILURE);
    }

        fscanf(f,"%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
                fscanf(f,"%d",&matrice[i][j]);
        }
        fclose(f);

        back(0);

    printf("Suma maxima este:%d",sumaMaxima);
    printf("Drumul:");
    for(int i=0; i<n; i++)
    {
        printf("%d",matrice[i][caleMaxima[i]]);
    }        printf("\n");

}