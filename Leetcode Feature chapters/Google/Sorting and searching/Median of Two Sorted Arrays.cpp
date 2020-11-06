class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size(), mid2;
		int mid1 = (m+n)/2; //-1 for index
        if((m+n) % 2 == 0) //even
        {
            mid2=mid1-1;
        }
        else mid2 = mid1;
        
		//cout<<"mid1="<<mid1<<",mid2="<<mid2<<endl;
  
		int indexAtMergedArr = 0, indexAtNums1=0, indexAtNums2 = 0;
		double ans,median1,median2;
        
		while(indexAtNums1 < m && indexAtNums2 < n && indexAtMergedArr <= mid1)
		{
			if(nums1[indexAtNums1] <= nums2[indexAtNums2]) 
            {
                if(indexAtMergedArr == mid1) median1 = nums1[indexAtNums1];
                if(indexAtMergedArr == mid2) median2 = nums1[indexAtNums1];
                indexAtNums1++;
            }
            else 
            {
                if(indexAtMergedArr == mid1) median1 = nums2[indexAtNums2];
                if(indexAtMergedArr == mid2) median2 = nums2[indexAtNums2];
                indexAtNums2++;
            }
			indexAtMergedArr++;
		}
		
		if(indexAtNums1 < m)
		{
			while(indexAtMergedArr <= mid1)
			{
				if(indexAtMergedArr == mid1) median1 = nums1[indexAtNums1];
	            if(indexAtMergedArr == mid2) median2 = nums1[indexAtNums1];
				indexAtNums1++;
				indexAtMergedArr++;
			}
		}
		if(indexAtNums2 < n)
		{
			while(indexAtMergedArr <= mid1)
			{
				if(indexAtMergedArr == mid1) median1 = nums2[indexAtNums2];
                if(indexAtMergedArr == mid2) median2 = nums2[indexAtNums2];
				indexAtNums2++;
				indexAtMergedArr++;
			}
		}

        //cout<<"median1="<<median1<<",median2="<<median2<<endl;
        ans = ((double)(median1 + median2)) / 2.0;
		return ans;
    }
};

