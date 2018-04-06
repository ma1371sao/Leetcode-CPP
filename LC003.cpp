class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> c_pos;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (c_pos.find(s[i]) == c_pos.end() || c_pos[s[i]] < start)
                c_pos[s[i]] = i;
            else {
                maxLen = max(maxLen, i - start);
                start = c_pos[s[i]] + 1;
                c_pos[s[i]] = i;
            }
        }
        maxLen = max(maxLen, (int)s.length() - start);
        return maxLen;
    }
};