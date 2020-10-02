//Some good test cases - 3, [[1,0],[2,0]]
//3, [[1,0]]
//1,[]
//2,[]
//5,[[0, 1], [1, 2], [3, 4]]


class UnionFind{
	private:
        vector<int> parent;
	    vector<int> size;
	
	public:
		UnionFind(int n)
		{
			for(int i=0; i<n; i++)
			{
				parent.push_back(i);
				size.push_back(1);
			}
		}
	
        int find(int A)
        {
            //find root of A
            int tempA = A, root = A;
            while(parent[A] != A) A = parent[A];
            root = A;

            //optimize so that this is O(1) next time
            A = tempA;
            while(parent[A] != A)
            {
                int oldParent = parent[A];
                parent[A] = root;
                A = oldParent ;
            }

            return root;
        }	

		bool unionSet(int A, int B)
		{
			int rootA = find(A);
			int rootB = find(B);

			//no merge occurred - cycle!
			if(rootA == rootB) return false;
			
			if(size[rootA] < size[rootB])
			{
				parent[rootA] = rootB;
				size[rootB] = size[rootB] + size[rootA];
			}
			else
			{
                parent[rootB] = rootA;
				size[rootA] = size[rootA] + size[rootB];
			}

			return true;
		}
		
};


class Solution {
public:
	

    bool validTree(int n, vector<vector<int>>& edges) {
        //if less means not connected
        //if more means cycle exists
        if(edges.size() != n-1) return false;
        
        //now to check if it is connected -
        //we see by union if they are all under one connected component


        //initialize union
        UnionFind *u = new UnionFind(n);
        
		for(int i=0; i<edges.size(); i++)
		{
			int A = edges[i][0], B = edges[i][1];
			if(u->unionSet(A,B) == false) return false;
		}
		
        
        return true;
    
    }
};




