/*

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) inorder_reverse_lookup[inorder[i]] = i;

        int preorderindex = 0;
        return buildTree(preorder, inorder, preorderindex, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> inorder_reverse_lookup;
    
    TreeNode* buildTree (vector<int>& preorder, vector<int>& inorder, int& preorderindex, int leftbound, int rightbound) {
        if (leftbound > rightbound) return nullptr;

        TreeNode *node = new TreeNode(preorder[preorderindex]);

        int inorderindex = inorder_reverse_lookup.at(preorder[preorderindex]);

        if (inorderindex - 1 >= leftbound) {
            ++preorderindex;
            node->left = buildTree(preorder, inorder, preorderindex, leftbound, inorderindex - 1);
        }

        if (inorderindex + 1 <= rightbound) {
            ++preorderindex;
            node->right = buildTree(preorder, inorder, preorderindex, inorderindex + 1, rightbound);
        }
        
        return node;
    }
};