class Solution {
private:
    int m,n;
public:
	int dfs(vector<vector<int>>& grid,int i,int j)
	{
		if(i < 0 || i >= m || j<0 || j>=n || grid[i][j] != 1) return 0;
        
		grid[i][j] = -1; //marking as visited
	
	    int currArea = 1;
		currArea += dfs(grid, i+1, j);
        currArea += dfs(grid, i-1, j);
		currArea += dfs(grid, i, j+1);
		currArea += dfs(grid, i, j-1);

		return currArea;
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
		if(m == 0) return 0;
		n = grid[0].size();
		int maxArea = 0;
		
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int currArea = dfs(grid,i,j);
                    if(currArea > maxArea) maxArea = currArea;
                }
            } 
		}
		return maxArea;
    }
};

