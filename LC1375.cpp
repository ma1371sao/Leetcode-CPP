class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        if (n == 0) return 0;
        list<int> l;
        unordered_map<int, list<int>::iterator> val_pos;
        for (int i = 1; i <= n; i++) {
            l.push_front(i);
            val_pos[i] = l.begin();
        }
        
        int mostRight = 0;
        int count = 0;
        for (int bulb : light) {
            mostRight = max(bulb, mostRight);
            l.erase(val_pos[bulb]);
            if (l.empty() || l.back() > mostRight) count++;
        }
        return count;
    }
};
