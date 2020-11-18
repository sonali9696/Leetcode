//good test case - 
//[0,-2,-1]
//[0,-2,2,-4]
//[-2,5]
//[-2,-3,-4]
//[-1,-1,0]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int prod = 1,leftProd=1, rightProd=1;
        bool hasZero = false, hasOne = false;
        
        int numOfNegativeNumbers = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0) numOfNegativeNumbers++;
            if(nums[i] == 0) hasZero = true;
            if(nums[i] == 1) hasOne = true;
        }
        
        int negativeLeftI = numOfNegativeNumbers, negativeLeftj = numOfNegativeNumbers;
        
        for(int i=0, j=n-1; j>=0, i<n; j--,i++)
        {
            if(nums[i] == 0) leftProd = 1; //reset
            else if(leftProd*nums[i] < 0 && negativeLeftI >= 1) leftProd = leftProd*nums[i]; 
            else if(leftProd == 1) leftProd = nums[i];
            else leftProd = max(nums[i], leftProd*nums[i]);
            
            if(leftProd == 1 && nums[i] != 0) hasOne = true;
            
            if(nums[j] == 0) rightProd = 1;
            else if(rightProd*nums[j] < 0 && negativeLeftj >= 1) rightProd = rightProd*nums[j];
            else if(rightProd == 1) rightProd = nums[j];
            else rightProd = max(nums[j], rightProd*nums[j]);
            
            if(rightProd == 1 && nums[j] != 0) hasOne = true;
            
            //cout<<leftProd<<" "<<rightProd<<endl;
            
            if(leftProd != 1 || rightProd != 1) 
                prod = max(prod, max(leftProd, rightProd));
        }
        
        if(hasZero == true && hasOne == false && (prod < 0 || prod == 1)) prod = 0;
        return prod;
    }
};

