class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
       	int m = grid.size();
		if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        int maxEnemiesDead = 0; 
        cout<<m<<" "<<n<<endl;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != '0') continue;
                else
                {
                    int r = i-1, count = 0;
                    while(r >= 0)
                    {
                        if(grid[r][j] == 'W') break;
                        if(grid[r][j] == 'E') count++;
                        r--;
                    }
                    r = i+1;
                    while(r < m)
                    {
                        if(grid[r][j] == 'W') break;
                        if(grid[r][j] == 'E') count++;
                        r++;
                    }
                    int c = j-1;
                    while(c >= 0)
                    {
                        if(grid[i][c] == 'W') break;
                        if(grid[i][c] == 'E') count++;
                        c--;
                    }
                    c = j+1;
                    while(c < n)
                    {
                        if(grid[i][c] == 'W') break;
                        if(grid[i][c] == 'E') count++;
                        c++;
                    }
                    if(count > maxEnemiesDead) maxEnemiesDead = count;
                }
            }
        } 
        return maxEnemiesDead;
    }
};

