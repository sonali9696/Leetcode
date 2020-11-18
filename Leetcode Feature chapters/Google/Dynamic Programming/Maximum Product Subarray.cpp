//good test case - 
//[0,-2,-1]
//[0,-2,2,-4]
//[-2,5]
//[-2,-3,-4]
//[-1,-1,0]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int currMax = nums[0], currMin = nums[0], prod = nums[0];
		//minTillNow is for storing -ve result in hopes that a -ve no comes later to make product larger
	
		int n = nums.size();
		if(n == 0) return 0;
		if(n == 1) return prod;

		for(int i=1; i<n; i++)
		{
			int calc1 = currMax*nums[i], calc2 = currMin*nums[i];
			currMax = max(nums[i],max(calc1,calc2));
            currMin = min(nums[i],min(calc1,calc2));
            prod = max(prod, currMax);
		}

		return prod;
    }
};