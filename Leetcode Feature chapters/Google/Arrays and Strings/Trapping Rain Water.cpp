class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), waterQuantity = 0;
        if(n <= 2) return 0;
        int rightHighest[n], leftHighest[n];
        rightHighest[n-1] = height[n-1];
        leftHighest[0] = height[0];

        for(int i = n-2; i >= 0; i--)
            rightHighest[i] = (height[i] > rightHighest[i+1])?height[i]:rightHighest[i+1];

        for(int i=1; i<n; i++)
            leftHighest[i] = (height[i] > leftHighest[i-1])?height[i]:leftHighest[i-1];
        
        for(int i=1; i<n-1; i++)
        {
            int minHt = min(leftHighest[i],rightHighest[i]);
            if(minHt > height[i]) waterQuantity += (minHt - height[i]);
        }
       
        return waterQuantity;
    }


};*/