class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int> > triplets;
        int l = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < l; i++)
        {
            int j = i + 1, k = l - 1;
            long long int sumToSearch = -nums[i];
            
            if(nums[i] > 0) break; //can't have greater elements sum to negative
            
            while(j < k)
            {
                long long int curr_sum = nums[j] + nums[k];
                
                if(curr_sum < sumToSearch) 
                {
                    j++;
                    while(j < l && nums[j] == nums[j-1]) j++;
                }
                else if(curr_sum > sumToSearch) 
                {
                    k--;
                    while(k >=0 && nums[k] == nums[k+1]) k--;
                }
                else if(curr_sum == sumToSearch)
                {
                     vector<int> v = {nums[i], nums[j], nums[k]};
                     //if(find(triplets.begin(), triplets.end(), v) == triplets.end())
                     triplets.push_back(v);
                    
                    // FOLOWING IS IMPORTANT TO NOT GET TLE!
                    int secondNum = nums[j], thirdNum = nums[k];
                    j++;
                    k--;
                    while(j < k && nums[j] == secondNum) j++;
                    while(k > i && nums[k] == thirdNum) k--;
                     
                } 
                
            }
            
            // FOLOWING IS IMPORTANT TO NOT GET TLE!
            int firstNum = nums[i], flag = 0;
            while(i<l && nums[i] == firstNum) 
            {
                i++;
                flag = 1;
            }
            if(flag == 1) i--; //to not skip 2 new elements
        }
        
        return triplets;
    }
};