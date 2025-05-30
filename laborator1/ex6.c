/*Se citesc m și n. Folosind doar cantitatea necesară de memorie, se citesc elementele unei matrici a[m][n]. 
Se cere să se afișeze maximul fiecărei coloane. */

#include<stdio.h>
#include <stdlib.h> 
 
int main() 
{    
     int m,n,i,j;    
      int **a;
                                                  // matricea este implementata ca un vector de pointeri la liniile ei  
    printf("m=");scanf("%d",&m);
    printf("n=");scanf("%d",&n);     
    // alocare vector de pointeri la linii
    if((a=(int**)malloc(m*sizeof(int*)))==NULL)
    {    printf("memorie insuficienta\n");
         exit(EXIT_FAILURE);} 
             // alocare linii
    for(i=0;i<m;i++){
        if((a[i]=(int*)malloc(n*sizeof(int)))==NULL){
            for(i--;i>=0;i--)free(a[i]);
                                         // elibereaza liniile alocate anterior          
            free(a);  
                                                     // elibereaza vectorul de pointeri 
            printf("memorie insuficienta\n"); 
            exit(EXIT_FAILURE);             }         }  
    for(i=0;i<m;i++){         
        for(j=0;j<n;j++){             
            printf("a[%d][%d]=",i,j);scanf("%d",&a[i][j]);
                     }      
                       }   
                         // cauta maximul fiecarei coloane     // parcurgea se face in ordinea coloanelor  
    for(j=0;j<n;j++){
        int max=a[0][j];
                 // parcurge fiecare element din coloana j, incepand cu a doua linie     
    for(i=1;i<m;i++){    
        int k=a[i][j];     
        if(k>max)max=k; 
    }
    printf("Maximul coloanei %d este %d\n",j,max);
}
    for(i=0; i<m; i++)free(a[i]);
    free(a);
    return 0;
}