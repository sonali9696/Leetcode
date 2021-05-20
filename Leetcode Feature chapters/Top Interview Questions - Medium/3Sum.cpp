class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<l-2; i++) //fix a number
        {
            if(nums[i] > 0) continue; //since array is sorted remaining elements can't sum to 0 as in this case all will be positive            
            if(i != 0 && nums[i] == nums[i-1]) continue; //to avoid duplicate eg if there are two 0s, all the triplets are already formed using the prev 0 so no need to recalculate 
            
            int target = 0 - nums[i], j = i+1, k = l-1;
            while(j < k)
            {
                if(nums[j] + nums[k] == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    while(j < k && nums[j] == nums[j-1]) j++; //to avoid duplicates
                }
                else if(nums[j] + nums[k] < target) j++;
                else k--;
            }
        }
        return ans;
    }
};