#include<stdio.h>
#include<limits.h>
#define max 10
#define INF INT_MAX
int A[max][max]={0};

int Find(int vertex,int parent[])
{
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    // path compression
    parent[vertex]=Find(parent[vertex],parent);
    return parent[vertex];
}

int Union(int rootU,int rootV,int parent[],int size[])
{
    if(size[rootU] < size[rootV])
    {
        parent[rootU]=rootV;            // Attach smaller tree under larger tree
        size[rootV] +=size[rootU];
    }
    else 
    {
        parent[rootV]=rootU;
       size[rootU] +=size[rootV];
    }
}

int kruskal(int A[][max],int n)
{
    int min,minU,minV,rootU,rootV,edgeCount=0;
    int parent[n],size[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;        // Each vertex is its own parent initially
        size[i]=1;          // Each set has initially size 1
    }
    // find the smallest edge
    while(edgeCount < n-1)
    {
        min=INF;
        minU=minV=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][j] < min)
                {
                    min=A[i][j];
                    minU=i;
                    minV=j;
                }
            }
        }
        if(min==INF)
        {
            break;      // No valid edge found, terminate
        }
        A[minU][minV]=A[minV][minU]=INF;        // mark edge as used
        rootU=Find(minU,parent);
        rootV=Find(minV,parent);
        printf("Edges in the minimum spanning tree are:\n");
        if(rootU!=rootV)
        {
            printf("Edge(%d->%d) with weight %d\n",minU,minV,min);
            Union(rootU,rootV,parent,size);
            edgeCount++;
        }
    }
        if(edgeCount!=n-1)
        {
            printf("The graph is not connected.No spanning tree exist");
        }
    
}

int main()
{
    int n;
    printf("Enter the number of vetices in the graph:");
    scanf("%d",&n);
    if(n<=0 || n>max)
    {
        printf("invalid number of vertices.pls enter a value between 1 and %d",max);
        return 1;
    }
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                A[i][j]=0;      // no self loops
            }
            else 
            {
                printf("A[%d][%d]: ",i,j);
                scanf("%d",&A[i][j]);
                if(A[i][j]==0)
                A[i][j]=INF;        // treat zero as no edge
            }
        }
    }
    kruskal(A,n);
}

// kruskals algorithm implementation