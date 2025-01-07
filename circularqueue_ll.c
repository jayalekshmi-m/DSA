#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue()
{
    struct node *newnode;
    int n,i;
    printf("enter number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data for node %d",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=rear=newnode;
            rear->next=front;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("underflow");
    }
    else if(front==rear)
    {
        front=rear=NULL;
        free(temp);

    }
    else
    {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("empty");
    }
    else
    {
        printf("front element is %d",front->data);
    }
}
void display()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("underflow condition");
    }
    else 
    {
        printf("elements are:\n");
        while(temp->next!=front)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void main()
{
    int choice;
    do 
    {
        printf("1.enqueue\n 2.dequeue\n 3.peek\n 4.display\n 5.exit\n enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            printf("exited from program");
            break;
            default:
            printf("invalid choice");
        }
    }while(choice!=5);
}
// implementation of circular queue using linked list