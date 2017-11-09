class LFUCache {
public:
	int cap;
	int minFre;
	unordered_map<int, int> key_val;
	unordered_map<int, int> key_fre;
	unordered_map<int, list<int>::iterator> key_pos;
	unordered_map<int, list<int>> fre_keys;
	LFUCache(int capacity) {
		cap = capacity;
		minFre = 0;
	}

	int get(int key) {
		if (key_val.find(key) != key_val.end()) {
			if (key_fre[key] == minFre && fre_keys[key_fre[key]].size() == 1)
				minFre++;
			fre_keys[key_fre[key]].erase(key_pos[key]);
			key_fre[key]++;
			fre_keys[key_fre[key]].push_front(key);
			key_pos[key] = fre_keys[key_fre[key]].begin();
			return key_val[key];
		}
		return -1;
	}

	void put(int key, int value) {
		if (cap == 0) return;
		if (key_val.find(key) != key_val.end()) {
			key_val[key] = value;
			if (key_fre[key] == minFre && fre_keys[key_fre[key]].size() == 1)
				minFre++;
			fre_keys[key_fre[key]].erase(key_pos[key]);
			key_fre[key]++;
			fre_keys[key_fre[key]].push_front(key);
			key_pos[key] = fre_keys[key_fre[key]].begin();
		}
		else {
			if (key_val.size() == cap) {
				int erasedKey = fre_keys[minFre].back();
				fre_keys[minFre].pop_back();
				key_val.erase(erasedKey);
				key_fre.erase(erasedKey);
				key_pos.erase(erasedKey);
			}
			key_val[key] = value;
			key_fre[key] = 1;
			minFre = 1;
			fre_keys[1].push_front(key);
			key_pos[key] = fre_keys[1].begin();
		}
	}
};

/**
* Your LFUCache object will be instantiated and called as such:
* LFUCache obj = new LFUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/