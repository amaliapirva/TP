/*: Să se imlementeze un program care gestionează un parc de automobile.
Informaţiile relative la un automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9),
puterea (în cai putere între 1 și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017).
Parcul conține n automobile, datele sunt citite de la tastatură.
Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.*/

#include<stdio.h>

typedef struct{
    int cod_masina:14;
    int nr_locuri:4;
    int putere:9;
    char marca[20];
    char culoare[20];
    int an_fabricatie:11;
}Automobil;
int n=0;
Automobil parc[100];

void adauga()
{
    if(n>=100){
        printf("Parcul este plin\n");
        return;
    }
    
    Automobil a;
    printf("Cod (1-9000): "); scanf("%u", &a.cod);
    printf("Nr locuri (1-9): "); scanf("%u", &a.locuri);
    printf("Putere (1-500 CP): "); scanf("%u", &a.putere);
    printf("An fabricatie (1800-2017): "); scanf("%u", &a.an);
    printf("Marca: "); scanf(" %29s", a.marca);
    printf("Culoare: "); scanf(" %19s", a.culoare);

    parc[n++] = a;
}

void stergeDupaCod()
{
    unsigned int cod;
    printf("Introduceti codul masinii de sters:");
    scanf("%u",&cod);

    for(int i=0; i<n; i++){
        if(parc[i].cod==cod){
            for(int j=i; j<n; j++)
            {
                parc[j]=parc[j+1];
            }
            n--;
            printf("Masina cu codul %u a fost stearsa.\n",cod);
            return;
        }
    }
    printf("Masina nu a fost gasita:\n");
}

void afiseazaToate() {
    printf("\nLista automobilelor:\n");
    for (int i = 0; i < n; i++) {
        printf("Cod: %u | Marca: %s | Culoare: %s | Locuri: %u | Putere: %u CP | An: %u\n",
            parc[i].cod, parc[i].marca, parc[i].culoare,
            parc[i].locuri, parc[i].putere, parc[i].an);
    }
}

void afiseazaDupaLocuri() {
    unsigned int nr;
    printf("Introduceti numarul de locuri: ");
    scanf("%u", &nr);

    printf("\nMasini cu %u locuri:\n", nr);
    for (int i = 0; i < n; i++) {
        if (parc[i].locuri == nr) {
            printf("Cod: %u | Marca: %s | Culoare: %s | Putere: %u CP | An: %u\n",
                parc[i].cod, parc[i].marca, parc[i].culoare,
                parc[i].putere, parc[i].an);
        }
    }
}

int comparaAn(const void *a, const void *b) {
    Automobil *m1 = (Automobil *)a;
    Automobil *m2 = (Automobil *)b;
    return m1->an - m2->an;
}

void sorteazaDupaAn() {
    qsort(parc, n, sizeof(Automobil), comparaAn);
    printf("Lista a fost sortata dupa anul fabricatiei.\n");
}

int main() {
    int opt;
    do {
        printf("\n=== Meniu ===\n");
        printf("1. Adauga automobil\n");
        printf("2. Sterge automobil dupa cod\n");
        printf("3. Afiseaza toate automobilele\n");
        printf("4. Afiseaza dupa numar de locuri\n");
        printf("5. Sorteaza dupa anul fabricatiei\n");
        printf("0. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: adauga(); break;
            case 2: stergeDupaCod(); break;
            case 3: afiseazaToate(); break;
            case 4: afiseazaDupaLocuri(); break;
            case 5: sorteazaDupaAn(); break;
            case 0: printf("Iesire...\n"); break;
            default: printf("Optiune invalida!\n");
        }

    } while (opt != 0);

    return 0;
}