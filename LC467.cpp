class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> maxLength(26, 0);
		int start = 0;
		int end = 0;
		int num = 0;
		while (start < p.length()) {
			for (end = start; end < p.length() - 1 && (p[end] - 'a' + 1) % 26 == p[end + 1] - 'a'; end++);
			maxLength[p[start] - 'a'] = max(maxLength[p[start] - 'a'], end - start + 1);
			start++;
		}
		for (int i = 0; i < 26; i++) {
			num += maxLength[i];
		}
		return num;
	}
};