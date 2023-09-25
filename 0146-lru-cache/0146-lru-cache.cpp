/*
use doubly linked list as we need to remove from anywhere in the queue and place it to the tail
*/

class Node {
public:
    int key;
    int val;
    Node *next, *prev;
    
    Node (int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node *node = remove(cache.at(key));
            append(node);
            return node->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *node = remove(cache.at(key));
            append(node);
            cache.at(key)->val = value;
        } else {
            Node *node = new Node(key, value);
            if (capacity == 0) {
                Node *lru = head;
                lru = remove(lru);
                cache.erase(lru->key);
                delete lru;
            } else {
                --capacity;
            }
            
            append(node);
            cache[key] = node;
        }
    }
    
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head = nullptr, *tail = nullptr;
    
    Node* remove (Node *node) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        
        if (head == node) head = head->next;
        if (tail == node) tail = tail->prev;
        
        node->next = nullptr;
        node->prev = nullptr;
        
        return node;
    }
    
    void append (Node *node) {
        if (head) {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        } else {
            head = node;
            tail = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */