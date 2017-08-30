struct character {
	char ch;
	int num;
	character(char c, int n) : ch(c), num(n) {}
};
bool cmp(const character a, const character b) {
	return a.num > b.num;
}
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> charIndex;
		vector<character> characters;
		for (int i = 0; i < s.length(); i++) {
			if (charIndex.find(s[i]) == charIndex.end()) {
				characters.push_back(character(s[i], 1));
				charIndex[s[i]] = characters.size() - 1;
			}
			else {
				characters[charIndex[s[i]]].num++;
			}
		}
		sort(characters.begin(), characters.end(), cmp);
		string res;
		for (int i = 0; i < characters.size(); i++) {
			while (characters[i].num > 0) {
				res.push_back(characters[i].ch);
				characters[i].num--;
			}
		}
		return res;
	}
};