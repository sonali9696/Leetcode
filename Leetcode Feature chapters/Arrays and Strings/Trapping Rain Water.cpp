class Solution {
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


};