//solution using BIT - 
//theoretically fastest - 
class NumMatrix {
private:
    vector<vector<int>> bit;
    int rows,cols;

    int lsb(int n)
    {
        return (n & (-n));
    }

    void updateBit(int r, int c, int val)
    {
        for(int i=r; i <= rows; i += lsb(i))
        {
            for(int j=c; j <= cols; j += lsb(j))
            {
                bit[i][j] += val;
            }
        }
    }

    void buildBit(vector<vector<int>>& matrix)
    {
        for(int i=1; i <= rows; i++)
        {
            for(int j=1; j <= cols; j++)
            {
                int val = matrix[i-1][j-1];
                updateBit(i,j,val);
            }
        }
    }

    int sumBit(int r, int c)
    {
        int sum = 0;
        for(int i=r; i > 0; i -= lsb(i))
        {
            for(int j=c; j > 0; j -= lsb(j))
            {
                sum += bit[i][j];		
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows == 0) return;
        cols = matrix[0].size();

        bit.resize(rows+1);
        for(int i=1; i<=rows; i++)
        {
            bit[i].resize(cols+1,0);
        }

        buildBit(matrix);        
    }

    void update(int row, int col, int val) {
        int old_val = sumRegion(row,col, row, col);
        row++;
        col++;
        updateBit(row,col,val-old_val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; row2++; col1++; col2++; //for 1 based indexing

        int a = sumBit(row2,col2);
        int b = sumBit(row1-1,col2);
        int c = sumBit(row2,col1-1);
        int d = sumBit(row1-1,col1-1);
        return ((a+d) - (b+c));
    }
};

/*class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int N = matrix.size();
        if(!N) return;
        int M = matrix[0].size();
        if(!M) return;
        vector<vector<int>> temp (N, vector<int>(M + 1));
        rec = temp;

        for(int i = 0; i < N; i++){
            for(int j = M - 1; j >= 0;  j--){
                if(j == M-1) rec[i][j] = matrix[i][j];
                else rec[i][j] = rec[i][j+1] + matrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int pre = rec[row][col] - rec[row][col+1];
        for(int i = col; i >= 0; i--){
            rec[row][i] += (val - pre);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += (rec[i][col1] - rec[i][col2 + 1]);
        }
        return sum;
    }
private:
    vector<vector<int>> rec;
};*/

/*process in above solution: just keep a record of accumulative sum of each row.
eg.

       [1,2,3]                                                   [ 6,5,3]
Given  [2,3,4] ,we simply record accumulative sum of each row -> [ 9,7,4]
       [3,4,5]                                                   [12,9,5]
When calculate sum within certain range, just use

Σ record[row_i][col1] - record[row_i][col2 + 1]
Time Complexity:
update -> O(N)
sum->O(N)

Space Complexity:
O(N^2)

N is the length or width of matrix.*/



/*class NumMatrix {
private:
	vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
    }
    
    void update(int row, int col, int val) {
        m[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1; i<= row2; i++)
		{
			for(int j=col1; j<=col2; j++)
			{
				sum += m[i][j];
			}
		}
		return sum;
    }
};*/

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */