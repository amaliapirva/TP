/*: Să se scrie o funcție maxN care primește ca prim parametru un număr n de elemente, iar apoi n
elemente de tip real, care vor fi date sub forma unei liste variabile de argumente. Funcția va returna maximul tuturor
argumentelor:*/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

double maxN(int n,...)
{
    va_list va; //lista de argumente variabile
    va_start(va,n);//initializare cu ultimul argument fix
    double max=va_arg(va,double);//preia prima valoare din va ca fiind de tip double
    while(--n){
        double e=va_arg(va,double);//returneaza pe rand fiecare valoare ramasa in va ca fiind de tip double
        if(max<e)max=e;
    }
    va_end(va);
    return max;
}
int main()
{
    printf("%g\n",maxN(3,8,0,5));//vom avea eroare la executie, functia maxN nu le va procesa corect
    printf("%g\n",maxN(3,(double)8,0.0,(float)5));
    return 0;

}