class Solution {
public:
    int maxLen = 0;
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0) return 0;
        vector<int> bArr(arr.size(), -1);
        int i = 0;
        for (string& s : arr) {
            bArr[i] = getBStr(s);
            i++;
        }
        dfs(arr, bArr, 0, 0, 0);
        return maxLen;
    }
    
    int getBStr(string& s) {
        int bS = 0;
        for (char& c : s) {
            int bC = 1 << (c - 'a');
            if ((bS & bC) != 0) {
                return -1;
            }
            bS |= bC;
        }
        return bS;
    }
    
    void dfs(vector<string>& arr, vector<int>& bArr, int idx, int bS, int curLen) {
        if (idx == arr.size()) {
            if (curLen > maxLen) {
                maxLen = curLen;
            }
            return;
        }
        
        dfs(arr, bArr, idx + 1, bS, curLen);
        if (bArr[idx] != -1 && (bS & bArr[idx]) == 0) {
            dfs(arr, bArr, idx + 1, (bS | bArr[idx]), curLen + arr[idx].length());
        }
    }
};
