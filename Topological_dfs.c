#include <stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int vertices) {
    visited[vertex] = 1; // Mark the current vertex as visited

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, vertices); // Recursive DFS call
        }
    }
    stack[++top] = vertex;
}

void topologicalSort(int graph[MAX][MAX], int vertices) {
    int visited[MAX] = {0}; // Initialize visited array

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, vertices);
        }
    }

    printf("\nTopological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]); // Print stack in reverse order
    }
    printf("\n");
}

// Main function
int main() {
    int graph[MAX][MAX];
    int vertices, i, j;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (Aij):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform Topological Sorting
    topologicalSort(graph, vertices);

    return 0;
}
