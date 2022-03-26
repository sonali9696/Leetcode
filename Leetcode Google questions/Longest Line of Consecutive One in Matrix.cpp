//Reducing size of dp arrays
//as only prev row is needed in calculations just store that 

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<int> horiz(n), vert(n), diag(n), antiDiag(n);
        
        int longestLine = 0;
        
        for(int i=0; i<m; i++)
        {
            int prevDiag = 0;
            
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 1)
                {
                    horiz[j] = (j - 1 >= 0)?(horiz[j-1] + 1) : 1;
                    vert[j] = (i - 1 >= 0)?(vert[j] + 1) : 1; //vert[j] has i-1 value before it is overwritten hence this can be used
                    
                    //we cant simply use diag[j-1] because all values before i are already overwritten
                    int currDiag = diag[j]; //this will be used in next j iteration
                    //so for that element, this is the value of j-1 before it is overwritten         
                    diag[j] = (i-1 >= 0 && j-1 >= 0)?(prevDiag + 1) : 1;
                    prevDiag = currDiag; //for next j
                    
                    antiDiag[j] = (i-1 >= 0 && j+1 < n)?(antiDiag[j+1] + 1) : 1;
                    
                    int maxLen1 = max(horiz[j], vert[j]);
                    int maxLen2 = max(diag[j], antiDiag[j]);
                    int maxLen = max(maxLen1, maxLen2);
                    
                    if(longestLine < maxLen) longestLine = maxLen;
                }
                else
                {
                    prevDiag = diag[j];
                    
                    horiz[j] = 0;
                    vert[j] = 0;
                    diag[j] = 0;
                    antiDiag[j] = 0;   
                }
            }
        }
        
        return longestLine;
    }
};

/*class Solution {
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
};*/