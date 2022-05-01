class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp of bool type
        //checks if substring is true or not i.e. if it can be divided into words of dict
        //from there is new word formed until current iter
        //if yes then true else false
        
        int n = s.length();
        vector<bool> dp(n+1);
        set<string> wordDictSet(wordDict.begin(), wordDict.end()); //for faster find
        dp[0] = true;
        
        for(int i=1; i<=n; i++) //index of dp
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] == true && wordDictSet.find(s.substr(j,i-j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
        
    }
};