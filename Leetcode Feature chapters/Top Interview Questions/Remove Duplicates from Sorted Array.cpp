class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, l = nums.size();
        if(l == 0) return 0;
        for(int j=1; j<l; j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return (i+1);
        
    }
};