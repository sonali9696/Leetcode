class Vector2D {
private:
    // vector<vector<int>>::iterator it;
    vector<vector<int>> v;
    int rows, cols, currentRow, currentCol;
    
public:
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
        rows = vec.size();
        
        currentRow = 0;
        while(currentRow < rows && vec[currentRow].empty()) currentRow++;
        
        if(rows > 0 && currentRow < rows) cols = v[currentRow].size();
        else cols = 0;
        
        currentCol = 0;
    }
    
    int next() {
        int val = v[currentRow][currentCol];
        if(currentCol + 1 == cols) 
        {
            currentRow++;
            while(currentRow < rows && v[currentRow].empty()) currentRow++;
            currentCol = 0;
            if(currentRow < rows) cols = v[currentRow].size();
        }
        else currentCol++;
        
        return val;
    }
    
    bool hasNext() {
        if(rows == 0 || cols == 0) return false; //empty
        else if(currentRow == rows || currentCol == cols)  return false;
        else return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */