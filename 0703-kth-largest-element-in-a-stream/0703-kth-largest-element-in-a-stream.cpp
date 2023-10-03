/*
default is maxheap so create a minheap using -ve values (or use the greater<int> comparator)
add to heap such that if size == k + 1, then pop the smallest element
this way the top of heap is always the kth largest element
overall complexity is logk
*/
class KthLargest {
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for (auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        topk.push(val);
        if (topk.size() == k + 1) {
            topk.pop();
        }
        
        return topk.top();
    }
    
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> topk;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */