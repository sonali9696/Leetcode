class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        set<int> s;
        for(int i=0; i<n; i++)
        {
            s.insert(bulbs[i]);
            auto it = s.lower_bound(bulbs[i]);
            
            if(it != s.begin()) 
            {
                it--; 
                if((bulbs[i] - *it - 1) == k) return (i+1);
            }
            
            it = s.upper_bound(bulbs[i]);
            if(it != s.end())
            {
                if((*it - bulbs[i] - 1) == k) return (i+1);
            }
        }
        
        return -1;
    }
};