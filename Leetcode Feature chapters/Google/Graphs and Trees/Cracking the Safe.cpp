class Solution {
public:
    string crackSafe(int n, int k) {
        string ans;
        set<string> visited;
        for(int i=0; i<n; i++) ans += '0';
        visited.insert(ans);
        
        int total = pow(k,n); //total combinations k^n
        
        for(int i=0; i<total; i++)
        {
            //get last n-1 digits from prev string
            string prev = ans.substr(ans.size()-(n-1), n-1);
            
            for(char j = '0' + (k-1); j >= '0'; j--)
            {
                string curr = prev + j;
                if(visited.count(curr) == 0)
                {
                    visited.insert(curr);
                    ans += j;
                    break;
                }
            }
            
        }
        
        return ans;
    }
};