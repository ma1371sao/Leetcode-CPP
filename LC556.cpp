class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        vector<int> digits;
        int cp_n = n;
        while (cp_n > 0) {
            digits.push_back(cp_n % 10);
            cp_n /= 10;
        }
        
        int len = digits.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            int tmp = digits[i];
            digits[i] = digits[j];
            digits[j] = tmp;
        }
        
        int idx = len - 1;
        for (; idx > 0 && digits[idx] <= digits[idx - 1]; idx--);
        if (idx == 0) return -1;
        int a = idx - 1;
        for (idx = len - 1; idx > a && digits[idx] <= digits[a]; idx--);
        int tmp = digits[a];
        digits[a] = digits[idx];
        digits[idx] = tmp;
        
        sort(digits.begin() + a + 1, digits.end());
        long long ans = 0;
        for (idx = len - 1; idx >= 0; idx--) {
            ans += pow(10, len - 1 - idx) * digits[idx];
            if (ans > INT_MAX) return -1;
        }
        return ans;
    }
};
