class Solution {
public:
    int calculate(string s) {
        int i = -1;
        return getRes(s, i);
    }
    
    int getRes(string& s, int& i) {
        int num = 0;
        int res = 0;
        char op = '+';
        for (i += 1; i < s.length() && s[i] != ')'; i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            else if (s[i] == '(')
                num = getRes(s, i);
            else {
                if (op == '+') res += num;
                else res -= num;
                num = 0;
                op = s[i];
            }
        }
        
        if (op == '+') res += num;
        else res -= num;
        return res;
    }
};
