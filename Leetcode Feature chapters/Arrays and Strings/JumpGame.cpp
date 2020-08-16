class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> jumpsToEnd;
        vector<int> jumpsToEndIndices;
        
        for(int i=0; i<n; i++) jumpsToEnd.push_back(false);
        jumpsToEnd[n-1] = true;
        jumpsToEndIndices.push_back(n-1);

        for(int i = n-2; i >= 0; i--)
        {
            int indexSize = jumpsToEndIndices.size();
            int distance = jumpsToEndIndices[indexSize-1] - i;
            if(distance > nums[i]) continue;
            else
            {
                jumpsToEnd[i] = true; 
                jumpsToEndIndices.push_back(i);
            }	
        }

        return jumpsToEnd[0];
    }

};