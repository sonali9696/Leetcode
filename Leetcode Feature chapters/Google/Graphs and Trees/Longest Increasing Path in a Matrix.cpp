class Solution {
    private:
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    public:
        int dfs(vector<vector<int>>& cache,vector<vector<int>>& matrix, int x, int y, int r, int c)
        {
            if(cache[x][y] != 0) return cache[x][y];
            int ans = 0; 

            for(int i=0; i < 4; i++)
            {
                int x2 = x + dirs[i][0];
                int y2 = y + dirs[i][1];

                if(x2 < 0 || x2 >= r || y2 < 0 || y2 >= c) continue;

                if(matrix[x2][y2] > matrix[x][y])
                {
                    ans = max(ans, dfs(cache,matrix,x2,y2,r,c));
                }
            }

            ans++; //counting current cell
            cache[x][y] = ans;
            return ans;	
        }

        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if(matrix.size() == 0) return 0;
            const int r = matrix.size(), c = matrix[0].size();
            if(c == 0) return 0;
            if(r == 1 && c == 1) return 1;

            vector<vector<int>>cache;
            for(int i=0; i<r; i++)
            {
                vector<int>temp;
                for(int j=0; j<c; j++) temp.push_back(0);
                cache.push_back(temp);
            }
            int longestPath = 0;

            for(int i=0; i<r;i++)
            {
                for(int j=0; j<c; j++)
                {
                    longestPath = max(longestPath, dfs(cache,matrix,i,j,r,c));
                }
            }
            return longestPath;
        }
};


