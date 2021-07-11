//DP solution:
//eg: [12*] -> ans is 24.
//divide into 2 parts for each character. Taking it by itself or taking it in pair with prev element
//if you take it by itself then you multiply it with dp[i-1] as encoding done till there
//if you take it in pair with prev then multiply by dp[i-2].
//add both cases to get total possibilities.
//this is done because for eg: in 12* if 1,2 is taken as "12" then cant pair * with 2 for those cases so have to consider dp[i-1] to get cases with "12" and then multiply with 9 (cases with just * individually)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), p = 1000000007;
        
        long long int NMinus2DpValue = 1, NMinus1DpValue = numOfWaysForCurrent(s.substr(0,1)); 

        for (int i = 1; i < n; i++) {
            long long int dpSingle = NMinus1DpValue * numOfWaysForCurrent(s.substr(i, 1));
            long long int dpPair = NMinus2DpValue * numOfWaysForCurrent(s.substr(i-1, 2));
            long long int dpCurrent = dpSingle % p + dpPair % p;
            
            NMinus2DpValue = NMinus1DpValue;
            NMinus1DpValue = dpCurrent % p;
        }
        return NMinus1DpValue;
    }
    
private:
    int numOfWaysForCurrent(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0'? 0:1;
        }
        
        if (s == "**")  
            return 15; // 11-26, except 20 because '*' is 1-9
        else if (s[1] =='*') {
            if (s[0] =='1') return 9;
            return s[0] == '2'? 6:0;
        }
        else if (s[0] == '*') 
            return s[1] <= '6'? 2:1; //2 because can * can be 1 or 2 eg: 11 or 21.
        else 
            // if two digits, it has to be in [10 26]; no leading 0
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; 
    }
};