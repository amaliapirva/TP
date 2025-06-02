/*Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate.
Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int n;
    struct elem *urm;
} elem;


elem* nou(int n, elem* urm) {
    elem *e = (elem *)malloc(sizeof(elem));
    if (!e) {
        printf("Memorie insuficienta!\n");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

elem* adaugaSfarsit(elem *lista, int n) {
    if (!lista) return nou(n, NULL);
    elem *p = lista;
    while (p->urm) {
        p = p->urm;
    }
    p->urm = nou(n, NULL);
    return lista;
}

void afisare(elem *lista) {
    if (!lista) {
        printf("Lista este goală.\n");
        return;
    }
    for (; lista; lista = lista->urm) {
        printf("%d ", lista->n);
    }
    printf("\n");
}

elem* inverseaza(elem *lista) {
    elem *anterior = NULL, *curent = lista, *urmator = NULL;
    while (curent != NULL) {
        urmator = curent->urm;
        curent->urm = anterior;
        anterior = curent;
        curent = urmator;
    }
    return anterior;
}

void eliberare(elem *lista) {
    while (lista) {
        elem *temp = lista;
        lista = lista->urm;
        free(temp);
    }
}


int main() {
    elem *lista = NULL;
    int optiune, valoare;

    do {
        printf("\n--- Meniu ---\n");
        printf("1. Adaugă element la sfârșit\n");
        printf("2. Afișează lista\n");
        printf("3. Inversează lista\n");
        printf("0. Ieșire\n");
        printf("Alege opțiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Valoare de adăugat: ");
                scanf("%d", &valoare);
                lista = adaugaSfarsit(lista, valoare);
                break;
            case 2:
                printf("Lista curentă: ");
                afisare(lista);
                break;
            case 3:
                lista = inverseaza(lista);
                printf("Lista a fost inversată.\n");
                break;
            case 0:
                eliberare(lista);
                printf("Program încheiat.\n");
                break;
            default:
                printf("Opțiune invalidă.\n");
        }
    } while (optiune != 0);

    return 0;
}
