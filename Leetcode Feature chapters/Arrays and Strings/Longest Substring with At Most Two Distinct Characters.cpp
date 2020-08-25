class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        char firstChar = '\0', secondChar = '\0';
        int n = s.length();
        int longestWindowLength = 0;
        int l = 0, r = 0;

        int lastIndex[2];
        memset(lastIndex,-1,sizeof(lastIndex));
        
        while(l <= r && r < n)
        {
            if(firstChar == '\0') 
            {
                firstChar = s[r];
                //freqTillNow[r] = 1;
                lastIndex[0] = r;
            }
            else if(secondChar == '\0' && s[r] != firstChar) 
            {
                secondChar = s[r];
                //freqTillNow[r] = 1;
                lastIndex[1] = r;
            }
            else
            {
                if(s[r] != firstChar && s[r] != secondChar)
                {
                    if(lastIndex[0] < lastIndex[1]) //least recently used
                    {
                        firstChar = s[r];
                        l = lastIndex[0]+1;
                        lastIndex[0] = r;
                    }
                    else
                    {
                        secondChar = s[r];
                        l = lastIndex[1]+1;
                        lastIndex[1] = r;
                    }
                }
                else if(s[r] == firstChar) lastIndex[0] = r;
                else lastIndex[1] = r;
            }

            if(r - l + 1 > longestWindowLength) longestWindowLength  = r - l + 1; 

            r++;
        }

        return longestWindowLength;
    }


};