class Solution {
public:
    int mySqrt(int x) {
        //sqrt will be between 1 to x
        //since it is just integer think like if it lies between 4 and 9 i.e. square of 2 and 3 then ans is 2
      //since 1 to x is sorted can use binary search to find it
        
        int low = 2, high = x/2;
        if(x == 0) return 0;
        if (x <= 3) return 1;
        
        while(low <= high)
        {
           int mid = low + (high-low)/2;
            long long int res = (long long int)mid*mid;
            long long int next = (long long int) (mid+1)*(mid+1);
            
            long long int prev=(long long int) (mid-1)*(mid-1);
            
            if(res == x) return mid;
            else if(x > res && x < next) return mid;
            
            else if (x < res && x > prev) return mid-1;
            
            else if(res < x) low = mid+1;
            
            else high = mid-1;
        }
        
        return low;
    }
};