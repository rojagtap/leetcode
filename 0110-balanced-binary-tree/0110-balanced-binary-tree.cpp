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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int left = get_height(root->left);
        int right = get_height(root->right);

        return isBalanced(root->left) && isBalanced(root->right) && abs(left - right) <= 1;
    }
    
private:
    int get_height(TreeNode* root) {
        if (!root) return 0;
        
        return max(get_height(root->left), get_height(root->right)) + 1;
    }
};