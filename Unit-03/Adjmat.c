#include <stdio.h>

#define V 4  // Number of vertices in the graph

// Function to add an undirected edge between vertices i and j
void addEdge(int mat[V][V], int i, int j) {
    mat[i][j] = 1;  // Mark an edge from vertex i to vertex j
    mat[j][i] = 1;  // Mark an edge from vertex j to vertex i (undirected) ---> just comment this line for directed graph
}

// Function to display the adjacency matrix of the graph
void display(int mat[V][V]) {
    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", mat[i][j]);  
        }
        printf("\n");  
    }
}

int main() {
    int mat[V][V] = {0};  // Initialize a V x V adjacency matrix with all zeros
    
    // Add undirected edges to the graph
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);
    
    
    display(mat);
    
    return 0;  
}