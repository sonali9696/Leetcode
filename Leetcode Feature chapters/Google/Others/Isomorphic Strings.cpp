class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> ascii_S(256,'#'), ascii_T(256,'#');
     
        int l = s.length();
        for(int i=0; i<l; i++)
        {
            if(ascii_S[s[i]] == '#' && ascii_T[t[i]] == '#')
            {
                ascii_S[s[i]] = t[i];
                ascii_T[t[i]] = s[i];
            }
            else
            {
                if(ascii_S[s[i]] != '#' && ascii_S[s[i]] != t[i]) return false;
                if(ascii_T[t[i]] != '#' && ascii_T[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};

/*class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> sTot, tTos;
        
        int l = s.length();
        for(int i=0; i<l; i++)
        {
            if(sTot.find(s[i]) == sTot.end() && tTos.find(t[i]) == tTos.end())
            {
                sTot[s[i]] = t[i];
                tTos[t[i]] = s[i];
            }
            
            else if(sTot.find(s[i]) != sTot.end())
            {
                if(sTot[s[i]] == t[i]) continue;
                else return false;
            }
            
            else if(tTos.find(t[i]) != tTos.end())
            {
                if(tTos[t[i]] == s[i]) continue;
                else return false;
            }
        }       
        
        return true;
    }
};*/

