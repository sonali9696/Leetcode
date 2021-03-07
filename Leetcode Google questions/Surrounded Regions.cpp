class Solution {
private:
	int m,n;
public:
	void dfs(vector<vector<char>>& board, int i, int j){
		if(i < 0 || i >= m || j < 0 || j >=n || board[i][j] != 'O') return;
		board[i][j] = '#'; //marking as visited
		dfs(board, i-1, j);
		dfs(board, i+1, j);
		dfs(board, i, j-1);
		dfs(board, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        //exploring border as the O cells connected to border won’t be flipped
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }       	
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        //convert board - O flips to X if not connected to border
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '#') board[i][j] = 'O'; //escaped
                else if(board[i][j] == 'O') board[i][j] = 'X'; //captured
            }
        }
    }
};

