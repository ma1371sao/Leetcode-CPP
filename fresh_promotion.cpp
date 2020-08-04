int isWinner(vector<vector<string>>& codeList, vector<string>& shoppingCart) {
    vector<string> matchStrs{"*"};
    for (int i = 0; i < codeList.size(); i++) {
        for (int j = 0; j < codeList[i].size(); j++) {
            matchStrs.push_back(codeList[i][j]);
        }
        matchStrs.push_back("*");
    }
    matchStrs.push_back("*");
    
    vector<vector<int>> dp(shoppingCart.size() + 1, vector<int>(matchStrs.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < shoppingCart.size(); i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 0; i < shoppingCart.size(); i++) {
        for (int j = 0; j < matchStrs.size(); j++) {
            if (shoppingCart[i] == matchStrs[j] || matchStrs[j] == "anything") {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (matchStrs[j] == "*") {
                dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j] || dp[i][j + 1]);
            }
        }
    }
    return dp[shoppingCart.size()][matchStrs.size()];
}

int main() {
    vector<vector<string>> codeList;
    codeList.push_back(vector<string>{"apple", "apple"});
    codeList.push_back(vector<string>{"apple", "apple", "banana"});
    
    vector<string> shoppingCart{"apple", "apple", "apple", "banana"};
    cout << isWinner(codeList, shoppingCart) << endl;
    cout << "finished" << endl;
    return 0;
}
