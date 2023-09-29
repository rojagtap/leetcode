/*
preorder will always give the root of a subtree
i.e., preorder[0] will always be the root; preorder[1] will be the root of left subtree if exists or else right, and so on
inorder will tell the position of the subtree given by inorder, i.e., if preorder[0] is inorder[2], then inorder[0-2] will be the left subtree and inorder[3-n] will be the right subtree and as mentioned earlier, the roots will be given by preorder as preorder[1] will be left subtree root and preorder[2] will be right subtree root

preorderindex: root index of the next subtree
leftbound: index of inorder indicating the left bound of the current subtree, i.e., the current subtree cannot go outside this range
rightbound: index of inorder indicating the right bound of the current subtree, i.e., the current subtree cannot go outside this range

1. start with the root (preorder[0]) and find its index in inorder
   everything to the left in inorder is the left subtree and vice versa for right
2. we can thus use the inorder index obtained in 1 for getting the range of left subtree and right subtree
3. now recursively. take preorder[1] as the new root but with right limit as inorderindex - 1
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