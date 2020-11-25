class Solution {
public:
int splitArray(vector<int>& nums, int m) {
        long long int l = 0, r = 0,mid;
        int n = nums.size();
        for(int i=0; i<n; i++) 
        {
            r += nums[i];
            if(l < nums[i]) l = nums[i];
        }
        //ans between largest num to sum of all numbers
    
        if(m == 1) return r;
        int ans = INT_MAX;

        int numOfSubarrays; //ans is between this
        while(l <= r)
        {
            mid = (l+r)/2;
            numOfSubarrays = 1;

            //check if this is possible
            int pos = 0, currSum = 0;
            while(pos < n)
            {
                currSum += nums[pos];
                if(currSum > mid)
                {
                    currSum = nums[pos];
                    numOfSubarrays++;
                }
                pos++;
            }
            
            if(numOfSubarrays > m) l = mid+1; //this value not possible with m partitions
            else
            {
                r = mid-1;
                if(ans > mid) ans = mid;
            }
        }
        return ans;
	}
};
