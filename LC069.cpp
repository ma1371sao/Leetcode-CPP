class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        long long left = 1;
        long long right = x;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x) return mid;
            else if (mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};