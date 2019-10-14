#include<stdio.h>
#define MAX 100
 
char s_name[MAX][MAX];
char s_USN[MAX][MAX];
char s_email[MAX][MAX];
int option,n,top,i;
char name[100],usn[100],email[100];

void push(void);
void pop(void);
void display(void);
int main()
{
    top=-1;
    printf("\nEnter the size of Auditorium[MAX=100]:\n");
    scanf("%d",&n);
    
    do
    {
        printf("\n Entry Registration\n Please choose any option given below");
        printf("\n\n 1.Enter Student Entry Details\n 2.Delete Last student details\n 3.Display Student info in Last in First Out\n 4.Exit \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n End");
                break;
            }
            default:
            {
                printf ("\nPlease press a valid option..\n\n");
            }
                 
        }
    }
    while(option!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\nRegister is full\n\n");
         
    }
    else
    {
        top++;
        printf("Enter Name \n");
        scanf("%s",&s_name[top][MAX]);
        printf("Enter USN \n");
        scanf("%s",&s_USN[top][MAX]);
        printf("Enter Email \n");
        scanf("%s",&s_email[top][MAX]);
        
        
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\nReister is empty\n\n");
    }
    else
    {
        printf("\nLast entered student details are deleted\n\n");
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("Students Entered: \n");
        printf("Name \t\t USN \t\t E-mail \t\t \n");
        for(i=top+1; i>=0; i--)
        {
            printf("%s \t\t %s \t\t %s \t\t \n",s_name[i],s_USN[i],s_email[i]);
        }
            
        
    }
    else
    {
        printf("\n The Register is empty\n\n");
    }
    
}
