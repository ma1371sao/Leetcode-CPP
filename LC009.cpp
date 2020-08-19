class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long i = 0;
        queue<int> q;
        long long y = x;
        while (y) {
            q.push(y % 10);
            y /= 10;
            if (i == 0) i = 1;
            else i *= 10;
        }
        
        y = 0;
        while (!q.empty()) {
            y += q.front() * i;
            i /= 10;
            q.pop();
        }
        if (x == y) return true;
        return false;
    }
};
