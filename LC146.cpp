class LRUCache {
public:
    unordered_map<int, int> key_val;
    list<int> keys;
    unordered_map<int, list<int>::iterator> key_pos;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (key_val.find(key) == key_val.end()) return -1;
        keys.erase(key_pos[key]);
        keys.push_front(key);
        key_pos[key] = keys.begin();
        return key_val[key];
    }
    
    void put(int key, int value) {
        if (key_val.find(key) != key_val.end()) {
            key_val[key] = value;
            keys.erase(key_pos[key]);
            keys.push_front(key);
            key_pos[key] = keys.begin();
        }
        else {
            if (key_val.size() == size) {
                int erasedKey = keys.back();
                key_val.erase(erasedKey);
                key_pos.erase(erasedKey);
                keys.pop_back();
            }
            key_val[key] = value;
            keys.push_front(key);
            key_pos[key] = keys.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
