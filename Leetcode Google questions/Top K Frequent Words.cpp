class Solution {
public:
    struct compStrings{
        bool operator()(pair<string, int> const& a, pair<string, int> const& b){
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        }
    };
    
    /*static bool compStrings(const pair<string, int> a, const pair<string, int> b){
        if(a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    }*/

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(string w : words) m[w]++;
        
        /*map<string, int>::iterator it;
        vector<pair<string,int> > v;
        for(it = m.begin(); it != m.end(); it++){
            v.push_back(make_pair(it->first, it->second));
        }
    
		sort(v.begin(), v.end(), compStrings);
		
		vector<string> ans;
	 	for(int i=0; i < k; i++){
			ans.push_back(v[i].first);
        }
        return ans;*/
        
        priority_queue<pair<string, int>, vector<pair<string, int> >, compStrings> pq;
        for(auto w : m){
            pq.push(w);
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()) 
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); //because heap builds from bottom to top so greater<int> means min heap. Similarly whatever is defined in custom sort, it means from begin to end it will be in reverse order
        return ans;
    }
};


