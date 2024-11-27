#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// ------------------- Node Structure for Adjacency List -------------------
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node NODE;

// Function to create a new node
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ------------------- Graph Structure -------------------
typedef struct {
    int vertex;          // Number of vertices
    NODE* adjList[MAX];  // Adjacency list
} GRAPH;

// ------------------- Graph Functions -------------------

// Function to initialize the graph
void create_adjList(GRAPH* g) {
    printf("Enter the number of vertices: ");
    scanf("%d", &(g->vertex));

    for (int i = 0; i < g->vertex; i++) {
        g->adjList[i] = NULL;  // Initialize adjacency list to NULL
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        NODE* newNode = createNode(v);
        newNode->next = g->adjList[u];
        g->adjList[u] = newNode;

        // For undirected graph, add reverse edge
        newNode = createNode(u);
        newNode->next = g->adjList[v];
        g->adjList[v] = newNode;
    }
}

// Function to display the adjacency list
void display_adjList(GRAPH* g) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < g->vertex; i++) {
        printf("%d: ", i);
        NODE* temp = g->adjList[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ------------------- Queue Operations -------------------
int f = -1, r = -1;  // Front and Rear pointers

int isempty(int *q) {
    return (f == -1 && r == -1);
}

void enqueue(int *q, int data) {
    if (isempty(q)) 
        f++;
    q[++r] = data;
}

int dequeue(int *q) {
    int d = q[f];
    if (f == r) {  // One element condition
        f = r = -1;
    } else {
        f++;
    }
    return d;
}

// ------------------- BFS Functions -------------------

// BFS to check if the graph is connected
bool bfs_is_connected(GRAPH* g, int source) {
    int *queue = (int *)calloc(g->vertex, sizeof(int));
    int *visited = (int *)calloc(g->vertex, sizeof(int));

    enqueue(queue, source);
    visited[source] = 1;
    int count = 1;

    while (!isempty(queue)) {
        int u = dequeue(queue);

        NODE* temp = g->adjList[u];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                enqueue(queue, v);
                visited[v] = 1;
                count++;
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
    return count == g->vertex;
}

// BFS to check for cycles
bool bfs_contains_cycle(GRAPH* g, int source) {
    int *queue = (int *)calloc(g->vertex, sizeof(int));
    int *visited = (int *)calloc(g->vertex, sizeof(int));
    int *parent = (int *)calloc(g->vertex, sizeof(int));

    for (int i = 0; i < g->vertex; i++) parent[i] = -1;

    enqueue(queue, source);
    visited[source] = 1;

    while (!isempty(queue)) {
        int u = dequeue(queue);

        NODE* temp = g->adjList[u];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                enqueue(queue, v);
                visited[v] = 1;
                parent[v] = u;
            } else if (parent[u] != v) {
                free(queue);
                free(visited);
                free(parent);
                return true;  // Cycle detected
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
    free(parent);
    return false;
}

// ------------------- Main Function -------------------
int main() {
    GRAPH g;

    create_adjList(&g);  // Initialize the graph
    display_adjList(&g); // Display the adjacency list

    int source;
    printf("\nEnter the source vertex for BFS: ");
    scanf("%d", &source);

    if (bfs_is_connected(&g, source)) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
    }

    if (bfs_contains_cycle(&g, source)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain any cycles.\n");
    }

    return 0;
}
