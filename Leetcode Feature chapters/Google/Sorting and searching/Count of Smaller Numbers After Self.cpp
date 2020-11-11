//mergesort: if any element from right added before left
//then all elements in left -> count++


/*TODO - DEBUG - 
[5,2,6,1]
Your answer
[1,1,0,0]
Expected answer
[2,1,1,0]*/

class Solution {
public:
    void merge(vector<pair<int,int>> &numsAndIndices,vector<int> &count, int low, int mid, int high)
    {
        //cout<<low<<" "<<mid<<" "<<high<<endl;
        
        vector<pair<int,int> > left;
        vector<pair<int,int> > right;
        
        for(int i=low; i <= mid; i++) left.push_back(numsAndIndices[i]);
        for(int i=mid+1; i <= high; i++) right.push_back(numsAndIndices[i]);
        
        int leftIndex=0, rightIndex=0, mergedIndex = low;
        
        while(leftIndex < left.size())
        {
            //cout<<"leftIndex="<<leftIndex<<",rightIndex="<<rightIndex<<endl;
            if(rightIndex >=  right.size() || left[leftIndex].first <= right[rightIndex].first)
            {
                //number of elements pushed before this already from right
                count[left[leftIndex].second] += rightIndex; 
                //cout<<"count of "<<left[leftIndex].second<<"="<<rightIndex<<endl;
                numsAndIndices[mergedIndex] = left[leftIndex];
                leftIndex++;
            }
            else //smaller element on right
            {
                numsAndIndices[mergedIndex] = right[rightIndex];
                rightIndex++;
            }
            
            mergedIndex++;
        }
        
        while(rightIndex <  right.size()) //only right array left
        {
            numsAndIndices[mergedIndex] = right[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
        
        
        /*for(int i=0; i<numsAndIndices.size(); i++) 
        {
            cout<<numsAndIndices[i].first<<" "<<numsAndIndices[i].second<<endl;
        }
        cout<<"***********"<<endl;*/
    }
    
    void mergesort(vector<pair<int,int>> &numsAndIndices,vector<int> &count, int low, int high)
    {
        if(low < high)
        {
            int mid = low + (high-low)/2;
            mergesort(numsAndIndices, count, low, mid);
            mergesort(numsAndIndices, count, mid+1, high);
            merge(numsAndIndices, count,low,mid,high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count;
        
        vector<pair<int,int>> numsAndIndices;
        for(int i=0; i<n; i++) 
        {
            numsAndIndices.push_back(make_pair(nums[i],i));
            count.push_back(0);
        }
        
        mergesort(numsAndIndices, count, 0, n-1);
        
        return count;
    }
};