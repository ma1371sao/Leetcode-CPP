class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s, 0, ans, "", 0);
        return ans;
    }
    
    void dfs(string s, int num, vector<string>& ans, string ip, int start) {
        if (num == 4 && start == s.length()) {
            ans.push_back(ip);
            return;
        } else if (num == 4) return;
        else if (start == s.length()) return;
        
        if (s[start] == '0')  {
            if (num == 0)
                dfs(s, num + 1, ans, ip + "0", start + 1);
            else
                dfs(s, num + 1, ans, ip + ".0", start + 1);
        } else {
            for (int i = 0; i < 3 && start + i < s.length(); i++) {
                string sub = s.substr(start, i + 1);
                int d = stoi(sub);
                if (d <= 255) {
                    if (num == 0)
                        dfs(s, num + 1, ans, ip + sub, start + i + 1);
                    else
                        dfs(s, num + 1, ans, ip + "." + sub, start + i + 1);
                }
            }
        }
    }
};
