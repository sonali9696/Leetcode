class Solution {
public:
    void rotate(vector<vector<int> >& image)
    {
        int numOfRows = image.size();
        int numOfCols = numOfRows;

        int startCol = 0, endCol = numOfCols-2, currRow = 0, currCol = 0;

        while(startCol <= endCol)
        {
            for(int currCol = startCol; currCol <= endCol; currCol++)
            {
                int i = currRow, j = currCol;
                int currNumber = image[i][j];
                
                while(1)
                {
                    int newRow = j, newCol = numOfCols - 1 - i;
                    int nextNum = image[newRow][newCol];
                    image[newRow][newCol] = currNumber;
                    i = newRow, j = newCol;
                    currNumber = nextNum; 

                    if(i == currRow && j == currCol) break;
                } 

            }
            
            currRow++; startCol++; endCol--;
            
        }
    }

};