#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix for the graph

// DFS function
void dfs(int num, int visited[], int start) {
    visited[start] = 1; // Mark the current node as visited
    printf("%d -> ", start); // Print the current vertex

    for (int i = 0; i < num; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(num, visited, i); // Recursively visit unvisited neighbors
        }
    }
}

int main() {
    int num, visited[MAX], i, j, k, start;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num);

    if (num > MAX) {
        printf("Error: Number of vertices exceeds the maximum limit of %d.\n", MAX);
        return 1;
    }

    // Initialize visited array and adjacency matrix
    for (i = 0; i < num; i++) {
        visited[i] = 0;
        for (j = 0; j < num; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (as pairs of vertices). Enter -1 -1 to stop:\n");
    while (1) {
        printf("Edge (from to): ");
        scanf("%d %d", &j, &k);

        if (j == -1 && k == -1) {
            break;
        }

        if (j < 0 || k < 0 || j >= num || k >= num) {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", num - 1);
            continue;
        }

        if (j == k) {
            printf("Self-loops are not allowed. Please enter two different vertices.\n");
            continue;
        }

        graph[j][k] = graph[k][j] = 1; // Add edge to adjacency matrix
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= num) {
        printf("Invalid starting vertex. Please enter a value between 0 and %d.\n", num - 1);
        return 1;
    }

    printf("DFS Traversal starting from vertex %d:\n", start);
    dfs(num, visited, start);
    printf("END\n");

    return 0;
}
// depth first search