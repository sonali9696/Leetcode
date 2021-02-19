class Solution {
private:
	int m, n, maxPossibleSquareSize;
public:
	bool isSquare(vector<vector<int>>& matrix, int len, int i, int j)
	{
        if(i+len-1 >= m || j+len-1 >= n || len > maxPossibleSquareSize) return false; 
		for(int row = i; row < i+len; row++)
		{
			for(int col = j; col < j+len; col++)
            {
                if(matrix[row][col] != 1) return false;
            }
		}
		return true;
	}

   	int countSquares(vector<vector<int>>& matrix) {
       	int numOfSquares = 0;
        m = matrix.size(), n = matrix[0].size();
        maxPossibleSquareSize = min(m,n);
        for(int i=0; i<m; i++)
        {
            int j=0;
            while(j<n)
            {
                if(matrix[i][j] == 1)
                {
                    numOfSquares++; //for 1 side squares
                    int len = 1;
                    int c = j+1; //so that at next j it checks in next loop again if there is a new 2 side square etc starting from it
                    while(c < n && matrix[i][c] == 1)
                    {
                        len++;
                        numOfSquares += (isSquare(matrix,len,i,j))?1:0;
                        c++;
                    }
                }
                j++;
            }
        } 

        return numOfSquares;
    }
};

