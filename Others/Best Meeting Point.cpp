//if we solve for 1D, we can solve for 2D using two 1D->
//we can't take mean as the meeting point because in 1-0-0-0-0-0-0-1-1
//mean is 5, but ans is 7. This is because 1 is heavier on right side so meeting point should be towards right
//we should take median as meeting point
//1-1-0-0-1 -> ans is 1
// so we may think that just by considering 1s and taking their median ans should come
//But in 1-1-0-0-1-1, ans is in the middle i.e. at position of 0s.
//it falls on 1 for odd number of 1s, but not necessary for even number of 1s

/*class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> row;
        vector<int> col;

        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int mid_row = row.size()%2? row[row.size()/2]: (row[row.size()/2 - 1] + row[row.size()/2]) / 2;
        int mid_col = col.size()%2? col[col.size()/2]: (col[col.size()/2 - 1] + col[col.size()/2]) / 2;

        int dist = 0;
        for(int i = 0; i<row.size(); i++) 
            dist += abs(mid_row - row[i]);
        for(int i = 0; i<col.size(); i++) 
            dist += abs(mid_col - col[i]);

        return dist;
    }  
};*/

class Solution {
private:
    int minDistance1D(vector<int> points, int median)
    {
        int n = points.size(), ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += abs(median-points[i]);
        }
        return ans;
    }
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        //collect rows in sorted manner to save time complexity in sorting
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1) rows.push_back(i);
            }
        }
        
        //collect cols in sorted manner to save time complexity in sorting
        vector<int> cols;
        for(int j=0; j<grid[0].size(); j++)
        {
            for(int i=0; i<grid.size(); i++)
            {
                if(grid[i][j] == 1) cols.push_back(j);
            }
        }
        
        //calculate median
        int mid_row = rows.size()%2? 
            rows[rows.size()/2]: (rows[rows.size()/2 - 1] + rows[rows.size()/2]) / 2;
        int mid_col = cols.size()%2? 
            cols[cols.size()/2]: (cols[cols.size()/2 - 1] + cols[cols.size()/2]) / 2;
        
        //calculate distance
        return minDistance1D(rows, mid_row) + minDistance1D(cols, mid_col);
    }
};