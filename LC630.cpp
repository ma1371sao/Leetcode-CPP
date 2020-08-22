bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int curTime = 0;
        for (auto c : courses) {
            curTime += c[0];
            pq.push(c[0]);
            if (curTime > c[1]) {
                curTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
