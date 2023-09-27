/*
why not got right->right->right?
     1
    / \
   2   3
  /
 4

So the expected output for above tree is [1,3,4]
with the right->right logic, this can't be achieved

basically "Right Side View" means the actual right side view, i.e., rightmost element on each level
so level order traversal
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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q;
        if (root) q.push_back(root);
        
        vector<int> rightside;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                TreeNode *node = q.front();

                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);

                if (i == qsize - 1) rightside.push_back(node->val);
            }
        }
        
        return rightside;
    }
};