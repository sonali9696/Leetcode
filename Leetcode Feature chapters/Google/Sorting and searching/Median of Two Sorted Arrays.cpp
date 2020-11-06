//find the partition i & j in A[] & B[], s.t. the # of elements before partition is (m+n)/2
//i is in smaller array, j is [(m+n+1)/2 - i] because we to get non -ve j, we need to ensure i is smaller than (m+n)/2 which is possible in the smaller array ---> m+n+1 because it works for both odd and even
//1)now last element in A's left < 1st element in B's right
//2)and last element in B's left < 1st element in A's right
//A,B are sorted so last in left will always be < 1st in right in its own array so no need to check
//if 1) and 2) not satisfied, then shift low and high in binary search manner in the larger size array.

class Solution {
private:
    double median;
public:
    void partition(vector<int> &A,vector<int> &B,int low,int high,int sizeA,int sizeB)
    {
        if(low > high) //eg: when A=[1,3], B=[2]
        {
            median = 0.0;
            return; 
        }
        
        int midA = (low+high)/2, midB = ((sizeA+sizeB+1)/2)-midA;
        
        if(midB-1 >= 0 && midA < sizeA && B[midB-1] > A[midA]) 
        //B too large -> A too small, shift midA right
        {   
            low = midA+1;
            partition(A,B,low,high,sizeA,sizeB);
        }
        else if(midA-1 >= 0 && midB < sizeB && A[midA-1] > B[midB]) 
        //A too large -> shift midA left
        {
            high = midA-1;
            partition(A,B,low,high,sizeA,sizeB);
        }
        else //this covers cases where paritions are at edges
        {
            int maxLeft, minRight;
            if(midA-1 >= 0 && midB-1 >= 0) maxLeft = max(A[midA-1],B[midB-1]);
            else if(midA-1 >= 0) maxLeft = A[midA-1];
            else if(midB-1 >= 0) maxLeft = B[midB-1];

            if(midA < sizeA && midB < sizeB) minRight = min(A[midA],B[midB]);
            else if(midA < sizeA) minRight = A[midA];
            else if(midB < sizeB) minRight = B[midB]; //not leaving at else for cases when both are > size
            //eg: [], [2]
            
            if((sizeA+sizeB) % 2 == 0) median = (maxLeft+minRight)/2.0;
            else median = maxLeft;
            return;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
        //ensuring first array is the smaller one on which we will do binary search
        //to ensure j>=0
		if(m <= n) partition(nums1,nums2,0,m,m,n); //dont send m-1 as high as it causes issue in say - 
        // when A=[1,3], B=[2] there it starts going to low > high condition after 1 iteration.
        else partition(nums2,nums1,0,n,n,m); //swapped
        
		return median;
    }
};

