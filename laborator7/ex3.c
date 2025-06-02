/*Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int n;
    struct elem *urm;
} elem;


elem *nou(int n, elem *urm) {
    elem *e = (elem *)malloc(sizeof(elem));
    if (!e) {
        printf("Memorie insuficienta!\n");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

elem *adaugaInceput(elem *lista, int n) {
    return nou(n, lista);
}

elem *adaugaSfarsit(elem *lista, int n) {
    if (!lista) return nou(n, NULL);
    elem *p = lista, *urm;
    for (urm = p->urm; urm; p = urm, urm = p->urm) {}
    p->urm = nou(n, NULL);
    return lista;
}

void afisare(elem *lista) {
    for (; lista; lista = lista->urm) {
        printf("%d ", lista->n);
    }
    putchar('\n');
}

int liste_identice(elem *a, elem *b) {
    while (a && b) {
        if (a->n != b->n)
            return 0;
        a = a->urm;
        b = b->urm;
    }
    return a == NULL && b == NULL;
}

void eliberare(elem *lista) {
    while (lista) {
        elem *temp = lista;
        lista = lista->urm;
        free(temp);
    }
}

int main() {
    elem *lista1 = NULL, *lista2 = NULL;
    int n, val;

    printf("Cate elemente are lista 1? ");
    scanf("%d", &n);
    printf("Introdu %d elemente pentru lista 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        lista1 = adaugaSfarsit(lista1, val);
    }

    printf("Cate elemente are lista 2? ");
    scanf("%d", &n);
    printf("Introdu %d elemente pentru lista 2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        lista2 = adaugaSfarsit(lista2, val);
    }

    printf("Lista 1: ");
    afisare(lista1);
    printf("Lista 2: ");
    afisare(lista2);

    if (liste_identice(lista1, lista2)) {
        printf("Listele sunt identice.\n");
    } else {
        printf("Listele NU sunt identice.\n");
    }

    eliberare(lista1);
    eliberare(lista2);

    return 0;
}
