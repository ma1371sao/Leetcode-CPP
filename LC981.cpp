class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string, greater<int>>> keyTimeValMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeValMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (keyTimeValMap.find(key) == keyTimeValMap.end())
            return "";
        if (keyTimeValMap[key].lower_bound(timestamp) != keyTimeValMap[key].end())
            return keyTimeValMap[key].lower_bound(timestamp)->second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
