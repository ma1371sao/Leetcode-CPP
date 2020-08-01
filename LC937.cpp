bool cmp(string log1, string log2) {
    string log1Words = log1.substr(log1.find(" ") + 1);
    string log2Words = log2.substr(log2.find(" ") + 1);
    return log1Words <= log2Words;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        string word;
        int fast = logs.size() - 1;
        int slow = logs.size() - 1;
        while (fast >= 0) {
            if (isDig(logs[fast])) {
                string tmp = logs[slow];
                logs[slow] = logs[fast];
                logs[fast] = tmp;
                slow--;
            }
            fast--;
        }
        
        if (slow == -1) {
            return logs;
        }
        
        sort(logs.begin(), logs.begin() + slow + 1, cmp);
        return logs;
    }
    
    bool isDig(string log) {
        int idx = log.find(' ') + 1;
        
        for (; idx < log.length() && log[idx] != ' '; idx++) {
            if (log[idx] < '0' || log[idx] > '9')
                return false;
        }
        return true;
    }
};
