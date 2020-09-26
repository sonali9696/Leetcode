class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = nums.size();
        
        if(n == 0)
        {
            if(lower != upper) ans.push_back(to_string(lower) + "->" + to_string(upper));
            else ans.push_back(to_string(lower));
            return ans;
        }
        
        int prev = nums[0], curr = nums[1];
        if(lower < prev)
        {
            if(prev == lower + 1) ans.push_back(to_string(lower));
            else ans.push_back(to_string(lower) + "->" + to_string(prev-1));
        }

        for(int i=1; i < n; i++)
        {
            curr = nums[i];
            prev = nums[i-1];
            if(curr == prev || curr == prev+1) continue; //curr - prev == 1 will cause overflow for int_max - int_min
            else if(curr == prev + 2) ans.push_back(to_string(prev+1));
            else ans.push_back(to_string(prev+1) + "->" + to_string(curr-1));
        }

        if(nums[n-1] < upper)
        {
            if(upper == nums[n-1] + 1) ans.push_back(to_string(upper));
            else ans.push_back(to_string(nums[n-1]+1) + "->" + to_string(upper));
        }

        return ans;
    }


    
    
};