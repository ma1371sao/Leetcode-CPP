class Solution {
public:
	int characterReplacement(string s, int k) {
		int maxRepeating = 0;
		if (s.length() == 0) return 0;
		for (int i = 0; i < 26; i++) {
			maxRepeating = max(maxRepeating, replace(k, s, 'A' + i));
		}
		return maxRepeating;
	}
	int replace(int k, string s, char substitute) {
		int start = 0;
		int end = 0;
		int maxRepeating = 0;
		while (end < s.length()) {
			if (s[end] == substitute || k > 0) {
				if (s[end] != substitute) k--;
				maxRepeating = max(maxRepeating, end - start + 1);
				end++;
			}
			else {
				if (s[start] != substitute) k++;
				start++;
			}
		}
		return maxRepeating;
	}
};