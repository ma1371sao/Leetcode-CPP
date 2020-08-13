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

int main() {
    vector<string> inFix{"1", "+", "2", "*", "3", "+", "4", "/", "5"};
    auto ans = toPostFix(inFix);
    for (string s : ans)
        cout << s << endl;
}
