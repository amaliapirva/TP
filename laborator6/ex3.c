/*Sa se scrie o functie citire care primește ca prim argument un șir de caractere fmt, iar apoi o listă de
argumente varargs, care reprezintă fiecare adresa unei variabile. Funcția va citi de la tastatură valori și le va
depozita în adresele de memorie care sunt date în lista varargs. Pentru a se ști ce tip de date se citește, în fmt se
dă câte o literă specifică pentru fiecare adresă din listă: d-int, f-float, s-șir de caractere:*/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void citire(const char *fmt,...)
{
    va_list va;
    va_start(va,fmt);
    int *addrInt;
    float *addrFloat;
    char *addrStr;
    for(;; fmt++){ //bucla infinita in care se proceseaza fiecare element din fmt
        switch(*fmt){
            case '\0':
                va_end(va);
                return;
            case 'd':
                addrInt=va_arg(va,int*);
                scanf("%d",addrInt);
                break;
            case 'f':
                addrFloat=va_arg(va,float*);
                scanf("%g",addrFloat);
                break;
            case 's':
                addrStr=va_arg(va,char*);
                scanf("%s",addrStr);
                break;
        }

    }
}

int main()
{
    int n,m;
    float x;
    char buf[100];
    printf("introduceti n,m,x si buf:\n");
    citire("ddfs",&n,&m,&x,buf);
    printf("n=%d,m=%d,x=%g,buf=%s",n,m,x,buf);
    return 0;
}