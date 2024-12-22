#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 100

struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES];
};

void initializeGraph(struct Graph *G, int vertices) {
    G->vertices = vertices;
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            G->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *G, int source, int destination) {
    if (source >= 0 && source < G->vertices && destination >= 0 && destination < G->vertices) {
        G->adjacencyMatrix[source][destination] = 1;
    } else {
        printf("Invalid edge: %d -> %d\n", source, destination);
    }
}

void DFS(struct Graph *G, int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < G->vertices; i++) {
        if (G->adjacencyMatrix[start][i] == 1 && !visited[i]) {
            DFS(G, i, visited);
        }
    }
}

void BFS(struct Graph *G, int start) {
    int queue[MAX_CITIES];
    int front = 0, rear = 0;
    int visited[MAX_CITIES] = {0};
    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < G->vertices; i++) {
            if (G->adjacencyMatrix[current][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    struct Graph G;
    int n, start;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    initializeGraph(&G, n);
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int source, destination;
        printf("Enter edge #%d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&G, source, destination);
    }
    printf("Enter the starting node for DFS/BFS: ");
    scanf("%d", &start);
    printf("DFS traversal starting from node %d: ", start);
    int visitedDFS[MAX_CITIES] = {0};
    DFS(&G, start, visitedDFS);
    printf("\n");
    printf("BFS traversal starting from node %d: ", start);
    BFS(&G, start);
    printf("\n");
    return 0;
}
