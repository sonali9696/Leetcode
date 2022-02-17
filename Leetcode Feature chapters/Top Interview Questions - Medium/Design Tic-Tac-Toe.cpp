class TicTacToe {
private:
    vector<vector<char>> board;
    int n;
    
    bool checkWinner(char symbol, int row, int col)
    {
        int countHoriz = 0, countVert = 0;
        for(int i=0; i<n; i++)
        {
            if(board[row][i] == symbol) countHoriz++; 
            if(board[i][col] == symbol) countVert++;
        }
        if(countHoriz == n || countVert == n) return true;
        
        //diagonal
        if(row == col || row + col == n-1)
        {
            int countLeftDiag = 0, countRightDiag = 0, j = n-1;
            for(int i=0; i<n; i++)
            {
                if(board[i][i] == symbol) countLeftDiag++;
                if(board[i][j] == symbol) countRightDiag++;
                j--;
            }
            if(countLeftDiag == n || countRightDiag == n) return true;
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
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */