class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<vector<int>> adjNodes(n);
        for (int i = 0; i < connections.size(); i++) {
            adjNodes[connections[i][0]].push_back(connections[i][1]);
            adjNodes[connections[i][1]].push_back(connections[i][0]);
        }
        unordered_set<int> visited;
        unordered_map<int, int> nodeDeep;
        findCriticalConns(adjNodes, res, 0, 0, -1, visited, nodeDeep);
        return res;
    }
    
    int findCriticalConns(vector<vector<int>>& adjNodes, vector<vector<int>>& res, 
                          int deep, int node, int parent,
                          unordered_set<int>& visited, unordered_map<int, int>& nodeDeep) {

        visited.insert(node);
        nodeDeep[node] = deep;
        int lowestDeep = deep;
        for (int adjNode : adjNodes[node]) {
            if (visited.find(adjNode) == visited.end()) {
                int childLowestDeep = findCriticalConns(adjNodes, res, deep + 1, adjNode, node, visited, nodeDeep);
                if (childLowestDeep > deep)
                    res.push_back(vector<int>{node, adjNode});
                if (childLowestDeep < lowestDeep)
                    lowestDeep = childLowestDeep;
            } else if (adjNode != parent && nodeDeep[adjNode] < lowestDeep)
                lowestDeep = nodeDeep[adjNode];
        }
        return lowestDeep;
    }
};
