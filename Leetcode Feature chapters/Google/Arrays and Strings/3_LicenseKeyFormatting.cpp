class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
    
        int l = S.length();
        string new_license = "";
        int count = 0;
        char c;
        
        for(int i = l-1; i >= 0; i--)
        {
            c = S[i];
            if(c == '-') continue;
            
            if(count != 0 && (count % K) == 0)
                new_license += '-';
                //new_license = '-' + new_license;
            
            if(isalpha(c) && islower(c)) c = toupper(c);
            new_license += c;
            //new_license = c + new_license;
            count++;
        }
        
        reverse(new_license.begin(), new_license.end());
        
        return new_license;
        
    }
    
};

