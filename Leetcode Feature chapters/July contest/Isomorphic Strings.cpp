class Solution {
public:
    bool isIsomorphic(string s, string t) {
       //map of chars in s to t
        map<char, char> sToT;
        set<char> charsOfTUsed;
        
        int n = t.length(); //given that length of s= len of t
        for(int i=0; i<n; i++)
        {
            if(sToT.find(s[i]) != sToT.end()) //already mapped
            {
                if(sToT[s[i]] != t[i]) return false; //same mapping to be used
            }
            else //new char
            {
                //first check if t[i] is not already mapped to some other char
                if(charsOfTUsed.find(t[i]) != charsOfTUsed.end()) return false;
                //if not then insert to map
                else 
                {
                    sToT[s[i]] = t[i];
                    charsOfTUsed.insert(t[i]);
                }
            }
        }
        
        return true;
    }
};