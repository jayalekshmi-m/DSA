#include<stdio.h>
int a[50],size,i;
void insert();
void delete();
void display();
void search();
    
void main()
{
        int choice;
        printf("enter array size");
    scanf("%d",&size);
    if(size>50)
    {
        printf("overflow");
        return;
    }
    else 
    {
         printf("enter array elements");
        for(i=0;i<size;i++)
        {
            scanf("%d",&a[i]);
        }
    }

    do{
    printf("1.Insertion 2.Deletion 3.Display 4.Search 5.Exit\n Pls enter  ur choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
        break;
        case 4:
        search();
        break;
        case 5:
        printf("exited from pgm");
        break;
        default:
        printf("invalid choice");
        break;

    }
}while(choice!=5);
}
void insert() {
    int num, pos;
    printf("Enter element you want to insert: ");
    scanf("%d", &num);
    printf("Enter position you want to insert (1-based index): ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1 || size >= 50) {
        printf("Invalid position or array is full\n");
        return;
    }

    for ( i = size; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    size++;
    printf("Element inserted successfully\n");
}
void display() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Array elements: ");
    for ( i = 0; i < size; i++) {
        printf("%d\n ", a[i]);
    }
}
void delete()
{
    int num,pos;
    printf("enter position of the element to delete(1-based index):");
    scanf("%d",&pos);
     printf("deleted element is %d\n ",a[pos-1]);
    if(pos<1 || pos>size)
    {
        printf("invalid position");
        return;
    }
    for(i=pos-1;i<size;i++)
    {
        a[i]=a[i+1];
    }
    size--;
    printf("element deleted succesfully\n");
}
void search()
{
    int num,flag=0;
    printf("enter element to search");
    scanf("%d",&num);
    for(i=0;i<size;i++)
    {
        if(a[i]==num)
        {
            printf("element found at position %d\n",i+1);
            flag=1;
            return;
        }
    }
    if(flag==0)
    {
        printf("element not found\n");
    }
}