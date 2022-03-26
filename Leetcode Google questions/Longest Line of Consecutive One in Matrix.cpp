class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> horiz(m,vector<int>(n,0));
        vector<vector<int>> vert(m,vector<int>(n,0));
        vector<vector<int>> diag(m,vector<int>(n,0));
        vector<vector<int>> antiDiag(m,vector<int>(n,0));
        
        int longestLine = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 1)
                {
                    horiz[i][j] = (j - 1 >= 0)?(horiz[i][j-1] + 1) : 1;
                    vert[i][j] = (i - 1 >= 0)?(vert[i-1][j] + 1) : 1;
                    diag[i][j] = (i-1 >= 0 && j-1 >= 0)?(diag[i-1][j-1] + 1) : 1;
                    antiDiag[i][j] = (i-1 >= 0 && j+1 < n)?(antiDiag[i-1][j+1] + 1) : 1;
                    
                    int maxLen1 = max(horiz[i][j], vert[i][j]);
                    int maxLen2 = max(diag[i][j], antiDiag[i][j]);
                    int maxLen = max(maxLen1, maxLen2);
                    
                    if(longestLine < maxLen) longestLine = maxLen;
                }
            }
        }
        
        return longestLine;
    }
};