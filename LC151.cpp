class Solution {
public:
    string reverseWords(string s) {
        bool allowEmpty = false;
        int n = s.length();
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                allowEmpty = true;
                s[pos++] = s[i];
            } else {
                if (allowEmpty) {
                    s[pos++] = s[i];
                    allowEmpty = false;
                }
            }
        }
        
        if (pos == 0) return "";
        s = s.substr(0, pos);
        if (s[pos - 1] == ' ') s.pop_back();
        n = s.length();
        reverse(s, 0, n - 1);
        int start = 0;
        while (start < n) {
            int pos = s.find(" ", start);
            if (pos == -1) pos = n;
            reverse(s, start, pos - 1);
            start = pos + 1;
        }
        return s;
    }
    
    void reverse(string& s, int i, int j) {
        for (; i < j; i++, j--) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};
