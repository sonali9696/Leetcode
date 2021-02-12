
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
       	int m = grid.size();
		if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        int maxEnemiesDead = 0; 
        vector<int> colHits(n,-1);
        int rowHits = -1; //dont need array as need this value only for current row, no need to store for prev rows
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j == 0) rowHits = -1;
                
                if(grid[i][j] == 'W')
                {
                    rowHits = -1;
                    colHits[j] = -1;
                }
                else
                {
                    if(colHits[j] == -1) //hits in col j from row i to m
                    {
                        int r = i, count = 0; //left of this is already taken care (1st col or wall before this)
                        while(r < m)
                        {
                            if(grid[r][j] == 'W') break;
                            if(grid[r][j] == 'E') count++;
                            r++;
                        }
                        colHits[j] = count;
                    }
                    
                    if(rowHits == -1) //hits in row i from col j to n
                    {
                        int c = j, count = 0;
                        while(c < n)
                        {
                            if(grid[i][c] == 'W') break;
                            if(grid[i][c] == 'E') count++;
                            c++;
                        }
                        rowHits = count;
                    }
                    
                    if(grid[i][j] == '0')
                    {
                        int totalHits = rowHits + colHits[j];
                        if(totalHits > maxEnemiesDead) maxEnemiesDead = totalHits;
                    }
                }
            }
        } 
        return maxEnemiesDead;
    }
};


/*class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
       	int m = grid.size();
		if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        int maxEnemiesDead = 0; 
        vector<int> rowHits(m,-1), colHits(n,-1);
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 'W')
                {
                    rowHits[i] = -1;
                    colHits[j] = -1;
                }
                else
                {
                    if(colHits[j] == -1) //hits in col j from row i to m
                    {
                        int r = i, count = 0; //left of this is already taken care (1st col or wall before this)
                        while(r < m)
                        {
                            if(grid[r][j] == 'W') break;
                            if(grid[r][j] == 'E') count++;
                            r++;
                        }
                        colHits[j] = count;
                    }
                    
                    if(rowHits[i] == -1) //hits in row i from col j to n
                    {
                        int c = j, count = 0;
                        while(c < n)
                        {
                            if(grid[i][c] == 'W') break;
                            if(grid[i][c] == 'E') count++;
                            c++;
                        }
                        rowHits[i] = count;
                    }
                    
                    if(grid[i][j] == '0')
                    {
                        int totalHits = rowHits[i] + colHits[j];
                        if(totalHits > maxEnemiesDead) maxEnemiesDead = totalHits;
                    }
                }
            }
        } 
        return maxEnemiesDead;
    }
};*/



/*class Solution {
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
};*/

