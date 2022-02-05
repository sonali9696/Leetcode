class Solution {
public:
    
    /*string countAndSay(int n) {
        if(n == 1) return "1";
        else return say(countAndSay(n-1)); 
    }
    
    string say(string n)
    {
        int l = n.length();
        string ans = "";
        int currCount = 1, currChar = n[0];
        
        if(l == 1)
        {
            ans = "1";
            ans.push_back(n[0]);
            return ans;
        }
        
        for(int i=1; i<l; i++) //starting pos
        {
            if(n[i] == n[i-1]) currCount++;
            else
            {
                ans = ans + to_string(currCount);
                ans.push_back(currChar);
                
                currCount = 1; //reset to start new character from current pos
                currChar = n[i];
            }
        }
        
        //add count of characters at the end
        ans = ans + to_string(currCount);
        ans.push_back(currChar);
        
        return ans;
    }*/
    
    string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
};