//binary search - 
//if mid is in an increasing slope then peak is in right half
//if mid is in a decreasing slope then peak is in left half
//when only one element left then that element is peak

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int low = 0, high = n-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            
            //shift search space
            if(nums[mid] < nums[mid+1]) //increasing slope
                low = mid+1;
            else //decreasing slope (not mid can be the start of the slope hence high is not mid-1 but mid)
                high = mid;
        }
        
        return low;
    }
};
    
/*class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0; //index 0
        for(int i=0; i<n; i++)
        {
            if(i == 0 && nums[i] > nums[i+1]) return i;
            else if(i != 0 && i == n-1 && nums[i] > nums[i-1]) return i;
            else if(i != 0 && i != n-1 && nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        
        return -1;
    }
};*/