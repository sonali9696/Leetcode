class LRUCache {
private:
	list<int> sequence;
	map<int,int> cache; //key,value
	map<int,list<int>::iterator> cacheToSeq; //key,iterator to element in vector sequence 
//(not mapping to index as when we push new element in front, index of every element changes)
//absolute index changes, relative is same hence using iterator
	int n;
	int currentSize;

public:
    LRUCache(int capacity) {
        n = capacity;
        currentSize = 0;
    }

    void pushToFront(int key)
    {
            sequence.push_front(key);
            cacheToSeq[key] = sequence.begin();
    }

    void moveToFront(int key)
    {
            list<int>::iterator it = cacheToSeq[key];
            sequence.erase(it);
            pushToFront(key);
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;

        moveToFront(key);
        
        /*cout<<"*********"<<key<<endl;
        map<int,int>::iterator it2;
        for(it2 = cache.begin(); it2 != cache.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
        cout<<endl;
        for(auto v : sequence) cout<<v<<endl;
        cout<<"********"<<endl;*/
        
        return cache[key];
    }

    void put(int key, int value) {
        //cout<<"*********"<<key<<" "<<value<<endl;
        if(cache.find(key) != cache.end())
        {
			//update value
            cache[key] = value;
            moveToFront(key);
            return;
        }

        if(currentSize < n)
        {
            currentSize++;
        }
        else
        {
            //remove least recently used
            int old = sequence.back();
            //cout<<"removing "<<old<<endl;
            sequence.pop_back();
            cache.erase(old);
            cacheToSeq.erase(old);
        }
		
        pushToFront(key);
        cache[key] = value;
        
        /*map<int,int>::iterator it2;
        for(it2 = cache.begin(); it2 != cache.end(); it2++) cout<<it2->first<<" "<<it2->second<<endl;
        cout<<endl;
        for(auto v : sequence) cout<<v<<endl;
        cout<<"********"<<endl;*/
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

