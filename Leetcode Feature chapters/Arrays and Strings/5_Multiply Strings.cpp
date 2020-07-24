class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        string currentNum = "", sum = "";
     
        if(num1 < num2) 
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        
        int l1 = num1.length(), l2 = num2.length();
        
        for(int i = l2-1; i >= 0; i--)
        {
            carry = 0;
            int n1 = num2[i] - '0';
            currentNum = "";
            for(int k=0; k < (l2-1-i); k++) currentNum = currentNum + '0';

            for(int j = l1 -1; j >=0; j--)
            {
                int n2 = num1[j] - '0';
                int product = n1*n2 + carry;
                carry = product / 10;
                product = product % 10;
                currentNum = (char)(product + '0') + currentNum;
            }
            //cout<<"currentNum="<<currentNum<<endl;
            
            if(carry > 0) currentNum = (char)(carry + '0') + currentNum;

            int lencurrentNum = currentNum.length(), carry2 = 0, n = sum.length()-1;
            
            for(int m = lencurrentNum-1; m >=0; m--)
            {
                int tempNum1;
                if(n < 0) tempNum1 = 0;
                else 
                {
                    tempNum1 = sum[n] - '0';
                }
                int tempNum2 = currentNum[m] - '0';
                int tempSum = tempNum1 + tempNum2 + carry2;
                carry2 = tempSum / 10;
                if(n < 0) sum = (char)(tempSum % 10 + '0') + sum;
                else sum[n] = (char)(tempSum % 10 + '0');
                n--;
            }
            if(carry2 > 0) sum = (char)(carry2+'0') + sum;
            
            //cout<<"sum="<<sum<<endl;
            
        }

        int NonZeroPos = 0; 
        for(int i=0; i<sum.length(); i++)
        {
            if(sum[i] == '0') NonZeroPos++;
            else break;
        }
        
        if(NonZeroPos < sum.length())
            sum = sum.substr(NonZeroPos);
        else sum = '0';
        
        return sum;
        
    }
};
