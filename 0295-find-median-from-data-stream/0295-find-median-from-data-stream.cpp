/*
left half will be maxheap
right half will be minheap
so that the top of both heaps will be the middle element(s)
*/
class MedianFinder {
public:
    MedianFinder() {
        length = 0;
    }
    
    void addNum(int num) {
        ++length;
        if (lefthalf.empty() || num <= lefthalf.top()) {
            lefthalf.push(num);
        } else {
            righthalf.push(num);
        }
        
        if (righthalf.size() > lefthalf.size()) {
            int rightmin = righthalf.top(); righthalf.pop();
            lefthalf.push(rightmin);
        } else if (lefthalf.size() - righthalf.size() == 2) {
            int leftmax = lefthalf.top(); lefthalf.pop();
            righthalf.push(leftmax);
        }
    }
    
    double findMedian() {
        if (length & 1) {
            return lefthalf.top();
        } else {
            return (lefthalf.top() + righthalf.top()) / 2.0;
        }
    }

private:
    int length;
    priority_queue<int> lefthalf;
    priority_queue<int, vector<int>, greater<int>> righthalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */