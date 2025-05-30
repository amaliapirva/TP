/* Se citește de la tastatură un număr n<=10 și un număr m<=20.
 Se cere să se scrie un program care generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. 
 Se vor utiliza pointeri. */
#include <stdio.h>

int main() {
    int m, n;
    int a[20][10];

    printf("Introduceti numarul de linii (m <= 20): ");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane (n <= 10): ");
    scanf("%d", &n);

    int val = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(a + i) + j) = val++;
        }
    }

    printf("Matricea generata este:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", *(*(a + i) + j));
        }
        printf("\n");
    }

    return 0;
}
