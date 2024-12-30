#include<stdio.h>
int main()
{
int choice,n,a,item, pos;
printf("Enter the no of elements: ");
scanf("%d",&n);
int arr[n];
printf("Enter the array elements: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int b;
do{
printf("1.Search 2.Sort 3.Insert 4.Delete 5.Display");
printf("\nEnter Your Choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the element to search: ");
    scanf("%d", &a);
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            printf("Element found at index %d", i+1);
            return 0; 
       }

    }
    printf("Element not found");
break;
case 2:
for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Elements after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
break;
case 3:
printf("Enter the element to be inserted: ");
    scanf("%d",&item);
    printf("Enter the position at which the element is to be inserted: ");
    scanf("%d",&pos);
    n++;
    for (int i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = item;
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
break;
case 4:
printf("Enter the element to be deleted: ");
    scanf("%d",&item);
    for (int i = 0; i < n; i++) {
        if(arr[i] == item) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            break;
        }
    }
        printf("Array after deletion: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
break;
case 5:
printf("Array elements are: ");
for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
}
break;
default:
printf("Error");
break;
}
printf("Do yo want to continue(1 for Yes/0 for No)");
scanf("%d", &b);
} while(b==1);

}