class Graph{
	private:
		vector<vector<int>> adjacencyList;
		int n;
		vector<int> visited;

	public:
		Graph(int &num)
		{
			n = num;
			for(int i=0; i < n; i++)
            {
                vector<int> temp;
                temp.push_back(i);
                adjacencyList.push_back(temp);
            }

			for(int i=0; i<n; i++) visited.push_back(false);
		}

		void addEdge(int &src, int &dest)
		{
			adjacencyList[src].push_back(dest);
		}
	
		void TopologicalSortUtil(stack<int> &st, int v)
		{
			visited[v] = true;
            for(auto node : adjacencyList[v])
            {
                if(visited[node] == false) TopologicalSortUtil(st, node);
            }

            st.push(v);
		}

		vector<int> TopologicalSort()
		{
			vector<int> order;
	
			stack<int> st;
			for(int i=0; i<n; i++)
			{
				if(visited[i] == false) TopologicalSortUtil(st,i);
			}

			int flag = 0;
			while(!st.empty())
			{
				order.push_back(st.top());
				st.pop();
			}

			
			return order;
		}

		bool isCycle(vector<int> &order)
		{
			map<int,int> position;
			for(int i=0; i<order.size(); i++)
			{
				position[order[i]] = i;
			}
			
            vector<vector<int>>::iterator j;
			for(int i=0; i<n; i++)
			{
				for(auto j : adjacencyList[i])
				{
					int src = i, dest = j;
					if(position[src] > position[dest]) return true;
				}
			}

			return false;
		}
		
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//create graph
		Graph *g = new Graph(numCourses);
		
		for(int i=0; i < prerequisites.size(); i++) g->addEdge(prerequisites[i][1], prerequisites[i][0]);
       
		//topological sort
		vector<int> order = g->TopologicalSort();

        bool cyclePresent = g->isCycle(order);

        if(cyclePresent == true)
        {
            vector<int> empty;
            return empty;
        }
        else return order;
    }
};

