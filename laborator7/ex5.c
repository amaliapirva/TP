/*Să se scrie o funcție care primește ca parametri două liste și returnează o listă care reprezintă
reuniunea elementelor lor, fiecare element apărând o singură dată, chiar dacă în listele originare el este duplicat.*/
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

int contine(elem *lista, int n) {
    for (; lista; lista = lista->urm) {
        if (lista->n == n)
            return 1;
    }
    return 0;
}

elem* reuniune(elem *a, elem *b) {
    elem *rez = NULL;

    for (; a; a = a->urm) {
        if (!contine(rez, a->n)) {
            rez = adaugaSfarsit(rez, a->n);
        }
    }

    for (; b; b = b->urm) {
        if (!contine(rez, b->n)) {
            rez = adaugaSfarsit(rez, b->n);
        }
    }

    return rez;
}

void afisare(elem *lista) {
    for (; lista; lista = lista->urm) {
        printf("%d ", lista->n);
    }
    printf("\n");
}

void eliberare(elem *lista) {
    while (lista) {
        elem *temp = lista;
        lista = lista->urm;
        free(temp);
    }
}

int main() {
    elem *lista1 = NULL, *lista2 = NULL, *rezultat = NULL;

    lista1 = adaugaSfarsit(lista1, 1);
    lista1 = adaugaSfarsit(lista1, 2);
    lista1 = adaugaSfarsit(lista1, 3);
    lista1 = adaugaSfarsit(lista1, 2);

    lista2 = adaugaSfarsit(lista2, 3);
    lista2 = adaugaSfarsit(lista2, 4);
    lista2 = adaugaSfarsit(lista2, 5);
    lista2 = adaugaSfarsit(lista2, 1);

    printf("Lista 1: ");
    afisare(lista1);

    printf("Lista 2: ");
    afisare(lista2);

    rezultat = reuniune(lista1, lista2);

    printf("Reuniune: ");
    afisare(rezultat);

    eliberare(lista1);
    eliberare(lista2);
    eliberare(rezultat);

    return 0;
}
