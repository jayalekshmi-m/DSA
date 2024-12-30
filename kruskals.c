#include <stdio.h>
#include <stdlib.h>


int comparator(const void *a, const void *b) {
    return ((int*)a)[2] - ((int*)b)[2];  
}


int findParent(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]); 
    return parent[x];
}


void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;  
        }
    }
}


void kruskal(int n, int edges[][3]) {
   
    qsort(edges, n, sizeof(edges[0]), comparator);
    
    int parent[n], rank[n];
    
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    
  
    for (int i = 0; i < n; i++) {
        int u = edges[i][0], v = edges[i][1], weight = edges[i][2];

       
        if (findParent(parent, u) != findParent(parent, v)) {
            unionSets(parent, rank, u, v);
            printf("%d -- %d == %d\n", u, v, weight);
            minCost += weight;
        }
    }
    
    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}


int main() {
   
    int edges[5][3] = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };
    
 
    kruskal(5, edges);
    
    return 0;
}
