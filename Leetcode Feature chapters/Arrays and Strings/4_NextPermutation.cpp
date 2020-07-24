class Solution {
public:
    
    void Swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), temp;
        
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] >= nums[n-1]) //no next perm possible till now
            {
                //find correct place to insert it
                int j = i+1;
                while(j < n && nums[j] <= nums[i]) j++;
                
                if(j<n) swap(nums[i], nums[j]);
                else //it is the last number
                {
                    int lastNum = nums[i];
                    j = i;
                    while(j<n-1)
                    {
                        nums[j] = nums[j+1];
                        j++;
                    }
                    nums[n-1] = lastNum;
                }
            }
            else
            {
                //find next largest number
                int j = i+1;
                while(j < n && nums[j] <= nums[i]) 
                {
                    j++;
                }
                
                if(j < n) 
                {
                    swap(nums[i], nums[j]);
                }
                break; //a number just greater than nums[i] exists hence the next perm. found
            }
            //rest on the more righter side is already sorted
        }
        
    }
};