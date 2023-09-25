/*
take prev, curr, end pointers
prev will track the previous end
curr will be current head
and end will jump k times for each curr
reverse curr -> .. -> end
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = nullptr, *curr = head, *end = head;
        
        int i;
        while (curr) {
            for (i = 1; i <= k && end; ++i) {
                end = end->next;
            }
            
            if (i <= k && !end) return head;
            
            ListNode *reversed = reverse(curr, end);
            if (prev) prev->next = reversed;
            else head = reversed;
            
            prev = curr;
            curr = end;
        }
        
        return head;
    }
    
private:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *prev, *curr = head, *next;
        
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = end;
        
        return prev;
    }
};