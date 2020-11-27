class LRUCache {
private:
	int n;
	map<int,int> cache;
	map<int,int> lastUsed; //sequence of usage,key
	long long int seqNo = 0;

public:
    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        else 
        {
            lastUsed[key] = seqNo++;
            /*cout<<"*********"<<key<<endl;
            map<int,int>::iterator it2;
            for(it2 = cache.begin(); it2 != cache.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
            cout<<endl;
            for(it2 = lastUsed.begin(); it2 != lastUsed.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
            cout<<"********"<<endl;*/
            return cache[key];
        }
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            cache[key] = value;
            lastUsed[key] = seqNo++;
            return;
        }
        if(cache.size() < n)
        {
            cache[key] = value;
            lastUsed[key] = seqNo++;
        }
        else //evict LRU then push
        {
            int keyToBeReplaced;
            int minSeq = INT_MAX;
            map<int,int>::iterator it;
            for(it = lastUsed.begin(); it != lastUsed.end(); it++)
            {
                if(it->second < minSeq) 
                {
                    minSeq = it->second;
                    keyToBeReplaced = it->first;
                }
            }
            //cout<<"keyToBeReplaced="<<keyToBeReplaced<<endl;
            cache.erase(keyToBeReplaced);
            cache[key] = value;
            lastUsed.erase(keyToBeReplaced);
            lastUsed[key] = seqNo++;
        }
        
        /*cout<<"*********"<<key<<" "<<value<<endl;
        map<int,int>::iterator it2;
        for(it2 = cache.begin(); it2 != cache.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
        cout<<endl;
        for(it2 = lastUsed.begin(); it2 != lastUsed.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
        cout<<"********"<<endl;*/
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

