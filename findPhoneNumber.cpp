//input string， 在input 找 电话号码， 返回电话号码as a string。 有且只有一个电话号码。 （format 的格式是这样的 1-234-567-8901）
bool isNum(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

string findPhoneNum(string s) {
    string p = "*1-...-...-....";
    vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
    dp[0][0] = true;
    dp[0][1] = true;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            if (s[i] == '.' || s[i] == '*')
                dp[i + 1][j + 1] = false;
            else if (s[i] == p[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (p[j] == '.' && isNum(s[i])) {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (p[j] == '*') {
                dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j] || dp[i][j + 1]);
            }
            
            if (j == p.length() - 1 && dp[i + 1][j + 1]) {
                return s.substr(i - 13, 14);
            }
        }
    }
    return "";
}

int main() {
    cout << findPhoneNum("111111-123-456-7890aaaaa") << endl;
}
