class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]; //count of 0s,1s,2s
        memset(count,0,sizeof(count));
        
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        int i=0;
        for(int j=0; j<3; j++)
        {
            while(count[j] > 0)
            {
                nums[i++] = j;
                count[j]--;
            }    
        }
        
    }
};