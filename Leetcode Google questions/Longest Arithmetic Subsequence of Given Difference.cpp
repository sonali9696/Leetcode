//for faster performance can create fixed size array using constraints-
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<int>dp(40005);//an alternative of map to improve performance
        int ans=1;
        for(auto x:arr){
            //for neg value add 20000
            dp[x+20000]=dp[x+20000-diff]+1;
            ans=max(ans,dp[x+20000]);
        }
        return ans;
    }
};

/*class Solution {
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
            auto it = dp.find(prevElement);
            if(it == dp.end())
            {
                dp[arr[i]] = 1;//starting new sequence
            }
            else
            {
                //increase length
                dp[arr[i]] = it->second + 1;
                maxLength = max(maxLength, dp[arr[i]]);
            }
        }
        
        return maxLength;
    }
};*/