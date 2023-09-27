/*
traverse the tree and if current root.val == subroot.val then check if isSame (https://leetcode.com/problems/same-tree/)
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        bool issub = false;
        if (root->val == subRoot->val) issub = isSame(root, subRoot);

        return issub || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        return isSame(p->left, q->left) && isSame(p->right, q->right) && p->val == q->val;
    }
};