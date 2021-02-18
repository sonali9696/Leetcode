class MyCalendar {
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
};