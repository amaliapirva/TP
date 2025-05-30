/* De exemplu să presupunem că avem maxim m studenți, fiecare cu maxim n note. 
Se cere să se calculeze pentru fiecare student media sa.*/

#include<stdio.h>

int main()
{
    float a[10][10];
    int n,m;
    printf("Se citeste numarul de studenti:");
    scanf("%d",&n);
    printf("Se citeste numarul maxim de note:");
    scanf("%d",&m);

    for(int i=0; i<n; i++)
    {   printf("Notele studentului %d\n",i);
        for(int j=0; j<m; j++)
        {
            printf("nota:");
            scanf("%g",&a[i][j]);
            if(a[i][j]==-1)break;
        }
    }

    for(int i=0; i<n; i++)
    {
        int k=0;
        float suma=0;
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=-1){
                suma+=a[i][j];
                k++;
            }else{
                break;
            }
        }
        if(k==0){
            printf("Studentul %d nu are note\n",i);
        }else{
            printf("Studentul %d are media %f\n",i,suma/k);
        }
    }
    return 0;
}