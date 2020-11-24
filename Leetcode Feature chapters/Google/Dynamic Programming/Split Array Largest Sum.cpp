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

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<vector<int> > f(n+1,vector<int>(m+1,INT_MAX));
        
        vector<int> sum(n+1,0); //sum[0] = 0 as 0 elements
        for(int i=0; i<n; i++) sum[i+1] = sum[i] + nums[i]; 
        //sum[1] = 0 + nums[0]; for #elements=1
        
        if(m == 1) return sum[n];
        for(int i=1; i<=n; i++) f[i][1] = sum[i]; //1st row 
        //here i:number of elements
        
        for(int i=1; i <= n; i++) //i: number of elements
        {
            for(int j=2; j <= m; j++) //j: number of partitions
            {
                if(j > i) break; //invalid j
                
                //find correct partition - 
                for(int k=1; k<i; k++) //k: number of elements
                {
                    //f[k][j-1] means fork elements with j-1 partitions
                    //2nd parameter is last partition: sum from nums[k+1] to nums[i]
                    int currMax = max(f[k][j-1],sum[i]-sum[k]); 
                    f[i][j] = min(f[i][j], currMax);
                }
            }
        } 

        return f[n][m];
    }
};