#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the Binary Search Tree (BST)
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

// Function to create a new node
NODE* createNode(int data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
NODE* insertNode(NODE *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value in a BST
int findMin(NODE *root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    NODE *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find the maximum value in a BST
int findMax(NODE *root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    NODE *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// Function to calculate the height of the BST
int findHeight(NODE *root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }
    else if(root->left == NULL && root->right == NULL) {
        return 0; // Height of a tree with only one node is 0
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

// Function to count the number of leaves in the BST
int countLeaves(NODE *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Leaf node
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// Function to calculate the depth of a given node
int findDepth(NODE *root, int key, int depth) {
    if (root == NULL) {
        return -1; // Key not found
    }
    if (root->data == key) {
        return depth;
    }
    if (key < root->data) {
        return findDepth(root->left, key, depth + 1);
    } else {
        return findDepth(root->right, key, depth + 1);
    }
}

// Menu-driven main function
int main() {
    NODE *root = NULL;
    int choice, data, key;

    while (1) {
        printf("\n----- Binary Search Tree Menu -----\n");
        printf("1. Insert Node\n");
        printf("2. Find Minimum Value\n");
        printf("3. Find Maximum Value\n");
        printf("4. Find Height of the Tree\n");
        printf("5. Count Number of Leaves\n");
        printf("6. Find Depth of a Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node with data %d inserted successfully.\n", data);
                break;
            case 2:
                printf("Minimum value in the tree: %d\n", findMin(root));
                break;
            case 3:
                printf("Maximum value in the tree: %d\n", findMax(root));
                break;
            case 4:
                printf("Height of the tree: %d\n", findHeight(root));
                break;
            case 5:
                printf("Number of leaves in the tree: %d\n", countLeaves(root));
                break;
            case 6:
                printf("Enter key to find its depth: ");
                scanf("%d", &key);
                int depth = findDepth(root, key, 0);
                if (depth == -1) {
                    printf("Key %d not found in the tree.\n", key);
                } else {
                    printf("Depth of the node with key %d: %d\n", key, depth);
                }
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
