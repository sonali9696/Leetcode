class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakMountain = arr[0], peakInd = 0, n = arr.size();
        for(int i=1; i<n; i++)
        {
            if(arr[i] > peakMountain) 
            {
                peakInd = i;    
                peakMountain = arr[i];
            }
        }
        return peakInd;
    }
};