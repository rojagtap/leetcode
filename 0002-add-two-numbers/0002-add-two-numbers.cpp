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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = sum / BASE;
        ListNode *addition = new ListNode(sum % BASE);

        l1 = l1->next;
        l2 = l2->next;
        
        ListNode *head = addition;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            addition->next = new ListNode(sum % BASE);
            carry = sum / BASE;
            
            l1 = l1->next;
            l2 = l2->next;
            addition = addition->next;
        }
        
        while (l1) {
            int sum = l1->val + carry;
            addition->next = new ListNode(sum % BASE);
            carry = sum / BASE;
            l1 = l1->next;
            
            addition = addition->next;
        }
        
        while (l2) {
            int sum = l2->val + carry;
            addition->next = new ListNode(sum % BASE);
            carry = sum / BASE;
            l2 = l2->next;
            addition = addition->next;
        }
        
        if (carry) {
            addition->next = new ListNode(carry);
        }
        
        return head;
    }
    
private:
    const int BASE = 10;
};