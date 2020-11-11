class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1, mid;
        int peak;
        while(low <= high)
        {
            mid = (low+high)/2;
            if((mid >= 1 && arr[mid] > arr[mid-1]) && (mid <= n-2 && arr[mid] > arr[mid+1]))
            {
                peak = mid;
                break;
            }
            else if(mid < 1 || (arr[mid] > arr[mid-1])) //left side -> increasing side
            {
                low = mid;
            }
            else if(mid > n-2 || (arr[mid] > arr[mid+1])) //right side -> decreasing side
            {
                high = mid;
            }
        }
        
        return peak;
    }
};

/*class Solution {
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
};*/