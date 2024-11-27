#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices
#define MAX 100  // Maximum vertices for DFS

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
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// ------------------- DFS for Adjacency Matrix -------------------

void dfsMatrix(int mat[V][V], int visited[], int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (mat[start][i] == 1 && visited[i] == 0) {
            dfsMatrix(mat, visited, i);
        }
    }
}

// ------------------- DFS for Adjacency List -------------------

void dfsList(NODE* adj[], int visited[], int start) {
    printf("%d ", start);
    visited[start] = 1;

    NODE* temp = adj[start];
    while (temp != NULL) {
        if (visited[temp->data] == 0) {
            dfsList(adj, visited, temp->data);
        }
        temp = temp->next;
    }
}

// ------------------- Main Function -------------------
int main() {
    // Adjacency Matrix
    int mat[V][V] = {0};
    addEdgeMatrix(mat, 0, 1);
    addEdgeMatrix(mat, 0, 2);
    addEdgeMatrix(mat, 1, 2);
    addEdgeMatrix(mat, 2, 3);

    printf("Adjacency Matrix:\n");
    displayMatrix(mat);

    int visitedMatrix[V] = {0};
    printf("DFS using Adjacency Matrix (starting from vertex 0): ");
    dfsMatrix(mat, visitedMatrix, 0);
    printf("\n");

    // Adjacency List
    NODE* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;  // Initialize adjacency list
    }
    addEdgeList(adj, 0, 1);
    addEdgeList(adj, 0, 2);
    addEdgeList(adj, 1, 2);
    addEdgeList(adj, 2, 3);

    printf("\nAdjacency List:\n");
    displayList(adj);

    int visitedList[V] = {0};
    printf("DFS using Adjacency List (starting from vertex 0): ");
    dfsList(adj, visitedList, 0);
    printf("\n");

    return 0;
}
