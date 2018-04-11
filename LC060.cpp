class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f(n + 1, 1);
        string res;
        list<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        for (int i = 2; i <= n; i++)
            f[i] = i * f[i - 1];
        for (int i = 1; i < n; i++) {
            int num = (k - 1) / f[n - i];
            auto it = nums.begin();
            for (int j = 0; j < num; j++, it++);
            res.push_back(*it + '0');
            k -= num * f[n - i];
            nums.erase(it);
        }
        res.push_back(*nums.begin() + '0');
        return res;
    }
};