//simplified -
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos2 = nums.size()-1, index = 0;
        
        while(index <= pos2)
        {
            if(nums[index] == 0)
            {
                swap(nums[pos0++], nums[index++]); 
                //as even if gets swapped by 2, index++ means it will get processed in next iteration
            }
            else if(nums[index] == 2)
            {
                swap(nums[pos2--], nums[index]); //we don't move index so that new value of nums[index] is processed before moving
            }
            else index++;
        }
        
        
    }
};

/* 
//one pass-
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = nums.size(); //i - where 0 is there right now, j - where 2 is right now
        int start = 0;
        while(start < nums.size() && nums[start] == 0)
        {
            i = start;
            start++;
        }
        
        int end = nums.size()-1;
        while(end >= 0 && nums[end] == 2)
        {
            j = end;
            end--;
        }
        
        for(int index = start; index < j; index++)
        {
            if(nums[index] == 0)
            {
                i++;
                while(i != index && i < j && nums[i] == 0) i++;
                swap(nums[i], nums[index]);
                if(nums[index] == 2) //new nums[index]
                {
                    j--;
                    while(j != index && j >= 0 && nums[j] == 2) j--;
                    swap(nums[j], nums[index]);
                }
            }
            
            if(nums[index] == 2)
            {
                j--;
                while(j != index && j >= 0 && nums[j] == 2) j--;
                swap(nums[j], nums[index]);
                if(nums[index] == 0) //new nums[index]
                {
                    i++;
                    while(i != index && i < j && nums[i] == 0) i++;
                    swap(nums[i], nums[index]);
                }
            }
        }
    }
};*/

/*class Solution {
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
};*/