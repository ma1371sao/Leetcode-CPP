struct cmp {
    bool operator() (const string& a, const string& b) {
        string s1 = a + b;
        string s2 = b + a;
        return s1 < s2;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, cmp> pq;
        bool isZero = true;
        for (int num : nums) {
            pq.push(to_string(num));
            if (num != 0) isZero = false;
        }
        if (isZero) return "0";
        string res;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
