#include<stdio.h>

int n,start,visited[25],adj[25][25];
void dfs(int start);


void dfs(int start){
    visited[start]=1;
    printf("\t%d", start);

    for(int i=0;i<n;i++){
        if(adj[start][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter Adjacency Matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\nA[%d][%d]",i,j);
            scanf("%d",adj[i][j]);
        }
    }
    printf("\nEnter the starting node for traversal: ");
    scanf("%d",&start);

    printf("\nDFS Traversal is: ");
    dfs(start);

    return 0;
}