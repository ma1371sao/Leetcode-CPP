class Solution {
public:    
    bool cmp(string& s1, string& s2, unordered_map<char, int>& order) {
        for (int i = 0; i < s1.length() || i < s2.length(); i++) {
            if (i >= s1.length()) return true;
            else if (i >= s2.length()) return false;
            else {
                int idx1 = order[s1[i]];
                int idx2 = order[s2[i]];
                if (idx1 < idx2) return true;
                if (idx1 > idx2) return false;
            }
        }
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> chOrder;
        for (int i = 0; i < order.size(); i++)
            chOrder[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++)
            if (!cmp(words[i], words[i + 1], chOrder)) return false;
        return true;
    }
};
