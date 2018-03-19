class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        unordered_map<int, int> h_n;
        for (int ct : citations) {
            if (ct > n) h_n[n]++;
            else h_n[ct]++;
        }
        int last = 0;
        for (int i = n; i >= 0; i--) {
            h_n[i] += last;
            if (h_n[i] >= i) return i;
            last = h_n[i];
        }
        return -1;
    }
};
