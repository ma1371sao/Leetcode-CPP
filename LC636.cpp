class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        unordered_map<int, int> tid_count;
        int curStart = -1;
        stack<int> q;
        for (string s : logs) {
            int tid, time, op;
            helper(s, tid, time, op);
            if (!op) {
                if (!q.empty()) {
                    int curTid = q.top();
                    tid_count[curTid] += time - curStart;
                }
                q.push(tid);
                curStart = time;
                
            } else {
                tid_count[tid] += time - curStart + 1;
                curStart = time + 1;
                q.pop();
            }
        }
        
        for (int i = 0; i < n; i++)
            ans[i] = tid_count[i];
        return ans;
    }
    
    void helper(string s, int& tid, int& time, int& op) {
        int start = 0;
        int idx = s.find(":");
        tid = stoi(s.substr(start, idx - start));
        start = idx + 1;
        idx = s.find(":", start);
        string opStr = s.substr(start, idx - start);
        if (opStr == "start") op = 0;
        else op = 1;
        start = idx + 1;
        time = stoi(s.substr(start));
    }
};
