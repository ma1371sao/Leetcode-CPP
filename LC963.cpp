class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<string> pointKey;
        for (auto& p : points) {
            string key = to_string(p[0]) + "_" + to_string(p[1]);
            pointKey.insert(key);
        }
        double res = 0;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    int x1 = points[i][0], x2 = points[j][0], x3 = points[k][0];
                    int y1 = points[i][1], y2 = points[j][1], y3 = points[k][1];
                    int y = y3 + y2 - y1;
                    int x = x3 + x2 - x1;
                    if ((y2 - y1) * (y3 - y1) + (x2 - x1) * (x3 - x1) != 0) continue;
                    
                    string key = to_string(x) + "_" + to_string(y);
                    if (pointKey.find(key) != pointKey.end()) {
                        double l = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
                        double w = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
                        if (l * w < res || res == 0)
                            res = l * w;
                    }
                }
            }
        }
        return res;
    }
};
