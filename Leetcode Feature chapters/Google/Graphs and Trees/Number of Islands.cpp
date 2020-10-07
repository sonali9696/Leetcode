class UnionSet{
    private:
        vector<int> parent;
        vector<int> size;
        int count = 0; //efficient way to count. Initialize it with number of 1s. Reduce by 1 at each merge.

    public:
        UnionSet(vector<vector<char>>& grid)
        {
            
            int R = grid.size(), C = grid[0].size();
            
            for(int i=0; i < R; i++)
            {
                for(int j=0; j<C; j++)
                {
                    if(grid[i][j] == '0')
                    {
                        parent.push_back(-1);
                        size.push_back(0);
                    }
                    else
                    {
                        count++;
                        parent.push_back(C*i + j);
                        size.push_back(1);
                    }
                }
            }
        }

        int findRoot(int A)
        {
            int temp = A;
            while(parent[A] != A) A = parent[A];
            int root = A;

            while(parent[A] != A)
            {
                int oldRoot = parent[A];
                parent[A] = root;
                A = oldRoot;
            }

            return root;
        }

        void unionFunc(int A, int B)
        {
            int rootA = findRoot(A);
            int rootB = findRoot(B);
            
            if(rootA == rootB) return;

            if(size[rootA] >= size[rootB])
            {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            else
            {
                parent[rootA] = rootB;
                size[rootB] += size[rootA];
            }
            
            count--; //count occurred
        }

        int getCount()
        {
            return count;
        }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;
        
        int R = grid.size(), C = grid[0].size();
        int totalIslands = R*C;
        
        if(R == 0 || C == 0) return 0;
        
        UnionSet *u = new UnionSet(grid);

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(grid[i][j] == '0') 
                {
                    continue;
                }
                
                if(i != 0 && grid[i-1][j] == '1')
                {
                    int A = (C*(i-1)) + j;
                    int B = (C*i) + j;
                    u->unionFunc(A,B);
                }

                if(j != 0 && grid[i][j-1] == '1')
                {
                    int A = (C*i) + j-1;
                    int B = (C*i) + j;
                    u->unionFunc(A,B);
                }

            }
        }
        totalIslands = u->getCount();

        return totalIslands;

    }
};

