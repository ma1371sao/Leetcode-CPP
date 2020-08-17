class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") return ans;
        unordered_map<char, string> digLet;
        digLet['2'] = "abc";
        digLet['3'] = "def";
        digLet['4'] = "ghi";
        digLet['5'] = "jkl";
        digLet['6'] = "mno";
        digLet['7'] = "pqrs";
        digLet['8'] = "tuv";
        digLet['9'] = "wxyz";
        string s = "";
        dfs(digLet, digits, 0, s, ans);
        return ans;
    }
    
    void dfs(unordered_map<char, string>& digLet, string& digits, int idx, string s, vector<string>& ans) {
        if (idx == digits.length()) {
            ans.push_back(s);
            return;
        }
        
        if (digits[idx] == '1') dfs(digLet, digits, idx + 1, s, ans);
        else {
            for (char c : digLet[digits[idx]]) {
                dfs(digLet, digits, idx + 1, s + c, ans);
            }
        }
    }
};
