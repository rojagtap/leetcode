/*
keep a heap of all list pointers
pop min and push next until all elements are added to the output list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        if (a->val >= b->val) return true;
        else return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> smallest;
        
        ListNode *head = new ListNode();
        ListNode *tail = head;
        
        for (auto& listhead : lists) {
            if (listhead) smallest.push(listhead);
        }
        
        while (!smallest.empty()) {
            ListNode* node = smallest.top();
            smallest.pop();
            
            if (node->next) {
                smallest.push(node->next);
            }
            
            tail->next = node;
            tail = tail->next;
            tail->next = nullptr;
        }
        
        return head->next;
    }
};