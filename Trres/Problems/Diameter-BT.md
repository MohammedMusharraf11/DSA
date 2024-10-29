```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root, int *diameter) {
    if (!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    // Update the diameter with the larger of the current diameter or the sum of lh and rh
    *diameter = (lh + rh > *diameter) ? lh + rh : *diameter;

    return 1 + (lh > rh ? lh : rh);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    height(root, &diameter);  // Pass the address of diameter
    return diameter;
}
```
