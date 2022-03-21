class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        //points[i][j] can be represented as dp[i][j]
        //here dp[i][j] can be calculated from prev row s.t. 
        //it is dp[i-1][k] + abs(j-k)
        //this k can be left of j or right of j
        //so rather than calculating it again and again for each col of current row
        //we store it in leftArray and rightArray so that
        //for every dp[i][j] we know what is the best value for all k<j
        //and for all k>j, we have rightArray
        
        int m = points.size(), n = points[0].size(); //given m,n >= 1
        
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        
        //for prev row, values from left and right:
        vector<long long> left(n,0);
        vector<long long> right(n,0);
        
        //first row
        for(int j=0; j<n; j++) dp[0][j] = points[0][j];
        
        for(int i=1; i<m; i++)
        {
            //calculates left
            for(int j=0; j<n; j++)
            {
                if(j == 0) left[j] = dp[i-1][j];
                else left[j] = max(left[j-1] - 1, dp[i-1][j]); 
                
                //note: you can think that left[j] maybe best by left[j-2]-2
                //but if left[j-2] is big enough it would have already replaced left[j-1] as well
                //so just seeing left[j-1] is enough
            }
            
            //calculates right
            right[n-1] = dp[i-1][n-1];
            for(int j=n-2; j>=0; j--)
            {
                right[j] = max(right[j+1]-1, dp[i-1][j]);
            }
            
            //calculate dp for current row
            for(int j=0; j<n; j++)
            {
                dp[i][j] = max(left[j], right[j]) + points[i][j];
            }
        }
        
        //ans is max in last row
        long long int maxPoints = 0;
        for(int j=0; j<n; j++)
        {
            if(dp[m-1][j] > maxPoints) maxPoints = dp[m-1][j];
        }
        
        return maxPoints;
    }
};