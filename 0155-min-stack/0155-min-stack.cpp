class MinStack {
public:
    vector<int> minStack;
    vector<int> minValues;

    MinStack() {
        minValues.push_back(INT_MAX);
    }
    
    void push(int val) {
        if (val <= minValues.back()) {
            minValues.push_back(val);
        }
        minStack.push_back(val);
    }
    
    void pop() {
        if (minValues.back() == minStack.back()) {
            minValues.pop_back();
        }
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return minValues.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */