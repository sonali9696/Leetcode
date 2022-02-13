class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        vector<int> curr;
        createPermutation(nums, n, curr, ans);
        
        return ans;
    }
    
    void createPermutation(vector<int> nums, int n, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            curr.push_back(nums[i]);
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            
            createPermutation(nums, n, curr, ans);
            
            curr.pop_back();
            auto it = nums.insert(nums.begin() + i, temp);
        }
    }
};