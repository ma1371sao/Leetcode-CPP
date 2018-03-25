//O(E + n)
class Solution {
public:
    struct Node {
        unordered_set<int> neighbors;
        bool isLeaf() {return neighbors.size() == 1;}
    };
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0) return res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        if (n == 2) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        vector<Node> nodes(n);
        for (auto e : edges) {
            nodes[e.first].neighbors.insert(e.second);
            nodes[e.second].neighbors.insert(e.first);
        }
        queue<int> leaves;
        for (int i = 0; i < n; i++)
            if (nodes[i].isLeaf())
                leaves.push(i);
        while (leaves.size() < n) {
            int num_l = leaves.size();
            n -= num_l;
            for (int i = 0; i < num_l; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (auto i : nodes[leaf].neighbors) {
                    nodes[i].neighbors.erase(leaf);
                    if (nodes[i].isLeaf())
                        leaves.push(i);
                }
            }
        }
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};