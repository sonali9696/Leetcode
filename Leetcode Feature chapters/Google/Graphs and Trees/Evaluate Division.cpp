class Solution {
    private:
        map<string,vector<pair<string,double>>> graph;
    
    public:
        void addEdge(string s, string d, double val)
        {
            graph[s].push_back(make_pair(d,val));
            if(val != 0) graph[d].push_back(make_pair(s,(1/val)));
        }

        bool findInGraph(string s, string d, double &ans, set<string> &visited)
        {
            //is s in graph
            if(graph.find(s) == graph.end()) return false;
            if(s == d) return true;

            //go to all neighbours and do dfs
            vector<pair<string,double>> v = graph[s];
            int l = v.size();
            for(int i=0; i<l; i++)
            {
                string node = v[i].first;
                
                //if already visited, ignore 
                if(visited.count(node) != 0) continue;
                
                double val = v[i].second;

                double old = ans;
                ans *= val;
                visited.insert(node);
                bool found = findInGraph(node,d,ans,visited);
                if(found == true) return true;	

                //reset
                visited.erase(node);
                ans = old;
            }
            return false;
        }

        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

            int n = equations.size();
            int n2 = queries.size();
            vector<double> result;

            if(n == 0)
            {
                for(int i=1; i<=n2; i++) result.push_back(-1.0);
                return result;
            }	

            //create graph
            for(int i=0; i<n; i++)
                addEdge(equations[i][0],equations[i][1],values[i]);

            for(int i=0; i<n2; i++)
            {
                string s = queries[i][0], d = queries[i][1];
                double ans = 1.0;
                
                set<string> visited; //fresh set for each new query
                visited.insert(s);
                bool found = findInGraph(s,d,ans,visited);
                if(found) result.push_back(ans);
                else result.push_back(-1.0);
            }   
            return result;
    	}

};


