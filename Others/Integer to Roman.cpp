class Solution {
public:
    string intToRoman(int num) {
        vector<int> numbers = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        //this is to do binary search to find biggest number closest to input number
        
        map<int, string> numToRoman;
        numToRoman[1] = "I";
        numToRoman[4] = "IV";
        numToRoman[5] = "V";
        numToRoman[9] = "IX";
        numToRoman[10] = "X";
        numToRoman[40] = "XL";
        numToRoman[50] = "L";
        numToRoman[90] = "XC";
        numToRoman[100] = "C";
        numToRoman[400] = "CD";
        numToRoman[500] = "D";
        numToRoman[900] = "CM";
        numToRoman[1000] = "M";
        
        string roman = "";
        int numPtr = 0;
        while(num != 0)
        {
            if(num > 1000) numPtr = 1000;
            else
            {
                auto it = lower_bound(numbers.begin(), numbers.end(), num);
                if(*it == num) numPtr = *it;
                else numPtr = *(--it);
            }
            
            roman = roman + numToRoman[numPtr];
            num -= numPtr;
        }
        
        return roman;
    }
};