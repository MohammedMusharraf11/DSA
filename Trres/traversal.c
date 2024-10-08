#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
  
    // Empty Tree
    if (root == NULL)
        return;
  
    // Recur on the left subtree
    inorderTraversal(root->left);
  
    // Visit the current node
    printf("%d ", root->data);
  
    // Recur on the right subtree
    inorderTraversal(root->right);
}


void preorderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right); 


}

void postorderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d",root->data);
}

// Function to create a new node
struct Node* newNode(int data) {  
    struct Node* node =
      (struct Node*)malloc(sizeof(struct Node));
  
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: "); 
    preorderTraversal(root);
    printf("\n");
    return 0;
}
