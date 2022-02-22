//boyer-moore voting algo: 
//take a candidate, keep doing +1 when it comes and -1 if something else comes
//if we reach 0 then next element is new candidate
//this works because since it is majority so even when we disregard the part where it became 0
//there will come a part where it is not 0 as it is more than the occurrences of minority
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int i = 1, n = nums.size(), count = 1;
        while(i<n)
        {
            if(count == 0)
            {
                ans = nums[i];
                count = 1;
                i++;
                continue;
            }
            
            if(nums[i] == ans) count++;
            else count--;
            
            i++;
        }
        
        return ans;
    }
};


/*class Solution {
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
};*/