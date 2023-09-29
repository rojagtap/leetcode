/*
identical mirror image of https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) inorder_reverse_lookup[inorder[i]] = i;

        int postorderindex = postorder.size() - 1;
        return buildTree(inorder, postorder, postorderindex, 0, inorder.size() - 1);

    }
    
private:
    unordered_map<int, int> inorder_reverse_lookup;
    
    TreeNode* buildTree (vector<int>& inorder, vector<int>& postorder, int& postorderindex, int leftbound, int rightbound) {
        if (leftbound > rightbound) return nullptr;

        TreeNode *node = new TreeNode(postorder[postorderindex]);

        int inorderindex = inorder_reverse_lookup.at(postorder[postorderindex]);

        if (inorderindex + 1 <= rightbound) {
            --postorderindex;
            node->right = buildTree(inorder, postorder, postorderindex, inorderindex + 1, rightbound);
        }
        
        if (inorderindex - 1 >= leftbound) {
            --postorderindex;
            node->left = buildTree(inorder, postorder, postorderindex, leftbound, inorderindex - 1);
        }
        
        return node;
    }

};