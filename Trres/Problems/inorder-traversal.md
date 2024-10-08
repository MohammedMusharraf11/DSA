[Problem Link](https://leetcode.com/problems/binary-tree-inorder-traversal/?envType=problem-list-v2&envId=binary-tree)
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorderHelper(struct TreeNode* root, int** result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    
    // Traverse the left subtree
    inorderHelper(root->left, result, returnSize);
    
    // Add the root value to the result array
    (*result)[(*returnSize)++] = root->val;
    
    // Traverse the right subtree
    inorderHelper(root->right, result, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Initialize return size to 0
    *returnSize = 0;
    
    // Allocate memory for the result array (you may want to adjust size based on tree depth)
    int* result = (int*)malloc(1000 * sizeof(int));  // Assuming a maximum of 1000 nodes
    
    if (result == NULL) {
        return NULL; // Check for memory allocation failure
    }
    
    // Call the helper function to perform the traversal
    inorderHelper(root, &result, returnSize);
    
    return result; // Return the result array
}
```