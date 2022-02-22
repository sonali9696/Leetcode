class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(freq.find(nums[i]) == freq.end()) freq[nums[i]] = 0;
            freq[nums[i]]++;
        }
        
        map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++)
        {
            if(it->second > n/2) return it->first;    
        }
        
        return nums[0]; //shouldn't reach here as there is a guarantee that max exists
    }
};