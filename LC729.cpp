struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

class MyCalendar {
public:
    set<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (events.empty()) {
            events.insert(make_pair(start, end));
            return true;
        }
        for (auto it : events) {
            if (start < it.second && end > it.first)
                return false;
        }
        events.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
