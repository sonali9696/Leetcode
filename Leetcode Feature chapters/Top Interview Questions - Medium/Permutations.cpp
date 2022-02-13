class Solution {
private:
    vector<vector<int>> ans;
        
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index=0, n = nums.size(); //index at which all n numbers will be tried at current iteration
        createPerm(nums,n,index);
        
        return ans;
    }
    
    void createPerm(vector<int> nums, int n, int index)
    {
        if(index == n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            
            createPerm(nums, n, index+1);
            
            swap(nums[index], nums[i]); //get it back to what it was for next iteration
        }
    }
    
};

/*class Solution {
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
};*/