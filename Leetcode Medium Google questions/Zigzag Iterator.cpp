class ZigzagIterator {
private:
	int i, j, m, n;
	int currentVector;
    vector<int> vec1, vec2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
    {
        m = v1.size();
        n = v2.size();
        vec1 = v1;
        vec2 = v2;
        i=0, j=0; 
        if(i < m) currentVector = 1;
        else currentVector = 2;
    }

    int next() {
		if(i >= m) currentVector = 2;
        if(j >= n) currentVector = 1; 
    
        int ans;
        
        if(currentVector == 1)
        {
            if(j < n) currentVector = 2;
            ans = vec1[i++];
        }
        else if(currentVector == 2)
        {
            if(i < m) currentVector = 1;
            ans = vec2[j++];
        }
        
        return ans; //dummy value to return something in all paths
    }

    bool hasNext() {
         if(i >= m && j >= n) return false;
         else return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
