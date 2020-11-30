class MinStack {
private:
    stack<int> st;
    stack<int> minTracker;
    //at every point, elements under x are unchanged so min is min till x-1 and xth element.
    //here we aren't pushing to minTracker if no new min found, except when x=latest min because 
    //we min might occur at 2 diff points in stack, we don't want to pop it and then give wrong min for other elements
    //eg: {6,6} are the 2 latest pushes to stack. If we store 6 only once in min, then for 2nd pop it will give some other min as 6 is already popped.
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {        
        int currMin;
        if(!minTracker.empty()) currMin = minTracker.top();
        else currMin = x;
        if(currMin >= x) minTracker.push(x); //else currMin already in min stack correctly
        //if stack is empty, x will be pushed by above logic

        st.push(x);
    }
    
    void pop() {
        if(!st.empty()) 
        {
            if(st.top() == minTracker.top()) minTracker.pop();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minTracker.empty()) return -1;
        return minTracker.top();
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