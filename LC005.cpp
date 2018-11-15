class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int left = 0;
        int right = s.length() - 1;
        int maxLen = 0;
        int start = 0;
        for (int l = left; l <= right; l++) {
            int mid = l + (right - l)/2;
            if (right - l + 1 <= maxLen)
                break;
            if ((right - l + 1) % 2) {
                int half = 0;
                for (; mid + half < s.length() && mid - half >= l && s[mid + half] == s[mid - half]; half++);
                half--;
                if (half * 2 + 1 > maxLen) {
                    maxLen = half * 2 + 1;
                    start = mid - half;
                }
            }
            else {
                int half = 0;
                for (; mid + 1 + half < s.length() && mid - half >= l && s[mid + 1 + half] == s[mid - half]; half++);
                half--;
                if (half * 2 + 2 > maxLen) {
                    maxLen = half * 2 + 2;
                    start = mid - half;
                }
            }
        }
        for (int r = right; r >= left; r--) {
            int mid = left + (r - left) / 2;
            if (r - left + 1 <= maxLen)
                break;
            if ((r - left + 1) % 2) {
                int half = 0;
                for (; mid - half >= left && mid + half <= r && s[mid + half] == s[mid - half]; half++);
                half--;
                if (half * 2 + 1 > maxLen) {
                    maxLen = half * 2 + 1;
                    start = mid - half;
                }
            }
            else {
                int half = 0;
                for (; mid + 1 + half <= r && mid - half >= left && s[mid + 1 + half] == s[mid - half]; half++);
                half--;
                if (half * 2 + 2 > maxLen) {
                    maxLen = half * 2 + 2;
                    start = mid - half;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
