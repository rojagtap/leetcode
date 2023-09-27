/*
pop all nodes in the level and add to result array
add the children of popped if present
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        if (root) q.push_back(root);

        vector<vector<int>> traversal;
        while (!q.empty()) {
            int qsize = q.size();
            vector<int> level;
            for (int _ = 0; _ < qsize; ++_) {
                TreeNode *node = q.front();
                
                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
                
                level.push_back(node->val);
            }

            traversal.push_back(level);
        }
        
        return traversal;
    }
};