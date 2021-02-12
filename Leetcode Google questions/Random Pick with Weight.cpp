/*Explanation of Approach 1:
Think that if we had an array [1,2,3,4,3]. Normal random pickIndex would pick any index from 0 to 4 with equal probability. But we want that index=1 is picked by 2/13 probability, index=0 with 1/13 probability and so on. (13 is sum of weights). To ensure that one way to think of it if we make a larger array (of size 13) where the values are the indices such that index i is repeated w[i] times then if we do a normal rand on this array then index 0 to 12 will be picked randomly with equal probability. 13 index array -> [0, 1,1, 2,2,2, 3,3,3,3, 4,4,4]. So there is a 3/13 chance of picking 2 as 2 is repeated thrice in the new array. 

Now instead of actually constructing this 13 index array, we just know the range of the index of the 13 index array where value = i. Eg:
 - for index=0, range is {0,0}
- index =1, range of indices of the new array is {1,2}
- index=2, range={3,5}
- index=3, range ={6,9}
- index = 4, range = {10,12}

In other words, 
- index=0, range is <1
- index=1, range is <3
- index=2, range is <6
- index = 3, range is < 10
- index = 4, range is < 13

If you notice the above numbers 1,3,6,10,13 - they are cumulative sum. 
The reason this happens is because for every range: right = left + (w[i] - 1) and left is (prev right+1). So if we substitute 2nd equation into 1st. right = (prev right)+w[i]; i.e. keep adding prev sum to current weight.

Thus the cumulative sum is able to implement this.*/
    
class Solution {
private:
	vector<int> cumulativeSum;
	int totalWeight;
    
public:
    Solution(vector<int>& w) {
       	int n = w.size();
		for(int i=0; i<n; i++)
		{
			if(i == 0) cumulativeSum.push_back(w[i]);
			else cumulativeSum.push_back(cumulativeSum[i-1] + w[i]);
		}
		totalWeight = cumulativeSum[n-1];
    }
    
    int pickIndex() {
       	float r = (float)rand()/RAND_MAX;
		int scaledRandomNumber = r*totalWeight; //0-13
		int n = cumulativeSum.size();

		for(int i=0; i<n; i++)
		{
			if(scaledRandomNumber < cumulativeSum[i]) return i;
		}
		return n-1;
    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */