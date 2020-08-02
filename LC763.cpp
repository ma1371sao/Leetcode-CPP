class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> partLens;
        if (S.length() == 0) {
            return partLens;
        }
        
        unordered_map<char, int> charIdx;
        vector<pair<int, int>> loc;
        for (int i = 0; i < S.length(); i++) {
            if (charIdx.find(S[i]) == charIdx.end()) {
                loc.push_back(make_pair(i, i));
                charIdx[S[i]] = loc.size() - 1;
                
            } else {
                loc[charIdx[S[i]]].second = i;
            }
        }
        
        int start, end;
        bool initializing = true;
        for (auto p : loc) {
            if (initializing) {
                start = p.first;
                end = p.second;
                initializing = false;
                
            } else if (p.first > end) {
                partLens.push_back(end - start + 1);
                start = p.first;
                end = p.second;
                
            } else {
                if (p.second > end)
                    end = p.second;
            }
        }
        partLens.push_back(end - start + 1);
        return partLens;
    }
};
