//O(N) - union find
//if the current edge is already connected i.e. union returns false 
//then this is the redundant edge

class Solution{
private:
    vector<int> parent;
    vector<int> size;
    
    void init(int n)
    {
        for(int i=0; i < n; i++)
        {
            parent.push_back(i); //parent[i] = i i.e. itself
            size.push_back(1);
        }
    }
    
    int find(int A)
    {
        while(parent[A] != A) 
        {
            A = parent[A];
        }
        
        int root = A;
        
        //optimization: for it to be faster next time
        while(parent[A] != A)
        {
            int oldParent = parent[A];
            parent[A] = root;
            A = oldParent;
        }
        
        return root;
    }
    
    bool unionSet(int A, int B)
    {
        int rootA = find(A), rootB = find(B);
        if(rootA == rootB) return false;
        else
        {
            if(size[rootA] >= size[rootB])
            {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            else
            {
                parent[rootA] = rootB;
                size[rootA] += size[rootB];
            }
        }
        return true;
    }
    
public:
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        //nodes can be max n+1 so-
        init(n + 1);
        
        for(vector<int> edge: edges)
        {
            if(!unionSet(edge[0], edge[1])) return edge;
        }
        
        return vector<int>();
    }
};

/* Simplified union find -

class Solution {
public:
    
    int find(int curr,vector<int>& parent){
        if(parent[curr]==-1){
            return curr;
        }
        return find(parent[curr],parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int> parent(n+1,-1);
        vector<int> ans;
        
        for(auto edge : edges){
            int sourceParent=find(edge[0],parent);
            int destParent=find(edge[1],parent);
            
            if(sourceParent==destParent){
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
                break;
            }
            parent[sourceParent]=destParent;
        }
        return ans;
    }
};*/


//TLE: O(N^2)
//DFS - before connecting u and v, if there already exists a path from u to v
//then this is a redundant edge
//given if u and v have some existing connections.

/*class Solution {
private:
    set<int> seen;
    int MAX_EDGE_VAL = 1000; //as per constraints in question
    
    bool dfs(vector<vector<int>> graph, int u, int v)
    {
        if(seen.count(u) == 0)
        {
            seen.insert(u);
            
            if(u == v) return true;
            
            for(int nei: graph[u])
            {
                if(dfs(graph, nei, v)) return true;
            }
        }
        
        return false;
    }
        
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph;
        
        for(int i=0; i <= MAX_EDGE_VAL; i++)
        {
            graph.push_back(vector<int>()); //creating graph[i] as empty vectors
        }
        
        for(vector<int> edge : edges)
        {
            seen.clear();
            if(!graph[edge[0]].empty() && !graph[edge[1]].empty() &&
              dfs(graph, edge[0], edge[1]))
            {
                return edge;
            }
            
            //connect edges on both sides as undirected graph
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return {-1,-1};
    }
};*/