/*Se citesc de la tastatură două numere n și m, n>=m. 
Pe urmă se citesc două matrici pătratice de dimensiuni n, respectiv m, conținând numere întregi. 
Afișați toate pozitiile unde a doua matrice apare în prima matrice. 
Afișarea se va face pe ecran sub forma unor perechi de forma (linie, coloană). 
Dacă a doua matrice nu apare în prima matrice, se va afișa textul “Nu apare”. 
Spre exemplu dacă se introduce: 5 3
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1

0 1 1
1 0 1
0 1 1
 se va afișa pe ecran: (0,1) (2,1) */

 #include<stdio.h>


 int main()
 {
    int n,m;
    int a[10][10],b[10][10];
    int gasit=0;
    printf("Se citeste n=:");
    scanf("%d",&n);

    printf("Se citeste m=:");
    scanf("%d",&m);

    //citim prima matrice
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    //citim a doua matrice
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("b[%d][%d]=",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    //cautam matricea daca apare in cealalta matrice
    for(int i=0; i<=n-m; i++){
        for(int j=0; j<=n-m; j++)
        {
            int ok=1;
            for(int x=0; x<m && ok; x++)
            {
                for(int y=0; y<m; y++)
                {
                    if(a[i+x][j+y]!=b[x][y]){
                        ok=0;
                        break;
                    }
                }
            }
            if (ok) {
                printf("(%d,%d) ", i, j);
                gasit=1;
        }
    }
 }
    if(!gasit)
    {
        printf("Nu apare");
    }
    return 0;
}