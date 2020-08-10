class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n1 + n2);
            } else if (tokens[i] == "-") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 - n1);
            } else if (tokens[i] == "*") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 * n1);
            } else if (tokens[i] == "/") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 / n1);
            } else {
                nums.push(stoul(tokens[i], nullptr, 10));
            }
        }
        return nums.top();
    }
};
