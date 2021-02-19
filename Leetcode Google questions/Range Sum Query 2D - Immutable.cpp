//Solution 2: DP - caching areas using Summed Area Table, a.k.a. Integral Image
class NumMatrix {
private:
	vector<vector<int>> dp; //storing 2d area with i,j as bottom right corner
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = (m==0)?0:matrix[0].size();
        if(m == 0 || n == 0) return;
        dp.resize(m+1);
        for(int i=0; i<=m; i++) dp[i].resize(n+1);
        
		for(int i=0; i<m+1; i++)
		{
			for(int j=0; j<n+1; j++)
			{
                if(i == 0 || j == 0) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1]; //as i,j of dp is +1 of matrix 
			}
		}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
        //return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
    }
};



//Solution 1: DP - caching rows by storing cumulative sums
/*class NumMatrix {
private:
	vector<vector<int>> cumulativesum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
       	int m = matrix.size(), n = (m==0)?0:matrix[0].size();
        
		for(int i=0; i<m; i++)
		{
            vector<int> temp;
			for(int j=0; j<n; j++)
			{
				if(j==0) temp.push_back(matrix[i][j]);
				else temp.push_back(matrix[i][j] + temp[j-1]); //cumulative[i][j] = cumulative[i][j-1] + matrix[i][j]
			}
            cumulativesum.push_back(temp);
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //for every row it is cumulative of row,col2 - row,col1
		int sum = 0;
		for(int row = row1; row <= row2; row++)
		{
			if(col1-1>=0) sum += cumulativesum[row][col2] - cumulativesum[row][col1-1];
			else sum += cumulativesum[row][col2];
		}
		return sum;
    }
};*/


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */