/*
keep send pointer to height down the tree and update it at the end
this way we dont have to re calculate or cache heights for each level
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int left = 0, right = 0;
        bool balanced = isBalanced(root->left, left) && isBalanced(root->right, right) && abs(right - left) <= 1;
        
        height = max(left, right) + 1;
        
        return balanced;
    }
};

// /*
// for all nodes do abs(left height - right height) and check if diff > 1
// also return alongside isbalanced(left) && isbalanced(right) && isbalanced(this)
// */

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;

//         int left = get_height(root->left);
//         int right = get_height(root->right);

//         return isBalanced(root->left) && isBalanced(root->right) && abs(left - right) <= 1;
//     }
    
// private:
//     unordered_map<TreeNode*, int> cache;
    
//     int get_height(TreeNode* root) {
//         if (cache.find(root) != cache.end()) return cache.at(root);

//         int result;
//         if (!root) result = 0;
//         else result = max(get_height(root->left), get_height(root->right)) + 1;
        
//         cache[root] = result;
//         return result;
//     }
// };