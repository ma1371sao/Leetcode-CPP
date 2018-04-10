class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        vector<pair<long long, int>> factor;
        int sign;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;
        else
            sign = 1;
        long long did = llabs((long long)dividend);
        long long dis = llabs((long long)divisor);
        factor.push_back(make_pair(dis, 1));
        int n = 1;
        while (1) {
            dis = (dis << 1);
            if (dis > did) break;
            n += n;
            factor.push_back(make_pair(dis, n));
        }
        int res = 0;
        for (int i = factor.size() - 1; i >= 0; i--) {
            if (did - factor[i].first >= 0) {
                res += factor[i].second;
                did -= factor[i].first;
            }
        }
        return res * sign;
    }
};