class Solution {
public:
    int titleToNumber(string columnTitle) {
       // extract letters
        // from right to left it is 26*num where num is 1-26 based on A-Z
        // ZY=(26*26)+(1*25)
        int ans = 0;
        int n = columnTitle.length();
        for(int i=0; i<n; i++)
        {
            char c = columnTitle[i];
            int num = c - 'A' + 1;
            ans = ans*26 + (int)(c-'A') + 1;
        }
        
        return ans;
    }
};