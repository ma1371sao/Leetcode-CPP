class Node {
public:
	unordered_map<char, Node*> chars;
	bool isWord;
	Node() {
		isWord = false;
	}
};
class Trie {
public:
	/** Initialize your data structure here. */
	Node* root;
	Trie() {
		root = new Node;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* p = root;
		for (int i = 0; i < word.length(); i++) {
			if (p->chars.find(word[i]) == p->chars.end()) {
				p->chars[word[i]] = new Node();
			}
			p = p->chars[word[i]];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* p = root;
		for (int i = 0; i < word.length(); i++) {
			if (p->chars.find(word[i]) == p->chars.end())
				return false;
			p = p->chars[word[i]];
		}
		if (p->isWord) return true;
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* p = root;
		for (int i = 0; i < prefix.length(); i++) {
			if (p->chars.find(prefix[i]) == p->chars.end())
				return false;
			p = p->chars[prefix[i]];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/