bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

struct pqCmp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int getNumMeetingRoom(vector<vector<int>>& meetings) {
    if (meetings.size() == 0) return 0;
    sort(meetings.begin(), meetings.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto m : meetings) {
        if (pq.empty()) pq.push(m[1]);
        else {
            int end = pq.top();
            if (end < m[0]) {
                pq.pop();
                pq.push(m[1]);
            } else
                pq.push(m[1]);
        }
    }
    return pq.size();
}

int main() {
    vector<vector<int>> meetings{{0, 30},{5, 10},{15, 20}};
    vector<vector<int>> meetings1{{7, 10}, {2, 4}};
    cout << getNumMeetingRoom(meetings) << endl;
    return 0;
}
