#include<stdio.h>
#define MAX 100

void bfs(int graph[][MAX],int num)
{
    int visited[num],queue[num];
    int front=0,rear=0,i;
    for(i=0;i<num;i++)
    {
    visited[i]=0;
    }
    int start=0;
    visited[start]=1;
    queue[rear++]=start;
    printf("BFS Traversal:\n");
    while(front<rear)
    {
        int current=queue[front++];
        printf("%d\t",current);

        for(i=0;i<num;i++)
        {
            if(graph[current][i]==1 && visited[i]==0)
            {
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
    printf("adjacency matrix:\n");
    for(i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int num,edges,vertex1,vertex2,i;
    int graph[MAX][MAX]={0};
    printf("enter the number of vertices in the graph");
    scanf("%d",&num);
    printf("enter the number of edges");
    scanf("%d",&edges);
    printf("enter the edges(as pair of vertices,eg.,0,1):\n");
    for(i=0;i<edges;i++)
    {
        scanf("%d%d",&vertex1,&vertex2);
        if(vertex1>=num || vertex2>=num || vertex1<0 || vertex2<0)
        {
            printf("invalid edge.please enter vertices between 0 and %d",num-1);
            i--;
            continue;
        }
        if(vertex1==vertex2)
        {
            printf("self loops are not allowed.enter different vertices\n");
            i--;
            continue;
        }
        graph[vertex1][vertex2]=1;
        graph[vertex2][vertex1]=1;
    }
    bfs(graph,num);
}

// breadth first search program