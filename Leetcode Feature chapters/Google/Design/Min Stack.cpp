class MinStack {
private:
    stack<int> st;
    stack<pair<int,int>> minTracker;
    int index;
    //at every point, elements under x are unchanged so min is min till x-1 and xth element.
    //here we aren't pushing to minTracker if no new min found, except when x=latest min because 
    //we min might occur at 2 diff points in stack, we don't want to pop it and then give wrong min for other elements
    //eg: {6,6} are the 2 latest pushes to stack. If we store 6 only once in min, then for 2nd pop it will give some other min as 6 is already popped.
    //now we are also storing which pos the min was found so that we don't have to store duplicate values repeatedly
    
public:
    /** initialize your data structure here. */
    MinStack() {
        index = -1;
    }
    
    void push(int x) { 
        index++;
        int currMin;
        if(!minTracker.empty()) currMin = minTracker.top().first;
        else currMin = x;
        
        if(currMin >= x) minTracker.push(make_pair(x,index)); 
        //if stack is empty, x will be pushed by above logic
        //else currMin already in min stack correctly
        
        st.push(x);
    }
    
    void pop() {
        if(!st.empty()) 
        {
            if(index == minTracker.top().second) minTracker.pop();
            st.pop();
        }
        index--;
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minTracker.empty()) return -1;
        return minTracker.top().first;
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