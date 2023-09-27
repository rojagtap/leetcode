// /*
// level order traversal with passing max of prev with each node as a pair
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
//     int goodNodes(TreeNode* root) {
//         queue<pair<TreeNode*, int>> q;
//         if (root) q.push(make_pair(root, INT_MIN));
        
//         int good = 0;
//         while (!q.empty()) {
//             int qsize = q.size();
//             for (int _ = 0; _ < qsize; ++_) {
//                 pair<TreeNode*, int> front = q.front();
                
//                 q.pop();
//                 if (front.first->left) q.push(make_pair(front.first->left, max(front.second, front.first->val)));
//                 if (front.first->right) q.push(make_pair(front.first->right, max(front.second, front.first->val)));
                
//                 if (front.first->val >= front.second) ++good;
//             }
//         }
        
//         return good;
//     }
// };


/*
recursively pass the current max to the next level
*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        goodNodes(root, INT_MIN);
        
        return good;
    }

private:
    int good = 0;
    
        void goodNodes(TreeNode* root, int maxprev) {
        if (!root) return;
        
        if (root->val >= maxprev) ++good;
        
        goodNodes(root->left, max(maxprev, root->val));
        goodNodes(root->right, max(maxprev, root->val));
    }

};