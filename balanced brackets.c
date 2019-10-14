#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 10

int top=-1, stack[MAX];


void push(char val)
{
 if(top==MAX-1)
 {
   printf("\n STACK OVERFLOW....!");;
 }
 else
 {
   top=top+1;
   stack[top]=val;
 }
}

void pop()
{
 if(top==-1)
   printf("\n STACK UNDERFLOW...!");
 else
 {
   top=top-1;
 }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Pair(char opening,char closing)
{
	if(opening == '(' && closing == ')')
	return 1;
	else if(opening == '{' && closing == '}') 
	return 1;
	else if(opening == '[' && closing == ']')
	return 1;
	return 0;
}

int main()
{
    char expr[MAX];
    int length=0,i,j;


    printf("Enter an expression to check:");
    scanf("%s",expr);

    length = strlen(expr);

    for(i=0;i<length;i++){
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
                push(expr[i]);
        }
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if(Pair(stack[top],expr[i]))
            {
                pop();
            }
        }
    }
    if(isEmpty())
    {
        printf("\nYES");
    }else{
        printf("\nNO");
    }
}
