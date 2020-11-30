class MinStack {
private:
    stack<int> st;
    stack<int> minTillHere; 
    //at every point, elements under x are unchanged so min is min till x-1 and xth element.
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        int currMin;
        if(!minTillHere.empty()) currMin = minTillHere.top();
        else currMin = x;
        if(currMin < x) minTillHere.push(currMin);
        else minTillHere.push(x);
    }
    
    void pop() {
        if(!st.empty()) st.pop();
        minTillHere.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        return minTillHere.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */