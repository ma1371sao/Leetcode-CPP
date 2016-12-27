struct KV {
	int key;
	int value;
	KV(int k, int v) :key(k), value(v) {}
};
class LRUCache {
public:
	int size;
	unordered_map<int, list<KV>::iterator> m;
	list<KV> l;
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (m.find(key) != m.end()) {
			KV node(key, m[key]->value);
			l.erase(m[key]);
			l.push_front(node);
			m[key] = l.begin();
			return m[key]->value;
		}
		else
			return -1;
	}

	void set(int key, int value) {
		if (m.find(key) == m.end()) {
			if (m.size() == size) {
				m.erase(l.back().key);
				l.pop_back();
				KV node(key, value);
				l.push_front(node);
				m[key] = l.begin();
			}
			else {
				KV node(key, value);
				l.push_front(node);
				m[key] = l.begin();
			}
		}
		else {
			l.erase(m[key]);
			KV node(key, value);
			l.push_front(node);
			m[key] = l.begin();
		}
	}
};