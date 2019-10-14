#include <stdio.h>
#define SIZE 10
 
 
int ar[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[++top1] = data;
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}
void push2 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[--top2] = data; 
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}
 

void pop1 ()
{
  if (top1 >= 0)
  {
    int value = ar[top1--];
    printf ("%d is being popped from Stack 1\n",value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
void pop2 ()
{
  if (top2 < SIZE)
  {
    int value = ar[top2++];
    printf ("%d is being popped from Stack 2\n",value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
 

void display1()
{
  int i;
  if(top1==-1)
  {
      printf("Stack is Empty!\n");
  }
  else
  {
  for (i = top1; i >= 0; --i)
  {
    printf ("%d ", ar[i]);
  }
  printf ("\n");
  }
}

void display2()
{
  int i;
  if(top2==SIZE)
  {
      printf("Stack is Empty!\n");
  }
  else
  {
  for (i = top2; i < SIZE; ++i)
  {
    printf ("%d ", ar[i]);
  }
  printf ("\n");
  }
}
 
int main()
{
  int ch,ele;
  do{
  printf("\n STACK MENU");
  printf("\n1.push to stack1\n2.push to stack2\n3.pop from stack 1\n4.pop from stack 2\n5.display stack 1\n6.display stack 3\n7.exit");
  printf("\n Enter your choice(1-4)");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("Enter element");
       scanf("%d",&ele);
       push1(ele);
	   break;
   case 2: printf("Enter element");
       scanf("%d",&ele);
       push2(ele);
	   break;
   case 3: pop1();
	   break;
   case 4: pop2();
	   break;
   case 5: display1();
	   break;
   case 6: display2();
	   break;
   case 7: break;
   default:
	   printf("\n INVALID CHOICE");
  }
  }while(ch!=7);
  getch();
}
