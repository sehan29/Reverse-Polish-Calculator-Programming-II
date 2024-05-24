#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSTACK 20
typedef int StackEntry;
typedef enum {FALSE, TRUE} Boolean;

typedef struct{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

// Creating New Stack
void CreateStack(Stack *s)
{
    s->top = -1;
}

// Checking Whether Empty or Not
Boolean IsStackEmpty(const Stack *s)
{

    if(s->top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}