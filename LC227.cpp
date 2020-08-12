class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            else if (s[i] == ' ') continue;
            else {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') {
                    num = st.top() * num;
                    st.pop();
                    st.push(num);
                } else {
                    num = st.top() / num;
                    st.pop();
                    st.push(num);
                }
                
                op = s[i];
                num = 0;
            }
        }
        
        if (op == '+') st.push(num);
        else if (op == '-') st.push(-num);
        else if (op == '*') {
            num = st.top() * num;
            st.pop();
            st.push(num);
        } else {
            num = st.top() / num;
            st.pop();
            st.push(num);
        }
        
        int res = 0;
        while (!empty(st)) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
