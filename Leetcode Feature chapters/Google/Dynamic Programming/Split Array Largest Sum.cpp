
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n == 1) return nums[0];


        vector<vector<int> > f(n+1,vector<int>(m+1,INT_MAX));
        f[0][0] = 0; //shows 1 element and m=0
        f[0][1] = nums[0]; //1st row valid till here only

        vector<int> sum(n+1,0); //sum[0] = 0 as 0 elements
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + nums[i-1]; //sum[1] = 0 + nums[0]; for #elements=1
        
        if(m == 1) return sum[n];
        
        for(int i=1; i <= n; i++) //1st row done already
        {
            for(int j=1; j <= m; j++) //m can't be 0 so starts from 1
            {
                if(j > i) break; //invalid j

                //find correct partition - 
                for(int k=0; k<i; k++) //i: number of elements
                {
                    //f[k][j-1] means for subarray nums[0...k] with 1 less partition
                    //2nd parameter is sum from nums[k+1] to nums[i]
                    int currMax = max(f[k][j-1],sum[i]-sum[k]); 
                    f[i][j] = min(f[i][j], currMax);
                }
            }
        } 

        return f[n][m];
    }
};

/*brute force - tle

class Solution {
private:
	int n;
	int minLargestSum;
    vector<vector<int> > sum;
public:
	void calcLargestSplitSum(vector<int>& nums, int m, int start, int end, int currLargest)
	{
        //cout<<"*******"<<endl;
        //cout<<start<<" "<<end<<" "<<m<<endl;
        //cout<<"currLargest="<<currLargest<<endl;
        
		if(start >= n || m < 1) return;
		if(m == 1)
		{
			end = n-1;
			currLargest = max(sum[start][end],currLargest);
            minLargestSum = min(minLargestSum,currLargest);
            //cout<<"m=1 "<<minLargestSum<<endl;
			return;
		}

		for(int i=start; i<n; i++)
		{
			end = i;
            //cout<<i<<" sum[start][end]="<<sum[start][end]<<endl;
            calcLargestSplitSum(nums,m-1,end+1,end+1,max(sum[start][end],currLargest));
		}
	}

    	int splitArray(vector<int>& nums, int m) {
            n = nums.size();
            minLargestSum = INT_MAX;
            if(n == 1) return nums[0];
            for(int i=0; i<n; i++)
            {
                vector<int> temp;
                for(int j=0; j<n; j++) temp.push_back(INT_MAX);
                sum.push_back(temp);
            }
            
            for(int start = 0; start < n; start++)
            {
                for(int end = start; end < n; end++)
                {
                    if(end == start) sum[start][end] = nums[start];
                    else sum[start][end] = sum[start][end-1]+nums[end];
                }
            }
            if(m == 1) return sum[0][n-1];

            calcLargestSplitSum(nums,m,0,0,INT_MIN);
            
            return minLargestSum;
    	}
};*/
