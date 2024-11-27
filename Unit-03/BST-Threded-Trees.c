#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Threaded Binary Search Tree
typedef struct Node {
    int data;           // Data stored in the node
    struct Node *left;  // Pointer to the left child or inorder predecessor
    struct Node *right; // Pointer to the right child or inorder successor
    int lthread;        // Left thread indicator (1: thread, 0: child)
    int rthread;        // Right thread indicator (1: thread, 0: child)
} NODE;

// Function to create a new node
NODE* createNode(int data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->lthread = 1;  // By default, threads are present
    newNode->rthread = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the TBST
NODE* insertNode(NODE *root, int data) {
    NODE *current = root, *parent = NULL, *newNode;
    newNode = createNode(data);

    if (root == NULL) {  // Tree is empty
        return newNode;
    }

    // Find the position to insert the new node
    while (current != NULL) {
        parent = current;
        if (data < current->data) {  // Move to the left subtree
            if (current->lthread == 0)  // Not a thread, follow the child
                current = current->left;
            else
                break;  // Found position to insert
        } else if (data > current->data) {  // Move to the right subtree
            if (current->rthread == 0)  // Not a thread, follow the child
                current = current->right;
            else
                break;  // Found position to insert
        } else {  // Duplicate keys are not allowed
            printf("Duplicate key: %d\n", data);
            return root;
        }
    }

    // Insert the new node at the found position
    if (data < parent->data) {
        newNode->left = parent->left;  // Inorder predecessor
        newNode->right = parent;      // Inorder successor
        parent->left = newNode;
        parent->lthread = 0;          // Left child exists now
    } else {
        newNode->left = parent;       // Inorder predecessor
        newNode->right = parent->right; // Inorder successor
        parent->right = newNode;
        parent->rthread = 0;          // Right child exists now
    }

    return root;
}

// Function to find the inorder successor of a node
NODE* inorderSuccessor(NODE *node) {
    if (node->rthread == 1)  // If it's a thread, return the successor
        return node->right;

    // Otherwise, move to the leftmost child of the right subtree
    node = node->right;
    while (node->lthread == 0)
        node = node->left;

    return node;
}

// Function to perform inorder traversal of the TBST
void inorderTraversal(NODE *root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    // Move to the leftmost node
    NODE *current = root;
    while (current->lthread == 0)
        current = current->left;

    // Traverse the tree using threads
    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
    printf("\n");
}

// Main function to test the Threaded Binary Search Tree
int main() {
    NODE *root = NULL;
    int data, choice;

    do {
        // Insert a node into the tree
        printf("\nEnter the data to insert: ");
        scanf("%d", &data);
        root = insertNode(root, data);

        printf("To continue inserting, press 1: ");
        scanf("%d", &choice);
    } while (choice == 1);

    // Display the inorder traversal of the tree
    printf("\nInorder traversal of the TBST: ");
    inorderTraversal(root);

    return 0;
}
