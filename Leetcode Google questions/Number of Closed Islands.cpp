class Solution {
private:
    int numOfClosedIslands, r, c, isClosed;
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if((i == 0 || i == r-1 || j == 0 || j == c-1) && grid[i][j] == 0) {
            isClosed = false;
            return;
        }
        
        if(i < 0 || i > r-1 || j < 0 || j > c-1 || grid[i][j] != 0) return; 
        
        grid[i][j] = -1; //visited
        
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        numOfClosedIslands = 0;
        
        r = grid.size(), c = grid[0].size();
        for(int i = 1; i < r-1; i++) //we are excluding borders
        {
            for(int j = 1; j < c-1; j++)
            {
                isClosed = true;
                if(grid[i][j] == 0) 
                {
                    dfs(grid, i, j);
                    if(isClosed) numOfClosedIslands++;
                }
            }
        }
        
        return numOfClosedIslands;
    }
};