class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ch_pos;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (ch_pos.find(s[i]) == ch_pos.end() || start > ch_pos[s[i]]) {
                ch_pos[s[i]] = i;
                int len = i - start + 1;
                if (len > maxLen) maxLen = len;
            }
            else {
                start = ch_pos[s[i]] + 1;
                int len = i - start + 1;
                ch_pos[s[i]] = i;
                if (len > maxLen) maxLen = len;
            }
        }
        return maxLen;
    }
};
