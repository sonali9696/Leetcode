//Solution with 26 number code separated by # and starts with #
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> anagramCodes;
        
        int l = strs.size();
        int count[26];
        
        for(string currString : strs)
        {
            memset(count,0,sizeof(count));
            for(char c : currString) count[c-'a']++;
            
            string code = "";
            for(int i=0; i<26; i++)
            {
                code.push_back('#');
                code = code + to_string(count[i]);
            }
            
            if(anagramCodes.find(code) != anagramCodes.end()) anagramCodes[code].push_back(currString);
            else
            {
                vector<string> v = {currString};
                anagramCodes[code] = v;
            }
        }
        
        map<string, vector<string>>::iterator it;
        for(it = anagramCodes.begin(); it != anagramCodes.end(); it++) ans.push_back(it->second);
        
        return ans;
    }
};

//Solution with code 1a2p1l1e for apple, ppale etc.
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramCodes; //eg: 1a2p1l1e is code for apple, ppale etc.
        map<char,int> freqOfLetters;
        
        int l = strs.size();
        for(int i=0; i<l; i++)
        {
            string currString = strs[i];
            int l2 = currString.length();
            for(int j=0; j<l2; j++)
            {
                if(freqOfLetters.find(currString[j]) != freqOfLetters.end()) freqOfLetters[currString[j]]++;
                else freqOfLetters[currString[j]] = 1;
            }
            
            string code = "";
            map<char,int>::iterator it;
            for(it = freqOfLetters.begin(); it != freqOfLetters.end(); it++)
                code = code + it->first + to_string(it->second);
            
            if(anagramCodes.find(code) != anagramCodes.end()) anagramCodes[code].push_back(currString);
            else
            {
                vector<string> v;
                v.push_back(currString);
                anagramCodes[code] = v;
            }
            
            freqOfLetters.clear();
        }
        
        unordered_map<string, vector<string>>::iterator it;
        for(it = anagramCodes.begin(); it != anagramCodes.end(); it++)
        {
            ans.push_back(it->second);
        }        
        
        
        return ans;
    }
};*/