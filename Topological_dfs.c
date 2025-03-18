// using adjacency matrix
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




// adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], top = -1;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX]; // Array of pointers to Node, each representing an adjacency list for a vertex

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// DFS function to perform topological sort
void dfs(Node* adjList[MAX], int visited[MAX], int vertex) {
    visited[vertex] = 1; // Mark the current vertex as visited

    // Traverse all the adjacent vertices of the current vertex
    Node* temp = adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(adjList, visited, temp->vertex); // Recursive DFS call
        }
        temp = temp->next;
    }

    stack[++top] = vertex; // Push vertex to stack after visiting all neighbors
}

// Function to perform topological sort
void topologicalSort(Node* adjList[MAX], int vertices) {
    int visited[MAX] = {0}; // Initialize visited array

    // Call DFS on each unvisited vertex
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(adjList, visited, i);
        }
    }

    // Print the topological sorting by popping from the stack
    printf("\nTopological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]); // Print stack in reverse order
    }
    printf("\n");
}

// Main function
int main() {
    int vertices, edges, u, v;

    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adjList[i] = NULL;
    }

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges and build the adjacency list
    printf("Enter the edges (u v) where an edge is from u to v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        // Add edge u -> v to the adjacency list
        Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // Perform Topological Sorting
    topologicalSort(adjList, vertices);

    return 0;
}


