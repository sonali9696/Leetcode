class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        //no of X == no of O 
        //or no of X = no of O + 1 as X is first player
        //or if someone has already won, no more moves should be there
        
        int noOfX = 0, noOfO = 0;
        for(string row : board)
        {
            for(int i=0; i<3; i++)
            {
                if(row[i] == 'X') noOfX++;
                else if(row[i] == 'O') noOfO++;
            }
        }
        
        if(noOfO > noOfX) return false; //O is 2nd player
        if(noOfX - 1 > noOfO) return false; //1st player can be max 1 step ahead
        
        if(noOfO == noOfX) //latest play was by O
        {
            //this is ok if X hasn't already won
            if(hasWon(board, 'X')) return false;
        }
        
        if(noOfX - 1 == noOfO) //latest play by X
        {
            //this is ok if O hasn't already won
            if(hasWon(board,'O')) return false;
        }
        
        return true;
    }
    
    bool hasWon(vector<string>& board, char player)
    {
        int count;
        
        //check row for winner
        for(int i=0; i<3; i++)
        {
            count = 0;
            for(int j=0; j<3; j++)
            {
                if(board[i][j] == player) count++;
            }
            if(count == 3) return true;
        }

        //check col for winner
        for(int j=0; j<3; j++)
        {
            count = 0;
            for(int i=0; i<3; i++)
            {
                if(board[i][j] == player) count++;
            }
            if(count == 3) return true;
        }
        
        //check diagonal
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        
        //check opp diagonal
        if(board[2][0] == player && board[1][1] == player && board[0][2] == player) return true;
        
        return false;
    }
};
