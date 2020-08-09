class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        if (n == 0) return ans;
        
        vector<string> part;
        dfs(s, 0, ans, part);
        return ans;
    }
    
    void dfs(string& s, int start, vector<vector<string>>& ans, vector<string>& part) {
        if (start == s.length()) {
            ans.push_back(part);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            string first = s.substr(start, i - start + 1);
            if (isPalm(first)) {
                part.push_back(first);
                dfs(s, i + 1, ans, part);
                part.pop_back();
            }
        }
    }
    
    bool isPalm(string& s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
