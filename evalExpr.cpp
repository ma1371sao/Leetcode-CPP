vector<string> parseExpr(string expr) {
    vector<string> ans;
    string num = "";
    for (char c : expr) {
        if (c == ' ') continue;
        else if (c >= '0' && c <= '9')
            num += c;
        else {
            ans.push_back(num);
            num = "";
            if (c == '+')
                ans.push_back("+");
            else if (c == '-')
                ans.push_back("-");
            else if (c == '*')
                ans.push_back("*");
            else if (c == '/')
                ans.push_back("/");
        } 
    }
    if (num.length() > 0)
        ans.push_back(num);
    return ans;
}

vector<string> toPostFix(vector<string> inFix) {
    vector<string> postFix;
    stack<string> op;
    for (string s : inFix) {
        if (s[0] >= '0' && s[0] <= '9')
            postFix.push_back(s);
        else {
            if (op.empty())
                op.push(s);
            else {
                if (s == "*" || s == "/") {
                    if (op.top() == "*" || op.top() == "/") {
                        postFix.push_back(op.top());
                        op.pop();
                        postFix.push_back(s);
                    } else
                        op.push(s);
                } else {
                    while (!op.empty()) {
                        postFix.push_back(op.top());
                        op.pop();
                    }
                    op.push(s);
                }
            }
        }
    }
    while (!op.empty()) {
        postFix.push_back(op.top());
        op.pop();
    }
    return postFix;
}

int evalPostFix(vector<string>& post) {
    stack<int> nums;
    for (string s : post) {
        if (s == "+") {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num1 + num2);
        } else if (s == "-") {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num2 - num1);
        } else if (s == "*") {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num1 * num2);
        } else if (s == "/") {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(num2 / num1);
        } else
            nums.push(stoul(s, nullptr, 10));
    }
    return nums.top();
}

int main() {
    auto inFix = parseExpr("1+2*3+4/2+2+3-1");
    for (string s : inFix)
        cout << s << endl;
    auto ans = toPostFix(inFix);
    cout << evalPostFix(ans) << endl;
}
