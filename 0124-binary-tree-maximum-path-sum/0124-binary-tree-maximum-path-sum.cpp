/*
similar to taking subtree sum but the max can be selective i.e.,
max(node, left + node, right + node, left + right + node)
*/

/*
for each subtree calculate the sum and update max
return max sub-subtree sum + root.val as the sum of this subtree
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
    int maxPathSum(TreeNode* root) {
        get_sum(root);
        
        return maxsum;
    }
    
private:
    int maxsum = -1001;
    
    int get_sum (TreeNode* root) {
        if (!root) return 0;
        
        int leftsum = get_sum(root->left);
        int rightsum = get_sum(root->right);
        
        maxsum = max({maxsum, root->val, leftsum + root->val, rightsum + root->val, leftsum + rightsum + root->val});
        
        return max({root->val, leftsum + root->val, rightsum + root->val});
    }
};