class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int posG = 0;
		int posS = 0;
		int num = 0;
		while (posG < g.size() && posS < s.size()) {
			if (g[posG] <= s[posS]) {
				num++;
				posG++;
				posS++;
			}
			else {
				posS++;
			}
		}
		return num;
	}
};