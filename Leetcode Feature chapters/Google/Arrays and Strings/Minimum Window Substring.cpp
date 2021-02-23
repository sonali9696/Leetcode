class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int sizeS = s.length(), sizeT = t.length();
        string ans = "";
        if(sizeS == 0 || sizeT == 0) return ans;

        map<char,int> freqOfTarget, freqOfCurrent;
        for(int i=0; i < sizeT; i++)
        {
            if(freqOfTarget.find(t[i]) == freqOfTarget.end()) freqOfTarget[t[i]] = 1;
            else freqOfTarget[t[i]] = freqOfTarget[t[i]] + 1;

            freqOfCurrent[t[i]] = 0;
        }

        int NumOfCharsMatch = 0, requiredMatch = freqOfTarget.size();

        while(r < sizeS)
        {
            char c = s[r];
            freqOfCurrent[c] = freqOfCurrent[c] + 1;
            if(freqOfCurrent[c] == freqOfTarget[c]) NumOfCharsMatch++;

            while(l <= r && NumOfCharsMatch == requiredMatch)
            {

                    if(ans == "" || ans.length() > r-l+1) 
                    {
                        ans = s.substr(l,r-l+1);
                    }

                    //find smallest window
                    char removedChar = s[l];
                    l++;
                    freqOfCurrent[removedChar]--;
                    if(freqOfCurrent[removedChar] < freqOfTarget[removedChar])
                        NumOfCharsMatch--;
            }	

            r++;
          }

        return ans;
    }


};