class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> indices;
		if (s.length() < p.length()) return indices;
		unordered_map<char, int> sCharNum;
		unordered_map<char, int> pCharNum;
		for (int i = 0; i < p.length(); i++) {
			pCharNum[p[i]]++;
		}
		for (int i = 0; i < p.length() - 1; i++) {
			sCharNum[s[i]]++;
		}
		for (int i = p.length() - 1; i < s.length(); i++) {
			sCharNum[s[i]]++;
			bool isAnagram = true;
			for (auto it = sCharNum.begin(); it != sCharNum.end(); it++) {
				if (it->second != pCharNum[it->first]) {
					isAnagram = false;
					break;
				}
			}
			if (isAnagram) indices.push_back(i - p.length() + 1);
			sCharNum[s[i - p.length() + 1]]--;
		}
		return indices;
	}
};