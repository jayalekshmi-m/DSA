#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*newnode,*temp;
// int n;
void insert_beg();
void insert_end();
void insert_pos();
void del_beg();
void del_end();
void del_pos();
void search();
void display();

void main()
{
    int i,n,choice;
    printf("enter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else 
        {
        temp->next=newnode;
        temp=newnode;
        }
        
    }
    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at a position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                del_beg();
                break;
            case 5:
                del_end();
                break;
            case 6:
                del_pos();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exited from program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 9);
}

   
    

void insert_beg()
{
   newnode = (struct node *)malloc(sizeof(struct node));
    struct node *newnode;
    printf("enter number to be inserted:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;


}
void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
     if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter number to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    }
    void insert_pos()
    {
        int i,pos;
             printf("enter position to insert:");
        scanf("%d",&pos);
        if(pos<1 )
        {
            printf("invalid position");
            return;
        }
        else 
            newnode = (struct node *)malloc(sizeof(struct node));
         printf("enter number to insert:");
        scanf("%d",&newnode->data);
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
        }
        temp=head;
        {
            for(i=0;i<=pos-1;i++)
            {
               temp=temp->next;
                // temp=newnode;
            }
             newnode->next=temp->next;
                temp->next=newnode;

        }
    }
    void del_beg()
    {
        if(head==NULL)
        {
            printf("list is empty");
            return;
        }
        head=temp;
        head=head->next;
        free(temp);
    }
    void del_end()
    {
        struct node *prevnode=NULL;
        if(head==NULL)
        {
            printf("list is empty");
            return;
        }
        else 
        {
            while(temp!=NULL)
            {
                prevnode=temp;
                temp=temp->next;
            }
            if(prevnode==NULL)
            {
                head=NULL;
            }
            else 
            {
            prevnode->next=NULL;
            }
        }
                   free(temp);
    }
    void del_pos()
    {
        int i,pos;
        struct node *nextnode;
        if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
        printf("enter position of element to delete");
        scanf("%d",&pos);
        if(pos<1)
        {
            printf("invalid position");
            return;
        }
         if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
         }
        else 
        {
                    temp=head;
            for(i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            nextnode=temp->next;
            temp->next=nextnode->next;
            free(nextnode);
        }

    }
    void search()
    {
        int i,item,flag=0,pos;
        if(head==NULL)
        {
            printf("list is empty");
        }
        printf("enter element to search");
        scanf("%d",&item);
       temp = head;
    while (temp != NULL) {
        pos++;
        if (temp->data == item) {
            printf("Element found at position %d.\n", pos);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
        if(flag==0)
        {
            printf("item not found");
        }
    }
void display()
{
     if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
 temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
