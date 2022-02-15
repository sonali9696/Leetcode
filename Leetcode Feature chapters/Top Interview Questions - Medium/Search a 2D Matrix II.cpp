class Solution {
private:
    int numOfRows, numOfCols;
public:
    bool binarySearchVertical(vector<vector<int>>& matrix, int target, int start)
    {
        int end = numOfRows-1;
        int colIndex = start; 
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(matrix[mid][colIndex] == target) return true;
            else if(matrix[mid][colIndex] > target) end = mid-1;
            else start = mid+1;
        }
        return false;    
    }
    
    bool binarySearchHorizontal(vector<vector<int>>& matrix, int target, int start)
    {
        int end = numOfCols-1;
        int rowIndex = start; 
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(matrix[rowIndex][mid] == target) return true;
            else if(matrix[rowIndex][mid] > target) end = mid-1;
            else start = mid+1;
        }
        return false;    
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //search in 1st row, 1st col, then go to next diagonal element and 
        //find that row and col starting from diagonal element to end
        //keep doing till you reach the end
        //note diagonal would end at [m][m] where m = min(number of rows, number of cols)
        
        numOfRows = matrix.size();
        numOfCols = matrix[0].size();
        int endIndex = min(numOfRows, numOfCols);
        
        for(int i=0; i<endIndex; i++)
        {
            bool ans1 = binarySearchVertical(matrix, target, i);
            bool ans2 = binarySearchHorizontal(matrix, target, i);
            if(ans1 == true || ans2 == true) return true;
        }
        
        
        return false;
    }
};