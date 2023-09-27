/*
keep a maxlen variable
update it for each node
return the max(left, right) + 1 for top node
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
    int diameterOfBinaryTree(TreeNode* root) {
        get_diameter(root);
        
        return maxlen;
    }

private:
    int maxlen = 0;
    
    int get_diameter(TreeNode* root) {
        if (!root) return 0;
        
        int left = get_diameter(root->left);
        int right = get_diameter(root->right);
        
        maxlen = max(maxlen, left + right);
        return max(left, right) + 1;
    }
};