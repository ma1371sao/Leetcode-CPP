class Solution {
public:
	int firstUniqChar(string s) {
		map<char, int> char_Index;
		unordered_map<char, int> char_Num;
		for (int i = 0; i < s.length(); i++) {
			if (char_Index.find(s[i]) == char_Index.end())
				char_Index[s[i]] = i;
			char_Num[s[i]]++;
		}
		int minIndex = INT_MAX;
		for (auto it = char_Index.begin(); it != char_Index.end(); it++) {
			if (char_Num[it->first] == 1 && it->second < minIndex)
				minIndex = it->second;
		}
		if (minIndex < INT_MAX) return minIndex;
		return -1;
	}
};