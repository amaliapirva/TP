/*: Se definește o structură Punct cu membrii x și y reali. Se cere un n<=10 și apoi n puncte.
Să se calculeze distanța dintre cele mai depărtate două puncte și să se afișeze.*/

#include<stdio.h>
#include<math.h>

typedef struct{
    double x,y;
}Punct;

double distanta(Punct a,Punct b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int n;
    Punct v[10];
    printf("Citim un numar n<=10: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Punctul %d are coordonatele: ",i);
        printf(" x= "); scanf("%lf",&v[i].x);
        printf(" y= "); scanf("%lf",&v[i].y);

    }
    double max_distanta=0.0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double d=distanta(v[i],v[j]);
            if(d>max_distanta){
                max_distanta=d;
            }
        }
    }
    printf("Cea mai mare distanta intre doua puncte este: %lf",max_distanta);
    return 0;
}