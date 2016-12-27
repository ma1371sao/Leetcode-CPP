class TrieNode {
public:
	// Initialize your data structure here.
	string s;
	bool isword;
	unordered_map<char, TrieNode*> character;
	TrieNode(string ss = "") {
		isword = false;
		s = ss;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i<word.length(); i++) {
			if (p->character.find(word[i]) == p->character.end()) {
				p->character[word[i]] = new TrieNode(word.substr(0, i + 1));
			}
			p = p->character[word[i]];
		}
		p->isword = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* p = root;
		for (int i = 0; i<word.length(); i++) {
			if (p->character.find(word[i]) == p->character.end())
				return false;
			p = p->character[word[i]];
		}
		if (p->isword)   return true;
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i<prefix.length(); i++) {
			if (p->character.find(prefix[i]) == p->character.end())
				return false;
			p = p->character[prefix[i]];
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");