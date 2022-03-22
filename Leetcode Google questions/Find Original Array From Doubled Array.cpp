//O(n) solution -
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> freq;
        
        //this is because input is max 10^5
        for(int i=0; i <= 2*100005; i++) freq.push_back(0);
        
        for(int v: changed) freq[v]++;

        vector<int> ans;
        
        for(int i=0; i<freq.size(); i++) {
            if(freq[i] == 0) continue;
            
            if(i == 0) //handle 0 case as 2*0 = 0
            {
                if(freq[0] % 2 == 1) return {}; //cant have odd 0s in double array
                
                freq[0] /= 2;
                while(freq[0]--) ans.push_back(0);
                
                continue;
            }
            
            if(freq[2*i] < freq[i]) return {}; //not enough double elements
            
            int f = freq[i];
            freq[i] -= f;
            freq[2*i] -= f;
            
            while(f--) ans.push_back(i);
        }
        
        return ans;
    }
};

//approach 2 - we can simply store all elements in map
//since map is sorted we come across smaller elements first
//so we just check if val*2 exists

/*class Solution {
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
};*/



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