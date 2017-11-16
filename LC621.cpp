class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> numChar(26, 0);
		for (int i = 0; i < tasks.size(); i++) {
			numChar[tasks[i] - 'A']++;
		}
		sort(numChar.begin(), numChar.end());
		int numEqual = 1;
		for (int i = 25; i > 0 && numChar[i] == numChar[i - 1]; i--, numEqual++);
		return max((int)tasks.size(), (numChar[25] - 1) * (n + 1) + numEqual);
	}
};