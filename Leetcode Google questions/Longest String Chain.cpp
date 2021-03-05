class Solution {
public:
	static bool compareStrings(const string &a, const string &b){
		return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
       	sort(words.begin(), words.end(), compareStrings); //can use bucket sort
        unordered_map<string, int> dp; //words, length of chain upto that word
		int lengthOfLongestChain = 1;
        if(words.size() == 0 || words.size() == 1) return words.size();	

		for(string w : words)
		{
			int l = w.length();
			dp[w] = 1;
			for(int i=0; i<l; i++){
				string tempWord = w.substr(0,i) + w.substr(i+1); //w without w[i]
				if(dp.find(tempWord) != dp.end()) dp[w] = max(dp[w], dp[tempWord]+1);
            }
            lengthOfLongestChain = max(lengthOfLongestChain, dp[w]);
		}
 		return lengthOfLongestChain;
    }
};

//Using bucket sort- (consumes more space)
/*class Solution {
public:

    vector<string> findAllWords(string &a)
    {
        vector<string> vec;
        for (int i=0; i<a.size(); ++i)
        {
            vec.push_back(a.substr(0, i) + a.substr(i+1, a.size()-i-1));
        }
        return vec;
    }
    
    int longestStrChain(vector<string>& words)
    {
        // Divides given word in 17 levels, according to their word length.
        vector<vector<string>> levels(17);
        for (auto &word : words)    levels[word.size()].push_back(word);
        
        unordered_map<string, int> mp;
        for (auto word: words)  mp[word] = 1;
        
        int ans = 1;
        for (int i=2; i<=16; ++i)
        {
            for (int j=0; j<levels[i].size(); ++j)
            {
                vector<string> diffWords = findAllWords(levels[i][j]);
                
                for (auto word: diffWords)
                {
                    if (mp.find(word) != mp.end())  mp[levels[i][j]] = max(mp[word] + 1, mp[levels[i][j]]);
                }
                
                ans = max (ans, mp[levels[i][j]]);
            }
        }
        
        return ans;
    }
};*/


