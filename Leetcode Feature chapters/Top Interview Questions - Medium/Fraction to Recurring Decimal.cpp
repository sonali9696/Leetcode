class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //long division
        if(numerator == 0) return "0";
        
        string ans = "";
        if((numerator < 0 && denominator > 0) ||(numerator > 0 && denominator < 0)) ans = "-";
        
        long long int divisor = denominator, dividend = numerator; 
        //if one of these -2^31 then if we do it 2^31 then it will cause integer overflow
        
        if(divisor < 0) divisor = -divisor; //easier to do long division of positives
        //else issue in comparing say -4 is less than 2 so we will think not divisible etc
        if(dividend < 0) dividend = -dividend;
        
        long long int quotient = dividend/divisor; //note that this takes care of -ve sign if ans is -ve
        long long int remainder = dividend % divisor;
        ans = ans + to_string(quotient);
        
        if(remainder == 0) return ans;
        else ans.push_back('.'); //decimal point
        
        map<int,int> seen; //if remainder starts repeating then decimal part of quotient will also repeat
        //number, position for seen
        
        dividend = remainder;
        while(remainder != 0)
        {
            if (seen.find(remainder) != seen.end())
            {
                ans = ans.insert(seen[remainder], "(");
                ans.push_back(')');
                break;
            }
            else seen[remainder] = ans.length();
            
            dividend = remainder*10; //due to decimal point, we add one 0 at end
            quotient = dividend/divisor;
            ans= ans + to_string(quotient);
            remainder = dividend % divisor;
        }
        
        return ans;
        
    }
};