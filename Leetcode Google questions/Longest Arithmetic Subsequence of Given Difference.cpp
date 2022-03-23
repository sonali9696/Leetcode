class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; //number, length of subsequence upto this number
        
        dp[arr[0]] = 1;
        int n = arr.size(), maxLength = 1;
        if(n == 0) return 0;
        
        for(int i=1; i<n; i++)
        {
            int prevElement = arr[i] - difference;
            
            //check if this prevElement already exists in map
            if(dp[prevElement])
            {
                //increase length
                dp[arr[i]] = dp[prevElement] + 1;
                maxLength = max(maxLength, dp[arr[i]]);
            }
            else dp[arr[i]] = 1;//starting new sequence
        }
        
        return maxLength;
    }
};