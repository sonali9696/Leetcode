class Solution {
public:
    int uniquePaths(int m, int n) {
        int matrix[m][n];
        
        for(int i=0; i<m; i++) matrix[i][n-1] = 1;
        for(int j=0; j<n; j++) matrix[m-1][j] = 1;
        
        
        for(int i = m-2; i >= 0; i--)
        {
            for(int j = n-2; j >=0; j--)
            {
                matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];         
            }
        }
        
        return matrix[0][0];
    }
};