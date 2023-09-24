/*
split from mid
reverse second half
merge both
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
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) return;
        
        ListNode *next, *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        next = slow->next;
        slow->next = nullptr;
        
        ListNode *mid = reverse(next);
        head = merge(head, mid);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode *prev, *curr = head, *next;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *merged = list1;
        ListNode *marker1, *marker2;
        while (list1 && list2) {
            marker1 = list1->next;
            marker2 = list2->next;

            list1->next = list2;
            list2->next = marker1;
            
            list1 = marker1;
            list2 = marker2;
        }
        
        return merged;
    }
};