//more space for O(1) time complexity

class TicTacToe {
private:
    vector<int> rows, cols;
    int leftDiag, rightDiag, n;
    
public:
    TicTacToe(int size) {
        n = size;
        
        for(int i=0; i<n; i++) 
        {
            rows.push_back(0); //no symbol yet
            cols.push_back(0); //no symbol yet
        }
        leftDiag = 0, rightDiag = 0; 
        //0 - no symbol yet
        //+1 for player 1's entries
        //-1 for player 2's entries
    }
    
    int move(int row, int col, int player) {
        if(player == 1)
        {
            rows[row]++;
            cols[col]++;
            if(row == col) leftDiag++;
            if(row + col == n-1) rightDiag++;
            
            if(rows[row] == n || cols[col] == n || leftDiag == n || rightDiag == n) return 1;
        }
        else
        {
            rows[row]--;
            cols[col]--;
            if(row == col) leftDiag--;
            if(row + col == n-1) rightDiag--;
            
            if(rows[row] == -n || cols[col] == -n || leftDiag == -n || rightDiag == -n) return 2;
        }
        
        return 0;
    }
};

/*class TicTacToe {
private:
    vector<vector<char>> board;
    int n;
    
    bool checkWinner(char symbol, int row, int col)
    {
        bool winner = true;
        for(int i=0; i<n; i++)
        {
            if(board[row][i] != symbol) 
            {
                winner = false; 
                break;
            }
        }
        if(winner == true) return true;
        
        winner = true;
        for(int i=0; i<n; i++)
        {
            if(board[i][col] != symbol) 
            {
                winner = false; 
                break;
            }
        }
        if(winner == true) return true;
        
        
        //left diagonal
        if(row == col)
        {
            winner = true;
            for(int i=0; i<n; i++)
            {
                if(board[i][i] != symbol)
                {
                    winner = false;
                    break;
                }
            }
            
            if(winner == true) return true;
        }
        
        //rightDiag
        if(row + col == n-1)
        {
            int j = n-1;
            winner = true;
            for(int i=0; i<n; i++)
            {
                if(board[i][j] != symbol)
                {
                    winner = false;
                    break;
                }
                
                j--;
            }
            
            if(winner == true) return true;
        }
        
        return false;
    }
    
public:
    TicTacToe(int size) {
        n = size;
        for(int i=0; i<n; i++)
        {
            vector<char> temp;
            for(int j=0; j<n; j++) temp.push_back('#');
            board.push_back(temp);
        }
    }
    
    int move(int row, int col, int player) {
        char symbol;
        if(player == 1) symbol = 'X';
        else symbol = 'O';
        board[row][col] = symbol;
        
        bool winnerFound = checkWinner(symbol, row, col);
        if(winnerFound == false) return 0;
        else return player;
    }
};*/

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */