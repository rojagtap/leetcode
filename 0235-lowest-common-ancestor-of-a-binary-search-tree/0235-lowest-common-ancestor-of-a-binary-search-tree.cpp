/*
in a bst for any node all values < node.val go to left and greater go to right

so if we traverse with p and q together, the point at which they diverge is the lca
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};