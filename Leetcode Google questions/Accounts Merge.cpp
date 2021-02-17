//DFS method-
class Solution {
private:
	map<string,bool> visited;
	map<string,set<string> > graph;
public:
	void dfs(string email, set<string>& emailSet)
	{
		if(visited[email] == true) return;
		visited[email] = true;
		emailSet.insert(email);
		for(auto e: graph[email])
		{
			dfs(e, emailSet);
		}
	}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = accounts.size();
		map<string,string> emailToName;
		
        //create graph - 
		//connect edges from first email to all others
		for(int i=0; i<n; i++)
		{
			string firstEmail = accounts[i][1];
            emailToName[firstEmail] = accounts[i][0];
            visited[firstEmail] = false;
            for(int j=2; j<accounts[i].size();j++)
            {
                graph[accounts[i][j]].insert(firstEmail);
                graph[firstEmail].insert(accounts[i][j]);
                emailToName[accounts[i][j]] = accounts[i][0];
                visited[accounts[i][j]] = false;
            }
		}
		
		//for every account, do dfs, update visited and add to ans
		vector<vector<string>> ans;
		map<string,set<string> >::iterator it;
		for(int i=0; i<n; i++)
		{
			for(int j=1; j<accounts[i].size(); j++)
			{
				if(visited[accounts[i][j]] == false)
				{
					set<string> emailSet;
					dfs(accounts[i][j], emailSet);
					vector<string> temp(emailSet.begin(), emailSet.end());
					temp.insert(temp.begin(),emailToName[accounts[i][j]]);
					ans.push_back(temp);
				}
			}
		}

		return ans;
    }
};




/*Union find-

class Solution {
private:
    map<string,string> parent;
    map<string,string> emailToName;
    
public:
    string find(string A)
    {
        while(parent[A] != A) A = parent[A];
        return A;
    }
    
    void unionSet(string A, string B)
    {
        string rootA = find(A), rootB = find(B);
        parent[rootB] = rootA;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans;
        //parent of other emails is first email
        
        //create parent list, map email to name
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                parent[accounts[i][j]] = accounts[i][j]; //initially parent of every email is itself
                emailToName[accounts[i][j]] = accounts[i][0];
            }
        }
        
        //now union of other emails with first email (root of other emails' parent=root of first email)
        //this will combine set of emails with common email
        for(int i=0; i<n; i++)
        {
            string firstEmail = accounts[i][1];
            for(int j=2; j<accounts[i].size(); j++)
            {
                unionSet(firstEmail,accounts[i][j]);
            }
        }
        
        //now add emails to the set that is mapped to their parent
        //this will help in creating output in desired format
        map<string,set<string>> mergedAccount;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string currEmail = accounts[i][j];
                string rootOfEmail = find(currEmail);
                mergedAccount[rootOfEmail].insert(currEmail);
            }
        }
        
        map<string,set<string>>::iterator it;
        for(it = mergedAccount.begin(); it != mergedAccount.end(); it++)
        {
            string name = emailToName[it->first];
            set<string> emails = it->second;
            vector<string> temp;
            temp.push_back(name);
            for(string s : emails) temp.push_back(s);
            ans.push_back(temp);
        }
        
        return ans;
    }
};*/