#include <stdio.h>
#include <stdlib.h>
#define V 4

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node NODE;

NODE * createNode(int data){
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge( NODE * adj[], int i , int j){
    NODE * newNode = createNode(j);
    newNode->next = adj[i];
    adj[i] = newNode;
    
    // Comment this lines if its directed
    newNode = createNode(i);
    newNode->next = adj[j];
    adj[j] = newNode;
}

void display(NODE *adj[]){
    for(int i=0;i<V;i++){
        printf("%d: ",i);
        NODE * temp = adj[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    NODE * adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL; // Initialize adjacency list
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    
    display(adj);
    return 0;
}



