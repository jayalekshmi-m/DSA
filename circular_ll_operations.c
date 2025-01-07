#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *newnode,*tail=NULL;

void creation();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();

void main()
{
    int choice;
    do 
    {
        printf("1.creation\n 2.insert beginning\n 3.insert end\n 4.insert pos\n 5.del beg\n 6.del end\n 7.del pos\n 8.display\n 9.exit\n pls enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            creation();
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
            printf("exited from program");
            break;
            default:
            printf("invalid choice");
            break;
        }
    }while(choice!=9);
}
void creation()
{
   int i,n;
    printf("enter number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data for node %d:",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(tail==NULL)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
    }
}
void display()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("list is empty");
        return;
    }
    else 
    {
        temp=tail->next;
        printf("elements are:\n");
        while(temp->next!=tail->next)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void insert_beg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter element to insert:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else 
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
    printf("element added successfully");

}
void insert_end()
{
     newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter element to insert:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else 
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    printf("element added succeessfully");

}
void insert_pos()
{
    int pos,i,count=0;
    struct node *temp;
    printf("enter position to insert:");
    scanf("%d",&pos);
    temp=tail->next;
    do{
        count++;
        temp=temp->next;
    }while(temp!=tail->next);
    if(pos<0 || pos>count+1)
    {
        printf("invalid posititon");
        return;
    }
    else if(pos==1)
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
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter element to insert:");
        scanf("%d",&newnode->data);
        if(tail==NULL)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else 
        {
            temp=tail->next;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
            printf("element added succeessfully");
}
void del_beg()
{
    struct node *temp;
    temp=tail->next;
    if(tail==NULL)
    {
        printf("list is empty");
        return;
    }
    else if(temp==tail)
    {
        tail=NULL;
        free(temp);
    }
    else 
    {
    tail->next=temp->next;
    free(temp);
    }
    printf("element deleted successfully\n");
}
void del_end()
{
    struct node *temp,*current;
    temp=tail->next;
    if(tail==NULL)
    {
        printf("list is empty");
        return;
    }
    else if(temp==tail)
    {
        tail=NULL;
        free(temp);
    }
    else 
    {
        while(temp->next!=tail->next)
        {
            current=temp;
            temp=temp->next;
        }
        current->next=tail->next;
        tail=current;
        free(temp);

    }
    printf("element deleted successfully");
}
void del_pos()
{
    int pos,i,count=0;
    struct node *temp,*nextnode;
    temp=tail->next;
    do{
        count++;
        temp=temp->next;
    }while(temp!=tail->next);
    printf("enter position to delete");
    scanf("%d",&pos);
    if(pos<0 || pos>count)
    {
        printf("invalid position");
        return;
    }
    else if(pos==1)
    {
        del_beg();
        return;
    }
    else if(pos==count)
    {
        del_end();
        return;
    }
    else 
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
    printf("element deleted successfully");
    
}
// circular linked list operations