class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longestSubstringLength = 0, l = s.length(), count = 0;
        
        map<char, int> indexOfCharactersMap;
        
        for(int i = 0; i < l; i++)
        {
            if(indexOfCharactersMap.find(s[i]) == indexOfCharactersMap.end() || indexOfCharactersMap[s[i]] == -1)
            {
                indexOfCharactersMap[s[i]] = i;
                count++;
            }
            else
            {
                int oldIndex = indexOfCharactersMap[s[i]];
                
                count = i - oldIndex;
                indexOfCharactersMap[s[i]] = i;
                int j = oldIndex-1;
                map<char, int>::iterator it;
                
                for(it = indexOfCharactersMap.begin(); it != indexOfCharactersMap.end(); ++it)
                {
                    if(it->second < oldIndex) indexOfCharactersMap[it->first] = -1;
                }
            }
            
            if(count > longestSubstringLength) longestSubstringLength = count;
        }
        
        return longestSubstringLength;
    }
};