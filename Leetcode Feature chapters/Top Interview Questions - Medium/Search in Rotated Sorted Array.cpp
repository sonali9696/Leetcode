class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size()-1;
        
        while(left <= right)
        {
            int m = left + (right-left)/2;
            if(nums[m] == target) return m;
            else if(nums[m] >= nums[left]) //left subarray
            {
                if(target < nums[m] && target >= nums[left]) right = m-1;
                else left = m+1;
            }
            else //right subarray
            {
                if(target > nums[m] && target <= nums[right]) 
                    left = m+1;
                else right = m-1;
            }
        }
        
        return -1;
    }
};

/*class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        if(target < nums[start] || target > nums[end]) return -1;
        
        int i = start, j = end;
        while(i<=j)
        {
            int m = (i+j)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) j = m-1;
            else i = m+1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size(), pos = -1;
        
        if(n == 1)
        {
            if(nums[0] == target) return 0;
            else return -1;
        }
        else if(n == 2)
        {
            if(nums[0] == target) return 0;
            else if(nums[1] == target) return 1;
            else return -1;
        }
        
        if(nums[n-1] > nums[0]) //not rotated
        {
            return binarySearch(nums,0,n-1,target); //find in whole array
        }
        
        int i = 0, j = n-1;
        //find pivot and search
        while(i <= j)
        {
            int m = (i+j)/2;
            
            //pivot found: last element of left array
            if((m-1 < 0 || nums[m] > nums[m-1]) && (m+1 == n || nums[m] > nums[m+1])) 
            {
                int binary1 = binarySearch(nums,0,m, target);
                int binary2 = binarySearch(nums, m+1, n-1, target);
                if(binary1 != -1) return binary1;
                else if(binary2 != -1) return binary2;
                else return -1;
            }
            
            //first element of right array
            else if((m+1 == n || nums[m] < nums[m+1]) && (m-1 < 0 || nums[m] < nums[m-1])) 
            {
                int binary1 = binarySearch(nums,0,m-1, target);
                int binary2 = binarySearch(nums, m, n-1, target);
                if(binary1 != -1) return binary1;
                else if(binary2 != -1) return binary2;
                else return -1;
            }
            //left subarray
            else if((m-1 < 0 || nums[m] > nums[m-1]) && (m+1 == n || nums[m] < nums[m+1]) && 
                    nums[m] > nums[n-1]) 
            {
                i = m+1;
            }  
            else 
            {
                j = m-1;
            }
        }
        return -1;
    }
};*/