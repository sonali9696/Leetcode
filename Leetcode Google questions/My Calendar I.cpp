class MyCalendar {
private:
    map<int,int> bookings;  
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(bookings.find(start) != bookings.end()) return false; //2 events cant start together
        
        auto nextEvent = bookings.lower_bound(start); //lower_bound means event >=s. =s is handled so this is the event after s
        if(nextEvent != bookings.end() && nextEvent->first < end) return false; //overlap with next event
        if(nextEvent != bookings.begin() && (--nextEvent)->second > start) return false; //overlap with prev event
       
        bookings[start] = end; //map automatically stores at correct place to keep it sorted
        return true;
    }
};

/*class MyCalendar {
private:
    vector<pair<int,int> > bookings;  
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        int l = bookings.size();
        for(int i=0; i<l; i++)
        {
            if(start >= bookings[i].second || end <= bookings[i].first) continue;
            else return false;
        }
        bookings.push_back(make_pair(start,end));
        return true;
    }
};*/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */