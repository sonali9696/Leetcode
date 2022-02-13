//so here you start with []
//then [] diverges into [1], [2], [3]
//[1] diverges into [1,2] and [1,3]. 
//[1,3] is final and stops as reached 3, no more numbers left
//[1,2] goes to [1,2,3]
//coming back to [2] -> diverges to [2,3] and stops
//[3] has already stopped
//so got it all

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        ans.push_back(curr); //empty set pushed
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            curr.push_back(nums[i]);
            ans.push_back(curr);
            appendSubsets(curr, nums, i);
            curr.pop_back();
        }
        
        return ans;
    }
    
    void appendSubsets(vector<int> curr, vector<int> nums, int index)
    {
        if(index == nums.size() - 1) return; //nothing further to append
        
        for(int i=index+1; i<nums.size(); i++)
        {
            curr.push_back(nums[i]);
            ans.push_back(curr);
            appendSubsets(curr,nums,i);
            curr.pop_back();
        }
    }
    
};