class Solution {
public:
    int countSubstrings(string s) {
        int n = 0;
        int left = 0;
        int right = s.length() - 1;
        for (int l = 0; l <= right; l++) {
            int mid = l + (right - l) / 2;
            if ((right - l + 1) % 2) {
                for (int i = 0; mid + i <= right; i++) {
                    if (s[mid - i] == s[mid + i])
                        n++;
                    else
                        break;
                }
            }
            else {
                for (int i = 0; mid + 1 + i <= right; i++) {
                    if (s[mid - i] == s[mid + 1 + i])
                        n++;
                    else
                        break;
                }
            }
        }
        for (int r = right - 1; r >= left; r--) {
            int mid = left + (r - left) / 2;
            if ((r - left + 1) % 2) {
                for (int i = 0; mid + i <= r; i++) {
                    if (s[mid - i] == s[mid + i])
                        n++;
                    else
                        break;
                }
            }
            else {
                for (int i = 0; mid + 1 + i <= r; i++) {
                    if (s[mid - i] == s[mid + 1 + i])
                        n++;
                    else
                        break;
                }
            }
        }
        return n;
    }
};
