struct cmp {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> res;
        unordered_map<int, int> val_n;
        for (int num : nums)
            val_n[num]++;
        for (auto it : val_n) {
            pq.push(make_pair(it.first, it.second));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
