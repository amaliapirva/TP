/* Se citesc din linia de comanda, numerele naturale n si k (n<=26, k<=n) si apoi un alfabet format din n litere
distincte.
Sa se afiseze toate parolele de cate k litere care respecta urmatoarele cerinte:
• 2 litere consecutive nu pot fi egale sau vocale
• 2 litere alaturate nu pot avea coduri ASCII consecutive (nu pot exista parole care sa contina sirurile bc sau cb …)
In cazul in care nu s-au putut crea parole, se va afisa mesajul “EROARE”.
Exemplu:
n=8, k=3, a b c d e f g h
Solutii (partiale): ace, acf, acg, ...*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int n,k;
char alfabet[100];
char sol[100];
int gasit=0;

int esteVocala(char c){
    c=tolower(c);
    return c== 'a' || c == 'e' || c=='i' || c=='o' || c =='u';
}

int conditiiValide(int nivel, char litera){
    if(nivel==0) return 1;

    char anterior=sol[nivel-1];

    if(anterior==litera)
        return 0;
    
    if(esteVocala(anterior) && esteVocala(litera))
        return 0;
    
    if(abs(anterior-litera)==1)
        return 0;
    
    return 1;
}

void backtrack(int nivel){
    if(nivel==k){
        sol[nivel]='\0';
        printf("%s\n",sol);
        gasit=1;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(conditiiValide(nivel,alfabet[i])){
            sol[nivel]=alfabet[i];
            backtrack(nivel+1);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc<4){
        printf("Valori invalide pentru n sau k");
        return 1;
    }
    if(argc!=n+3){
        printf("Trebuie sa introduci exact %d litere.\n",n);
        return 1;
    }

    for(int i=0; i<n; i++)
    {
        alfabet[i]=argv[i+3][0];
    }
    backtrack(0);

    if(!gasit)
        printf("Eroare\n");

    return 0;
}