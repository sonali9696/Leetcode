class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rOld = mat.size(), cOld = mat[0].size();
        if(rOld*cOld != r*c) return mat;
        
        vector<vector<int>> newMatrix;
        for(int i=0; i<r; i++)
        {
            newMatrix.push_back(vector<int>());
            for(int j=0; j<c; j++) newMatrix[i].push_back(1);
        }
        
        
        int currentRow = 0, currentCol = 0;
        for(int i=0; i<rOld; i++)
        {
            for(int j=0; j<cOld; j++)
            {
                newMatrix[currentRow][currentCol] = mat[i][j];
                currentCol++;
                if(currentCol == c){
                    currentCol = 0;
                    currentRow++;
                }
            }
        }
        
        return newMatrix;
    }
};
