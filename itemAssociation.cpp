bool cmp (const vector<string>& a, const vector<string>& b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }
    return true;
}

vector<string> itemAssociation(vector<vector<string>>& associations) {
    unordered_map<string, int> itemId;
    unordered_map<int, vector<string>> idCluster;
    unordered_set<int> ids;
    int id = 0;
    int maxSize = 0;
    if (associations.size() == 0) {
        vector<string> res;
        return res;
    }
    
    for (int i = 0; i < associations.size(); i++) {
        if (itemId.find(associations[i][0]) == itemId.end() &&
           itemId.find(associations[i][1]) == itemId.end()) {
            itemId[associations[i][0]] = id;
            itemId[associations[i][1]] = id;
            idCluster[id].push_back(associations[i][0]);
            idCluster[id].push_back(associations[i][1]);
            ids.insert(id);
            if (idCluster[id].size() > maxSize) 
                maxSize = idCluster[id].size();
            id++;
            
        } else if (itemId.find(associations[i][0]) == itemId.end()) {
            int id1 = itemId[associations[i][1]];
            itemId[associations[i][0]] = id1;
            idCluster[id1].push_back(associations[i][0]);
            if (idCluster[id1].size() > maxSize)
                maxSize = idCluster[id1].size();
            
        } else if (itemId.find(associations[i][1]) == itemId.end()) {
            int id0 = itemId[associations[i][0]];
            itemId[associations[i][1]] = id0;
            idCluster[id0].push_back(associations[i][1]);
            if (idCluster[id0].size() > maxSize) 
                maxSize = idCluster[id0].size();
            
        } else {
            int id0 = itemId[associations[i][0]];
            int id1 = itemId[associations[i][1]];
            ids.erase(id0);
            for (string item : idCluster[id0]) {
                idCluster[id1].push_back(item);
                itemId[item] = id1;
            }
            idCluster.erase(id0);
            if (idCluster[id1].size() > maxSize) 
                maxSize = idCluster[id1].size();
        }
    }
    
    vector<vector<string>> clusters;
    for (int id : ids) {
        if (idCluster[id].size() == maxSize) {
            sort(idCluster[id].begin(), idCluster[id].end());
            clusters.push_back(idCluster[id]);
        }
    }
    if (clusters.size() == 1) return clusters[0];
    sort(clusters.begin(), clusters.end(), cmp);
    return clusters[0];
}


int main() {
    vector<vector<string>> associations(3);
    associations[0] = vector<string>{"A", "B"};
    associations[1] = vector<string>{"C", "B"};
    associations[2] = vector<string>{"D", "E"};
    vector<string> res = itemAssociation(associations);
    for (auto s : res) {
        cout << s << endl;
    }
    return 0;
}
