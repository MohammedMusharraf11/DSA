#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices in the graph

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

// ------------------- Adjacency List Functions -------------------

// Add an edge to the adjacency list
void addEdgeList(NODE* adj[], int i, int j) {
    NODE* newNode = createNode(j);
    newNode->next = adj[i];
    adj[i] = newNode;

    // Uncomment the next two lines if the graph is undirected
    newNode = createNode(i);
    newNode->next = adj[j];
    adj[j] = newNode;
}

// Display the adjacency list
void displayList(NODE* adj[]) {
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        NODE* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ------------------- Adjacency Matrix Functions -------------------

// Add an edge to the adjacency matrix
void addEdgeMatrix(int mat[V][V], int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1;  // Comment this line for a directed graph
}

// Display the adjacency matrix
void displayMatrix(int mat[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
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

// ------------------- BFS Using Adjacency Matrix -------------------
void bfsMatrix(int mat[V][V], int source) {
    int *queue = (int *)calloc(V, sizeof(int));
    int *visited = (int *)calloc(V, sizeof(int));

    enqueue(queue, source);
    visited[source] = 1;
    printf("\nBFS Traversal (Matrix):\n");

    while (!isempty(queue)) {
        int u = dequeue(queue);
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (mat[u][v] == 1 && visited[v] == 0) {
                enqueue(queue, v);
                visited[v] = 1;
            }
        }
    }

    free(queue);
    free(visited);
}

// ------------------- BFS Using Adjacency List -------------------
void bfsList(NODE* adj[], int source) {
    int *queue = (int *)calloc(V, sizeof(int));
    int *visited = (int *)calloc(V, sizeof(int));

    enqueue(queue, source);
    visited[source] = 1;
    printf("\nBFS Traversal (List):\n");

    while (!isempty(queue)) {
        int u = dequeue(queue);
        printf("%d ", u);

        NODE* temp = adj[u];
        while (temp != NULL) {
            int v = temp->data;
            if (visited[v] == 0) {
                enqueue(queue, v);
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
}

// ------------------- Main Function -------------------
int main() {
    // Adjacency Matrix
    int mat[V][V] = {0};  // Initialize all entries to 0
    addEdgeMatrix(mat, 0, 1);
    addEdgeMatrix(mat, 0, 2);
    addEdgeMatrix(mat, 1, 2);
    addEdgeMatrix(mat, 2, 3);
    displayMatrix(mat);

    // Adjacency List
    NODE* adj[V] = {NULL};  // Initialize all vertices to NULL
    addEdgeList(adj, 0, 1);
    addEdgeList(adj, 0, 2);
    addEdgeList(adj, 1, 2);
    addEdgeList(adj, 2, 3);
    displayList(adj);

    // Perform BFS
    int source;
    printf("\nEnter the source vertex for BFS: ");
    scanf("%d", &source);

    bfsMatrix(mat, source);
    bfsList(adj, source);

    return 0;
}
