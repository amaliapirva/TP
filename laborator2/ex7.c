/* Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca argument.
Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double.
Funcția de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat,
n - un număr întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de tabelat.
Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs din math.h
Exemplu: tabelare(-10,10,20,fabs) va afișa pe câte o linie valori de forma f(-10)=10  f(-9)=9   … f(10)=10 */

#include<stdio.h>
#include<math.h>

void tabelare(double a, double b, int n, double (*f)(double)){
    double pas=(b-a) / n;

    for(int i=0; i<=n; i++){
        double x=a+i*pas;
        printf("f(%.2f)=%.2f\n",x,f(x));
    }
}

int main()
{
    double a,b;
    int n,optiune;

    printf("Introduceti capetele intervalului:\n");
    printf("a= "); scanf("%lf",&a);
    printf("b= "); scanf("%lf",&b);
    printf("Introduceti numarul de segmente n: "); scanf("%d",&n);

    //meniul cu optiuni
    printf("Alegeti functia de tabelare");
    printf("1. cos\n");
    printf("2. sqrt\n");
    printf("3. fabs\n");
    printf("Optiunea dumneavostra: ");
    scanf("%d",&optiune);

    printf("Rezultatul tabelarii:\n");

    switch (optiune)
    {
    case 1:
        tabelare(a,b,n,cos);
        break;
    case 2:
        tabelare(a,b,n,sqrt);
        break;
    case 3:
    tabelare(a,b,n,fabs);
        break;
    default:
        printf("Optiune invalida");
        return 1;
    }

    return 0;
}