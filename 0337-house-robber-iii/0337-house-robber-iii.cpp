/*
level order traversal + max[i] = max(max[i - 1], nums[i] + max[i - 2]) does not work
see the commented solution

recursively alternate between current + current.next.next and current.next nodes take max
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
    int rob(TreeNode* root) {
        if (cache.find(root) != cache.end()) return cache[root];
        if (!root) return 0;
        
        int maxcash = root->val;
        if (root->left) {
            maxcash += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            maxcash += rob(root->right->left) + rob(root->right->right);
        }
        
        maxcash = max(maxcash, rob(root->left) + rob(root->right));
        cache[root] = maxcash;
        return maxcash;
    }
private:
    unordered_map<TreeNode*, int> cache;
};

// // doesnt work for
// //       3
// //     /   \
// //    2     4
// //  /
// // 3       
// // answer is 3 + 4 = 7
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
        
//         int iminus2 = 0, iminus1 = 0, i = 0;
//         while (!q.empty()) {
//             int numsi = 0;
//             int qsize = q.size();
//             for (int _ = 0; _ < qsize; ++_) {
//                 TreeNode *node = q.front();
//                 q.pop();

//                 numsi += node->val;

//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }

//             i = max(iminus1, numsi + iminus2);
//             iminus2 = iminus1;
//             iminus1 = i;
//         }

//         return i;
//     }
// };