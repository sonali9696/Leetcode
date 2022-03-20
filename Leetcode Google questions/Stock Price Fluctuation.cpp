class StockPrice {
private:
    map<int, int> timeToPriceMap;
    multiset<int> priceSet; //set that stores duplicates is multiset
    map<int, multiset<int>::iterator> timeToPriceIter;
    
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(timeToPriceIter.count(timestamp) == 0) //new time
        {
            auto it = priceSet.insert(price);
            timeToPriceIter[timestamp] = it;
            timeToPriceMap[timestamp] = price;
        }
        else //update existing value
        {
            auto it = timeToPriceIter[timestamp];
            priceSet.erase(it);
            it = priceSet.insert(price);
            timeToPriceIter[timestamp] = it;
            timeToPriceMap[timestamp] = price;
        }
    }
    
    int current() {
        //maps are sorted so last element will have highest timestamp
        //so that is current value
        return timeToPriceMap.rbegin()->second; //last element
    }
    
    int maximum() {
        //priceSet is sorted so-
        return *priceSet.rbegin(); //last element
    }
    
    int minimum() {
        return *priceSet.begin(); //first element
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */