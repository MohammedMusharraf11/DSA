#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

// Function prototypes
NODE* createnode(int data);
NODE* insertNode(NODE *root, int data);
void inorderTraversal(NODE *root);
void preorderTraversal(NODE *root);
void postorderTraversal(NODE *root);

int main() {
    NODE *root = NULL;
    int choice, data;

    while (1) {
        printf("\n----- Binary Search Tree Menu -----\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
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
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
NODE* createnode(int data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
NODE* insertNode(NODE *root, int data) {
    if (root == NULL) {
        root = createnode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for inorder traversal (Left -> Root -> Right)
void inorderTraversal(NODE *root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for preorder traversal (Root -> Left -> Right)
void preorderTraversal(NODE *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for postorder traversal (Left -> Right -> Root)
void postorderTraversal(NODE *root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
