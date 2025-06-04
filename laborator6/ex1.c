/* Se citește un 0<n<=100 întreg și apoi două valori x
și y reale, x<y. Se vor citi apoi n valori, care fiecare trebuie să fie în intervalul [x,y]. În final se va afișa minimul și
maximul valorilor citite. Dacă vreuna dintre valorile introduse nu este conformă cerințelor, programul va afișa
valoarea greșită și se va termina imediat.
*/
//rezolvarea problemei folosind varargs pentru erori

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void err(const char *fmt,...)
{
    va_list va;//pointer la lista de argumente variabile
    va_start(va,fmt);//va trebui initializat cu ultimul argument fix al functiei
    fprintf(stderr,"eroare ");
    vfprintf(stderr,fmt,va);//varianta de fprintf care primeste o lista de argumente variabila
    va_end(va);
    fputc('\n',stderr);
    exit(EXIT_FAILURE);
}

int main()
{
    int i,n;
    float x,y,e,min,max;
    printf("n="); scanf("%d",&n);
    if(n<=0 || n>100) err("n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    if(x>=y)err("x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
    for(i=0; i<n; i++){
        printf("e="); scanf("%g",&e);
        if(e<x || e>y) err("element invalid:%g\n",e);
        if(e<min)min=e;
        if(e>max)max=e;
    }
    printf("min:%g,max:%g\n",min,max);
    return 0;
}