class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        
        int i=0, j=0;
        string sum;
        int l1 = num1.length(), l2 = num2.length();
        while(i < l1 && j < l2){
            int currSum = carry + (num1[i] - '0') + (num2[j] - '0');
            carry = currSum / 10;
            currSum = currSum % 10;
            sum.push_back(currSum + '0');
            i++;
            j++;
        }
        
        while(i < l1){
            int currSum = carry + (num1[i] - '0');
            carry = currSum / 10;
            currSum = currSum % 10;
            sum.push_back(currSum + '0');
            i++;
        }
        
        while(j < l2){
            int currSum = carry + (num2[j] - '0');
            carry = currSum / 10;
            currSum = currSum % 10;
            sum.push_back(currSum + '0');
            j++;
        }
        
        if(carry != 0) sum.push_back(carry + '0');
        
        //think about trailing zeros?
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};