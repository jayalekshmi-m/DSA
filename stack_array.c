#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("enter data");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("overflow condition\n");
        return;
    }
    else
    {
        top++;
        stack[top]=x;
        printf("element pushed %d\n",x);
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("underflow condition\n");
        return;
    }
    else 
    {
        item=stack[top];
        top--;
        printf("poped item is:%d\n",item);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("topmost element is %d\n",stack[top]);
    }
}
void display()
{
    int i;
    printf("elements are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
void main()
{
    int choice;
    // clrscr();
    do
    {
        printf("enter choice:\n1.push\n 2.pop\n 3.peek\n 4.dispaly\n 5.exit\n pls enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            printf("exiting program\n bie bie");
            break;
            default:
            printf("invalid condition\n");
        }
        }while(choice!=5);
        // getch();
    }
    // implementing stack using array
