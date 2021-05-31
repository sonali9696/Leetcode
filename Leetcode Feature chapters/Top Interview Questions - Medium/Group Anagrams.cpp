class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> anagramCodes; //eg: 1a2p1l1e is code for apple, ppale etc.
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
        
        map<string, vector<string>>::iterator it;
        for(it = anagramCodes.begin(); it != anagramCodes.end(); it++)
        {
            ans.push_back(it->second);
        }        
        
        
        return ans;
    }
};