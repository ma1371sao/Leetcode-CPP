class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        unordered_map<int, vector<int>> gidToIdx;
        unordered_map<int, int> idxToGid;
        for (int i = 0; i < n; i++) {
            idxToGid[i] = i;
            gidToIdx[i].push_back(i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (idxToGid[i] != idxToGid[j] && isSimilar(A[i], A[j])) {
                    int id1 = idxToGid[i];
                    int id2 = idxToGid[j];
                    for(int k : gidToIdx[id1]) {
                        gidToIdx[id2].push_back(k);
                        idxToGid[k] = id2;
                    }
                    gidToIdx.erase(id1);
                }
            }
        }
        return gidToIdx.size();
    }
    
    bool isSimilar(string& s1, string& s2) {
        for (int i = 0, cnt = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2) return false;
            }
        }
        return true;
    }
};
