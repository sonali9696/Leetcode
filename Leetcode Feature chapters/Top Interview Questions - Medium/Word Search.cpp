//without extra space used by visited -

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        int index = 0;
        bool found = false;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                dfs(board, word, i, j, index, found);
            }
        }
        
        return found;
    }
    
    void dfs(vector<vector<char>>& board, string word, int i, int j, int index, bool& found)
    {   
        if(i == board.size() || i < 0 || j < 0 || j == board[0].size() || found == true 
           || board[i][j] == '#' || index == word.size())         
        {
            return;
        }
        
        if(board[i][j] == word[index])
        {
            board[i][j] = '#'; //i.e. visited
            
            if(index == word.size() - 1)
            {
                found = true;
                return;
            }
            
            dfs(board, word, i-1, j, index+1, found); 
            dfs(board, word, i+1, j, index+1, found);
            dfs(board, word, i, j-1, index+1, found);
            dfs(board, word, i, j+1, index+1, found);
            
            board[i][j] = word[index]; //reverting back
        }
        
    }
};

/*class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        int index = 0;
        bool found = false;
        
        vector<vector<bool>> visited;
        for(int i=0; i<rows; i++)
        {
            vector<bool> temp;
            for(int j=0; j<cols; j++) 
            {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                dfs(board, word, i, j, index, visited, found);
            }
        }
        
        return found;
    }
    
    void dfs(vector<vector<char>>& board, string word, int i, int j, int index, vector<vector<bool>>& visited, bool& found)
    {   
        if(i == board.size() || i < 0 || j < 0 || j == board[0].size() || found == true 
           || visited[i][j] == true || index == word.size())         
        {
            return;
        }
        
        visited[i][j] = true;
        
        
        if(board[i][j] == word[index])
        {
            if(index == word.size() - 1)
            {
                found = true;
                return;
            }
            
            dfs(board, word, i-1, j, index+1, visited, found); 
            dfs(board, word, i+1, j, index+1, visited, found);
            dfs(board, word, i, j-1, index+1, visited, found);
            dfs(board, word, i, j+1, index+1, visited, found);
        }
        
        visited[i][j] = false;
    }
};*/