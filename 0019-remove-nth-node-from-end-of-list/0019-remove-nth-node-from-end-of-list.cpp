/*
calculate size by going to the end
then go to (size - n)th node with a prev pointer
prev->next = nth->next
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        int sz = 0;
        ListNode *end = head;
        while (end) {
            ++sz;
            end = end->next;
        }
        
        if (sz == n) return head->next;
        
        int jumps = sz - n;
        ListNode *prev, *nth = head;
        while (jumps > 0) {
            --jumps;
            prev = nth;
            nth = nth->next;
        }
        
        prev->next = nth->next;
        
        return head;
    }
};