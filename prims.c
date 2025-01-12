#include<stdio.h>
#include<limits.h>
#define max 10
int A[max][max]={0};

void prims(int A[][max],int n)
{
    int min,minU,minV,cost=0,edgecount=1;
    int parent[n],visited[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        visited[i]=0;
    }
    visited[0]=1;  // Start from vertex 0
    while(edgecount<n)
    {
        min=INT_MAX;   // Initialize minimum as infinity
        for(int i=0; i<n; i++)
        {
            if(visited[i])    // Check only visited nodes
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && A[i][j] < min)   // Find the smallest edge
                    {
                        min=A[i][j];
                        minU=i;     // Store the starting vertex
                        minV=j;     // Store the ending vertex
                    }
                }
            }
        }
        if(min==INT_MAX)
        {
            break;     // Stop if no edge is found
        }
        A[minU][minV]=A[minV][minU]=INT_MAX;      // Mark edge as used
        printf("%d->",min);      // Print the weight of the edge
        cost +=min;             // Add weight to total cost
        visited[minV]=1;          // Mark the vertex as visited
        printf("Spanning tree edges are {%d,%d}=%d\n",minU,minV,min);
        edgecount++;
    }
    printf("Total cost is %d",cost);
}

void main()
{
    int n,i,j;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix (weight):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                A[i][j]=0;        // No self-loops
            }
            else 
            {
                printf("A[%d][%d]:",i,j);
                scanf("%d",&A[i][j]);              // Input weights
            }
            if(A[i][j]==0)
            {
                A[i][j]=INT_MAX;                    // Replace 0 with infinity for no edge

            }
        }
    }
    prims(A,n);
}

// implementation of prims algorithm