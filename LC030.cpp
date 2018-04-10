class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0) return res;
        int l = s.length();
        int wl = words[0].length();
        int l_sub = wl * words.size();
        unordered_map<string, int> word_num;
        for (auto word : words) 
            word_num[word]++;
        for (int i = 0; i < wl && i + l_sub <= l; i++) {
            int count = 0;
            int start = i;
            unordered_map<string, int> word_count;
            for (int j = i; j + wl <= l; j += wl) {
                string sub = s.substr(j, wl);
                if (word_num.find(sub) != word_num.end()) {
                    word_count[sub]++;
                    count++;
                    if (word_count[sub] <= word_num[sub]) {
                        if (count == words.size()) {
                            res.push_back(start);
                            string startWord = s.substr(start, wl);
                            word_count[startWord]--;
                            count--;
                            start += wl;
                        }
                    }
                    else {
                        while (s.substr(start, wl) != sub) {
                            word_count[s.substr(start, wl)]--;
                            count--;
                            start += wl;
                        }
                        word_count[s.substr(start, wl)]--;
                        start += wl;
                        count--;
                    }
                }
                else {
                    start = j + wl;
                    count = 0;
                    word_count.clear();
                }
            }
        }
        return res;
    }
};