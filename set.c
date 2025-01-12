#include<stdio.h>

void set_union(int arr1[],int arr2[],int u[],int limit)
{
    printf("The union is : {");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i]==1 || arr2[i]==1)
        {
            printf("%d,",u[i]);
        }
    }
    printf("}\n");
}

void set_intersection(int arr1[],int arr2[],int u[],int limit)
{
    printf("Set intersection:{");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i]==1 && arr2[i]==1)
        {
            printf("%d,",u[i]);
        }
    }
    printf("}\n");
}

void set_display(int arr[],int limit)
{
    printf("The set is : {");
    for(int i=0;i<limit;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("}\n");
}

int isPresent(int data,int u[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        if(data==u[i])
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int limit,num1,num2,i,data,k;
    printf("Enter the number of elements in the universal set:");
    scanf("%d",&limit);
    int u[limit];
    printf("Enter the elements of universal set\n");
    for(i=0;i<limit;i++)
    {
        printf("Enter the element");
        scanf("%d",&u[i]);
    }
    // initialize subsets
    int arr1[limit],arr2[limit];
    for(i=0;i<limit;i++)
    {
        arr1[i]=arr2[i]=0;
    }
    // input the first subset
    printf("Enter the elements of first subset(less than %d): ",limit);
    scanf("%d",&num1);
    for(i=0;i<num1;i++)
    {
        printf("Enter the element:");
        scanf("%d",&data);
        k=isPresent(data,u,limit);
        if(k!=-1)
        {
            arr1[k]=1;
        }
        else 
        {
            printf("Enter a valid element which is a subset of universal set:");
            break;
        }
    }
    printf("Enter the elements of second subset(less than %d)",limit);
    scanf("%d",&num2);
    for(i=0;i<num2;i++)
    {
        printf("Enter the element:");
        scanf("%d",&data);
        k=isPresent(data,u,limit);
        if(k!=-1)
        {
            arr2[k]=1;
        }
        else 
        {
            printf("Enter a valid element which is a subset of universal set.\n");
        }
    }
    // display subsets
    set_display(arr1,limit);
    set_display(arr2,limit);
    // perform union and intersection
    set_union(arr1,arr2,u,limit);
    set_intersection(arr1,arr2,u,limit);
}

// set using bit vector