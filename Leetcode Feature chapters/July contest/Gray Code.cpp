class Solution {
public:
    vector<string> generateGrayCode(int n){
        if(n < 1) return {"0"};
        else if(n == 1) return {"0","1"};
        
        vector<string> left = generateGrayCode(n-1);
        int l = left.size();
        vector<string> ans;
        for(int i=0; i<l; i++) ans.push_back("0" + left[i]);
        for(int i=l-1; i>=0; i--) ans.push_back("1" + left[i]);
        return ans;
    }
    
    int binaryToDecimal(string bin){
        int dec = 0, base = 1, l = bin.length();
        
        for(int i=l-1; i>=0; i--){
            if(bin[i] == '1') dec += base;
            base *= 2;
        }
        
        return dec;
    }
    
    vector<int> grayCode(int n) {
        vector<int> ans = {0,1};
        if(n == 1) return ans;
        
        vector<string> ansInStr = generateGrayCode(n);
        
        vector<int> ansInInt;
        int l = ansInStr.size();
        for(int i=0; i<l; i++){
            string num = ansInStr[i];
            long long int decimalNum = binaryToDecimal(num);
            ansInInt.push_back(decimalNum);
        }
        
        return ansInInt;
        
    }
};