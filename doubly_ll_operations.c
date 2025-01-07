#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*newnode,*temp;
int size;

void create();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void display();

void main()
{
    int choice;
    do{
    printf("1.Creation\n 2.Insertion at beg\n 3.Insertion at end\n 4.Insert at pos\n 5.Del at beg\n 6.Del at end\n 7.Del at pos\n 8.Display\n 9.Exit");
    printf("Enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create();
        break;
        case 2:
        insert_beg();
        break;
        case 3:
        insert_end();
        break;
        case 4:
        insert_pos();
        break;
        case 5:
        del_beg();
        break;
        case 6:
        del_end();
        break;
        case 7:
        del_pos();
        break;
        case 8:
        display();
        break;
        case 9:
        printf("Exited from program");
        break;
        default:
        printf("Invalid choice");
        break;
    }
}while(choice!=9);
}

void create()
{
    int size,i;
    printf("enter number of elements:");
    scanf("%d",&size);
    printf("enter elements to insert");
    for(i=0;i<size;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else 
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
}

void display()
{
    temp=head;
    printf("elements are:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void insert_beg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter element to insert");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else 
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    size++;
}
void insert_end()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter element to insert:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else 
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    size++;
}

void insert_pos()
{
    int pos,i,count=0;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter position to insert");
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    scanf("%d",&pos);
    if(pos<1 || pos>count+1)
    {
        printf("invalid position");
        return;
    }
    printf("enter element to insert");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
        temp=head;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        if(head==NULL)
        {
            head=temp=newnode;
        } else if(pos==1)
        {
            insert_beg();
            return;
        }
        else if(pos==count+1)
        {
            insert_end();
            return;
        }
        else 
        {
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;
        }
        size++;
}

void del_beg()
{ 
    if(head==NULL)
    {
        printf("empty");
    } else 
    {
    temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    size--;
    printf("elemented deleted successfully");
}

void del_end()
{
    struct node *prevnode;
   if (head == NULL) {
        printf("List is empty\n");
        return ;
    }

    temp = head;
    prevnode = NULL;

    while (temp->next != NULL) { // Traverse to the last node
        prevnode = temp;
        temp = temp->next;
    }

    if (prevnode == NULL) { // Only one node in the list
        head = NULL;
    } else {
        prevnode->next = NULL;
    }
    free(temp);
        size--;
        printf("elemented deleted successfully");
}

void del_pos()
{
    int pos,i,count=0;
    struct node *nextnode;
   temp=head;
    while(temp!=NULL)   
    {
        count++;
        temp=temp->next;
    }
    printf("enter position you want to delete");
    scanf("%d",&pos);
    if(pos<1 || pos>count)
    {
        printf("invalid position");
        return ;
    }
    if(pos==1)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
    temp=head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    }
    size--;
   printf("elemented deleted successfully");


}
// doubly linked list operations