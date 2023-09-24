/*
create a map of original vs copy
traverse the list and create links using the map
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        mapping[nullptr] = nullptr;
        
        Node *ptr = head;
        while (ptr) {
            mapping[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        while (ptr) {
            mapping.at(ptr)->next = mapping.at(ptr->next);
            mapping.at(ptr)->random = mapping.at(ptr->random);
            
            ptr = ptr->next;
        }
        
        return mapping.find(head) != mapping.end() ? mapping.at(head) : nullptr;
    }
};