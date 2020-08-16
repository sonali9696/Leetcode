class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> jumpsToEnd;
        int latestJumpsToEndIndex = n - 1;
        
        for(int i=0; i<n; i++) jumpsToEnd.push_back(false);
        jumpsToEnd[n-1] = true;

        for(int i = n-2; i >= 0; i--)
        {
            int distance = latestJumpsToEndIndex - i;
            if(distance > nums[i]) continue;
            else
            {
                jumpsToEnd[i] = true; 
                latestJumpsToEndIndex = i;
            }	
        }

        return jumpsToEnd[0];
    }

};