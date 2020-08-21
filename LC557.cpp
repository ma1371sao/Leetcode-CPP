class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        while (start < s.length()) {
            int pos = s.find(" ", start);
            if (pos == -1) pos = s.length();
            for (int i = start, j = pos - 1; i < j; i++, j--) {
                int tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
            start = pos + 1;
        }
        return s;
    }
};
