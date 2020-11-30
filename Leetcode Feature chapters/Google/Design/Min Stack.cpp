class MinStack {
class MinStack {
private:
    stack<pair<int,int> > st;
    //at every point, elements under x are unchanged so min is min till x-1 and xth element.
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        int currMin;
        if(!st.empty()) currMin = st.top().second;
        else currMin = x;
        if(currMin < x) st.push(make_pair(x,currMin));
        else st.push(make_pair(x,x));
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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