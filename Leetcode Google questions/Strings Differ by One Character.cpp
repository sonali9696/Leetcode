class Solution {
public:
    bool differByOne(vector<string>& dict) {
        //each word can be represented as say:
        //abcd as - *bcd, a*cd, ab*d, abc*
        //think of this as 4 nodes in a graph
        //keep processing all words
        //if any node has more than 1 word then true!
        //else false
        
        int n = dict.size();
        if(n < 2) return false;
        
        //unordered_map<string, bool> nodesMap;
        unordered_set<string> nodes;
        
        for(int i=0; i<n; i++)
        {
            string s = dict[i];
            int len = s.length();
            for(int j=0; j<len; j++)
            {
                char old = s[j];
                s[j] = '*';
            
                if(nodes.count(s) != 0) return true;
                nodes.insert(s);
                
                /*if(nodesMap[s]) return true; //2 strings with same node
                nodesMap[s] = true;*/
                
                s[j] = old;
            }
        }
        
        return false;
    }
};