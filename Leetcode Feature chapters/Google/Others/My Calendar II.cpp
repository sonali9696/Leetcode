class MyCalendarTwo {
private:
	vector<pair<int,int> > bookings;
	vector<pair<int,int> > doubleBookings;

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        int l = doubleBookings.size();
        for(int i=0; i < l; i++)
        {
            pair<int,int> time = doubleBookings[i];
            int s1 = time.first, e1 = time.second;
            if(end <= s1 || start >= e1) continue; //no conflict
            else return false;
            //note == end is considered as event range doesn’t include end value
        }

        l = bookings.size();
        for(int i=0; i < l; i++)
        {
            pair<int,int> time = bookings[i];
            int s1 = time.first, e1 = time.second;
            if(end <= s1 || start >= e1) continue;
            else
            {
                int s = max(s1,start), e = min(e1, end);
                doubleBookings.push_back(make_pair(s,e));
            }
        }

        bookings.push_back(make_pair(start,end));
        return true;
    }
};



/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */