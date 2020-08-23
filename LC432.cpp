struct Node {
    unordered_set<string> keys;
    int val;
};

class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> key_val;
    unordered_map<int, list<Node*>::iterator> val_node;
    list<Node*> nodes;
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (key_val.count(key)) {
            int oldVal = key_val[key];
            key_val[key]++;
            auto it = val_node[oldVal];
            Node* nd = *it;
            
            if (val_node.count(oldVal + 1)) {
                Node* newNd = *(val_node[oldVal + 1]);
                newNd->keys.insert(key);
                
            } else {
                auto nxtIt = next(it);
                Node* newNd = new Node();
                newNd->val = oldVal + 1;
                newNd->keys.insert(key);
                auto newIt = nodes.insert(nxtIt, newNd);
                val_node[oldVal + 1] = newIt;
            }
            
            nd->keys.erase(key);
            if (nd->keys.empty()) {
                nodes.erase(it);
                val_node.erase(oldVal);
                delete(nd);
            }
                
                
        } else {
            key_val[key] = 1;
            if (val_node.count(1)) {
                Node* newNd = *(val_node[1]);
                newNd->keys.insert(key);
            } else {
                Node* newNd = new Node();
                newNd->val = 1;
                newNd->keys.insert(key);
                nodes.push_front(newNd);
                val_node[1] = nodes.begin();
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (key_val.count(key)) {
            int oldVal = key_val[key];
            if (oldVal > 1) {
                key_val[key]--;
                auto it = val_node[oldVal];
                Node* nd = *it;
                
                if (val_node.count(oldVal - 1)) {
                    Node* newNd = *(val_node[oldVal - 1]);
                    newNd->keys.insert(key);
                } else {
                    Node* newNd = new Node();
                    newNd->val = oldVal - 1;
                    newNd->keys.insert(key);
                    auto newIt = nodes.insert(it, newNd);
                    val_node[oldVal - 1] = newIt;
                }
                
                nd->keys.erase(key);
                if (nd->keys.empty()) {
                    nodes.erase(it);
                    val_node.erase(oldVal);
                    delete(nd);
                }
                
            } else {
                key_val.erase(key);
                auto it = val_node[oldVal];
                Node* nd = *it;
                nd->keys.erase(key);
                if (nd->keys.empty()) {
                    nodes.erase(it);
                    val_node.erase(oldVal);
                    delete(nd);
                }
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (nodes.empty()) return "";
        Node* tail = *(nodes.rbegin());
        return *(tail->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (nodes.empty()) return "";
        Node* head = *(nodes.begin());
        return *(head->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
