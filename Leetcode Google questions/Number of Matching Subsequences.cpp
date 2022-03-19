class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //first we can't store freq of occurrences simply
        //as order is important here
        //so we store char, indices of occurences instead
        
        //now note that acc to given constraint
        //words[i].size is very small compared to length of s
        //hence we shouldn't traverse entire s for each words[i] repeatedly
        //so bound ans by words[i].size rather than s.length for each word.
            
        //for doing so, we preprocess s - i.e. create the order map
        //then for each word[i], we see if we have the characters in ordermap
        
        
        vector<vector<int>> orderOfChars(26);
        
        int l = s.length();
        for(int i=0; i<l; i++)
        {
            int charIndex = s[i] - 'a';
            orderOfChars[charIndex].push_back(i);
        }
        
        int ans = 0;
        for(string word: words)
        {
            if(isSubsequence(word, orderOfChars)) ans++;
        }
        return ans;
    }
    
    bool isSubsequence(string word, vector<vector<int>>& orderOfChars)
    {
        int prev = -1; //last occurrence of letter in this
        int n = word.length();
        
        for(auto w: word)
        {
            //find index of occurrence of this letter in s
            //such that it is greater than prev
            //binary search used here for optimizing this
            
            auto it = upper_bound(orderOfChars[w-'a'].begin(), orderOfChars[w-'a'].end(), prev);
            
            if(it == orderOfChars[w-'a'].end()) return false;
            prev = *it;
        }

        return true;  
    }
};