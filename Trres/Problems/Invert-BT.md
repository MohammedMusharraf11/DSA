# Invert Binary Tree Example

Given function:
```c
struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root) return NULL;

    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left); 
    invertTree(root->right); 
    return root;
}
```
     
      4
     / \
    2   7
   / \ / \
  1  3 6  9

Step-by-Step Recursive Calls and Swaps
Initial call with root node 4:

Swap left and right children of node 4.
New structure after swap:
markdown
Copy code
     4
    / \
   7   2
  / \ / \
 6  9 1  3
Call invertTree on root->left (node 7).
Recursive call with node 7:

Swap left and right children of node 7.
New structure after swap:
markdown
Copy code
     4
    / \
   7   2
  / \ / \
 9  6 1  3
Call invertTree on root->left (node 9).
Recursive call with node 9:

Node 9 has no children, so no swap is performed.
Return to previous call at node 7.
Back to node 7:

Call invertTree on root->right (node 6).
Recursive call with node 6:

Node 6 has no children, so no swap is performed.
Return to previous call at node 4.
Back to root node 4:

Call invertTree on root->right (node 2).
Recursive call with node 2:

Swap left and right children of node 2.
New structure after swap:
markdown
Copy code
     4
    / \
   7   2
  / \ / \
 9  6 3  1
Call invertTree on root->left (node 3).
Recursive call with node 3:

Node 3 has no children, so no swap is performed.
Return to previous call at node 2.
Back to node 2:

Call invertTree on root->right (node 1).
Recursive call with node 1:

Node 1 has no children, so no swap is performed.
Return to previous call at node 4.
Final Inverted Tree Structure
After all recursive calls, the final inverted tree structure is:

markdown
Copy code
      4
     / \
    7   2
   / \ / \
  9  6 3  1
Resulting Tree After Inversion: [4,7,2,9,6,3,1]
markdown
Copy code
      4
     / \
    7   2
   / \ / \
  9  6 3  1
Each recursive call inverts the left and right subtrees, creating a mirror image of the original tree.
