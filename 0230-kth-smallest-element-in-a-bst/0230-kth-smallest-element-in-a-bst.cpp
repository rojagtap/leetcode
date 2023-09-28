/*
inorder traversal

after left decrement k
if k == 0 stop
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kth;
    }
private:
    int kth = INT_MAX;
    
    void inorder(TreeNode *root, int& k) {
        if (!root) return;
        
        inorder(root->left, k);
        
        --k;
        if (!k) {
            kth = root->val;
            return;
        }

        inorder(root->right, k);
    }
};