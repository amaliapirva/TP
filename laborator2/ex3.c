/*Se dă un vector de puncte în plan, având coordonatele (x,y) de tipul double. 
Se cere să se sorteze acest vector în ordinea distanțelor punctelor față de origine.*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
    double x,y;
}Pt;

double dist(const Pt *pt)
{
    return sqrt(pt->x*pt->x+pt->y*pt->y);
}
//deoarece qsort transmite functiei de comparare adresele elementelor, functia va primi pointeri la elemente
//in acest caz, deoarece vectorul are elemente de tipul Pt, functia va primi parametrii de tipul Pt*

int cmpDist(const void *elem1, const void *elem2)
{
    const Pt *p1=(const Pt*)elem1;
    const Pt *p2=(const Pt*)elem2;
    double d1=dist(p1);
    double d2=dist(p2);

    if(d1<d2) return -1;
    if(d1>d2) return 1;
    return 0;
}
int main(void)
{
    Pt puncte[5]={{1,3},{7,5},{0,0},{-2,4},{1,1}};
    int i,n=5;
    qsort(puncte,n,sizeof(Pt),cmpDist);
    for(i=0; i<n; i++)
    {
        printf("%g, %g\n",puncte[i].x,puncte[i].y);
    }
    return 0;
}