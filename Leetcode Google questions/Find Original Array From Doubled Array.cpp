class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> freq;
        
        if(changed.size() % 2 == 1) return vector<int>();
        
        for(int v: changed)
        {
            freq[v]++;
        }
        
        vector<int> ans;
        
        map<int, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); ++it)
        {
            int v = it->first;
            
            if(freq[v] == 0) continue;
            
            if(v == 0) //2*0 is itself so slash freq by 2 and add to ans
            {
                if(freq[v] % 2 == 1) //can't have odd number of 0s in doubled array
                    return vector<int>();
                
                freq[v] /= 2;
                
                for(int i=0; i<freq[v]; i++) ans.push_back(0);
                
                freq[v] = 0;
                
                continue;
            }
            
            int f = freq[v];
            
            if(freq[2*v] < f) //not enough double elements
                return vector<int>();
            
            freq[v] -= f;
            freq[2*v] -= f;
            
            for(int i=0; i<f; i++) ans.push_back(v);
        }
        
        return ans;
    }
};



/*class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        sort(changed.begin(), changed.end());
        
        int n = changed.size();
        if(n % 2 != 0) return vector<int>(); //not a doubled array
        
        //for quick find() we use unordered_map as avg time complexity is O(1)
        //worst case is O(n)
        unordered_map<int, int> changedMap;
        for(int i=0; i<n; i++)
        {
            changedMap[changed[i]]++;
        }
        
        //now we find *2 of each element and remove both
        vector<int> baseArray;
        for(int i=0; i<n; i++)
        {
            int val = changed[i];
            
            if(!changedMap[val]) continue;
            
            changedMap[val]--;
            if(changedMap[val] == 0) changedMap.erase(val);
            
            int doubleVal = val*2;
            
            //this should exist in the map else not a double array
            if(!changedMap[doubleVal]) return vector<int>();
            
            changedMap[doubleVal]--;
            if(changedMap[doubleVal] == 0) 
            {
                changedMap.erase(doubleVal);
            }
            
            baseArray.push_back(val);
        }
        
        return baseArray;
    }
};*/