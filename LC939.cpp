class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = 0;
        map<int, set<int>> xToY;
        for (auto& p : points) {
            xToY[p[0]].insert(p[1]);
        }
        
        for (auto it1 = xToY.begin(); it1 != xToY.end(); it1++) {
            for (auto it2 = next(it1, 1); it2 != xToY.end(); it2++) {
                int x1 = it1->first, x2 = it2->first;
                vector<int> ys;
                
                for (auto y : it1->second) {
                    if (it2->second.find(y) != it2->second.end())
                        ys.push_back(y);
                }
                
                if (ys.size() < 2) continue;
                int w = INT_MAX;
                for (int i = 1; i < ys.size(); i++) {
                    w = min(w, ys[i] - ys[i - 1]);
                }
                if (ans == 0 || ans > w * (x2 - x1))
                    ans = w * (x2 - x1);
            }
        }
        return ans;
    }
};
