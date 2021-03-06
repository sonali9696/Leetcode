class LFUCache {
private:
	int cap;
	unordered_map<int, pair<int,int> > cache; //key, (value,freq)
	unordered_map<int, list<int> > freqBuckets; //freq, list of keys
	unordered_map<int, list<int>::iterator> freqListIter; //iterator to list of keys under a freq
	int minFreq;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
       	if(cache.find(key) == cache.end()) 
        {
            return -1;
        }

		int originalFreq = cache[key].second; 
        cache[key].second++; //freq increased
		
		list<int>::iterator it = freqListIter[key];
		freqBuckets[originalFreq].erase(it);
		
        freqBuckets[originalFreq+1].push_back(key);
		freqListIter[key] = --freqBuckets[originalFreq+1].end();

		while(freqBuckets.find(minFreq) == freqBuckets.end() || freqBuckets[minFreq].size() == 0) minFreq++;
        
		return cache[key].first;
		
    }
    
    void put(int key, int value) {
		if(cap <= 0) return;
        int currVal = get(key); //so that freq increased and pushed to correct bucket
		//get also takes care of updating minFreq if minFreq bucket is empty unless key not in cache

        //already in cache-
        if(currVal != -1) {
            cache[key].first = value; //freq already increased in get
            return;
        }
        else if(cache.size() >= cap)
        {
	        //remove LFU key, and if multiple keys of least freq then LRU key
	        while(freqBuckets.find(minFreq) == freqBuckets.end() || freqBuckets[minFreq].size() == 0) minFreq++;
	        int keyToRemove = freqBuckets[minFreq].front();
            freqBuckets[minFreq].pop_front();
            cache.erase(keyToRemove);
            freqListIter.erase(key);
        }
     
        freqBuckets[1].push_back(key);
        cache[key] = {value,1};
        freqListIter[key] = --freqBuckets[1].end();
        minFreq = 1;
        //we are not doing size--, size++ as no need to maintain size variable as cache.size() will give that value in O(1)
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

