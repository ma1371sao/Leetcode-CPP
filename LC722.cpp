class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string line = "";
        bool blockCm = false;
        for (string s : source) {
            for (int i = 0; i < s.length(); i++) {
                if (blockCm) {
                    if (s[i] == '*' && i < s.length() - 1 && s[i + 1] == '/') {
                        blockCm = false;
                        i++;
                    }
                } else {
                    if (s[i] == '/' && i < s.length() - 1 && s[i + 1] == '*') {
                        blockCm = true;
                        i++;
                    } else if (s[i] == '/' && i < s.length() - 1 && s[i + 1] == '/') {
                        break;
                    } else line += s[i];
                }
            }
            
            if (!blockCm && line.length() > 0) {
                ans.push_back(line);
                line = "";
            }
        }
        return ans;
    }
};
