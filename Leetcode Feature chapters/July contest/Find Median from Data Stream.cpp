//use two heaps -> first half (smaller elements) is stored in max heap, second half is stored in min heap
//and heaps are balanced i.e. size is equal or difference is 1
//if sum of the sizes is odd then top of the bigger heap is median
//else median is mean of the two tops.

class MedianFinder {
private:
    priority_queue<int> low;//max heap
    priority_queue<int, vector<int>, greater<int> > high; //min heap
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        //first add element to low
        //to balance, push out low's head and add to high
        //IF this creates size of high > size of low, then move high's head to low
        
        low.push(num);
        high.push(low.top());
        low.pop();

        if(high.size() > low.size())
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        //by the pushing process we are maintaining low as the bigger heap
        if(low.size() > high.size()) return low.top();
        else return (double)((low.top()+high.top())/2.0); //Note: DON'T DIV BY JUST 2 AS IT WILL GIVE WRONG VALUE DUE TO INT TRUNCATION. NEED TO USE 2.0 or *0.5
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */