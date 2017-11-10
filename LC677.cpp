struct Trie {
	int val;
	unordered_map<char, Trie*> nxtTrie;
	Trie() : val(0) {}
};
class MapSum {
public:
	/** Initialize your data structure here. */
	Trie* root;
	unordered_map<string, int> key_val;
	MapSum() {
		root = new Trie();
	}

	void insert(string key, int val) {
		Trie* p = root;
		bool doExist = (key_val.find(key) != key_val.end());
		for (int i = 0; i < key.length(); i++) {
			if (p->nxtTrie.find(key[i]) == p->nxtTrie.end()) {
				p->nxtTrie[key[i]] = new Trie();
			}
			if (doExist) p->nxtTrie[key[i]]->val -= key_val[key];
			p->nxtTrie[key[i]]->val += val;
			p = p->nxtTrie[key[i]];
		}
		key_val[key] = val;
	}

	int sum(string prefix) {
		Trie* p = root;
		for (int i = 0; i < prefix.length(); i++) {
			if (p->nxtTrie.find(prefix[i]) == p->nxtTrie.end())
				return 0;
			p = p->nxtTrie[prefix[i]];
		}
		return p->val;
	}
};

/**
* Your MapSum object will be instantiated and called as such:
* MapSum obj = new MapSum();
* obj.insert(key,val);
* int param_2 = obj.sum(prefix);
*/