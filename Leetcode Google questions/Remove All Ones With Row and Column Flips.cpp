//better space -

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //we can remove ones if all rows are either the same or opposite of each other
        if(grid.size() == 0 || grid[0].size() == 0) return true;
        
        //check if all rows are either same as row or opposite of it
        for(int i=1; i<grid.size(); i++)
        {
            if(grid[i] == grid[0]) continue;
            
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] != 1 - grid[0][j]) return false;    
            }
        }
        
        return true;
    }
};

/*class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //we can remove ones if all rows are either the same or opposite of each other
        if(grid.size() == 0) return true;
        
        vector<int> row = grid[0];
        if(row.size() == 0) return true;
        
        vector<int> oppRow;
        for(int i=0; i<row.size(); i++)
        {
            oppRow.push_back(1 - row[i]);
        }
        
        //check if all rows are either same as row or opposite of it
        
        for(int i=1; i<grid.size(); i++)
        {
            vector<int> currRow = grid[i];
            
            if(currRow != row && currRow != oppRow) return false;
        }
        
        return true;
    }
};*/