/*
reuse the same list and move pointers using 2 additional helper pointers
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode *head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode *merged = head;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
            
            merged = merged->next;
        }
        
        if (list1) {
            merged->next = list1;
        }
        
        if (list2) {
            merged->next = list2;
        }
        
        return head;
    }
};