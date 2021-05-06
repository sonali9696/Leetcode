//O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        int left = 1;
        vector<int> R(l);
        R[l-1] = 1;
        for(int i=l-2; i>=0; i--) R[i] = R[i+1]*nums[i+1];
        
        for(int i=0; i<l; i++) {
            R[i] = left*R[i];
            left *= nums[i];
        }
        return R;
    }
};

//using 2 prod arrays
/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        int L[l], R[l];
        L[0] = 1, R[l-1] = 1;
        for(int i=1; i<l; i++) L[i] = L[i-1]*nums[i-1];
        for(int i=l-2; i>=0; i--) R[i] = R[i+1]*nums[i+1];
        
        vector<int> ans(l);
        for(int i=0; i<l; i++) ans[i] = L[i]*R[i];
        return ans;
    }
};*/

/*
//using division-
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        int l = nums.size(); 
        vector<int> ans(l);
        
        int prod = 1, prodWithoutZero = 1, numberOfZeros = 0;
        for(int i=0; i<l; i++){
            prod *= nums[i];
            if(nums[i] != 0) prodWithoutZero *= nums[i];
            else numberOfZeros++;
        }
        
        for(int i=0; i<l; i++){
            if(nums[i] != 0) ans[i] = prod/nums[i];
            else if(numberOfZeros == 1) ans[i] = prodWithoutZero;
            else ans[i] = 0;
            
        }
        
        return ans;
    }
};*/