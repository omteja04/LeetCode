class MyCalendar {
public:
    map<int,int> mp;
    // <end, start>
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto pair = mp.upper_bound(start);

        if(pair == mp.end() || end <= pair->second) {
            mp[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */