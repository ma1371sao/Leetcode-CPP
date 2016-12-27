struct trie {
	trie* charac[26];
	int end;
	trie()
	{
		end = 0;
		for (int i = 0; i<26; i++)
			charac[i] = NULL;
	}
};
class WordDictionary {
public:
	trie root;
	// Adds a word into the data structure.
	void addWord(string word) {
		trie *t = &root;
		for (int i = 0; i<word.length(); i++)
		{
			if (t->charac[word[i] - 'a'] == NULL)
				t->charac[word[i] - 'a'] = new trie;
			t = t->charac[word[i] - 'a'];
		}
		t->end = 1;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		if (word.length() == 0)
			return false;
		trie *t = &root;
		if (DFS(t, 0, word))
			return true;
		return false;
	}
	bool DFS(trie *t, int pos, string & word)
	{
		if (pos == word.length())
			if (t->end)
				return true;
			else
				return false;
		if (word[pos] != '.') {
			if (t->charac[word[pos] - 'a'] == NULL)
				return false;
			if (DFS(t->charac[word[pos] - 'a'], pos + 1, word))
				return true;
			else
				return false;
		}
		else {
			for (int i = 0; i<26; i++)
				if (t->charac[i])
					if (DFS(t->charac[i], pos + 1, word))
						return true;
		}
		return false;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");