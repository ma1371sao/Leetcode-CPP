class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string formatS;
		int pos = S.length() - 1;
		while (pos >= 0) {
			for (int i = 0; i < K && pos >= 0;) {
				if (S[pos] != '-') {
					if (S[pos] >= 'a' && S[pos] <= 'z') formatS.push_back(S[pos] - 32);
					else formatS.push_back(S[pos]);
					i++;
				}
				pos--;
			}
			formatS.push_back('-');
		}
		int numDash = 0;
		for (int i = formatS.length() - 1; i >= 0 && formatS[i] == '-'; i--, numDash++);
		formatS = formatS.substr(0, formatS.length() - numDash);
		reverse(formatS.begin(), formatS.end());
		return formatS;
	}
};