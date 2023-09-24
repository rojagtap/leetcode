/*
create a map of original vs copy
traverse the map and create links
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
        
        Node *ptr = head;
        while (ptr) {
            mapping[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        for (auto entry : mapping) {
            if (entry.first->next) mapping.at(entry.first)->next = mapping.at(entry.first->next);
            if (entry.first->random) mapping.at(entry.first)->random = mapping.at(entry.first->random);
        }
        
        return mapping.find(head) != mapping.end() ? mapping.at(head) : nullptr;
    }
};