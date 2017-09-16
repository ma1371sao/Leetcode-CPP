class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.length() == 0) return true;
		bool allCap = true;
		for (int i = 0; i < word.length(); i++) {
			if (!isCapital(word[i])) {
				allCap = false;
				break;
			}
		}
		if (allCap) return true;
		for (int i = 0; i < word.length(); i++) {
			if (isCapital(word[i])) {
				allCap = true;
				break;
			}
		}
		if (!allCap) return true;
		if (isCapital(word[0])) {
			for (int i = 1; i < word.length(); i++) {
				if (isCapital(word[i]))
					return false;
			}
			return true;
		}
		return false;
	}

	bool isCapital(char c) {
		if (c >= 'a' && c <= 'z')
			return false;
		return true;
	}
};