class Solution {
public:
	int magicalString(int n) {
		if (n == 0) return 0;
		if (n < 4) return 1;
		int num = 1;
		string magicStr = "122";
		string group = "122";
		int cur = 2;
		char nxt = '1';
		while (magicStr.size() < n) {
			if (group[cur] == '1') {
				magicStr.push_back(nxt);
				group.push_back(nxt);
				if (nxt == '1') num++;
			}
			else {
				magicStr.push_back(nxt);
				if (nxt == '1') num++;
				if (magicStr.size() == n) break;
				magicStr.push_back(nxt);
				if (nxt == '1') num++;
				group.push_back(nxt);
				group.push_back(nxt);
			}
			if (nxt == '1') nxt = '2';
			else nxt = '1';
			cur++;
		}
		return num;
	}
};