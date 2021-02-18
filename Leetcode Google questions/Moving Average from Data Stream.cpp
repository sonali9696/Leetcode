class MovingAverage {
private:
	queue<int> q;
	int maxSize;
	double currAvg;
public:
    	/** Initialize your data structure here. */
    MovingAverage(int size) {
		maxSize = size;
		currAvg = 0.0;
    }
    
    double next(int val) {
       	if(q.size() < maxSize)
			currAvg = (double)(currAvg * q.size() + val)/(double)(q.size()+1);
		else
		{
			int elementToRemove = q.front();
			q.pop();
			currAvg = (double)((currAvg * maxSize) - elementToRemove + val)/maxSize;
		}
		
		q.push(val);
		return currAvg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

