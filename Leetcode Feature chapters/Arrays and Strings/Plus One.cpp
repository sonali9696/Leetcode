class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1, carry = 0;
        
        while(i >= 0 && digits[i] == 9)
        {
            digits[i] = 0;
            i--;
        }

        if(i<0) //all digits were 9
        {
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }
            else
        {
            digits[i] = digits[i]+1;
        }	

        return digits;

    }

};