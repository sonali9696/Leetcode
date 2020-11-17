class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0], currsum = nums[0];
        for(int i=1; i<n; i++)
        {
            if(currsum + nums[i] < nums[i]) currsum = nums[i];
            else currsum = currsum + nums[i];
            if(maxsum < currsum) maxsum = currsum;
        }
        return maxsum;
    }
};

