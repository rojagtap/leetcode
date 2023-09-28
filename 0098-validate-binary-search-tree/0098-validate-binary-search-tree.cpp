/*
flat bst in inorder is a sorted array (since binary search is done on a sorted array)
each prev element < next in a sorted array
traverse in inorder and see if at any point next < prev if yes then false
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
    bool isValidBST(TreeNode* root) {
        bool isleft = root->left ? isValidBST(root->left) : true;
        if (!isleft) return false;
        
        bool isthis = root->val > prev;
        if (!isthis) return false;
        prev = root->val;
        
        bool isright = root->right ? isValidBST(root->right) : true;
        if (!isright) return false;
        
        return isleft && isthis && isright;
    }
    
    
private:
    long prev = LONG_MIN;
};