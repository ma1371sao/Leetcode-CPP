class Solution {
public:
    string frequencySort(string s) {
        vector<string> bucket(s.length() + 1, "");
        unordered_map<char, int> char_num;
        for (auto c: s) char_num[c]++;
        for (auto it : char_num) {
            char c = it.first;
            int num = it.second;
            string s(num, c);
            bucket[num] += s;
        }
        string res;
        for (int i = s.length(); i > 0; i--)
            res += bucket[i];
        return res;
    }
};