class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        dict['V'] = 5;
        
        int l = s.length(), i=0, ans = 0;
        while(i < l)
        {
            if(i != l-1)
            {
                if(dict[s[i]] < dict[s[i+1]])
                {
                    ans += (dict[s[i+1]] - dict[s[i]]);
                    i += 2;
                    continue;
                }
            }
            
            ans += dict[s[i]];
            i++;
        }
        
        return ans;
    }
};
/*class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        dict['V'] = 5;
        
        map<string, int> specialCases;
        specialCases["IV"] = 4;
        specialCases["IX"] = 9;
        specialCases["XL"] = 40;
        specialCases["XC"] = 90;
        specialCases["CD"] = 400;
        specialCases["CM"] = 900;
        
        
        int l = s.length(), i=0, ans = 0;
        while(i < l)
        {
            if(i != l-1)
            {
                string twoLetters = s.substr(i,2);
                if(specialCases.find(twoLetters) != specialCases.end())
                {
                    ans += specialCases[twoLetters];
                    i += 2;
                    continue;
                }
            }
            
            ans += dict[s[i]];
            i++;
        }
        
        return ans;
    }
};*/