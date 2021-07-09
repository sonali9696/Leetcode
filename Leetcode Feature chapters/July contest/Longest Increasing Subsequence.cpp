//optimal - O(n log n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > sub[sub.size()-1]) sub.push_back(nums[i]); //continue current subsequence
            else
            {
                //find the element in current subsequence which is just > nums[i] and replace it with nums[i]
                //this will open possibilities of growing this subseq if future elements are > nums[i]
                //but < than the number replaced
                
                //optimal - binary search to find the element
                auto left = lower_bound(sub.begin(), sub.end(), nums[i]); //=nums[i] or just > than it
                int index = left - sub.begin();
                sub[index] = nums[i];
            }
        }
        
        return sub.size();
    }
};

/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int longestIncSubsequenceLen = 1;
        vector<int> dp(n,1); //base case - subsequence starting and ending with itself so size=1
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++) 
            {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);  
            }
            longestIncSubsequenceLen = max(longestIncSubsequenceLen, dp[i]);
        }
        
        return longestIncSubsequenceLen;
    }
};*/