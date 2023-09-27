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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root) q.push(make_pair(root, INT_MIN));
        
        int good = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int _ = 0; _ < qsize; ++_) {
                pair<TreeNode*, int> front = q.front();
                
                q.pop();
                if (front.first->left) q.push(make_pair(front.first->left, max(front.second, front.first->val)));
                if (front.first->right) q.push(make_pair(front.first->right, max(front.second, front.first->val)));
                
                if (front.first->val >= front.second) ++good;
            }
        }
        
        return good;
    }
};