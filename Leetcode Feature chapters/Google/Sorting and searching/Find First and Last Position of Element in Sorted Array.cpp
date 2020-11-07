class Solution {
private:
	vector<int> targetPos;
	int n;
public:
	void findPosition(int low, int high,int target,vector<int>& nums)
	{
		int mid = low + (high-low)/2;
		if(mid > n || low > high) return;

		if(nums[mid] < target) findPosition(mid+1,high,target,nums);
		else if(nums[mid] > target) findPosition(low,mid-1,target,nums);
		else
		{
			if(targetPos[0] == -1 || targetPos[0] > mid) targetPos[0] = mid;
			if(targetPos[1] < mid) targetPos[1] = mid;

			if(mid > 0 && nums[mid-1] == target) findPosition(low,mid-1,target,nums);
            if(mid < n-1 && nums[mid+1] == target) findPosition(mid+1,high,target,nums);
		}
	}
	
    vector<int> searchRange(vector<int>& nums, int target) {
        targetPos = {-1,-1};
        n = nums.size();
        if(n == 0) return targetPos;

        findPosition(0,n-1,target,nums);

        return targetPos;
    }
};

