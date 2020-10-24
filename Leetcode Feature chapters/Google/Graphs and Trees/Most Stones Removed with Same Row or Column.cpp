
//sum of (size-1 of connected components) using union

class UnionSet{
private:
	vector<int> parent;
	vector<int> sizeOfUnion;

public:
	UnionSet(vector<vector<int>>& stones)
	{
		int n = stones.size();
		for(int i=0; i<n; i++)
		{
			parent.push_back(i);
			sizeOfUnion.push_back(1);
		}
	}

	int findRoot(int node) //node means index of node in stones
	{
		int A = node;
		while(parent[node] != node) node = parent[node];
		int root = node;

		//O(1) next time
		while(parent[A] != A)
        {
            int oldRoot = parent[A];
            parent[A] = root;
            A = oldRoot;
        }	

		return root;
	}

	bool unionNodes(int A, int B)
	{
		int rootA = findRoot(A), rootB = findRoot(B);
		if(rootA == rootB) return false;
		if(sizeOfUnion[rootA] > sizeOfUnion[rootB])
		{
			parent[rootB] = rootA;
			sizeOfUnion[rootA] += sizeOfUnion[rootB];
		}
		else
		{
			parent[rootA] = rootB;
			sizeOfUnion[rootB] += sizeOfUnion[rootA];
        }
        return true;
	}

	int numberOfComponents()
	{
		int num = 0;
		for(int i=0; i<parent.size(); i++)
		{
			if(parent[i] == i) num++;
		}
		return num;
	}

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size() == 0 || stones.size() == 1) return 0;
        
        UnionSet *u = new UnionSet(stones);

        int n = stones.size();

        //union same row and same col
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])
                {
                    u->unionNodes(i,j);
                }
            }
        }

        int noOfComp = u->numberOfComponents();
        return stones.size() - noOfComp;
    }
};

/*
//dfs solution for reference - 

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int res = 0;
        int n = stones.size();
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                res += dfs(stones, visited, i) - 1;
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int curr)
    {
        if(visited[curr]) return 0;
        int ret = 1;
        visited[curr] = true;
        
        for(int i=0; i<stones.size(); i++)
        {
            if(!visited[i] && (stones[i][0] == stones[curr][0] || stones[curr][1] == stones[i][1]))
                ret += dfs(stones, visited, i);
        }
        return ret;
    }
};
*/



