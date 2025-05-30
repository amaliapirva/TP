/*Se citesc de la tastatură un număr n și o matrice pătratică de dimensiune n conținând litere din alfabet.
 Pe urmă se citește de la tastatură un cuvânt. Verificați dacă respectivul cuvânt se poate construi parcurgând
literele matricii pe verticală în sus sau în jos sau pe orizontală spre stânga sau spre dreapta. 
Afișați toate pozițiile de unde trebuie începută parcurgerea, precum și sensul de parcurgere necesar pentru a construi cuvântul.
Spre exemplu, dacă de la tastatură se introduce:
5

e r e m a
h e r e b
b m e r e
b a m e r
a e m r e

mere

pe ecran se va afișa:
De la linia 0 coloana 3 spre stânga.
De la linia 0 coloana 3 în jos.
De la linia 2 coloana 1 spre dreapta.
De la linia 3 coloana 2 în sus.

Nu are importanță ordinea în care sunt afișate soluțiile găsite. Dacă nu există soluție, se afișează “Nu există soluție”*/

#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    char matrice[20][20];
    char cuvant[10];
    int gasit=0;

    printf("Citim numarul n:\n");
    scanf("%d",&n);

    //citim matricea

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("m[%d][%d]= ",i,j);
            scanf(" %c",&matrice[i][j]);
        }
    }

    printf("Citim un cuvant:\n");
    scanf("%s", cuvant);
    int len=strlen(cuvant);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j+len<=n){
                int ok=1;
                for(int k=0; k<len; k++)
                {
                    if(matrice[i][j+k]!=cuvant[k])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    printf("De la linia %d coloana %d spre dreapta.\n",i,j);
                    gasit=1;
                }
            }
            if(j-len+1>=0)
            {
                int ok=1;
                for(int k=0; k<len; k++)
                {
                    if(matrice[i][j-k]!=cuvant[k])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    printf("De la linia %d coloana %d spre stanga.\n",i,j);
                    gasit=1;
                }
            }
            if(i+len<=n)
            {
                int ok=1;
                for(int k=0; k<len; k++)
                {
                    if(matrice[i+k][j]!=cuvant[k])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    printf("De la linia %d coloana %d in jos.\n",i,j);
                    gasit=1;
                }
            }
            if(i-len+1>=0)
            {
                int ok=1;
                for(int k=0; k<len; k++)
                {
                    if(matrice[i-k][j]!=cuvant[k])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    printf("De la linia %d coloana %d in sus.\n",i,j);
                    gasit=1;
                }
            }
        }
    }
    if(!gasit)
    
        printf("nu exista solutie");
    
    return 0;
}