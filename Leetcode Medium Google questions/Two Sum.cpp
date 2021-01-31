class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > numsWithIndices;
        int n = nums.size();
        for(int i=0; i<n; i++) numsWithIndices.push_back(make_pair(nums[i],i));

        sort(numsWithIndices.begin(),numsWithIndices.end());

        int l = 0, r = n-1;
        while(l<r)
        {
            int leftNum = numsWithIndices[l].first, rightNum=numsWithIndices[r].first;
            if(leftNum + rightNum == target)
            {
                int p1 = numsWithIndices[l].second, p2 = numsWithIndices[r].second;
                vector<int> ans;
                if (p1 <= p2) ans = {p1,p2};
                else ans = {p2,p1};
                return ans; 
            }
            else if(leftNum + rightNum > target) r--;
            else l++;
        }

        vector<int> ans = {-1,-1}; //wont reach here
        return ans;
    }
};