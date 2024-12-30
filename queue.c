#include <stdio.h>
#include <stdlib.h>
#define MAX 35

int queue[MAX];
int front=-1;
int rear=-1;

int main(){
    int choice,n,x;
do{

    printf("1) enqeue\n");
     printf("2) Display\n");
      printf("3) dequeue\n");
       printf("select any : ");
       scanf("%d",&choice);
       switch(choice){
        case 1:

            if(rear==max-1){
        printf("queue is full\n ");
            }else{
                printf("enter the element to be inserted : ");
                scanf("%d",&x);
                rear++;
                queue[rear]=x;
            }
            break;
            case 2:
            if(rear==-1)
            {
                printf("queue is empty");
                }
                else{
                   printf("queue elements are:/n");
                   for(int i=front+1;i<=rear;i++){
                    printf("%d\n" queue[i]);
                   }
                }break;
            
            case 3:
            if(front==rear==-1){
                printf("queue is empty");
            
            }else{
                printf("deleted element is : %d\n",queue[front+1]);
                front++;
            }
            break;
            default:
            printf("invalid choice");
            }
       }

}
}