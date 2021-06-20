class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp(l);
        int longest = 1;
        dp[0] = 1;
        
        for(int i=1; i<l; i++)
        {
            dp[i] = 1;
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            longest = max(longest, dp[i]);
        }
        
        return longest;
    }
};