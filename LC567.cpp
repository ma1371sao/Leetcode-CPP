class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.length() > s2.length()) return false;
		vector<int> charS1(26, 0);
		vector<int> charS2(26, 0);
		for (int i = 0; i < s1.length(); i++) {
			charS1[s1[i] - 'a']++;
			charS2[s2[i] - 'a']++;
		}
		if (charS1 == charS2) return true;
		for (int i = 0; i + s1.length() < s2.length(); i++) {
			charS2[s2[i] - 'a']--;
			charS2[s2[i + s1.length()] - 'a']++;
			if (charS1 == charS2) return true;
		}
		return false;
	}
};