class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal < 0) return false;
		if (maxChoosableInteger >= desiredTotal) return true;
		if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal) return false;
		string visit(maxChoosableInteger + 1, '0');
		unordered_map<string, bool> visitRecord;
		return canWin(maxChoosableInteger, desiredTotal, visit, visitRecord);
	}

	bool canWin(int maxChoosableInteger, int desiredTotal, string& visit, unordered_map<string, bool>& visitRecord) {
		string state = visit;
		if (visitRecord.find(state) != visitRecord.end()) return visitRecord[state];
		for (int num = maxChoosableInteger; num > 0; num--) {
			if (visit[num] == '0') {
				if (num >= desiredTotal) {
					visitRecord[state] = true;
					return true;
				}
				visit[num] = '1';
				if (!canWin(maxChoosableInteger, desiredTotal - num, visit, visitRecord)) {
					visit[num] = '0';
					visitRecord[state] = true;
					return true;
				}
				visit[num] = '0';
			}
		}
		visitRecord[state] = false;
		return false;
	}
};