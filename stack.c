#include <stdio.h>

int main()
{
    int max = 5;
    int stack[max];
    int top = -1;
    int choice;

    while (choice != 5)
    {

        printf("Choose operation: \n1 Insertion\n2 Deletion\n3 Peek\n4 Display\n5 Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top == max - 1)
            {
                printf("Overflow\n");
            }
            else
            {
                int user_input;
                printf("Enter the element: ");
                scanf("%d", &user_input);

                top++;
                stack[top] = user_input;
            }

            break;
        case 2:
            if (top == -1)
            {
                printf("underflow\n");
            }
            else
            {
                int item;
                item = stack[top];
                top = top - 1;
                printf("the deleted element is : %d\n", item);
            }
            break;
        case 3:
        if(top==-1)
        {
            printf(" underflow\n");
        }
            else
            {
              printf("the topmost element is : %d",stack[top]);
            }
        case 4: 
        if(top ==-1)
        {
           printf(" underflow\n");
        }
        else
        {
            printf("the elements are : ");
            for(int i=top;i>=0; i--)
            {
       printf("%d ",stack[i]);
            }
            
        }
        default:
            printf("Enter a valid option!");
            break;
        }
    }
}
