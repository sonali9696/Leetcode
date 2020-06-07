class Solution {
public:
    int maxArea(vector<int>& height) {
        
        long long int maxWaterArea = 0;
        int l = height.size(), length, breadth;
        
        int i = 0, j = l-1;
        while(i<j)
        {
            length = min(height[i], height[j]);
            breadth = j-i;
            
            if((length*breadth) > maxWaterArea) maxWaterArea = length*breadth;
            
            if(height[i] < height[j]) i++; 
            //as otherwise the same smaller one will be considered for length in next iteration
            else j--;
        }
        
        return maxWaterArea;  
    }
};