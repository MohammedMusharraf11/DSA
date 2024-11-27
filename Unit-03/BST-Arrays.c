#include <stdio.h>

#define SIZE 10 // Define the size of the binary search tree (array)

// Structure to represent each node in the binary search tree
typedef struct node {
    int data;  // Data value stored in the node
    int flag;  // Flag to indicate if the node is occupied (1 if occupied, 0 if empty)
} NODE;

// Function to perform an in-order traversal of the BST
void inorder(NODE *bst, int i) {
    // Check if the current node is valid and within bounds
    if (bst[i].flag == 1 && i < SIZE) {
        inorder(bst, 2 * i + 1); // Recursive call to traverse the left subtree
        printf("%d ", bst[i].data); // Print the current node's data
        inorder(bst, 2 * i + 2); // Recursive call to traverse the right subtree
    }
}

// Function to insert a new value into the BST
void insert(NODE *bst, int data, int index) {
    if (index >= SIZE) {
        // If index is out of bounds, print an error and return
        printf("\nIndex out of bounds. Insertion is NOT possible.\n");
        return;
    }
    
    if (bst[index].flag == 0) { 
        // Insert data if the current node is empty
        bst[index].data = data;
        bst[index].flag = 1;
    } 
    else if (data < bst[index].data) { 
        // Move to the left child if data is smaller
        insert(bst, data, 2 * index + 1);
    } 
    else if (data > bst[index].data) { 
        // Move to the right child if data is larger
        insert(bst, data, 2 * index + 2);
    } 
    else {
        // Duplicate values are not inserted
        printf("\nDuplicate value. Insertion is NOT possible.\n");
    }
}


int main() {
    int ch, data;
    NODE bst[SIZE] = {}; // Initialize all nodes in the BST with default values (flag = 0)

    // Loop to insert data into the BST
    do {
        printf("\nEnter the data: ");
        scanf("%d", &data); // Read the data to be inserted
        insert(bst, data, 0); // Insert the data starting from the root (index 0)
        printf("\nPress 0 to discontinue: ");
        scanf("%d", &ch); // Check if the user wants to continue
    } while (ch); // Continue until the user enters 0

    // Perform an in-order traversal to display the tree
    printf("\nIn-order traversal of the BST: ");
    inorder(bst, 0);

    return 0; // Exit the program
}
