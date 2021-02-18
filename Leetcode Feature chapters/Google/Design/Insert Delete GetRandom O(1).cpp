//we need combo of a map and vector to do everything in O(1).
//Imp thing to note is that if we try to delete an element from the middle, it will change indices of everything after it
//if we try to fix it then we wont do it in O(n)
//so instead, swap the element to be deleted with last one and delete from end.
//cant use list with the iterator to it in map as list can't be accessed by index i.e. [] so getRandom() wont be possible

class RandomizedSet {
private:
    vector<int> randSet;
    map<int, int> mp; //val, index
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        randSet.push_back(val);
        mp[val] = randSet.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = randSet[randSet.size()-1];
        int currInd = mp[val];
        
        randSet[currInd] = last; //last element added to index, so basically the element we wanted to delete is replaced
        mp[last] = currInd;
        
        randSet.pop_back(); //duplicate entry of last element to be removed
        
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return randSet[rand() % randSet.size()];    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */