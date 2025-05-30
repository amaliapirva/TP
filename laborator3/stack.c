#include<stdio.h>
//Stiva=structura de date de tip LIFO(last in first out)
#define MAX_SIZE 100
int top=-1;

int stack[MAX_SIZE];// vectorul care va reprezenta stiva

//functie de adaugare a unui element in stiva

void push(int item)
{
    if(top==MAX_SIZE-1){
        printf("Stiva este plina\n");
        return;
    }
    stack[++top]=item;
}
//functie de extragere a unui element
int pop(){
    if(top==-1){
        printf("Stiva este goala\n");
        return -1;
    }
    return stack[top--];
}

//functie de afisat elementele din stiva
void display()
{
    if(top==-1){
        printf("Stiva este goala\n");
        return;
    }
    printf("Elementele din stiva sunt:\n");
    for(int i=top; i>=0; i--)
       { printf("%d",stack[i]);}
    printf("\n");
}

int main()
{
    printf("1");
    push(10);
    printf("a");
    push(20);
    push(30);
    display();
    printf("Elementul extras din stiva: %d\n",pop());
    display();
    return 0;
}