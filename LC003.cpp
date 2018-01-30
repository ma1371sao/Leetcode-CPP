class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> ch_pos;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (ch_pos.find(s[i]) == ch_pos.end()) {
                ch_pos[s[i]] = i;
            }
            else {
                res = max(res, i - start);
                for (int j = start; j < ch_pos[s[i]]; j++) {
                    ch_pos.erase(s[j]);
                }
                start = ch_pos[s[i]] + 1;
                ch_pos[s[i]] = i;
            }
        }
        res = max(res, (int)(s.length() - start));
        return res;
    }
};
