#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct Node {
    int data; // Data stored in the node
    struct Node *left; // Pointer to the left child
    struct Node *right; // Pointer to the right child
} NODE;

// Function to create a new node
NODE *createNode(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = data; // Assign data
    newNode->left = newNode->right = NULL; // Initialize left and right children to NULL
    return newNode;
}

// Function to insert a node in the BST
NODE *insertNode(NODE *root, int data) {
    if (root == NULL) {
        return createNode(data); // Create a new node if the tree is empty
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data); // Insert into the left subtree
    } else if (data > root->data) {
        root->right = insertNode(root->right, data); // Insert into the right subtree
    }
    return root;
}

// Function to find the minimum value node in the BST
NODE *findMin(NODE *root) {
    // Explanation: The minimum value in a BST is found by moving as far left as possible.
    while (root->left != NULL) {
        root = root->left; // Keep going left until you reach the leaf
    }
    return root; // Return the leftmost node
}

// Function to delete a node in the BST
NODE *deleteNode(NODE *root, int data) {
    if (root == NULL) {
        // Base case: If the tree is empty or the node is not found
        return root;
    }

    // Recursively traverse the tree to find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data); // Look in the left subtree
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // Look in the right subtree
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            // Case 1: Node with only a right child or no child
            NODE *temp = root->right; // Store the right child
            free(root); // Free memory of the current node
            return temp; // Replace the current node with its right child
        } else if (root->right == NULL) {
            // Case 2: Node with only a left child
            NODE *temp = root->left; // Store the left child
            free(root); // Free memory of the current node
            return temp; // Replace the current node with its left child
        }

        // Case 3: Node with two children
        // Explanation:
        // - Find the inorder successor (the smallest value in the right subtree).
        // - Replace the current node's value with the inorder successor's value.
        // - Recursively delete the inorder successor.
        NODE *temp = findMin(root->right); // Find the smallest node in the right subtree
        root->data = temp->data; // Replace current node's data with the successor's data
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }

    return root; // Return the (potentially updated) root node
}

// Function to perform inorder traversal of the BST
void inorderTraversal(NODE *root) {
    if (root != NULL) {
        inorderTraversal(root->left); // Visit left subtree
        printf("%d ", root->data); // Print the root node's data
        inorderTraversal(root->right); // Visit right subtree
    }
}

// Main function to test the above functions
int main() {
    NODE *root = NULL;

    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the given tree: ");
    inorderTraversal(root);
    printf("\n");

    // Test deletion scenarios
    printf("Delete 20\n");
    root = deleteNode(root, 20); // Node with no child
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 30\n");
    root = deleteNode(root, 30); // Node with one child
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 50\n");
    root = deleteNode(root, 50); // Node with two children
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
