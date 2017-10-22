class Solution {
public:
	string convertToTitle(int n) {
		string title;
		do {
			n--;
			title.push_back('A' + n % 26);
			n /= 26;
		} while (n);
		reverse(title.begin(), title.end());
		return title;
	}
};